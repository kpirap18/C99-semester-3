/*
Считать мактрицу и записать 2 способом.
Создать массив, где будут первый четный элемент каждой строки.
Если четного нет, то 0.
*/

#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define INPUTERR -1
#define MEMORYERR -2

void free_matrix2(int **ptrs, int n)
{
    for (int i = 0; i < n; i++)
       free(ptrs[i]);
    free(ptrs);
}

void print_array(int *arr, int m)
{
    for (int j = 0; j < m; ++j)
    {
        printf("%d ", arr[j]);
    }
}

int allocate_matrix(int ***ptrs, int n, int m)
{
    int **ptrs_tmp = calloc(n, sizeof(int *));
    if (ptrs_tmp == NULL)
        return -1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            ptrs_tmp[i] = calloc(m, sizeof(int));
            if (ptrs_tmp[i] == NULL)
            {
                free_matrix2(ptrs_tmp, n);
                return -1;
            }
        }
        *ptrs = ptrs_tmp;
        return 0;
    }
}

int is_even(int n)
{
    return (n % 2 == 0) ? 1 : 0;
}

int find_even_row(int *array, int m)
{
    int even = 0;
    for (int i = 0; i < m; ++i)
    {
        if (is_even(array[i]))
        {
            even = array[i];
            break;
        }
    }

    return even;
}

int make_even_arr(int **matr, int **arr, int n, int m)
{
    int even = 0;
    *arr = malloc(n * sizeof(int));

    if (!(*arr))
    {
        return MEMORYERR;
    }

    for (int i = 0; i < n; ++i)
    {
        (*arr)[i] = find_even_row(matr[i], m);
    }

    return OK;
}

int read_size(FILE *f, int *n, int *m)
{
    int rc = OK;

    if (fscanf(f, "%d", n) != 1 || *n <= 0)
    {
        rc = INPUTERR;
        return rc;
    }

    if (fscanf(f, "%d", m) != 1 || *m <= 0)
    {
        rc = INPUTERR;
        return rc;
    }

    return OK;
}

int read_matrix(FILE *f, int ***matrix, int n, int m)
{
    int rc = OK;
    int mat;
    int **tmp = NULL;

    rc = allocate_matrix(&tmp, n, m);
    if (rc == OK)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (fscanf(f, "%d", &mat)!= 1)
                {
                    rc = INPUTERR;
                }
                tmp[i][j] = mat;
            }
        }
        if (rc != INPUTERR)
        {
            *matrix = tmp;
        }
    }
    else
    {
        *matrix = NULL;
        rc = MEMORYERR;
    } 

    return rc;
}

int main()
{
    int rc = OK;
    int n, m;
    int **matr = NULL;
    rc = read_size(stdin, &n, &m);

    if (rc == OK)
    {
        rc = read_matrix(stdin, &matr, n, m);
        if (rc == OK)
        {
            int *arr = NULL;
            rc = make_even_arr(matr, &arr, n, m);
            if (rc == OK)
            {
                print_array(arr, n);
                free(arr);
            }
            free_matrix2(matr, n);
        }
        else
        {
            printf("Input error\n");
        }
    }
    else
    {
        printf("Input error\n");
    }

}