#ifndef PARSING_H
#define PARSING_H

#include "my_main.h"

void parsing_to_file(int *pb, int *pe, FILE *f_out);
void parsing_key_array(int *pb, const int *pb_old, const int *pe_old, double ava);
void parsing_array(FILE *f, int *pb);
int file_size(FILE *f);

#endif // PARSING_H
