#include "Init.h"

static void Toggle_HS_Osc(void){
    OSCCON ^= 0x2;
}

static void Set_EUSART(void){
    /*  Activate Async mode */
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1;
    
    /*  Baud rate settings  */
    TXSTAbits.BRGH = BRGH_VALUE;
    BAUDCONbits.BRG16 = BRG16_VALUE;
    SPBRG = SPBRG_VALUE;
    SPBRGH = SPBRGH_VALUE;
    
}

static void Turn_on_Interrupts(void){
    /*  Enable interrupt priority   */
    RCONbits.IPEN = 1;
    /*  Enable High priority interrupts   */
    INTCONbits.GIE = 1;
    /*  Enable Low priority interrupts   */
    INTCONbits.PEIE = 1;
    /*  EUSART interrupts   */
    PIE1bits.TXIE = 1;
    PIE1bits.RCIE = 1;
    /*  PORTB on-change interrupts   */
    INTCONbits.RBIE = 1;
    /*  Set EUSART Interrupts high priority */
    IPR1bits.RCIP = 1;
    IPR1bits.TXIP = 1;
    /*  Set Timer 0 low priority    */
    INTCON2bits.TMR0IP = 0;
    /*  Set PORTB On-change Interrupt*/
    INTCON2bits.RBIP = 0;
    /*  Timer 0 interrupts  */
    INTCONbits.TMR0IE = 1;
}


static char Configure_T0(unsigned char bits,unsigned int prescaler){
    
    
    switch(prescaler){
        case (2): 
            T0CON &= ~(1 << 2);
            T0CON &= ~(1 << 1);
            T0CON &= ~(1 << 0);
            break;
        case (4): 
            T0CON &= ~(1 << 2);
            T0CON &= ~(1 << 1);
            T0CON |= 1;
            break;
        case (8): 
            T0CON &= ~(1 << 2);
            T0CON |= (1 << 1);
            T0CON &= ~(1 << 0);
            break;
        case (16): 
            T0CON &= ~(1 << 2);
            T0CON |= (1 << 1);
            T0CON |= (1 << 0);
            break;
        case (32): 
            T0CON |= (1 << 2);
            T0CON &= ~(1 << 1);
            T0CON &= ~(1 << 0);
            break;
        case (64): 
            T0CON |= (1 << 2);
            T0CON &= ~(1 << 1);
            T0CON |= (1 << 0);
            break;
        case (128): 
            T0CON |= (1 << 2);
            T0CON |= (1 << 1);
            T0CON &= ~(1 << 0);
            break;
        case (256): 
            T0CON |= (1 << 2);
            T0CON |= (1 << 1);
            T0CON |= (1 << 0);
            break;
        default:
            return 0;
    }
    
    if(bits == 8){
        T0CONbits.T08BIT = 1;
    }
    else if(bits == 16){
        T0CONbits.T08BIT = 0;
    }
    else {
        return 0;
    }
    return 1;
}

void Init_Startup(void){
    /*  Set All GPIO as Digital */
    ADCON0 = 0;
    ADCON1 = 0xFF;
    
    /*   Activate HS Oscillator   */
    Toggle_HS_Osc();
    
    /*  Setup Timer 0   */
    if(Configure_T0(T0_BITS,T0_PRESCALER)){
        strcpy(TX_pointer,"Failed to configure Timer 0!\r");
        EUSART_Turn_TX_ON();
    }
    
    /*  Setup EUSART    */
    Set_EUSART();
    
    /*  Setup interrupts    */
    Turn_on_Interrupts();
    
}

