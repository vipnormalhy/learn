#include <iostream>
#include <stdio.h>
#include <csignal>
#include <sys/types.h>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>


void signal_action_handler(int sig_num, siginfo_t *info, void *data) {
	std::cout << "Receive signum " << sig_num << std::endl;
	printf("info address is %p, data address is %p", info, data);
}

int main() {
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO | SA_RESETHAND;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_action_handler;
	sa.sa_restorer = NULL;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGILL, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);

	while (true) {
		std::cout << "1 seconds passed!" << std::endl;
		boost::this_thread::sleep_for(boost::chrono::nanoseconds(1000000000));
	}
	return 0;
}
