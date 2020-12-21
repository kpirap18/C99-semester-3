#include <stdlib.h>
#include "Python.h"
#include "array.h"

static PyObject* array_copy(const int *array, int n)
{
    PyObject *new_arr, *elem;

    new_arr = PyList_New(n);
    if (!new_arr)
	{
        return NULL;
	}

    for (int i = 0; i < n; i++)
    {
        elem = PyLong_FromLong(array[i]);
        if (!elem)
        {
            Py_DECREF(new_arr);
            return NULL;
        }

        PyList_SET_ITEM(new_arr, i, elem);
    }

    return new_arr;
}
// void shift_arr(int *array, int len, int k);
static PyObject* py_shift_arr(PyObject *self, PyObject *args)
{
    PyObject *elem, *obj, *check_i, *pbuf;
    int n, k;

	// Принимаю массив, его длину, и на сколько позиций надо сдвинуть
    if (!PyArg_ParseTuple(args, "Oii", &obj, &n, &k))
    {
        return NULL;
    }

    obj = PySequence_Fast(obj, "Argument must be iterable");
    if (!obj)
    {
        return NULL;
    }

    int *a = malloc(n * sizeof(int));
    if (!a)
    {
        Py_DECREF(obj);
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        elem = PySequence_Fast_GET_ITEM(obj, i);
        if (!elem)
        {
            Py_DECREF(obj);
            free(a);
            return NULL;
        }

        check_i = PyNumber_Long(elem);
        if (!check_i)
        {
            Py_DECREF(obj);
            free(a);
            return NULL;
        }

        a[i] = PyLong_AS_LONG(check_i);

        Py_DECREF(check_i);
    }

    Py_DECREF(obj);

    shift_arr(a, n, k);
    pbuf = array_copy(a, n);
    free(a);
	
	// Возвращаю массив после сдвига
    return pbuf;
}

// int square_arr(int *array, int n, int *sq_array, int *sq_n);
static PyObject* py_square_arr(PyObject *self, PyObject *args)
{
    PyObject *elem, *obj, *check_i, *pbuf;
	int *a, *b;
    int n, sq_n, rc;
	
	// Принимаю исходный массив, длину исходного массива, длину нового массива
    if (!PyArg_ParseTuple(args, "Oii", &obj, &n, &sq_n))
    {
        return NULL;
    }

    obj = PySequence_Fast(obj, "Argument must be iterable");
    if (!obj)
    {
        return NULL;
    }

    a = malloc(n * sizeof(int)); // исходный массив 
	b = malloc(sq_n * sizeof(int)); // новый массив
    if (!a)
    {
        Py_DECREF(obj);
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        elem = PySequence_Fast_GET_ITEM(obj, i);
        if (!elem)
        {
            Py_DECREF(obj);
            free(a);
            return NULL;
        }

		// This is the equivalent of the Python expression int(elem) (из документации)
        check_i = PyNumber_Long(elem); 
        if (!check_i)
        {
            Py_DECREF(obj);
            free(a);
            return NULL;
        }

        a[i] = PyLong_AS_LONG(check_i);

        Py_DECREF(check_i);
    }

    Py_DECREF(obj);

    rc = square_arr(a, n, b, &sq_n);
    pbuf = array_copy(b, sq_n);
    free(a);
	
	// Возвращаю Код ошибки(вернула функция square_arr), новый массив и его длину
    return Py_BuildValue("(iOi)", rc, pbuf, sq_n);
}

// таблица содержит необходимую информацию о функциях модуля
static PyMethodDef libarray_dll_methods[] =
{
    { "shift_arr", py_shift_arr, METH_VARARGS, 
	"Shift array by k positions to the left " },
	{ "square_arr", py_square_arr, METH_VARARGS, "Find complete squares" },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef libarray_dll_module =
{
    PyModuleDef_HEAD_INIT,
    "libarray_dll",
    "A libarray_dll module for tasks with array (lab_12)",
    -1,
    libarray_dll_methods
};

PyMODINIT_FUNC PyInit_libarray_dll(void)
{
    return PyModule_Create(&libarray_dll_module);
}
