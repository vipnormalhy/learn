#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/shared_ptr.hpp>

class TestThreadInterrupt {
	public:
		boost::shared_ptr<boost::thread> m_t;
		void timer_print();
};

