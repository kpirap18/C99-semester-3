#include "../inc/operationmatrix.h"
#include "../inc/initializmatrix.h"

void sum_matrix(double **mat1, double **mat2, double **mat_res, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat_res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multi_matrix(double **mat1, double **mat2, double **mat_res, int n, int m, int q)
{
    double res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            res = 0;
            for (int k = 0; k < m; k++)
            {
                res += (mat1[i][k] * mat2[k][j]);
            }
            mat_res[i][j] = res;
        }
    }
}

double det(double **a, int n)
{
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    double ans = 1;

    double multi_mat_val;
    for (int i = 0; i < n; ++i)
    {
        int k = -1;
        double buf_mat_val = 0;
        for (int j = i; j < n; j++)
            if ((fabs(a[j][i]) - fabs(buf_mat_val)) > EPS)
            {
                k = j;
                buf_mat_val = a[j][i];
            }

        if (k == -1)
            return 0;
        if (k != i)
        {
            double *buf = a[i];
            a[i] = a[k];
            a[k] = buf;
            ans *= -1;
        }
        if (fabs(a[k][i]) < EPS)
        {
            ans = 0;
            break;
        }

        for (int j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > EPS)
            {
                multi_mat_val = 1 / a[i][i] * a[j][i];
                for (int p = i; p < n; p++)
                    a[j][p] -= a[i][p] * multi_mat_val;
            }
        ans *= a[i][i];
    }
    return ans;
}

void iverse_matrix(double **invmat, double **mat, int n)
{
    int i, j, k, z;
    double r, res;

    for (k = 0; k < n; k++)
    {
        if (fabs(mat[k][k] - 0) < EPS)
        {
            double *buf = mat[k];
            mat[k] = mat[k + 1];
            mat[k + 1] = buf;
            buf = invmat[k];
            invmat[k] = invmat[k + 1];
            invmat[k + 1] = buf;
            k--;
        }
        else
        {
            r = 1 / mat[k][k];
            for (j = 0; j < n; j++)
            {
                mat[k][j] *= r;
                invmat[k][j] *= r;
            }
            for (i = k + 1; i < n; i++)
            {
                res = mat[i][k];
                for (z = 0; z < n; z++)
                {
                    mat[i][z] -= mat[k][z] * res;
                    invmat[i][z] -= invmat[k][z] * res;
                }
            }
        }
    }
    for (k = n - 1; k >= 0; k--)
    {
        for (i = k - 1; i >= 0; i--)
        {
            res = mat[i][k];
            for (z = n - 1; z >= 0; z--)
            {
                mat[i][z] = mat[i][z] - mat[k][z] * res;
                invmat[i][z] = invmat[i][z] - invmat[k][z] * res;
            }
        }
    }
}
