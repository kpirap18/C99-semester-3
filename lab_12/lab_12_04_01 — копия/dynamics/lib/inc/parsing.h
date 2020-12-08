#ifndef _PARSING_H_
#define _PARSING_H_

#include <stdio.h>
#include "app.h"

#ifdef EXPORTS
#define PARSING_DLL __declspec(dllexport)
#else
#define PARSING_DLL __declspec(dllimport)
#endif

#define PARSING_DECL __cdecl

PARSING_DLL void PARSING_DECL parsing_to_file(FILE *f_out, int *pb, int *pe);

PARSING_DLL void PARSING_DECL parsing_array(FILE *f, int *pb);

PARSING_DLL int PARSING_DECL file_size(FILE *f);

#endif // _PARSING_H_
