#include <stdio.h>
#include <stdlib.h>


#define OK 0
#define MEMERYERROR -1
#define INPUTERROR -2
#define FILEERROR -3
#define ARGERROR -4

size_t set_len (double **arr, size_t len, size_t new_len)
{
    size_t rc = OK;
    double *tmp = *arr;

    if (tmp == NULL && len == 0 && new_len > 0)
    {
        tmp = malloc(new_len * sizeof(double));

        if (tmp == NULL)
        {
            rc = MEMERYERROR;
        }
    }
    else if (tmp != NULL && len > 0 && new_len > 0)
    {
        tmp = realloc(*arr, new_len);

        if (tmp == NULL)
        {
            rc = MEMERYERROR;
        }
    }
    else if (tmp != NULL && len > 0 && new_len == 0)
    {
        free(tmp);
        tmp = NULL;
    }
    else if (tmp == NULL && len == 0 && new_len == 0)
    {
        rc = ARGERROR;
    }

    if (rc == OK)
    {
        rc = new_len;
        *arr = tmp;
    }

    return rc;
}

int parsingfrom_array(FILE *f, double **array, size_t *len)
{
    int rc = OK;
    double *tmp = NULL;
    size_t len_tmp = 0;

    if (f == NULL)
    {
        rc = FILEERROR;
    }
    else if (fscanf(f, "%zu", &len_tmp) == 1 && len_tmp > 0)
    {
        len_tmp = set_len(&tmp, 0, len_tmp);
        
        if (len_tmp > 0)
        {
            for (size_t i = 0; i < len_tmp; ++i)
            {
                if (fscanf(f, "%lf", (tmp + i)) != 1)
                {
                    set_len(&tmp, len_tmp, 0);
                    rc = INPUTERROR;
                }
            }
        }
    }
    else
    {
        rc = INPUTERROR;
    }

    if (rc == OK)
    {
        *len = len_tmp;
        *array = tmp;
    }

    return rc;    
}

int parsingto_array(FILE *f, double *array, size_t len)
{
    if (!f)
    {
        return FILEERROR;
    }
    for (size_t i = 0; i < len; ++i)
    {
        printf("%.6lf", *(array + i));
    }
}

int main()
{
    size_t len = 0;
    double *array = NULL;

    parsingfrom(stdin, &array, &len);
    parsingto(stdout, array, len);

    return OK;
}
