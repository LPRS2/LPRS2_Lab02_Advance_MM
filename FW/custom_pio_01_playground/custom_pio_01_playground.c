

#include <stdint.h>
#include "system.h"
#include <stdio.h>


volatile uint32_t* pio = (volatile uint32_t*)SW_AND_LED_PIO_BASE;

int main() {

	printf("sizeof(pio) = %d\n", sizeof(pio));
	printf("sizeof(*pio) = %d\n", sizeof(*pio));
	printf("pio = 0x%08x\n", pio);
	printf("\n");

	pio[0] = 1;
	printf("pio[0] = %u (0x%08x)\n", pio[0], pio[0]);

	pio[0] = 0;
	printf("pio[0] = %u (0x%08x)\n", pio[0], pio[0]);


	for(int i = 0; i < 16; i++){
		pio[i] = pio[i];

		//TODO Print all regs.
		printf("pio[%d] = 0x%08x\n", i, pio[i]);
	}

	return 0;
}
