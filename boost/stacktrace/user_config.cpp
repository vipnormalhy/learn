// Copyright Antony Polukhin, 2016-2017.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// #define BOOST_USER_CONFIG </home/normalhy/learn/boost/stacktrace/user_config.hpp>

#include <iostream>     // std::err
#include <exception>    // std::set_terminate, std::abort
#include <boost/array.hpp>
#include <boost/stacktrace.hpp>
#include <boost/filesystem.hpp>

BOOST_NOINLINE void foo(int i);
BOOST_NOINLINE void bar(int i);
 
BOOST_NOINLINE void bar(int i) {
    boost::array<int, 5> a = {{-1, -231, -123, -23, -32}};
    if (i >= 0) {
        foo(a[i]);
    } else {
        std::cerr << "Terminate called:\n" << boost::stacktrace::stacktrace() << '\n';
        exit(0);
				boost::stacktrace::safe_dump_to("./dump_info");
    }
}

BOOST_NOINLINE void foo(int i) {
    bar(--i);
}

int main() {
    foo(5);

		if (boost::filesystem::exists("./dump_info")) {
			std::ifstream ifs("./dump_info");
			boost::stacktrace::stacktrace st = boost::stacktrace::stacktrace::from_dump(ifs);
			std::cout << st << std::endl;
		}
    return 2;
}




