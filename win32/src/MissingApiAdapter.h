
#ifndef __MISSINGAPIADAPTER_H__
#define __MISSINGAPIADAPTER_H__

#include "PyWinTypes.h"

extern "C" {

PYWINTYPES_EXPORT PyObject* PyEval_CallObject(PyObject *func, PyObject *arg);

PYWINTYPES_EXPORT PyObject* PyEval_CallObjectWithKeywords(PyObject *func, PyObject *arg, PyObject *kwds);

}

#endif  // __MISSINGAPIADAPTER_H__
