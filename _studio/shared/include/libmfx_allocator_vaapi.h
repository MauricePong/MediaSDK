// Copyright (c) 2017 Intel Corporation
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "mfx_common.h"

#if defined (MFX_VA_LINUX)

#ifndef _LIBMFX_ALLOCATOR_VAAPI_H_
#define _LIBMFX_ALLOCATOR_VAAPI_H_

#include <va/va.h>

#include "mfxvideo++int.h"
#include "libmfx_allocator.h"

// VAAPI Allocator internal Mem ID
struct vaapiMemIdInt
{
    VASurfaceID* m_surface;
    VAImage m_image;
    unsigned int m_fourcc;
};

// Internal Allocators 
namespace mfxDefaultAllocatorVAAPI
{
    mfxStatus AllocFramesHW(mfxHDL pthis, mfxFrameAllocRequest *request, mfxFrameAllocResponse *response);
    mfxStatus LockFrameHW(mfxHDL pthis, mfxMemId mid, mfxFrameData *ptr);
    mfxStatus GetHDLHW(mfxHDL pthis, mfxMemId mid, mfxHDL *handle);
    mfxStatus UnlockFrameHW(mfxHDL pthis, mfxMemId mid, mfxFrameData *ptr=0);
    mfxStatus FreeFramesHW(mfxHDL pthis, mfxFrameAllocResponse *response);

    mfxStatus SetFrameData(const VAImage &va_image, mfxU32 mfx_fourcc, mfxU8* pBuffer, mfxFrameData*  ptr);

    class mfxWideHWFrameAllocator : public  mfxBaseWideFrameAllocator
    {
    public:
        mfxWideHWFrameAllocator(mfxU16 type, mfxHDL handle);
        virtual ~mfxWideHWFrameAllocator(void){};

        VADisplay* pVADisplay;

//        VASurfaceID* m_SrfQueue;
//        vaapiMemIdInt* m_SrfQueue;

        mfxU32 m_DecId;
    };

} //  namespace mfxDefaultAllocatorVAAPI

#endif // LIBMFX_ALLOCATOR_VAAPI_H_
#endif // (MFX_VA_LINUX)
/* EOF */
