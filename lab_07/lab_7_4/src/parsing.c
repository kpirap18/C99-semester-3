#include "../inc/parsing.h"

void parsing_to_file(int *pb, int *pe, FILE *f_out)
{
    while (pb < pe)
    {
        fprintf(f_out, "%d ", *pb);
        pb++;
    }
}
void parsing_key_array(int *pb, const int *pb_old, const int *pe_old, double ava)
{
    while (pb_old < pe_old)
    {
        if (*pb_old - ava > EPS)
        {
            *pb = *pb_old;
            pb += 1;
        }
        pb_old++;
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
int file_size(FILE *f)
{
    int for_read, len = 0;

    while (feof(f))
    {
        if (fscanf(f, "%d", &for_read) == 1)
        {
            len += 1;
        }
        else if (feof(f))
        {
            len = 0;
            break;
        }
    }

    return len;
}

