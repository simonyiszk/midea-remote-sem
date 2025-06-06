/*
 * display.h
 *
 *  Created on: Mar 14, 2025
 *      Author: pali
 */

#ifndef BSP_INC_DISPLAY_H_
#define BSP_INC_DISPLAY_H_

#include <stdint.h>

void DisplayDecimal(uint8_t value);
void DisplayHex(uint8_t value);
void DisplayOff(void);

#endif /* BSP_INC_DISPLAY_H_ */
