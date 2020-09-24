#include "../inc/main.h"
#include "../inc/parsing.h"
#include "../inc/mysort.h"
#include "../inc/key.h"

int main(/*int argc, char **argv*/)
{
    int argc = 4;
    char argv[12][122] = {"app.exe", "C:/msys64/home/Ira/cprog/lab_07/f_in.txt", "C:/msys64/home/Ira/cprog/lab_07/f_out.txt"};

    int rc = OK;

    if (argc == 3 || argc == 4)
    {
        FILE *f_in;

        f_in = fopen(argv[1], "r");

        if (f_in != NULL)
        {
            int len_array = file_size(f_in);

            if (len_array != 0)
            {
                int *array = (int *)malloc(len_array * sizeof(int));

                if (array != NULL)
                {
                    fseek(f_in, 0L, SEEK_SET);
                    parsing_array(f_in, array);

                    fclose(f_in);

                    if (argc == 4 && strcmp(argv[3], "f") == 0)
                    {
                        int *key_arrayb, *key_arraye;
                        int len_key = key(array, array + len_array, &key_arrayb, &key_arraye);

                        if (len_key > 0)
                        {
                            free(array);

                            mysort(key_arrayb, len_key, sizeof(int), compare);

                            FILE *f_out;
                            f_out = fopen(argv[2], "w");

                            if (f_out != NULL)
                            {
                                parsing_to_file(key_arrayb, key_arraye, f_out);
                                free(key_arrayb);
                                fclose(f_out);
                            }
                            else
                            {
                                printf("ERR");
                                rc = FILE_OPEN_ERR;
                            }
                        }
                        else
                        {
                            printf("ERR");
                            rc = ERROR_MEMORY;
                        }
                    }
                    else
                    {
                        mysort(array, len_array, sizeof(int), compare);

                        FILE *f_out;
                        f_out = fopen(argv[2], "w");

                        if (f_out != NULL)
                        {
                            parsing_to_file(array, array + len_array, f_out);
                            free(array);
                            fclose(f_out);
                        }
                        else
                        {
                            printf("ERR");
                            rc = FILE_OPEN_ERR;
                        }
                    }
                }
                else
                {
                    printf("ERR");
                    rc = ERROR_MEMORY;
                }
            }
            else
            {
                printf("ERR");
                rc = FILE_EMPTY_ERR;
            }
        }
        else
        {
            printf("ERR");
            rc = FILE_OPEN_ERR;
        }
    }
    else
    {
        printf("ERR");
        rc = INVALID_ARG;
    }

    return rc;
}
