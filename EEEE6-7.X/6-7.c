#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

#define COUNT_PER_LENGTH 3125

void tone(int freq, int length) {
    // length ?0.1s = 1
    int period = 15625 / freq;
    int periodCount = 0;
    int lengthCount = 0;
    while(length) {
        if (TMR0IF == 1) {
            periodCount += 1;
            lengthCount += 1;
            TMR0IF = 0;

            if (periodCount == period) {
                PORTC = PORTC ^ 0x04;
                periodCount = 0;
            }
            if (lengthCount == COUNT_PER_LENGTH) {
                length -= 1;
                lengthCount = 0;
            }
        }
    }
}

void rest(int length) {
    // length ?0.1s = 1
    int count = 0;
    while(length) {
        if (TMR0IF == 1) {
            count += 1;
            TMR0IF = 0;
            if (count == COUNT_PER_LENGTH) {
                length -= 1;
                count = 0;
            }
        }
    }
}

void main() {
    OPTION_REG = 0b11011000;
    PORTC = 0b00000000;
    OSCCON = 0b11110000;
    TRISC = 0b00000000;
    ANSELC = 0b00000000;

    const int C = 264;
//    const int CS = 275;
    const int D = 293;
//    const int DS = 308;
    const int E = 330;
    const int F = 352;
//    const int FS = 367;
    const int G = 391;
//    const int GS = 413;
    const int A = 440;
//    const int AS = 469;
    const int B = 495;

//  ?????
    tone(A, 4);
    tone(G, 4);
    tone(F, 4);
    rest(4);
    tone(D, 4);
    tone(B, 2);
    tone(A, 2);
    tone(G, 2);
    tone(A, 2);
    tone(G, 2);
    tone(F, 4);
    rest(2);
    tone(G, 2);
    tone(A, 2);
    tone(E, 6);
    tone(D, 2);
    tone(C, 12);
    rest(15);
//    ?????
//    tone(C, 5);
//    tone(C, 5);
//    tone(G, 5);
//    tone(G, 5);
//    tone(A, 5);
//    tone(A, 5);
//    tone(G, 10);
//    tone(F, 5);
//    tone(F, 5);
//    tone(E, 5);
//    tone(E, 5);
//    tone(D, 5);
//    tone(D, 5);
//    tone(C, 15);
//    rest(10);
}
