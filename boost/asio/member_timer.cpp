#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


class Print {
public:
    Print(boost::asio::io_service &io) :
        timer_(io, boost::posix_time::seconds(1)),
        count_(0) {
    }
    ~Print() {
        std::cout << "Finally, count is " << count_ << std::endl;
    }
    inline void StartWait();
    void print();
private:
    boost::asio::deadline_timer timer_;
    int count_;    
};

void Print::StartWait() {
    timer_.async_wait(boost::bind(&Print::print, this));
}

void Print::print() {
    if (count_ < 5) {
        timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
        timer_.async_wait(boost::bind(&Print::print, this));
    }
    std::cout << "wait count " << count_ << std::endl;    
    count_++;
}
                      


int main(int argc, char **argv) {
    boost::asio::io_service io;
    Print p(io);
    p.StartWait();
    io.run();

    return 0;
}
