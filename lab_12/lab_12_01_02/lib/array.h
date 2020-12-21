#ifndef _ARRAY_H_
#define _ARRAY_H_

#ifdef EXPORTS
#define ARRAY_DLL __declspec(dllexport)
#else
#define ARRAY_DLL __declspec(dllimport)
#endif

#define ARRAYE_DECL __cdecl

ARRAY_DLL void ARRAYE_DECL shift_arr(int *array, int len, int k);

ARRAY_DLL int ARRAYE_DECL is_square(int n);

ARRAY_DLL int ARRAYE_DECL square_arr(int *array, int n, int *sq_array, int *sq_n);

#endif // _ARRAY_H_
