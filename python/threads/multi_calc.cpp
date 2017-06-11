#include <boost/python.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <math.h>
#include <iostream>

#include "../../get_time.hpp"

PyObject *pymodule = NULL;
PyObject *pArgs = NULL;
PyObject *pFunc = NULL;


long double calc_total(int num) {
    if (1 == num) {
        return num;
    } else {
        return calc_total(num - 1) * static_cast<long double>(num);
    }
}

void threads_calc(int calc_num, int repeat_times) {
    for (int i = 0; i < repeat_times; i++ ) {
        calc_total(calc_num);
    }
}

void threads_calc_python(int calc_num, int repeat_times) {
#ifdef MULTI_THREADS
    PyGILState_STATE gsstate = PyGILState_Ensure();
#endif
    for (int i = 0; i < repeat_times; i++) {
        boost::python::call<long double>(pFunc, calc_num);
        // std::cout << "calc result is " << std::fixed << std::setprecision(0) << result << std::endl;
    }
#ifdef MULTI_THREADS
    PyGILState_Release(gsstate);
#endif
}


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << argv[0] << " need 2 arguments at least" << std::endl;
        exit(-1);
    }

    Py_SetProgramName(argv[0]);

    Py_Initialize();
#ifdef MULTI_THREADS
    PyEval_InitThreads();
#endif

#ifdef MULTI_THREADS
    int threads_num = boost::lexical_cast<int>(argv[1]);
#else
    int threads_num = 1;
#endif
    int calc_num = boost::lexical_cast<int>(argv[2]);
    int repeat = boost::lexical_cast<int>(argv[3]);

    boost::thread_group group;

    PyRun_SimpleString("import sys;sys.path.append('./')");
    // std::cout << "path " << Py_GetPath() << std::endl;
    // std::cout << "pythonhome " << Py_GetPythonHome() << std::endl;
    // std::cout << "asdfasdfasdfnnnnn" << std::endl;

    // find the py module
    PyObject *pname = PyString_FromString("calc");
    PyObject *pymodule = PyImport_Import(pname);
    if (NULL == pymodule) {
        std::cout << "Cannto import calc" << std::endl;
        exit(-2);
    }
    Py_DECREF(pname);
    pFunc = PyObject_GetAttrString(pymodule, "calc_total");

    pArgs = PyTuple_New(1);
    PyObject *pvalue = PyInt_FromLong(calc_num);
    PyTuple_SetItem(pArgs, 0, pvalue);

    std::cout << "pyint from long refcnt " << pvalue->ob_refcnt << std::endl;

    double start_time = get_current_time();
    int thread_run_times = ceil(static_cast<float>(repeat) / static_cast<float>(threads_num));

    std::cout << "Evey thread will deal " << thread_run_times << " times calc." << std::endl;

    for (int thread_index = 0; thread_index < threads_num; thread_index++) {
        group.create_thread(boost::bind(&threads_calc_python, calc_num, thread_run_times));
    }
#ifdef MULTI_THREADS
    PyEval_ReleaseLock();
#endif
    group.join_all();
    // threads_calc_python(calc_num, thread_run_times);
    double end_time = get_current_time();

    output_interval(start_time, end_time);
    // Py_Finalize();
    return 1;
}
