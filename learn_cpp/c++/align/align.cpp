#include <iostream>

int main() {
    typedef struct _AlignTestStruct {
        char a;
        int b;
        short c;
    } AlignTestStruct;

    AlignTestStruct test;
    std::cout << "a position " << reinterpret_cast<long>(&test.a) - reinterpret_cast<long>(&test) << std::endl;
    std::cout << "b position " << reinterpret_cast<long>(&test.b) - reinterpret_cast<long>(&test) << std::endl;
    std::cout << "c position " << reinterpret_cast<long>(&test.c) - reinterpret_cast<long>(&test) << std::endl;
    std::cout << "sizeof " << sizeof(AlignTestStruct) << std::endl;

    typedef struct _AlignTestStruct2 {
        int a;
        char b;
        short c;
        char d;
//        char e;
    } AlignTestStruct2;

    AlignTestStruct2 test2;
    std::cout << "a position " << reinterpret_cast<long>(&test2.a) - reinterpret_cast<long>(&test2) << std::endl;
    std::cout << "b position " << reinterpret_cast<long>(&test2.b) - reinterpret_cast<long>(&test2) << std::endl;
    std::cout << "c position " << reinterpret_cast<long>(&test2.c) - reinterpret_cast<long>(&test2) << std::endl;
    std::cout << "d position " << reinterpret_cast<long>(&test2.d) - reinterpret_cast<long>(&test2) << std::endl;
//    std::cout << "e position " << reinterpret_cast<long>(&test2.e) - reinterpret_cast<long>(&test2) << std::endl;
    std::cout << "sizeof " << sizeof(AlignTestStruct2) << std::endl;

    typedef struct _AlignTestStruct3 {
        char a : 1;
        short b : 5;
        short c : 2;
    } AlignTestStruct3;

    AlignTestStruct3 test3;
    std::cout << sizeof(test3) << std::endl;
    return 0;
}
