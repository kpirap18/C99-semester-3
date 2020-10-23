#include "app.h"
#include "io.h"
#include "my_check.h"
#include "film.h"
#include "film_arr.h"

int main(/*int argc, char **argv*/)
{    
    setbuf(stdout, NULL);
    int argc = 3;
    char argv[12][1212] = {"app.exe", "C:/msys64/home/Ira/cprog/lab_09/func_tests/pos_01_in.txt", "name", "1234"};
    int rc = OK;

    if ((argc == 4) || (argc == 3))
    {
        if (check_feild(argv[2]) == INVALID_ARG)
        {
            //printf("Not right argument\n");
            rc = INVALID_ARG;
        }
        else
        {
            FILE *f;
            f = fopen(argv[1], "r");
            if (f == NULL)
            {
                //printf("No such file or directory\n");
                rc = OPEN_ERROR;
            }
            else
            {

                if (argc == 4)
                {
                    if (strcmp(argv[2], "year") == 0 && check_key(argv[3]) == INVALID_ARG)
                    {
                        //printf("Not right argument\n");
                        rc = INVALID_ARG;
                    }


                    if (((strcmp(argv[2], "title") == 0) || (strcmp(argv[2], "name") == 0)) &&
                            strlen(argv[3]) > MAX_LEN_ARRAY - 1)
                    {
                        //printf("Not right argument\n");
                        rc =  INVALID_ARG;
                    }
                }

                if (rc == OK)
                {
                    film_r *films = NULL;
                    int n_films = 0;
                    rc = f_create(f, &films, &n_films, argv[2]);

                    if (rc != OK)
                    {
                        //printf("Invalid arg in file\n");
                        rc = FILE_INVALID_ARG;
                    }
                    else
                    {
                        if (argc == 4)
                        {
                            int found_number = film_found(films, argv[2], argv[3], n_films);
                            if (found_number == NOT_FOUND)
                            {
                                printf("Not found");

                                rc = OK;
                            }
                            else
                                film_print(stdout, &films[found_number]);
                        }
                        else
                            f_print(stdout, films, n_films);
                        f_free(films, n_films);
                    }

                }
            }
            fclose(f);
        }
    }
    else
    {
        //printf("Not enough argument\n");
        rc = NOT_ENOUGH_ARG;
    }

    return rc;
}
