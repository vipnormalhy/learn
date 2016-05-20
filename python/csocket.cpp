#include <sys/socket.h>
#include <stdio.h>
#include "Python.h"

static PyObject* csocket_socket(PyObject *self, PyObject *args)
{
	int sockfd;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("apply socket fd failed!!\n");
	}
	return Py_BuildValue("i", sockfd);
};


static PyMethodDef csocket_methods[] = {
	{"socket", PyCFunction(csocket_socket), METH_O, "Create a socekt"},
	{NULL, NULL, 0, NULL},
};


PyMODINIT_FUNC initcsocket(void)
{
	(void)Py_InitModule("csocket", csocket_methods);
	return;
}
