#ifndef __HG__FORGE__MEMORY__ALLOCATOR_HPP__
#define __HG__FORGE__MEMORY__ALLOCATOR_HPP__

#include <cstring>
#include <cstdlib>
#include <cassert>

#include <new>
#include <vector>

#include "../logging/Log.hpp"
#include "../exceptions/BaseException.hpp"


namespace forge {
namespace memory {

    void init();
    void deInit();

}   // namespace memory
}   // namespace forge

#define forge_del delete


#ifdef __FORGE__DBG__

    #define forge_new new(__FILE__, __LINE__)

    struct AllocationRecord {
        void               *Pointer;
        char                FileName[120];
        unsigned long int   LineNum;
        size_t              AllocSize;

        AllocationRecord(void *pointer,
                         const char *fileName,
                         unsigned long int lineNum,
                         size_t allocSize)
            : Pointer(pointer),
              LineNum(lineNum),
              AllocSize(allocSize) {
            strncpy(this->FileName, fileName, sizeof(FileName) - 1);
        }
    };


    namespace forge {
    namespace memory {


        static
        const char *_basename(const char *filePath) {
            size_t len = strlen(filePath);
            for (int i = len - 1; i >= 0; --i) {
                if (filePath[i] == '/' ||
                    filePath[i] == '\\') {
                    return &(filePath[i + 1]);
                }
            }

            return nullptr;
        }


        static
        std::vector<AllocationRecord> _Records;

        static
        bool _HeapSizeCapped;

        static
        unsigned long int _HeapSizeCap;


        struct HeapOverflowError : exceptions::BaseException {
            HeapOverflowError(AllocationRecord record)
                : _AllocRecord(record) { }

            virtual void generateMessage() override {
                snprintf(_Message, EXCEPTION_MESSAGE_SIZE - 1,
                         "Failed to allocate memory! Reached the limit (%lu) when allocating (%lu) bytes in %s:%lu",
                         _HeapSizeCap, _AllocRecord.AllocSize, _basename(_AllocRecord.FileName), _AllocRecord.LineNum);
            }

          protected:
            AllocationRecord _AllocRecord;
        };


        void init() {
            logging::out::print("Running the Forge global allocator in debug mode!");

            _HeapSizeCapped = false;
        }


        void init(unsigned long int maxHeapSize) {
            _HeapSizeCapped = true;
            _HeapSizeCap = maxHeapSize;
        }


        void deInit() {
            logging::out::print("De-initializing the Forge global allocator!");

            if (_Records.empty()) {
                logging::out::print("No outstanding allocations remaining!");
            }
            else {
                logging::err::print("Outstanding allocations!");
                for (auto it = _Records.begin(); it != _Records.end(); ++it)
                    logging::err::print("* Allocation (%p) (%lu bytes) at (%s:%d)",
                                        it->Pointer,
                                        it->AllocSize,
                                        _basename(it->FileName),
                                        it->LineNum);
            }
        }

        // Module getters:
        std::vector<AllocationRecord> get_AllocationRecords() { return _Records; }

        size_t get_AllocatedHeapSize() {
            size_t netAllocSize = 0;

            for (auto it = _Records.begin(); it != _Records.end(); ++it)
                netAllocSize += it->AllocSize;

            return netAllocSize;
        }

    }   // namespace memory
    }   // namespace forge


    using namespace forge::memory;


    void *operator new(size_t allocSize,
                       const char *fileName,
                       unsigned long int lineNum) {
        _Records.push_back(AllocationRecord(malloc(allocSize),
                                            fileName, lineNum,
                                            allocSize));

        if (_HeapSizeCapped)
            if (get_AllocatedHeapSize() > _HeapSizeCap)
                throw HeapOverflowError(_Records.back());

        return _Records.back().Pointer;
    }


    void *operator new[](size_t allocSize,
                         const char *fileName,
                         unsigned long int lineNum) {
        _Records.push_back(AllocationRecord(malloc(allocSize),
                                            fileName, lineNum,
                                            allocSize));

        if (_HeapSizeCapped)
            if (get_AllocatedHeapSize() > _HeapSizeCap)
                throw HeapOverflowError(_Records.back());

        return _Records.back().Pointer;
    }


    void operator delete(void *pointer) {
        free(pointer);

        for (auto it = _Records.begin(); it != _Records.end(); ++it) {
            if (it->Pointer == pointer) {
                _Records.erase(it);
                return;
            }
        }
    }



#else

    #define forge_new new


    void *operator new(std::size_t allocSize) {
        return malloc(allocSize);
    }


    void *operator new[](std::size_t allocSize) {
        return malloc(allocSize);
    }


    void operator delete(void *pointer) {
        free(pointer);
    }


    namespace forge {
    namespace memory {

        void init() { }
        void deInit() { }

    }   // namespace memory
    }   // namespace forge

#endif


#endif // __HG__FORGE__MEMORY__ALLOCATOR_HPP__
