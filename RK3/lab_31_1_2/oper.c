#include "oper.h"

int find_int(int **matrix, int n, int m)
{
    if (matrix == NULL || n == 0 || m == 0 || n != m)
    {
        return ERROR;
    }

    int max_int = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = n - i; j < m; ++j)
        {
            if (abs(matrix[i][j]) % 10 == 5)
            {
                max_int = matrix[i][j];
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = n - i; j < m; ++j)
        {
            if (abs(matrix[i][j]) % 10 == 5)
            {
                if (matrix[i][j] > max_int)
                {
                    max_int = matrix[i][j];
                }
            }
        }
    }

    if (max_int == 0)
    {
        return NOTFIND;
    }

    return max_int;
}