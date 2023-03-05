// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLeadtools.h
//  Leadtools
//

#if !defined(LTLEADTOOLS_H)
#define LTLEADTOOLS_H

#if !defined(LTVLATEST_CONFIG)
#  define LTVLATEST_CONFIG LTV20_CONFIG
#  define LTVERLATEST_ 2000
#  define L_VERLATEST_DESIGNATOR "20"
#endif

#if !defined(LTVER_)
#  if defined(LTV18_CONFIG)
#    define LTVER_ 1800
#    define L_VER_DESIGNATOR "18"
#  elif defined(LTV19_CONFIG)
#    define LTVER_ 1900
#    define L_VER_DESIGNATOR "19"
#  elif defined(LTV20_CONFIG)
#    define LTVER_ 2000
#    define L_VER_DESIGNATOR "20"
#  else
#    define LTVER_ LTVERLATEST_
#    define L_VER_DESIGNATOR L_VERLATEST_DESIGNATOR
#    define LTV20_CONFIG
#  endif

#  if LTVER_ >= 1600
#    define LEADTOOLS_V16_OR_LATER
#  endif
#  if LTVER_ >= 1700
#    define LEADTOOLS_V17_OR_LATER
#  endif
#  if LTVER_ >= 1750
#    define LEADTOOLS_V175_OR_LATER
#  endif
#  if LTVER_ >= 1800
#    define LEADTOOLS_V18_OR_LATER
#  endif
#  if LTVER_ >= 1900
#    define LEADTOOLS_V19_OR_LATER
#  endif
#  if LTVER_ >= 2000
#    define LEADTOOLS_V20_OR_LATER
#  endif
#endif



#define LT_AVAILABLE(_mac, _ios, _ltVersion) LT_AVAILABLE_##_ltVersion(_mac, _ios) // Available starting LEADTOOLS *ltVersion*
#define LT_ENUM_AVAILABLE(_mac, _ios, _ltVersion) LT_AVAILABLE_##_ltVersion(_mac, _ios) // Enum available starting LEADTOOLS *ltVersion*
#define LT_CLASS_AVAILABLE(_mac, _ios, _ltVersion) LT_CLASS_AVAILABLE_##_ltVersion(_mac, _ios) // Class available starting LEADTOOLS *ltVersion*

#define LT_DEPRECATED(ltVersion, ...) LT_DEPRECATED_##ltVersion(__VA_ARGS__) // Deprecated starting LEADTOOLS *ltVersion*
#define LT_DEPRECATED_USENEW(ltVersion, alternative) LT_DEPRECATED_USENEW_##ltVersion(alternative) // Deprecated starting LEADTOOLS *ltVersion*
#define LT_ENUM_DEPRECATED(ltVersion, ...)  LT_ENUM_DEPRECATED_##ltVersion(__VA_ARGS__) // Enum deprecated starting LEADTOOLS *ltVersion*

#define LT_UNAVAILABLE(ltVersion, ...) LT_UNAVAILABLE_##ltVersion(__VA_ARGS__) // Unavailable starting LEADTOOLS *ltVersion*
#define LT_UNAVAILABLE_USENEW(ltVersion, alternative) LT_UNAVAILABLE_USENEW_##ltVersion(alternative) // Unavailable starting LEADTOOLS *ltVersion*



#if defined(LEADTOOLS_V18_OR_LATER)
#   define LT_AVAILABLE_18_0(_mac, _ios)       NS_AVAILABLE(_mac, _ios)
#   define LT_ENUM_AVAILABLE_18_0(_mac, _ios)  NS_ENUM_AVAILABLE(_mac, _ios)
#   define LT_CLASS_AVAILABLE_18_0(_mac, _ios) NS_CLASS_AVAILABLE(_mac, _ios)
#
#   define LT_DEPRECATED_18_0(...)                __deprecated_msg("Deprecated starting LEADTOOLS 18.0. " __VA_ARGS__) OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 18.0. " __VA_ARGS__)
#   define LT_DEPRECATED_USENEW_18_0(alternative) __deprecated_msg("Deprecated starting LEADTOOLS 18.0. Use '" alternative "' instead.") OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 18.0. Use '" alternative "' instead.")
#   define LT_ENUM_DEPRECATED_18_0(...)           __deprecated_msg("Deprecated starting LEADTOOLS 18.0. " __VA_ARGS__) OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 18.0. " __VA_ARGS__)
#
#   define LT_UNAVAILABLE_18_0(...)              __attribute__((unavailable("Unavailable starting LEADTOOLS 18.0. " __VA_ARGS__)))
#   define LT_UNAVAILABLE_USENEW_18_0(alternate) __attribute__((unavailable("Unavailable starting LEADTOOLS 18.0. Use '" alternate "' instead.")))
#else
#   define LT_AVAILABLE_18_0(_mac, _ios)       __attribute__((unavailable("Unavailable until LEADTOOLS 18.0")))
#   define LT_ENUM_AVAILABLE_18_0(_mac, _ios)  __attribute__((unavailable("Unavailable until LEADTOOLS 18.0")))
#   define LT_CLASS_AVAILABLE_18_0(_mac, _ios) __attribute__((unavailable("Unavailable until LEADTOOLS 18.0")))
#
#   define LT_DEPRECATED_18_0(...)
#   define LT_DEPRECATED_USENEW_18_0(alternative)
#   define LT_ENUM_DEPRECATED_18_0(...)
#
#   define LT_UNAVAILABLE_18_0(...)
#   define LT_UNAVAILABLE_USENEW_18_0(alternate)
#endif

#if defined(LEADTOOLS_V19_OR_LATER)
#   define LT_AVAILABLE_19_0(_mac, _ios)       NS_AVAILABLE(_mac, _ios)
#   define LT_ENUM_AVAILABLE_19_0(_mac, _ios)  NS_ENUM_AVAILABLE(_mac, _ios)
#   define LT_CLASS_AVAILABLE_19_0(_mac, _ios) NS_CLASS_AVAILABLE(_mac, _ios)
#
#   define LT_DEPRECATED_19_0(...)                __deprecated_msg("Deprecated starting LEADTOOLS 19.0. " __VA_ARGS__) OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 19.0. " __VA_ARGS__)
#   define LT_DEPRECATED_USENEW_19_0(alternative) __deprecated_msg("Deprecated starting LEADTOOLS 19.0. Use '" alternative "' instead.") OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 19.0. Use '" alternative "' instead.")
#   define LT_ENUM_DEPRECATED_19_0(...)           __deprecated_msg("Deprecated starting LEADTOOLS 19.0. " __VA_ARGS__) OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 19.0. " __VA_ARGS__)
#
#   define LT_UNAVAILABLE_19_0(...)              __attribute__((unavailable("Unavailable starting LEADTOOLS 19.0. " __VA_ARGS__)))
#   define LT_UNAVAILABLE_USENEW_19_0(alternate) __attribute__((unavailable("Unavailable starting LEADTOOLS 19.0. Use '" alternate "' instead.")))
#else
#   define LT_AVAILABLE_19_0(_mac, _ios)       __attribute__((unavailable("Unavailable until LEADTOOLS 19.0")))
#   define LT_ENUM_AVAILABLE_19_0(_mac, _ios)  __attribute__((unavailable("Unavailable until LEADTOOLS 19.0")))
#   define LT_CLASS_AVAILABLE_19_0(_mac, _ios) __attribute__((unavailable("Unavailable until LEADTOOLS 19.0")))
#
#   define LT_DEPRECATED_19_0(...)
#   define LT_DEPRECATED_USENEW_19_0(alternative)
#   define LT_ENUM_DEPRECATED_19_0(...)
#
#   define LT_UNAVAILABLE_19_0(...)
#   define LT_UNAVAILABLE_USENEW_19_0(alternate)
#endif

#   define LT_AVAILABLE_20_0(_mac, _ios)       NS_AVAILABLE(_mac, _ios)
#   define LT_ENUM_AVAILABLE_20_0(_mac, _ios)  NS_ENUM_AVAILABLE(_mac, _ios)
#   define LT_CLASS_AVAILABLE_20_0(_mac, _ios) NS_CLASS_AVAILABLE(_mac, _ios)
#
#   define LT_DEPRECATED_20_0(...)                __deprecated_msg("Deprecated starting LEADTOOLS 20.0. " __VA_ARGS__) OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 20.0. " __VA_ARGS__)
#   define LT_DEPRECATED_USENEW_20_0(alternative) __deprecated_msg("Deprecated starting LEADTOOLS 20.0. Use '" alternative "' instead.") OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 20.0. Use '" alternative "' instead.")
#   define LT_ENUM_DEPRECATED_20_0(...)           __deprecated_msg("Deprecated starting LEADTOOLS 20.0. " __VA_ARGS__) OBJC_SWIFT_UNAVAILABLE("Deprecated starting LEADTOOLS 20.0. " __VA_ARGS__)
#
#   define LT_UNAVAILABLE_20_0(...)              __attribute__((unavailable("Unavailable starting LEADTOOLS 20.0. " __VA_ARGS__)))
#   define LT_UNAVAILABLE_USENEW_20_0(alternate) __attribute__((unavailable("Unavailable starting LEADTOOLS 20.0. Use '" alternate "' instead.")))



#if !defined(LEADTOOLS_EXPORT)
#   if defined(__cplusplus)
#       define LEADTOOLS_EXPORT extern "C" __attribute__((visibility("default")))
#   else
#       define LEADTOOLS_EXPORT extern __attribute__((visibility("default")))
#   endif
#endif



#if !defined(LT_BOXABLE)
#   if defined(__has_attribute) && __has_attribute(objc_boxable)
#       define LT_BOXABLE __attribute__((objc_boxable))
#   else
#       define LT_BOXABLE
#   endif
#endif

#endif // #if !defined(LTLEADTOOLS_H)
