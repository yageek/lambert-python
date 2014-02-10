#include <Python.h>
#include <structmember.h>

typedef struct {
    PyObject_HEAD
		double x;
		double y;
		double z;
} Point;

static PyObject *
Point_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Point *self;

    self = (Point *)type->tp_alloc(type, 0);
 
    self->x = 0;
    self->y = 0;
    self->z = 0;
	
    return (PyObject *)self;
}

static int
Point_init(Point *self, PyObject *args, PyObject *kwds)
{
  
    static char *kwlist[] = {"x", "y", "z", NULL};
    if (! PyArg_ParseTupleAndKeywords(args, kwds, "|ddd", kwlist,
                                      &self->x, &self->y,
                                      &self->z))
        return -1;
									  
	
									  
    return 0;
}

static PyMemberDef Point_members[] = {
    {"x", T_DOUBLE, offsetof(Point, x), 0,
     "X coordinate (longitude)"},
    {"y", T_DOUBLE, offsetof(Point, y), 0,
     "Y coordinate (latitude)"},
    {"z", T_DOUBLE, offsetof(Point, z), 0,
     "Z coordinate (altitude)"},
    {NULL}  /* Sentinel */
};


static PyTypeObject PointType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "lambert.Point",             /* tp_name */
    sizeof(Point),             /* tp_basicsize */
    0,                         /* tp_itemsize */
    0, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "Point objects",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    0,             /* tp_methods */
    Point_members,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)Point_init,      /* tp_init */
    0,                         /* tp_alloc */
    Point_new,                 /* tp_new */
};

static PyModuleDef lambertmodule = {
    PyModuleDef_HEAD_INIT,
    "lambert",
    "Example module that creates an extension type.",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_lambert(void)
{
    PyObject* m;

    if (PyType_Ready(&PointType) < 0)
        return NULL;

    m = PyModule_Create(&lambertmodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&PointType);
    PyModule_AddObject(m, "Point", (PyObject *)&PointType);
    return m;
}
