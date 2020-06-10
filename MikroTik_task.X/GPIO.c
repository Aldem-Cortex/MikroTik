#include "GPIO.h"

/*  GPIO setting up */

static void Set_PORTB_as_input(char port){
    
    TRISB |= 1 << port;
}

static void Set_PORTA_as_output(char port){
    TRISA &= ~(1 << port);
}

static void Set_PORTB_as_output(char port){
    TRISB &= ~(1 << port);
}


void GPIO_Setup(void){
    Set_PORTA_as_output(0);
    Set_PORTA_as_output(1);
    Set_PORTA_as_output(2);
    Set_PORTA_as_output(3);
    Set_PORTA_as_output(5);
    Set_PORTB_as_output(0);
    Set_PORTB_as_output(1);
    Set_PORTB_as_output(2);
    Set_PORTB_as_output(3);
    Set_PORTB_as_output(4);
    Set_PORTB_as_input(5);
    Set_PORTB_as_output(6);
    Set_PORTB_as_output(7);
}

