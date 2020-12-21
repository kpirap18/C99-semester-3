#ifndef _PARSING_H_
#define _PARSING_H_

#include <stdio.h>
#include "app.h"

void parsing_to_file(FILE *f_out, int *pb, int *pe);

void parsing_array(FILE *f, int *pb);

int file_size(FILE *f);

#endif // _PARSING_H_
