/* _core.c — extensie C pentru fastmath */
#define PY_SSIZE_T_CLEAN
#include <Python.h>

/* Suma elementelor unei liste de numere */
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

/* Produs scalar (dot product) a două liste */
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

/* Tabelul de metode expuse în Python */
static PyMethodDef Methods[] = {
    {"sum_list", sum_list, METH_VARARGS, "Sum of a list of numbers."},
    {"dot",      dot,      METH_VARARGS, "Dot product of two lists."},
    {NULL, NULL, 0, NULL}   /* terminator */
};

/* Definiția modulului */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "_core",            /* numele modulului */
    "fastmath C core",  /* docstring */
    -1,
    Methods
};

/* Funcția de init — numele TREBUIE să fie PyInit_<nume modul> */
PyMODINIT_FUNC PyInit__core(void) {
    return PyModule_Create(&moduledef);
}
