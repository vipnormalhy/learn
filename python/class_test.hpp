#include <boost/python.hpp>
#include <iostream>
#include <boost/shared_ptr.hpp>


class Base {
public:
    Base();
    virtual void foo();
    virtual ~Base() {};
};

class Derive: public Base {
public:
    Derive();
    virtual void foo();
    void foo2();
    virtual ~Derive() {};
};


class DeriveWrap: public Derive {
public:
    DeriveWrap(PyObject *pyobj);
    virtual void foo();
    void foo3();
    virtual ~DeriveWrap() {};
private:
    PyObject* self_;
};

typedef boost::shared_ptr<DeriveWrap> DeriveWrapPtr;
