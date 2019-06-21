#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

void main() {
    OPTION_REG = 0b11010111;
    PORTC = 0b00000000;
    OSCCON = 0b011110000;
    ANSELC = 0x00;
    TRISC = 0x00;
    CCP1CON = 0b1100;
    
    T2CON = 0b111;
    
    PR2 = 0xff;
    
    CCPR1L = 255;
    
    int pm = -1;
    
    while(1) {
        if (TMR0IF == 1) {
            TMR0IF = 0;
            if (CCPR1L == 0) {
                pm = 1;
            } else if (CCPR1L == 255) {
                pm = -1;
            }
            CCPR1L += pm;
        }
    }
}
