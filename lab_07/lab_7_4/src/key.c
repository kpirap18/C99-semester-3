#include "../inc/key.h"
#include "../inc/parsing.h"

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

int key_count(const int *pb, const int *pe, double ava)
{
    int count = 0;
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

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;

    double avarage_num = avarage(pb_src, pe_src);
    int len_key = key_count(pb_src, pe_src, avarage_num);

    if (len_key != 0)
    {
        rc = len_key;
        *pb_dst = (int *)malloc(len_key * sizeof(int));

        if (*pb_dst != NULL)
        {
            *pe_dst = *pb_dst + len_key;

            int *pa = *pb_dst;

            parsing_key_array(pa, pb_src, pe_src, avarage_num);
        }
        else
        {
			*pb_dst = NULL;
            rc = ERROR_MEMORY;
        }
    }
    else
    {
		*pb_dst = NULL;
        rc = KEYARRAY_EMRTY_ERR;
    }

    return rc;
}
