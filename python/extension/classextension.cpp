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

PyStudent *pStudent;

static void PyStudent_init(PyStudent *self, PyObject *args)
{
	const char *pName = NULL;

	cout << "enter student init func" << endl;
	if (!PyArg_ParseTuple(args, "s", &pName))
	{
		cout << "Parse student args FAILED!!!" << endl;
		return;
	}
	else
	{
		cout << "Parse student args succ" << endl;
	}

	size_t namelen = strlen(pName);
	cout << "name len is " << namelen << endl;
	self->name = new char[namelen + 1];
	strncpy(self->name, pName, namelen + 1);
	pStudent = self;
};

static PyObject *student_getid(PyStudent *self)
{
	cout << "Student's id is " << self->id << endl;
	return Py_BuildValue("i", self->id);
}

static PyMethodDef student_method[] = {
	{"getid", (PyCFunction)student_getid, METH_O, "get student's id"},
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
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
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
	(newfunc)PyType_GenericNew,  // tp_new
};

PyMODINIT_FUNC initstudent()
{
	PyObject *module = Py_InitModule("student", pystudent_method);
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

// for test
int main()
{
	Py_Initialize();

	initstudent();
	
	PyRun_SimpleString("import student");
	PyRun_SimpleString("print student.student");
	PyRun_SimpleString("type(student.student)");
	PyRun_SimpleString("a = student.student(\"aa\")");
	PyRun_SimpleString("a.id = 3");
	PyRun_SimpleString("print a.id");
	PyRun_SimpleString("print a.name");
	cout << "In c layer, self id is " << pStudent->id << " name is " << pStudent->name << endl;
	Py_Finalize();
	return 0;
}
