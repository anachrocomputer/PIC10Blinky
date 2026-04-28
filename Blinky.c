/*
 * File:   Blinky.c
 * Author: john
 *
 * Created on April 28, 2026, 8:24 PM
 */

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
    volatile int dally;
    
    TRISAbits.TRISA0 = 0;   // RA0 pin 1 to output
    TRISAbits.TRISA1 = 0;   // RA1 pin 3 to output
    TRISAbits.TRISA2 = 0;   // RA2 pin 4 to output
                            // RA3 pin 6 is input-only
    ANSELAbits.ANSA0 = 0;   // RA0 is digital
    ANSELAbits.ANSA1 = 0;   // RA1 is digital
    ANSELAbits.ANSA2 = 0;   // RA2 is digital
    
    WPUAbits.WPUA0 = 0;   // RA0 no weak pull-up
    WPUAbits.WPUA1 = 0;   // RA1 no weak pull-up
    WPUAbits.WPUA2 = 0;   // RA2 no weak pull-up
    WPUAbits.WPUA3 = 0;   // RA3 no weak pull-up
    
    while (1)
    {
        LATAbits.LATA0 = 1;
        
        for (dally = 0; dally < 30000; dally++)
            ;
        
        LATAbits.LATA0 = 0;
        
        for (dally = 0; dally < 30000; dally++)
            ;
    }
}
