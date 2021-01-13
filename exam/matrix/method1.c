//Матрица как одномерный массив
#include <stdlib.h>

int allocate_matrix1(int **data, int n, int m)
{
    int *data_tmp;
    data_tmp = calloc(n * m, sizeof(int));
    if (data_tmp)
    {
        *data = data_tmp;
        return 0;
    }
    else
        return -1;
}

void free_matrix1(int *data)
{
    free(data);
}
