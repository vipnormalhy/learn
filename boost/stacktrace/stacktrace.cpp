#include <iostream>
#include <boost/atomic.hpp>
#include <boost/thread.hpp>
//#include <boost/chrono/io/timezone.hpp>
#include <boost/chrono/time_point.hpp>
#include <boost/chrono/io/time_point_io.hpp>
//#include <boost/chrono.hpp>
#include <boost/any.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
//#include <boost/chrono/chrono_io.hpp>


boost::atomic<long> a(0);

void accumulate(int index) {
    if (index == 99) {
        std::cout << "init 100 enddddd" << std::endl;
    }
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
    a += 1;
}


int main() {
    boost::array<boost::thread, 100> vthread;
    int thread_num = 100;
    for (int i = 0; i < thread_num; i++) {
        vthread[i] = boost::thread(boost::bind(&accumulate, i));
    }

    for (int i = 0; i < thread_num; i++) {
        vthread[i].join();
    }

    std::cout << a << std::endl;
    std::cout << boost::chrono::system_clock::now() << std::endl;
    std::cout << boost::chrono::time_fmt(boost::chrono::timezone::local) << boost::chrono::system_clock::now() << std::endl;
    std::cout << boost::chrono::steady_clock::now() << std::endl;
    std::cout << boost::chrono::process_cpu_clock::now() << std::endl;
    std::cout << boost::chrono::thread_clock::now() << std::endl;
    return 1;
}
