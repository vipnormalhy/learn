#include <iostream>

class monster {
public :
     // two type of default constructor
     // Cannot use both at a same class
     monster();
     //monster(int iHp = 0, int iMp = 0){this->iHp=iHp; this->iMp=iMp;} // default constructor

     monster(const monster &); // copy constructor
     ~monster();
     const monster & operator=(const monster &);
     monster(int);
     
     void set_hp(int hp);
     void set_mp(int mp);
     
private:
     int iHp;
     int iMp;
};

void monster::set_hp(int hp) {
     iHp = hp;
}

void monster::set_mp(int mp) {
     iMp = mp;
}

monster::monster() {
     std::cout << "Enter default constructor" << std::endl;
     
     iHp = 0;
     iMp = 0;
}

monster::monster(const monster & from) {
     std::cout << "Enter copy constructor" << std::endl;

     iHp = from.iHp;
     iMp = from.iMp;
}

monster::~monster() {
     std::cout << "Enter destructor" << std::endl;
     
}

const monster & monster::operator=(const monster &from) {
     std::cout << "Enter operator =" << std::endl;

     iHp = from.iHp;
     iMp = from.iMp;

     return *this;
}

monster::monster(int default_hp) {
     std::cout << "Enter one int param function" << std::endl;

     iHp = default_hp;
}

int main()
{
     monster mA;

     mA.set_hp(30);
     mA.set_mp(20);

     monster mB(mA); // direct initialize, do not use operate=
     monster mC = mB; // copy initialize, do not use operate=
     monster mE = 4; // initial temp object, and use copy constructor copy to mE
     monster mD; // direct initialize, use default constructor

     mD = mB; // use operate =
     
     return 0;
}

// I think the output shuld be:
// Default constructor
// Copy constructor
// Copy constructor
// One int param function constructor
// Copy constructor     // wrong, compiler will find the correct constructor function
// Default constructor 
// Operator = function
