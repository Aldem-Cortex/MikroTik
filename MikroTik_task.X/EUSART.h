/* 
 * File:   EUSART.h
 * Author: User
 *
 * Created on June 9, 2020, 2:44 PM
 */

#ifndef EUSART_H
#define	EUSART_H

#include <xc.h>
#include <string.h>
#include <stdbool.h>
#include <proc/pic18f45j10.h>

char Transmit_Buffer[64];
char *TX_pointer = Transmit_Buffer;
char Receive_Buffer[64];
char *RX_pointer = Receive_Buffer;
bool received = 0;

void EUSART_Turn_TX_ON(void);
void EUSART_Turn_TX_OFF(void);
void EUSART_Turn_RX_ON(void);
void EUSART_Transmit(char size, char *buffer);
void EUSART_Receive(void);
unsigned char EUSART_Analize_data(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* EUSART_H */

