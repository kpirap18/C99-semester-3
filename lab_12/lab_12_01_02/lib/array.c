#include <stdio.h>
#include <math.h>
#include <array.h>

ARRAY_DLL void ARRAYE_DECL shift_arr(int *array, int len, int k)
{
    if (k < 0 || len <= 0)
    {
        return;
    }

    int buf;
    int new_k = k % len;
    while(new_k)
    {
        buf = array[0];
        for (int i = 0; i < len; ++i)
        {
            array[i] = array[i + 1];
        }
        array[len - 1] = buf;
        new_k--;
    }
}

ARRAY_DLL int ARRAYE_DECL is_square(int n)
{
    double num = sqrt(n);
    return ((int)(num) * (int)num == n) ? 1 : 0;
}

ARRAY_DLL int ARRAYE_DECL square_arr(int *array, int n, int *sq_array, int *sq_n)
{
    int len = 0;
    for (int i = 0; i < n; ++i)
    {
        if (is_square(array[i]))
        {
            len++;
        }
    }

    if (*sq_n >= len)
    {
        len = 0;
        for (int i = 0; i < n; ++i)
        {
            if (is_square(array[i]))
            {
                sq_array[len] = array[i];
                len++;
            }
        }
        *sq_n = len;
        return 0;
    }
    else if (*sq_n < len || len == 0)
    {
        *sq_n = len;
        return -1;
    }
	
	return 0;
}
