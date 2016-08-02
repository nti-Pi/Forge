#include "release_alloc.hpp"

#include <cstdlib>


namespace forge {
namespace memory {
namespace release_alloc {

    void init() { }
    void deInit() { }


    void *alloc(size_t size) {
        return malloc(size);
    }


    void *allocArray(size_t size) {
        return malloc(size);
    }


    void deAlloc(void *ptr) {
        free(ptr);
    }


    void deAllocArray(void *ptr) {
        free(ptr);
    }


    void *reAlloc(void *ptr, size_t size) {
        return realloc(ptr, size);
    }

}   // namespace release_alloc
}   // namespace memory
}   // namespace forge
