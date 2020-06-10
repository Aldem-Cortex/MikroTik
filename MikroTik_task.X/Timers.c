
#include <proc/pic18f45j10.h>



void Timers_Turn_T0_ON(void){
    T0CONbits.TMR0ON = 1;
}

