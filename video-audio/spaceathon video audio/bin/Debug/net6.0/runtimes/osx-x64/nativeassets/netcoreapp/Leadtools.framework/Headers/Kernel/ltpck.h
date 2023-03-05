//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if defined(_MSC_VER)
#pragma warning(disable: 4103)  // alignment changed after including header, may be due to missing #pragma pack(pop)
#elif defined(FOR_XCODE)
#pragma GCC diagnostic ignored "-Wpragma-pack"
#endif

#if defined(L_HEADER_ENTRY)

   #if defined(__cplusplus)
      extern "C"
      {
   #endif // #if defined(__cplusplus)

   #if !defined(RC_INVOKED)
      #pragma pack(push, 1)
   #endif // #if !defined(RC_INVOKED)

#elif defined(L_HEADER_ENTRY8_)

   #if defined(__cplusplus)
      extern "C++"
      {
   #endif // #if defined(__cplusplus)

   #if !defined(RC_INVOKED)
      #pragma pack(push, 8)
   #endif // #if !defined(RC_INVOKED)

#else

   #if !defined(RC_INVOKED)
      #pragma pack(pop)
   #endif // #if !defined(RC_INVOKED)

   #if defined(__cplusplus)
      } // extern "C"
   #endif // #if defined(__cplusplus)

#endif
