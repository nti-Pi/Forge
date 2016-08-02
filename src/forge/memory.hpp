#ifndef __HG__FORGE__MEMORY_HPP__
#define __HG__FORGE__MEMORY_HPP__


#ifdef __FORGE__DBG__

    #include "memory/debug_alloc.hpp"

    namespace forge {
    namespace memory {

        void init(size_t maxHeapSize = (size_t)(-1));
        void deInit();

    }   // namespace memory
    }   // namespace forge

    void *operator new      (size_t size, const char *fileName, unsigned int lineNum);
    void *operator new    [](size_t size, const char *fileName, unsigned int lineNum);
    void  operator delete   (void *ptr) throw ();
    void  operator delete [](void *ptr) throw ();

#else

    #include "memory/release_alloc.hpp"

    namespace forge {
    namespace memory {

        void init();
        void deInit();

    }   // namespace memory
    }   // namespace forge


    void *operator new   (size_t size);
    void *operator new [](size_t size);
    void  operator delete   (void *ptr) throw ();
    void  operator delete [](void *ptr) throw ();

#endif // __FORGE__DBG__


#endif // __HG__FORGE__MEMORY_HPP__
