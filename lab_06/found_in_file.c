#include "my_utils.h"

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
            int key_year = atoi(key);

            if (key_year == films[mid].year)
            {
                search = mid;
                break;
            }
            if (key_year < films[mid].year)
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
