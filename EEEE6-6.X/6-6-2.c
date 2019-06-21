#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

void main() {
    OPTION_REG = 0b11010011;
    PORTC = 0b00000000;
    OSCCON = 0b11110000;
    TRISC = 0b00000000;
    ANSELC = 0b00000000;

    int count = 0;
    int soundLength = 3906;
    int soundHalf = soundLength / 2;
    
    while(1) {
        if (TMR0IF == 1) {
            count += 1;
            TMR0IF = 0;
            if (count < soundHalf) {
                PORTC = PORTC ^ 0b00000100;
            }
        }
        if (count == soundLength) {
            count = 0;
        }
    }
}

