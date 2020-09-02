#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN_TITLE  26
#define MAX_LEN_NAME   26
#define MAX_LEN_ARRAY  15

#define OK              0
#define NOT_ENOUGH_ARG 53
#define OPEN_ERROR     -2
#define FILE_EMPTY     42
#define NOT_FOUND      -3
#define INVALID_ARG    -4
#define READ_ERROR     -5

typedef struct
{
    char title[MAX_LEN_TITLE];
    char name[MAX_LEN_NAME];
    int year;
} film_r;

int from_file_to_array(FILE *const f, film_r *film)
{

    int rc;

    rc = fscanf(f, "%s %s %d\n", film->title, film->name, &film->year);


    if (rc != 3)
        return READ_ERROR;

    return OK;
}

int add_info_txt(film_r films[], const film_r film, int len, char *field)
{
    film_r film_rewrite;
    memset(&film_rewrite, 0, sizeof(film_r));
    int pos = 0;


    if (strcmp(field, "title") == 0)
        for (int i = 0; i < len; i++)
        {
            if (strcmp(film.title, films[i].title) < 0)    // узнать как упорядочить
                break;
            ++pos;
        }

    if (strcmp(field, "name") == 0)
        for (int i = 0; i < len; i++)
        {
            if (strcmp(film.name, films[i].name) < 0)    // узнать как упорядочить
                break;
            ++pos;
        }

    if (strcmp(field, "year") == 0)
        for (int i = 0; i < len; i++)
        {
            if (film.year < films[i].year)   // узнать как упорядочить
                break;
            ++pos;
        }

    for (int i = len - 1; i >= pos; i--)
    {
        film_rewrite = films[i];
        films[i] = films[i + 1];
        films[i + 1] = film_rewrite;
    }

    films[pos] = film;

    return OK;
}

void struct_print(film_r film)
{
    printf("%s ", film.title);
    printf("%s ", film.name);
    printf("%d\n", film.year);
}

void structs_print(film_r *films, int len_catalog)
{
    for (int i = 0; i < len_catalog; i++)
        struct_print(films[i]);
}

int found_film(film_r *films, char *field, char *key, int len_catalog)
{
    int left = 0;
    int right = len_catalog;
    int search = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (strcmp(field, "title") == 0)
        {
            if (strcmp(key, films[mid].title) == 0)
            {
                search = mid;
                break;
            }
            if (strcmp(key, films[mid].title) < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (strcmp(field, "name") == 0)
        {
            if (strcmp(key, films[mid].name) == 0)
            {
                search = mid;
                break;
            }
            if (strcmp(key, films[mid].name) < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (strcmp(field, "year") == 0)
        {
            char *point = strchr(key, '.');
            if (point != NULL)
                return INVALID_ARG;

            int key_year = atoi(key);

            if (key_year == films[mid].year)
            {
                search = mid;
                break;
            }
            if (strcmp(key, films[mid].title) < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }

    }
    if (search == -1)
        return NOT_FOUND;
    else
        return search;
}

int main(/*int argc, char **argv*/)
{
    FILE *f;

    int argc = 4;
    char argv[12][111] = {"evr", "test.txt", "year", "1234"};
    f = fopen("C:/msys64/home/tni67/cprog/lab_06_01_01/test.txt", "r");

    if (f == NULL)
    {
        printf("No such file or directory");
        return OPEN_ERROR;
    }

    if ((argc == 4) || (argc == 3))
    {
        film_r films[MAX_LEN_ARRAY];
        film_r film;
        memset(&film, 0, sizeof(film_r));

        int len_catalog = 1;

        int rc = from_file_to_array(f, &film);
        films[0] = film;

        while(rc != READ_ERROR)
        {
            rc = from_file_to_array(f, &film);
            if (rc == OK)
            {
                add_info_txt(films, film, len_catalog, argv[2]);
                len_catalog++;
            }
        }

        if (argc == 4)
        {
            int found_number = found_film(films, argv[2], argv[3], len_catalog);

            if (found_number == INVALID_ARG)
            {
                printf("Not right argument\n");
                return INVALID_ARG;
            }

            if (found_number == NOT_FOUND)
            {
                printf("Not found");
                return NOT_FOUND;
            }

            struct_print(films[found_number]);
        }
        else
            structs_print(films, len_catalog);

        return OK;
    }

    printf("Not enough argument\n");
    return INVALID_ARG;
}
