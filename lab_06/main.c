#include "my_utils.h"
#include "from_file.h"
#include "found_in_file.h"
#include "my_print.h"

int main(int argc, char **argv)
{
    if ((argc == 4) || (argc == 3))
    {
        if (check_feild(argv[2]) == INVALID_ARG)
        {
            //printf("Not right argument\n");
            return INVALID_ARG;
        }

        if ((argc == 4) && (strcmp(argv[2], "year") == 0))
        {
            if (check_key(argv[3]) == INVALID_ARG)
            {
                //printf("Not right argument\n");
                return INVALID_ARG;
            }
        }

        if ((argc == 4) && ((strcmp(argv[2], "title") == 0) || (strcmp(argv[2], "name") == 0)))
        {
            if (strlen(argv[3]) > MAX_LEN_ARRAY - 1)
            {
                //printf("Not right argument\n");
                return INVALID_ARG;
            }
        }

        FILE *f;
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            //printf("No such file or directory\n");
            return OPEN_ERROR;
        }

        film_r films[MAX_LEN_ARRAY];
        int len_catalog = read_from_file_all(films, f, argv[2]);

        if (len_catalog == FILE_INVALID_ARG)
        {
            //printf("Invalid arg in file\n");
            fclose(f);
            return FILE_INVALID_ARG;
        }

        if (argc == 4)
        {
            int found_number = found_film(films, argv[2], argv[3], len_catalog);

            if (found_number == NOT_FOUND)
            {
                printf("Not found");
                fclose(f);
                return OK;
            }
            else
                struct_print(films[found_number]);
        }
        else
            structs_print(films, len_catalog);

        fclose(f);
        return OK;
    }

    //printf("Not enough argument\n");
    return NOT_ENOUGH_ARG;
}
