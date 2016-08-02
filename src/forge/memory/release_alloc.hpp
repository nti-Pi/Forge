#ifndef __HG__FORGE__MEMORY__RELEASEALLOC_HPP__
#define __HG__FORGE__MEMORY__RELEASEALLOC_HPP__

#include <cstdlib>


namespace forge {
namespace memory {
namespace release_alloc {

    void init();
    void deInit();

    void *alloc(size_t size);
    void *allocArray(size_t size);
    void  deAlloc(void *ptr);
    void  deAllocArray(void *ptr);

    void *reAlloc(void *ptr, size_t size);

}   // namespace release_alloc
}   // namespace memory
}   // namespace forge


#define forge_cmem_malloc(X)     forge::memory::release_alloc::alloc(X)
#define forge_cmem_realloc(X, S) forge::memory::release_alloc::reAlloc(X, S)
#define forge_cmem_free(X)       forge::memory::release_alloc::deAlloc(X)

#define forge_new        new
#define forge_del        delete

// Placement new:
#define forge_pnew(X)    new(X)


#endif // __HG__FORGE__MEMORY__RELEASEALLOC_HPP__

