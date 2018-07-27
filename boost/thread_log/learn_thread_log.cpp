#include <iostream>
#include <boost/bind.hpp>
#include "learn_thread_log.hpp"

void TestThreadInterrupt::timer_print() {
	int index = 0;
	while (true) {
		index += 1;
		boost::this_thread::sleep_for(boost::chrono::nanoseconds(1000000000));
		std::cout << "Hi Check thread" << std::endl;

		if (index > 3) {
			if (!m_t) {
				continue;
			}

			m_t->interrupt();
		}
	}
}

int main(int, char *[]) {
	TestThreadInterrupt test;

	auto func = boost::bind(&TestThreadInterrupt::timer_print, &test);
	test.m_t = boost::make_shared<boost::thread>(func);
	test.m_t->join();
	std::cout << "thread end." << std::endl;
}
