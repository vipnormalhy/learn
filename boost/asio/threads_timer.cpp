#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>

class Printer {
public:
    Printer(boost::asio::io_service &io);
    ~Printer();
    inline void StartWait();
    void Print1();
    void Print2();
private:
    boost::asio::strand m_strand_;
    boost::asio::deadline_timer m_timer1_;
    boost::asio::deadline_timer m_timer2_;
    int m_count_;
};

void Printer::StartWait() {
    m_timer1_.async_wait(m_strand_.wrap(boost::bind(&Printer::Print1, this)));
    m_timer2_.async_wait(m_strand_.wrap(boost::bind(&Printer::Print2, this)));
}

void Printer::Print2() {
    std::cout << "count " << m_count_ << std::endl;
    if (m_count_ <= 5) {
        m_timer2_.expires_at(m_timer2_.expires_at() + boost::posix_time::seconds(1));
        m_timer2_.async_wait(m_strand_.wrap(boost::bind(&Printer::Print2, this)));
    }
    m_count_++;
}

void Printer::Print1() {
    std::cout << "count " << m_count_ << std::endl;
    if (m_count_ <= 5) {
        m_timer1_.expires_at(m_timer1_.expires_at() + boost::posix_time::seconds(1));
        m_timer1_.async_wait(m_strand_.wrap(boost::bind(&Printer::Print1, this)));
    }
    m_count_++;
}

Printer::Printer(boost::asio::io_service &io) :
    m_strand_(io),
    m_timer1_(io, boost::posix_time::seconds(1)),
    m_timer2_(io, boost::posix_time::seconds(2)),
    m_count_(0) {
}

Printer::~Printer() {
    std::cout << "count at last " << m_count_ << std::endl;
}


int main() {
    boost::asio::io_service io;
    Printer p(io);
    p.StartWait();
    boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
    io.run();
    t.join();
    return 1;
}
