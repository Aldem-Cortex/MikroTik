#include "LED_Controller.h"

char LED_Controller_Switch_Right (char current_led){
    switch (current_led){
        case(1): 
            LED1 = 0; LED2 = 1; return current_led+1;
            strcpy(TX_pointer,"LED2 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(2): 
            LED2 = 0; LED3 = 1; return current_led+1;
            strcpy(TX_pointer,"LED3 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(3): 
            LED3 = 0; LED4 = 1; return current_led+1;
            strcpy(TX_pointer,"LED4 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(4): 
            LED4 = 0; LED5 = 1; return current_led+1;
            strcpy(TX_pointer,"LED5 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(5): 
            LED5 = 0; LED6 = 1; return current_led+1;
            strcpy(TX_pointer,"LED6 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(6): 
            LED6 = 0; LED7 = 1; return current_led+1;
            strcpy(TX_pointer,"LED7 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(7): 
            LED7 = 0; LED8 = 1; return current_led+1;
            strcpy(TX_pointer,"LED8 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(8): 
            LED8 = 0; LED9 = 1; return current_led+1;
            strcpy(TX_pointer,"LED9 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(9): 
            LED9 = 0; LED10 = 1; return current_led+1;
            strcpy(TX_pointer,"LED10 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(10): 
            LED10 = 0; LED1 = 1; return 1;
            strcpy(TX_pointer,"LED1 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        default:
            return 1;
            break;
    }
}

char LED_Controller_Switch_Left (char current_led){
    switch (current_led){
        case(1): 
            LED1 = 0; LED10 = 1; return 10;
            strcpy(TX_pointer,"LED10 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(2): 
            LED2 = 0; LED1 = 1; return current_led-1;
            strcpy(TX_pointer,"LED1 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(3): 
            LED3 = 0; LED2 = 1; return current_led-1;
            strcpy(TX_pointer,"LED2 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(4): 
            LED4 = 0; LED3 = 1; return current_led-1;
            strcpy(TX_pointer,"LED3 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(5): 
            LED5 = 0; LED4 = 1; return current_led-1;
            strcpy(TX_pointer,"LED4 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(6): 
            LED6 = 0; LED5 = 1; return current_led-1;
            strcpy(TX_pointer,"LED5 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(7): 
            LED7 = 0; LED6 = 1; return current_led-1;
            strcpy(TX_pointer,"LED6 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(8): 
            LED8 = 0; LED7 = 1; return current_led-1;
            strcpy(TX_pointer,"LED7 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(9): 
            LED9 = 0; LED8 = 1; return current_led-1;
            strcpy(TX_pointer,"LED8 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        case(10): 
            LED10 = 0; LED9 = 1; return current_led-1;
            strcpy(TX_pointer,"LED9 is ON\r");
            EUSART_Turn_TX_ON();
            break;
        default:
            return 1;
            break;
    }
}


