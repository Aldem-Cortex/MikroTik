#ifndef LED_CONTROLLER_H
#define	LED_CONTROLLER_H

#include <stdio.h>
#include "EUSART.h"
#include <proc/pic18f45j10.h>

#define     LED1            PORTAbits.RA0
#define     LED2            PORTAbits.RA1
#define     LED3            PORTAbits.RA2
#define     LED4            PORTAbits.RA3
#define     LED5            PORTAbits.RA5
#define     LED6            PORTBbits.RB0
#define     LED7            PORTBbits.RB1
#define     LED8            PORTBbits.RB2
#define     LED9            PORTBbits.RB3
#define     LED10           PORTBbits.RB4
#define     BUTTON          PORTBbits.RB5
#define     RIGHT           1
#define     LEFT            0

bool Direction = RIGHT;
char Current_LED = 1;

char LED_Controller_Switch_Right (char current_led);
char LED_Controller_Switch_Left (char current_led);

#endif	/* LED_CONTROLLER_H */

