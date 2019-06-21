#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config PLLEN = ON
#pragma config LVP = OFF

#include <xc.h>

void bright() {
    if (ADGO == 0) {
        if (ADRESH > 0x80) {
            CCPR1L = 0;
        } else {
            CCPR1L = 0xFF - ADRESH;
        }
        ADGO = 1;
    }
}

void main() {
    // アナログ入力の初期化
    ANSELA = 0b00000100;
    TRISA = 0b00000100;
    ADCON0 = 0b00001001;
    ADCON1 = 0b00110000;

    // TB7をデジタル入力に
    TRISB = 0b10000000;

    // PWM信号の初期化
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
    
    // モード切り替えを保持する変数
    int mode = 0;

    while(1){
        if (RB7 == 0) {
            while(RB7 == 0) {}
            mode = 1 - mode;
        }
        if (mode) {
            // ONモード
            bright();
        } else {
            // OFFモード
            CCPR1L = 0;
        }
    }
}
