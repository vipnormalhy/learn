#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/chrono.hpp>


boost::asio::io_service io1;
boost::asio::io_service io2;
boost::asio::strand strand(io1);

boost::shared_ptr<boost::thread> t;

void test_func2(int count) {
    std::cout << "start to execute at " << boost::chrono::time_point_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::now()) << std::endl;
    std::cout << "there is second count " << count << std::endl;
}

int test_func(int count) {
    if (count <= 15) {
        boost::asio::deadline_timer timer(io2, boost::posix_time::milliseconds(50));
        timer.async_wait(strand.wrap(boost::bind(test_func2, count)));
        std::cout << "async wait starts at " << boost::chrono::time_point_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::now()) << std::endl;

        if (!t) {
            t.reset(new boost::thread(boost::bind(&boost::asio::io_service::run, &io2)));
        } else if (io2.stopped()) {
            io2.reset();
            t.reset(new boost::thread(boost::bind(&boost::asio::io_service::run, &io2)));
        }
    }
    // boost::this_thread::sleep(boost::posix_time::seconds(8));
    std::cout << "there is a count " << count << std::endl;

    return 0;
}


int main() {
    int count = 0;

    for (int i = 0; i < 20; i++) {
        strand.post(boost::bind(test_func, count++));
    }

    boost::shared_ptr<boost::thread> t1(new boost::thread(boost::bind(&boost::asio::io_service::run, &io1)));
    boost::shared_ptr<boost::thread> t2(new boost::thread(boost::bind(&boost::asio::io_service::run, &io1)));
    boost::shared_ptr<boost::thread> t3(new boost::thread(boost::bind(&boost::asio::io_service::run, &io1)));    

    t1->join();
    t2->join();
    t3->join();
    return 0;
}
