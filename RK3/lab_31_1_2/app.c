#include "app.h"
#include "io.h"
#include "memory.h"
#include "oper.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    int find_num = 0;
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

    rc = read_matrix(f, &matrix, &n, &m);
    fclose(f);

    if (rc == OK)
    {
        find_num = find_int(matrix, n, m);

        if (find_num != NOTFIND)
        {
            printf("%d\n", find_num);
            rc = OK;
        }
        else
        {
            rc = NOTFIND;
        }
        
        free(matrix);
    }
    
    return rc;
}