#include <stdio.h>
 
// Simulated device status
int deviceStatus = 0;
 
// Function to handle device requests
void handleDeviceRequest(int request) {
	switch (request) {
    	case 1:
        	// Perform action for request 1
            printf("Handling Request 1: Turning ON the device.\n");
    	    deviceStatus = 1;
        	break;
    	case 2:
        	// Perform action for request 2
            printf("Handling Request 2: Turning OFF the device.\n");
            deviceStatus = 0;
        	break;
    	default:
            printf("Unknown request. Ignoring.\n");
	}
}
 
int main() {
	int userRequest;
 
	while (1) {
    	// Simulating user input or external requests
        printf("Enter device request (1: Turn ON, 2: Turn OFF, 0: Exit): ");
    	scanf("%d", &userRequest);
 
    	if (userRequest == 0) {
            printf("Exiting program.\n");
        	break;
    	}
 
    	// Handle the device request
        handleDeviceRequest(userRequest);
 
    	// Display the current device status
	    printf("Device Status: %s\n", (deviceStatus == 1) ? "ON" : "OFF");
	}
 
	return 0;
}

