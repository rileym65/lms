#ifndef _TYPES_H
#define _TYPES_H

#include <sys/types.h>

#ifdef MINGW

typedef char               Int8;
typedef short              Int16;
typedef int                Int32;
typedef long long          Int64;
typedef unsigned char      UInt8;
typedef unsigned short     UInt16;
typedef unsigned int       UInt32;
typedef unsigned long long UInt64;
typedef unsigned char      Byte;
typedef unsigned short     Word;
typedef unsigned int       Dword;
typedef unsigned long long Qword;
typedef double             Double;
typedef float              Single;
typedef bool               Boolean;

#else

typedef int8_t    Int8;
typedef int16_t   Int16;
typedef int32_t   Int32;
typedef int64_t   Int64;
typedef u_int8_t  UInt8;
typedef u_int16_t UInt16;
typedef u_int32_t UInt32;
typedef u_int64_t UInt64;
typedef u_int8_t  Byte;
typedef u_int16_t Word;
typedef u_int32_t Dword;
typedef u_int64_t Qword;
typedef double    Double;
typedef float     Single;
typedef bool      Boolean;

#endif

#endif

