

#include <stdint.h>
#include "system.h"

void busy_wait(int ms){
	//TODO
}

int main() {
	volatile uint32_t* pio = (volatile uint32_t*)SW_AND_LED_PIO_BASE;

	uint8_t reset;
	uint8_t pause;
	uint8_t speed;
	const uint8_t moduo = 100;

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
