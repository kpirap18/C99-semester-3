#include "io.h"

int read_matrix(FILE *f, int ***matrix, int *n, int *m)
{
    int rc = OK;
    int mat;
    int **tmp = NULL;

    rc = fscanf(f, "%d", n);
    if (rc != 1 || *n < 0)
    {
        rc = INPUTERROR;
        return rc;
    }

    rc = fscanf(f, "%d", m);
    if (rc != 1 || *n < 0)
    {
        rc = INPUTERROR;
        return rc;
    }

    if (*n == *m)
    {
        rc = OK;
    }
    else
    {
        rc = INPUTERROR;
        return rc;
    }
    

    if (rc == OK)
    {
        tmp = allocate_matrix(*n, *m);
        if (tmp)
        {
            for (int i = 0; i < *n; ++i)
            {
                for (int j = 0; j < *m; ++j)
                {
                    rc = fscanf(f, "%d", &mat);
                    if (rc != 1)
                    {
                        rc = INPUTERROR;
                        break;
                    }
                    tmp[i][j] = mat;
                }
                if (rc == INPUTERROR)
                {
                    break;
                }
            }
            if (rc == 1)
            {
                *matrix = tmp;
                rc = OK;
            }
            else
            {
                free(tmp);
                *matrix = NULL;
                rc = INPUTERROR;
            }
        }
    }
    else
    {
        rc = INPUTERROR;
        *matrix = NULL;
    }

    return rc;
}
