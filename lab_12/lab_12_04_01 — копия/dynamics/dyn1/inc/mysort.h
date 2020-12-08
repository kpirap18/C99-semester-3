#ifndef _MYSORT_H_
#define _MYSORT_H_

#include "app.h"

int comparator_int(const void *p, const void *q);

void swap(void *first, void *second, size_t size);

void mysort(void *const first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif // _MYSORT_H_
