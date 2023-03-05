//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTVER_H)
#define LTVER_H

#if defined(LTV21_CONFIG)
#define LTVER_   2100
#define L_VER_DESIGNATOR "21"
#define L_VER_DESIGNATOR_STR "21"
#elif defined(LTV22_CONFIG)
#define LTVER_   2200
#define L_VER_DESIGNATOR "22"
#define L_VER_DESIGNATOR_STR "22"
#else
// You must define LTV##_CONFIG before including any LEADTOOLS header files
// For example:
// #define LTV21_CONFIG    // Using LEADTOOLS v21
// or
// #define LTV22_CONFIG    // Using LEADTOOLS v22
#if !defined(RC_INVOKED)
#error LEADTOOLS Vxx_CONFIG not found!
#endif // #if !defined(RC_INVOKED)
#endif // #if defined(LTV15_CONFIG)

#define LEADTOOLS_V16_OR_LATER
#define LEADTOOLS_V17_OR_LATER
#define LEADTOOLS_V175_OR_LATER
#define LEADTOOLS_V18_OR_LATER
#define LEADTOOLS_V19_OR_LATER
#define LEADTOOLS_V20_OR_LATER
#define LEADTOOLS_V21_OR_LATER

#if LTVER_ >= 2200
#define LEADTOOLS_V22_OR_LATER
#endif

#if defined(FOR_UWP)
   #define L_PLATFORM_DESIGNATOR "UWPUnmanaged"
#else
   #define L_PLATFORM_DESIGNATOR "CDLL"
#endif

#ifdef FOR_DEBUG
#define L_DEBUG_SUBFOLDER  "\\Debug"
#else
#define L_DEBUG_SUBFOLDER  ""
#endif // #ifdef FOR_DEBUG

#if defined(FOR_WIN64) || defined(FOR_UWP64)
#define L_LIB_SUBFOLDER  "x64"
#define L_LIB_SUFFIX "x"
#elif defined(FOR_WIN32) || defined(FOR_UWP32)
#define L_LIB_SUBFOLDER  "Win32"
#define L_LIB_SUFFIX "u"
#elif defined(FOR_UWPARM)
#define L_LIB_SUBFOLDER  "ARM"
#endif // #if defined(FOR_WIN64)

#define L_BIN_SUBFOLDER L_LIB_SUBFOLDER L_DEBUG_SUBFOLDER

#define L_DOTNET_FOLDER "DotNet4"

#endif // #if !defined(LTVER_H)
