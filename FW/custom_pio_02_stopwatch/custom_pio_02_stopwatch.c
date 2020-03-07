

#include <stdint.h>
#include "system.h"

void busy_wait(int ms){
	//TODO
}

int main() {

	volatile uint32_t* sw = (volatile uint32_t*)SW_PIO_BASE;
	volatile uint32_t* led = (volatile uint32_t*)LED_PIO_BASE;

	uint8_t pause;
	uint8_t speed;

	uint8_t cnt;


	while(1) { // Infinite loop.
		// Read inputs.
		//TODO

		// Calculate state.
		//TODO

		// Write outputs.
		//TODO
	}

	return 0;
}
