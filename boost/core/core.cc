#include <iostream>
#include <vector>
#include <boost/core/demangle.hpp>
#include <boost/core/explicit_operator_bool.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/core/is_same.hpp>
#include <boost/core/lightweight_test.hpp>

template <class X>
struct test{};

template <typename T>
class test2{
private:
    T *a;
public:
    test2() { a = new(int);}
    BOOST_EXPLICIT_OPERATOR_BOOL();
    bool operator!() const {
        return !a;
    }
};

int main() {
    char *buff = NULL;
    boost::ignore_unused(buff);
    const char *name = typeid(test<int>).name();
    std::cout << boost::core::demangle(name) << std::endl;
    std::cout << typeid(test<long>).name() << std::endl;
    std::cout << typeid(test<std::vector<int> >).name() << std::endl;

    test2<int> c;
    if (c) {
        std::cout << "okkkkk" << std::endl;
    }

    BOOST_TEST(buff != NULL);

    // if (BOOST_TEST(boost::core::is_same<int, int>)) {
        
    // }
    return 1;
}
