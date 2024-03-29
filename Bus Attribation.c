#include <stdio.h>
#define NUM_DEVICES 3
int busArbitrationRoundRobin(int currentDevice) {
	return (currentDevice + 1) % NUM_DEVICES;
}
int main() {
	int currentDevice = 0; 
	printf("Bus Arbitration Simulation\n");
	for (int cycle = 1; cycle <= 10; cycle++) {
        printf("Cycle %d: Device %d accesses the bus\n", cycle, currentDevice);
 		currentDevice = busArbitrationRoundRobin(currentDevice);
        printf("\n");
	}
 
    return 0;
}

