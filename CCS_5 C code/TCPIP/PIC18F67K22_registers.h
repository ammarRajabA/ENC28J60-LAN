#ifndef 18F67K22_H
#define 18F67K22_H

struct{
   unsigned int TOSU:5;
} TOSUbits;
#byte TOSUbits = 0xFFF
#byte TOSU = 0xFFF

#byte TOSHbits = 0xFFE

#byte TOSLbits = 0xFFD

struct{
   unsigned int STKPTR:5;
   unsigned int :1;
   unsigned int STKUNF:1;
   unsigned int STKFUL:1;
} STKPTRbits;
#byte STKPTRbits = 0xFFC
#byte STKPTR = 0xFFC

struct {
   unsigned int PCU:5;
} PCLATUbits;
#byte PCLATUbits = 0xFFB
#byte PCLATU = 0xFFB

#byte PCLATHbits = 0xFFA

#byte PCLbits = 0xFF9

struct {
   unsigned int TBLPTRU:5;
   unsigned int ACSS:1;
} TBLPTRUbits;
#byte TBLPTRUbits = 0xFF8
#byte TBLPTRU = 0xFF8

#byte TBLPTRHbits = 0xFF7

#byte TBLPTRLbits = 0xFF6

#byte TABLATbits = 0xFF5

#byte PRODHbits = 0xFF4

#byte PRODLbits = 0xFF3

struct{
   unsigned int RBIF:1;
   unsigned int INT0IF:1;
   unsigned int TMR0IF:1;
   unsigned int RBIE:1;
   unsigned int INT0IE:1;
   unsigned int TMR0IE:1;
   unsigned int PEIE:1;
   unsigned int GIE:1;
} INTCONbits;
#byte INTCONbits = 0xFF2
#byte INTCON = 0xFF2

struct {
   unsigned int RBIP:1;
   unsigned int INT3IP:1;
   unsigned int TMR0IP:1;
   unsigned int INTEDG:1;
   unsigned int INTEDG_2:1;
   unsigned int INTEDG_3:1;
   unsigned int INTEDG_4:1;
   unsigned int RBPU:1;
} INTCON2bits;
#byte INTCON2bits = 0xFF1
#byte INTCON2 = 0xFF1

struct {
   unsigned int INT1IF:1;
   unsigned int INT2IF:1;
   unsigned int INT3IF:1;
   unsigned int INT1IE:1;
   unsigned int INT2IE:1;
   unsigned int INT3IE:1;
   unsigned int INT1IP:1;
   unsigned int INT2IP:1;
} INTCON3bits;
#byte INTCON3bits = 0xFF0
#byte INTCON3 = 0xFF0

#byte INDF0 = 0xFEF

#byte POSTINC0bits = 0xFEE

#byte POSTDEC0bits = 0xFED

#byte PREINC0bits = 0xFEC

#byte PLUSW0bits = 0xFEB

struct {
   unsigned int FSR0H:4;
} FSR0Hbits;
#byte FSR0Hbits = 0xFEA
#byte FSR0H = 0xFEA

#byte FSR0Lbits = 0xFE9

#byte WREGbits = 0xFE8

#byte INDF1bits = 0xFE7

#byte POSTINC1bits = 0xFE6

#byte POSTDEC1bits = 0xFE5

#byte PREINC1bits = 0xFE4

#byte PLUSW1bits = 0xFE3

struct {
   unsigned int FSR1H:4;
} FSR1Hbits;
#byte FSR1Hbits = 0xFE2
#byte FSR1H = 0xFE2

#byte FSR1Lbits = 0xFE1

struct {
   unsigned int BSR:4;
} BSRbits;
#byte BSRbits = 0xFE0
#byte BSR = 0xFE0

#byte INDF2 = 0xFDF

#byte POSTINC2 = 0xFDE

#byte POSTDEC2bits = 0xFDD

#byte PREINC2bits = 0xFDC

#byte PLUSW2bits = 0xFDB

struct {
   unsigned int FSR2H:4;
} FSR2Hbits;
#byte FSR2Hbits = 0xFDA
#byte FSR2H = 0xFDA

#byte FSR2L = 0xFD9
#word FSR2 = 0xFD9

struct {
   unsigned int C:1;
   unsigned int DC:1;
   unsigned int Z:1;
   unsigned int OV:1;
   unsigned int N:1;
} STATUSbits;
#byte STATUSbits = 0xFD8
#byte STATUS = 0xFD8

#byte TMR0H = 0xFD7

#byte TMR0L = 0xFD6

struct {
   unsigned int T0PS:3;
   unsigned int PSA:1;
   unsigned int T0SE:1;
   unsigned int T0CS:1;
   unsigned int T08BIT:1;
   unsigned int TMR0ON:1;
} T0CONbits;
#byte T0CONbits = 0xFD5
#byte T0CON = 0xFD5

#byte SPBRGH1bits = 0xFD4

struct {
   unsigned int SWDTEN:1;
   unsigned int ULPSINK:1;
   unsigned int ULPEN:1;
   unsigned int :1;
   unsigned int SRETEN:1;
   unsigned int ULPLVL:1;
   unsigned int :1;
   unsigned int REGSLP:1;
} WDTCONbits;
#byte WDTCONbits = 0xFD1
#byte WDTCON = 0xFD1

struct {
   unsigned int BOR:1;
   unsigned int POR:1;
   unsigned int PD:1;
   unsigned int TO:1;
   unsigned int RI:1;
   unsigned int CM:1;
   unsigned int SBOREN:1;
   unsigned int IPEN:1;
} RCONbits;
#byte RCONbits = 0xFD0
#byte RCON = 0xFD0

#byte TMR1Hbits = 0xFCF

#byte TMR1Lbits = 0xFCE

struct{
   unsigned int TMR1ON:1;
   unsigned int RD1:1;
   unsigned int T1SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T1CKPS:2;
   unsigned int TMR1CS:2;
} T1CONbits;
#byte T1CONbits = 0xFCD
#byte T1CON = 0xFCD

#byte TMR2bits = 0xFCC

struct {
   unsigned int T2CKPS:2;
   unsigned int TMR2ON:1;
   unsigned int T2OUTPS:4;
} T2CONbits;
#byte T2CONbits = 0xFCA
#byte T2CON = 0xFCA

#byte SSP1BUF = 0xFC9

#byte SSP1ADD = 0xFC8

struct {
   unsigned int BF:1;
   unsigned int UA:1;
   unsigned int R:1;
   unsigned int S:1;
   unsigned int P:1;
   unsigned int D:1;
   unsigned int CKE:1;
   unsigned int SMP:1;
} SSP1STATbits;
#byte SSP1STATbits = 0xFC7
#byte SSP1STAT = 0xFC7

struct {
   unsigned int SSPM:4;
   unsigned int CKP:1;
   unsigned int SSPEN:1;
   unsigned int SSPOV:1;
   unsigned int WCOL:1;
} SSP1CON1bits;
#byte SSP1CON1bits = 0xFC6
#byte SSP1CON1 = 0xFC6

struct{
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int ACKSTAT:1;
   unsigned int GCEN:1;
} SSP1CON2bits;
#byte SSP1CON2bits = 0xFC5
#byte SSP1CON2 = 0xFC5

#byte ADRESHbits = 0xFC4

#byte ADRESLbits = 0xFC3

struct {
   unsigned int ADON:1;
   unsigned int GO:1;
   unsigned int CHS:5;
} ADCON0bits;
#byte ADCON0bits = 0xFC2
#byte ADCON0 = 0xFC2

struct {
   unsigned int CHSN:3;
   unsigned int VNCFG:1;
   unsigned int VCFG:2;
   unsigned int TRIGSEL:2;
} ADCON1bits;
#byte ADCON1bits = 0xFC1
#byte ADCON1 = 0xFC1

struct{
   unsigned int ADCS:3;
   unsigned int ACQT:3;
   unsigned int :1;
   unsigned int ADFM:1;
} ADCON2bits;
#byte ADCON2bits = 0xFC0
#byte ADCON2 = 0xFC0

#byte TMR3Hbits = 0xFB3

struct{
   unsigned int TMR3ON:1;
   unsigned int RD1:1;
   unsigned int T3SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T3CKPS:2;
   unsigned int TMR3CS:2;
} T3CONbits;
#byte T3CONbits = 0xFB1
#byte T3CON = 0xFB1

#byte SPBRG1bits = 0xFAF

#byte RCREG1bits = 0xFAE

#byte TXREG1bits = 0xFAD

struct{
   unsigned int TX9D:1;
   unsigned int TRMT:1;
   unsigned int BRGH:1;
   unsigned int SENDB:1;
   unsigned int SYNC:1;
   unsigned int TXEN:1;
   unsigned int TX:1;
   unsigned int CSRC:1;
} TXSTA1bits;
#byte TXSTA1bits = 0xFAC
#byte TXSTA1 = 0xFAC

struct{
   unsigned int RX9D:1;
   unsigned int OERR:1;
   unsigned int FERR:1;
   unsigned int ADDEN:1;
   unsigned int CREN:1;
   unsigned int SREN:1;
   unsigned int RX:1;
   unsigned int SPEN:1;
} RCSTA1bits;
#byte RCSTA1bits = 0xFAB
#byte RCSTA1 = 0xFAB

struct{
   unsigned int RTCCIP:1;
   unsigned int CCP1IP:1;
   unsigned int CCP2IP:1;
   unsigned int CTMUIP:1;
   unsigned int TX2IP:1;
   unsigned int RC2IP:1;
   unsigned int :1;
   unsigned int TMR5GIP:1;
} IPR3bits;
#byte IPR3bits = 0xFA5
#byte IPR3 = 0xFA5

struct{
   unsigned int RTCCIF:1;
   unsigned int CCP1IF:1;
   unsigned int CCP2IF:1;
   unsigned int CTMUIF:1;
   unsigned int TX2IF:1;
   unsigned int RC2IF:1;
   unsigned int :1;
   unsigned int TMR5GIF:1;
} PIR3bits;
#byte PIR3bits = 0xFA4
#byte PIR3 = 0xFA4

struct {
   unsigned int RTCCIE:1;
   unsigned int CCP1IE:1;
   unsigned int CCP2IE:1;
   unsigned int CTMUIE:1;
   unsigned int TX2IE:1;
   unsigned int RC2IE:1;
   unsigned int :1;
   unsigned int TMR5GIE:1;
} PIE3bits;
#byte PIE3bits = 0xFA3
#byte PIE3 = 0xFA3

struct{
   unsigned int TMR3GIP:1;
   unsigned int TMR3IP:1;
   unsigned int HLVDIP:1;
   unsigned int BCL1IP:1;
   unsigned int BCL2IP:1;
   unsigned int SSP2IP:1;
   unsigned int :1;
   unsigned int OSCFIP:1;
} IPR2bits;
#byte IPR2bits = 0xFA2
#byte IPR2 = 0xFA2

struct PIR2BITS {
   unsigned int TMR3GIF:1;
   unsigned int TMR3IF:1;
   unsigned int HLVDIF:1;
   unsigned int BCL1IF:1;
   unsigned int BCL2IF:1;
   unsigned int SSP2IF:1;
   unsigned int :1;
   unsigned int OSCFIF:1;
} PIR2bits;
#byte PIR2bits = 0xFA1
#byte PIR2 = 0xFA1

struct{
   unsigned int TMR3GIE:1;
   unsigned int TMR3IE:1;
   unsigned int HLVDIE:1;
   unsigned int BCL1IE:1;
   unsigned int BCL2IE:1;
   unsigned int SSP2IE:1;
   unsigned int :1;
   unsigned int OSCFIE:1;
} PIE2bits;
#byte PIE2bits = 0xFA0
#byte PIE2 = 0xFA0

struct{
   unsigned int TMR1IP:1;
   unsigned int TMR2IP:1;
   unsigned int TMR1GIP:1;
   unsigned int SSP1IP:1;
   unsigned int TX1IP:1;
   unsigned int RC1IP:1;
   unsigned int ADIP:1;
   unsigned int PSPIP:1;
} IPR1bits;
#byte IPR1bits = 0xF9F
#byte IPR1 = 0xF9F

struct{
   unsigned int TMR1IF:1;
   unsigned int TMR2IF:1;
   unsigned int TMR1GIF:1;
   unsigned int SSP1IF:1;
   unsigned int TX1IF:1;
   unsigned int RC1IF:1;
   unsigned int ADIF:1;
   unsigned int PSPIF:1;
} PIR1bits;
#byte PIR1bits = 0xF9E
#byte PIR1 = 0xF9E

struct{
   unsigned int TMR1IE:1;
   unsigned int TMR2IE:1;
   unsigned int TMR1GIE:1;
   unsigned int SSP1IE:1;
   unsigned int TX1IE:1;
   unsigned int RC1IE:1;
   unsigned int ADIE:1;
   unsigned int PSPIE:1;
} PIE1bits;
#byte PIE1bits = 0xF9D
#byte PIE1 = 0xF9D

struct{
   unsigned int TRISG0:1;
   unsigned int TRISG1:1;
   unsigned int TRISG2:1;
   unsigned int TRISG3:1;
   unsigned int TRISG4:1;
   unsigned int TRISG5:1;
   unsigned int TRISG6:1;
   unsigned int TRISG7:1;
} TRISGbits;
#byte TRISGbits = 0xF98
#byte TRISG = 0xF98

struct{
   unsigned int TRISF0:1;
   unsigned int TRISF1:1;
   unsigned int TRISF2:1;
   unsigned int TRISF3:1;
   unsigned int TRISF4:1;
   unsigned int TRISF5:1;
   unsigned int TRISF6:1;
   unsigned int TRISF7:1;
} TRISFbits;
#byte TRISFbits = 0xF97
#byte TRISF = 0xF97

struct {
   unsigned int TRISE0:1;
   unsigned int TRISE1:1;
   unsigned int TRISE2:1;
   unsigned int TRISE3:1;
   unsigned int TRISE4:1;
   unsigned int TRISE5:1;
   unsigned int TRISE6:1;
   unsigned int TRISE7:1;
} TRISEbits;
#byte TRISEbits = 0xF96
#byte TRISE = 0xF96

struct{
   unsigned int TRISD0:1;
   unsigned int TRISD1:1;
   unsigned int TRISD2:1;
   unsigned int TRISD3:1;
   unsigned int TRISD4:1;
   unsigned int TRISD5:1;
   unsigned int TRISD6:1;
   unsigned int TRISD7:1;
} TRISDbits;
#byte TRISDbits = 0xF95
#byte TRISD = 0xF95

struct{
   unsigned int TRISC0:1;
   unsigned int TRISC1:1;
   unsigned int TRISC2:1;
   unsigned int TRISC3:1;
   unsigned int TRISC4:1;
   unsigned int TRISC5:1;
   unsigned int TRISC6:1;
   unsigned int TRISC7:1;
} TRISCbits;
#byte TRISCbits = 0xF94
#byte TRISC = 0xF94

struct{
   unsigned int TRISB0:1;
   unsigned int TRISB1:1;
   unsigned int TRISB2:1;
   unsigned int TRISB3:1;
   unsigned int TRISB4:1;
   unsigned int TRISB5:1;
   unsigned int TRISB6:1;
   unsigned int TRISB7:1;
} TRISBbits;
#byte TRISBbits = 0xF93
#byte TRISB = 0xF93

struct{
   unsigned int TRISA0:1;
   unsigned int TRISA1:1;
   unsigned int TRISA2:1;
   unsigned int TRISA3:1;
   unsigned int TRISA4:1;
   unsigned int TRISA5:1;
   unsigned int TRISA6:1;
   unsigned int TRISA7:1;
} TRISAbits;
#byte TRISAbits = 0xF92
#byte TRISA = 0xF92

struct{
   unsigned int LATG0:1;
   unsigned int LATG1:1;
   unsigned int LATG2:1;
   unsigned int LATG3:1;
   unsigned int LATG4:1;
   unsigned int LATG5:1;
   unsigned int LATG6:1;
   unsigned int LATG7:1;
} LATGbits;
#byte LATGbits = 0xF8F
#byte LATG = 0xF8F

struct {
   unsigned int LATF0:1;
   unsigned int LATF1:1;
   unsigned int LATF2:1;
   unsigned int LATF3:1;
   unsigned int LATF4:1;
   unsigned int LATF5:1;
   unsigned int LATF6:1;
   unsigned int LATF7:1;
} LATFbits;
#byte LATFbits = 0xF8E
#byte LATF = 0xF8E

struct {
   unsigned int LATE0:1;
   unsigned int LATE1:1;
   unsigned int LATE2:1;
   unsigned int LATE3:1;
   unsigned int LATE4:1;
   unsigned int LATE5:1;
   unsigned int LATE6:1;
   unsigned int LATE7:1;
} LATEbits;
#byte LATEbits = 0xF8D
#byte LATE = 0xF8D

struct {
   unsigned int LATD0:1;
   unsigned int LATD1:1;
   unsigned int LATD2:1;
   unsigned int LATD3:1;
   unsigned int LATD4:1;
   unsigned int LATD5:1;
   unsigned int LATD6:1;
   unsigned int LATD7:1;
} LATDbits;
#byte LATDbits = 0xF8C
#byte LATD = 0xF8C

struct{
   unsigned int LATC0:1;
   unsigned int LATC1:1;
   unsigned int LATC2:1;
   unsigned int LATC3:1;
   unsigned int LATC4:1;
   unsigned int LATC5:1;
   unsigned int LATC6:1;
   unsigned int LATC7:1;
} LATCbits;
#byte LATCbits = 0xF8B
#byte LATC = 0xF8B

struct{
   unsigned int LATB0:1;
   unsigned int LATB1:1;
   unsigned int LATB2:1;
   unsigned int LATB3:1;
   unsigned int LATB4:1;
   unsigned int LATB5:1;
   unsigned int LATB6:1;
   unsigned int LATB7:1;
} LATBbits;
#byte LATBbits = 0xF8A
#byte LATB = 0xF8A

struct {
   unsigned int LATA0:1;
   unsigned int LATA1:1;
   unsigned int LATA2:1;
   unsigned int LATA3:1;
   unsigned int LATA4:1;
   unsigned int LATA5:1;
   unsigned int LATA6:1;
   unsigned int LATA7:1;
} LATAbits;
#byte LATAbits = 0xF89
#byte LATA = 0xF89

struct{
   unsigned int RG0:1;
   unsigned int RG1:1;
   unsigned int RG2:1;
   unsigned int RG3:1;
   unsigned int RG4:1;
   unsigned int RG5:1;
   unsigned int RG6:1;
   unsigned int RG7:1;
} PORTGbits;
#byte PORTGbits = 0xF86
#byte PORTG = 0xF86

struct{
   unsigned int RF0:1;
   unsigned int RF1:1;
   unsigned int RF2:1;
   unsigned int RF3:1;
   unsigned int RF4:1;
   unsigned int RF5:1;
   unsigned int RF6:1;
   unsigned int RF7:1;
} PORTFbits;
#byte PORTFbits = 0xF85
#byte PORTF = 0xF85

struct{
   unsigned int RE0:1;
   unsigned int RE1:1;
   unsigned int RE2:1;
   unsigned int RE3:1;
   unsigned int RE4:1;
   unsigned int RE5:1;
   unsigned int RE6:1;
   unsigned int RE7:1;
} PORTEbits;
#byte PORTEbits = 0xF84
#byte PORTE = 0xF84

struct {
   unsigned int RD0:1;
   unsigned int RD1:1;
   unsigned int RD2:1;
   unsigned int RD3:1;
   unsigned int RD4:1;
   unsigned int RD5:1;
   unsigned int RD6:1;
   unsigned int RD7:1;
} PORTDbits;
#byte PORTDbits = 0xF83
#byte PORTD = 0xF83

struct{
   unsigned int RC0:1;
   unsigned int RC1:1;
   unsigned int RC2:1;
   unsigned int RC3:1;
   unsigned int RC4:1;
   unsigned int RC5:1;
   unsigned int RC6:1;
   unsigned int RC7:1;
} PORTCbits;
#byte PORTCbits = 0xF82
#byte PORTC = 0xF82

struct{
   unsigned int RB0:1;
   unsigned int RB1:1;
   unsigned int RB2:1;
   unsigned int RB3:1;
   unsigned int RB4:1;
   unsigned int RB5:1;
   unsigned int RB6:1;
   unsigned int RB7:1;
} PORTBbits;
#byte PORTBbits = 0xF81
#byte PORTB = 0xF81

struct{
   unsigned int RA0:1;
   unsigned int RA1:1;
   unsigned int RA2:1;
   unsigned int RA3:1;
   unsigned int RA4:1;
   unsigned int RA5:1;
   unsigned int RA6:1;
   unsigned int RA7:1;
} PORTAbits;
#byte PORTAbits = 0xF80
#byte PORTA = 0xF80

#byte TMR5Hbits = 0xF7D

struct {
   unsigned int TMR5ON:1;
   unsigned int RD1:1;
   unsigned int T5SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T5CKPS:2;
   unsigned int TMR5CS:2;
} T5CONbits;
#byte T5CONbits = 0xF7B
#byte T5CON = 0xF7B

#byte TMR4bits = 0xF6D

struct{
   unsigned int T4CKPS:2;
   unsigned int TMR4ON:1;
   unsigned int T4OUTPS:4;
} T4CONbits;
#byte T4CONbits = 0xF6B
#byte T4CON = 0xF6B

#byte SSP2BUFbits = 0xF6A

#byte SSP2ADDbits = 0xF69

struct{
   unsigned int BF:1;
   unsigned int UA:1;
   unsigned int R:1;
   unsigned int S:1;
   unsigned int P:1;
   unsigned int D:1;
   unsigned int CKE:1;
   unsigned int SMP:1;
} SSP2STATbits;
#byte SSP2STATbits = 0xF68
#byte SSP2STAT = 0xF68

struct{
   unsigned int SSPM:4;
   unsigned int CKP:1;
   unsigned int SSPEN:1;
   unsigned int SSPOV:1;
   unsigned int WCOL:1;
} SSP2CON1bits;
#byte SSP2CON1bits = 0xF67
#byte SSP2CON1 = 0xF67

struct{
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int ACKSTAT:1;
   unsigned int GCEN:1;
} SSP2CON2bits;
#byte SSP2CON2bits = 0xF66
#byte SSP2CON2 = 0xF66

struct{
   unsigned int ABDEN:1;
   unsigned int WUE:1;
   unsigned int :1;
   unsigned int BRG1:1;
   unsigned int TXCKP:1;
   unsigned int RXDTP:1;
   unsigned int RCMT:1;
   unsigned int ABDOVF:1;
} BAUDCON1bits;
#byte BAUDCON1bits = 0xF65
#byte BAUDCON1 = 0xF65

struct{
   unsigned int SPI2OD:1;
   unsigned int :4;
   unsigned int CCP1OD:1;
   unsigned int CCP2OD:1;
   unsigned int SPI1OD:1;
} ODCON1bits;
#byte ODCON1bits = 0xF29
#byte ODCON1 = 0xF29

struct{
   unsigned int CCP3OD:1;
   unsigned int CCP4OD:1;
   unsigned int CCP5OD:1;
   unsigned int CCP6OD:1;
   unsigned int CCP7OD:1;
   unsigned int CCP8OD:1;
   unsigned int CCP9OD:1;
   unsigned int CCP10OD:1;
} ODCON2bits;
#byte ODCON2bits = 0xF28
#byte ODCON2 = 0xF28

struct{
   unsigned int CTMUDS:1;
   unsigned int CTMUREF:2;
   unsigned int :3;
   unsigned int U1OD:1;
   unsigned int U2OD:1;
} ODCON3bits;
#byte ODCON3bits = 0xF27
#byte ODCON3 = 0xF27

struct{
   unsigned int ANSEL:8;
} ANCON0bits;
#byte ANCON0bits = 0xF25
#byte ANCON0 = 0xF25

struct{
   unsigned int ANSEL:2;
   unsigned int ANSEL1:2;
} ANCON1bits;
#byte ANCON1bits = 0xF24
#byte ANCON1 = 0xF24

struct{
   unsigned int RX9D:1;
   unsigned int OERR:1;
   unsigned int FERR:1;
   unsigned int ADDEN:1;
   unsigned int CREN:1;
   unsigned int SREN:1;
   unsigned int RX:1;
   unsigned int SPEN:1;
} RCSTA2bits;
#byte RCSTA2bits = 0xF22
#byte RCSTA2 = 0xF22

struct{
   unsigned int TX9D:1;
   unsigned int TRMT:1;
   unsigned int BRGH:1;
   unsigned int SENDB:1;
   unsigned int SYNC:1;
   unsigned int TXEN:1;
   unsigned int TX:1;
   unsigned int CSRC:1;
} TXSTA2bits;
#byte TXSTA2bits = 0xF21
#byte TXSTA2 = 0xF21

struct{
   unsigned int ABDEN:1;
   unsigned int WUE:1;
   unsigned int :1;
   unsigned int BRG1:1;
   unsigned int TXCKP:1;
   unsigned int RXDTP:1;
   unsigned int RCIDL:1;
   unsigned int ABDOVF:1;
} BAUDCON2bits;
#byte BAUDCON2bits = 0xF20
#byte BAUDCON2 = 0xF20

#byte SPBRGH2bits = 0xF1F

#byte SPBRG2bits = 0xF1E

#byte RCREG2bits = 0xF1D

#byte TXREG2bits = 0xF1C


#endif
