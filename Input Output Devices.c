#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void device1_interrupt_handler(int signal) {
    printf("Device 1 Interrupt Handler\n");
}
void device2_interrupt_handler(int signal) {
    printf("Device 2 Interrupt Handler\n");
}
void enable_interrupt(int device) {
	switch(device) {
    	case 1:
            signal(SIGINT, device1_interrupt_handler);
        	break;
    	case 2:
            signal(SIGINT, device2_interrupt_handler);
        	break;
    	default:
            printf("Invalid device\n");
        	break;
	}
}
void disable_interrupt(int device) {
	signal(SIGINT, SIG_DFL);
}

int main() {
    enable_interrupt(1);
    enable_interrupt(2);
    printf("Interrupts enabled for both devices. Press Ctrl+C to trigger interrupts.\n");
	while (1) {
	}
    disable_interrupt(1);
    disable_interrupt(2);
	return 0;
}
