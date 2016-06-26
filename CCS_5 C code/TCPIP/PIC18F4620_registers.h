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
   unsigned int :1;
   unsigned int TMR0IP:1;
   unsigned int :1;
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
   unsigned int :1;
   unsigned int INT1IE:1;
   unsigned int INT2IE:1;
   unsigned int :1;
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
   unsigned int IOFS:1;
   unsigned int OSTS:1;
   unsigned int IRCF4:1;
   unsigned int IRCF5:1;
   unsigned int IRCF6:1;
   unsigned int IDLEN:1;
} OSCCONbits;
#byte OSCCONbits = 0xFD3
#byte OSCCON = 0xFD3

struct HLVDCONBITS {
   unsigned int HLVDL0:1;
   unsigned int HLVDL1:1;
   unsigned int HLVDL2:1;
   unsigned int HLVDL3:1;
   unsigned int HLVDEN:1;
   unsigned int IVRST:1;
   unsigned int :1;
   unsigned int VDIRMAG:1;
} HLVDCONbits;
#byte HLVDCONbits = 0xFD2
#byte HLVDCON = 0xFD2

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
   unsigned int :1;
   unsigned int SBOREN:1;
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

#byte SSPBUF = 0xFC9

#byte SSPADD = 0xFC8

struct SSPSTATBITS {
   unsigned int BF:1;
   unsigned int UA:1;
   unsigned int R:1;
   unsigned int S:1;
   unsigned int P:1;
   unsigned int D:1;
   unsigned int CKE:1;
   unsigned int SMP:1;
} SSPSTATbits;
#byte SSPSTATbits = 0xFC7
#byte SSPSTAT = 0xFC7

struct SSPCON1BITS {
   unsigned int SSPM0:1;
   unsigned int SSPM1:1;
   unsigned int SSPM2:1;
   unsigned int SSPM3:1;
   unsigned int CKP:1;
   unsigned int SSPEN:1;
   unsigned int SSPOV:1;
   unsigned int WCOL:1;
} SSPCON1bits;
#byte SSPCON1bits = 0xFC6
#byte SSPCON1 = 0xFC6

struct SSPCON2BITS {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int ACKSTAT:1;
   unsigned int GCEN:1;
} SSPCON2bits;
#byte SSPCON2bits = 0xFC5
#byte SSPCON2 = 0xFC5

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
   unsigned int DC2B1:1;
} CCP2CONbits;
#byte CCP2CONbits = 0xFBA
#byte CCP2CON = 0xFBA

struct BAUDCONBITS {
   unsigned int ABDEN:1;
   unsigned int WUE:1;
   unsigned int :1;
   unsigned int BRG1:1;
   unsigned int TXCKP:1;
   unsigned int RXDTP:1;
   unsigned int RCIDL:1;
   unsigned int ABDOVF:1;
} BAUDCONbits;
#byte BAUDCONbits = 0xFB8
#byte BAUDCON = 0xFB8

struct PWM1CONBITS {
   unsigned int PDC0:1;
   unsigned int PDC1:1;
   unsigned int PDC2:1;
   unsigned int PDC3:1;
   unsigned int PDC4:1;
   unsigned int PDC5:1;
   unsigned int PDC6:1;
   unsigned int PRSEN:1;
} PWM1CONbits;
#byte PWM1CONbits = 0xFB7
#byte PWM1CON = 0xFB7

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

#byte SPBRGH = 0xFB0

#byte SPBRG = 0xFAF

#byte RCREG = 0xFAE

#byte TXREG = 0xFAD

struct TXSTABITS {
   unsigned int TX9D:1;
   unsigned int TRMT:1;
   unsigned int BRGH:1;
   unsigned int SENDB:1;
   unsigned int SYNC:1;
   unsigned int TXEN:1;
   unsigned int TX:1;
   unsigned int CSRC:1;
} TXSTAbits;
#byte TXSTAbits = 0xFAC
#byte TXSTA = 0xFAC

struct RCSTABITS {
   unsigned int RX9D:1;
   unsigned int OERR:1;
   unsigned int FERR:1;
   unsigned int ADDEN:1;
   unsigned int CREN:1;
   unsigned int SREN:1;
   unsigned int RX:1;
   unsigned int SPEN:1;
} RCSTAbits;
#byte RCSTAbits = 0xFAB
#byte RCSTA = 0xFAB

#byte EEADRH = 0xFAA

#byte EEADR = 0xFA9

#byte EEDATA = 0xFA8

#byte EECON2 = 0xFA7

struct EECON1BITS {
   unsigned int RD:1;
   unsigned int WR:1;
   unsigned int WREN:1;
   unsigned int WRERR:1;
   unsigned int FREE:1;
   unsigned int :1;
   unsigned int CFGS:1;
   unsigned int EEPGD:1;
} EECON1bits;
#byte EECON1bits = 0xFA6
#byte EECON1 = 0xFA6

struct IPR2BITS {
   unsigned int CCP2IP:1;
   unsigned int TMR3IP:1;
   unsigned int HLVDIP:1;
   unsigned int BCLIP:1;
   unsigned int EEIP:1;
   unsigned int :1;
   unsigned int CMIP:1;
   unsigned int OSCFIP:1;
} IPR2bits;
#byte IPR2bits = 0xFA2
#byte IPR2 = 0xFA2

struct PIR2BITS {
   unsigned int CCP2IF:1;
   unsigned int TMR3IF:1;
   unsigned int HLVDIF:1;
   unsigned int BCLIF:1;
   unsigned int EEIF:1;
   unsigned int :1;
   unsigned int CMIF:1;
   unsigned int OSCFIF:1;
} PIR2bits;
#byte PIR2bits = 0xFA1
#byte PIR2 = 0xFA1

struct PIE2BITS {
   unsigned int CCP2IE:1;
   unsigned int TMR3IE:1;
   unsigned int HLVDIE:1;
   unsigned int BCLIE:1;
   unsigned int EEIE:1;
   unsigned int :1;
   unsigned int CMIE:1;
   unsigned int OSCFIE:1;
} PIE2bits;
#byte PIE2bits = 0xFA0
#byte PIE2 = 0xFA0

struct IPR1BITS {
   unsigned int TMR1IP:1;
   unsigned int TMR2IP:1;
   unsigned int CCP1IP:1;
   unsigned int SSPIP:1;
   unsigned int TXIP:1;
   unsigned int RCIP:1;
   unsigned int ADIP:1;
   unsigned int PSPIP:1;
} IPR1bits;
#byte IPR1bits = 0xF9F
#byte IPR1 = 0xF9F

struct PIR1BITS {
   unsigned int TMR1IF:1;
   unsigned int TMR2IF:1;
   unsigned int CCP1IF:1;
   unsigned int SSPIF:1;
   unsigned int TXIF:1;
   unsigned int RCIF:1;
   unsigned int ADIF:1;
   unsigned int PSPIF:1;
} PIR1bits;
#byte PIR1bits = 0xF9E
#byte PIR1 = 0xF9E

struct PIE1BITS {
   unsigned int TMR1IE:1;
   unsigned int TMR2IE:1;
   unsigned int CCP1IE:1;
   unsigned int SSPIE:1;
   unsigned int TXIE:1;
   unsigned int RCIE:1;
   unsigned int ADIE:1;
   unsigned int PSPIE:1;
} PIE1bits;
#byte PIE1bits = 0xF9D
#byte PIE1 = 0xF9D

struct OSCTUNEBITS {
   unsigned int TUN0:1;
   unsigned int TUN1:1;
   unsigned int TUN2:1;
   unsigned int TUN3:1;
   unsigned int TUN4:1;
   unsigned int :1;
   unsigned int PLLEN:1;
   unsigned int INTSRC:1;
} OSCTUNEbits;
#byte OSCTUNEbits = 0xF9B
#byte OSCTUNE = 0xF9B

struct TRISEBITS {
   unsigned int TRISE0:1;
   unsigned int TRISE1:1;
   unsigned int TRISE2:1;
   unsigned int :1;
   unsigned int PSPMODE:1;
   unsigned int IBOV:1;
   unsigned int OBF:1;
   unsigned int IBF:1;
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
   unsigned int LATA6:1;
   unsigned int LATA7:1;
} LATAbits;
#byte LATAbits = 0xF89
#byte LATA = 0xF89

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
   unsigned int RA6:1;
   unsigned int RA7:1;
} PORTAbits;
#byte PORTAbits = 0xF80
#byte PORTA = 0xF80

