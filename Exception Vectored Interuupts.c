#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
 
// Define a signal handler function for the segmentation fault
void handle_segfault(int signum) {
    printf("Segmentation Fault (Signal %d) - Exiting program\n", signum);
	exit(signum);
}
 
int main() {
	// Install the signal handler for SIGSEGV (Segmentation Fault)
	if (signal(SIGSEGV, handle_segfault) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
	}
 
	// Access an invalid memory address to trigger a segmentation fault
	int *ptr = NULL;
	*ptr = 10;  // This will cause a segmentation fault
 
	// The program will not reach this point if a segmentation fault occurs
	printf("This line will not be executed due to the segmentation fault.\n");
 
    return 0;
}

