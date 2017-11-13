#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <iostream>

boost::asio::io_service io_service;
boost::asio::io_service io_service2;
boost::asio::strand strand(io_service);

void print(int count) {
    std::cout << "count " << count << " end" << std::endl;
}

void test_func(int count) {
    // boost::this_thread::sleep(boost::posix_time::seconds(1));
    // boost::asio::deadline_timer timer_(io_service, boost::posix_time::seconds(1));
    // timer_.async_wait(boost::bind(print));
    // timer_.wait();
    print(count);
}

void test_post() {
    int count = 0;
    for (int i = 0; i < 20; i++) {
        // strand.dispatch(boost::bind(test_func, count++));        
        // strand.post(boost::bind(test_func, count++));
        // boost::asio::deadline_timer timer_(io_service, boost::posix_time::seconds(1));
        strand.dispatch(boost::bind(test_func, count++));        
        strand.post(boost::bind(test_func, count++));
    }
}

int main() {
    int count = 0;
    boost::thread t[10];

    for (int i = 0; i < 20; i++) {
        // strand.dispatch(boost::bind(test_func, count++));        
        // strand.post(boost::bind(test_func, count++));
        // boost::asio::deadline_timer timer_(io_service, boost::posix_time::seconds(1));
        io_service.dispatch(boost::bind(test_func, count++));        
        io_service.post(boost::bind(test_func, count++));

        io_service2.dispatch(boost::bind(test_func, count++));
        io_service2.post(boost::bind(test_func, count++));
    }

    for (int i = 0; i < 5; i++) {
        t[2*i] = boost::thread(boost::bind(&boost::asio::io_service::run, &io_service));
        t[2*i+1] = boost::thread(boost::bind(&boost::asio::io_service::run, &io_service2));
        // t[i] = boost::thread(boost::bind(test_func, count++));
    }
    // io_service.post(boost::bind(test_post));
    // strand.dispatch(boost::bind(test_func, 89));
    // io_service.run();
    // for (int i = 0; i < 10; i++) {
    //     t[i].join();
    // }
    std::cout << "all endded" << std::endl;
    return 0;
}
