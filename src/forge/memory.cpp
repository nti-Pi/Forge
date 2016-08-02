#include "memory.hpp"


#ifdef __FORGE__DBG__

    namespace forge {
    namespace memory {

        void init(size_t maxHeapSize) {
            memory::debug_alloc::init(maxHeapSize);
        }


        void deInit() {
            memory::debug_alloc::deInit();
        }

    }   // namespace memory
    }   // namespace forge


    void *operator new   (size_t size, const char *fileName, unsigned int lineNum) {
        return forge::memory::debug_alloc::alloc(size, fileName, lineNum);
    }


    void *operator new [](size_t size, const char *fileName, unsigned int lineNum) {
        return forge::memory::debug_alloc::allocArray(size, fileName, lineNum);
    }


    void  operator delete  (void *ptr) throw () {
        forge::memory::debug_alloc::deAlloc(ptr);
    }


    void  operator delete [](void *ptr) throw () {
        forge::memory::debug_alloc::deAllocArray(ptr);
    }



#else

    namespace forge {
    namespace memory {

        void init() {
            memory::release_alloc::init();
        }


        void deInit() {
            memory::release_alloc::deInit();
        }

    }   // namespace memory
    }   // namespace forge


    void *operator new   (size_t size) {
        return forge::memory::release_alloc::alloc(size);
    }


    void *operator new [](size_t size) {
        return forge::memory::release_alloc::allocArray(size);
    }


    void  operator delete  (void *ptr) throw () {
        forge::memory::release_alloc::deAlloc(ptr);
    }


    void  operator delete [](void *ptr) throw () {
        forge::memory::release_alloc::deAllocArray(ptr);
    }

#endif
