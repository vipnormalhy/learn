#include "Python.h"

int main()
{
	Py_Initialize();
	PyRun_SimpleString("print 'Hello, New World'");
	Py_Finalize();
	return 1;
}
