#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "app.h"

typedef double (__cdecl *func_avarage)(const int *, const int *);

typedef int (__cdecl *func_key_count)(const int *, const int *, double(*func)(const int *, const int *));

typedef int (__cdecl *func_key)(const int *, int, int *, int *, double(*func)(const int *, const int *));

typedef int (__cdecl *func_comparator_int)(const void *, const void *);

typedef void (__cdecl *func_swap)(void *, void *, size_t);

typedef void (__cdecl *func_mysort)(void *const, size_t, size_t, int (*comparator)(const void *, const void *));

typedef void (__cdecl *func_parsing_to_file)(FILE *, int *, int *);

typedef void (__cdecl *func_parsing_array)(FILE *, int *);

typedef int (__cdecl *func_file_size)(FILE *);

typedef struct
{
	func_avarage avarage;
	func_comparator_int comparator_int;
	func_file_size file_size;
	func_key key;
	func_key_count key_count;
	func_mysort mysort;
	func_parsing_array parsing_array;
	func_parsing_to_file parsing_to_file;
	func_swap swap;
}all_func;

int load_lib(HMODULE *hlib, all_func *func)
{
	int rc = OK;
	*hlib = LoadLibrary("libapp.dll");
	if ((*hlib == NULL))
	{
		return LIBRARY_ERR;
	}
	
	func->avarage = (func_avarage)GetProcAddress(*hlib, "avarage");
	if (func->avarage == NULL)
	{
		printf("tut ava");
		rc = LIBRARY_MEM_ERR;
	}
	if (rc == OK)
	{
		func->comparator_int = (func_comparator_int)GetProcAddress(*hlib, "comparator_int");
		if (func->comparator_int == NULL)
		{
			printf("tut cmp");
			rc = LIBRARY_MEM_ERR;
		}
	}
	if (rc == OK)
	{
		func->file_size = (func_file_size)GetProcAddress(*hlib, "file_size");
		if (func->file_size == NULL)
		{
			printf("tut size");
			rc = LIBRARY_MEM_ERR;
		}
	}
	if (rc == OK)
	{
		func->key = (func_key)GetProcAddress(*hlib, "key");
		if (func->key == NULL)
		{
			printf("tut key");
			rc = LIBRARY_MEM_ERR;
		}
	}
	if (rc == OK)
	{
		func->key_count = (func_key_count)GetProcAddress(*hlib, "key_count");
		if (func->key_count == NULL)
		{
			printf("tut cou");
			rc = LIBRARY_MEM_ERR;
		}
	}
	if (rc == OK)
	{
		func->mysort = (func_mysort)GetProcAddress(*hlib, "mysort");
		if (func->mysort == NULL)
		{
			printf("tut sort");
			rc = LIBRARY_MEM_ERR; 
		}
	}
	if (rc == OK)
	{
		func->parsing_array = (func_parsing_array)GetProcAddress(*hlib, "parsing_array");
		if (func->parsing_array == NULL)
		{
			printf("tut par1");
			rc = LIBRARY_MEM_ERR;
		}
	}
	if (rc == OK)
	{
		func->parsing_to_file = (func_parsing_to_file)GetProcAddress(*hlib, "parsing_to_file");
		if (func->parsing_to_file == NULL)
		{
			printf("tut par2");
			rc = LIBRARY_MEM_ERR;
		}
	}
	if (rc == OK)
	{
		func->swap = (func_swap)GetProcAddress(*hlib, "swap");
		if (func->swap == NULL)
		{
			//printf("tut");
			rc = LIBRARY_MEM_ERR;
		}
	}
	
	return rc;	
}

int main(int argc, char **argv)
{
	HMODULE hlib;
	all_func my_func;
    int rc = OK;
    int *key_array = NULL;
    int *array = NULL;
	FILE *f_in;

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
	
	rc = load_lib(&hlib, &my_func);
	if (rc == LIBRARY_ERR)
	{
		printf("Error while loading library.\n");
		return LIBRARY_ERR;
	}
	else if (rc == LIBRARY_MEM_ERR)
	{
		printf("Error while loading some function.\n");
		FreeLibrary(hlib);
		return LIBRARY_MEM_ERR;
	}

    f_in = fopen(argv[1], "r");
    if (f_in)
    {
        FILE *f_out;
        f_out = fopen(argv[2], "w");
        if (f_out)
        {
            int len_array = my_func.file_size(f_in);

            if (len_array != 0)
            {
                array = (int *)malloc(len_array * sizeof(int));

                if (array != NULL)
                {
                    fseek(f_in, 0L, SEEK_SET);
                    my_func.parsing_array(f_in, array);

                    if (argc == 4 && strcmp(argv[3], "f") == 0)
                    {
                        int len_key = my_func.key_count(array, array + len_array, my_func.avarage);

                        if (len_key > 0)
                        {
                            key_array = (int *)calloc(len_key + 1, sizeof(int));
                            int len_check = my_func.key(array, len_array, key_array, &len_key,  my_func.avarage);
                            if (len_check == MY_ERROR)
                            {
                                printf("1Key array is empty\n");
                                rc = KEYARRAY_EMRTY_ERR;
                            }
                        }
                        else
                        {
                            printf("2Key array is empty\n");
                            rc = KEYARRAY_EMRTY_ERR;
                        }


                        if (rc == OK && key_array)
                        {
                            my_func.mysort(key_array, len_key, sizeof(int), my_func.comparator_int);

                            my_func.parsing_to_file(f_out, key_array, key_array + len_key);
                            free(key_array);

                        }
                        else
                        {
                            printf("Memory error with array\n");
                            rc = MEMORY_ERR ;
                        }
						free(array);
                    }
                    else if (argc == 3)
                    {
                        my_func.mysort(array, len_array, sizeof(int), my_func.comparator_int);

                        my_func.parsing_to_file(f_out, array, array + len_array);
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
	
	FreeLibrary(hlib);
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
