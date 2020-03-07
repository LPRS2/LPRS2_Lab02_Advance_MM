

#include <stdint.h>
#include "system.h"
#include <stdio.h>


int main() {

	register volatile uint32_t* sw = (volatile uint32_t*)SW_PIO_BASE;
	register volatile uint32_t* led = (volatile uint32_t*)LED_PIO_BASE;


	printf("sizeof(sw) = %d\n", sizeof(sw));
	printf("sizeof(*sw) = %d\n", sizeof(*sw));
	printf("sw = 0x%08x\n", sw);

	printf("*sw = %u (0x%08x)\n", *sw, *sw);

	*sw = 0; // Read-only mem. mapped reg discard writing to it.
	printf("*sw = %u (0x%08x)\n", *sw, *sw);

	*led = *sw;
	printf("*led = %u (0x%08x)\n", *led, *led);
	*led = ~ *sw;
	printf("*led = %u (0x%08x)\n", *led, *led);

	return 0;
}
