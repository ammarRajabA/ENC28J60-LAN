#byte TOSU = 0xFFF

#word TOS = 0xFFD
#byte TOSH = 0xFFE
#byte TOSL = 0xFFD

typedef union 
 {
   union {
      struct {
         unsigned int STKPTR0:5;
         unsigned int :1;
         unsigned int STKUNF:1;
         unsigned int STKFUL:1;
      };
      struct {
         unsigned int STKPTR:5;
      };

      struct {
         unsigned int :7;
         unsigned int STKOVF:1;
      };
   };
} STKPTRBITS;
STKPTRBITS STKPTRbits;
#byte STKPTRbits = 0xFFC
#byte STKPTR = 0xFFC

#byte PCLATU = 0xFFB

#byte PCLATH = 0xFFA

#byte PCL = 0xFF9

typedef union 
 {
      struct {
         unsigned int TBLPTRU0:5;
         unsigned int ACSS:1;
      };
      struct {
         unsigned int TBLPTRU:5;
      };
} TBLPTRUBITS;
TBLPTRUBITS TBLPTRUbits;
#byte TBLPTRUbits = 0xFF8
#byte TBLPTRU = 0xFF8

#word TBLPTR = 0xFF6
#byte TBLPTRH = 0xFF7
#byte TBLPTRL = 0xFF6

#byte TABLAT = 0xFF5

#word PROD = 0xFF3
#byte PRODH = 0xFF4
#byte PRODL = 0xFF3

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int INT0F:1;
         unsigned int T0IF:1;
         unsigned int :1;
         unsigned int INT0E:1;
         unsigned int T0IE:1;
         unsigned int GIEL:1;
         unsigned int GIEH:1;
      };

   union {
      struct {
         unsigned int :6;
         unsigned int PEIE:1;
         unsigned int GIE:1;
      };
   };

      struct {
         unsigned int RBIF:1;
         unsigned int INT0IF:1;
         unsigned int TMR0IF:1;
         unsigned int RBIE:1;
         unsigned int INT0IE:1;
         unsigned int TMR0IE:1;
         unsigned int PEIE_GIEL:1;
         unsigned int GIE_GIEH:1;
      };
   };
} INTCONBITS;
INTCONBITS INTCONbits;
#byte INTCONbits = 0xFF2
#byte INTCON = 0xFF2

typedef union 
 {
   union {
      struct {
         unsigned int RBIP:1;
         unsigned int :1;
         unsigned int TMR0IP:1;
         unsigned int :1;
         unsigned int INTEDG2:1;
         unsigned int INTEDG1:1;
         unsigned int INTEDG0:1;
         unsigned int RBPU:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int INTEDG:3;
      };

      struct {
         unsigned int :2;
         unsigned int T0IP:1;
      };
   };
} INTCON2BITS;
INTCON2BITS INTCON2bits;
#byte INTCON2bits = 0xFF1
#byte INTCON2 = 0xFF1

typedef struct 
 {
   union {
      struct {
         unsigned int INT1F:1;
         unsigned int INT2F:1;
         unsigned int :1;
         unsigned int INT1E:1;
         unsigned int INT2E:1;
         unsigned int :1;
         unsigned int INT1P:1;
         unsigned int INT2P:1;
      };

      struct {
         unsigned int INT1IF:1;
         unsigned int INT2IF:1;
         unsigned int :1;
         unsigned int INT1IE:1;
         unsigned int INT2IE:1;
         unsigned int :1;
         unsigned int INT1IP:1;
         unsigned int INT2IP:1;
      };
   };
} INTCON3BITS;
INTCON3BITS INTCON3bits;
#byte INTCON3bits = 0xFF0
#byte INTCON3 = 0xFF0

#byte INDF0 = 0xFEF

#byte POSTINC0 = 0xFEE

#byte POSTDEC0 = 0xFED

#byte PREINC0 = 0xFEC

#byte PLUSW0 = 0xFEB

#word FSR0 = 0xFE9
#byte FSR0H = 0xFEA
#byte FSR0L = 0xFE9

#byte WREG = 0xFE8

#byte INDF1 = 0xFE7

#byte POSTINC1 = 0xFE6

#byte POSTDEC1 = 0xFE5

#byte PREINC1 = 0xFE4

#byte PLUSW1 = 0xFE3

#word FSR1 = 0xFE1
#byte FSR1H = 0xFE2
#byte FSR1L = 0xFE1

#byte BSR = 0xFE0

#byte INDF2 = 0xFDF

#byte POSTINC2 = 0xFDE

#byte POSTDEC2 = 0xFDD

#byte PREINC2 = 0xFDC

#byte PLUSW2 = 0xFDB

#word FSR2 = 0xFD9
#byte FSR2H = 0xFDA
#byte FSR2L = 0xFD9

typedef struct 
 {
   unsigned int C:1;
   unsigned int DC:1;
   unsigned int Z:1;
   unsigned int OV:1;
   unsigned int N:1;
} STATUSBITS;
STATUSBITS STATUSbits;
#byte STATUSbits = 0xFD8
#byte STATUS = 0xFD8

#word TMR0 = 0xFD6
#byte TMR0H = 0xFD7
#byte TMR0L = 0xFD6

typedef union 
 {
      struct {
         unsigned int T0PS0:3;
         unsigned int PSA:1;
         unsigned int T0SE:1;
         unsigned int T0CS:1;
         unsigned int T08BIT:1;
         unsigned int TMR0ON:1;
      };
      struct {
         unsigned int T0PS:3;
      };
} T0CONBITS;
T0CONBITS T0CONbits;
#byte T0CONbits = 0xFD5
#byte T0CON = 0xFD5

typedef union 
 {
      struct {
         unsigned int SCS0:2;
         unsigned int IOFS:1;
         unsigned int OSTS:1;
         unsigned int IRCF0:3;
         unsigned int IDLEN:1;
      };
      struct {
         unsigned int SCS:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int IRCF:3;
      };
} OSCCONBITS;
OSCCONBITS OSCCONbits;
#byte OSCCONbits = 0xFD3
#byte OSCCON = 0xFD3

typedef union 
 {
   union {
      struct {
         unsigned int LVDL0:4;
         unsigned int LVDEN:1;
         unsigned int IVRST:1;
      };
      struct {
         unsigned int LVDL:4;
      };

   union {
      struct {
         unsigned int LVV0:4;
         unsigned int :1;
         unsigned int BGST:1;
      };
   };
      struct {
         unsigned int LVV:4;
      };

      struct {
         unsigned int HLVDL0:4;
         unsigned int HLVDEN:1;
         unsigned int IRVST:1;
         unsigned int :1;
         unsigned int VDIRMAG:1;
      };
   };
      struct {
         unsigned int HLVDL:4;
      };
} HLVDCONBITS;
HLVDCONBITS HLVDCONbits;
#byte HLVDCONbits = 0xFD2
#byte HLVDCON = 0xFD2

typedef struct 
 {
   union {
      struct {
         unsigned int SWDTEN:1;
      };

      struct {
         unsigned int SWDTE:1;
      };
   };
} WDTCONBITS;
WDTCONBITS WDTCONbits;
#byte WDTCONbits = 0xFD1
#byte WDTCON = 0xFD1

typedef struct 
 {
   unsigned int BOR:1;
   unsigned int POR:1;
   unsigned int PD:1;
   unsigned int TO:1;
   unsigned int RI:1;
   unsigned int :1;
   unsigned int SBOREN:1;
   unsigned int IPEN:1;
} RCONBITS;
RCONBITS RCONbits;
#byte RCONbits = 0xFD0
#byte RCON = 0xFD0

#word TMR1 = 0xFCE
#byte TMR1H = 0xFCF
#byte TMR1L = 0xFCE

typedef struct 
 {
   union {
      struct {
         unsigned int :2;
         unsigned int T1INSYNC:1;
      };

      struct {
         unsigned int TMR1ON:1;
         unsigned int TMR1CS:1;
         unsigned int T1SYNC:1;
         unsigned int T1OSCEN:1;
         unsigned int T1CKPS0:2;
         unsigned int T1RUN:1;
         unsigned int RD16:1;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int T1CKPS:2;
      };
} T1CONBITS;
T1CONBITS T1CONbits;
#byte T1CONbits = 0xFCD
#byte T1CON = 0xFCD

#byte TMR2 = 0xFCC

#byte PR2 = 0xFCB

typedef union 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int TOUTPS0:4;
      };
      struct {
         unsigned int :3;
         unsigned int TOUTPS:4;
      };

      struct {
         unsigned int T2CKPS0:2;
         unsigned int TMR2ON:1;
         unsigned int T2OUTPS0:4;
      };
   };
      struct {
         unsigned int T2CKPS:2;
         unsigned int :1;
         unsigned int T2OUTPS:4;
      };
} T2CONBITS;
T2CONBITS T2CONbits;
#byte T2CONbits = 0xFCA
#byte T2CON = 0xFCA

#byte SSPBUF = 0xFC9

#byte SSPADD = 0xFC8

typedef struct 
 {
   union {
      struct {
         unsigned int :2;
         unsigned int R_W:1;
         unsigned int :2;
         unsigned int D_A:1;
      };

   union {
      struct {
         unsigned int :2;
         unsigned int I2C_READ:1;
         unsigned int I2C_START:1;
         unsigned int I2C_STOP:1;
         unsigned int I2C_DAT:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int WRITE:1;
         unsigned int :2;
         unsigned int ADDRESS:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int READ_WRITE:1;
         unsigned int :2;
         unsigned int DATA_ADDRESS:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int W:1;
         unsigned int :2;
         unsigned int A:1;
      };
   };

      struct {
         unsigned int BF:1;
         unsigned int UA:1;
         unsigned int R:1;
         unsigned int S:1;
         unsigned int P:1;
         unsigned int D:1;
         unsigned int CKE:1;
         unsigned int SMP:1;
      };
   };
} SSPSTATBITS;
SSPSTATBITS SSPSTATbits;
#byte SSPSTATbits = 0xFC7
#byte SSPSTAT = 0xFC7

typedef union 
 {
      struct {
         unsigned int SSPM0:4;
         unsigned int CKP:1;
         unsigned int SSPEN:1;
         unsigned int SSPOV:1;
         unsigned int WCOL:1;
      };
      struct {
         unsigned int SSPM:4;
      };
} SSPCON1BITS;
SSPCON1BITS SSPCON1bits;
#byte SSPCON1bits = 0xFC6
#byte SSPCON1 = 0xFC6

typedef struct 
 {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int ACKSTAT:1;
   unsigned int GCEN:1;
} SSPCON2BITS;
SSPCON2BITS SSPCON2bits;
#byte SSPCON2bits = 0xFC5
#byte SSPCON2 = 0xFC5

#word ADRES = 0xFC3
#byte ADRESH = 0xFC4
#byte ADRESL = 0xFC3

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int GO_DONE:1;
      };

   union {
      struct {
         unsigned int :1;
         unsigned int DONE:1;
      };
   };

      struct {
         unsigned int ADON:1;
         unsigned int GO:1;
         unsigned int CHS0:4;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int CHS:4;
      };
} ADCON0BITS;
ADCON0BITS ADCON0bits;
#byte ADCON0bits = 0xFC2
#byte ADCON0 = 0xFC2

typedef union 
 {
      struct {
         unsigned int PCFG0:4;
         unsigned int VCFG0:2;
      };
      struct {
         unsigned int PCFG:4;
         unsigned int VCFG:2;
      };
} ADCON1BITS;
ADCON1BITS ADCON1bits;
#byte ADCON1bits = 0xFC1
#byte ADCON1 = 0xFC1

typedef union 
 {
      struct {
         unsigned int ADCS0:3;
         unsigned int ACQT0:3;
         unsigned int :1;
         unsigned int ADFM:1;
      };
      struct {
         unsigned int ADCS:3;
         unsigned int ACQT:3;
      };
} ADCON2BITS;
ADCON2BITS ADCON2bits;
#byte ADCON2bits = 0xFC0
#byte ADCON2 = 0xFC0

#word CCPR1 = 0xFBE
#byte CCPR1H = 0xFBF
#byte CCPR1L = 0xFBE

typedef union 
 {
      struct {
         unsigned int CCP1M0:4;
         unsigned int DC1B0:2;
      };
      struct {
         unsigned int CCP1M:4;
         unsigned int DC1B:2;
      };
} CCP1CONBITS;
CCP1CONBITS CCP1CONbits;
#byte CCP1CONbits = 0xFBD
#byte CCP1CON = 0xFBD

#word ECCPR1 = 0xFBB
#byte ECCPR1H = 0xFBC
#byte ECCPR1L = 0xFBB

typedef union 
 {
      struct {
         unsigned int ECCP1M0:4;
         unsigned int EDC1B0:2;
         unsigned int EPWM1M0:2;
      };
      struct {
         unsigned int ECCP1M:4;
         unsigned int EDC1B:2;
         unsigned int EPWM1M:2;
      };
} ECCP1CONBITS;
ECCP1CONBITS ECCP1CONbits;
#byte ECCP1CONbits = 0xFBA
#byte ECCP1CON = 0xFBA

typedef struct 
 {
   union {
      struct {
         unsigned int ABDEN:1;
         unsigned int WUE:1;
         unsigned int :1;
         unsigned int BRG16:1;
         unsigned int TXCKP:1;
         unsigned int RXDTP:1;
         unsigned int RCIDL:1;
         unsigned int ABDOVF:1;
      };

      struct {
         unsigned int :4;
         unsigned int SCKP:1;
      };
   };
} BAUDCONBITS;
BAUDCONBITS BAUDCONbits;
#byte BAUDCONbits = 0xFB8
#byte BAUDCON = 0xFB8

typedef union 
 {
      struct {
         unsigned int PDC0:7;
         unsigned int PRSEN:1;
      };
      struct {
         unsigned int PDC:7;
      };
} ECCP1DELBITS;
ECCP1DELBITS ECCP1DELbits;
#byte ECCP1DELbits = 0xFB7
#byte ECCP1DEL = 0xFB7

typedef union 
 {
      struct {
         unsigned int PSSBD0:2;
         unsigned int PSSAC0:2;
         unsigned int ECCPAS0:3;
         unsigned int ECCPASE:1;
      };
      struct {
         unsigned int PSSBD:2;
         unsigned int PSSAC:2;
         unsigned int ECCPAS:3;
      };
} ECCP1ASBITS;
ECCP1ASBITS ECCP1ASbits;
#byte ECCP1ASbits = 0xFB6
#byte ECCP1AS = 0xFB6

typedef union 
 {
   union {
      struct {
         unsigned int CVR0:4;
         unsigned int CVRSS:1;
         unsigned int CVRR:1;
         unsigned int CVROE:1;
         unsigned int CVREN:1;
      };
      struct {
         unsigned int CVR:4;
      };

      struct {
         unsigned int :4;
         unsigned int CVREF:1;
      };
   };
} CVRCONBITS;
CVRCONBITS CVRCONbits;
#byte CVRCONbits = 0xFB5
#byte CVRCON = 0xFB5

typedef union 
 {
      struct {
         unsigned int CM0:3;
         unsigned int CIS:1;
         unsigned int C1INV:1;
         unsigned int C2INV:1;
         unsigned int C1OUT:1;
         unsigned int C2OUT:1;
      };
      struct {
         unsigned int CM:3;
      };
} CMCONBITS;
CMCONBITS CMCONbits;
#byte CMCONbits = 0xFB4
#byte CMCON = 0xFB4

#word TMR3 = 0xFB2
#byte TMR3H = 0xFB3
#byte TMR3L = 0xFB2

typedef union 
 {
   union {
      struct {
         unsigned int TMR3ON:1;
         unsigned int TMR3CS:1;
         unsigned int T3SYNC:1;
         unsigned int T3CCP1:1;
         unsigned int T3CKPS0:2;
         unsigned int T3ECCP1:1;
         unsigned int RD16:1;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int T3CKPS:2;
      };

      struct {
         unsigned int :2;
         unsigned int T3NSYNC:1;
         unsigned int :3;
         unsigned int T3CCP2:1;
      };
   };
} T3CONBITS;
T3CONBITS T3CONbits;
#byte T3CONbits = 0xFB1
#byte T3CON = 0xFB1

#byte SPBRGH = 0xFB0

#byte SPBRG = 0xFAF

#byte RCREG = 0xFAE

#byte TXREG = 0xFAD

typedef struct 
 {
   unsigned int TX9D:1;
   unsigned int TRMT:1;
   unsigned int BRGH:1;
   unsigned int SENDB:1;
   unsigned int SYNC:1;
   unsigned int TXEN:1;
   unsigned int TX9:1;
   unsigned int CSRC:1;
} TXSTABITS;
TXSTABITS TXSTAbits;
#byte TXSTAbits = 0xFAC
#byte TXSTA = 0xFAC

typedef struct 
 {
   union {
      struct {
         unsigned int RX9D:1;
         unsigned int OERR:1;
         unsigned int FERR:1;
         unsigned int ADDEN:1;
         unsigned int CREN:1;
         unsigned int SREN:1;
         unsigned int RX9:1;
         unsigned int SPEN:1;
      };

      struct {
         unsigned int :3;
         unsigned int ADEN:1;
      };
   };
} RCSTABITS;
RCSTABITS RCSTAbits;
#byte RCSTAbits = 0xFAB
#byte RCSTA = 0xFAB

#byte EEADRH = 0xFAA

#byte EEADR = 0xFA9

#byte EEDATA = 0xFA8

#byte EECON2 = 0xFA7

typedef struct 
 {
   unsigned int RD:1;
   unsigned int WR:1;
   unsigned int WREN:1;
   unsigned int WRERR:1;
   unsigned int FREE:1;
   unsigned int :1;
   unsigned int CFGS:1;
   unsigned int EEPGD:1;
} EECON1BITS;
EECON1BITS EECON1bits;
#byte EECON1bits = 0xFA6
#byte EECON1 = 0xFA6

typedef struct 
 {
   union {
      struct {
         unsigned int FIFOWMIP:1;
         unsigned int RXBnIP:1;
         unsigned int :2;
         unsigned int TXBnIP:1;
      };

      struct {
         unsigned int RXB0IP:1;
         unsigned int RXB1IP:1;
         unsigned int TXB0IP:1;
         unsigned int TXB1IP:1;
         unsigned int TXB2IP:1;
         unsigned int ERRIP:1;
         unsigned int WAKIP:1;
         unsigned int IRXIP:1;
      };
   };
} IPR3BITS;
IPR3BITS IPR3bits;
#byte IPR3bits = 0xFA5
#byte IPR3 = 0xFA5

typedef struct 
 {
   union {
      struct {
         unsigned int RXB0IF:1;
         unsigned int RXB1IF:1;
         unsigned int TXB0IF:1;
         unsigned int TXB1IF:1;
         unsigned int TXB2IF:1;
         unsigned int ERRIF:1;
         unsigned int WAKIF:1;
         unsigned int IRXIF:1;
      };

      struct {
         unsigned int FIFOWMIF:1;
         unsigned int RXBnIF:1;
         unsigned int :2;
         unsigned int TXBnIF:1;
      };
   };
} PIR3BITS;
PIR3BITS PIR3bits;
#byte PIR3bits = 0xFA4
#byte PIR3 = 0xFA4

typedef struct 
 {
   union {
      struct {
         unsigned int RXB0IE:1;
         unsigned int RXB1IE:1;
         unsigned int TXB0IE:1;
         unsigned int TXB1IE:1;
         unsigned int TXB2IE:1;
         unsigned int ERRIE:1;
         unsigned int WAKIE:1;
         unsigned int IRXIE:1;
      };

   union {
      struct {
         unsigned int FIFOWMIE:1;
         unsigned int RXBnIE:1;
         unsigned int :2;
         unsigned int TXBnIE:1;
      };
   };

      struct {
         unsigned int FIFOMWIE:1;
      };
   };
} PIE3BITS;
PIE3BITS PIE3bits;
#byte PIE3bits = 0xFA3
#byte PIE3 = 0xFA3

typedef struct 
 {
   union {
      struct {
         unsigned int :2;
         unsigned int LVDIP:1;
      };

      struct {
         unsigned int ECCP1IP:1;
         unsigned int TMR3IP:1;
         unsigned int HLVDIP:1;
         unsigned int BCLIP:1;
         unsigned int EEIP:1;
         unsigned int :1;
         unsigned int CMIP:1;
         unsigned int OSCFIP:1;
      };
   };
} IPR2BITS;
IPR2BITS IPR2bits;
#byte IPR2bits = 0xFA2
#byte IPR2 = 0xFA2

typedef struct 
 {
   union {
      struct {
         unsigned int ECCP1IF:1;
         unsigned int TMR3IF:1;
         unsigned int HLVDIF:1;
         unsigned int BCLIF:1;
         unsigned int EEIF:1;
         unsigned int :1;
         unsigned int CMIF:1;
         unsigned int OSCFIF:1;
      };

      struct {
         unsigned int :2;
         unsigned int LVDIF:1;
      };
   };
} PIR2BITS;
PIR2BITS PIR2bits;
#byte PIR2bits = 0xFA1
#byte PIR2 = 0xFA1

typedef struct 
 {
   union {
      struct {
         unsigned int ECCP1IE:1;
         unsigned int TMR3IE:1;
         unsigned int HLVDIE:1;
         unsigned int BCLIE:1;
         unsigned int EEIE:1;
         unsigned int :1;
         unsigned int CMIE:1;
         unsigned int OSCFIE:1;
      };

      struct {
         unsigned int :2;
         unsigned int LVDIE:1;
      };
   };
} PIE2BITS;
PIE2BITS PIE2bits;
#byte PIE2bits = 0xFA0
#byte PIE2 = 0xFA0

typedef struct 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int TXBIP:1;
      };

      struct {
         unsigned int TMR1IP:1;
         unsigned int TMR2IP:1;
         unsigned int CCP1IP:1;
         unsigned int SSPIP:1;
         unsigned int TXIP:1;
         unsigned int RCIP:1;
         unsigned int ADIP:1;
         unsigned int PSPIP:1;
      };
   };
} IPR1BITS;
IPR1BITS IPR1bits;
#byte IPR1bits = 0xF9F
#byte IPR1 = 0xF9F

typedef struct 
 {
   unsigned int TMR1IF:1;
   unsigned int TMR2IF:1;
   unsigned int CCP1IF:1;
   unsigned int SSPIF:1;
   unsigned int TXIF:1;
   unsigned int RCIF:1;
   unsigned int ADIF:1;
   unsigned int PSPIF:1;
} PIR1BITS;
PIR1BITS PIR1bits;
#byte PIR1bits = 0xF9E
#byte PIR1 = 0xF9E

typedef struct 
 {
   unsigned int TMR1IE:1;
   unsigned int TMR2IE:1;
   unsigned int CCP1IE:1;
   unsigned int SSPIE:1;
   unsigned int TXIE:1;
   unsigned int RCIE:1;
   unsigned int ADIE:1;
   unsigned int PSPIE:1;
} PIE1BITS;
PIE1BITS PIE1bits;
#byte PIE1bits = 0xF9D
#byte PIE1 = 0xF9D

typedef union 
 {
   union {
      struct {
         unsigned int TUN0:5;
         unsigned int :1;
         unsigned int PLLEN:1;
         unsigned int INTSRC:1;
      };
      struct {
         unsigned int TUN:5;
      };

      struct {
         unsigned int :7;
         unsigned int INTSCR:1;
      };
   };
} OSCTUNEBITS;
OSCTUNEBITS OSCTUNEbits;
#byte OSCTUNEbits = 0xF9B
#byte OSCTUNE = 0xF9B

typedef struct 
 {
   unsigned int TRISE0:1;
   unsigned int TRISE1:1;
   unsigned int TRISE2:1;
   unsigned int TRISE3:1;
   unsigned int TRISE4:1;
   unsigned int TRISE5:1;
   unsigned int TRISE6:1;
   unsigned int TRISE7:1;
} TRISEBITS;
TRISEBITS TRISEbits;
#byte TRISEbits = 0xF96
#byte TRISE = 0xF96

typedef struct 
 {
   unsigned int TRISD0:1;
   unsigned int TRISD1:1;
   unsigned int TRISD2:1;
   unsigned int TRISD3:1;
   unsigned int TRISD4:1;
   unsigned int TRISD5:1;
   unsigned int TRISD6:1;
   unsigned int TRISD7:1;
} TRISDBITS;
TRISDBITS TRISDbits;
#byte TRISDbits = 0xF95
#byte TRISD = 0xF95

typedef struct 
 {
   unsigned int TRISC0:1;
   unsigned int TRISC1:1;
   unsigned int TRISC2:1;
   unsigned int TRISC3:1;
   unsigned int TRISC4:1;
   unsigned int TRISC5:1;
   unsigned int TRISC6:1;
   unsigned int TRISC7:1;
} TRISCBITS;
TRISCBITS TRISCbits;
#byte TRISCbits = 0xF94
#byte TRISC = 0xF94

typedef struct 
 {
   unsigned int TRISB0:1;
   unsigned int TRISB1:1;
   unsigned int TRISB2:1;
   unsigned int TRISB3:1;
   unsigned int TRISB4:1;
   unsigned int TRISB5:1;
   unsigned int TRISB6:1;
   unsigned int TRISB7:1;
} TRISBBITS;
TRISBBITS TRISBbits;
#byte TRISBbits = 0xF93
#byte TRISB = 0xF93

typedef struct 
 {
   unsigned int TRISA0:1;
   unsigned int TRISA1:1;
   unsigned int TRISA2:1;
   unsigned int TRISA3:1;
   unsigned int TRISA4:1;
   unsigned int TRISA5:1;
   unsigned int TRISA6:1;
   unsigned int TRISA7:1;
} TRISABITS;
TRISABITS TRISAbits;
#byte TRISAbits = 0xF92
#byte TRISA = 0xF92

typedef struct 
 {
   unsigned int LATE0:1;
   unsigned int LATE1:1;
   unsigned int LATE2:1;
   unsigned int LATE3:1;
   unsigned int LATE4:1;
   unsigned int LATE5:1;
   unsigned int LATE6:1;
   unsigned int LATE7:1;
} LATEBITS;
LATEBITS LATEbits;
#byte LATEbits = 0xF8D
#byte LATE = 0xF8D

typedef struct 
 {
   unsigned int LATD0:1;
   unsigned int LATD1:1;
   unsigned int LATD2:1;
   unsigned int LATD3:1;
   unsigned int LATD4:1;
   unsigned int LATD5:1;
   unsigned int LATD6:1;
   unsigned int LATD7:1;
} LATDBITS;
LATDBITS LATDbits;
#byte LATDbits = 0xF8C
#byte LATD = 0xF8C

typedef struct 
 {
   unsigned int LATC0:1;
   unsigned int LATC1:1;
   unsigned int LATC2:1;
   unsigned int LATC3:1;
   unsigned int LATC4:1;
   unsigned int LATC5:1;
   unsigned int LATC6:1;
   unsigned int LATC7:1;
} LATCBITS;
LATCBITS LATCbits;
#byte LATCbits = 0xF8B
#byte LATC = 0xF8B

typedef struct 
 {
   unsigned int LATB0:1;
   unsigned int LATB1:1;
   unsigned int LATB2:1;
   unsigned int LATB3:1;
   unsigned int LATB4:1;
   unsigned int LATB5:1;
   unsigned int LATB6:1;
   unsigned int LATB7:1;
} LATBBITS;
LATBBITS LATBbits;
#byte LATBbits = 0xF8A
#byte LATB = 0xF8A

typedef struct 
 {
   unsigned int LATA0:1;
   unsigned int LATA1:1;
   unsigned int LATA2:1;
   unsigned int LATA3:1;
   unsigned int LATA4:1;
   unsigned int LATA5:1;
   unsigned int LATA6:1;
   unsigned int LATA7:1;
} LATABITS;
LATABITS LATAbits;
#byte LATAbits = 0xF89
#byte LATA = 0xF89

typedef struct 
 {
   unsigned int RE0:1;
   unsigned int RE1:1;
   unsigned int RE2:1;
   unsigned int RE3:1;
   unsigned int RE4:1;
   unsigned int RE5:1;
   unsigned int RE6:1;
   unsigned int RE7:1;
} PORTEBITS;
PORTEBITS PORTEbits;
#byte PORTEbits = 0xF84
#byte PORTE = 0xF84

typedef struct 
 {
   unsigned int RD0:1;
   unsigned int RD1:1;
   unsigned int RD2:1;
   unsigned int RD3:1;
   unsigned int RD4:1;
   unsigned int RD5:1;
   unsigned int RD6:1;
   unsigned int RD7:1;
} PORTDBITS;
PORTDBITS PORTDbits;
#byte PORTDbits = 0xF83
#byte PORTD = 0xF83

typedef struct 
 {
   unsigned int RC0:1;
   unsigned int RC1:1;
   unsigned int RC2:1;
   unsigned int RC3:1;
   unsigned int RC4:1;
   unsigned int RC5:1;
   unsigned int RC6:1;
   unsigned int RC7:1;
} PORTCBITS;
PORTCBITS PORTCbits;
#byte PORTCbits = 0xF82
#byte PORTC = 0xF82

typedef struct 
 {
   unsigned int RB0:1;
   unsigned int RB1:1;
   unsigned int RB2:1;
   unsigned int RB3:1;
   unsigned int RB4:1;
   unsigned int RB5:1;
   unsigned int RB6:1;
   unsigned int RB7:1;
} PORTBBITS;
PORTBBITS PORTBbits;
#byte PORTBbits = 0xF81
#byte PORTB = 0xF81

typedef struct 
 {
   unsigned int RA0:1;
   unsigned int RA1:1;
   unsigned int RA2:1;
   unsigned int RA3:1;
   unsigned int RA4:1;
   unsigned int RA5:1;
   unsigned int RA6:1;
   unsigned int RA7:1;
} PORTABITS;
PORTABITS PORTAbits;
#byte PORTAbits = 0xF80
#byte PORTA = 0xF80

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int F:1;
      };

      struct {
         unsigned int EWIN0:5;
         unsigned int FIFOWM:1;
         unsigned int MDSEL0:2;
      };
   };
      struct {
         unsigned int EWIN:5;
         unsigned int :1;
         unsigned int MDSEL:2;
      };
} ECANCONBITS;
ECANCONBITS ECANCONbits;
#byte ECANCONbits = 0xF77
#byte ECANCON = 0xF77

#byte TXERRCNT = 0xF76

#byte RXERRCNT = 0xF75

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RXB1OVFL:1;
         unsigned int FIFOEMPTY:1;
      };

      struct {
         unsigned int EWARN:1;
         unsigned int RXWARN:1;
         unsigned int TXWARN:1;
         unsigned int RXBP:1;
         unsigned int TXBP:1;
         unsigned int TXBO:1;
         unsigned int RXBnOVFL:1;
         unsigned int RXB0OVFL:1;
      };
   };
} COMSTATBITS;
COMSTATBITS COMSTATbits;
#byte COMSTATbits = 0xF74
#byte COMSTAT = 0xF74

typedef struct 
 {
   unsigned int :4;
   unsigned int CANCAP:1;
   unsigned int ENDRHI:1;
} CIOCONBITS;
CIOCONBITS CIOCONbits;
#byte CIOCONbits = 0xF73
#byte CIOCON = 0xF73

typedef union 
 {
      struct {
         unsigned int SEG2PH0:3;
         unsigned int :3;
         unsigned int WAKFIL:1;
         unsigned int WAKDIS:1;
      };
      struct {
         unsigned int SEG2PH:3;
         unsigned int :3;
      };
} BRGCON3BITS;
BRGCON3BITS BRGCON3bits;
#byte BRGCON3bits = 0xF72
#byte BRGCON3 = 0xF72

typedef union 
 {
   union {
      struct {
         unsigned int PRSEG0:3;
         unsigned int SEG1PH0:3;
         unsigned int SAM:1;
         unsigned int SEG2PHT:1;
      };
      struct {
         unsigned int PRSEG:3;
         unsigned int SEG1PH:3;
      };

      struct {
         unsigned int :7;
         unsigned int SEG2PHTS:1;
      };
   };
} BRGCON2BITS;
BRGCON2BITS BRGCON2bits;
#byte BRGCON2bits = 0xF71
#byte BRGCON2 = 0xF71

typedef union 
 {
      struct {
         unsigned int BRP0:6;
         unsigned int SJW0:2;
      };
      struct {
         unsigned int BRP:6;
         unsigned int SJW:2;
      };
} BRGCON1BITS;
BRGCON1BITS BRGCON1bits;
#byte BRGCON1bits = 0xF70
#byte BRGCON1 = 0xF70

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int FP1:3;
      };

   union {
      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };

      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };
} CANCONBITS;
CANCONBITS CANCONbits;
#byte CANCONbits = 0xF6F
#byte CANCON = 0xF6F

typedef union 
 {
   union {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };

      struct {
         unsigned int :1;
         unsigned int EICODE1:3;
      };
   };
} CANSTATBITS;
CANSTATBITS CANSTATbits;
#byte CANSTATbits = 0xF6E
#byte CANSTAT = 0xF6E

#byte RXB0D7 = 0xF6D

#byte RXB0D6 = 0xF6C

#byte RXB0D5 = 0xF6B

#byte RXB0D4 = 0xF6A

#byte RXB0D3 = 0xF69

#byte RXB0D2 = 0xF68

#byte RXB0D1 = 0xF67

#byte RXB0D0 = 0xF66

typedef union 
 {
   union {
      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR:1;
      };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };

      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };
} RXB0DLCBITS;
RXB0DLCBITS RXB0DLCbits;
#byte RXB0DLCbits = 0xF65
#byte RXB0DLC = 0xF65

#byte RXB0EIDL = 0xF64

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXB0EIDHBITS;
RXB0EIDHBITS RXB0EIDHbits;
#byte RXB0EIDHbits = 0xF63
#byte RXB0EIDH = 0xF63

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXID:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXB0SIDLBITS;
RXB0SIDLBITS RXB0SIDLbits;
#byte RXB0SIDLbits = 0xF62
#byte RXB0SIDL = 0xF62

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXB0SIDHBITS;
RXB0SIDHBITS RXB0SIDHbits;
#byte RXB0SIDHbits = 0xF61
#byte RXB0SIDH = 0xF61

typedef struct 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int FILHIT1:3;
         unsigned int :1;
         unsigned int RTRRO:1;
      };

   union {
      struct {
         unsigned int FILHIT0:1;
         unsigned int JTOFF_FILHIT1:1;
         unsigned int RXB0DBEN_FILHIT2:1;
         unsigned int RXRTRRO_FILHIT3:1;
         unsigned int FILHIT4:1;
         unsigned int RXM0_RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };

   union {
      struct {
         unsigned int :2;
         unsigned int RXBODBEN:1;
      };
   };

      struct {
         unsigned int :1;
         unsigned int JTOFF:1;
         unsigned int RXB0DBEN:1;
         unsigned int RXRTRRO:1;
         unsigned int :1;
         unsigned int RXM0:1;
      };
   };
} RXB0CONBITS;
RXB0CONBITS RXB0CONbits;
#byte RXB0CONbits = 0xF60
#byte RXB0CON = 0xF60

typedef union 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };

      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };
} CANCON_RO0BITS;
CANCON_RO0BITS CANCON_RO0bits;
#byte CANCON_RO0bits = 0xF5F
#byte CANCON_RO0 = 0xF5F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO0BITS;
CANSTAT_RO0BITS CANSTAT_RO0bits;
#byte CANSTAT_RO0bits = 0xF5E
#byte CANSTAT_RO0 = 0xF5E

#byte RXB1D7 = 0xF5D

#byte RXB1D6 = 0xF5C

#byte RXB1D5 = 0xF5B

#byte RXB1D4 = 0xF5A

#byte RXB1D3 = 0xF59

#byte RXB1D2 = 0xF58

#byte RXB1D1 = 0xF57

#byte RXB1D0 = 0xF56

typedef union 
 {
   union {
      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR:1;
      };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };

      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };
} RXB1DLCBITS;
RXB1DLCBITS RXB1DLCbits;
#byte RXB1DLCbits = 0xF55
#byte RXB1DLC = 0xF55

#byte RXB1EIDL = 0xF54

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXB1EIDHBITS;
RXB1EIDHBITS RXB1EIDHbits;
#byte RXB1EIDHbits = 0xF53
#byte RXB1EIDH = 0xF53

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXID:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXB1SIDLBITS;
RXB1SIDLBITS RXB1SIDLbits;
#byte RXB1SIDLbits = 0xF52
#byte RXB1SIDL = 0xF52

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXB1SIDHBITS;
RXB1SIDHBITS RXB1SIDHbits;
#byte RXB1SIDHbits = 0xF51
#byte RXB1SIDH = 0xF51

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int FILHIT3:1;
         unsigned int :1;
         unsigned int RTRRO:1;
      };

   union {
      struct {
         unsigned int FILHIT0:3;
         unsigned int RXRTRRO_FILHIT3:1;
         unsigned int FILHIT4:1;
         unsigned int RXM0_RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:3;
      };

      struct {
         unsigned int :3;
         unsigned int RXRTRRO:1;
         unsigned int :1;
         unsigned int RXM0:1;
      };
   };
} RXB1CONBITS;
RXB1CONBITS RXB1CONbits;
#byte RXB1CONbits = 0xF50
#byte RXB1CON = 0xF50

typedef union 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };

      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };
} CANCON_RO1BITS;
CANCON_RO1BITS CANCON_RO1bits;
#byte CANCON_RO1bits = 0xF4F
#byte CANCON_RO1 = 0xF4F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO1BITS;
CANSTAT_RO1BITS CANSTAT_RO1bits;
#byte CANSTAT_RO1bits = 0xF4E
#byte CANSTAT_RO1 = 0xF4E

#byte TXB0D7 = 0xF4D

#byte TXB0D6 = 0xF4C

#byte TXB0D5 = 0xF4B

#byte TXB0D4 = 0xF4A

#byte TXB0D3 = 0xF49

#byte TXB0D2 = 0xF48

#byte TXB0D1 = 0xF47

#byte TXB0D0 = 0xF46

typedef union 
 {
      struct {
         unsigned int DLC0:4;
         unsigned int :2;
         unsigned int TXRTR:1;
      };
      struct {
         unsigned int DLC:4;
         unsigned int :2;
      };
} TXB0DLCBITS;
TXB0DLCBITS TXB0DLCbits;
#byte TXB0DLCbits = 0xF45
#byte TXB0DLC = 0xF45

#byte TXB0EIDL = 0xF44

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} TXB0EIDHBITS;
TXB0EIDHBITS TXB0EIDHbits;
#byte TXB0EIDHbits = 0xF43
#byte TXB0EIDH = 0xF43

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} TXB0SIDLBITS;
TXB0SIDLBITS TXB0SIDLbits;
#byte TXB0SIDLbits = 0xF42
#byte TXB0SIDL = 0xF42

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} TXB0SIDHBITS;
TXB0SIDHBITS TXB0SIDHbits;
#byte TXB0SIDHbits = 0xF41
#byte TXB0SIDH = 0xF41

typedef union 
 {
      struct {
         unsigned int TXPRI0:2;
         unsigned int :1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
      struct {
         unsigned int TXPRI:2;
      };
} TXB0CONBITS;
TXB0CONBITS TXB0CONbits;
#byte TXB0CONbits = 0xF40
#byte TXB0CON = 0xF40

typedef union 
 {
   union {
      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };

      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };
} CANCON_RO2BITS;
CANCON_RO2BITS CANCON_RO2bits;
#byte CANCON_RO2bits = 0xF3F
#byte CANCON_RO2 = 0xF3F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO2BITS;
CANSTAT_RO2BITS CANSTAT_RO2bits;
#byte CANSTAT_RO2bits = 0xF3E
#byte CANSTAT_RO2 = 0xF3E

#byte TXB1D7 = 0xF3D

#byte TXB1D6 = 0xF3C

#byte TXB1D5 = 0xF3B

#byte TXB1D4 = 0xF3A

#byte TXB1D3 = 0xF39

#byte TXB1D2 = 0xF38

#byte TXB1D1 = 0xF37

#byte TXB1D0 = 0xF36

typedef union 
 {
      struct {
         unsigned int DLC0:4;
         unsigned int :2;
         unsigned int TXRTR:1;
      };
      struct {
         unsigned int DLC:4;
         unsigned int :2;
      };
} TXB1DLCBITS;
TXB1DLCBITS TXB1DLCbits;
#byte TXB1DLCbits = 0xF35
#byte TXB1DLC = 0xF35

#byte TXB1EIDL = 0xF34

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} TXB1EIDHBITS;
TXB1EIDHBITS TXB1EIDHbits;
#byte TXB1EIDHbits = 0xF33
#byte TXB1EIDH = 0xF33

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} TXB1SIDLBITS;
TXB1SIDLBITS TXB1SIDLbits;
#byte TXB1SIDLbits = 0xF32
#byte TXB1SIDL = 0xF32

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} TXB1SIDHBITS;
TXB1SIDHBITS TXB1SIDHbits;
#byte TXB1SIDHbits = 0xF31
#byte TXB1SIDH = 0xF31

typedef union 
 {
   union {
      struct {
         unsigned int TXPRI0:2;
         unsigned int :1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
      struct {
         unsigned int TXPRI:2;
      };

      struct {
         unsigned int :7;
         unsigned int TXBIFTXB1CON:1;
      };
   };
} TXB1CONBITS;
TXB1CONBITS TXB1CONbits;
#byte TXB1CONbits = 0xF30
#byte TXB1CON = 0xF30

typedef union 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };

      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };
} CANCON_RO3BITS;
CANCON_RO3BITS CANCON_RO3bits;
#byte CANCON_RO3bits = 0xF2F
#byte CANCON_RO3 = 0xF2F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO3BITS;
CANSTAT_RO3BITS CANSTAT_RO3bits;
#byte CANSTAT_RO3bits = 0xF2E
#byte CANSTAT_RO3 = 0xF2E

#byte TXB2D7 = 0xF2D

#byte TXB2D6 = 0xF2C

#byte TXB2D5 = 0xF2B

#byte TXB2D4 = 0xF2A

#byte TXB2D3 = 0xF29

#byte TXB2D2 = 0xF28

#byte TXB2D1 = 0xF27

#byte TXB2D0 = 0xF26

typedef union 
 {
      struct {
         unsigned int DLC0:4;
         unsigned int :2;
         unsigned int TXRTR:1;
      };
      struct {
         unsigned int DLC:4;
         unsigned int :2;
      };
} TXB2DLCBITS;
TXB2DLCBITS TXB2DLCbits;
#byte TXB2DLCbits = 0xF25
#byte TXB2DLC = 0xF25

#byte TXB2EIDL = 0xF24

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} TXB2EIDHBITS;
TXB2EIDHBITS TXB2EIDHbits;
#byte TXB2EIDHbits = 0xF23
#byte TXB2EIDH = 0xF23

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} TXB2SIDLBITS;
TXB2SIDLBITS TXB2SIDLbits;
#byte TXB2SIDLbits = 0xF22
#byte TXB2SIDL = 0xF22

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} TXB2SIDHBITS;
TXB2SIDHBITS TXB2SIDHbits;
#byte TXB2SIDHbits = 0xF21
#byte TXB2SIDH = 0xF21

typedef struct 
 {
   union {
      struct {
         unsigned int :7;
         unsigned int TXBIFBXB2CON:1;
      };

      struct {
         unsigned int TXPRI0:2;
         unsigned int :1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };
} TXB2CONBITS;
TXB2CONBITS TXB2CONbits;
#byte TXB2CONbits = 0xF20
#byte TXB2CON = 0xF20

#byte RXM1EIDL = 0xF1F

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXM1EIDHBITS;
RXM1EIDHBITS RXM1EIDHbits;
#byte RXM1EIDHbits = 0xF1E
#byte RXM1EIDH = 0xF1E

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXM1SIDLBITS;
RXM1SIDLBITS RXM1SIDLbits;
#byte RXM1SIDLbits = 0xF1D
#byte RXM1SIDL = 0xF1D

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXM1SIDHBITS;
RXM1SIDHBITS RXM1SIDHbits;
#byte RXM1SIDHbits = 0xF1C
#byte RXM1SIDH = 0xF1C

#byte RXM0EIDL = 0xF1B

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXM0EIDHBITS;
RXM0EIDHBITS RXM0EIDHbits;
#byte RXM0EIDHbits = 0xF1A
#byte RXM0EIDH = 0xF1A

typedef union 
 {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXM0SIDLBITS;
RXM0SIDLBITS RXM0SIDLbits;
#byte RXM0SIDLbits = 0xF19
#byte RXM0SIDL = 0xF19

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXM0SIDHBITS;
RXM0SIDHBITS RXM0SIDHbits;
#byte RXM0SIDHbits = 0xF18
#byte RXM0SIDH = 0xF18

#byte RXF5EIDL = 0xF17

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF5EIDHBITS;
RXF5EIDHBITS RXF5EIDHbits;
#byte RXF5EIDHbits = 0xF16
#byte RXF5EIDH = 0xF16

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF5SIDLBITS;
RXF5SIDLBITS RXF5SIDLbits;
#byte RXF5SIDLbits = 0xF15
#byte RXF5SIDL = 0xF15

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF5SIDHBITS;
RXF5SIDHBITS RXF5SIDHbits;
#byte RXF5SIDHbits = 0xF14
#byte RXF5SIDH = 0xF14

#byte RXF4EIDL = 0xF13

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF4EIDHBITS;
RXF4EIDHBITS RXF4EIDHbits;
#byte RXF4EIDHbits = 0xF12
#byte RXF4EIDH = 0xF12

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF4SIDLBITS;
RXF4SIDLBITS RXF4SIDLbits;
#byte RXF4SIDLbits = 0xF11
#byte RXF4SIDL = 0xF11

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF4SIDHBITS;
RXF4SIDHBITS RXF4SIDHbits;
#byte RXF4SIDHbits = 0xF10
#byte RXF4SIDH = 0xF10

#byte RXF3EIDL = 0xF0F

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF3EIDHBITS;
RXF3EIDHBITS RXF3EIDHbits;
#byte RXF3EIDHbits = 0xF0E
#byte RXF3EIDH = 0xF0E

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF3SIDLBITS;
RXF3SIDLBITS RXF3SIDLbits;
#byte RXF3SIDLbits = 0xF0D
#byte RXF3SIDL = 0xF0D

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF3SIDHBITS;
RXF3SIDHBITS RXF3SIDHbits;
#byte RXF3SIDHbits = 0xF0C
#byte RXF3SIDH = 0xF0C

#byte RXF2EIDL = 0xF0B

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF2EIDHBITS;
RXF2EIDHBITS RXF2EIDHbits;
#byte RXF2EIDHbits = 0xF0A
#byte RXF2EIDH = 0xF0A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF2SIDLBITS;
RXF2SIDLBITS RXF2SIDLbits;
#byte RXF2SIDLbits = 0xF09
#byte RXF2SIDL = 0xF09

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF2SIDHBITS;
RXF2SIDHBITS RXF2SIDHbits;
#byte RXF2SIDHbits = 0xF08
#byte RXF2SIDH = 0xF08

#byte RXF1EIDL = 0xF07

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF1EIDHBITS;
RXF1EIDHBITS RXF1EIDHbits;
#byte RXF1EIDHbits = 0xF06
#byte RXF1EIDH = 0xF06

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF1SIDLBITS;
RXF1SIDLBITS RXF1SIDLbits;
#byte RXF1SIDLbits = 0xF05
#byte RXF1SIDL = 0xF05

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF1SIDHBITS;
RXF1SIDHBITS RXF1SIDHbits;
#byte RXF1SIDHbits = 0xF04
#byte RXF1SIDH = 0xF04

#byte RXF0EIDL = 0xF03

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF0EIDHBITS;
RXF0EIDHBITS RXF0EIDHbits;
#byte RXF0EIDHbits = 0xF02
#byte RXF0EIDH = 0xF02

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF0SIDLBITS;
RXF0SIDLBITS RXF0SIDLbits;
#byte RXF0SIDLbits = 0xF01
#byte RXF0SIDL = 0xF01

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF0SIDHBITS;
RXF0SIDHBITS RXF0SIDHbits;
#byte RXF0SIDHbits = 0xF00
#byte RXF0SIDH = 0xF00

typedef union 
 {
   union {
      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };

      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };
} CANCON_RO4BITS;
CANCON_RO4BITS CANCON_RO4bits;
#byte CANCON_RO4bits = 0xE7F
#byte CANCON_RO4 = 0xE7F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO4BITS;
CANSTAT_RO4BITS CANSTAT_RO4bits;
#byte CANSTAT_RO4bits = 0xE7E
#byte CANSTAT_RO4 = 0xE7E

#byte B5D7 = 0xE7D

#byte B5D6 = 0xE7C

#byte B5D5 = 0xE7B

#byte B5D4 = 0xE7A

#byte B5D3 = 0xE79

#byte B5D2 = 0xE78

typedef struct 
 {
   unsigned int :3;
   unsigned int B57D23:1;
} B5D2BITS;
B5D2BITS B5D2bits;
#byte B5D2bits = 0xE78
#byte B5D2 = 0xE78

#byte B5D1 = 0xE77

#byte B5D0 = 0xE76

typedef struct 
 {
   unsigned int :7;
   unsigned int B57D07:1;
} B5D0BITS;
B5D0BITS B5D0bits;
#byte B5D0bits = 0xE76
#byte B5D0 = 0xE76

typedef union 
 {
   union {
      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
         unsigned int RXRTR:1;
      };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };

      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR_TXRTR:1;
      };
   };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };
} B5DLCBITS;
B5DLCBITS B5DLCbits;
#byte B5DLCbits = 0xE75
#byte B5DLC = 0xE75

#byte B5EIDL = 0xE74

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} B5EIDHBITS;
B5EIDHBITS B5EIDHbits;
#byte B5EIDHbits = 0xE73
#byte B5EIDH = 0xE73

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDEN:1;
      };

   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXID:1;
      };
   };
} B5SIDLBITS;
B5SIDLBITS B5SIDLbits;
#byte B5SIDLbits = 0xE72
#byte B5SIDL = 0xE72

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} B5SIDHBITS;
B5SIDHBITS B5SIDHbits;
#byte B5SIDHbits = 0xE71
#byte B5SIDH = 0xE71

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int RXRTRRO:1;
      };

   union {
      struct {
         unsigned int TXPRI0:2;
         unsigned int RTREN:1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };

   union {
      struct {
         unsigned int FILHIT0:5;
         unsigned int RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:5;
      };

      struct {
         unsigned int FILHIT0_TXPRI0:1;
         unsigned int FILHIT1_TXPRI1:1;
         unsigned int FILHIT2_RTREN:1;
         unsigned int FILHIT3_TXREQ:1;
         unsigned int FILHIT4_TXERR:1;
         unsigned int RXRTRRO_TXLARB:1;
         unsigned int RXM1_TXABT:1;
         unsigned int RXFUL_TXBIF:1;
      };
   };
} B5CONBITS;
B5CONBITS B5CONbits;
#byte B5CONbits = 0xE70
#byte B5CON = 0xE70

typedef union 
 {
   union {
      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };

      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };
} CANCON_RO5BITS;
CANCON_RO5BITS CANCON_RO5bits;
#byte CANCON_RO5bits = 0xE6F
#byte CANCON_RO5 = 0xE6F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO5BITS;
CANSTAT_RO5BITS CANSTAT_RO5bits;
#byte CANSTAT_RO5bits = 0xE6E
#byte CANSTAT_RO5 = 0xE6E

#byte B4D7 = 0xE6D

typedef struct 
 {
   unsigned int :7;
   unsigned int B46D77:1;
} B4D7BITS;
B4D7BITS B4D7bits;
#byte B4D7bits = 0xE6D
#byte B4D7 = 0xE6D

#byte B4D6 = 0xE6C

#byte B4D5 = 0xE6B

#byte B4D4 = 0xE6A

#byte B4D3 = 0xE69

#byte B4D2 = 0xE68

#byte B4D1 = 0xE67

#byte B4D0 = 0xE66

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RXRTR:1;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
         unsigned int TXRTR:1;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };

      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR_TXRTR:1;
      };
   };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };
} B4DLCBITS;
B4DLCBITS B4DLCbits;
#byte B4DLCbits = 0xE65
#byte B4DLC = 0xE65

#byte B4EIDL = 0xE64

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} B4EIDHBITS;
B4EIDHBITS B4EIDHbits;
#byte B4EIDHbits = 0xE63
#byte B4EIDH = 0xE63

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXID:1;
      };
   };
} B4SIDLBITS;
B4SIDLBITS B4SIDLbits;
#byte B4SIDLbits = 0xE62
#byte B4SIDL = 0xE62

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} B4SIDHBITS;
B4SIDHBITS B4SIDHbits;
#byte B4SIDHbits = 0xE61
#byte B4SIDH = 0xE61

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int RXRTRRO:1;
      };

   union {
      struct {
         unsigned int FILHIT0_TXPRI0:1;
         unsigned int FILHIT1_TXPRI1:1;
         unsigned int FILHIT2_RTREN:1;
         unsigned int FILHIT3_TXREQ:1;
         unsigned int FILHIT4_TXERR:1;
         unsigned int RXRTRRO_TXLARB:1;
         unsigned int RXM1_TXABT:1;
         unsigned int RXFUL_TXBIF:1;
      };
   };

   union {
      struct {
         unsigned int FILHIT0:5;
         unsigned int RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:5;
      };

      struct {
         unsigned int TXPRI0:2;
         unsigned int RTREN:1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };
} B4CONBITS;
B4CONBITS B4CONbits;
#byte B4CONbits = 0xE60
#byte B4CON = 0xE60

typedef union 
 {
   union {
      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };

      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };
} CANCON_RO6BITS;
CANCON_RO6BITS CANCON_RO6bits;
#byte CANCON_RO6bits = 0xE5F
#byte CANCON_RO6 = 0xE5F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO6BITS;
CANSTAT_RO6BITS CANSTAT_RO6bits;
#byte CANSTAT_RO6bits = 0xE5E
#byte CANSTAT_RO6 = 0xE5E

#byte B3D7 = 0xE5D

#byte B3D6 = 0xE5C

#byte B3D5 = 0xE5B

#byte B3D4 = 0xE5A

#byte B3D3 = 0xE59

#byte B3D2 = 0xE58

#byte B3D1 = 0xE57

#byte B3D0 = 0xE56

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RXRTR:1;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
         unsigned int TXRTR:1;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };

      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR_TXRTR:1;
      };
   };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };
} B3DLCBITS;
B3DLCBITS B3DLCbits;
#byte B3DLCbits = 0xE55
#byte B3DLC = 0xE55

#byte B3EIDL = 0xE54

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} B3EIDHBITS;
B3EIDHBITS B3EIDHbits;
#byte B3EIDHbits = 0xE53
#byte B3EIDH = 0xE53

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXID:1;
      };
   };
} B3SIDLBITS;
B3SIDLBITS B3SIDLbits;
#byte B3SIDLbits = 0xE52
#byte B3SIDL = 0xE52

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} B3SIDHBITS;
B3SIDHBITS B3SIDHbits;
#byte B3SIDHbits = 0xE51
#byte B3SIDH = 0xE51

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int RXRTRRO:1;
      };

   union {
      struct {
         unsigned int TXPRI0:2;
         unsigned int RTREN:1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };

   union {
      struct {
         unsigned int FILHIT0_TXPRI0:1;
         unsigned int FILHIT1_TXPRI1:1;
         unsigned int FILHIT2_RTREN:1;
         unsigned int FILHIT3_TXREQ:1;
         unsigned int FILHIT4_TXERR:1;
         unsigned int RXRTRRO_TXLARB:1;
         unsigned int RXM1_TXABT:1;
         unsigned int RXFUL_TXBIF:1;
      };
   };

      struct {
         unsigned int FILHIT0:5;
         unsigned int RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:5;
      };
} B3CONBITS;
B3CONBITS B3CONbits;
#byte B3CONbits = 0xE50
#byte B3CON = 0xE50

typedef union 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };

      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };
} CANCON_RO7BITS;
CANCON_RO7BITS CANCON_RO7bits;
#byte CANCON_RO7bits = 0xE4F
#byte CANCON_RO7 = 0xE4F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO7BITS;
CANSTAT_RO7BITS CANSTAT_RO7bits;
#byte CANSTAT_RO7bits = 0xE4E
#byte CANSTAT_RO7 = 0xE4E

#byte B2D7 = 0xE4D

#byte B2D6 = 0xE4C

#byte B2D5 = 0xE4B

#byte B2D4 = 0xE4A

#byte B2D3 = 0xE49

#byte B2D2 = 0xE48

#byte B2D1 = 0xE47

#byte B2D0 = 0xE46

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RXRTR:1;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
         unsigned int TXRTR:1;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };

      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR_TXRTR:1;
      };
   };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };
} B2DLCBITS;
B2DLCBITS B2DLCbits;
#byte B2DLCbits = 0xE45
#byte B2DLC = 0xE45

#byte B2EIDL = 0xE44

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} B2EIDHBITS;
B2EIDHBITS B2EIDHbits;
#byte B2EIDHbits = 0xE43
#byte B2EIDH = 0xE43

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXID:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} B2SIDLBITS;
B2SIDLBITS B2SIDLbits;
#byte B2SIDLbits = 0xE42
#byte B2SIDL = 0xE42

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} B2SIDHBITS;
B2SIDHBITS B2SIDHbits;
#byte B2SIDHbits = 0xE41
#byte B2SIDH = 0xE41

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int RXRTRRO:1;
      };

   union {
      struct {
         unsigned int TXPRI0:2;
         unsigned int RTREN:1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };

   union {
      struct {
         unsigned int FILHIT0_TXPRI0:1;
         unsigned int FILHIT1_TXPRI1:1;
         unsigned int FILHIT2_RTREN:1;
         unsigned int FILHIT3_TXREQ:1;
         unsigned int FILHIT4_TXERR:1;
         unsigned int RXRTRRO_TXLARB:1;
         unsigned int RXM1_TXABT:1;
         unsigned int RXFUL_TXBIF:1;
      };
   };

      struct {
         unsigned int FILHIT0:5;
         unsigned int RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:5;
      };
} B2CONBITS;
B2CONBITS B2CONbits;
#byte B2CONbits = 0xE40
#byte B2CON = 0xE40

typedef union 
 {
   union {
      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };

      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };
} CANCON_RO8BITS;
CANCON_RO8BITS CANCON_RO8bits;
#byte CANCON_RO8bits = 0xE3F
#byte CANCON_RO8 = 0xE3F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO8BITS;
CANSTAT_RO8BITS CANSTAT_RO8bits;
#byte CANSTAT_RO8bits = 0xE3E
#byte CANSTAT_RO8 = 0xE3E

#byte B1D7 = 0xE3D

#byte B1D6 = 0xE3C

#byte B1D5 = 0xE3B

#byte B1D4 = 0xE3A

#byte B1D3 = 0xE39

#byte B1D2 = 0xE38

#byte B1D1 = 0xE37

#byte B1D0 = 0xE36

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RXRTR:1;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
         unsigned int TXRTR:1;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };

      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR_TXRTR:1;
      };
   };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };
} B1DLCBITS;
B1DLCBITS B1DLCbits;
#byte B1DLCbits = 0xE35
#byte B1DLC = 0xE35

#byte B1EIDL = 0xE34

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} B1EIDHBITS;
B1EIDHBITS B1EIDHbits;
#byte B1EIDHbits = 0xE33
#byte B1EIDH = 0xE33

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXID:1;
      };
   };
} B1SIDLBITS;
B1SIDLBITS B1SIDLbits;
#byte B1SIDLbits = 0xE32
#byte B1SIDL = 0xE32

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} B1SIDHBITS;
B1SIDHBITS B1SIDHbits;
#byte B1SIDHbits = 0xE31
#byte B1SIDH = 0xE31

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int RXRTRRO:1;
      };

   union {
      struct {
         unsigned int TXPRI0:2;
         unsigned int RTREN:1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };

   union {
      struct {
         unsigned int FILHIT0:5;
         unsigned int RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:5;
      };

      struct {
         unsigned int FILHIT0_TXPRI0:1;
         unsigned int FILHIT1_TXPRI1:1;
         unsigned int FILHIT2_RTREN:1;
         unsigned int FILHIT3_TXREQ:1;
         unsigned int FILHIT4_TXERR:1;
         unsigned int RXRTRRO_TXLARB:1;
         unsigned int RXM1_TXABT:1;
         unsigned int RXFUL_TXBIF:1;
      };
   };
} B1CONBITS;
B1CONBITS B1CONbits;
#byte B1CONbits = 0xE30
#byte B1CON = 0xE30

typedef union 
 {
   union {
      struct {
         unsigned int FP0:1;
         unsigned int WIN0_FP1:1;
         unsigned int WIN1_FP2:1;
         unsigned int WIN2_FP3:1;
         unsigned int ABAT:1;
         unsigned int REQOP0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int REQOP:3;
      };

      struct {
         unsigned int :1;
         unsigned int WIN0:3;
      };
   };
      struct {
         unsigned int :1;
         unsigned int WIN:3;
      };
} CANCON_RO9BITS;
CANCON_RO9BITS CANCON_RO9bits;
#byte CANCON_RO9bits = 0xE2F
#byte CANCON_RO9 = 0xE2F

typedef union 
 {
      struct {
         unsigned int EICODE0:1;
         unsigned int EICODE1_ICODE0:1;
         unsigned int EICODE2_ICODE1:1;
         unsigned int EICODE3_ICODE2:1;
         unsigned int EICODE4:1;
         unsigned int OPMODE0:3;
      };
      struct {
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int OPMODE:3;
      };
} CANSTAT_RO9BITS;
CANSTAT_RO9BITS CANSTAT_RO9bits;
#byte CANSTAT_RO9bits = 0xE2E
#byte CANSTAT_RO9 = 0xE2E

#byte B0D7 = 0xE2D

#byte B0D6 = 0xE2C

#byte B0D5 = 0xE2B

#byte B0D4 = 0xE2A

#byte B0D3 = 0xE29

#byte B0D2 = 0xE28

#byte B0D1 = 0xE27

#byte B0D0 = 0xE26

typedef struct 
 {
   union {
      struct {
         unsigned int :6;
         unsigned int RXRTR:1;
      };

   union {
      struct {
         unsigned int :4;
         unsigned int RESRB0:2;
         unsigned int TXRTR:1;
      };
   };
      struct {
         unsigned int :4;
         unsigned int RESRB:2;
      };

      struct {
         unsigned int DLC0:4;
         unsigned int RB0:2;
         unsigned int RXRTR_TXRTR:1;
      };
   };
      struct {
         unsigned int DLC:4;
         unsigned int RB:2;
      };
} B0DLCBITS;
B0DLCBITS B0DLCbits;
#byte B0DLCbits = 0xE25
#byte B0DLC = 0xE25

#byte B0EIDL = 0xE24

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} B0EIDHBITS;
B0EIDHBITS B0EIDHbits;
#byte B0EIDHbits = 0xE23
#byte B0EIDH = 0xE23

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXID:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDE:1;
         unsigned int SRR:1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} B0SIDLBITS;
B0SIDLBITS B0SIDLbits;
#byte B0SIDLbits = 0xE22
#byte B0SIDL = 0xE22

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} B0SIDHBITS;
B0SIDHBITS B0SIDHbits;
#byte B0SIDHbits = 0xE21
#byte B0SIDH = 0xE21

typedef struct 
 {
   union {
      struct {
         unsigned int :5;
         unsigned int RXRTRRO:1;
      };

   union {
      struct {
         unsigned int TXPRI0:2;
         unsigned int RTREN:1;
         unsigned int TXREQ:1;
         unsigned int TXERR:1;
         unsigned int TXLARB:1;
         unsigned int TXABT:1;
         unsigned int TXBIF:1;
      };
   };
      struct {
         unsigned int TXPRI:2;
      };

   union {
      struct {
         unsigned int FILHIT0_TXPRI0:1;
         unsigned int FILHIT1_TXPRI1:1;
         unsigned int FILHIT2_RTREN:1;
         unsigned int FILHIT3_TXREQ:1;
         unsigned int FILHIT4_TXERR:1;
         unsigned int RXRTRRO_TXLARB:1;
         unsigned int RXM1_TXABT:1;
         unsigned int RXFUL_TXBIF:1;
      };
   };

      struct {
         unsigned int FILHIT0:5;
         unsigned int RTRRO:1;
         unsigned int RXM1:1;
         unsigned int RXFUL:1;
      };
   };
      struct {
         unsigned int FILHIT:5;
      };
} B0CONBITS;
B0CONBITS B0CONbits;
#byte B0CONbits = 0xE20
#byte B0CON = 0xE20

typedef struct 
 {
   unsigned int :2;
   unsigned int TXB0IE:1;
   unsigned int TXB1IE:1;
   unsigned int TXB2IE:1;
} TXBIEBITS;
TXBIEBITS TXBIEbits;
#byte TXBIEbits = 0xDFC
#byte TXBIE = 0xDFC

typedef struct 
 {
   unsigned int RXB0IE:1;
   unsigned int RXB1IE:1;
   unsigned int B0IE:1;
   unsigned int B1IE:1;
   unsigned int B2IE:1;
   unsigned int B3IE:1;
   unsigned int B4IE:1;
   unsigned int B5IE:1;
} BIE0BITS;
BIE0BITS BIE0bits;
#byte BIE0bits = 0xDFA
#byte BIE0 = 0xDFA

typedef struct 
 {
   unsigned int :2;
   unsigned int B0TXEN:1;
   unsigned int B1TXEN:1;
   unsigned int B2TXEN:1;
   unsigned int B3TXEN:1;
   unsigned int B4TXEN:1;
   unsigned int B5TXEN:1;
} BSEL0BITS;
BSEL0BITS BSEL0bits;
#byte BSEL0bits = 0xDF8
#byte BSEL0 = 0xDF8

typedef union 
 {
      struct {
         unsigned int FIL12_0:2;
         unsigned int FIL13_0:2;
         unsigned int FIL14_0:2;
         unsigned int FIL15_0:2;
      };
      struct {
         unsigned int FIL12_:2;
         unsigned int FIL13_:2;
         unsigned int FIL14_:2;
         unsigned int FIL15_:2;
      };
} MSEL3BITS;
MSEL3BITS MSEL3bits;
#byte MSEL3bits = 0xDF3
#byte MSEL3 = 0xDF3

typedef union 
 {
      struct {
         unsigned int FIL8_0:2;
         unsigned int FIL9_0:2;
         unsigned int FIL10_0:2;
         unsigned int FIL11_0:2;
      };
      struct {
         unsigned int FIL8_:2;
         unsigned int FIL9_:2;
         unsigned int FIL10_:2;
         unsigned int FIL11_:2;
      };
} MSEL2BITS;
MSEL2BITS MSEL2bits;
#byte MSEL2bits = 0xDF2
#byte MSEL2 = 0xDF2

typedef union 
 {
      struct {
         unsigned int FIL4_0:2;
         unsigned int FIL5_0:2;
         unsigned int FIL6_0:2;
         unsigned int FIL7_0:2;
      };
      struct {
         unsigned int FIL4_:2;
         unsigned int FIL5_:2;
         unsigned int FIL6_:2;
         unsigned int FIL7_:2;
      };
} MSEL1BITS;
MSEL1BITS MSEL1bits;
#byte MSEL1bits = 0xDF1
#byte MSEL1 = 0xDF1

typedef union 
 {
      struct {
         unsigned int FIL0_0:2;
         unsigned int FIL1_0:2;
         unsigned int FIL2_0:2;
         unsigned int FIL3_0:2;
      };
      struct {
         unsigned int FIL0_:2;
         unsigned int FIL1_:2;
         unsigned int FIL2_:2;
         unsigned int FIL3_:2;
      };
} MSEL0BITS;
MSEL0BITS MSEL0bits;
#byte MSEL0bits = 0xDF0
#byte MSEL0 = 0xDF0

typedef union 
 {
      struct {
         unsigned int F14BP_0:4;
         unsigned int F15BP_0:4;
      };
      struct {
         unsigned int F14BP_:4;
         unsigned int F15BP_:4;
      };
} RXFBCON7BITS;
RXFBCON7BITS RXFBCON7bits;
#byte RXFBCON7bits = 0xDE7
#byte RXFBCON7 = 0xDE7

typedef union 
 {
      struct {
         unsigned int F12BP_0:4;
         unsigned int F13BP_0:4;
      };
      struct {
         unsigned int F12BP_:4;
         unsigned int F13BP_:4;
      };
} RXFBCON6BITS;
RXFBCON6BITS RXFBCON6bits;
#byte RXFBCON6bits = 0xDE6
#byte RXFBCON6 = 0xDE6

typedef union 
 {
      struct {
         unsigned int F10BP_0:4;
         unsigned int F11BP_0:4;
      };
      struct {
         unsigned int F10BP_:4;
         unsigned int F11BP_:4;
      };
} RXFBCON5BITS;
RXFBCON5BITS RXFBCON5bits;
#byte RXFBCON5bits = 0xDE5
#byte RXFBCON5 = 0xDE5

typedef union 
 {
      struct {
         unsigned int F8BP_0:4;
         unsigned int F9BP_0:4;
      };
      struct {
         unsigned int F8BP_:4;
         unsigned int F9BP_:4;
      };
} RXFBCON4BITS;
RXFBCON4BITS RXFBCON4bits;
#byte RXFBCON4bits = 0xDE4
#byte RXFBCON4 = 0xDE4

typedef union 
 {
      struct {
         unsigned int F6BP_0:4;
         unsigned int F7BP_0:4;
      };
      struct {
         unsigned int F6BP_:4;
         unsigned int F7BP_:4;
      };
} RXFBCON3BITS;
RXFBCON3BITS RXFBCON3bits;
#byte RXFBCON3bits = 0xDE3
#byte RXFBCON3 = 0xDE3

typedef union 
 {
      struct {
         unsigned int F4BP_0:4;
         unsigned int F5BP_0:4;
      };
      struct {
         unsigned int F4BP_:4;
         unsigned int F5BP_:4;
      };
} RXFBCON2BITS;
RXFBCON2BITS RXFBCON2bits;
#byte RXFBCON2bits = 0xDE2
#byte RXFBCON2 = 0xDE2

typedef union 
 {
      struct {
         unsigned int F2BP_0:4;
         unsigned int F3BP_0:4;
      };
      struct {
         unsigned int F2BP_:4;
         unsigned int F3BP_:4;
      };
} RXFBCON1BITS;
RXFBCON1BITS RXFBCON1bits;
#byte RXFBCON1bits = 0xDE1
#byte RXFBCON1 = 0xDE1

typedef union 
 {
      struct {
         unsigned int F0BP_0:4;
         unsigned int F1BP_0:4;
      };
      struct {
         unsigned int F0BP_:4;
         unsigned int F1BP_:4;
      };
} RXFBCON0BITS;
RXFBCON0BITS RXFBCON0bits;
#byte RXFBCON0bits = 0xDE0
#byte RXFBCON0 = 0xDE0

#byte SDFLC = 0xDD8

typedef struct 
 {
   unsigned int RXF8EN:1;
   unsigned int RXF9EN:1;
   unsigned int RXF10EN:1;
   unsigned int RXF11EN:1;
   unsigned int RXF12EN:1;
   unsigned int RXF13EN:1;
   unsigned int RXF14EN:1;
   unsigned int RXF15EN:1;
} RXFCON1BITS;
RXFCON1BITS RXFCON1bits;
#byte RXFCON1bits = 0xDD5
#byte RXFCON1 = 0xDD5

typedef struct 
 {
   unsigned int RXF0EN:1;
   unsigned int RXF1EN:1;
   unsigned int RXF2EN:1;
   unsigned int RXF3EN:1;
   unsigned int RXF4EN:1;
   unsigned int RXF5EN:1;
   unsigned int RXF6EN:1;
   unsigned int RXF7EN:1;
} RXFCON0BITS;
RXFCON0BITS RXFCON0bits;
#byte RXFCON0bits = 0xDD4
#byte RXFCON0 = 0xDD4

#byte RXF15EIDL = 0xD93

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF15EIDHBITS;
RXF15EIDHBITS RXF15EIDHbits;
#byte RXF15EIDHbits = 0xD92
#byte RXF15EIDH = 0xD92

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF15SIDLBITS;
RXF15SIDLBITS RXF15SIDLbits;
#byte RXF15SIDLbits = 0xD91
#byte RXF15SIDL = 0xD91

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF15SIDHBITS;
RXF15SIDHBITS RXF15SIDHbits;
#byte RXF15SIDHbits = 0xD90
#byte RXF15SIDH = 0xD90

#byte RXF14EIDL = 0xD8B

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF14EIDHBITS;
RXF14EIDHBITS RXF14EIDHbits;
#byte RXF14EIDHbits = 0xD8A
#byte RXF14EIDH = 0xD8A

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF14SIDLBITS;
RXF14SIDLBITS RXF14SIDLbits;
#byte RXF14SIDLbits = 0xD89
#byte RXF14SIDL = 0xD89

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF14SIDHBITS;
RXF14SIDHBITS RXF14SIDHbits;
#byte RXF14SIDHbits = 0xD88
#byte RXF14SIDH = 0xD88

#byte RXF13EIDL = 0xD87

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF13EIDHBITS;
RXF13EIDHBITS RXF13EIDHbits;
#byte RXF13EIDHbits = 0xD86
#byte RXF13EIDH = 0xD86

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF13SIDLBITS;
RXF13SIDLBITS RXF13SIDLbits;
#byte RXF13SIDLbits = 0xD85
#byte RXF13SIDL = 0xD85

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF13SIDHBITS;
RXF13SIDHBITS RXF13SIDHbits;
#byte RXF13SIDHbits = 0xD84
#byte RXF13SIDH = 0xD84

#byte RXF12EIDL = 0xD83

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF12EIDHBITS;
RXF12EIDHBITS RXF12EIDHbits;
#byte RXF12EIDHbits = 0xD82
#byte RXF12EIDH = 0xD82

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF12SIDLBITS;
RXF12SIDLBITS RXF12SIDLbits;
#byte RXF12SIDLbits = 0xD81
#byte RXF12SIDL = 0xD81

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF12SIDHBITS;
RXF12SIDHBITS RXF12SIDHbits;
#byte RXF12SIDHbits = 0xD80
#byte RXF12SIDH = 0xD80

#byte RXF11EIDL = 0xD7B

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF11EIDHBITS;
RXF11EIDHBITS RXF11EIDHbits;
#byte RXF11EIDHbits = 0xD7A
#byte RXF11EIDH = 0xD7A

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF11SIDLBITS;
RXF11SIDLBITS RXF11SIDLbits;
#byte RXF11SIDLbits = 0xD79
#byte RXF11SIDL = 0xD79

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF11SIDHBITS;
RXF11SIDHBITS RXF11SIDHbits;
#byte RXF11SIDHbits = 0xD78
#byte RXF11SIDH = 0xD78

#byte RXF10EIDL = 0xD77

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF10EIDHBITS;
RXF10EIDHBITS RXF10EIDHbits;
#byte RXF10EIDHbits = 0xD76
#byte RXF10EIDH = 0xD76

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF10SIDLBITS;
RXF10SIDLBITS RXF10SIDLbits;
#byte RXF10SIDLbits = 0xD75
#byte RXF10SIDL = 0xD75

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF10SIDHBITS;
RXF10SIDHBITS RXF10SIDHbits;
#byte RXF10SIDHbits = 0xD74
#byte RXF10SIDH = 0xD74

#byte RXF9EIDL = 0xD73

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF9EIDHBITS;
RXF9EIDHBITS RXF9EIDHbits;
#byte RXF9EIDHbits = 0xD72
#byte RXF9EIDH = 0xD72

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF9SIDLBITS;
RXF9SIDLBITS RXF9SIDLbits;
#byte RXF9SIDLbits = 0xD71
#byte RXF9SIDL = 0xD71

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF9SIDHBITS;
RXF9SIDHBITS RXF9SIDHbits;
#byte RXF9SIDHbits = 0xD70
#byte RXF9SIDH = 0xD70

#byte RXF8EIDL = 0xD6B

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF8EIDHBITS;
RXF8EIDHBITS RXF8EIDHbits;
#byte RXF8EIDHbits = 0xD6A
#byte RXF8EIDH = 0xD6A

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF8SIDLBITS;
RXF8SIDLBITS RXF8SIDLbits;
#byte RXF8SIDLbits = 0xD69
#byte RXF8SIDL = 0xD69

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF8SIDHBITS;
RXF8SIDHBITS RXF8SIDHbits;
#byte RXF8SIDHbits = 0xD68
#byte RXF8SIDH = 0xD68

#byte RXF7EIDL = 0xD67

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF7EIDHBITS;
RXF7EIDHBITS RXF7EIDHbits;
#byte RXF7EIDHbits = 0xD66
#byte RXF7EIDH = 0xD66

typedef union 
 {
   union {
      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };

      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };
   };
} RXF7SIDLBITS;
RXF7SIDLBITS RXF7SIDLbits;
#byte RXF7SIDLbits = 0xD65
#byte RXF7SIDL = 0xD65

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF7SIDHBITS;
RXF7SIDHBITS RXF7SIDHbits;
#byte RXF7SIDHbits = 0xD64
#byte RXF7SIDH = 0xD64

#byte RXF6EIDL = 0xD63

typedef struct 
 {
   unsigned int EID8:2;
   unsigned int EID10:6;
} RXF6EIDHBITS;
RXF6EIDHBITS RXF6EIDHbits;
#byte RXF6EIDHbits = 0xD62
#byte RXF6EIDH = 0xD62

typedef struct 
 {
   union {
      struct {
         unsigned int :3;
         unsigned int EXIDE:1;
      };

      struct {
         unsigned int EID16:2;
         unsigned int :1;
         unsigned int EXIDEN:1;
         unsigned int :1;
         unsigned int SID0:3;
      };
   };
      struct {
         unsigned int EID1:2;
         unsigned int :1;
         unsigned int :1;
         unsigned int :1;
         unsigned int SID:3;
      };
} RXF6SIDLBITS;
RXF6SIDLBITS RXF6SIDLbits;
#byte RXF6SIDLbits = 0xD61
#byte RXF6SIDL = 0xD61

typedef struct 
 {
   unsigned int SID3:7;
   unsigned int SID10:1;
} RXF6SIDHBITS;
RXF6SIDHBITS RXF6SIDHbits;
#byte RXF6SIDHbits = 0xD60
#byte RXF6SIDH = 0xD60

