
#include "MissingApiAdapter.h"

extern "C" {

static PyObject* PyEval_CallObject(PyObject *func, PyObject *arg)
{
    bool free_arg = false;
    if (arg != NULL && ! PyTuple_Check(arg)) {
        PyErr_SetString(PyExc_TypeError,
                        "argument list must be a tuple");
        return NULL;
    } else if (arg == NULL) {
        arg = PyTuple_New(0);
        free_arg = true;
    }
    PyObject* ret = PyObject_Call(func, arg, NULL);
    if (free_arg) {
        Py_DECREF(arg);
    }
    return ret;
}

static PyObject* PyEval_CallObjectWithKeywords(PyObject *func, PyObject *arg, PyObject *kwds)
{
    if (kwds != NULL && !PyDict_Check(kwds)) {
        PyErr_SetString(PyExc_TypeError,
                        "keyword list must be a dictionary");
        return NULL;
    }
    bool free_arg = false;
    if (arg != NULL && ! PyTuple_Check(arg)) {
        PyErr_SetString(PyExc_TypeError,
                        "argument list must be a tuple");
        return NULL;
    } else if (arg == NULL) {
        arg = PyTuple_New(0);
        free_arg = true;
    }
    PyObject* ret = PyObject_Call(func, arg, kwds);
    if (free_arg) {
        Py_DECREF(arg);
    }
    return ret;
}

}
