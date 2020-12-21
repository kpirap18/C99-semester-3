import ctypes
from ctypes import c_int, POINTER

lib = ctypes.CDLL('../libarray.dll')

# void shift_arr(int *array, int len, int k);
_shift_arr = lib.shift_arr
_shift_arr.argtypes = (POINTER(c_int), c_int, c_int)
'''
# int is_square(int n);
_is_square = lib.is_square
_is_square.argtypes = c_int
_is_square.restype = c_int
'''
# int square_arr(int *array, int n, int *sq_array, int *sq_n);
_square_arr = lib.square_arr
_square_arr.argtypes = (POINTER(c_int), c_int, POINTER(c_int), POINTER(c_int))
_square_arr.restype = c_int


def shift_arr(array, k):
    len_arr = len(array)
    new_arr = (c_int * len_arr)(*array)
    _shift_arr(new_arr, len_arr, k)
    
    return list(new_arr)


def square_arr1(array):
    n = len(array)
    new_arr = (c_int * n)(*array)
    sq_n = (c_int)(n)
    sq_arr = (c_int * n)()
    rc = _square_arr(new_arr, n, sq_arr, sq_n)
    
    return list(sq_arr), sq_n.value


def square_arr2(array):
    n = len(array)
    new_arr = (c_int * n)(*array)
    sq_n = (c_int)(0)
    sq_arr = (c_int * n)()
    rc = _square_arr(new_arr, n, sq_arr, sq_n)
    if (rc == -1 and sq_n.value != 0):
        sq_arr = (c_int * sq_n.value)()
    rc = _square_arr(new_arr, n, sq_arr, sq_n)
    
    return list(sq_arr), sq_n.value
