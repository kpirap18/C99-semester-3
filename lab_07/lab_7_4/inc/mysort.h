#ifndef MYSORT_H
#define MYSORT_H

#include "my_main.h"

int compare(const void *x1, const void *x2);
void swap(void *first, void *second, size_t size);
void mysort(void *const first, size_t number, size_t size, int (*func_cmp)(const void *, const void *));

#endif // MYSORT_H
