// Copyright 2014 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// kernel_default.h: Chooses default GEMM and GEMV kernels for the
// host platform.

#ifndef GEMMLOWP_INTERNAL_KERNEL_DEFAULT_H_
#define GEMMLOWP_INTERNAL_KERNEL_DEFAULT_H_

#include "internal/common.h"

#ifdef GEMMLOWP_NEON
#include "internal/kernel_neon.h"
namespace gemmlowp {
typedef NEONKernel12x4Depth2 DefaultKernelForGEMM;
typedef NEONKernel8x1Depth4 DefaultKernelForGEMV;
}
#else
#include "internal/kernel_reference.h"
namespace gemmlowp {
typedef ReferenceKernel<KernelFormat<KernelSideFormat<CellFormat<4, 4>, 2>,
                                     KernelSideFormat<CellFormat<4, 4>, 2> > >
    DefaultKernelForGEMM;
typedef ReferenceKernel<KernelFormat<KernelSideFormat<CellFormat<4, 4>, 2>,
                                     KernelSideFormat<CellFormat<1, 4>, 1> > >
    DefaultKernelForGEMV;
}
#endif

#endif  // GEMMLOWP_INTERNAL_KERNEL_DEFAULT_H_
