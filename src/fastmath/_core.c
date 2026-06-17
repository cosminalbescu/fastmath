/* _core.c — C extension for fastmath */
#define PY_SSIZE_T_CLEAN
#include <Python.h>

/* Sum the elements of a list of numbers */
static PyObject *sum_list(PyObject *self, PyObject *args) {
    PyObject *list;
    if (!PyArg_ParseTuple(args, "O", &list))
        return NULL;

    Py_ssize_t n = PyList_Size(list);
    double total = 0.0;
    for (Py_ssize_t i = 0; i < n; i++) {
        PyObject *item = PyList_GetItem(list, i);   /* borrowed ref */
        total += PyFloat_AsDouble(item);
    }
    return PyFloat_FromDouble(total);
}

/* Dot product of two lists */
static PyObject *dot(PyObject *self, PyObject *args) {
    PyObject *a, *b;
    if (!PyArg_ParseTuple(args, "OO", &a, &b))
        return NULL;

    Py_ssize_t n = PyList_Size(a);
    if (n != PyList_Size(b)) {
        PyErr_SetString(PyExc_ValueError, "lists must have equal length");
        return NULL;
    }
    double result = 0.0;
    for (Py_ssize_t i = 0; i < n; i++) {
        result += PyFloat_AsDouble(PyList_GetItem(a, i))
                * PyFloat_AsDouble(PyList_GetItem(b, i));
    }
    return PyFloat_FromDouble(result);
}

/* Dot product of two lists */
static PyMethodDef Methods[] = {
    {"sum_list", sum_list, METH_VARARGS, "Sum of a list of numbers."},
    {"dot",      dot,      METH_VARARGS, "Dot product of two lists."},
    {NULL, NULL, 0, NULL}   /* terminator */
};

/* Module definition */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "_core",            /* module name */
    "fastmath C core",  /* docstring */
    -1,
    Methods
};

/* Initialization function — the name MUST be PyInit_<module name> */
PyMODINIT_FUNC PyInit__core(void) {
    return PyModule_Create(&moduledef);
}
