//Объединение подходов (1) - массив указателей, а сама матрица - одномерный массив
#include <stdlib.h>

//Выход: указатель на массив строк матрицы (p)
//следить за первым!
int allocate_matrix3(int ***ptrs, int n, int m)
{
    int *matrix = NULL;
    int **ptrs_tmp = NULL;

    ptrs_tmp = calloc(n, sizeof(int *));
    if (ptrs_tmp == NULL)
        return -1;
    matrix = calloc(n * m, sizeof(int));
    if (matrix == NULL)
    {
        free(ptrs_tmp);
        return -1;
    }
    for (int i = 0; i < n; i++)
        ptrs_tmp[i] = matrix + (i *m);
    *ptrs = ptrs_tmp;
    return 0;
}

// ПОТЕНЦИАЛЬНАЯ ОШИБКА
// Нулевой указатель может указывать не туда, куда надо
void free_matrix3(int **ptrs)
{
    free(ptrs[0]);
    free(ptrs);
}