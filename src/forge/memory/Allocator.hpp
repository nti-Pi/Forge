#ifndef __HG__FORGE__MEMORY__ALLOCATOR_HPP__
#define __HG__FORGE__MEMORY__ALLOCATOR_HPP__

#include <cstring>
#include <cstdlib>

#include <new>
#include <vector>

#include "../logging/Log.hpp"


namespace forge {
namespace memory {

    void init();
    void deInit();

}   // namespace memory
}   // namespace forge


#ifdef __DBG__FORGE__

    #define forge_new new(__FILE__, __LINE__)


    struct _AllocationRecord {
        void               *Pointer;
        char                FileName[120];
        unsigned long int   LineNum;
        size_t              AllocSize;

        _AllocationRecord(void *pointer,
                          const char *fileName,
                          unsigned long int lineNum,
                          size_t allocSize)
            : Pointer(pointer),
              LineNum(lineNum),
              AllocSize(allocSize) {
            strncpy(this->FileName, fileName, sizeof(FileName) - 1);
        }
    };


    static const char *_basename(const char *filePath) {
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
    std::vector<_AllocationRecord> _Records;


    void *operator new(size_t allocSize,
                       const char *fileName,
                       unsigned long int lineNum) {
        _Records.push_back(_AllocationRecord(malloc(allocSize),
                                             fileName, lineNum,
                                             allocSize));
        return _Records.back().Pointer;
    }


    void *operator new[](size_t allocSize,
                         const char *fileName,
                         unsigned long int lineNum) {
        _Records.push_back(_AllocationRecord(malloc(allocSize),
                                             fileName, lineNum,
                                             allocSize));
        return _Records.back().Pointer;
    }


    void operator delete(void *pointer) {
        free(pointer);

        // A simple optimization; recently allocated memory blocks are more likely to be
        // de-allocated than older ones.
        // Since new allocation-records are stored at the end of the array, this gives us
        // a better average-case deletion time.
        for (auto it = _Records.end() - 1; it != _Records.begin(); ++it) {
            if (it->Pointer == pointer) {
                _Records.erase(it);
                return;
            }

        }
    }


    namespace forge {
    namespace memory {

        void init() {
            logging::out::print("Running the Forge global allocator in debug mode!");
        }

        void deInit() {
            logging::out::print("De-initializing the Forge global allocator!");

            if (_Records.empty()) {
                logging::out::print("No outstanding allocations remaining!");
            }
            else {
                logging::err::print("Outstanding allocations!");
                for (auto it = _Records.begin(); it != _Records.end(); ++it)
                    logging::err::print("Allocation (%p) (%lu bytes) at (%s:%d)",
                                        it->Pointer,
                                        it->AllocSize,
                                        _basename(it->FileName),
                                        it->LineNum);
            }
        }

    }   // namespace memory
    }   // namespace forge


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
