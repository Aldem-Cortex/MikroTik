/* 
 * File:   GPIO.h
 * Author: User
 *
 * Created on June 9, 2020, 12:58 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include <xc.h>
#include <proc/pic18f45j10.h>

#define     ON              1
#define     OFF             0

void GPIO_Setup(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

