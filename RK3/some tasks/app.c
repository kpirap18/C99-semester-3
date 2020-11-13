#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define OK 0

void print(double **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%.6lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*double **allocate_matrix(int n, int m)
{
    double **ptrs, *data;

    ptrs = malloc(n * sizeof(double*));

    if (!ptrs)
    {
        return NULL;
    }

    data = malloc(n * m * sizeof(double));

    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        ptrs[i] = data + i * m;
    }

    return ptrs;
}*/

double **allocate_matrix(int n, int m)
{
    double **data = (double**)malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*)data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}

void full_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = i + 1;
        }
    }
}

void shift_rows(double **matrix, int n, int m, int row)
{
    double *tmp;

    for (int i = row; i < n - 1; ++i)
    {
        tmp = matrix[i];
        matrix[i] = matrix[i + 1];
        matrix[i + 1] = tmp;
    }
}

void shift_col(double **matrix, int n, int m, int col)
{
    int tmp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = col; j < m - 1; ++j)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][j + 1];
            matrix[i][j + 1] = tmp;
        }
    }
}

/*int del_row(double ***matrix, int n, int m)
{
    //ree(matrix[n - 1]);

    double **tmp = realloc(*matrix, sizeof(double *) * (n - 1) * m);

    if (!tmp)
    {
        return -1;
    }

    *matrix = tmp;

    return OK;
}

int del_col(double ***matrix, int n, int m)
{
    double **tmp = realloc(*matrix, sizeof(double *) * (m - 1) * n);

    if (!tmp)
    {
        return -1;
    }

    *matrix = tmp;

    return OK;
}*/

int del_row(double ***matrix, int n, int m)
{
    double **tmp = realloc(*matrix, (n - 1) * sizeof(double*) + (n - 1) * m * sizeof(double));

    if (!tmp)
    {
        return -1;
    }

    for (int i = 0; i < n - 1; i++)
        tmp[i] = (double*)((char*)tmp + (n - 1) * sizeof(double*) + i * m * sizeof(double));

    *matrix = tmp;
    return OK;
}

int del_col(double ***matrix, int n, int m)
{
    double **tmp = realloc(*matrix, n * sizeof(double*) + n * (m - 1) * sizeof(double));

    if (!tmp)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
        tmp[i] = (double*)((char*)tmp + n * sizeof(double*) + i * (m - 1) * sizeof(double));

    *matrix = tmp;
    return OK;
}

void free_matrix(double **matrix)
{
    free(matrix[0]);
    free(matrix);
}

int main()
{
    double **matrix_1 = NULL;
    int n = 5, m = 5;

    matrix_1 = allocate_matrix(n, m);

    if (matrix_1)
    {
        full_matrix(matrix_1, n, m);
        print(matrix_1, n, m);
        printf("\n\n");

        shift_rows(matrix_1, n, m, 3);
        print(matrix_1, n, m);
        printf("\n\n");

        int rc = del_row(&matrix_1, n, m);
        n = n - 1;
        print(matrix_1, n, m);
        printf("\n\n");
        printf("rc = %d\n", rc);

        // shift_col(matrix_1, n, m, 0);
        // print(matrix_1, n, m);
        // printf("\n\n");

        rc = del_col(&matrix_1, n, m);
        m = m - 1;
        print(matrix_1, n, m);
        printf("\n\n");
        printf("rc = %d\n", rc);

        //free_matrix(matrix_1);
        free(matrix_1);
    }
    return OK;
}

int filelen(FILE *f)
{
    int num, len = 0;
    
    fseek(f , 0L, SEEK_SET); 
    
    while (fscanf(f, "%d", &num) == 1)
    {
        len++;
    }
    
    fseek(f , 0, SEEK_SET); 
    
    return len;
}

int file_size(FILE *f)
{
    int for_read, len = 0;

    while (!feof(f))
    {
        if (fscanf(f, "%d", &for_read) == 1)
        {
            len += 1;
        }
        else if (!feof(f))
        {
            len = 0;
            break;
        }
    }

    return len;
}

int read_info_mat(FILE *f, int *n, int *m)
{
    int rc = OK;

    rc = fscanf(f, "%d", n);
    if (rc != 1 || *n <= 0)
    {
        rc = FILE_READ_ERR;
        return rc;
    }

    rc = fscanf(f, "%d", m);
    if (rc != 1 || *m <= 0)
    {
        rc = FILE_READ_ERR;
        return rc;
    }

    return OK;
}

int read_matrix(FILE *f, double **matrix, int n, int m)
{
    int rc;
    double mat_val;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rc = fscanf(f, "%lf", &mat_val);
            if (rc != 1)
            {
                rc = FILE_READ_ERR;
                return rc;
            }
            matrix[i][j] = mat_val;
        }
    }

    return OK;
}

void print_matrix(FILE *f, double **matrix, int n, int m)
{
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%.6lf ", matrix[i][j]);
        fprintf(f, "\n");
    }
}

void parsing_to_file(int *pb, int *pe, FILE *f_out)
{
    while (pb < pe)
    {
        fprintf(f_out, "%d ", *pb);
        pb++;
    }
}
void parsing_array(FILE *f, int *pb)
{
    int for_read;
    while (fscanf(f, "%d", &for_read) == 1)
    {
        *pb = for_read;
        pb++;
    }
}

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
