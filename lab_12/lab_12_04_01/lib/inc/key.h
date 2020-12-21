#ifndef _KEY_H_
#define _KEY_H_

#include "app.h"

#ifdef STATICS
#define KEY_DLL
#define KEY_DECL
#else
#ifdef EXPORTS
#define KEY_DLL __declspec(dllexport)
#define KEY_DECL __cdecl
#else
#define KEY_DLL __declspec(dllimport)
#define KEY_DECL __cdecl
#endif
#endif


KEY_DLL double KEY_DECL avarage(const int *pb, const int *pe);

KEY_DLL int KEY_DECL key_count(const int *pb, const int *pe, double(*func)(const int*, const int*));

KEY_DLL int KEY_DECL key(const int *pb_src, int len, int *pb_dst, int *len_key, double(*func)(const int*, const int*));

#endif // _KEY_H_
