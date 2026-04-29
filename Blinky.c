/* Blinky --- blink LEDs on the PIC10F322 in SOT23-6 package 2026-04-28 */


// PIC10F322 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSC    // Oscillator Selection bits (INTOSC oscillator: CLKIN function disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
#pragma config LPBOR = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>

void main(void)
{
    volatile uint16_t dally;
    uint16_t pwm1;
    uint16_t pwm2;
    
    OSCCONbits.IRCF = 7;    // Select 16MHz internal oscillator
    
    TRISAbits.TRISA0 = 0;   // RA0 pin 1 to output
    TRISAbits.TRISA1 = 0;   // RA1 pin 3 to output
    TRISAbits.TRISA2 = 0;   // RA2 pin 4 to output
                            // RA3 pin 6 is input-only
    ANSELAbits.ANSA0 = 0;   // RA0 is digital
    ANSELAbits.ANSA1 = 0;   // RA1 is digital
    ANSELAbits.ANSA2 = 0;   // RA2 is digital
    
    WPUAbits.WPUA0 = 0;     // RA0 no weak pull-up
    WPUAbits.WPUA1 = 0;     // RA1 no weak pull-up
    WPUAbits.WPUA2 = 0;     // RA2 no weak pull-up
    WPUAbits.WPUA3 = 0;     // RA3 no weak pull-up
    
    T2CONbits.T2CKPS = 3;   // Divide-by64 prescaler
    T2CONbits.TMR2ON = 1;   // Timer 2 enabled
    
    PWM1CONbits.PWM1EN = 1; // PWM1 enabled
    PWM1CONbits.PWM1OE = 1; // PWM1 output enabled
    
    PWM2CONbits.PWM2EN = 1; // PWM2 enabled
    PWM2CONbits.PWM2OE = 1; // PWM2 output enabled
    
    while (1)
    {
        LATAbits.LATA2 = 0;
        
        for (pwm1 = 0; pwm1 < 1024; pwm1++)
        {
            pwm2 = 1023 - pwm1;
            
            PWM1DCH = (uint8_t)(pwm1 >> 2);
            PWM1DCL = (uint8_t)((pwm1 & 0x03) << 6);
            
            PWM2DCH = (uint8_t)(pwm2 >> 2);
            PWM2DCL = (uint8_t)((pwm2 & 0x03) << 6);
            
            for (dally = 0; dally < 200; dally++)
                ;
        }
        
        LATAbits.LATA2 = 1;
        
        for (pwm2 = 0; pwm2 < 1024; pwm2++)
        {
            pwm1 = 1023 - pwm2;
            
            PWM1DCH = (uint8_t)(pwm1 >> 2);
            PWM1DCL = (uint8_t)((pwm1 & 0x03) << 6);
            
            PWM2DCH = (uint8_t)(pwm2 >> 2);
            PWM2DCL = (uint8_t)((pwm2 & 0x03) << 6);
            
            for (dally = 0; dally < 200; dally++)
                ;
        }
    }
}
