#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void handleInterrupt(int signum) {
    printf("Received interrupt signal (Ctrl+C) - exiting\n");
	_exit(0);
}
int main() {
	if (signal(SIGINT, handleInterrupt) == SIG_ERR) {
        perror("Error setting up signal handler");
    	return 1;
	}
	while (1) {
        printf("Program is running...\n");
    	sleep(1);
	}
    return 0;
}

