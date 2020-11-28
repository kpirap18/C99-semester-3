#include "oper.h"
#include "io.h"

static int sum_num(int a)
{
    a = abs(a);
    int sum = 0;
    if (a == 0)
    {
        return 0;
    }

    while (a)
    {
        sum += a % 10;
        a = a / 10;
    }

    return sum;
}

static void my_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (sum_num(a[j - 1]) > sum_num(a[j]))
            {
                int buf = a[j - 1];
                a[j - 1] = a[j];
                a[j] = buf;
            }
        }
    }
}

int arr_len(int **matrix, int n, int m)
{
    int len_arr = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (sum_num(matrix[i][j]) > 10)
            {
                len_arr++;
            }
        }
    }

    return len_arr;
}

void arr_to_matrix(int **matrix, int *arr, int n, int m)
{
    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (sum_num(matrix[i][j]) > 10)
            {
                matrix[i][j] = arr[k];
                k++;
            }
        }
    }

}

void matrix_to_arr(int **matrix, int *arr, int n, int m)
{
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (sum_num(matrix[i][j]) > 10)
            {
                arr[k] = matrix[i][j];
                k++;
            }
        }
    }
}

int *arr_new(int **matrix, int n, int m)
{
    int *tmp;
    int len = arr_len(matrix, n, m);

    if (len == 0)
    {
        return NULL;
    }

    tmp = malloc(len * sizeof(int));
    if (!tmp)
    {
        return NULL;
    }
    else
    {
        matrix_to_arr(matrix, tmp, n , m);
        my_sort(tmp, len);
    }

    return tmp;
}

int matrix_new(int **matrix, int n, int m)
{
    int *tmp = NULL;
    if (matrix == NULL || n == 0 || m == 0)
    {
        return ERROR;
    }

    tmp = arr_new(matrix, n, m);

    if (!tmp)
    {
        return MEMERROR;
    }
    else
    {
        arr_to_matrix(matrix, tmp, n, m);

        free(tmp);
    }

    return OK;    
}
