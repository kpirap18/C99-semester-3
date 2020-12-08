#include "key.h"
#include "parsing.h"

double avarage(const int *pb, const int *pe)
{
    int count = 0;
    double average_num = 0;
    while (pb < pe)
    {
        average_num += *pb;
        count++;
        pb++;
    }

    return average_num / count;
}

int key_count(const int *pb, const int *pe, double(*func)(const int*, const int*))
{
    int count = 0;
    double ava = func(pb, pe);
    while (pb < pe)
    {
        if (*pb - ava > EPS)
        {
            count++;
        }
        pb++;
    }

    return count;
}

int key(const int *pb_src, int len, int *pb_dst, int *len_key, double(*func)(const int*, const int*))
{
    double avarage_num = func(pb_src, pb_src + len);
    int n = 0;
    const int *pb = pb_src;
    const int *pe_src = pb_src + len;

    while (pb < pe_src)
    {
        if (*pb - avarage_num > EPS)
        {
            n++;
        }
        pb++;
    }
    pb = pb_src;

    if (n <= *len_key)
    {
        while (pb < pb_src + len)
        {
            if (*pb - avarage_num > EPS)
            {
                *pb_dst = *pb;
                pb_dst++;

            }
            pb++;
        }
    }
    else
    {
        *len_key = n;
        return MY_ERROR;
    }

    return OK;
}
