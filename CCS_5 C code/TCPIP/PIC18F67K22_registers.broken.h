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

#byte SPBRGH1 = 0xFD4

struct OSCCONBITS {
   unsigned int SCS0:1;
   unsigned int SCS1:1;
   unsigned int HFIOFS:1;
   unsigned int OSTS:1;
   unsigned int IRCF4:1;
   unsigned int IRCF5:1;
   unsigned int IRCF6:1;
   unsigned int IDLEN:1;
} OSCCONbits;
#byte OSCCONbits = 0xFD3
#byte OSCCON = 0xFD3

struct IPR5BITS {
   unsigned int TMR4IP:1;
   unsigned int TMR5IP:1;
   unsigned int TMR6IP:1;
   unsigned int TMR7IP:1;
   unsigned int TMR8IP:1;
   unsigned int TMR10IP:1;
   unsigned int TMR12IP:1;
   unsigned int TMR7GIP:1;
} IPR5bits;
#byte IPR5bits = 0xFD2
#byte IPR5 = 0xFD2

struct WDTCONBITS {
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

struct RCONBITS {
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

#byte TMR1H = 0xFCF

#byte TMR1L = 0xFCE

struct T1CONBITS {
   unsigned int TMR1ON:1;
   unsigned int RD1:1;
   unsigned int T1SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T1CKPS4:1;
   unsigned int T1CKPS5:1;
   unsigned int TMR1CS6:1;
   unsigned int TMR1CS1:1;
} T1CONbits;
#byte T1CONbits = 0xFCD
#byte T1CON = 0xFCD

#byte TMR2 = 0xFCC

#byte PR2 = 0xFCB

struct T2CONBITS {
   unsigned int T2CKPS0:1;
   unsigned int T2CKPS1:1;
   unsigned int TMR2ON:1;
   unsigned int T2OUTPS3:1;
   unsigned int T2OUTPS4:1;
   unsigned int T2OUTPS5:1;
   unsigned int T2OUTPS3:1;
} T2CONbits;
#byte T2CONbits = 0xFCA
#byte T2CON = 0xFCA

#byte SSP1BUF = 0xFC9

#byte SSP1MSK = 0xFC8

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
   unsigned int CHS2:1;
   unsigned int CHS3:1;
   unsigned int CHS4:1;
   unsigned int CHS5:1;
   unsigned int CHS4:1;
} ADCON0bits;
#byte ADCON0bits = 0xFC2
#byte ADCON0 = 0xFC2

struct ADCON1BITS {
   unsigned int CHSN0:1;
   unsigned int CHSN1:1;
   unsigned int CHSN2:1;
   unsigned int VNCFG:1;
   unsigned int VCFG4:1;
   unsigned int VCFG5:1;
   unsigned int TRIGSEL6:1;
   unsigned int TRIGSEL1:1;
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

struct ECCP1ASBITS {
   unsigned int PSS1BD0:1;
   unsigned int PSS1BD1:1;
   unsigned int PSS1AC2:1;
   unsigned int PSS1AC3:1;
   unsigned int ECCP1AS4:1;
   unsigned int ECCP1AS5:1;
   unsigned int ECCP1AS6:1;
   unsigned int ECCP1ASE:1;
} ECCP1ASbits;
#byte ECCP1ASbits = 0xFBF
#byte ECCP1AS = 0xFBF

struct ECCP1DELBITS {
   unsigned int P1DC0:1;
   unsigned int P1DC1:1;
   unsigned int P1DC2:1;
   unsigned int P1DC3:1;
   unsigned int P1DC4:1;
   unsigned int P1DC5:1;
   unsigned int P1DC6:1;
   unsigned int P1RSEN:1;
} ECCP1DELbits;
#byte ECCP1DELbits = 0xFBE
#byte ECCP1DEL = 0xFBE

#byte CCPR1H = 0xFBD

#byte CCPR1L = 0xFBC

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
#byte CCP1CONbits = 0xFBB
#byte CCP1CON = 0xFBB

struct PIR5BITS {
   unsigned int TMR4IF:1;
   unsigned int TMR5IF:1;
   unsigned int TMR6IF:1;
   unsigned int TMR7IF:1;
   unsigned int TMR8IF:1;
   unsigned int TMR10IF:1;
   unsigned int TMR12IF:1;
   unsigned int TMR7GIF:1;
} PIR5bits;
#byte PIR5bits = 0xFBA
#byte PIR5 = 0xFBA

struct PIE5BITS {
   unsigned int TMR4IE:1;
   unsigned int TMR5IE:1;
   unsigned int TMR6IE:1;
   unsigned int TMR7IE:1;
   unsigned int TMR8IE:1;
   unsigned int TMR10IE:1;
   unsigned int TMR12IE:1;
   unsigned int TMR7GIE:1;
} PIE5bits;
#byte PIE5bits = 0xFB9
#byte PIE5 = 0xFB9

struct IPR4BITS {
   unsigned int CCP3IP:1;
   unsigned int CCP4IP:1;
   unsigned int CCP5IP:1;
   unsigned int CCP6IP:1;
   unsigned int CCP7IP:1;
   unsigned int CCP8IP:1;
   unsigned int CCP9IP:1;
   unsigned int CCP10IP:1;
} IPR4bits;
#byte IPR4bits = 0xFB8
#byte IPR4 = 0xFB8

struct PIR4BITS {
   unsigned int CCP3IF:1;
   unsigned int CCP4IF:1;
   unsigned int CCP5IF:1;
   unsigned int CCP6IF:1;
   unsigned int CCP7IF:1;
   unsigned int CCP8IF:1;
   unsigned int CCP9IF:1;
   unsigned int CCP10IF:1;
} PIR4bits;
#byte PIR4bits = 0xFB7
#byte PIR4 = 0xFB7

struct PIE4BITS {
   unsigned int CCP3IE:1;
   unsigned int CCP4IE:1;
   unsigned int CCP5IE:1;
   unsigned int CCP6IE:1;
   unsigned int CCP7IE:1;
   unsigned int CCP8IE:1;
   unsigned int CCP9IE:1;
   unsigned int CCP10IE:1;
} PIE4bits;
#byte PIE4bits = 0xFB6
#byte PIE4 = 0xFB6

struct CVRCONBITS {
   unsigned int CVR0:1;
   unsigned int CVR1:1;
   unsigned int CVR2:1;
   unsigned int CVR3:1;
   unsigned int CVR4:1;
   unsigned int CVRSS:1;
   unsigned int CVROE:1;
   unsigned int CVREN:1;
} CVRCONbits;
#byte CVRCONbits = 0xFB5
#byte CVRCON = 0xFB5

struct CMSTATBITS {
   unsigned int :5;
   unsigned int CMP1OUT:1;
   unsigned int CMP2OUT:1;
   unsigned int CMP3OUT:1;
} CMSTATbits;
#byte CMSTATbits = 0xFB4
#byte CMSTAT = 0xFB4

#byte TMR3H = 0xFB3

#byte TMR3L = 0xFB2

struct T3CONBITS {
   unsigned int TMR3ON:1;
   unsigned int RD1:1;
   unsigned int T3SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T3CKPS4:1;
   unsigned int T3CKPS5:1;
   unsigned int TMR3CS6:1;
   unsigned int TMR3CS1:1;
} T3CONbits;
#byte T3CONbits = 0xFB1
#byte T3CON = 0xFB1

struct T3GCONBITS {
   unsigned int T3GSS0:1;
   unsigned int T3GSS1:1;
   unsigned int T3GVAL:1;
   unsigned int T3GGO:1;
   unsigned int T3GSPM:1;
   unsigned int T3GTM:1;
   unsigned int T3GPOL:1;
   unsigned int TMR3GE:1;
} T3GCONbits;
#byte T3GCONbits = 0xFB0
#byte T3GCON = 0xFB0

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

struct T1GCONBITS {
   unsigned int T1GSS0:1;
   unsigned int T1GSS1:1;
   unsigned int T1GVAL:1;
   unsigned int T1GGO:1;
   unsigned int T1GSPM:1;
   unsigned int T1GTM:1;
   unsigned int T1GPOL:1;
   unsigned int TMR1GE:1;
} T1GCONbits;
#byte T1GCONbits = 0xFAA
#byte T1GCON = 0xFAA

struct IPR6BITS {
   unsigned int CMP1IP:1;
   unsigned int CMP2IP:1;
   unsigned int CMP3IP:1;
   unsigned int :1;
   unsigned int EEIP:1;
} IPR6bits;
#byte IPR6bits = 0xFA9
#byte IPR6 = 0xFA9

struct HLVDCONBITS {
   unsigned int HLVDL0:1;
   unsigned int HLVDL1:1;
   unsigned int HLVDL2:1;
   unsigned int HLVDL3:1;
   unsigned int HLVDEN:1;
   unsigned int IRVST:1;
   unsigned int BGVST:1;
   unsigned int VDIRMAG:1;
} HLVDCONbits;
#byte HLVDCONbits = 0xFA8
#byte HLVDCON = 0xFA8

struct PSPCONBITS {
   unsigned int :4;
   unsigned int PSPMODE:1;
   unsigned int IBOV:1;
   unsigned int OBF:1;
   unsigned int IBF:1;
} PSPCONbits;
#byte PSPCONbits = 0xFA7
#byte PSPCON = 0xFA7

struct PIR6BITS {
   unsigned int CMP1IF:1;
   unsigned int CMP2IF:1;
   unsigned int CMP3IF:1;
   unsigned int :1;
   unsigned int EEIF:1;
} PIR6bits;
#byte PIR6bits = 0xFA6
#byte PIR6 = 0xFA6

struct IPR3BITS {
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

struct PIR3BITS {
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

struct PIE3BITS {
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

struct IPR2BITS {
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

struct PIE2BITS {
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

struct IPR1BITS {
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

struct PIR1BITS {
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

struct PIE1BITS {
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

struct PSTR1CONBITS {
   unsigned int STRA:1;
   unsigned int STRB:1;
   unsigned int STRC:1;
   unsigned int STRD:1;
   unsigned int STRSYNC:1;
   unsigned int :1;
   unsigned int CMPL6:1;
   unsigned int CMPL1:1;
} PSTR1CONbits;
#byte PSTR1CONbits = 0xF9C
#byte PSTR1CON = 0xF9C

struct OSCTUNEBITS {
   unsigned int TUN0:1;
   unsigned int TUN1:1;
   unsigned int TUN2:1;
   unsigned int TUN3:1;
   unsigned int TUN4:1;
   unsigned int TUN5:1;
   unsigned int PLLEN:1;
   unsigned int INTSRC:1;
} OSCTUNEbits;
#byte OSCTUNEbits = 0xF9B
#byte OSCTUNE = 0xF9B

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
#byte TRISG = 0xF98
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
#byte TRISE = 0xF96
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
#byte TRISD = 0xF95
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
#byte TRISC = 0xF94
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
#byte TRISB = 0xF93
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
#byte TRISA = 0xF92
#byte TRISA = 0xF92

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
#byte LATG = 0xF8F
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
#byte LATE = 0xF8D
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
#byte LATD = 0xF8C
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
#byte LATC = 0xF8B
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
#byte LATB = 0xF8A
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
#byte LATA = 0xF89
#byte LATA = 0xF89

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
#byte PORTG = 0xF86
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
#byte PORTE = 0xF84
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
#byte PORTD = 0xF83
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
#byte PORTC = 0xF82
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
#byte PORTB = 0xF81
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
#byte PORTA = 0xF80
#byte PORTA = 0xF80

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
#byte EECON1bits = 0xF7F
#byte EECON1 = 0xF7F

#byte EECON2 = 0xF7E

#byte TMR5H = 0xF7D

#byte TMR5L = 0xF7C

struct T5CONBITS {
   unsigned int TMR5ON:1;
   unsigned int RD1:1;
   unsigned int T5SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T5CKPS4:1;
   unsigned int T5CKPS5:1;
   unsigned int TMR5CS6:1;
   unsigned int TMR5CS1:1;
} T5CONbits;
#byte T5CONbits = 0xF7B
#byte T5CON = 0xF7B

struct T5GCONBITS {
   unsigned int T5GSS0:1;
   unsigned int T5GSS1:1;
   unsigned int T5GVAL:1;
   unsigned int T5GGO:1;
   unsigned int T5GSPM:1;
   unsigned int T5GTM:1;
   unsigned int T5GPOL:1;
   unsigned int TMR5GE:1;
} T5GCONbits;
#byte T5GCONbits = 0xF7A
#byte T5GCON = 0xF7A

#byte CCPR4H = 0xF79

#byte CCPR4L = 0xF78

struct CCP4CONBITS {
   unsigned int CCP4M0:1;
   unsigned int CCP4M1:1;
   unsigned int CCP4M2:1;
   unsigned int CCP4M3:1;
   unsigned int DC4B4:1;
   unsigned int DC4B1:1;
} CCP4CONbits;
#byte CCP4CONbits = 0xF77
#byte CCP4CON = 0xF77

#byte CCPR5H = 0xF76

#byte CCPR5L = 0xF75

struct CCP5CONBITS {
   unsigned int CCP5M0:1;
   unsigned int CCP5M1:1;
   unsigned int CCP5M2:1;
   unsigned int CCP5M3:1;
   unsigned int DC5B4:1;
   unsigned int DC5B1:1;
} CCP5CONbits;
#byte CCP5CONbits = 0xF74
#byte CCP5CON = 0xF74

#byte CCPR6H = 0xF73

#byte CCPR6L = 0xF72

struct CCP6CONBITS {
   unsigned int CCP6M0:1;
   unsigned int CCP6M1:1;
   unsigned int CCP6M2:1;
   unsigned int CCP6M3:1;
   unsigned int DC6B4:1;
   unsigned int DC6B1:1;
} CCP6CONbits;
#byte CCP6CONbits = 0xF71
#byte CCP6CON = 0xF71

#byte CCPR7H = 0xF70

#byte CCPR7L = 0xF6F

struct CCP7CONBITS {
   unsigned int CCP7M0:1;
   unsigned int CCP7M1:1;
   unsigned int CCP7M2:1;
   unsigned int CCP7M3:1;
   unsigned int DC7B4:1;
   unsigned int DC7B1:1;
} CCP7CONbits;
#byte CCP7CONbits = 0xF6E
#byte CCP7CON = 0xF6E

#byte TMR4 = 0xF6D

#byte PR4 = 0xF6C

struct T4CONBITS {
   unsigned int T4CKPS0:1;
   unsigned int T4CKPS1:1;
   unsigned int TMR4ON:1;
   unsigned int T4OUTPS3:1;
   unsigned int T4OUTPS4:1;
   unsigned int T4OUTPS5:1;
   unsigned int T4OUTPS3:1;
} T4CONbits;
#byte T4CONbits = 0xF6B
#byte T4CON = 0xF6B

#byte SSP2BUF = 0xF6A

#byte SSP2MSK = 0xF69

#byte SSP2ADD = 0xF69

struct SSP2STATBITS {
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

struct SSP2CON1BITS {
   unsigned int SSPM0:1;
   unsigned int SSPM1:1;
   unsigned int SSPM2:1;
   unsigned int SSPM3:1;
   unsigned int CKP:1;
   unsigned int SSPEN:1;
   unsigned int SSPOV:1;
   unsigned int WCOL:1;
} SSP2CON1bits;
#byte SSP2CON1bits = 0xF67
#byte SSP2CON1 = 0xF67

struct SSP2CON2BITS {
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

struct BAUDCON1BITS {
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

struct OSCCON2BITS {
   unsigned int MFIOSEL:1;
   unsigned int MFIOFS:1;
   unsigned int :1;
   unsigned int SOSCGO:1;
   unsigned int :2;
   unsigned int SOSCRUN:1;
} OSCCON2bits;
#byte OSCCON2bits = 0xF64
#byte OSCCON2 = 0xF64

#byte EEADRH = 0xF63

#byte EEADR = 0xF62

#byte EEDATA = 0xF61

struct PIE6BITS {
   unsigned int CMP1IE:1;
   unsigned int CMP2IE:1;
   unsigned int CMP3IE:1;
   unsigned int :1;
   unsigned int EEIE:1;
} PIE6bits;
#byte PIE6bits = 0xF60
#byte PIE6 = 0xF60

struct RTCCFGBITS {
   unsigned int RTCPTR0:1;
   unsigned int RTCPTR1:1;
   unsigned int RTCOE:1;
   unsigned int HALFSEC:1;
   unsigned int RTCSYNC:1;
   unsigned int RTCWREN:1;
   unsigned int :1;
   unsigned int RTCEN:1;
} RTCCFGbits;
#byte RTCCFGbits = 0xF5F
#byte RTCCFG = 0xF5F

#byte RTCCAL = 0xF5E

#byte RTCVALH = 0xF5D

#byte RTCVALL = 0xF5C

struct ALRMCFGBITS {
   unsigned int ALRMPTR0:1;
   unsigned int ALRMPTR1:1;
   unsigned int AMASK2:1;
   unsigned int AMASK3:1;
   unsigned int AMASK4:1;
   unsigned int AMASK5:1;
   unsigned int CHIME:1;
   unsigned int ALRMEN:1;
} ALRMCFGbits;
#byte ALRMCFGbits = 0xF5B
#byte ALRMCFG = 0xF5B

#byte ALRMRPT = 0xF5A

#byte ALRMVALH = 0xF59

#byte ALRMVALL = 0xF58

struct CTMUCONHBITS {
   unsigned int CTTRIG:1;
   unsigned int IDISSEN:1;
   unsigned int EDGSEQEN:1;
   unsigned int EDGEN:1;
   unsigned int TGEN:1;
   unsigned int CTMUSIDL:1;
   unsigned int :1;
   unsigned int CTMUEN:1;
} CTMUCONHbits;
#byte CTMUCONHbits = 0xF57
#byte CTMUCONH = 0xF57

struct CTMUCONLBITS {
   unsigned int EDG1STAT:1;
   unsigned int EDG2STAT:1;
   unsigned int EDG1SEL2:1;
   unsigned int EDG1SEL3:1;
   unsigned int EDG1POL:1;
   unsigned int EDG2SEL5:1;
   unsigned int EDG2SEL6:1;
   unsigned int EDG2POL:1;
} CTMUCONLbits;
#byte CTMUCONLbits = 0xF56
#byte CTMUCONL = 0xF56

struct CTMUICONBITS {
   unsigned int IRNG0:1;
   unsigned int IRNG1:1;
   unsigned int ITRIM2:1;
   unsigned int ITRIM3:1;
   unsigned int ITRIM4:1;
   unsigned int ITRIM5:1;
   unsigned int ITRIM6:1;
   unsigned int ITRIM5:1;
} CTMUICONbits;
#byte CTMUICONbits = 0xF55
#byte CTMUICON = 0xF55

struct CM1CONBITS {
   unsigned int CCH0:1;
   unsigned int CCH1:1;
   unsigned int CREF:1;
   unsigned int EVPOL3:1;
   unsigned int EVPOL4:1;
   unsigned int CPOL:1;
   unsigned int COE:1;
   unsigned int CON:1;
} CM1CONbits;
#byte CM1CONbits = 0xF54
#byte CM1CON = 0xF54

struct PADCFG1BITS {
   unsigned int :1;
   unsigned int RTSECSEL1:1;
   unsigned int RTSECSEL1:1;
   unsigned int :3;
   unsigned int REPU:1;
   unsigned int RDPU:1;
} PADCFG1bits;
#byte PADCFG1bits = 0xF53
#byte PADCFG1 = 0xF53

struct ECCP2ASBITS {
   unsigned int PSS2BD0:1;
   unsigned int PSS2BD1:1;
   unsigned int PSS2AC2:1;
   unsigned int PSS2AC3:1;
   unsigned int ECCP2AS4:1;
   unsigned int ECCP2AS5:1;
   unsigned int ECCP2AS6:1;
   unsigned int ECCP2ASE:1;
} ECCP2ASbits;
#byte ECCP2ASbits = 0xF52
#byte ECCP2AS = 0xF52

struct ECCP2DELBITS {
   unsigned int P2DC0:1;
   unsigned int P2DC1:1;
   unsigned int P2DC2:1;
   unsigned int P2DC3:1;
   unsigned int P2DC4:1;
   unsigned int P2DC5:1;
   unsigned int P2DC6:1;
   unsigned int P2RSEN:1;
} ECCP2DELbits;
#byte ECCP2DELbits = 0xF51
#byte ECCP2DEL = 0xF51

#byte CCPR2H = 0xF50

#byte CCPR2L = 0xF4F

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
#byte CCP2CONbits = 0xF4E
#byte CCP2CON = 0xF4E

struct ECCP3ASBITS {
   unsigned int PSS3BD0:1;
   unsigned int PSS3BD1:1;
   unsigned int PSS3AC2:1;
   unsigned int PSS3AC3:1;
   unsigned int ECCP3AS4:1;
   unsigned int ECCP3AS5:1;
   unsigned int ECCP3AS6:1;
   unsigned int ECCP3ASE:1;
} ECCP3ASbits;
#byte ECCP3ASbits = 0xF4D
#byte ECCP3AS = 0xF4D

struct ECCP3DELBITS {
   unsigned int P3DC0:1;
   unsigned int P3DC1:1;
   unsigned int P3DC2:1;
   unsigned int P3DC3:1;
   unsigned int P3DC4:1;
   unsigned int P3DC5:1;
   unsigned int P3DC6:1;
   unsigned int P3RSEN:1;
} ECCP3DELbits;
#byte ECCP3DELbits = 0xF4C
#byte ECCP3DEL = 0xF4C

#byte CCPR3H = 0xF4B

#byte CCPR3L = 0xF4A

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
#byte CCP3CONbits = 0xF49
#byte CCP3CON = 0xF49

#byte CCPR8H = 0xF48

#byte CCPR8L = 0xF47

struct CCP8CONBITS {
   unsigned int CCP8M0:1;
   unsigned int CCP8M1:1;
   unsigned int CCP8M2:1;
   unsigned int CCP8M3:1;
   unsigned int DC8B4:1;
   unsigned int DC8B1:1;
} CCP8CONbits;
#byte CCP8CONbits = 0xF46
#byte CCP8CON = 0xF46

#byte CCPR9H = 0xF45

#byte CCPR9L = 0xF44

struct CCP9CONBITS {
   unsigned int CCP9M0:1;
   unsigned int CCP9M1:1;
   unsigned int CCP9M2:1;
   unsigned int CCP9M3:1;
   unsigned int DC9B4:1;
   unsigned int DC9B1:1;
} CCP9CONbits;
#byte CCP9CONbits = 0xF43
#byte CCP9CON = 0xF43

#byte CCPR10H = 0xF42

#byte CCPR10L = 0xF41

struct CCP10CONBITS {
   unsigned int CCP10M0:1;
   unsigned int CCP10M1:1;
   unsigned int CCP10M2:1;
   unsigned int CCP10M3:1;
   unsigned int DC10B4:1;
   unsigned int DC10B1:1;
} CCP10CONbits;
#byte CCP10CONbits = 0xF40
#byte CCP10CON = 0xF40

#byte TMR7H = 0xF3F

#byte TMR7L = 0xF3E

struct T7CONBITS {
   unsigned int TMR7ON:1;
   unsigned int RD1:1;
   unsigned int T7SYNC:1;
   unsigned int SOSCEN:1;
   unsigned int T7CKPS4:1;
   unsigned int T7CKPS5:1;
   unsigned int TMR7CS6:1;
   unsigned int TMR7CS1:1;
} T7CONbits;
#byte T7CONbits = 0xF3D
#byte T7CON = 0xF3D

struct T7GCONBITS {
   unsigned int T7GSS0:1;
   unsigned int T7GSS1:1;
   unsigned int T7GVAL:1;
   unsigned int T7GGO:1;
   unsigned int T7GSPM:1;
   unsigned int T7GTM:1;
   unsigned int T7GPOL:1;
   unsigned int TMR7GE:1;
} T7GCONbits;
#byte T7GCONbits = 0xF3C
#byte T7GCON = 0xF3C

#byte TMR6 = 0xF3B

#byte PR6 = 0xF3A

struct T6CONBITS {
   unsigned int T6CKPS0:1;
   unsigned int T6CKPS1:1;
   unsigned int TMR6ON:1;
   unsigned int T6OUTPS3:1;
   unsigned int T6OUTPS4:1;
   unsigned int T6OUTPS5:1;
   unsigned int T6OUTPS3:1;
} T6CONbits;
#byte T6CONbits = 0xF39
#byte T6CON = 0xF39

#byte TMR8 = 0xF38

#byte PR8 = 0xF37

struct T8CONBITS {
   unsigned int T8CKPS0:1;
   unsigned int T8CKPS1:1;
   unsigned int TMR8ON:1;
   unsigned int T8OUTPS3:1;
   unsigned int T8OUTPS4:1;
   unsigned int T8OUTPS5:1;
   unsigned int T8OUTPS3:1;
} T8CONbits;
#byte T8CONbits = 0xF36
#byte T8CON = 0xF36

#byte TMR10 = 0xF35

#byte PR10 = 0xF34

struct T10CONBITS {
   unsigned int T10CKPS0:1;
   unsigned int T10CKPS1:1;
   unsigned int TMR10ON:1;
   unsigned int T10OUTPS3:1;
   unsigned int T10OUTPS4:1;
   unsigned int T10OUTPS5:1;
   unsigned int T10OUTPS3:1;
} T10CONbits;
#byte T10CONbits = 0xF33
#byte T10CON = 0xF33

#byte TMR12 = 0xF32

#byte PR12 = 0xF31

struct T12CONBITS {
   unsigned int T12CKPS0:1;
   unsigned int T12CKPS1:1;
   unsigned int TMR12ON:1;
   unsigned int T12OUTPS3:1;
   unsigned int T12OUTPS4:1;
   unsigned int T12OUTPS5:1;
   unsigned int T12OUTPS3:1;
} T12CONbits;
#byte T12CONbits = 0xF30
#byte T12CON = 0xF30

struct CM2CONBITS {
   unsigned int CCH0:1;
   unsigned int CCH1:1;
   unsigned int CREF:1;
   unsigned int EVPOL3:1;
   unsigned int EVPOL4:1;
   unsigned int CPOL:1;
   unsigned int COE:1;
   unsigned int CON:1;
} CM2CONbits;
#byte CM2CONbits = 0xF2F
#byte CM2CON = 0xF2F

struct CM3CONBITS {
   unsigned int CCH0:1;
   unsigned int CCH1:1;
   unsigned int CREF:1;
   unsigned int EVPOL3:1;
   unsigned int EVPOL4:1;
   unsigned int CPOL:1;
   unsigned int COE:1;
   unsigned int CON:1;
} CM3CONbits;
#byte CM3CONbits = 0xF2E
#byte CM3CON = 0xF2E

struct CCPTMRS0BITS {
   unsigned int C1TSEL0:1;
   unsigned int C1TSEL1:1;
   unsigned int C1TSEL2:1;
   unsigned int C2TSEL3:1;
   unsigned int C2TSEL4:1;
   unsigned int C2TSEL5:1;
   unsigned int C3TSEL6:1;
   unsigned int C3TSEL1:1;
} CCPTMRS0bits;
#byte CCPTMRS0bits = 0xF2D
#byte CCPTMRS0 = 0xF2D

struct CCPTMRS1BITS {
   unsigned int C4TSEL0:1;
   unsigned int C4TSEL1:1;
   unsigned int C5TSEL0:1;
   unsigned int :1;
   unsigned int C6TSEL0:1;
   unsigned int :1;
   unsigned int C7TSEL6:1;
   unsigned int C7TSEL1:1;
} CCPTMRS1bits;
#byte CCPTMRS1bits = 0xF2C
#byte CCPTMRS1 = 0xF2C

struct CCPTMRS2BITS {
   unsigned int C8TSEL0:1;
   unsigned int C8TSEL1:1;
   unsigned int C9TSEL0:1;
   unsigned int :1;
   unsigned int C10TSEL0:1;
} CCPTMRS2bits;
#byte CCPTMRS2bits = 0xF2B
#byte CCPTMRS2 = 0xF2B

struct REFOCONBITS {
   unsigned int RODIV0:1;
   unsigned int RODIV1:1;
   unsigned int RODIV2:1;
   unsigned int RODIV3:1;
   unsigned int ROSEL:1;
   unsigned int ROSSLP:1;
   unsigned int :1;
   unsigned int ROON:1;
} REFOCONbits;
#byte REFOCONbits = 0xF2A
#byte REFOCON = 0xF2A

struct ODCON1BITS {
   unsigned int SPI2OD:1;
   unsigned int :4;
   unsigned int CCP1OD:1;
   unsigned int CCP2OD:1;
   unsigned int SPI1OD:1;
} ODCON1bits;
#byte ODCON1bits = 0xF29
#byte ODCON1 = 0xF29

struct ODCON2BITS {
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

struct ODCON3BITS {
   unsigned int CTMUDS:1;
   unsigned int :5;
   unsigned int U1OD:1;
   unsigned int U2OD:1;
} ODCON3bits;
#byte ODCON3bits = 0xF27
#byte ODCON3 = 0xF27

#byte ANCON0 = 0xF25

struct ANCON1BITS {
   unsigned int ANSEL0:1;
   unsigned int ANSEL1:1;
   unsigned int ANSEL1:2;
} ANCON1bits;
#byte ANCON1bits = 0xF24
#byte ANCON1 = 0xF24

struct ANCON2BITS {
   unsigned int ANSEL1:4;
} ANCON2bits;
#byte ANCON2bits = 0xF23
#byte ANCON2 = 0xF23

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
#byte RCSTA2bits = 0xF22
#byte RCSTA2 = 0xF22

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
#byte TXSTA2bits = 0xF21
#byte TXSTA2 = 0xF21

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
#byte BAUDCON2bits = 0xF20
#byte BAUDCON2 = 0xF20

#byte SPBRGH2 = 0xF1F

#byte SPBRG2 = 0xF1E

#byte RCREG2 = 0xF1D

#byte TXREG2 = 0xF1C

struct PSTR2CONBITS {
   unsigned int STRA:1;
   unsigned int STRB:1;
   unsigned int STRC:1;
   unsigned int STRD:1;
   unsigned int STRSYNC:1;
   unsigned int :1;
   unsigned int CMPL6:1;
   unsigned int CMPL1:1;
} PSTR2CONbits;
#byte PSTR2CONbits = 0xF1B
#byte PSTR2CON = 0xF1B

struct PSTR3CONBITS {
   unsigned int STRA:1;
   unsigned int STRB:1;
   unsigned int STRC:1;
   unsigned int STRD:1;
   unsigned int STRSYNC:1;
   unsigned int :1;
   unsigned int CMPL6:1;
   unsigned int CMPL1:1;
} PSTR3CONbits;
#byte PSTR3CONbits = 0xF1A
#byte PSTR3CON = 0xF1A

struct PMD0BITS {
   unsigned int ADCMD:1;
   unsigned int SSP1MD:1;
   unsigned int SSP2MD:1;
   unsigned int UART1MD:1;
   unsigned int UART2MD:1;
   unsigned int CCP1MD:1;
   unsigned int CCP2MD:1;
   unsigned int CCP3MD:1;
} PMD0bits;
#byte PMD0bits = 0xF19
#byte PMD0 = 0xF19

struct PMD1BITS {
   unsigned int EMBMD:1;
   unsigned int TMR1MD:1;
   unsigned int TMR2MD:1;
   unsigned int TMR3MD:1;
   unsigned int TMR4MD:1;
   unsigned int RTCCMD:1;
   unsigned int CTMUMD:1;
   unsigned int PSPMD:1;
} PMD1bits;
#byte PMD1bits = 0xF18
#byte PMD1 = 0xF18

struct PMD2BITS {
   unsigned int CMP1MD:1;
   unsigned int CMP2MD:1;
   unsigned int CMP3MD:1;
   unsigned int TMR5MD:1;
   unsigned int TMR6MD:1;
   unsigned int TMR7MD:1;
   unsigned int TMR8MD:1;
   unsigned int TMR10MD:1;
} PMD2bits;
#byte PMD2bits = 0xF17
#byte PMD2 = 0xF17

struct PMD3BITS {
   unsigned int TMR12MD:1;
   unsigned int CCP4MD:1;
   unsigned int CCP5MD:1;
   unsigned int CCP6MD:1;
   unsigned int CCP7MD:1;
   unsigned int CCP8MD:1;
   unsigned int CCP9MD:1;
   unsigned int CCP10MD:1;
} PMD3bits;
#byte PMD3bits = 0xF16
#byte PMD3 = 0xF16

