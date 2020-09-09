#ifndef _FROM_FILE_H
#define _FROM_FILE_H

#include "my_utils.h"

int check_feild(char *feild);
int check_key(char *key);
int from_file_to_array(FILE *const f, film_r *film);
int add_info_txt(film_r films[], const film_r film, int len, char *field);
int read_from_file_all (film_r *films, FILE *const f, char *argv);

#endif // FROM_FILE_H
