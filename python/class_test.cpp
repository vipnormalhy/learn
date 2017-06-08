#include "class_test.hpp"

namespace bp = boost::python;


Base::Base() {
    std::cout << "Come to Base's construct function" << std::endl;
}

void Base::foo() {
    std::cout << "Come to Derive foo function" << std::endl;
}


Derive::Derive() {
    std::cout << "Come to Derive's construct function" << std::endl;
}


void Derive::foo() {
    std::cout << "Come to Derive's foo function" << std::endl;
}

DeriveWrap::DeriveWrap(PyObject *pyobj) {
    std::cout << "Come to DeriveWrap's construct function" << std::endl;
    self_ = pyobj;
}


void DeriveWrap::foo() {
    std::cout << "Come to DeriveWrap's foo function" << std::endl;
}


BOOST_PYTHON_MODULE(derive) {
    // bp::class_<Derive, DeriveWrapPtr, boost::noncopyable>("Derive");
    bp::class_<Derive>("Derive");
};
