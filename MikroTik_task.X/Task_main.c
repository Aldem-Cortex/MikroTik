/*
 * File:   Task_main.c
 * Author: User
 *
 * Created on June 9, 2020, 11:27 AM
 */
// CONFIG1L
#pragma config WDTEN = ON       // Watchdog Timer Enable bit (WDT enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Reset on stack overflow/underflow enabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG1H
#pragma config CP0 = OFF        // Code Protection bit (Program memory is not code-protected)

// CONFIG2L
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config FOSC2 = ON       // Default/Reset System Clock Select bit (Clock selected by FOSC as system clock is enabled when OSCCON<1:0> = 00)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = ON        // Two-Speed Start-up (Internal/External Oscillator Switchover) Control bit (Two-Speed Start-up enabled)

// CONFIG2H
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = DEFAULT // CCP2 MUX bit (CCP2 is multiplexed with RC1)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include "GPIO.h"
#include "Init.h"
#include "EUSART.h"
#include "Timers.h"
#include "LED_Controller.h"

#define     _XTAL_FREQ      20000000

unsigned int Timer_counter;
unsigned char Timer_multiplier = 10;


void __interrupt(high_priority) RX_TX (void){
    unsigned char temp;
    if(PIR1bits.TXIF){
        // Transmit routine
        EUSART_Transmit(sizeof(Transmit_Buffer), TX_pointer);
        EUSART_Turn_TX_OFF();
        PIR1bits.TXIF = 0;
    }
    
    if(PIR1bits.RCIF){
        EUSART_Receive();
        temp = EUSART_Analize_data();
        if(temp != 0){
            Timer_multiplier = temp;
        }
        PIR1bits.RCIF = 0;
    }
}

void __interrupt(low_priority) Timers (void){
        //Timers interrupt
    /*  At 20Mhz, 16 bit timer and 256 prescaler each interrupt should be about 
     *      every 200us. Let's multiply it by 500 to get a 100 ms step 
     *                      in LED change speed                              */
    if (INTCONbits.TMR0IF){
        Timer_counter++;
        if(Timer_counter >= 500*Timer_multiplier){
            if(Direction){
                Current_LED = LED_Controller_Switch_Right (Current_LED);
            }
            else{
                Current_LED = LED_Controller_Switch_Left (Current_LED);
            }
            Timer_counter = 0;
        }
        INTCONbits.TMR0IF = 0;
    }
        //Button interrupt
    /*  On-press the LED direction is changed   */
    if(INTCONbits.RBIF){
        Direction ^= 1;
        INTCONbits.RBIF = 0;
    }
}

void main(void) {
    
    Init_Startup();
    
    GPIO_Setup();
    
    EUSART_Turn_RX_ON();
       
    Timers_Turn_T0_ON();
    
    LED1 = ON;
    
    while(1){
    CLRWDT();
        
    }
    
    return;
}


