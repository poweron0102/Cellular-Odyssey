#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"

PyMemberDef NewGame_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(PyBaseExceptionObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(PyBaseExceptionObject) + sizeof(PyObject *), 0, NULL},
    {0}
};

static PyGetSetDef NewGame_getseters[] = {
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef NewGame_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_NewGame_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "NewGame",
    .tp_getset = NewGame_getseters,
    .tp_methods = NewGame_methods,
    .tp_members = NewGame_members,
    .tp_basicsize = sizeof(PyBaseExceptionObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(PyBaseExceptionObject),
    .tp_weaklistoffset = sizeof(PyBaseExceptionObject) + sizeof(PyObject *),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE,
};
static PyTypeObject *CPyType_NewGame_template = &CPyType_NewGame_template_;


static int
Game_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *Game_setup(PyTypeObject *type);
PyObject *CPyDef_Game(void);

static PyObject *
Game_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Game) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = Game_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_Game_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
Game_traverse(main___GameObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_level);
    Py_VISIT(self->_screen);
    Py_VISIT(self->_clock);
    Py_VISIT(self->_time);
    Py_VISIT(self->_lest_time);
    Py_VISIT(self->_delta_time);
    Py_VISIT(self->_run_time);
    return 0;
}

static int
Game_clear(main___GameObject *self)
{
    Py_CLEAR(self->_level);
    Py_CLEAR(self->_screen);
    Py_CLEAR(self->_clock);
    Py_CLEAR(self->_time);
    Py_CLEAR(self->_lest_time);
    Py_CLEAR(self->_delta_time);
    Py_CLEAR(self->_run_time);
    return 0;
}

static void
Game_dealloc(main___GameObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Game_dealloc)
    Game_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem Game_vtable[4];
static bool
CPyDef_Game_trait_vtable_setup(void)
{
    CPyVTableItem Game_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Game_____init__,
        (CPyVTableItem)CPyDef_Game___new_game,
        (CPyVTableItem)CPyDef_Game___update,
        (CPyVTableItem)CPyDef_Game___run,
    };
    memcpy(Game_vtable, Game_vtable_scratch, sizeof(Game_vtable));
    return 1;
}

static PyObject *
Game_get_level(main___GameObject *self, void *closure);
static int
Game_set_level(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_screen(main___GameObject *self, void *closure);
static int
Game_set_screen(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_clock(main___GameObject *self, void *closure);
static int
Game_set_clock(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_time(main___GameObject *self, void *closure);
static int
Game_set_time(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_lest_time(main___GameObject *self, void *closure);
static int
Game_set_lest_time(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_delta_time(main___GameObject *self, void *closure);
static int
Game_set_delta_time(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_run_time(main___GameObject *self, void *closure);
static int
Game_set_run_time(main___GameObject *self, PyObject *value, void *closure);

static PyGetSetDef Game_getseters[] = {
    {"level",
     (getter)Game_get_level, (setter)Game_set_level,
     NULL, NULL},
    {"screen",
     (getter)Game_get_screen, (setter)Game_set_screen,
     NULL, NULL},
    {"clock",
     (getter)Game_get_clock, (setter)Game_set_clock,
     NULL, NULL},
    {"time",
     (getter)Game_get_time, (setter)Game_set_time,
     NULL, NULL},
    {"lest_time",
     (getter)Game_get_lest_time, (setter)Game_set_lest_time,
     NULL, NULL},
    {"delta_time",
     (getter)Game_get_delta_time, (setter)Game_set_delta_time,
     NULL, NULL},
    {"run_time",
     (getter)Game_get_run_time, (setter)Game_set_run_time,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Game_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_Game_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"new_game",
     (PyCFunction)CPyPy_Game___new_game,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"update",
     (PyCFunction)CPyPy_Game___update,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"run",
     (PyCFunction)CPyPy_Game___run,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Game_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Game",
    .tp_new = Game_new,
    .tp_dealloc = (destructor)Game_dealloc,
    .tp_traverse = (traverseproc)Game_traverse,
    .tp_clear = (inquiry)Game_clear,
    .tp_getset = Game_getseters,
    .tp_methods = Game_methods,
    .tp_init = Game_init,
    .tp_basicsize = sizeof(main___GameObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_Game_template = &CPyType_Game_template_;

static PyObject *
Game_setup(PyTypeObject *type)
{
    main___GameObject *self;
    self = (main___GameObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Game_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_Game(void)
{
    PyObject *self = Game_setup(CPyType_Game);
    if (self == NULL)
        return NULL;
    char res = CPyDef_Game_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Game_get_level(main___GameObject *self, void *closure)
{
    if (unlikely(self->_level == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'level' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_level);
    PyObject *retval = self->_level;
    return retval;
}

static int
Game_set_level(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'level' cannot be deleted");
        return -1;
    }
    if (self->_level != NULL) {
        CPy_DECREF(self->_level);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_level = tmp;
    return 0;
}

static PyObject *
Game_get_screen(main___GameObject *self, void *closure)
{
    if (unlikely(self->_screen == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'screen' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_screen);
    PyObject *retval = self->_screen;
    return retval;
}

static int
Game_set_screen(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'screen' cannot be deleted");
        return -1;
    }
    if (self->_screen != NULL) {
        CPy_DECREF(self->_screen);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_screen = tmp;
    return 0;
}

static PyObject *
Game_get_clock(main___GameObject *self, void *closure)
{
    if (unlikely(self->_clock == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'clock' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_clock);
    PyObject *retval = self->_clock;
    return retval;
}

static int
Game_set_clock(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'clock' cannot be deleted");
        return -1;
    }
    if (self->_clock != NULL) {
        CPy_DECREF(self->_clock);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_clock = tmp;
    return 0;
}

static PyObject *
Game_get_time(main___GameObject *self, void *closure)
{
    if (unlikely(self->_time == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'time' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_time);
    PyObject *retval = self->_time;
    return retval;
}

static int
Game_set_time(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'time' cannot be deleted");
        return -1;
    }
    if (self->_time != NULL) {
        CPy_DECREF(self->_time);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_time = tmp;
    return 0;
}

static PyObject *
Game_get_lest_time(main___GameObject *self, void *closure)
{
    if (unlikely(self->_lest_time == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'lest_time' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_lest_time);
    PyObject *retval = self->_lest_time;
    return retval;
}

static int
Game_set_lest_time(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'lest_time' cannot be deleted");
        return -1;
    }
    if (self->_lest_time != NULL) {
        CPy_DECREF(self->_lest_time);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_lest_time = tmp;
    return 0;
}

static PyObject *
Game_get_delta_time(main___GameObject *self, void *closure)
{
    if (unlikely(self->_delta_time == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'delta_time' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_delta_time);
    PyObject *retval = self->_delta_time;
    return retval;
}

static int
Game_set_delta_time(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'delta_time' cannot be deleted");
        return -1;
    }
    if (self->_delta_time != NULL) {
        CPy_DECREF(self->_delta_time);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_delta_time = tmp;
    return 0;
}

static PyObject *
Game_get_run_time(main___GameObject *self, void *closure)
{
    if (unlikely(self->_run_time == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'run_time' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_run_time);
    PyObject *retval = self->_run_time;
    return retval;
}

static int
Game_set_run_time(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'run_time' cannot be deleted");
        return -1;
    }
    if (self->_run_time != NULL) {
        CPy_DECREF(self->_run_time);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_run_time = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {"check_events", (PyCFunction)CPyPy_check_events, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "main",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_main(void)
{
    PyObject* modname = NULL;
    if (CPyModule_main_internal) {
        Py_INCREF(CPyModule_main_internal);
        return CPyModule_main_internal;
    }
    CPyModule_main_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_main_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_main_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_main_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_main_internal;
    fail:
    Py_CLEAR(CPyModule_main_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_NewGame);
    Py_CLEAR(CPyType_Game);
    return NULL;
}

PyObject *CPyDef_check_events(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_event;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyTagged cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    cpy_r_r0 = CPyModule_pygame;
    cpy_r_r1 = CPyStatics[3]; /* 'event' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 50, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r3 = CPyStatics[4]; /* 'get' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 50, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r5 = _PyObject_Vectorcall(cpy_r_r4, 0, 0, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 50, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r6 = PyObject_GetIter(cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 50, CPyStatic_globals);
        goto CPyL17;
    }
CPyL4: ;
    cpy_r_r7 = PyIter_Next(cpy_r_r6);
    if (cpy_r_r7 == NULL) goto CPyL18;
    cpy_r_event = cpy_r_r7;
    cpy_r_r8 = CPyStatics[5]; /* 'type' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_event, cpy_r_r8);
    CPy_DECREF(cpy_r_event);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 51, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r10 = CPyModule_pygame;
    cpy_r_r11 = CPyStatics[6]; /* 'QUIT' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 51, CPyStatic_globals);
        goto CPyL20;
    }
    if (likely(PyLong_Check(cpy_r_r12)))
        cpy_r_r13 = CPyTagged_FromObject(cpy_r_r12);
    else {
        CPy_TypeError("int", cpy_r_r12); cpy_r_r13 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == CPY_INT_TAG)) {
        CPy_AddTraceback("main.py", "check_events", 51, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r14 = CPyTagged_StealAsObject(cpy_r_r13);
    cpy_r_r15 = PyObject_RichCompare(cpy_r_r9, cpy_r_r14, 2);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 51, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r16 = PyObject_IsTrue(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("main.py", "check_events", 51, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r18 = cpy_r_r16;
    if (!cpy_r_r18) goto CPyL4;
    cpy_r_r19 = CPyModule_pygame;
    cpy_r_r20 = CPyStatics[7]; /* 'quit' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 52, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r21, 0, 0, 0);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 52, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL21;
CPyL13: ;
    cpy_r_r23 = CPyModule_sys;
    cpy_r_r24 = CPyStatics[8]; /* 'exit' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 53, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r26 = _PyObject_Vectorcall(cpy_r_r25, 0, 0, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("main.py", "check_events", 53, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL22;
CPyL15: ;
    cpy_r_r27 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("main.py", "check_events", 50, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r28 = Py_None;
    CPy_INCREF(cpy_r_r28);
    return cpy_r_r28;
CPyL17: ;
    cpy_r_r29 = NULL;
    return cpy_r_r29;
CPyL18: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL15;
CPyL19: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL17;
CPyL20: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r9);
    goto CPyL17;
CPyL21: ;
    CPy_DECREF(cpy_r_r22);
    goto CPyL13;
CPyL22: ;
    CPy_DECREF(cpy_r_r26);
    goto CPyL4;
}

PyObject *CPyPy_check_events(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":check_events", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *retval = CPyDef_check_events();
    return retval;
fail: ;
    CPy_AddTraceback("main.py", "check_events", 49, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    tuple_T2OO cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    CPyTagged cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    tuple_T2OO cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    cpy_r_r0 = CPyModule_pygame;
    cpy_r_r1 = CPyStatics[9]; /* 'init' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 60, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r3 = _PyObject_Vectorcall(cpy_r_r2, 0, 0, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 60, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL30;
CPyL2: ;
    cpy_r_r4 = CPyModule_pygame;
    cpy_r_r5 = CPyStatics[10]; /* 'font' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 61, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r7 = CPyStatics[9]; /* 'init' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 61, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r8, 0, 0, 0);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 61, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL31;
CPyL5: ;
    cpy_r_r10 = CPyStatic_globals;
    cpy_r_r11 = CPyStatics[11]; /* 'FULLSCREEN' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 62, CPyStatic_globals);
        goto CPyL29;
    }
    if (unlikely(!PyBool_Check(cpy_r_r12))) {
        CPy_TypeError("bool", cpy_r_r12); cpy_r_r13 = 2;
    } else
        cpy_r_r13 = cpy_r_r12 == Py_True;
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("main.py", "__init__", 62, CPyStatic_globals);
        goto CPyL29;
    }
    if (!cpy_r_r13) goto CPyL14;
    cpy_r_r14 = CPyStatics[96]; /* 1280 */
    cpy_r_r15 = CPyStatics[97]; /* 720 */
    CPy_INCREF(cpy_r_r14);
    CPy_INCREF(cpy_r_r15);
    cpy_r_r16.f0 = cpy_r_r14;
    cpy_r_r16.f1 = cpy_r_r15;
    cpy_r_r17 = CPyModule_pygame;
    cpy_r_r18 = CPyStatics[11]; /* 'FULLSCREEN' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 63, CPyStatic_globals);
        goto CPyL32;
    }
    if (likely(PyLong_Check(cpy_r_r19)))
        cpy_r_r20 = CPyTagged_FromObject(cpy_r_r19);
    else {
        CPy_TypeError("int", cpy_r_r19); cpy_r_r20 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == CPY_INT_TAG)) {
        CPy_AddTraceback("main.py", "__init__", 63, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r21 = CPyModule_pygame;
    cpy_r_r22 = CPyStatics[12]; /* 'display' */
    cpy_r_r23 = CPyObject_GetAttr(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 63, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r24 = CPyStatics[13]; /* 'set_mode' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 63, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r26 = PyTuple_New(2);
    if (unlikely(cpy_r_r26 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r16.f0;
    PyTuple_SET_ITEM(cpy_r_r26, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r16.f1;
    PyTuple_SET_ITEM(cpy_r_r26, 1, __tmp2);
    cpy_r_r27 = CPyTagged_StealAsObject(cpy_r_r20);
    PyObject *cpy_r_r28[2] = {cpy_r_r26, cpy_r_r27};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r29, 2, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 63, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r27);
    ((main___GameObject *)cpy_r_self)->_screen = cpy_r_r30;
    goto CPyL18;
CPyL14: ;
    cpy_r_r31 = CPyStatics[96]; /* 1280 */
    cpy_r_r32 = CPyStatics[97]; /* 720 */
    CPy_INCREF(cpy_r_r31);
    CPy_INCREF(cpy_r_r32);
    cpy_r_r33.f0 = cpy_r_r31;
    cpy_r_r33.f1 = cpy_r_r32;
    cpy_r_r34 = CPyModule_pygame;
    cpy_r_r35 = CPyStatics[12]; /* 'display' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 65, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r37 = CPyStatics[13]; /* 'set_mode' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 65, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r39 = PyTuple_New(2);
    if (unlikely(cpy_r_r39 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = cpy_r_r33.f0;
    PyTuple_SET_ITEM(cpy_r_r39, 0, __tmp3);
    PyObject *__tmp4 = cpy_r_r33.f1;
    PyTuple_SET_ITEM(cpy_r_r39, 1, __tmp4);
    PyObject *cpy_r_r40[1] = {cpy_r_r39};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r38, cpy_r_r41, 1, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 65, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DECREF(cpy_r_r39);
    ((main___GameObject *)cpy_r_self)->_screen = cpy_r_r42;
CPyL18: ;
    cpy_r_r43 = CPyModule_pygame;
    cpy_r_r44 = CPyStatics[14]; /* 'time' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 67, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r46 = CPyStatics[15]; /* 'Clock' */
    cpy_r_r47 = CPyObject_GetAttr(cpy_r_r45, cpy_r_r46);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 67, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r47, 0, 0, 0);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 67, CPyStatic_globals);
        goto CPyL29;
    }
    ((main___GameObject *)cpy_r_self)->_clock = cpy_r_r48;
    cpy_r_r49 = CPyModule_pygame;
    cpy_r_r50 = CPyStatics[14]; /* 'time' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 68, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r52 = CPyStatics[16]; /* 'get_ticks' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_r51, cpy_r_r52);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 68, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r53, 0, 0, 0);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 68, CPyStatic_globals);
        goto CPyL29;
    }
    ((main___GameObject *)cpy_r_self)->_time = cpy_r_r54;
    cpy_r_r55 = CPyModule_pygame;
    cpy_r_r56 = CPyStatics[14]; /* 'time' */
    cpy_r_r57 = CPyObject_GetAttr(cpy_r_r55, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 69, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r58 = CPyStatics[16]; /* 'get_ticks' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_r57, cpy_r_r58);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 69, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r60 = _PyObject_Vectorcall(cpy_r_r59, 0, 0, 0);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 69, CPyStatic_globals);
        goto CPyL29;
    }
    ((main___GameObject *)cpy_r_self)->_lest_time = cpy_r_r60;
    cpy_r_r61 = CPyStatics[98]; /* 0 */
    CPy_INCREF(cpy_r_r61);
    ((main___GameObject *)cpy_r_self)->_delta_time = cpy_r_r61;
    cpy_r_r62 = CPyStatics[98]; /* 0 */
    CPy_INCREF(cpy_r_r62);
    ((main___GameObject *)cpy_r_self)->_run_time = cpy_r_r62;
    cpy_r_r63 = CPyStatics[17]; /* 'main_menu' */
    cpy_r_r64 = NULL;
    cpy_r_r65 = 1 ? Py_True : Py_False;
    cpy_r_r66 = CPyDef_Game___new_game(cpy_r_self, cpy_r_r63, cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 72, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL37;
CPyL28: ;
    return 1;
CPyL29: ;
    cpy_r_r67 = 2;
    return cpy_r_r67;
CPyL30: ;
    CPy_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL31: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL5;
CPyL32: ;
    CPy_DecRef(cpy_r_r16.f0);
    CPy_DecRef(cpy_r_r16.f1);
    goto CPyL29;
CPyL33: ;
    CPy_DecRef(cpy_r_r16.f0);
    CPy_DecRef(cpy_r_r16.f1);
    CPyTagged_DecRef(cpy_r_r20);
    goto CPyL29;
CPyL34: ;
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r27);
    goto CPyL29;
CPyL35: ;
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    goto CPyL29;
CPyL36: ;
    CPy_DecRef(cpy_r_r39);
    goto CPyL29;
CPyL37: ;
    CPy_DECREF(cpy_r_r66);
    goto CPyL28;
}

PyObject *CPyPy_Game_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    char retval = CPyDef_Game_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "__init__", 59, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Game___new_game(PyObject *cpy_r_self, PyObject *cpy_r_level, PyObject *cpy_r_set_screen, PyObject *cpy_r_supress) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    tuple_T2II cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    CPyTagged cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject **cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject **cpy_r_r86;
    PyObject *cpy_r_r87;
    int32_t cpy_r_r88;
    char cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    if (cpy_r_set_screen != NULL) goto CPyL45;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_set_screen = cpy_r_r0;
CPyL2: ;
    if (cpy_r_supress != NULL) goto CPyL46;
    cpy_r_r1 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r1);
    cpy_r_supress = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = PyObject_IsTrue(cpy_r_set_screen);
    cpy_r_r3 = cpy_r_r2 >= 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("main.py", "new_game", 75, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r4 = cpy_r_r2;
    if (!cpy_r_r4) goto CPyL48;
    cpy_r_r5 = CPyModule_pygame;
    cpy_r_r6 = CPyStatics[12]; /* 'display' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 78, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r8 = CPyStatics[13]; /* 'set_mode' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 78, CPyStatic_globals);
        goto CPyL47;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_set_screen};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 78, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_DECREF(((main___GameObject *)cpy_r_self)->_screen);
    ((main___GameObject *)cpy_r_self)->_screen = cpy_r_r12;
    cpy_r_r14 = ((main___GameObject *)cpy_r_self)->_screen;
    CPy_INCREF(cpy_r_r14);
    cpy_r_r15 = CPyStatics[18]; /* 'assets/gui/load.png' */
    cpy_r_r16 = CPyModule_pygame;
    cpy_r_r17 = CPyStatics[19]; /* 'image' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r19 = CPyStatics[20]; /* 'load' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL49;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r15};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = _PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r24 = CPyModule_pygame;
    cpy_r_r25 = CPyStatics[21]; /* 'transform' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r27 = CPyStatics[22]; /* 'scale' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL50;
    }
    PyObject *cpy_r_r29[2] = {cpy_r_r23, cpy_r_set_screen};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = _PyObject_Vectorcall(cpy_r_r28, cpy_r_r30, 2, 0);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_set_screen);
    cpy_r_r32.f0 = 0;
    cpy_r_r32.f1 = 0;
    cpy_r_r33 = CPyStatics[23]; /* 'blit' */
    cpy_r_r34 = PyTuple_New(2);
    if (unlikely(cpy_r_r34 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = CPyTagged_StealAsObject(cpy_r_r32.f0);
    PyTuple_SET_ITEM(cpy_r_r34, 0, __tmp5);
    PyObject *__tmp6 = CPyTagged_StealAsObject(cpy_r_r32.f1);
    PyTuple_SET_ITEM(cpy_r_r34, 1, __tmp6);
    PyObject *cpy_r_r35[3] = {cpy_r_r14, cpy_r_r31, cpy_r_r34};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_VectorcallMethod(cpy_r_r33, cpy_r_r36, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 79, CPyStatic_globals);
        goto CPyL51;
    } else
        goto CPyL52;
CPyL16: ;
    CPy_DECREF(cpy_r_r14);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r38 = CPyModule_pygame;
    cpy_r_r39 = CPyStatics[12]; /* 'display' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 80, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r41 = CPyStatics[24]; /* 'flip' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 80, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r43 = _PyObject_Vectorcall(cpy_r_r42, 0, 0, 0);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 80, CPyStatic_globals);
        goto CPyL53;
    } else
        goto CPyL54;
CPyL19: ;
    cpy_r_r44 = CPyStatic_globals;
    cpy_r_r45 = CPyStatics[11]; /* 'FULLSCREEN' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL53;
    }
    if (unlikely(!PyBool_Check(cpy_r_r46))) {
        CPy_TypeError("bool", cpy_r_r46); cpy_r_r47 = 2;
    } else
        cpy_r_r47 = cpy_r_r46 == Py_True;
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == 2)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL53;
    }
    if (!cpy_r_r47) goto CPyL33;
    cpy_r_r48 = CPyModule_pygame;
    cpy_r_r49 = CPyStatics[12]; /* 'display' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r51 = CPyStatics[25]; /* 'get_surface' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r50, cpy_r_r51);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r53 = _PyObject_Vectorcall(cpy_r_r52, 0, 0, 0);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r54 = CPyStatics[26]; /* 'get_flags' */
    PyObject *cpy_r_r55[1] = {cpy_r_r53};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = PyObject_VectorcallMethod(cpy_r_r54, cpy_r_r56, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r53);
    if (likely(PyLong_Check(cpy_r_r57)))
        cpy_r_r58 = CPyTagged_FromObject(cpy_r_r57);
    else {
        CPy_TypeError("int", cpy_r_r57); cpy_r_r58 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == CPY_INT_TAG)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r59 = CPyModule_pygame;
    cpy_r_r60 = CPyStatics[11]; /* 'FULLSCREEN' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r59, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL56;
    }
    if (likely(PyLong_Check(cpy_r_r61)))
        cpy_r_r62 = CPyTagged_FromObject(cpy_r_r61);
    else {
        CPy_TypeError("int", cpy_r_r61); cpy_r_r62 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r62 == CPY_INT_TAG)) {
        CPy_AddTraceback("main.py", "new_game", 81, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r63 = CPyTagged_And(cpy_r_r58, cpy_r_r62);
    CPyTagged_DECREF(cpy_r_r58);
    CPyTagged_DECREF(cpy_r_r62);
    cpy_r_r64 = cpy_r_r63 != 0;
    CPyTagged_DECREF(cpy_r_r63);
    if (cpy_r_r64) goto CPyL33;
    cpy_r_r65 = CPyModule_pygame;
    cpy_r_r66 = CPyStatics[12]; /* 'display' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 82, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r68 = CPyStatics[27]; /* 'toggle_fullscreen' */
    cpy_r_r69 = CPyObject_GetAttr(cpy_r_r67, cpy_r_r68);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 82, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r70 = _PyObject_Vectorcall(cpy_r_r69, 0, 0, 0);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 82, CPyStatic_globals);
        goto CPyL53;
    } else
        goto CPyL57;
CPyL33: ;
    cpy_r_r71 = CPyStatics[28]; /* '.' */
    cpy_r_r72 = CPyStr_Build(2, cpy_r_r71, cpy_r_level);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 84, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r73 = CPyStatics[29]; /* 'levels' */
    cpy_r_r74 = CPyStatic_globals;
    cpy_r_r75 = CPyStatics[30]; /* 'import_module' */
    cpy_r_r76 = CPyDict_GetItem(cpy_r_r74, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 84, CPyStatic_globals);
        goto CPyL58;
    }
    PyObject *cpy_r_r77[2] = {cpy_r_r72, cpy_r_r73};
    cpy_r_r78 = (PyObject **)&cpy_r_r77;
    cpy_r_r79 = _PyObject_Vectorcall(cpy_r_r76, cpy_r_r78, 2, 0);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 84, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_r72);
    if (((main___GameObject *)cpy_r_self)->_level != NULL) {
        CPy_DECREF(((main___GameObject *)cpy_r_self)->_level);
    }
    ((main___GameObject *)cpy_r_self)->_level = cpy_r_r79;
    cpy_r_r80 = 1;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("main.py", "new_game", 84, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r81 = CPyStatics[98]; /* 0 */
    CPy_INCREF(cpy_r_r81);
    CPy_DECREF(((main___GameObject *)cpy_r_self)->_run_time);
    ((main___GameObject *)cpy_r_self)->_run_time = cpy_r_r81;
    cpy_r_r83 = ((main___GameObject *)cpy_r_self)->_level;
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AttributeError("main.py", "new_game", "Game", "level", 86, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF(cpy_r_r83);
CPyL38: ;
    cpy_r_r84 = CPyStatics[9]; /* 'init' */
    PyObject *cpy_r_r85[2] = {cpy_r_r83, cpy_r_self};
    cpy_r_r86 = (PyObject **)&cpy_r_r85;
    cpy_r_r87 = PyObject_VectorcallMethod(cpy_r_r84, cpy_r_r86, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("main.py", "new_game", 86, CPyStatic_globals);
        goto CPyL59;
    } else
        goto CPyL60;
CPyL39: ;
    CPy_DECREF(cpy_r_r83);
    cpy_r_r88 = PyObject_IsTrue(cpy_r_supress);
    CPy_DECREF(cpy_r_supress);
    cpy_r_r89 = cpy_r_r88 >= 0;
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("main.py", "new_game", 75, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r90 = cpy_r_r88;
    if (cpy_r_r90) goto CPyL43;
    cpy_r_r91 = (PyObject *)CPyType_NewGame;
    CPy_Raise(cpy_r_r91);
    if (unlikely(!0)) {
        CPy_AddTraceback("main.py", "new_game", 88, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_Unreachable();
CPyL43: ;
    cpy_r_r92 = Py_None;
    CPy_INCREF(cpy_r_r92);
    return cpy_r_r92;
CPyL44: ;
    cpy_r_r93 = NULL;
    return cpy_r_r93;
CPyL45: ;
    CPy_INCREF(cpy_r_set_screen);
    goto CPyL2;
CPyL46: ;
    CPy_INCREF(cpy_r_supress);
    goto CPyL4;
CPyL47: ;
    CPy_DecRef(cpy_r_set_screen);
    CPy_DecRef(cpy_r_supress);
    goto CPyL44;
CPyL48: ;
    CPy_DECREF(cpy_r_set_screen);
    goto CPyL33;
CPyL49: ;
    CPy_DecRef(cpy_r_set_screen);
    CPy_DecRef(cpy_r_supress);
    CPy_DecRef(cpy_r_r14);
    goto CPyL44;
CPyL50: ;
    CPy_DecRef(cpy_r_set_screen);
    CPy_DecRef(cpy_r_supress);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r23);
    goto CPyL44;
CPyL51: ;
    CPy_DecRef(cpy_r_supress);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r34);
    goto CPyL44;
CPyL52: ;
    CPy_DECREF(cpy_r_r37);
    goto CPyL16;
CPyL53: ;
    CPy_DecRef(cpy_r_supress);
    goto CPyL44;
CPyL54: ;
    CPy_DECREF(cpy_r_r43);
    goto CPyL19;
CPyL55: ;
    CPy_DecRef(cpy_r_supress);
    CPy_DecRef(cpy_r_r53);
    goto CPyL44;
CPyL56: ;
    CPy_DecRef(cpy_r_supress);
    CPyTagged_DecRef(cpy_r_r58);
    goto CPyL44;
CPyL57: ;
    CPy_DECREF(cpy_r_r70);
    goto CPyL33;
CPyL58: ;
    CPy_DecRef(cpy_r_supress);
    CPy_DecRef(cpy_r_r72);
    goto CPyL44;
CPyL59: ;
    CPy_DecRef(cpy_r_supress);
    CPy_DecRef(cpy_r_r83);
    goto CPyL44;
CPyL60: ;
    CPy_DECREF(cpy_r_r87);
    goto CPyL39;
}

PyObject *CPyPy_Game___new_game(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"level", "set_screen", "supress", 0};
    static CPyArg_Parser parser = {"O|OO:new_game", kwlist, 0};
    PyObject *obj_level;
    PyObject *obj_set_screen = NULL;
    PyObject *obj_supress = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_level, &obj_set_screen, &obj_supress)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    PyObject *arg_level;
    if (likely(PyUnicode_Check(obj_level)))
        arg_level = obj_level;
    else {
        CPy_TypeError("str", obj_level); 
        goto fail;
    }
    PyObject *arg_set_screen;
    if (obj_set_screen == NULL) {
        arg_set_screen = NULL;
    } else {
        arg_set_screen = obj_set_screen; 
    }
    PyObject *arg_supress;
    if (obj_supress == NULL) {
        arg_supress = NULL;
    } else {
        arg_supress = obj_supress; 
    }
    PyObject *retval = CPyDef_Game___new_game(arg_self, arg_level, arg_set_screen, arg_supress);
    return retval;
fail: ;
    CPy_AddTraceback("main.py", "new_game", 75, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Game___update(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T3OOO cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    CPyTagged cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    char cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    CPyPtr cpy_r_r59;
    CPyPtr cpy_r_r60;
    CPyPtr cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject **cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    cpy_r_r0 = CPyModule_pygame;
    cpy_r_r1 = CPyStatics[12]; /* 'display' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("main.py", "update", 91, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r3 = CPyStatics[24]; /* 'flip' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "update", 91, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r5 = _PyObject_Vectorcall(cpy_r_r4, 0, 0, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("main.py", "update", 91, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL22;
CPyL3: ;
    cpy_r_r6 = ((main___GameObject *)cpy_r_self)->_screen;
    CPy_INCREF(cpy_r_r6);
    cpy_r_r7 = CPyStatics[98]; /* 0 */
    cpy_r_r8 = CPyStatics[98]; /* 0 */
    cpy_r_r9 = CPyStatics[98]; /* 0 */
    CPy_INCREF(cpy_r_r7);
    CPy_INCREF(cpy_r_r8);
    CPy_INCREF(cpy_r_r9);
    cpy_r_r10.f0 = cpy_r_r7;
    cpy_r_r10.f1 = cpy_r_r8;
    cpy_r_r10.f2 = cpy_r_r9;
    cpy_r_r11 = CPyStatics[31]; /* 'fill' */
    cpy_r_r12 = PyTuple_New(3);
    if (unlikely(cpy_r_r12 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r12, 0, __tmp7);
    PyObject *__tmp8 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r12, 1, __tmp8);
    PyObject *__tmp9 = cpy_r_r10.f2;
    PyTuple_SET_ITEM(cpy_r_r12, 2, __tmp9);
    PyObject *cpy_r_r13[2] = {cpy_r_r6, cpy_r_r12};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r14, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("main.py", "update", 92, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL24;
CPyL4: ;
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r16 = ((main___GameObject *)cpy_r_self)->_clock;
    CPy_INCREF(cpy_r_r16);
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyStatics[32]; /* 'FPS' */
    cpy_r_r19 = CPyDict_GetItem(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "update", 93, CPyStatic_globals);
        goto CPyL25;
    }
    if (likely(PyLong_Check(cpy_r_r19)))
        cpy_r_r20 = CPyTagged_FromObject(cpy_r_r19);
    else {
        CPy_TypeError("int", cpy_r_r19); cpy_r_r20 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == CPY_INT_TAG)) {
        CPy_AddTraceback("main.py", "update", 93, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r21 = CPyStatics[33]; /* 'tick' */
    cpy_r_r22 = CPyTagged_StealAsObject(cpy_r_r20);
    PyObject *cpy_r_r23[2] = {cpy_r_r16, cpy_r_r22};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = PyObject_VectorcallMethod(cpy_r_r21, cpy_r_r24, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("main.py", "update", 93, CPyStatic_globals);
        goto CPyL26;
    } else
        goto CPyL27;
CPyL7: ;
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r26 = ((main___GameObject *)cpy_r_self)->_time;
    CPy_INCREF(cpy_r_r26);
    CPy_DECREF(((main___GameObject *)cpy_r_self)->_lest_time);
    ((main___GameObject *)cpy_r_self)->_lest_time = cpy_r_r26;
    cpy_r_r28 = CPyModule_pygame;
    cpy_r_r29 = CPyStatics[14]; /* 'time' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("main.py", "update", 95, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r31 = CPyStatics[16]; /* 'get_ticks' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("main.py", "update", 95, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r33 = _PyObject_Vectorcall(cpy_r_r32, 0, 0, 0);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("main.py", "update", 95, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(((main___GameObject *)cpy_r_self)->_time);
    ((main___GameObject *)cpy_r_self)->_time = cpy_r_r33;
    cpy_r_r35 = ((main___GameObject *)cpy_r_self)->_time;
    CPy_INCREF(cpy_r_r35);
    cpy_r_r36 = ((main___GameObject *)cpy_r_self)->_lest_time;
    CPy_INCREF(cpy_r_r36);
    cpy_r_r37 = PyNumber_Subtract(cpy_r_r35, cpy_r_r36);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("main.py", "update", 96, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r38 = PyFloat_FromDouble(1000.0);
    cpy_r_r39 = PyNumber_TrueDivide(cpy_r_r37, cpy_r_r38);
    CPy_DECREF(cpy_r_r37);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("main.py", "update", 96, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(((main___GameObject *)cpy_r_self)->_delta_time);
    ((main___GameObject *)cpy_r_self)->_delta_time = cpy_r_r39;
    cpy_r_r41 = ((main___GameObject *)cpy_r_self)->_run_time;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = ((main___GameObject *)cpy_r_self)->_delta_time;
    CPy_INCREF(cpy_r_r42);
    cpy_r_r43 = PyNumber_InPlaceAdd(cpy_r_r41, cpy_r_r42);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("main.py", "update", 97, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(((main___GameObject *)cpy_r_self)->_run_time);
    ((main___GameObject *)cpy_r_self)->_run_time = cpy_r_r43;
    cpy_r_r45 = CPyStatics[34]; /* '' */
    cpy_r_r46 = CPyStatics[35]; /* 'Cellular Odyssey   FPS: ' */
    cpy_r_r47 = CPyStatics[36]; /* '{:{}}' */
    cpy_r_r48 = ((main___GameObject *)cpy_r_self)->_clock;
    CPy_INCREF(cpy_r_r48);
    cpy_r_r49 = CPyStatics[37]; /* 'get_fps' */
    PyObject *cpy_r_r50[1] = {cpy_r_r48};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = PyObject_VectorcallMethod(cpy_r_r49, cpy_r_r51, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_DECREF(cpy_r_r48);
    cpy_r_r53 = CPyStatics[38]; /* '.1f' */
    cpy_r_r54 = CPyStatics[39]; /* 'format' */
    PyObject *cpy_r_r55[3] = {cpy_r_r47, cpy_r_r52, cpy_r_r53};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = PyObject_VectorcallMethod(cpy_r_r54, cpy_r_r56, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL29;
    }
    CPy_DECREF(cpy_r_r52);
    cpy_r_r58 = PyList_New(2);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r59 = (CPyPtr)&((PyListObject *)cpy_r_r58)->ob_item;
    cpy_r_r60 = *(CPyPtr *)cpy_r_r59;
    CPy_INCREF(cpy_r_r46);
    *(PyObject * *)cpy_r_r60 = cpy_r_r46;
    cpy_r_r61 = cpy_r_r60 + 8;
    *(PyObject * *)cpy_r_r61 = cpy_r_r57;
    cpy_r_r62 = PyUnicode_Join(cpy_r_r45, cpy_r_r58);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r63 = CPyModule_pygame;
    cpy_r_r64 = CPyStatics[12]; /* 'display' */
    cpy_r_r65 = CPyObject_GetAttr(cpy_r_r63, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r66 = CPyStatics[40]; /* 'set_caption' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL31;
    }
    PyObject *cpy_r_r68[1] = {cpy_r_r62};
    cpy_r_r69 = (PyObject **)&cpy_r_r68;
    cpy_r_r70 = _PyObject_Vectorcall(cpy_r_r67, cpy_r_r69, 1, 0);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("main.py", "update", 98, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL32;
CPyL20: ;
    CPy_DECREF(cpy_r_r62);
    cpy_r_r71 = Py_None;
    CPy_INCREF(cpy_r_r71);
    return cpy_r_r71;
CPyL21: ;
    cpy_r_r72 = NULL;
    return cpy_r_r72;
CPyL22: ;
    CPy_DECREF(cpy_r_r5);
    goto CPyL3;
CPyL23: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    goto CPyL21;
CPyL24: ;
    CPy_DECREF(cpy_r_r15);
    goto CPyL4;
CPyL25: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL21;
CPyL26: ;
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r22);
    goto CPyL21;
CPyL27: ;
    CPy_DECREF(cpy_r_r25);
    goto CPyL7;
CPyL28: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL21;
CPyL29: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL21;
CPyL30: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL21;
CPyL31: ;
    CPy_DecRef(cpy_r_r62);
    goto CPyL21;
CPyL32: ;
    CPy_DECREF(cpy_r_r70);
    goto CPyL20;
}

PyObject *CPyPy_Game___update(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":update", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *retval = CPyDef_Game___update(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("main.py", "update", 90, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Game___run(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    tuple_T3OOO cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
CPyL1: ;
    if (!1) goto CPyL13;
    cpy_r_r0 = CPyDef_check_events();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("main.py", "run", 102, CPyStatic_globals);
        goto CPyL14;
    } else
        goto CPyL15;
CPyL3: ;
    cpy_r_r1 = CPyDef_Game___update(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("main.py", "run", 103, CPyStatic_globals);
        goto CPyL14;
    } else
        goto CPyL16;
CPyL4: ;
    cpy_r_r2 = ((main___GameObject *)cpy_r_self)->_level;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("main.py", "run", "Game", "level", 105, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r2);
CPyL5: ;
    cpy_r_r3 = CPyStatics[41]; /* 'loop' */
    PyObject *cpy_r_r4[2] = {cpy_r_r2, cpy_r_self};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("main.py", "run", 105, CPyStatic_globals);
        goto CPyL17;
    } else
        goto CPyL18;
CPyL6: ;
    CPy_DECREF(cpy_r_r2);
    goto CPyL1;
CPyL7: ;
    cpy_r_r7 = CPy_CatchError();
    cpy_r_r8 = (PyObject *)CPyType_NewGame;
    cpy_r_r9 = CPy_ExceptionMatches(cpy_r_r8);
    if (cpy_r_r9) goto CPyL10;
    CPy_Reraise();
    if (!0) {
        goto CPyL11;
    } else
        goto CPyL19;
CPyL9: ;
    CPy_Unreachable();
CPyL10: ;
    CPy_RestoreExcInfo(cpy_r_r7);
    CPy_DecRef(cpy_r_r7.f0);
    CPy_DecRef(cpy_r_r7.f1);
    CPy_DecRef(cpy_r_r7.f2);
    goto CPyL1;
CPyL11: ;
    CPy_RestoreExcInfo(cpy_r_r7);
    CPy_DecRef(cpy_r_r7.f0);
    CPy_DecRef(cpy_r_r7.f1);
    CPy_DecRef(cpy_r_r7.f2);
    cpy_r_r10 = CPy_KeepPropagating();
    if (!cpy_r_r10) goto CPyL14;
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r11 = Py_None;
    CPy_INCREF(cpy_r_r11);
    return cpy_r_r11;
CPyL14: ;
    cpy_r_r12 = NULL;
    return cpy_r_r12;
CPyL15: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL3;
CPyL16: ;
    CPy_DECREF(cpy_r_r1);
    goto CPyL4;
CPyL17: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL7;
CPyL18: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL6;
CPyL19: ;
    CPy_DecRef(cpy_r_r7.f0);
    CPy_DecRef(cpy_r_r7.f1);
    CPy_DecRef(cpy_r_r7.f2);
    goto CPyL9;
}

PyObject *CPyPy_Game___run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":run", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *retval = CPyDef_Game___run(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("main.py", "run", 100, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    PyObject **cpy_r_r6;
    PyObject **cpy_r_r7;
    void *cpy_r_r9;
    void *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r21;
    PyObject **cpy_r_r22;
    void *cpy_r_r24;
    void *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r40;
    PyObject **cpy_r_r41;
    void *cpy_r_r43;
    void *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    PyObject **cpy_r_r51;
    PyObject **cpy_r_r52;
    void *cpy_r_r54;
    void *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    char cpy_r_r61;
    tuple_T3OOO cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject **cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject **cpy_r_r81;
    PyObject **cpy_r_r82;
    void *cpy_r_r84;
    void *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    char cpy_r_r91;
    char cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    char cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    char cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    char cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    char cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    char cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    char cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    char cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    char cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    char cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    char cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    char cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    char cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    char cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    char cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    char cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    int32_t cpy_r_r188;
    char cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    int32_t cpy_r_r192;
    char cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    char cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    int32_t cpy_r_r208;
    char cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    int32_t cpy_r_r212;
    char cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    int32_t cpy_r_r219;
    char cpy_r_r220;
    PyObject *cpy_r_r221;
    char cpy_r_r222;
    char cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    int32_t cpy_r_r228;
    char cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    char cpy_r_r235;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[42]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", -1, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_sys;
    cpy_r_r6 = (PyObject **)&CPyModule_os;
    cpy_r_r7 = (PyObject **)&CPyModule_time;
    PyObject **cpy_r_r8[3] = {cpy_r_r5, cpy_r_r6, cpy_r_r7};
    cpy_r_r9 = (void *)&cpy_r_r8;
    int64_t cpy_r_r10[3] = {1, 2, 3};
    cpy_r_r11 = (void *)&cpy_r_r10;
    cpy_r_r12 = CPyStatics[102]; /* (('sys', 'sys', 'sys'), ('os', 'os', 'os'),
                                    ('time', 'time', 'time')) */
    cpy_r_r13 = CPyStatic_globals;
    cpy_r_r14 = CPyStatics[45]; /* 'main.py' */
    cpy_r_r15 = CPyStatics[46]; /* '<module>' */
    cpy_r_r16 = CPyImport_ImportMany(cpy_r_r12, cpy_r_r9, cpy_r_r13, cpy_r_r14, cpy_r_r15, cpy_r_r11);
    if (!cpy_r_r16) goto CPyL96;
    cpy_r_r17 = CPyStatics[103]; /* ('ModuleType',) */
    cpy_r_r18 = CPyStatics[48]; /* 'types' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 4, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_types = cpy_r_r20;
    CPy_INCREF(CPyModule_types);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = (PyObject **)&CPyModule_builtins;
    cpy_r_r22 = (PyObject **)&CPyModule_dataclasses;
    PyObject **cpy_r_r23[2] = {cpy_r_r21, cpy_r_r22};
    cpy_r_r24 = (void *)&cpy_r_r23;
    int64_t cpy_r_r25[2] = {5, 6};
    cpy_r_r26 = (void *)&cpy_r_r25;
    cpy_r_r27 = CPyStatics[106]; /* (('builtins', 'builtins', 'builtins'),
                                    ('dataclasses', 'dataclasses', 'dataclasses')) */
    cpy_r_r28 = CPyStatic_globals;
    cpy_r_r29 = CPyStatics[45]; /* 'main.py' */
    cpy_r_r30 = CPyStatics[46]; /* '<module>' */
    cpy_r_r31 = CPyImport_ImportMany(cpy_r_r27, cpy_r_r24, cpy_r_r28, cpy_r_r29, cpy_r_r30, cpy_r_r26);
    if (!cpy_r_r31) goto CPyL96;
    cpy_r_r32 = CPyStatics[107]; /* ('Enum',) */
    cpy_r_r33 = CPyStatics[51]; /* 'enum' */
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyImport_ImportFromMany(cpy_r_r33, cpy_r_r32, cpy_r_r32, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 7, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_enum = cpy_r_r35;
    CPy_INCREF(CPyModule_enum);
    CPy_DECREF(cpy_r_r35);
    cpy_r_r36 = CPyStatics[108]; /* ('import_module',) */
    cpy_r_r37 = CPyStatics[52]; /* 'importlib' */
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyImport_ImportFromMany(cpy_r_r37, cpy_r_r36, cpy_r_r36, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 8, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_importlib = cpy_r_r39;
    CPy_INCREF(CPyModule_importlib);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r40 = (PyObject **)&CPyModule_math;
    cpy_r_r41 = (PyObject **)&CPyModule_random;
    PyObject **cpy_r_r42[2] = {cpy_r_r40, cpy_r_r41};
    cpy_r_r43 = (void *)&cpy_r_r42;
    int64_t cpy_r_r44[2] = {9, 10};
    cpy_r_r45 = (void *)&cpy_r_r44;
    cpy_r_r46 = CPyStatics[111]; /* (('math', 'math', 'math'), ('random', 'random', 'random')) */
    cpy_r_r47 = CPyStatic_globals;
    cpy_r_r48 = CPyStatics[45]; /* 'main.py' */
    cpy_r_r49 = CPyStatics[46]; /* '<module>' */
    cpy_r_r50 = CPyImport_ImportMany(cpy_r_r46, cpy_r_r43, cpy_r_r47, cpy_r_r48, cpy_r_r49, cpy_r_r45);
    if (!cpy_r_r50) goto CPyL96;
    cpy_r_r51 = (PyObject **)&CPyModule_pygame;
    cpy_r_r52 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r53[2] = {cpy_r_r51, cpy_r_r52};
    cpy_r_r54 = (void *)&cpy_r_r53;
    int64_t cpy_r_r55[2] = {13, 14};
    cpy_r_r56 = (void *)&cpy_r_r55;
    cpy_r_r57 = CPyStatics[114]; /* (('pygame', 'pygame', 'pg'), ('numpy', 'numpy', 'np')) */
    cpy_r_r58 = CPyStatic_globals;
    cpy_r_r59 = CPyStatics[45]; /* 'main.py' */
    cpy_r_r60 = CPyStatics[46]; /* '<module>' */
    cpy_r_r61 = CPyImport_ImportMany(cpy_r_r57, cpy_r_r54, cpy_r_r58, cpy_r_r59, cpy_r_r60, cpy_r_r56);
    if (cpy_r_r61) goto CPyL22;
    cpy_r_r62 = CPy_CatchError();
    cpy_r_r63 = CPyModule_builtins;
    cpy_r_r64 = CPyStatics[59]; /* 'ImportError' */
    cpy_r_r65 = CPyObject_GetAttr(cpy_r_r63, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 16, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r66 = CPy_ExceptionMatches(cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    if (!cpy_r_r66) goto CPyL17;
    cpy_r_r67 = CPyStatics[60]; /* ('Erro ao importar pygame, numpy ou numba.\n'
                                   'Instalando dependências...') */
    cpy_r_r68 = CPyModule_builtins;
    cpy_r_r69 = CPyStatics[61]; /* 'print' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 17, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r71[1] = {cpy_r_r67};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = _PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 1, 0);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 17, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL97;
CPyL14: ;
    cpy_r_r74 = CPyStatics[62]; /* 'pip install pygame numpy numba' */
    cpy_r_r75 = CPyModule_os;
    cpy_r_r76 = CPyStatics[63]; /* 'system' */
    cpy_r_r77 = CPyObject_GetAttr(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 18, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r78[1] = {cpy_r_r74};
    cpy_r_r79 = (PyObject **)&cpy_r_r78;
    cpy_r_r80 = _PyObject_Vectorcall(cpy_r_r77, cpy_r_r79, 1, 0);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 18, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL98;
CPyL16: ;
    cpy_r_r81 = (PyObject **)&CPyModule_pygame;
    cpy_r_r82 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r83[2] = {cpy_r_r81, cpy_r_r82};
    cpy_r_r84 = (void *)&cpy_r_r83;
    int64_t cpy_r_r85[2] = {19, 20};
    cpy_r_r86 = (void *)&cpy_r_r85;
    cpy_r_r87 = CPyStatics[114]; /* (('pygame', 'pygame', 'pg'), ('numpy', 'numpy', 'np')) */
    cpy_r_r88 = CPyStatic_globals;
    cpy_r_r89 = CPyStatics[45]; /* 'main.py' */
    cpy_r_r90 = CPyStatics[46]; /* '<module>' */
    cpy_r_r91 = CPyImport_ImportMany(cpy_r_r87, cpy_r_r84, cpy_r_r88, cpy_r_r89, cpy_r_r90, cpy_r_r86);
    if (!cpy_r_r91) {
        goto CPyL20;
    } else
        goto CPyL19;
CPyL17: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL20;
    } else
        goto CPyL99;
CPyL18: ;
    CPy_Unreachable();
CPyL19: ;
    CPy_RestoreExcInfo(cpy_r_r62);
    CPy_DECREF(cpy_r_r62.f0);
    CPy_DECREF(cpy_r_r62.f1);
    CPy_DECREF(cpy_r_r62.f2);
    goto CPyL22;
CPyL20: ;
    CPy_RestoreExcInfo(cpy_r_r62);
    CPy_DECREF(cpy_r_r62.f0);
    CPy_DECREF(cpy_r_r62.f1);
    CPy_DECREF(cpy_r_r62.f2);
    cpy_r_r92 = CPy_KeepPropagating();
    if (!cpy_r_r92) goto CPyL96;
    CPy_Unreachable();
CPyL22: ;
    cpy_r_r93 = CPyModule_settings;
    cpy_r_r94 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r95 = cpy_r_r93 != cpy_r_r94;
    if (cpy_r_r95) goto CPyL25;
    cpy_r_r96 = CPyStatics[64]; /* 'settings' */
    cpy_r_r97 = PyImport_Import(cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 24, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_settings = cpy_r_r97;
    CPy_INCREF(CPyModule_settings);
    CPy_DECREF(cpy_r_r97);
CPyL25: ;
    cpy_r_r98 = CPyModule_functions;
    cpy_r_r99 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r100 = cpy_r_r98 != cpy_r_r99;
    if (cpy_r_r100) goto CPyL28;
    cpy_r_r101 = CPyStatics[65]; /* 'functions' */
    cpy_r_r102 = PyImport_Import(cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 25, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_functions = cpy_r_r102;
    CPy_INCREF(CPyModule_functions);
    CPy_DECREF(cpy_r_r102);
CPyL28: ;
    cpy_r_r103 = CPyModule_in_game;
    cpy_r_r104 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r105 = cpy_r_r103 != cpy_r_r104;
    if (cpy_r_r105) goto CPyL31;
    cpy_r_r106 = CPyStatics[66]; /* 'in_game' */
    cpy_r_r107 = PyImport_Import(cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 26, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_in_game = cpy_r_r107;
    CPy_INCREF(CPyModule_in_game);
    CPy_DECREF(cpy_r_r107);
CPyL31: ;
    cpy_r_r108 = CPyModule_scheduler;
    cpy_r_r109 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r110 = cpy_r_r108 != cpy_r_r109;
    if (cpy_r_r110) goto CPyL34;
    cpy_r_r111 = CPyStatics[67]; /* 'scheduler' */
    cpy_r_r112 = PyImport_Import(cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 27, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_scheduler = cpy_r_r112;
    CPy_INCREF(CPyModule_scheduler);
    CPy_DECREF(cpy_r_r112);
CPyL34: ;
    cpy_r_r113 = CPyModule_textures;
    cpy_r_r114 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r115 = cpy_r_r113 != cpy_r_r114;
    if (cpy_r_r115) goto CPyL37;
    cpy_r_r116 = CPyStatics[68]; /* 'textures' */
    cpy_r_r117 = PyImport_Import(cpy_r_r116);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 28, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_textures = cpy_r_r117;
    CPy_INCREF(CPyModule_textures);
    CPy_DECREF(cpy_r_r117);
CPyL37: ;
    cpy_r_r118 = CPyModule_parallax;
    cpy_r_r119 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r120 = cpy_r_r118 != cpy_r_r119;
    if (cpy_r_r120) goto CPyL40;
    cpy_r_r121 = CPyStatics[69]; /* 'parallax' */
    cpy_r_r122 = PyImport_Import(cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 29, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_parallax = cpy_r_r122;
    CPy_INCREF(CPyModule_parallax);
    CPy_DECREF(cpy_r_r122);
CPyL40: ;
    cpy_r_r123 = CPyModule_map;
    cpy_r_r124 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r125 = cpy_r_r123 != cpy_r_r124;
    if (cpy_r_r125) goto CPyL43;
    cpy_r_r126 = CPyStatics[70]; /* 'map' */
    cpy_r_r127 = PyImport_Import(cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 30, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_map = cpy_r_r127;
    CPy_INCREF(CPyModule_map);
    CPy_DECREF(cpy_r_r127);
CPyL43: ;
    cpy_r_r128 = CPyModule_gun;
    cpy_r_r129 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r130 = cpy_r_r128 != cpy_r_r129;
    if (cpy_r_r130) goto CPyL46;
    cpy_r_r131 = CPyStatics[71]; /* 'gun' */
    cpy_r_r132 = PyImport_Import(cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 31, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_gun = cpy_r_r132;
    CPy_INCREF(CPyModule_gun);
    CPy_DECREF(cpy_r_r132);
CPyL46: ;
    cpy_r_r133 = CPyModule_player;
    cpy_r_r134 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r135 = cpy_r_r133 != cpy_r_r134;
    if (cpy_r_r135) goto CPyL49;
    cpy_r_r136 = CPyStatics[72]; /* 'player' */
    cpy_r_r137 = PyImport_Import(cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 32, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_player = cpy_r_r137;
    CPy_INCREF(CPyModule_player);
    CPy_DECREF(cpy_r_r137);
CPyL49: ;
    cpy_r_r138 = CPyModule_events;
    cpy_r_r139 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r140 = cpy_r_r138 != cpy_r_r139;
    if (cpy_r_r140) goto CPyL52;
    cpy_r_r141 = CPyStatics[73]; /* 'events' */
    cpy_r_r142 = PyImport_Import(cpy_r_r141);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 33, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_events = cpy_r_r142;
    CPy_INCREF(CPyModule_events);
    CPy_DECREF(cpy_r_r142);
CPyL52: ;
    cpy_r_r143 = CPyModule_hud;
    cpy_r_r144 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r145 = cpy_r_r143 != cpy_r_r144;
    if (cpy_r_r145) goto CPyL55;
    cpy_r_r146 = CPyStatics[74]; /* 'hud' */
    cpy_r_r147 = PyImport_Import(cpy_r_r146);
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 34, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_hud = cpy_r_r147;
    CPy_INCREF(CPyModule_hud);
    CPy_DECREF(cpy_r_r147);
CPyL55: ;
    cpy_r_r148 = CPyModule_ray_caster;
    cpy_r_r149 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r150 = cpy_r_r148 != cpy_r_r149;
    if (cpy_r_r150) goto CPyL58;
    cpy_r_r151 = CPyStatics[75]; /* 'ray_caster' */
    cpy_r_r152 = PyImport_Import(cpy_r_r151);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 35, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_ray_caster = cpy_r_r152;
    CPy_INCREF(CPyModule_ray_caster);
    CPy_DECREF(cpy_r_r152);
CPyL58: ;
    cpy_r_r153 = CPyModule_dialogue;
    cpy_r_r154 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r155 = cpy_r_r153 != cpy_r_r154;
    if (cpy_r_r155) goto CPyL61;
    cpy_r_r156 = CPyStatics[76]; /* 'dialogue' */
    cpy_r_r157 = PyImport_Import(cpy_r_r156);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 36, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_dialogue = cpy_r_r157;
    CPy_INCREF(CPyModule_dialogue);
    CPy_DECREF(cpy_r_r157);
CPyL61: ;
    cpy_r_r158 = CPyModule_sprites;
    cpy_r_r159 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r160 = cpy_r_r158 != cpy_r_r159;
    if (cpy_r_r160) goto CPyL64;
    cpy_r_r161 = CPyStatics[77]; /* 'sprites' */
    cpy_r_r162 = PyImport_Import(cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 37, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_sprites = cpy_r_r162;
    CPy_INCREF(CPyModule_sprites);
    CPy_DECREF(cpy_r_r162);
CPyL64: ;
    cpy_r_r163 = CPyModule_enemy;
    cpy_r_r164 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r165 = cpy_r_r163 != cpy_r_r164;
    if (cpy_r_r165) goto CPyL67;
    cpy_r_r166 = CPyStatics[78]; /* 'enemy' */
    cpy_r_r167 = PyImport_Import(cpy_r_r166);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 38, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_enemy = cpy_r_r167;
    CPy_INCREF(CPyModule_enemy);
    CPy_DECREF(cpy_r_r167);
CPyL67: ;
    cpy_r_r168 = CPyModule_drawer;
    cpy_r_r169 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r170 = cpy_r_r168 != cpy_r_r169;
    if (cpy_r_r170) goto CPyL70;
    cpy_r_r171 = CPyStatics[79]; /* 'drawer' */
    cpy_r_r172 = PyImport_Import(cpy_r_r171);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 39, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_drawer = cpy_r_r172;
    CPy_INCREF(CPyModule_drawer);
    CPy_DECREF(cpy_r_r172);
CPyL70: ;
    cpy_r_r173 = CPyModule_actions;
    cpy_r_r174 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r175 = cpy_r_r173 != cpy_r_r174;
    if (cpy_r_r175) goto CPyL73;
    cpy_r_r176 = CPyStatics[80]; /* 'actions' */
    cpy_r_r177 = PyImport_Import(cpy_r_r176);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 40, CPyStatic_globals);
        goto CPyL96;
    }
    CPyModule_actions = cpy_r_r177;
    CPy_INCREF(CPyModule_actions);
    CPy_DECREF(cpy_r_r177);
CPyL73: ;
    cpy_r_r178 = CPyModule_builtins;
    cpy_r_r179 = CPyStatics[81]; /* 'Exception' */
    cpy_r_r180 = CPyObject_GetAttr(cpy_r_r178, cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 43, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r181 = PyTuple_Pack(1, cpy_r_r180);
    CPy_DECREF(cpy_r_r180);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 43, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r182 = CPyStatics[82]; /* 'main' */
    cpy_r_r183 = (PyObject *)CPyType_NewGame_template;
    cpy_r_r184 = CPyType_FromTemplate(cpy_r_r183, cpy_r_r181, cpy_r_r182);
    CPy_DECREF(cpy_r_r181);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 43, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r185 = CPyStatics[83]; /* '__mypyc_attrs__' */
    cpy_r_r186 = CPyStatics[84]; /* '__dict__' */
    cpy_r_r187 = PyTuple_Pack(1, cpy_r_r186);
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 43, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r188 = PyObject_SetAttr(cpy_r_r184, cpy_r_r185, cpy_r_r187);
    CPy_DECREF(cpy_r_r187);
    cpy_r_r189 = cpy_r_r188 >= 0;
    if (unlikely(!cpy_r_r189)) {
        CPy_AddTraceback("main.py", "<module>", 43, CPyStatic_globals);
        goto CPyL100;
    }
    CPyType_NewGame = (PyTypeObject *)cpy_r_r184;
    CPy_INCREF(CPyType_NewGame);
    cpy_r_r190 = CPyStatic_globals;
    cpy_r_r191 = CPyStatics[85]; /* 'NewGame' */
    cpy_r_r192 = CPyDict_SetItem(cpy_r_r190, cpy_r_r191, cpy_r_r184);
    CPy_DECREF(cpy_r_r184);
    cpy_r_r193 = cpy_r_r192 >= 0;
    if (unlikely(!cpy_r_r193)) {
        CPy_AddTraceback("main.py", "<module>", 43, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r194 = NULL;
    cpy_r_r195 = CPyStatics[82]; /* 'main' */
    cpy_r_r196 = (PyObject *)CPyType_Game_template;
    cpy_r_r197 = CPyType_FromTemplate(cpy_r_r196, cpy_r_r194, cpy_r_r195);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 56, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r198 = CPyDef_Game_trait_vtable_setup();
    if (unlikely(cpy_r_r198 == 2)) {
        CPy_AddTraceback("main.py", "<module>", -1, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r199 = CPyStatics[83]; /* '__mypyc_attrs__' */
    cpy_r_r200 = CPyStatics[86]; /* 'level' */
    cpy_r_r201 = CPyStatics[87]; /* 'screen' */
    cpy_r_r202 = CPyStatics[88]; /* 'clock' */
    cpy_r_r203 = CPyStatics[14]; /* 'time' */
    cpy_r_r204 = CPyStatics[89]; /* 'lest_time' */
    cpy_r_r205 = CPyStatics[90]; /* 'delta_time' */
    cpy_r_r206 = CPyStatics[91]; /* 'run_time' */
    cpy_r_r207 = PyTuple_Pack(7, cpy_r_r200, cpy_r_r201, cpy_r_r202, cpy_r_r203, cpy_r_r204, cpy_r_r205, cpy_r_r206);
    if (unlikely(cpy_r_r207 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 56, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r208 = PyObject_SetAttr(cpy_r_r197, cpy_r_r199, cpy_r_r207);
    CPy_DECREF(cpy_r_r207);
    cpy_r_r209 = cpy_r_r208 >= 0;
    if (unlikely(!cpy_r_r209)) {
        CPy_AddTraceback("main.py", "<module>", 56, CPyStatic_globals);
        goto CPyL101;
    }
    CPyType_Game = (PyTypeObject *)cpy_r_r197;
    CPy_INCREF(CPyType_Game);
    cpy_r_r210 = CPyStatic_globals;
    cpy_r_r211 = CPyStatics[92]; /* 'Game' */
    cpy_r_r212 = CPyDict_SetItem(cpy_r_r210, cpy_r_r211, cpy_r_r197);
    CPy_DECREF(cpy_r_r197);
    cpy_r_r213 = cpy_r_r212 >= 0;
    if (unlikely(!cpy_r_r213)) {
        CPy_AddTraceback("main.py", "<module>", 56, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r214 = CPyStatic_globals;
    cpy_r_r215 = CPyStatics[93]; /* '__name__' */
    cpy_r_r216 = CPyDict_GetItem(cpy_r_r214, cpy_r_r215);
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 110, CPyStatic_globals);
        goto CPyL96;
    }
    if (likely(PyUnicode_Check(cpy_r_r216)))
        cpy_r_r217 = cpy_r_r216;
    else {
        CPy_TypeErrorTraceback("main.py", "<module>", 110, CPyStatic_globals, "str", cpy_r_r216);
        goto CPyL96;
    }
    cpy_r_r218 = CPyStatics[94]; /* '__main__' */
    cpy_r_r219 = PyUnicode_Compare(cpy_r_r217, cpy_r_r218);
    CPy_DECREF(cpy_r_r217);
    cpy_r_r220 = cpy_r_r219 == -1;
    if (!cpy_r_r220) goto CPyL89;
    cpy_r_r221 = PyErr_Occurred();
    cpy_r_r222 = cpy_r_r221 != NULL;
    if (!cpy_r_r222) goto CPyL89;
    cpy_r_r223 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r223)) {
        CPy_AddTraceback("main.py", "<module>", 110, CPyStatic_globals);
        goto CPyL96;
    }
CPyL89: ;
    cpy_r_r224 = cpy_r_r219 == 0;
    if (!cpy_r_r224) goto CPyL95;
    cpy_r_r225 = CPyDef_Game();
    if (unlikely(cpy_r_r225 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 111, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r226 = CPyStatic_globals;
    cpy_r_r227 = CPyStatics[95]; /* 'game' */
    cpy_r_r228 = CPyDict_SetItem(cpy_r_r226, cpy_r_r227, cpy_r_r225);
    CPy_DECREF(cpy_r_r225);
    cpy_r_r229 = cpy_r_r228 >= 0;
    if (unlikely(!cpy_r_r229)) {
        CPy_AddTraceback("main.py", "<module>", 111, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r230 = CPyStatic_globals;
    cpy_r_r231 = CPyStatics[95]; /* 'game' */
    cpy_r_r232 = CPyDict_GetItem(cpy_r_r230, cpy_r_r231);
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 112, CPyStatic_globals);
        goto CPyL96;
    }
    if (likely(Py_TYPE(cpy_r_r232) == CPyType_Game))
        cpy_r_r233 = cpy_r_r232;
    else {
        CPy_TypeErrorTraceback("main.py", "<module>", 112, CPyStatic_globals, "main.Game", cpy_r_r232);
        goto CPyL96;
    }
    cpy_r_r234 = CPyDef_Game___run(cpy_r_r233);
    CPy_DECREF(cpy_r_r233);
    if (unlikely(cpy_r_r234 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 112, CPyStatic_globals);
        goto CPyL96;
    } else
        goto CPyL102;
CPyL95: ;
    return 1;
CPyL96: ;
    cpy_r_r235 = 2;
    return cpy_r_r235;
CPyL97: ;
    CPy_DECREF(cpy_r_r73);
    goto CPyL14;
CPyL98: ;
    CPy_DECREF(cpy_r_r80);
    goto CPyL16;
CPyL99: ;
    CPy_DECREF(cpy_r_r62.f0);
    CPy_DECREF(cpy_r_r62.f1);
    CPy_DECREF(cpy_r_r62.f2);
    goto CPyL18;
CPyL100: ;
    CPy_DecRef(cpy_r_r184);
    goto CPyL96;
CPyL101: ;
    CPy_DecRef(cpy_r_r197);
    goto CPyL96;
CPyL102: ;
    CPy_DECREF(cpy_r_r234);
    goto CPyL95;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_main = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_sys = Py_None;
    CPyModule_os = Py_None;
    CPyModule_time = Py_None;
    CPyModule_types = Py_None;
    CPyModule_dataclasses = Py_None;
    CPyModule_enum = Py_None;
    CPyModule_importlib = Py_None;
    CPyModule_math = Py_None;
    CPyModule_random = Py_None;
    CPyModule_pygame = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_settings = Py_None;
    CPyModule_functions = Py_None;
    CPyModule_in_game = Py_None;
    CPyModule_scheduler = Py_None;
    CPyModule_textures = Py_None;
    CPyModule_parallax = Py_None;
    CPyModule_map = Py_None;
    CPyModule_gun = Py_None;
    CPyModule_player = Py_None;
    CPyModule_events = Py_None;
    CPyModule_hud = Py_None;
    CPyModule_ray_caster = Py_None;
    CPyModule_dialogue = Py_None;
    CPyModule_sprites = Py_None;
    CPyModule_enemy = Py_None;
    CPyModule_drawer = Py_None;
    CPyModule_actions = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[115];
const char * const CPyLit_Str[] = {
    "\v\005event\003get\004type\004QUIT\004quit\004exit\004init\004font\nFULLSCREEN\adisplay\bset_mode",
    "\a\004time\005Clock\tget_ticks\tmain_menu\023assets/gui/load.png\005image\004load",
    "\b\ttransform\005scale\004blit\004flip\vget_surface\tget_flags\021toggle_fullscreen\001.",
    "\b\006levels\rimport_module\004fill\003FPS\004tick\000\030Cellular Odyssey   FPS: \005{:{}}",
    "\n\aget_fps\003.1f\006format\vset_caption\004loop\bbuiltins\003sys\002os\amain.py\b<module>",
    "\t\nModuleType\005types\vdataclasses\004Enum\004enum\timportlib\004math\006random\006pygame",
    "\004\002pg\005numpy\002np\vImportError",
    "\001DErro ao importar pygame, numpy ou numba.\nInstalando depend\303\252ncias...",
    "\005\005print\036pip install pygame numpy numba\006system\bsettings\tfunctions",
    "\t\ain_game\tscheduler\btextures\bparallax\003map\003gun\006player\006events\003hud",
    "\b\nray_caster\bdialogue\asprites\005enemy\006drawer\aactions\tException\004main",
    "\a\017__mypyc_attrs__\b__dict__\aNewGame\005level\006screen\005clock\tlest_time",
    "\006\ndelta_time\brun_time\004Game\b__name__\b__main__\004game",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0031280\000720\0000",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    16, 3, 43, 43, 43, 3, 44, 44, 44, 3, 14, 14, 14, 3, 99, 100, 101, 1,
    47, 3, 42, 42, 42, 3, 49, 49, 49, 2, 104, 105, 1, 50, 1, 30, 3, 53,
    53, 53, 3, 54, 54, 54, 2, 109, 110, 3, 55, 55, 56, 3, 57, 57, 58, 2,
    112, 113
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_main_internal = NULL;
CPyModule *CPyModule_main;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_sys;
CPyModule *CPyModule_os;
CPyModule *CPyModule_time;
CPyModule *CPyModule_types;
CPyModule *CPyModule_dataclasses;
CPyModule *CPyModule_enum;
CPyModule *CPyModule_importlib;
CPyModule *CPyModule_math;
CPyModule *CPyModule_random;
CPyModule *CPyModule_pygame;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_settings;
CPyModule *CPyModule_functions;
CPyModule *CPyModule_in_game;
CPyModule *CPyModule_scheduler;
CPyModule *CPyModule_textures;
CPyModule *CPyModule_parallax;
CPyModule *CPyModule_map;
CPyModule *CPyModule_gun;
CPyModule *CPyModule_player;
CPyModule *CPyModule_events;
CPyModule *CPyModule_hud;
CPyModule *CPyModule_ray_caster;
CPyModule *CPyModule_dialogue;
CPyModule *CPyModule_sprites;
CPyModule *CPyModule_enemy;
CPyModule *CPyModule_drawer;
CPyModule *CPyModule_actions;
PyTypeObject *CPyType_NewGame;
PyTypeObject *CPyType_Game;
PyObject *CPyDef_Game(void);
PyObject *CPyDef_check_events(void);
PyObject *CPyPy_check_events(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game_____init__(PyObject *cpy_r_self);
PyObject *CPyPy_Game_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_Game___new_game(PyObject *cpy_r_self, PyObject *cpy_r_level, PyObject *cpy_r_set_screen, PyObject *cpy_r_supress);
PyObject *CPyPy_Game___new_game(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Game___update(PyObject *cpy_r_self);
PyObject *CPyPy_Game___update(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Game___run(PyObject *cpy_r_self);
PyObject *CPyPy_Game___run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
