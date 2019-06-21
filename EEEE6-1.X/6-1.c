#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

void main() {
    PORTC = 0b00000000;
    OSCCON = 0b11110000;
    TRISC = 0b00000000;
    ANSELC = 0b00000000;
    
    PORTC = 0b00000100;
    while(1) {}
}
