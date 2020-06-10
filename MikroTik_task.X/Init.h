/* 
 * File:   Init.h
 * Author: User
 *
 * Created on June 9, 2020, 1:02 PM
 */

#ifndef INIT_H
#define	INIT_H

#include <stdio.h>
#include "EUSART.h"
#include <proc/pic18f45j10.h>

#define     BRGH_VALUE      0
#define     BRG16_VALUE     0
#define     SPBRG_VALUE     15
#define     SPBRGH_VALUE    0
#define     T0_BITS         16
#define     T0_PRESCALER    256

void Init_Startup(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* INIT_H */

