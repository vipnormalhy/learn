#include <iostream>

class cOther{
public:
	cOther();
	inline int get_value() {return b;};
private:
	int b;
};

cOther::cOther()
{
	b = 1;
	std::cout << "Enter cOther constructor" << b << std::endl;
}


class cBase{
public:
	cBase();
	cBase(int i);
	~cBase();
	inline int get_value() {return a;};
private:
	int a;
};

cBase::cBase()
{
	a = 1;
	std::cout << "Enter base constructor" << std::endl;
}

cBase::cBase(int i)
{
	a = i;
	std::cout << "Enter base constructor2" << std::endl;
}

cBase::~cBase()
{
}

class cInherit:public cBase{
public:
	cInherit();
	cInherit(int i);
	~cInherit();
private:
	cOther cobj;
};

cInherit::cInherit()
{
	std::cout << "Enter inherit constructor" << std::endl;
}

cInherit::cInherit(int i) : cBase(i)
{
	std::cout << "Enter inherit constructor2" << std::endl;
}

cInherit::~cInherit()
{
}

int main()
{
	cInherit a(3);

	std::cout << a.get_value() << std::endl;

	return 1;
}
