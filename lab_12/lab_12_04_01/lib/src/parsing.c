#include <string.h>
#include "parsing.h"

PARSING_DLL void PARSING_DECL parsing_to_file(FILE *f_out, int *pb, int *pe)
{
    while (pb < pe)
    {
        fprintf(f_out, "%d ", *pb);
        pb++;
    }
}

PARSING_DLL void PARSING_DECL parsing_array(FILE *f, int *pb)
{
    int for_read;
    while (fscanf(f, "%d", &for_read) == 1)
    {
        *pb = for_read;
        pb++;
    }
}

PARSING_DLL int PARSING_DECL file_size(FILE *f)
{
    int for_read, len = 0;

    while (!feof(f))
    {
        if (fscanf(f, "%d", &for_read) == 1)
        {
            len += 1;
        }
        else if (!feof(f))
        {
            len = 0;
            break;
        }
    }

    return len;
}

