#byte TOSU = 0xFFF

#byte TOSH = 0xFFE

#byte TOSL = 0xFFD

struct STKPTRBITS {
   unsigned int STKPTR0:1;
   unsigned int STKPTR1:1;
   unsigned int STKPTR2:1;
   unsigned int STKPTR3:1;
   unsigned int STKPTR4:1;
   unsigned int :1;
   unsigned int STKUNF:1;
   unsigned int STKFUL:1;
} STKPTRbits;
#byte STKPTRbits = 0xFFC
#byte STKPTR = 0xFFC

#byte PCLATU = 0xFFB

#byte PCLATH = 0xFFA

#byte PCL = 0xFF9

struct TBLPTRUBITS {
   unsigned int TBLPTRU0:1;
   unsigned int TBLPTRU1:1;
   unsigned int TBLPTRU2:1;
   unsigned int TBLPTRU3:1;
   unsigned int TBLPTRU4:1;
   unsigned int ACSS:1;
} TBLPTRUbits;
#byte TBLPTRUbits = 0xFF8
#byte TBLPTRU = 0xFF8

#byte TBLPTRH = 0xFF7

#byte TBLPTRL = 0xFF6

#byte TABLAT = 0xFF5

#byte PRODH = 0xFF4

#byte PRODL = 0xFF3

struct INTCONBITS {
   unsigned int RBIF:1;
   unsigned int INT0IF:1;
   unsigned int TMR0IF:1;
   unsigned int RBIE:1;
   unsigned int INT0IE:1;
   unsigned int TMR0IE:1;
   unsigned int PEIE_GIEL:1;
   unsigned int GIE_GIEH:1;
} INTCONbits;
#byte INTCONbits = 0xFF2
#byte INTCON = 0xFF2

struct INTCON2BITS {
   unsigned int RBIP:1;
   unsigned int INT3IP:1;
   unsigned int TMR0IP:1;
   unsigned int INTEDG3:1;
   unsigned int INTEDG4:1;
   unsigned int INTEDG5:1;
   unsigned int INTEDG6:1;
   unsigned int RBPU:1;
} INTCON2bits;
#byte INTCON2bits = 0xFF1
#byte INTCON2 = 0xFF1

struct INTCON3BITS {
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

#byte POSTINC0 = 0xFEE

#byte POSTDEC0 = 0xFED

#byte PREINC0 = 0xFEC

#byte PLUSW0 = 0xFEB

#byte FSR0H = 0xFEA

#byte FSR0L = 0xFE9

#byte WREG = 0xFE8

#byte INDF1 = 0xFE7

#byte POSTINC1 = 0xFE6

#byte POSTDEC1 = 0xFE5

#byte PREINC1 = 0xFE4

#byte PLUSW1 = 0xFE3

#byte FSR1H = 0xFE2

#byte FSR1L = 0xFE1

#byte BSR = 0xFE0

#byte INDF2 = 0xFDF

#byte POSTINC2 = 0xFDE

#byte POSTDEC2 = 0xFDD

#byte PREINC2 = 0xFDC

#byte PLUSW2 = 0xFDB

#byte FSR2H = 0xFDA

#byte FSR2L = 0xFD9

#word FSR2 = 0xFD9

struct STATUSBITS {
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

struct T0CONBITS {
   unsigned int T0PS0:1;
   unsigned int T0PS1:1;
   unsigned int T0PS2:1;
   unsigned int PSA:1;
   unsigned int T0SE:1;
   unsigned int T0CS:1;
   unsigned int T08BIT:1;
   unsigned int TMR0ON:1;
} T0CONbits;
#byte T0CONbits = 0xFD5
#byte T0CON = 0xFD5

struct OSCCONBITS {
   unsigned int SCS0:1;
   unsigned int SCS1:1;
   unsigned int :1;
   unsigned int OSTS:1;
   unsigned int :3;
   unsigned int IDLEN:1;
} OSCCONbits;
#byte OSCCONbits = 0xFD3
#byte OSCCON = 0xFD3

struct ECON1BITS {
   unsigned int :2;
   unsigned int RXEN:1;
   unsigned int TXRTS:1;
   unsigned int CSUMEN:1;
   unsigned int DMAST:1;
   unsigned int RXRST:1;
   unsigned int TXRST:1;
} ECON1bits;
#byte ECON1bits = 0xFD2
#byte ECON1 = 0xFD2

struct WDTCONBITS {
   unsigned int SWDTEN:1;
} WDTCONbits;
#byte WDTCONbits = 0xFD1
#byte WDTCON = 0xFD1

struct RCONBITS {
   unsigned int BOR:1;
   unsigned int POR:1;
   unsigned int PD:1;
   unsigned int TO:1;
   unsigned int RI:1;
   unsigned int :2;
   unsigned int IPEN:1;
} RCONbits;
#byte RCONbits = 0xFD0
#byte RCON = 0xFD0

#byte TMR1H = 0xFCF

#byte TMR1L = 0xFCE

struct T1CONBITS {
   unsigned int TMR1ON:1;
   unsigned int TMR1CS:1;
   unsigned int T1SYNC:1;
   unsigned int T1OSCEN:1;
   unsigned int T1CKPS4:1;
   unsigned int T1CKPS5:1;
   unsigned int T1RUN:1;
   unsigned int RD16:1;
} T1CONbits;
#byte T1CONbits = 0xFCD
#byte T1CON = 0xFCD

#byte TMR2 = 0xFCC

#byte PR2 = 0xFCB

struct T2CONBITS {
   unsigned int T2CKPS0:1;
   unsigned int T2CKPS1:1;
   unsigned int TMR2ON:1;
   unsigned int TOUTPS:4;
} T2CONbits;
#byte T2CONbits = 0xFCA
#byte T2CON = 0xFCA

#byte SSP1BUF = 0xFC9

#byte SSP1ADD = 0xFC8

struct SSP1STATBITS {
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

struct SSP1CON1BITS {
   unsigned int SSPM0:1;
   unsigned int SSPM1:1;
   unsigned int SSPM2:1;
   unsigned int SSPM3:1;
   unsigned int CKP:1;
   unsigned int SSPEN:1;
   unsigned int SSPOV:1;
   unsigned int WCOL:1;
} SSP1CON1bits;
#byte SSP1CON1bits = 0xFC6
#byte SSP1CON1 = 0xFC6

struct SSP1CON2BITS {
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

#byte ADRESH = 0xFC4

#byte ADRESL = 0xFC3

struct ADCON0BITS {
   unsigned int ADON:1;
   unsigned int GO:1;
   unsigned int CHS:4;
} ADCON0bits;
#byte ADCON0bits = 0xFC2
#byte ADCON0 = 0xFC2

struct ADCON1BITS {
   unsigned int PCFG0:1;
   unsigned int PCFG1:1;
   unsigned int PCFG2:1;
   unsigned int PCFG3:1;
   unsigned int VCFG4:1;
   unsigned int VCFG1:1;
} ADCON1bits;
#byte ADCON1bits = 0xFC1
#byte ADCON1 = 0xFC1

struct ADCON2BITS {
   unsigned int ADCS0:1;
   unsigned int ADCS1:1;
   unsigned int ADCS2:1;
   unsigned int ACQT3:1;
   unsigned int ACQT4:1;
   unsigned int ACQT2:1;
   unsigned int :1;
   unsigned int ADFM:1;
} ADCON2bits;
#byte ADCON2bits = 0xFC0
#byte ADCON2 = 0xFC0

#byte CCPR1H = 0xFBF

#byte CCPR1L = 0xFBE

struct CCP1CONBITS {
   unsigned int CCP1M0:1;
   unsigned int CCP1M1:1;
   unsigned int CCP1M2:1;
   unsigned int CCP1M3:1;
   unsigned int DC1B4:1;
   unsigned int DC1B5:1;
   unsigned int P1M6:1;
   unsigned int P1M1:1;
} CCP1CONbits;
#byte CCP1CONbits = 0xFBD
#byte CCP1CON = 0xFBD

#byte CCPR2H = 0xFBC

#byte CCPR2L = 0xFBB

struct CCP2CONBITS {
   unsigned int CCP2M0:1;
   unsigned int CCP2M1:1;
   unsigned int CCP2M2:1;
   unsigned int CCP2M3:1;
   unsigned int DC2B4:1;
   unsigned int DC2B5:1;
   unsigned int P2M6:1;
   unsigned int P2M1:1;
} CCP2CONbits;
#byte CCP2CONbits = 0xFBA
#byte CCP2CON = 0xFBA

#byte CCPR3H = 0xFB9

#byte CCPR3L = 0xFB8

struct CCP3CONBITS {
   unsigned int CCP3M0:1;
   unsigned int CCP3M1:1;
   unsigned int CCP3M2:1;
   unsigned int CCP3M3:1;
   unsigned int DC3B4:1;
   unsigned int DC3B5:1;
   unsigned int P3M6:1;
   unsigned int P3M1:1;
} CCP3CONbits;
#byte CCP3CONbits = 0xFB7
#byte CCP3CON = 0xFB7

struct ECCP1ASBITS {
   unsigned int PSSBD0:1;
   unsigned int PSSBD1:1;
   unsigned int PSSAC2:1;
   unsigned int PSSAC3:1;
   unsigned int ECCPAS4:1;
   unsigned int ECCPAS5:1;
   unsigned int ECCPAS6:1;
   unsigned int ECCPASE:1;
} ECCP1ASbits;
#byte ECCP1ASbits = 0xFB6
#byte ECCP1AS = 0xFB6

struct CVRCONBITS {
   unsigned int CVR0:1;
   unsigned int CVR1:1;
   unsigned int CVR2:1;
   unsigned int CVR3:1;
   unsigned int CVRSS:1;
   unsigned int CVRR:1;
   unsigned int CVROE:1;
   unsigned int CVREN:1;
} CVRCONbits;
#byte CVRCONbits = 0xFB5
#byte CVRCON = 0xFB5

struct CMCONBITS {
   unsigned int CM0:1;
   unsigned int CM1:1;
   unsigned int CM2:1;
   unsigned int CIS:1;
   unsigned int C1INV:1;
   unsigned int C2INV:1;
   unsigned int C1OUT:1;
   unsigned int C2OUT:1;
} CMCONbits;
#byte CMCONbits = 0xFB4
#byte CMCON = 0xFB4

#byte TMR3H = 0xFB3

#byte TMR3L = 0xFB2

struct T3CONBITS {
   unsigned int TMR3ON:1;
   unsigned int TMR3CS:1;
   unsigned int T3SYNC:1;
   unsigned int T3CCP3:1;
   unsigned int T3CKPS4:1;
   unsigned int T3CKPS5:1;
   unsigned int T3CCP6:1;
   unsigned int RD16:1;
} T3CONbits;
#byte T3CONbits = 0xFB1
#byte T3CON = 0xFB1

#byte SPBRG1 = 0xFAF

#byte RCREG1 = 0xFAE

#byte TXREG1 = 0xFAD

struct TXSTA1BITS {
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

struct RCSTA1BITS {
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

#byte EECON2 = 0xFA7

struct EECON1BITS {
   unsigned int :1;
   unsigned int WR:1;
   unsigned int WREN:1;
   unsigned int WRERR:1;
   unsigned int FREE:1;
} EECON1bits;
#byte EECON1bits = 0xFA6
#byte EECON1 = 0xFA6

struct IPR3BITS {
   unsigned int CCP3IP:1;
   unsigned int CCP4IP:1;
   unsigned int CCP5IP:1;
   unsigned int TMR4IP:1;
   unsigned int TX2IP:1;
   unsigned int RC2IP:1;
} IPR3bits;
#byte IPR3bits = 0xFA5
#byte IPR3 = 0xFA5

struct PIR3BITS {
   unsigned int CCP3IF:1;
   unsigned int CCP4IF:1;
   unsigned int CCP5IF:1;
   unsigned int TMR4IF:1;
   unsigned int TX2IF:1;
   unsigned int RC2IF:1;
} PIR3bits;
#byte PIR3bits = 0xFA4
#byte PIR3 = 0xFA4

struct PIE3BITS {
   unsigned int CCP3IE:1;
   unsigned int CCP4IE:1;
   unsigned int CCP5IE:1;
   unsigned int TMR4IE:1;
   unsigned int TX2IE:1;
   unsigned int RC2IE:1;
} PIE3bits;
#byte PIE3bits = 0xFA3
#byte PIE3 = 0xFA3

struct IPR2BITS {
   unsigned int CCP2IP:1;
   unsigned int TMR3IP:1;
   unsigned int :1;
   unsigned int BCL1IP:1;
   unsigned int WOLIP:1;
   unsigned int ETHIP:1;
   unsigned int CMIP:1;
   unsigned int OSCFIP:1;
} IPR2bits;
#byte IPR2bits = 0xFA2
#byte IPR2 = 0xFA2

struct PIR2BITS {
   unsigned int CCP2IF:1;
   unsigned int TMR3IF:1;
   unsigned int :1;
   unsigned int BCL1IF:1;
   unsigned int WOLIF:1;
   unsigned int ETHIF:1;
   unsigned int CMIF:1;
   unsigned int OSCFIF:1;
} PIR2bits;
#byte PIR2bits = 0xFA1
#byte PIR2 = 0xFA1

struct PIE2BITS {
   unsigned int CCP2IE:1;
   unsigned int TMR3IE:1;
   unsigned int :1;
   unsigned int BCL1IE:1;
   unsigned int WOLIE:1;
   unsigned int ETHIE:1;
   unsigned int CMIE:1;
   unsigned int OSCFIE:1;
} PIE2bits;
#byte PIE2bits = 0xFA0
#byte PIE2 = 0xFA0

struct IPR1BITS {
   unsigned int TMR1IP:1;
   unsigned int TMR2IP:1;
   unsigned int CCP1IP:1;
   unsigned int SSP1IP:1;
   unsigned int TX1IP:1;
   unsigned int RC1IP:1;
   unsigned int ADIP:1;
} IPR1bits;
#byte IPR1bits = 0xF9F
#byte IPR1 = 0xF9F

struct PIR1BITS {
   unsigned int TMR1IF:1;
   unsigned int TMR2IF:1;
   unsigned int CCP1IF:1;
   unsigned int SSP1IF:1;
   unsigned int TX1IF:1;
   unsigned int RC1IF:1;
   unsigned int ADIF:1;
} PIR1bits;
#byte PIR1bits = 0xF9E
#byte PIR1 = 0xF9E

struct PIE1BITS {
   unsigned int TMR1IE:1;
   unsigned int TMR2IE:1;
   unsigned int CCP1IE:1;
   unsigned int SSP1IE:1;
   unsigned int TX1IE:1;
   unsigned int RC1IE:1;
   unsigned int ADIE:1;
} PIE1bits;
#byte PIE1bits = 0xF9D
#byte PIE1 = 0xF9D

struct OSCTUNEBITS {
   unsigned int :4;
   unsigned int PPRE:1;
   unsigned int PPST5:1;
   unsigned int PLLEN:1;
   unsigned int PPST1:1;
} OSCTUNEbits;
#byte OSCTUNEbits = 0xF9B
#byte OSCTUNE = 0xF9B

struct TRISJBITS {
   unsigned int :4;
   unsigned int TRISJ4:1;
   unsigned int TRISJ5:1;
} TRISJbits;
#byte TRISJbits = 0xF9A
#byte TRISJ = 0xF9A

struct TRISHBITS {
   unsigned int TRISH0:1;
   unsigned int TRISH1:1;
   unsigned int TRISH2:1;
   unsigned int TRISH3:1;
   unsigned int TRISH4:1;
   unsigned int TRISH5:1;
   unsigned int TRISH6:1;
   unsigned int TRISH7:1;
} TRISHbits;
#byte TRISHbits = 0xF99
#byte TRISH = 0xF99

struct TRISGBITS {
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

struct TRISFBITS {
   unsigned int :1;
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

struct TRISEBITS {
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

struct TRISDBITS {
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

struct TRISCBITS {
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

struct TRISBBITS {
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

struct TRISABITS {
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

struct LATJBITS {
   unsigned int :4;
   unsigned int LATJ4:1;
   unsigned int LATJ5:1;
} LATJbits;
#byte LATJbits = 0xF91
#byte LATJ = 0xF91

struct LATHBITS {
   unsigned int LATH0:1;
   unsigned int LATH1:1;
   unsigned int LATH2:1;
   unsigned int LATH3:1;
   unsigned int LATH4:1;
   unsigned int LATH5:1;
   unsigned int LATH6:1;
   unsigned int LATH7:1;
} LATHbits;
#byte LATHbits = 0xF90
#byte LATH = 0xF90

struct LATGBITS {
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

struct LATFBITS {
   unsigned int :1;
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

struct LATEBITS {
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

struct LATDBITS {
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

struct LATCBITS {
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

struct LATBBITS {
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

struct LATABITS {
   unsigned int LATA0:1;
   unsigned int LATA1:1;
   unsigned int LATA2:1;
   unsigned int LATA3:1;
   unsigned int LATA4:1;
   unsigned int LATA5:1;
   unsigned int REPU:1;
   unsigned int RDPU:1;
} LATAbits;
#byte LATAbits = 0xF89
#byte LATA = 0xF89

struct PORTJBITS {
   unsigned int :4;
   unsigned int RJ4:1;
   unsigned int RJ5:1;
} PORTJbits;
#byte PORTJbits = 0xF88
#byte PORTJ = 0xF88

struct PORTHBITS {
   unsigned int RH0:1;
   unsigned int RH1:1;
   unsigned int RH2:1;
   unsigned int RH3:1;
   unsigned int RH4:1;
   unsigned int RH5:1;
   unsigned int RH6:1;
   unsigned int RH7:1;
} PORTHbits;
#byte PORTHbits = 0xF87
#byte PORTH = 0xF87

struct PORTGBITS {
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

struct PORTFBITS {
   unsigned int :1;
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

struct PORTEBITS {
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

struct PORTDBITS {
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

struct PORTCBITS {
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

struct PORTBBITS {
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

struct PORTABITS {
   unsigned int RA0:1;
   unsigned int RA1:1;
   unsigned int RA2:1;
   unsigned int RA3:1;
   unsigned int RA4:1;
   unsigned int RA5:1;
   unsigned int :1;
   unsigned int RJPU:1;
} PORTAbits;
#byte PORTAbits = 0xF80
#byte PORTA = 0xF80

#byte SPBRGH1 = 0xF7F

struct BAUDCON1BITS {
   unsigned int ABDEN:1;
   unsigned int WUE:1;
   unsigned int :1;
   unsigned int BRG1:1;
   unsigned int TXCKP:1;
   unsigned int RXDTP:1;
   unsigned int RCIDL:1;
   unsigned int ABDOVF:1;
} BAUDCON1bits;
#byte BAUDCON1bits = 0xF7E
#byte BAUDCON1 = 0xF7E

#byte SPBRGH2 = 0xF7D

struct BAUDCON2BITS {
   unsigned int ABDEN:1;
   unsigned int WUE:1;
   unsigned int :1;
   unsigned int BRG1:1;
   unsigned int TXCKP:1;
   unsigned int RXDTP:1;
   unsigned int RCIDL:1;
   unsigned int ABDOVF:1;
} BAUDCON2bits;
#byte BAUDCON2bits = 0xF7C
#byte BAUDCON2 = 0xF7C

#byte ERDPTH = 0xF7B

#byte ERDPTL = 0xF7A

#word ERDPT = 0xF7A

struct ECCP1DELBITS {
   unsigned int PDC0:1;
   unsigned int PDC1:1;
   unsigned int PDC2:1;
   unsigned int PDC3:1;
   unsigned int PDC4:1;
   unsigned int PDC5:1;
   unsigned int PDC6:1;
   unsigned int PRSEN:1;
} ECCP1DELbits;
#byte ECCP1DELbits = 0xF79
#byte ECCP1DEL = 0xF79

#byte TMR4 = 0xF78

#byte PR4 = 0xF77

struct T4CONBITS {
   unsigned int T4CKPS0:1;
   unsigned int T4CKPS1:1;
   unsigned int TMR4ON:1;
   unsigned int T4OUTPS:4;
} T4CONbits;
#byte T4CONbits = 0xF76
#byte T4CON = 0xF76

#byte CCPR4H = 0xF75

#byte CCPR4L = 0xF74

struct CCP4CONBITS {
   unsigned int CCP4M0:1;
   unsigned int CCP4M1:1;
   unsigned int CCP4M2:1;
   unsigned int CCP4M3:1;
   unsigned int DC4B4:1;
   unsigned int DC4B1:1;
} CCP4CONbits;
#byte CCP4CONbits = 0xF73
#byte CCP4CON = 0xF73

#byte CCPR5H = 0xF72

#byte CCPR5L = 0xF71

struct CCP5CONBITS {
   unsigned int CCP5M0:1;
   unsigned int CCP5M1:1;
   unsigned int CCP5M2:1;
   unsigned int CCP5M3:1;
   unsigned int DC5B4:1;
   unsigned int DC5B1:1;
} CCP5CONbits;
#byte CCP5CONbits = 0xF70
#byte CCP5CON = 0xF70

#byte SPBRG2 = 0xF6F

#byte RCREG2 = 0xF6E

#byte TXREG2 = 0xF6D

struct TXSTA2BITS {
   unsigned int TX9D:1;
   unsigned int TRMT:1;
   unsigned int BRGH:1;
   unsigned int SENDB:1;
   unsigned int SYNC:1;
   unsigned int TXEN:1;
   unsigned int TX:1;
   unsigned int CSRC:1;
} TXSTA2bits;
#byte TXSTA2bits = 0xF6C
#byte TXSTA2 = 0xF6C

struct RCSTA2BITS {
   unsigned int RX9D:1;
   unsigned int OERR:1;
   unsigned int FERR:1;
   unsigned int ADDEN:1;
   unsigned int CREN:1;
   unsigned int SREN:1;
   unsigned int RX:1;
   unsigned int SPEN:1;
} RCSTA2bits;
#byte RCSTA2bits = 0xF6B
#byte RCSTA2 = 0xF6B

struct ECCP3ASBITS {
   unsigned int PSSBD0:1;
   unsigned int PSSBD1:1;
   unsigned int PSSAC2:1;
   unsigned int PSSAC3:1;
   unsigned int ECCPAS4:1;
   unsigned int ECCPAS5:1;
   unsigned int ECCPAS6:1;
   unsigned int ECCPASE:1;
} ECCP3ASbits;
#byte ECCP3ASbits = 0xF6A
#byte ECCP3AS = 0xF6A

struct ECCP3DELBITS {
   unsigned int PDC0:1;
   unsigned int PDC1:1;
   unsigned int PDC2:1;
   unsigned int PDC3:1;
   unsigned int PDC4:1;
   unsigned int PDC5:1;
   unsigned int PDC6:1;
   unsigned int PRSEN:1;
} ECCP3DELbits;
#byte ECCP3DELbits = 0xF69
#byte ECCP3DEL = 0xF69

struct ECCP2ASBITS {
   unsigned int PSSBD0:1;
   unsigned int PSSBD1:1;
   unsigned int PSSAC2:1;
   unsigned int PSSAC3:1;
   unsigned int ECCPAS4:1;
   unsigned int ECCPAS5:1;
   unsigned int ECCPAS6:1;
   unsigned int ECCPASE:1;
} ECCP2ASbits;
#byte ECCP2ASbits = 0xF68
#byte ECCP2AS = 0xF68

struct ECCP2DELBITS {
   unsigned int PDC0:1;
   unsigned int PDC1:1;
   unsigned int PDC2:1;
   unsigned int PDC3:1;
   unsigned int PDC4:1;
   unsigned int PDC5:1;
   unsigned int PDC6:1;
   unsigned int PRSEN:1;
} ECCP2DELbits;
#byte ECCP2DELbits = 0xF67
#byte ECCP2DEL = 0xF67

#byte EDATA = 0xF61

struct EIRBITS {
   unsigned int RXERIF:1;
   unsigned int TXERIF:1;
   unsigned int :1;
   unsigned int TXIF:1;
   unsigned int LINKIF:1;
   unsigned int DMAIF:1;
   unsigned int PKTIF:1;
} EIRbits;
#byte EIRbits = 0xF60
#byte EIR = 0xF60

struct ECON2BITS {
   unsigned int :5;
   unsigned int ETHEN:1;
   unsigned int PKTDEC:1;
   unsigned int AUTOINC:1;
} ECON2bits;
#byte ECON2bits = 0xEFE
#byte ECON2 = 0xEFE

struct ESTATBITS {
   unsigned int PHYRDY:1;
   unsigned int TXABRT:1;
   unsigned int RXBUSY:1;
   unsigned int :1;
   unsigned int LATECOL:1;
   unsigned int :1;
   unsigned int BUFER:1;
} ESTATbits;
#byte ESTATbits = 0xEFD
#byte ESTAT = 0xEFD

struct EIEBITS {
   unsigned int RXERIE:1;
   unsigned int TXERIE:1;
   unsigned int :1;
   unsigned int TXIE:1;
   unsigned int LINKIE:1;
   unsigned int DMAIE:1;
   unsigned int PKTIE:1;
} EIEbits;
#byte EIEbits = 0xEFB
#byte EIE = 0xEFB

#byte EDMACSH = 0xEF7

#byte EDMACSL = 0xEF6

#byte EDMADSTH = 0xEF5

#byte EDMADSTL = 0xEF4

#word EDMADST = 0xEF4

#byte EDMANDH = 0xEF3

#byte EDMANDL = 0xEF2

#word EDMAND = 0xEF2

#byte EDMASTH = 0xEF1

#byte EDMASTL = 0xEF0

#word EDMAST = 0xEF0

#byte ERXWRPTH = 0xEEF

#byte ERXWRPTL = 0xEEE

#word ERXWRPT = 0xEEE

#byte ERXRDPTH = 0xEED

#byte ERXRDPTL = 0xEEC

#word ERXRDPT = 0xEEC

#byte ERXNDH = 0xEEB

#byte ERXNDL = 0xEEA

#word ERXND = 0xEEA

#byte ERXSTH = 0xEE9

#byte ERXSTL = 0xEE8

#word ERXST = 0xEE8

#byte ETXNDH = 0xEE7

#byte ETXNDL = 0xEE6

#word ETXND = 0xEE6

#byte ETXSTH = 0xEE5

#byte ETXSTL = 0xEE4

#word ETXST = 0xEE4

#byte EWRPTH = 0xEE3

#byte EWRPTL = 0xEE2

#word EWRPT = 0xEE2

#byte EPKTCNT = 0xED9

struct ERXFCONBITS {
   unsigned int BCEN:1;
   unsigned int MCEN:1;
   unsigned int HTEN:1;
   unsigned int MPEN:1;
   unsigned int PMEN:1;
   unsigned int CRCEN:1;
   unsigned int ANDOR:1;
   unsigned int UCEN:1;
} ERXFCONbits;
#byte ERXFCONbits = 0xED8
#byte ERXFCON = 0xED8

#byte EPMOH = 0xED5

#byte EPMOL = 0xED4

#byte EPMCSH = 0xED1

#byte EPMCSL = 0xED0

#byte EPMM7 = 0xECF

#byte EPMM6 = 0xECE

#byte EPMM5 = 0xECD

#byte EPMM4 = 0xECC

#byte EPMM3 = 0xECB

#byte EPMM2 = 0xECA

#byte EPMM1 = 0xEC9

#byte EPMM0 = 0xEC8

#byte EHT7 = 0xEC7

#byte EHT6 = 0xEC6

#byte EHT5 = 0xEC5

#byte EHT4 = 0xEC4

#byte EHT3 = 0xEC3

#byte EHT2 = 0xEC2

#byte EHT1 = 0xEC1

#byte EHT0 = 0xEC0

#byte MIRDH = 0xEB9

#byte MIRDL = 0xEB8

#byte MIWRH = 0xEB7

#byte MIWRL = 0xEB6

#byte MIREGADR = 0xEB4

struct MICMDBITS {
   unsigned int MIIRD:1;
   unsigned int MIISCAN:1;
} MICMDbits;
#byte MICMDbits = 0xEB2
#byte MICMD = 0xEB2

struct MICONBITS {
   unsigned int :7;
   unsigned int RSTMII:1;
} MICONbits;
#byte MICONbits = 0xEB1
#byte MICON = 0xEB1

#byte MAMXFLH = 0xEAB

#byte MAMXFLL = 0xEAA

#byte MACLCON2 = 0xEA9

#byte MACLCON1 = 0xEA8

#byte MAIPGH = 0xEA7

#byte MAIPGL = 0xEA6

#byte MABBIPG = 0xEA4

struct MACON4BITS {
   unsigned int :4;
   unsigned int NOBKOFF:1;
   unsigned int BPEN:1;
   unsigned int DEFER:1;
} MACON4bits;
#byte MACON4bits = 0xEA3
#byte MACON4 = 0xEA3

struct MACON3BITS {
   unsigned int FULDPX:1;
   unsigned int FRMLNEN:1;
   unsigned int HFRMEN:1;
   unsigned int PHDREN:1;
   unsigned int TXCRCEN:1;
   unsigned int PADCFG5:1;
   unsigned int PADCFG6:1;
   unsigned int PADCFG2:1;
} MACON3bits;
#byte MACON3bits = 0xEA2
#byte MACON3 = 0xEA2

struct MACON1BITS {
   unsigned int MARXEN:1;
   unsigned int PASSALL:1;
   unsigned int RXPAUS:1;
   unsigned int TXPAUS:1;
} MACON1bits;
#byte MACON1bits = 0xEA0
#byte MACON1 = 0xEA0

#byte EPAUSH = 0xE99

#byte EPAUSL = 0xE98

struct EFLOCONBITS {
   unsigned int FCEN0:1;
   unsigned int FCEN1:1;
   unsigned int FULDPXS:1;
} EFLOCONbits;
#byte EFLOCONbits = 0xE97
#byte EFLOCON = 0xE97

struct MISTATBITS {
   unsigned int BUSY:1;
   unsigned int SCAN:1;
   unsigned int NVALID:1;
   unsigned int LINKFL:1;
} MISTATbits;
#byte MISTATbits = 0xE8A
#byte MISTAT = 0xE8A

#byte MAADR2 = 0xE85

#byte MAADR1 = 0xE84

#byte MAADR4 = 0xE83

#byte MAADR3 = 0xE82

#byte MAADR6 = 0xE81

#byte MAADR5 = 0xE80

