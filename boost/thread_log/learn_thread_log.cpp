#include <iostream>
#include <boost/bind.hpp>
#include <vector>
#include "learn_thread_log.hpp"

void TestThreadInterrupt::timer_print() {
	int index = 0;
	while (true) {
		index += 1;
		boost::this_thread::sleep_for(boost::chrono::nanoseconds(1000000000));
		std::cout << "Hi Check thread" << boost::this_thread::get_id() << std::endl;

		if (index > 3) {
			if (!m_t) {
				continue;
			}

			m_t->interrupt();
		}
	}
}

int main(int, char *[]) {
	std::vector<boost::shared_ptr<boost::thread> > thread_pool;
	std::vector<boost::shared_ptr<TestThreadInterrupt> > test_pool;

	for (int i = 0; i < 100; i++) {
		boost::shared_ptr<TestThreadInterrupt> test = boost::make_shared<TestThreadInterrupt>();

		auto func = boost::bind(&TestThreadInterrupt::timer_print, test);
		test->m_t = boost::make_shared<boost::thread>(func);
		thread_pool.push_back(test->m_t);
	}

	for (int i = 0; i < (int)thread_pool.size(); i++) {
		thread_pool[i]->join();
	}

	std::cout << "thread end." << std::endl;
}
