#include <stdlib.h>
#include <math.h>
#include "mysort.h"

int comparator_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}
void swap(void *first, void *second, size_t size)
{
    char t;
    char *a = (char*)first;
    char *b = (char*)second;

    do
    {
        t = *a;
        *a++ = *b;
        *b++ = t;
    }while (--size > 0);
}
void mysort(void *const first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    char *pb = first;
    char *pe = (char *)first + (number - 1) * size;

    int flag = 1;

    while ((pb < pe) && flag > 0)
    {
        flag = 0;
        for (char *i = pb; i < pe; i += size)
        {
            if (comparator(i, i + size) > 0)
            {
                swap(i, i + size, size);
                flag = 1;
            }
        }
        pe -= size;

        for (char *i = pe; i > pb; i -= size)
        {
            if (comparator(i - size, i) > 0)
            {
                swap(i - size, i, size);
                flag = 1;
            }
        }
        pb += size;
    }
}
