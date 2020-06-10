#include "EUSART.h"

void EUSART_Turn_TX_ON(void){
    TXSTAbits.TXEN = 1;
}

void EUSART_Turn_TX_OFF(void){
    TXSTAbits.TXEN = 0;
}

void EUSART_Turn_RX_ON(void){
    RCSTAbits.CREN = 1;
}

void EUSART_Transmit(char size, char *buffer){
    for(int i = 0; i < size; i++){
        TXREG = *(buffer+i);
        while(TXSTAbits.TRMT != 1){};
    }
}

/*  Receiving the string and storing in buffer  */

void EUSART_Receive(void){
    *RX_pointer = RCREG;
    if(*(RX_pointer) != '\n'){
        RX_pointer++;
    }
    else{
        RX_pointer = Receive_Buffer;
        received = 1;
    }
}

/*  Analyzing received data and converting chars to values  */

unsigned char EUSART_Analize_data(void){
    char temp_data;
    char *temp_pointer;
    if(received){
        temp_pointer = strstr(RX_pointer,"speed=");
        if((*(temp_pointer+7) != '\r')&&(*(temp_pointer+8) != '\r')){
            temp_data = (*(temp_pointer+6)-48)*100 + (*(temp_pointer+7)-48)*10 + (*(temp_pointer+8)-48);
        }
        if((*(temp_pointer+7) != '\r')&&(*(temp_pointer+8) == '\r')){
            temp_data = (*(temp_pointer+6)-48)*10 + (*(temp_pointer+7)-48)*10;
        }
        if(*(temp_pointer+7) == '\r'){
            temp_data = (*(temp_pointer+6)-48);
        }
        received = 0;
        return temp_data;
    }
    return 0;
}

