#ifndef CGBASE_H_
#define CGBASE_H_
#pragma once

#include <float.h>

# if defined(_WIN32) || defined(__CYGWIN32__)
#  define __WIN32__ 1
# endif

#if !defined(CG_EXTERN)
#  if defined(__cplusplus)
#   define CG_EXTERN extern "C"
#  else
#   define CG_EXTERN extern
#  endif
#endif

#if !defined(CG_INLINE)
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define CG_INLINE static inline
# elif defined(__cplusplus)
#  define CG_INLINE static inline
# elif defined(__GNUC__)
#  define CG_INLINE static __inline__
# else
#  define CG_INLINE static    
# endif
#endif

#if defined(__LP64__) && __LP64__
# define CGFLOAT_TYPE double
# define CGFLOAT_IS_DOUBLE 1
# define CGFLOAT_MIN DBL_MIN
# define CGFLOAT_MAX DBL_MAX
#else
# define CGFLOAT_TYPE float
# define CGFLOAT_IS_DOUBLE 0
# define CGFLOAT_MIN FLT_MIN
# define CGFLOAT_MAX FLT_MAX
#endif

typedef CGFLOAT_TYPE CGFloat;
#define CGFLOAT_DEFINED 1

#if !defined(CG_PRIVATE_EXTERN)
# define CG_PRIVATE_EXTERN CG_LOCAL
#endif

// CGBASE_H_
#endif
