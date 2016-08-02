#include "debug_alloc.hpp"

#include <cstdio>


namespace forge {
namespace memory {
namespace debug_alloc {

    static
    size_t _MaxHeapSize;


    void init(size_t maxHeapSize) {
        _MaxHeapSize = maxHeapSize;
    }


    void deInit() {

    }


    void *alloc(size_t size, const char *fileName, unsigned int lineNum) {
        return malloc(size);
    }


    void *allocArray(size_t size, const char *fileName, unsigned int lineNum) {
        return malloc(size);
    }


    void deAlloc(void *ptr) {
        free(ptr);
    }


    void deAllocArray(void *ptr) {
        free(ptr);
    }


    void *logAlloc(void *ptr) {
        return ptr;
    }


    void *reAlloc(void *ptr, size_t size) {
        return realloc(ptr, size);
    }

}   // namespace debug_alloc
}   // namespace memory
}   // namespace forge
