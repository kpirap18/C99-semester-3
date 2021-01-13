/*
Функция set_len единая функция, которая управляет памятью
Принять длинну массива, принять элементы массива,
распечатать массив, вставить после каждого элемента меньше 
среднего арифметического, среднее арифмитическог массива
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERRMEM -1
#define ERRPARAM -2
#define ERRINPUT -3

size_t set_len(double **arr, size_t len, size_t newlen)
{
    size_t rc = OK;
    double *arr_tmp = *arr;
    if ((arr_tmp == NULL) && (len == 0) && (newlen > 0))
    {
        arr_tmp = malloc(newlen * sizeof(double));
        if (!arr_tmp)
            rc = ERRMEM;
    }
    else if ((arr_tmp != NULL) && (len > 0) && (newlen > 0))
    {
        arr_tmp = realloc(*arr, newlen);
        if (!arr_tmp)
            rc = ERRMEM;
    }
    else if ((arr_tmp != NULL) && (len > 0) && (newlen == 0))
    {
        free(arr_tmp);
        arr_tmp = NULL;
    }
    else
        rc = ERRPARAM;

    if (rc == OK)
    {
        rc = newlen;
        *arr = arr_tmp;
    }
    printf("rc alloc %zu\n", rc);
    return rc;
}


int input_arr(FILE *f, size_t *n, double **arr)
{
    int rc = OK;
    double *arr_tmp;

    size_t n_tmp = 0;

    if ((fscanf(f, "%zu", &n_tmp) == 1) && (n_tmp > 0))
    {
        n_tmp = set_len(&arr_tmp, 0, n_tmp);
        if (n_tmp > 0)
        {
            for (size_t i = 0; (i < n_tmp) && (rc == OK); i++)
            {
                if (fscanf(f, "%lf", (arr_tmp +i)) != 1)
                    rc = ERRINPUT;
            }
        }
    }
    else
        rc = ERRINPUT;

    if (rc == OK)
    {
        *arr = arr_tmp;
        *n = n_tmp;
    }
    else if (n_tmp > 0)
        n_tmp = set_len(&arr_tmp, n_tmp, 0);

    return rc;
}

void print_arr(FILE *f, size_t n, double *arr)
{
    for (size_t i = 0; i < n; i++)
        fprintf(f, "%lf ", arr[i]);
}

int main(void)
{
    setbuf(stdout, NULL);
    int rc = OK;
    double *arr = NULL;
    size_t n = 0;

    rc = input_arr(stdin, &n, &arr);
    if (rc == OK)
    {
        fprintf(stdin, "Got array:\n");
        print_arr(stdin, n, arr);


    }
    return rc;
}