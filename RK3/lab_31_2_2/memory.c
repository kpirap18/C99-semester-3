#include "memory.h"

int **allocate_matrix(int n, int m)
{
    int **data = (int **)malloc(n * sizeof(int*) + n * m * sizeof(int));

    if (!data)
    {
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        data[i] = (int*)((char*)data + n * sizeof(int*) + i * m * sizeof(int));
    }

    return data;
}