#include <Python.h>

PyObject * mymodule_meth_foobar(PyObject * self, PyObject * args, PyObject * kwargs) {
    static char * keywords[] = {"alpha", "beta", NULL};

    double alpha;
    double beta = 0.5;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "d|d", keywords, &alpha, &beta)) {
        return NULL;
    }

    return PyFloat_FromDouble(alpha * alpha - beta * 2.0);
}

PyMethodDef module_methods[] = {
    {"foobar", (PyCFunction)mymodule_meth_foobar, METH_VARARGS | METH_KEYWORDS, NULL},
    {},
};

PyModuleDef module_def = {PyModuleDef_HEAD_INIT, "mymodule", NULL, -1, module_methods};

extern "C" PyObject * PyInit_mymodule() {
    PyObject * module = PyModule_Create(&module_def);
    return module;
}
