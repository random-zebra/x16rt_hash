#define PY_SSIZE_T_CLEAN

#include <Python.h>

#include "x16rt.h"

static PyObject *x16rt_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    x16rt_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    x16rt_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef X16RTMethods[] = {
    { "getPoWHash", x16rt_getpowhash, METH_VARARGS, "Returns the proof of work hash using X16RT hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef X16RTModule = {
    PyModuleDef_HEAD_INIT,
    "x16rt_hash",
    "...",
    -1,
    X16RTMethods
};

PyMODINIT_FUNC PyInit_x16rt_hash(void) {
    return PyModule_Create(&X16RTModule);
}

#else

PyMODINIT_FUNC initx16rt_hash(void) {
    (void) Py_InitModule("x16rt_hash", X16RTMethods);
}
#endif
