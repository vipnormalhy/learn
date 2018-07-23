#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

int signal_handler(int sig_num) {
	std::cout << "Receive signal " << sig_num << std::endl;
}

void signal_action_handler(int sig_num, siginfo_t *info, void *data) {
	std::cout << "Receive signum " << sig_num << std::endl;
	printf("info address is %p, data address is %p", info, data);
}

int main() {
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_action_handler;
	sa.sa_handler = NULL;
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
