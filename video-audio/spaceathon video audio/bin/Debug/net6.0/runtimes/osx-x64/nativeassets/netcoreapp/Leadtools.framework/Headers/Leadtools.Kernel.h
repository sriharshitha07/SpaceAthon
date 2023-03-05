// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  Leadtools.Kernel.h
//  Leadtools
//

#if !defined(LEADTOOLS_KERNEL_H)
#define LEADTOOLS_KERNEL_H

#if !defined(LEADTOOLS_KERNEL_FRAMEWORK)
#  define LEADTOOLS_KERNEL_FRAMEWORK
#endif // #if !defined(LEADTOOLS_KERNEL_FRAMEWORK)

#if !defined(LT_COMP_UNICODE)
#  define LT_COMP_UNICODE
#endif // #if !defined(LT_COMP_UNICODE)

#if !defined(LEADTOOLS_EXPORT)
#  if defined(__cplusplus)
#     define LEADTOOLS_EXPORT extern "C"
#  else
#     define LEADTOOLS_EXPORT extern
#  endif
#endif

#include <Leadtools/Kernel/ltkrn.h>
#include <Leadtools/Kernel/ltdis.h>
#include <Leadtools/Kernel/ltfil.h>
#include <Leadtools/Kernel/ltbar.h>
#include <Leadtools/Kernel/ltocr.h>
#include <Leadtools/Kernel/ltdocwrt.h>
#include <Leadtools/Kernel/ltspellcheck.h>
#include <Leadtools/Kernel/ltsvg.h>
#include <Leadtools/Kernel/ltimgclr.h>
#include <Leadtools/Kernel/ltimgcor.h>
#include <Leadtools/Kernel/ltimgefx.h>

#if __has_include(<Leadtools/Kernel/ltclr.h>)
#  include <Leadtools/Kernel/ltclr.h>
#endif

#if __has_include(<Leadtools/Kernel/ltdic.h>)
#  include <Leadtools/Kernel/ltdic.h>
#endif

#if __has_include(<Leadtools/Kernel/ltjp2.h>)
#  include <Leadtools/Kernel/ltjp2.h>
#endif

#if __has_include(<Leadtools/Kernel/ltvkrn.h>)
#  include <Leadtools/Kernel/ltvkrn.h>
#endif

#endif // #if !defined(LEADTOOLS_KERNEL_H)
