#include "my_utils.h"

void struct_print(film_r film)
{
    printf("%s\n", film.title);
    printf("%s\n", film.name);
    printf("%d\n", film.year);
}

void structs_print(film_r *films, int len_catalog)
{
    for (int i = 0; i < len_catalog; i++)
        struct_print(films[i]);
}
