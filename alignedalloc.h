#ifndef COBALT_COBALT_ALIGNEDALLOC_H_
#define COBALT_COBALT_ALIGNEDALLOC_H_

#include <cstdlib>
#include <cstddef>

namespace cobalt
{
    template <typename T>
    inline T *alignedAlloc(size_t size, size_t align = 16)
    {
        void *ptr;
#if defined(_MSC_VER)
        ptr = _aligned_malloc(size, align);
#else
        if (::posix_memalign(&ptr, align, size))
        {
            return NULL;
        }
#endif
        return static_cast<T*>(ptr);
    }
};

#endif

#test 2