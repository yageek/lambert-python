#include <Python.h>
#include <structmember.h>

typedef struct {
    PyObject_HEAD
		double x;
		double y;
		double z;
} lambert_PointObject;


static PyMemberDef lambert_Point_members[] = {
    {"x", T_DOUBLE, offsetof(lambert_PointObject, x), 0,
     "X coordinate (longitude)"},
    {"y", T_DOUBLE, offsetof(lambert_PointObject, y), 0,
     "Y coordinate (latitude)"},
    {"z", T_DOUBLE, offsetof(lambert_PointObject, z), 0,
     "Z coordinate (altitude)"},
    {NULL}  /* Sentinel */
};

/* Point initialisation */
static PyObject * Point_new(PyTypeObject * type, PyObject * args, PyObject * kwds){

    lambert_PointObject * self;
    self = (lambert_PointObject*) type->tp_alloc(type,0);
    if(self == NULL){
        Py_DECREF(self);
        return NULL;
    }

    self->x = 0;
    self->y = 0;
    self->z = 0;

    return (PyObject*) self;
}
/* Point dealloc */
static void Point_dealloc(lambert_PointObject * self){
    self->ob_type->tp_free((PyObject*) self);
}


/* Point initialization */
static int Point_init(lambert_PointObject *self, PyObject *args, PyObject *kwds){


    static char *kwlist[] = {"x", "y", "z", NULL};
    if (! PyArg_ParseTupleAndKeywords(args, kwds, "|ddd", kwlist,
                                      &self->x, &self->y,
                                      &self->z))
        return -1;



    return 0;
}

static PyTypeObject lambert_PointType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "lambert.Point",             /*tp_name*/
    sizeof(lambert_PointObject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor) Point_dealloc,                         /*tp_dealloc*/
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
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,        /*tp_flags*/
    "Point objects",           /* tp_doc */
    0,                    /* tp_traverse */
    0,                     /* tp_clear */
    0,                     /* tp_richcompare */
    0,                     /* tp_weaklistoffset */
    0,                     /* tp_iter */
    0,                     /* tp_iternext */
    0,             /* tp_methods */
    lambert_Point_members,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) Point_init,      /* tp_init */
    0,                         /* tp_alloc */
    Point_new,                 /* tp_new */
};


/*Modules methods */
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

