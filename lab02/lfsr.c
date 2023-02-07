#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
	int bit0, bit2, bit3, bit5, left_bit;

	bit0 = *reg & 1;
	bit2 = (*reg >> 2) & 1;
	bit3 = (*reg >> 3) & 1;
	bit5 = (*reg >> 5) & 1;
	left_bit = bit0 ^ bit2 ^ bit3 ^ bit5;
	*reg >>= 1;
	*reg = (*reg & ~(1 << 15)) | (left_bit << 15);	
}
	
