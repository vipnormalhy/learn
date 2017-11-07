#include <iostream>
#include <boost/coroutine2/all.hpp>
#include <boost/tuple/tuple.hpp>

int test() {
    boost::coroutines2::coroutine<int>::pull_type coro(
        [] (boost::coroutines2::coroutine<int>::push_type &sink) {
            std::cout << "enter coro" << std::endl;
            // sink(boost::make_tuple(3, 4));
            sink(3);
            std::cout << "leave coro" << std::endl;
            sink(4);
            sink(5);
        }
        );
    int result = coro.get();
    coro();
    std::cout << "coro's last result?" << coro.get() << std::endl;
    return result;
}



int main() {
    boost::coroutines2::coroutine<int>::pull_type coro(
        [] (boost::coroutines2::coroutine<int>::push_type &sink) {
            std::cout << "enter coro" << std::endl;
            // sink(boost::make_tuple(3, 4));
            sink(3);
            std::cout << "leave coro" << std::endl;
            sink(4);
            sink(5);
        }
        );    
    std::cout << "enter main" << std::endl;
    int a;
    a = test();
    std::cout << "a is " << a << std::endl;
    std::cout << "leave main" << std::endl;
    a = test();
    std::cout << "a is " << a << std::endl;
    return 0;
}

