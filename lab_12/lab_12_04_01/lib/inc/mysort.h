#ifndef _MYSORT_H_
#define _MYSORT_H_

#include "app.h"

#ifdef STATICS
#define SORT_DLL
#define SORT_DECL
#else
#ifdef EXPORTS
#define SORT_DLL __declspec(dllexport)
#define SORT_DECL __cdecl
#else
#define SORT_DLL __declspec(dllimport)
#define SORT_DECL __cdecl
#endif
#endif

SORT_DLL int SORT_DECL comparator_int(const void *p, const void *q);

SORT_DLL void SORT_DECL swap(void *first, void *second, size_t size);

SORT_DLL void SORT_DECL mysort(void *const first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif // _MYSORT_H_
