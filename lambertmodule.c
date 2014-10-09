#include <Python.h>
#include <structmember.h>

typedef struct {
    PyObject_HEAD
		double x;
		double y;
		double z;
} lambert_PointObject;

static PyTypeObject lambert_PointType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "lambert.Point",             /*tp_name*/
    sizeof(lambert_PointObject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "Point objects",           /* tp_doc */
};

static PyMethodDef lambert_methods[] = {
    {NULL}  /* Sentinel */
};

#ifndef PyMODINIT_FUNC  /* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
initlambert(void) 
{
    PyObject* m;

    lambert_PointType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&lambert_PointType) < 0)
        return;

    m = Py_InitModule3("lambert", lambert_methods,
                       "Example module that creates an extension type.");

    Py_INCREF(&lambert_PointType);
    PyModule_AddObject(m, "Point", (PyObject *)&lambert_PointType);
}