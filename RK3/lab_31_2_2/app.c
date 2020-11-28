#include "app.h"
#include "io.h"
#include "memory.h"
#include "oper.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    FILE *f;

    if (argc != 2)
    {
        return ARGERROR;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        return FILEERROR;
    }

    int **matrix = NULL;
    int n = 0;
    int m = 0;

    rc = read_size(f, &n, &m);
    
    if (rc == OK)
    {
        rc = read_matrix(f, &matrix, n, m);
    }
    fclose(f);

    if (rc == OK)
    {
        rc = matrix_new(matrix, n, m);

        if (rc == OK)
        {
            print(matrix, n, m);
            rc = OK;
        }
        else
        {
            rc = MEMERROR;
        }
    }
    free(matrix);

    return rc;
}
