#ifndef _KEY_H_
#define _KEY_H_


#include "app.h"

double avarage(const int *pb, const int *pe);

int key_count(const int *pb, const int *pe, double(*func)(const int*, const int*));

int key(const int *pb_src, int len, int *pb_dst, int *len_key, double(*func)(const int*, const int*));

#endif // _KEY_H_
