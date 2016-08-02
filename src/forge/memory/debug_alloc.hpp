#ifndef __HG__FORGE__MEMORY__DEBUGALLOC_HPP__
#define __HG__FORGE__MEMORY__DEBUGALLOC_HPP__

#include <cstdlib>


namespace forge {
namespace memory {
namespace debug_alloc {

    void init(size_t maxHeapSize = (size_t)(-1));
    void deInit();

    void *alloc(size_t size, const char *fileName, unsigned int lineNum);
    void *allocArray(size_t size, const char *fileName, unsigned int lineNum);
    void  deAlloc(void *ptr);
    void  deAllocArray(void *ptr);

    void *logAlloc(void *ptr);
    void *reAlloc(void *ptr, size_t size);

}   // namespace debug_alloc
}   // namespace memory
}   // namespace forge


#define forge_cmem_malloc(X)                 forge::memory::debug_alloc::alloc(X, __FILE__, __LINE__)
#define forge_cmem_realloc(ptr, num_bytes)   forge::memory::debug_alloc::reAlloc(ptr, num_bytes)
#define forge_cmem_free(X)                   forge::memory::debug_alloc::deAlloc(X)

#define forge_new           new(__FILE__, __LINE__)
#define forge_del           delete

// Placement new:
#define forge_pnew(X)       new(forge::memory::debug_alloc::logAlloc(X))


#endif // __HG__FORGE__MEMORY__DEBUGALLOC_HPP__
