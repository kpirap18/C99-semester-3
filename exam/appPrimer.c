#include <stdio.h>
#include <stdlib.h>

#define OK          0
#define INPUTERR    -1
#define MEMORYERR   -2

// функции для ввода\вывода массива и размера
int input_size(FILE *f, int *n);
int input_array(FILE *f, int *a, int n);
void print_array(int *a, int n);

// функции для работы с массивом
int min_array(int *a, int n);
void swap(void *a, void *b, size_t size);

int main()
{
    int n = 0;
    int *array = NULL;

    int rc = OK;

    rc = input_size(stdin, &n);
    if (rc == OK)
    {
        array = malloc(sizeof(int) * n);
        if (array)
        {
            rc = input_array(stdin, array, n);
            if (rc == OK)
            {
                int min_i = min_array(array, n);
                swap(&array[0], &array[min_i], sizeof(int));
                print_array(array, n);
            }
            else
            {
                printf("Input error\n");
            }
            free(array);
        }
    }
    else
    {
        printf("Input error\n");
    }

    return rc;
}

int input_size(FILE *f, int *n)
{
    int rc = OK;
    if (fscanf(f, "%d", n) != 1)
    {
        rc = INPUTERR;
    }

    return rc;
}

int input_array(FILE *f, int *a, int n)
{
    int rc = OK;
    int buf;
    for (int i = 0; i < n; ++i)
    {
        if (fscanf(f, "%d", &buf) == 1)
        {
            a[i] = buf;
        }
        else
        {
            rc = INPUTERR;
            break;
        }
    }

    return rc;
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
}

int min_array(int *a, int n)
{
    int min = a[0];
    int min_i = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < min)
        {
            min = a[i];
            min_i = i;
        }
    }

    return min_i;
}

void swap(void *a, void *b, size_t size)
{
    char tmp;
    size_t i;
    for (i = 0; i < size; i++)
    {
        tmp = *((char*) b + i);
        *((char*) b + i) = *((char*) a + i);
        *((char*) a + i) = tmp;
    }
}
