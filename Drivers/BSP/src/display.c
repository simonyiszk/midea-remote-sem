/*
 * display.c
 *
 *  Created on: Mar 14, 2025
 *      Author: pali
 */

#include "main.h"
#include "spi.h"
#include "display.h"

SPI_HandleTypeDef* DISPLAY_SPI = &hspi1;

static const uint8_t pattern[17] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F, // 9
	0x77, // A
	0x7C, // b
	0x39, // C
	0x5E, // d
	0x79, // E
	0x71, // F
	0x00  // empty
};

void DisplayDecimal(uint8_t value){
	uint8_t bcd[2] = {0, value};
	while(bcd[1]>=10){
		bcd[1]-=10;
		bcd[0]++;
		if(bcd[0]>=10){
			bcd[0]-=10;
		}
	}
	bcd[1] = 0xFF - pattern[bcd[1]];
	bcd[0] = 0xFF - pattern[bcd[0]];
	HAL_SPI_Transmit(DISPLAY_SPI, bcd, 1, HAL_MAX_DELAY);
}

void DisplayHex(uint8_t value){
	uint8_t data[2] = {
		0xFF - pattern[(value>>4) & 0x0F],
		0xFF - pattern[value & 0x0F]
	};
	HAL_SPI_Transmit(DISPLAY_SPI, data, 1, HAL_MAX_DELAY);
}

void DisplayOff(void){
	uint8_t data[2] = {0, 0};
	HAL_SPI_Transmit(DISPLAY_SPI, data, 1, HAL_MAX_DELAY);
}
