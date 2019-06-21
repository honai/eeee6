#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

void main() {
    OPTION_REG = 0b11010111;
    PORTC = 0b00000000;
    OSCCON = 0b11110000;
    TRISC = 0b00000000;
    ANSELC = 0b00000000;

    int count = 0;
    PORTC = 0b00000100;
    while(1) {
        if (TMR0IF == 1) {
            count += 1;
            TMR0IF = 0;
        }
        if (count == 122) {
            if (PORTC == 0b00000000) {
                PORTC = 0b00000100;
            } else {
                PORTC = 0b00000000;
            }
            count = 0;
        }
    }
}
