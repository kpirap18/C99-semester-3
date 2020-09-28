#include "../inc/mysort.h"

int compare(const void *x1, const void *x2)
{
    const int *a = x1;
    const int *b = x2;
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
void mysort(void *const first, size_t number, size_t size, int (*func_cmp)(const void *, const void *))
{
    char *pb = first;
    char *pe = (char *)first + (number - 1) * size;

    int flag = 1;

    while ((pb < pe) && flag > 0)
    {
        flag = 0;
        for (char *i = pb; i < pe; i += size)
        {
            if (func_cmp(i, i + size) > 0)
            {
                swap(i, i + size, size);
                flag = 1;
            }
        }
        pe -= size;

        for (char *i = pe; i > pb; i -= size)
        {
            if (func_cmp(i - size, i) > 0)
            {
                swap(i - size, i, size);
                flag = 1;
            }
        }
        pb += size;
    }
}
