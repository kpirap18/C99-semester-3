#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "app.h"
#include "parsing.h"
#include "mysort.h"
#include "key.h"

int main(int argc, char **argv)
{
//    int argc = 4;
//    char argv[5][222] = {"erg", "C:/msys64/home/Ira/cprog/lab_12/lab_12_04_01/in.txt",
//                         "C:/msys64/home/Ira/cprog/lab_12/lab_12_04_01/out.txt", "f"};
    int rc = OK;
    int *key_array = NULL;
    int *array = NULL;

    if (argc != 3 && argc != 4)
    {
        printf("app.exe in.txt out.txt [f]\n");
        return INVALID_ARG;
    }
    if (argc == 4 && (strcmp(argv[3], "f") != 0))
    {
        printf("app.exe in.txt out.txt [f]\n");
        return INVALID_ARG;
    }

    FILE *f_in;

    f_in = fopen(argv[1], "r");
    if (f_in)
    {
        FILE *f_out;
        f_out = fopen(argv[2], "w");
        if (f_out)
        {
            int len_array = file_size(f_in);

            if (len_array != 0)
            {
                array = (int *)malloc(len_array * sizeof(int));

                if (array != NULL)
                {
                    fseek(f_in, 0L, SEEK_SET);
                    parsing_array(f_in, array);

                    if (argc == 4 && strcmp(argv[3], "f") == 0)
                    {
                        int len_key = key_count(array, array + len_array, avarage);

                        if (len_key > 0)
                        {
                            key_array = (int *)calloc(len_key + 1, sizeof(int));
                            int len_check = key(array, len_array, key_array, &len_key, avarage);

                            if (len_check == MY_ERROR)
                            {
                                printf("Key array is empty\n");
                                rc = MY_ERROR;
                            }
                        }
                        else
                        {
                            printf("Key array is empty\n");
                            rc = MY_ERROR;
                        }

                        if (rc == OK && key_array)
                        {
                            mysort(key_array, len_key, sizeof(int), comparator_int);

                            parsing_to_file(f_out, key_array, key_array + len_key);
                            free(key_array);

                        }
                        else
                        {
                            printf("Memory error with array\n");
                            rc = MEMORY_ERR;
                        }
                        free(array);
                    }
                    else if (argc == 3)
                    {
                        mysort(array, len_array, sizeof(int), comparator_int);

                        parsing_to_file(f_out, array, array + len_array);
                        free(array);
                    }
                }
                else
                {
                    printf("Memory error with array\n");
                    rc = MEMORY_ERR;
                }
            }
            else
            {
                printf("File is empty\n");
                rc = FILE_EMPTY_ERR;
            }
            fclose(f_out);
        }
        else
        {
            printf("Error with open file output\n");
            rc = FILE_OPEN_ERR;
        }
        fclose(f_in);
    }
    else
    {
        printf("Error with open file input\n");
        rc = FILE_OPEN_ERR;
    }

    return rc;
}










//    if (argc == 3 || argc == 4)
//    {
//        FILE *f_in;

//        f_in = fopen(argv[1], "r");

//        if (f_in != NULL)
//        {
//            int len_array = file_size(f_in);

//            if (len_array != 0)
//            {
//                int *array = (int *)malloc(len_array * sizeof(int));

//                if (array != NULL)
//                {
//                    fseek(f_in, 0L, SEEK_SET);
//                    parsing_array(f_in, array);

//                    fclose(f_in);

//                    if (argc == 4 && strcmp(argv[3], "f") == 0)
//                    {
//                        int len_key = key_count(array, array + len_array, avarage);
//                        int *key_arrayb = (int *)malloc(len_key * sizeof(int));
//                        free(array);

//                        if (len_key > 0)
//                        {
//                            mysort(key_arrayb, len_key, sizeof(int), comparator_int);

//                            FILE *f_out;
//                            f_out = fopen(argv[2], "w");

//                            if (f_out != NULL)
//                            {
//                                parsing_to_file(key_arrayb, key_arraye, f_out);
//                                free(key_arrayb);
//                                fclose(f_out);
//                            }
//                            else
//                            {
//                                //printf("ERR");
//                                rc = FILE_OPEN_ERR;
//                            }
//                        }
//                        else
//                        {
//                            //printf("ERR");
//                            rc = ERROR_MEMORY;
//                        }
//                    }
//                    else if (argc == 3)
//                    {
//                        mysort(array, len_array, sizeof(int), comparator_int);

//                        FILE *f_out;
//                        f_out = fopen(argv[2], "w");

//                        if (f_out != NULL)
//                        {
//                            parsing_to_file(array, array + len_array, f_out);
//                            free(array);
//                            fclose(f_out);
//                        }
//                        else
//                        {
//                            //printf("ERR");
//                            rc = FILE_OPEN_ERR;
//                        }
//                    }
//                    else
//                    {
//                        //printf("ERR");
//                        rc = INVALID_ARG;
//                    }
//                }
//                else
//                {
//                    //printf("ERR");
//                    rc = ERROR_MEMORY;
//                }
//            }
//            else
//            {
//                //printf("ERR");
//                rc = FILE_EMPTY_ERR;
//            }
//        }
//        else
//        {
//            //printf("ERR");
//            rc = FILE_OPEN_ERR;
//        }
//    }
//    else
//    {
//        //printf("ERR");
//        rc = INVALID_ARG;
//    }

//    return rc;
//}
