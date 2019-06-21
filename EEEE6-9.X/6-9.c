#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

void main() {
    ANSELA = 0b00000100;
    TRISA = 0b00000100;
    ADCON0 = 0b00001001;
    ADCON1 = 0b00110000;

    OPTION_REG = 0b11010111;
    PORTC = 0b00000000;
    OSCCON = 0b011110000;
    ANSELC = 0x00;
    TRISC = 0x00;
    CCP1CON = 0b1100;
    
    T2CON = 0b111;
    
    PR2 = 0xff;
    
    CCPR1L = 255;

    while(TMR0IF == 0) {}
    TMR0IF = 0;

    ADGO = 1;

    while(1){
        if (ADGO == 0) {
            TMR0IF = 0;
            CCPR1L = 0xFF * (0x95 - ADRESH) / 0x95;
            ADGO = 1;
        }
    }
}
