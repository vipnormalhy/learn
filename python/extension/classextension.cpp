#include <iostream>
#include <cstddef>
#include "Python.h"
#include "structmember.h"

using namespace std;

class CStudent
{
private:
	int id;
	char *name;
public:
	inline int get_id() {return id;};
	inline char *get_name() {return name;};
	void set_id(int sid) {id = sid;};
	void set_name(char *pname);
};

typedef struct {
	PyObject_HEAD
	int id;
	char *name;
} PyStudent;

inline void CStudent::set_name(char *pname)
{
	this->name = pname;
	return;
};

static PyMemberDef pystudent_member[] = {
	{"id", T_UINT, offsetof(PyStudent, id)},
	{"name", T_STRING, offsetof(PyStudent, name)},
	{NULL, 0, 0},
};


static PyMethodDef pystudent_method[] = {
	{NULL, NULL, 0, NULL},
};

static void PyStudent_dealloc(PyStudent *self)
{
	if (self->name)
	{
		delete [] self->name;
	}

	Py_TYPE(self)->tp_free((PyObject *)self);
};

static void PyStudent_init(PyStudent *self, PyObject *args)
{
	char *pName = NULL;

	cout << "enter student init func" << endl;
	if (!PyArg_ParseTuple(args, "s", pName))
	{
		cout << "Parse student args FAILED!!!" << endl;
		return;
	}

	size_t namelen = strlen(pName);
	self->name = new char[namelen + 1];
	strncpy(pName, self->name, namelen);
};

static PyMethodDef student_method[] = {
	{NULL, NULL, 0, NULL},
};

static PyTypeObject studentclass = {
	PyVarObject_HEAD_INIT(&PyType_Type, 0)
	"stucent.student",
	sizeof(PyStudent),
	0,
	(destructor)PyStudent_dealloc,
	0,  // print func
	0,  // getattr func
	0,  // setattr func
	0,  // tp_compare func
	0,  // tp_repr func
	0,  // number methods
	0,  // sequence methods
	0,  // mapping methods
	0,  // hash func
	0,  // call func
	0,  // str func
	0,  // getattro func
	0,  // setattro func
	0,  // buffer func
#ifndef PY_TYPEFLAGS_DEFAULT
	0,
#else
	PY_TYPEFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,  // tp_flags
#endif
	"student test class",  // doc
	0,  // tp_traverse
	0,  // tp clear
	0,  // tp richcompare
	0,  // tp_weeklistoffset
	0,  // tp_iter
	0,  // tp iternext
	student_method,  // tp methods
	pystudent_member,  // tp members
	0,  // tp_getset
	0,  // tp base
	0,  // tp_dict
	0,  // tp_descr_get
	0,  // tp_descri_set
	0,   // tp distoffset
	(initproc)PyStudent_init,
	0,  // tp_allocate
	0,  // tp_new
};

PyMODINIT_FUNC initstudent()
{
	PyObject *module = Py_InitModule("student", pystudent_method);
	cout << "Start init student module!!!" << endl;
	if (!module)
	{
		cout << "Init student module Failed!!!!" << endl;
		return;
	}

	if (PyType_Ready(&studentclass) < 0)
	{
		cout << "cannot add student class tu student" << endl;
		return;
	}

	Py_INCREF((PyObject *)&studentclass);
	int ret = PyModule_AddObject(module, "student", (PyObject *)&studentclass);
	if (ret < 0)
	{
		cout << "Add student class to student module FAILED!!!" << endl;
		return;
	}
	else
	{
		cout << "Add student class SUCC!!!" << endl;
	}

	return;
};
