
#include <memory>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

template<typename ...Types>
class Test {
    public:
        int m_member;
        Test() {m_member = 0;}

        void test(Types... types);
};

template<typename T>
void output1(T value) {
    std::cout << value << "++++++++++" << std::endl;
}

template<typename... Types>
void Test<Types ...>::test(Types... types) {
    std::cout << "=================" << std::endl;
    int dummy[] = {0, ((void) output1(types), 0)...};
    // int dummy2[] = {0, ((void ) output(types))...};
    std::cout << "=================" << std::endl;
    std::cout << dummy << std::endl;
}

void output(const int &a) {
    std::cout << "lvalue" << std::endl;
}

void output(int &&a) {
    std::cout << "rvalue " << std::endl;
}

template<typename T>
void receive_reference(T &&a) {
    std::cout << "receive rvalue reference is " << a << std::endl;

    output(std::forward<T>(a));
}

void test_remove() {
    std::vector<int> vec_int({2, 3, 3, 5, 4});
    vec_int.erase(std::remove(vec_int.begin(), vec_int.end(), 3), vec_int.end());

    for (auto iter = vec_int.cbegin(); iter != vec_int.cend(); iter++) {
        std::cout << *iter << std::endl;
    }
}

void test_multiple_vector() {
}

template<typename T>
class Text {
    public:
        template<typename U>
        void foo() {}
};

template<typename T>
class Image {
    public:
        void init();
};

template<typename T>
void Image<T>::init() {
    Text<int> int_text;

    int_text.template foo<T>();
}

void test_template() {
    Image<int> image_int;
    image_int.init();
}

void test_allocator() {
    std::vector<int, std::allocator<int>> a;
    a.push_back(3);
    std::cout << a[0] << std::endl;
}

int main() {
    typedef std::allocator<int> INT_ALLOCATOR;

    INT_ALLOCATOR a1;
    int *pointer = std::allocator_traits<INT_ALLOCATOR>::allocate(a1, 10);
    *pointer = 3;
    *(pointer + 1) = 5;
    std::cout << *pointer << *(pointer + 1) << *(pointer + 2) << std::endl;

    int *point_null;
    std::cout << typeid(point_null).name() << std::endl;
    std::cout << typeid(point_null).hash_code() << std::endl;

    Test<int, int, double> testobject;
    testobject.test(1, 1, 3.0);
    // Test<int> testobject;
    // std::cout << testobject.m_member << std::endl;
    // testobject.test(1);

    // Test testobjext1;
    // std::cout << testobjext1.m_member << std::endl;

    // Test<int, float> testobject3;
    // testobject3.test(1, 2.0);

    receive_reference(45);
    int i = 45;
    receive_reference(i);

    // int c = 3, 4;
    // std::cout << c << std::endl;
    test_remove();
    test_allocator();

    test_template();
    return 0;
}