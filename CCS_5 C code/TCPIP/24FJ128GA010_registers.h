#word WREG0 = 0x000

#word WREG1 = 0x002

#word WREG2 = 0x004

#word WREG3 = 0x006

#word WREG4 = 0x008

#word WREG5 = 0x00A

#word WREG6 = 0x00C

#word WREG7 = 0x00E

#word WREG8 = 0x010

#word WREG9 = 0x012

#word WREG10 = 0x014

#word WREG11 = 0x016

#word WREG12 = 0x018

#word WREG13 = 0x01A

#word WREG14 = 0x01C

#word WREG15 = 0x01E

#word SPLIM = 0x020

#word PCL = 0x02E

#word PCH = 0x030

#word TBLPAG = 0x032

#word PSVPAG = 0x034

#word RCOUNT = 0x036

struct SRBITS {
   unsigned int C:1;
   unsigned int Z:1;
   unsigned int OV:1;
   unsigned int N:1;
   unsigned int RA:1;
   unsigned int IPL5:1;
   unsigned int IPL6:1;
   unsigned int IPL7:1;
   unsigned int DC:1;
} SRbits;
#word SRbits = 0x042
#word SR = 0x042

struct CORCONBITS {
   unsigned int :2;
   unsigned int PSV:1;
   unsigned int IPL3:1;
} CORCONbits;
#word CORCONbits = 0x044
#word CORCON = 0x044

#word DISICNT = 0x052

struct CNEN1BITS {
   unsigned int CN0IE:1;
   unsigned int CN1IE:1;
   unsigned int CN2IE:1;
   unsigned int CN3IE:1;
   unsigned int CN4IE:1;
   unsigned int CN5IE:1;
   unsigned int CN6IE:1;
   unsigned int CN7IE:1;
   unsigned int CN8IE:1;
   unsigned int CN9IE:1;
   unsigned int CN10IE:1;
   unsigned int CN11IE:1;
   unsigned int CN12IE:1;
   unsigned int CN13IE:1;
   unsigned int CN14IE:1;
   unsigned int CN15IE:1;
} CNEN1bits;
#word CNEN1bits = 0x060
#word CNEN1 = 0x060

struct CNEN2BITS {
   unsigned int CN16IE:1;
   unsigned int CN17IE:1;
   unsigned int CN18IE:1;
   unsigned int CN19IE:1;
   unsigned int CN20IE:1;
   unsigned int CN21IE:1;
} CNEN2bits;
#word CNEN2bits = 0x062
#word CNEN2 = 0x062

struct CNPU1BITS {
   unsigned int CN0PUE:1;
   unsigned int CN1PUE:1;
   unsigned int CN2PUE:1;
   unsigned int CN3PUE:1;
   unsigned int CN4PUE:1;
   unsigned int CN5PUE:1;
   unsigned int CN6PUE:1;
   unsigned int CN7PUE:1;
   unsigned int CN8PUE:1;
   unsigned int CN9PUE:1;
   unsigned int CN10PUE:1;
   unsigned int CN11PUE:1;
   unsigned int CN12PUE:1;
   unsigned int CN13PUE:1;
   unsigned int CN14PUE:1;
   unsigned int CN15PUE:1;
} CNPU1bits;
#word CNPU1bits = 0x068
#word CNPU1 = 0x068

struct CNPU2BITS {
   unsigned int CN16PUE:1;
   unsigned int CN17PUE:1;
   unsigned int CN18PUE:1;
   unsigned int CN19PUE:1;
   unsigned int CN20PUE:1;
   unsigned int CN21PUE:1;
} CNPU2bits;
#word CNPU2bits = 0x06A
#word CNPU2 = 0x06A

struct INTCON1BITS {
   unsigned int :1;
   unsigned int OSCFAIL:1;
   unsigned int STKERR:1;
   unsigned int ADDRERR:1;
   unsigned int MATHERR:1;
   unsigned int :1;
   unsigned int DIV0ERR:1;
   unsigned int :8;
   unsigned int NSTDIS:1;
} INTCON1bits;
#word INTCON1bits = 0x080
#word INTCON1 = 0x080

struct INTCON2BITS {
   unsigned int INT0EP:1;
   unsigned int INT1EP:1;
   unsigned int INT2EP:1;
   unsigned int INT3EP:1;
   unsigned int INT4EP:1;
   unsigned int :9;
   unsigned int DISI:1;
   unsigned int ALTIVT:1;
} INTCON2bits;
#word INTCON2bits = 0x082
#word INTCON2 = 0x082

struct IFS0BITS {
   unsigned int INT0IF:1;
   unsigned int IC1IF:1;
   unsigned int OC1IF:1;
   unsigned int T1IF:1;
   unsigned int :1;
   unsigned int IC2IF:1;
   unsigned int OC2IF:1;
   unsigned int T2IF:1;
   unsigned int T3IF:1;
   unsigned int SPI1FLTIF:1;
   unsigned int SPI1IF:1;
   unsigned int U1RXIF:1;
   unsigned int U1TXIF:1;
   unsigned int AD1IF:1;
} IFS0bits;
#word IFS0bits = 0x084
#word IFS0 = 0x084

struct IFS1BITS {
   unsigned int SI2C1IF:1;
   unsigned int MI2C1IF:1;
   unsigned int CMPIF:1;
   unsigned int CNIF:1;
   unsigned int INT1IF:1;
   unsigned int :4;
   unsigned int OC3IF:1;
   unsigned int OC4IF:1;
   unsigned int T4IF:1;
   unsigned int T5IF:1;
   unsigned int INT2IF:1;
   unsigned int U2RXIF:1;
   unsigned int U2TXIF:1;
} IFS1bits;
#word IFS1bits = 0x086
#word IFS1 = 0x086

struct IFS2BITS {
   unsigned int SPI2FLTIF:1;
   unsigned int SPI2IF:1;
   unsigned int :3;
   unsigned int IC3IF:1;
   unsigned int IC4IF:1;
   unsigned int IC5IF:1;
   unsigned int :1;
   unsigned int OC5IF:1;
   unsigned int :3;
   unsigned int PMPIF:1;
} IFS2bits;
#word IFS2bits = 0x088
#word IFS2 = 0x088

struct IFS3BITS {
   unsigned int :1;
   unsigned int SI2C2IF:1;
   unsigned int MI2C2IF:1;
   unsigned int :2;
   unsigned int INT3IF:1;
   unsigned int INT4IF:1;
   unsigned int :7;
   unsigned int RTCCIF:1;
} IFS3bits;
#word IFS3bits = 0x08A
#word IFS3 = 0x08A

struct IFS4BITS {
   unsigned int :1;
   unsigned int U1ERIF:1;
   unsigned int U2ERIF:1;
   unsigned int CRCIF:1;
} IFS4bits;
#word IFS4bits = 0x08C
#word IFS4 = 0x08C

struct IEC0BITS {
   unsigned int INT0IE:1;
   unsigned int IC1IE:1;
   unsigned int OC1IE:1;
   unsigned int T1IE:1;
   unsigned int :1;
   unsigned int IC2IE:1;
   unsigned int OC2IE:1;
   unsigned int T2IE:1;
   unsigned int T3IE:1;
   unsigned int SPI1FLTIE:1;
   unsigned int SPI1IE:1;
   unsigned int U1RXIE:1;
   unsigned int U1TXIE:1;
   unsigned int ADIE:1;
} IEC0bits;
#word IEC0bits = 0x094
#word IEC0 = 0x094

struct IEC1BITS {
   unsigned int SI2C1IE:1;
   unsigned int MI2C1IE:1;
   unsigned int CMPIE:1;
   unsigned int CNIE:1;
   unsigned int INT1IE:1;
   unsigned int :4;
   unsigned int OC3IE:1;
   unsigned int OC4IE:1;
   unsigned int T4IE:1;
   unsigned int T5IE:1;
   unsigned int INT2IE:1;
   unsigned int U2RXIE:1;
   unsigned int U2TXIE:1;
} IEC1bits;
#word IEC1bits = 0x096
#word IEC1 = 0x096

struct IEC2BITS {
   unsigned int SPI2FLTIE:1;
   unsigned int SPI2IE:1;
   unsigned int :3;
   unsigned int IC3IE:1;
   unsigned int IC4IE:1;
   unsigned int IC5IE:1;
   unsigned int :1;
   unsigned int OC5IE:1;
   unsigned int :3;
   unsigned int PMPIE:1;
} IEC2bits;
#word IEC2bits = 0x098
#word IEC2 = 0x098

struct IEC3BITS {
   unsigned int :1;
   unsigned int SI2C2IE:1;
   unsigned int MI2C2IE:1;
   unsigned int :2;
   unsigned int INT3IE:1;
   unsigned int INT4IE:1;
   unsigned int :7;
   unsigned int RTCCIE:1;
} IEC3bits;
#word IEC3bits = 0x09A
#word IEC3 = 0x09A

struct IEC4BITS {
   unsigned int :1;
   unsigned int U1ERIE:1;
   unsigned int U2ERIE:1;
   unsigned int CRCIE:1;
} IEC4bits;
#word IEC4bits = 0x09C
#word IEC4 = 0x09C

struct IPC0BITS {
   unsigned int INT0IP:3;
   unsigned int :1;
   unsigned int IC1IP:3;
   unsigned int :1;
   unsigned int OC1IP:3;
   unsigned int :1;
   unsigned int T1IP:3;
} IPC0bits;
#word IPC0bits = 0x0A4
#word IPC0 = 0x0A4

struct IPC1BITS {
   unsigned int :4;
   unsigned int IC2IP4:1;
   unsigned int IC2IP5:1;
   unsigned int IC2IP2:1;
   unsigned int :1;
   unsigned int OC2IP8:1;
   unsigned int OC2IP9:1;
   unsigned int OC2IP2:1;
   unsigned int :1;
   unsigned int T2IP12:1;
   unsigned int T2IP13:1;
   unsigned int T2IP2:1;
} IPC1bits;
#word IPC1bits = 0x0A6
#word IPC1 = 0x0A6

struct IPC2BITS {
   unsigned int T3IP0:1;
   unsigned int T3IP1:1;
   unsigned int T3IP2:1;
   unsigned int :1;
   unsigned int SPI1FLTIP4:1;
   unsigned int SPI1FLTIP5:1;
   unsigned int SPI1FLTIP2:1;
   unsigned int :1;
   unsigned int SP1IP8:1;
   unsigned int SP1IP9:1;
   unsigned int SP1IP2:1;
   unsigned int :1;
   unsigned int U1RXIP12:1;
   unsigned int U1RXIP13:1;
   unsigned int U1RXIP2:1;
} IPC2bits;
#word IPC2bits = 0x0A8
#word IPC2 = 0x0A8

struct IPC3BITS {
   unsigned int U1TXIP0:1;
   unsigned int U1TXIP1:1;
   unsigned int U1TXIP2:1;
   unsigned int :1;
   unsigned int ADIP4:1;
   unsigned int ADIP5:1;
   unsigned int ADIP2:1;
} IPC3bits;
#word IPC3bits = 0x0AA
#word IPC3 = 0x0AA

struct IPC4BITS {
   unsigned int SI2C1P0:1;
   unsigned int SI2C1P1:1;
   unsigned int SI2C1P2:1;
   unsigned int :1;
   unsigned int MI2C1P4:1;
   unsigned int MI2C1P5:1;
   unsigned int MI2C1P2:1;
   unsigned int :1;
   unsigned int CMPIP8:1;
   unsigned int CMPIP9:1;
   unsigned int CMPIP2:1;
   unsigned int :1;
   unsigned int CNIP12:1;
   unsigned int CNIP13:1;
   unsigned int CNIP2:1;
} IPC4bits;
#word IPC4bits = 0x0AC
#word IPC4 = 0x0AC

#word IPC5 = 0x0AE

struct IPC6BITS {
   unsigned int :4;
   unsigned int OC3IP4:1;
   unsigned int OC3IP5:1;
   unsigned int OC3IP2:1;
   unsigned int :1;
   unsigned int OC4IP8:1;
   unsigned int OC4IP9:1;
   unsigned int OC4IP2:1;
   unsigned int :1;
   unsigned int T4IP12:1;
   unsigned int T4IP13:1;
   unsigned int T4IP2:1;
} IPC6bits;
#word IPC6bits = 0x0B0
#word IPC6 = 0x0B0

struct IPC7BITS {
   unsigned int T5IP0:1;
   unsigned int T5IP1:1;
   unsigned int T5IP2:1;
   unsigned int :1;
   unsigned int INT2IP4:1;
   unsigned int INT2IP5:1;
   unsigned int INT2IP2:1;
   unsigned int :1;
   unsigned int U2RXIP8:1;
   unsigned int U2RXIP9:1;
   unsigned int U2RXIP2:1;
   unsigned int :1;
   unsigned int U2TXIP12:1;
   unsigned int U2TXIP13:1;
   unsigned int U2TXIP2:1;
} IPC7bits;
#word IPC7bits = 0x0B2
#word IPC7 = 0x0B2

struct IPC8BITS {
   unsigned int SPIFLT2IP0:1;
   unsigned int SPIFLT2IP1:1;
   unsigned int SPIFLT2IP2:1;
   unsigned int :1;
   unsigned int SPI2IP4:1;
   unsigned int SPI2IP5:1;
   unsigned int SPI2IP2:1;
} IPC8bits;
#word IPC8bits = 0x0B4
#word IPC8 = 0x0B4

struct IPC9BITS {
   unsigned int :4;
   unsigned int IC3IP4:1;
   unsigned int IC3IP5:1;
   unsigned int IC3IP2:1;
   unsigned int :1;
   unsigned int IC4IP8:1;
   unsigned int IC4IP9:1;
   unsigned int IC4IP2:1;
   unsigned int :1;
   unsigned int IC5IP12:1;
   unsigned int IC5IP13:1;
   unsigned int IC5IP2:1;
} IPC9bits;
#word IPC9bits = 0x0B6
#word IPC9 = 0x0B6

struct IPC10BITS {
   unsigned int :4;
   unsigned int OC5IP4:1;
   unsigned int OC5IP5:1;
   unsigned int OC5IP2:1;
} IPC10bits;
#word IPC10bits = 0x0B8
#word IPC10 = 0x0B8

struct IPC11BITS {
   unsigned int :4;
   unsigned int PMPIP4:1;
   unsigned int PMPIP5:1;
   unsigned int PMPIP2:1;
} IPC11bits;
#word IPC11bits = 0x0BA
#word IPC11 = 0x0BA

struct IPC12BITS {
   unsigned int :4;
   unsigned int SI2C2P4:1;
   unsigned int SI2C2P5:1;
   unsigned int SI2C2P2:1;
   unsigned int :1;
   unsigned int MI2C2P8:1;
   unsigned int MI2C2P9:1;
   unsigned int MI2C2P2:1;
} IPC12bits;
#word IPC12bits = 0x0BC
#word IPC12 = 0x0BC

struct IPC13BITS {
   unsigned int :4;
   unsigned int INT3IP4:1;
   unsigned int INT3IP5:1;
   unsigned int INT3IP2:1;
   unsigned int :1;
   unsigned int INT4IP8:1;
   unsigned int INT4IP9:1;
   unsigned int INT4IP2:1;
} IPC13bits;
#word IPC13bits = 0x0BE
#word IPC13 = 0x0BE

struct IPC15BITS {
   unsigned int :8;
   unsigned int RTCCIP8:1;
   unsigned int RTCCIP9:1;
   unsigned int RTCCIP2:1;
} IPC15bits;
#word IPC15bits = 0x0C2
#word IPC15 = 0x0C2

struct IPC16BITS {
   unsigned int :4;
   unsigned int U1ERIP4:1;
   unsigned int U1ERIP5:1;
   unsigned int U1ERIP2:1;
   unsigned int :1;
   unsigned int U2ERIP8:1;
   unsigned int U2ERIP9:1;
   unsigned int U2ERIP2:1;
   unsigned int :1;
   unsigned int CRCIP12:1;
   unsigned int CRCIP13:1;
   unsigned int CRCIP2:1;
} IPC16bits;
#word IPC16bits = 0x0C4
#word IPC16 = 0x0C4

struct INTTREGBITS {
   unsigned int VECNUM0:1;
   unsigned int VECNUM1:1;
   unsigned int VECNUM2:1;
   unsigned int VECNUM3:1;
   unsigned int VECNUM4:1;
   unsigned int VECNUM5:1;
   unsigned int :2;
   unsigned int ILR8:1;
   unsigned int ILR9:1;
   unsigned int ILR10:1;
   unsigned int ILR3:1;
   unsigned int :2;
   unsigned int TMODE:1;
   unsigned int IRQtoCPU:1;
} INTTREGbits;
#word INTTREGbits = 0x0E0
#word INTTREG = 0x0E0

#word TMR1 = 0x100

#word PR1 = 0x102

struct T1CONBITS {
   unsigned int :1;
   unsigned int TCS:1;
   unsigned int T1SYNC:1;
   unsigned int :1;
   unsigned int TCKPS:2;
   unsigned int TGATE:1;
   unsigned int :6;
   unsigned int TSIDL:1;
   unsigned int :1;
   unsigned int TON:1;
} T1CONbits;
#word T1CONbits = 0x104
#word T1CON = 0x104

#word TMR2 = 0x106

#word TMR3HLD = 0x108

#word TMR3 = 0x10A

#word PR2 = 0x10C

#word PR3 = 0x10E

struct T2CONBITS {
   unsigned int :1;
   unsigned int TCS:1;
   unsigned int :1;
   unsigned int T3:1;
   unsigned int TCKPS4:1;
   unsigned int TCKPS5:1;
   unsigned int TGATE:1;
   unsigned int :6;
   unsigned int TSIDL:1;
   unsigned int :1;
   unsigned int TON:1;
} T2CONbits;
#word T2CONbits = 0x110
#word T2CON = 0x110

struct T3CONBITS {
   unsigned int :1;
   unsigned int TCS:1;
   unsigned int :2;
   unsigned int TCKPS4:1;
   unsigned int TCKPS5:1;
   unsigned int TGATE:1;
   unsigned int :6;
   unsigned int TSIDL:1;
   unsigned int :1;
   unsigned int TON:1;
} T3CONbits;
#word T3CONbits = 0x112
#word T3CON = 0x112

#word TMR4 = 0x114

#word TMR5HLD = 0x116

#word TMR5 = 0x118

#word PR4 = 0x11A

#word PR5 = 0x11C

struct T4CONBITS {
   unsigned int :1;
   unsigned int TCS:1;
   unsigned int :1;
   unsigned int T3:1;
   unsigned int TCKPS4:1;
   unsigned int TCKPS5:1;
   unsigned int TGATE:1;
   unsigned int :6;
   unsigned int TSIDL:1;
   unsigned int :1;
   unsigned int TON:1;
} T4CONbits;
#word T4CONbits = 0x11E
#word T4CON = 0x11E

struct T5CONBITS {
   unsigned int :1;
   unsigned int TCS:1;
   unsigned int :2;
   unsigned int TCKPS4:1;
   unsigned int TCKPS5:1;
   unsigned int TGATE:1;
   unsigned int :6;
   unsigned int TSIDL:1;
   unsigned int :1;
   unsigned int TON:1;
} T5CONbits;
#word T5CONbits = 0x120
#word T5CON = 0x120

#word IC1BUF = 0x140

struct IC1CONBITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI6:1;
   unsigned int ICTMR:1;
   unsigned int :5;
   unsigned int ICSIDL:1;
} IC1CONbits;
#word IC1CONbits = 0x142
#word IC1CON = 0x142

#word IC2BUF = 0x144

struct IC2CONBITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI6:1;
   unsigned int ICTMR:1;
   unsigned int :5;
   unsigned int ICSIDL:1;
} IC2CONbits;
#word IC2CONbits = 0x146
#word IC2CON = 0x146

#word IC3BUF = 0x148

struct IC3CONBITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI6:1;
   unsigned int ICTMR:1;
   unsigned int :5;
   unsigned int ICSIDL:1;
} IC3CONbits;
#word IC3CONbits = 0x14A
#word IC3CON = 0x14A

#word IC4BUF = 0x14C

struct IC4CONBITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI6:1;
   unsigned int ICTMR:1;
   unsigned int :5;
   unsigned int ICSIDL:1;
} IC4CONbits;
#word IC4CONbits = 0x14E
#word IC4CON = 0x14E

#word IC5BUF = 0x150

struct IC5CONBITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI6:1;
   unsigned int ICTMR:1;
   unsigned int :5;
   unsigned int ICSIDL:1;
} IC5CONbits;
#word IC5CONbits = 0x152
#word IC5CON = 0x152

#word OC1RS = 0x180

#word OC1R = 0x182

struct OC1CONBITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int OCTSEL:1;
   unsigned int OCFLT:1;
   unsigned int :8;
   unsigned int OCSIDL:1;
} OC1CONbits;
#word OC1CONbits = 0x184
#word OC1CON = 0x184

#word OC2RS = 0x186

#word OC2R = 0x188

struct OC2CONBITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int OCTSEL:1;
   unsigned int OCFLT:1;
   unsigned int :8;
   unsigned int OCSIDL:1;
} OC2CONbits;
#word OC2CONbits = 0x18A
#word OC2CON = 0x18A

#word OC3RS = 0x18C

#word OC3R = 0x18E

struct OC3CONBITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int OCTSEL:1;
   unsigned int OCFLT:1;
   unsigned int :8;
   unsigned int OCSIDL:1;
} OC3CONbits;
#word OC3CONbits = 0x190
#word OC3CON = 0x190

#word OC4RS = 0x192

#word OC4R = 0x194

struct OC4CONBITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int OCTSEL:1;
   unsigned int OCFLT:1;
   unsigned int :8;
   unsigned int OCSIDL:1;
} OC4CONbits;
#word OC4CONbits = 0x196
#word OC4CON = 0x196

#word OC5RS = 0x198

#word OC5R = 0x19A

struct OC5CONBITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int OCTSEL:1;
   unsigned int OCFLT:1;
   unsigned int :8;
   unsigned int OCSIDL:1;
} OC5CONbits;
#word OC5CONbits = 0x19C
#word OC5CON = 0x19C

#word I2C1RCV = 0x200

#word I2C1TRN = 0x202

#word I2C1BRG = 0x204

struct I2C1CONBITS {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int STREN:1;
   unsigned int GCEN:1;
   unsigned int SMEN:1;
   unsigned int DISSLW:1;
   unsigned int A10M:1;
   unsigned int IPMIEN:1;
   unsigned int SCLREL:1;
   unsigned int I2CSIDL:1;
   unsigned int :1;
   unsigned int I2CEN:1;
} I2C1CONbits;
#word I2C1CONbits = 0x206
#word I2C1CON = 0x206

struct I2C1STATBITS {
   unsigned int TBF:1;
   unsigned int RBF:1;
   unsigned int R:1;
   unsigned int S:1;
   unsigned int P:1;
   unsigned int D:1;
   unsigned int I2CPOV:1;
   unsigned int IWCOL:1;
   unsigned int ADD:1;
   unsigned int GCSTAT:1;
   unsigned int BCL:1;
   unsigned int :3;
   unsigned int TRSTAT:1;
   unsigned int ACKSTAT:1;
} I2C1STATbits;
#word I2C1STATbits = 0x208
#word I2C1STAT = 0x208

#word I2C1ADD = 0x20A

#word I2C1MSK = 0x20C

#word I2C2RCV = 0x210

#word I2C2TRN = 0x212

#word I2C2BRG = 0x214

struct I2C2CONBITS {
   unsigned int SEN:1;
   unsigned int RSEN:1;
   unsigned int PEN:1;
   unsigned int RCEN:1;
   unsigned int ACKEN:1;
   unsigned int ACKDT:1;
   unsigned int STREN:1;
   unsigned int GCEN:1;
   unsigned int SMEN:1;
   unsigned int DISSLW:1;
   unsigned int A10M:1;
   unsigned int IPMIEN:1;
   unsigned int SCLREL:1;
   unsigned int I2CSIDL:1;
   unsigned int :1;
   unsigned int I2CEN:1;
} I2C2CONbits;
#word I2C2CONbits = 0x216
#word I2C2CON = 0x216

struct I2C2STATBITS {
   unsigned int TBF:1;
   unsigned int RBF:1;
   unsigned int R:1;
   unsigned int S:1;
   unsigned int P:1;
   unsigned int D:1;
   unsigned int I2CPOV:1;
   unsigned int IWCOL:1;
   unsigned int ADD:1;
   unsigned int GCSTAT:1;
   unsigned int BCL:1;
   unsigned int :3;
   unsigned int TRSTAT:1;
   unsigned int ACKSTAT:1;
} I2C2STATbits;
#word I2C2STATbits = 0x218
#word I2C2STAT = 0x218

#word I2C2ADD = 0x21A

#word I2C2MSK = 0x21C

struct U1MODEBITS {
   unsigned int STSEL:1;
   unsigned int PDSEL1:1;
   unsigned int PDSEL2:1;
   unsigned int BRGH:1;
   unsigned int RXINV:1;
   unsigned int ABAUD:1;
   unsigned int LPBACK:1;
   unsigned int WAKE:1;
   unsigned int UEN8:1;
   unsigned int UEN1:1;
   unsigned int :1;
   unsigned int RTSMD:1;
   unsigned int IREN:1;
   unsigned int USIDL:1;
   unsigned int :1;
   unsigned int UARTEN:1;
} U1MODEbits;
#word U1MODEbits = 0x220
#word U1MODE = 0x220

struct U1STABITS {
   unsigned int URXDA:1;
   unsigned int OERR:1;
   unsigned int FERR:1;
   unsigned int PERR:1;
   unsigned int RIDLE:1;
   unsigned int ADDEN:1;
   unsigned int URXISEL6:1;
   unsigned int URXISEL7:1;
   unsigned int TRMT:1;
   unsigned int UTXBF:1;
   unsigned int UTXEN:1;
   unsigned int UTXBRK:1;
   unsigned int :1;
   unsigned int UTXISEL13:1;
   unsigned int UTXINV:1;
   unsigned int UTXISEL1:1;
} U1STAbits;
#word U1STAbits = 0x222
#word U1STA = 0x222

#word U1TXREG = 0x224

#word U1RXREG = 0x226

#word U1BRG = 0x228

struct U2MODEBITS {
   unsigned int STSEL:1;
   unsigned int PDSEL1:1;
   unsigned int PDSEL2:1;
   unsigned int BRGH:1;
   unsigned int RXINV:1;
   unsigned int ABAUD:1;
   unsigned int LPBACK:1;
   unsigned int WAKE:1;
   unsigned int UEN8:1;
   unsigned int UEN1:1;
   unsigned int :1;
   unsigned int RTSMD:1;
   unsigned int IREN:1;
   unsigned int USIDL:1;
   unsigned int :1;
   unsigned int UARTEN:1;
} U2MODEbits;
#word U2MODEbits = 0x230
#word U2MODE = 0x230

struct U2STABITS {
   unsigned int URXDA:1;
   unsigned int OERR:1;
   unsigned int FERR:1;
   unsigned int PERR:1;
   unsigned int RIDLE:1;
   unsigned int ADDEN:1;
   unsigned int URXISEL6:1;
   unsigned int URXISEL7:1;
   unsigned int TRMT:1;
   unsigned int UTXBF:1;
   unsigned int UTXEN:1;
   unsigned int UTXBRK:1;
   unsigned int :1;
   unsigned int UTXISEL13:1;
   unsigned int UTXINV:1;
   unsigned int UTXISEL1:1;
} U2STAbits;
#word U2STAbits = 0x232
#word U2STA = 0x232

#word U2TXREG = 0x234

#word U2RXREG = 0x236

#word U2BRG = 0x238

struct SPI1STATBITS {
   unsigned int SPIRBF:1;
   unsigned int SPITBF:1;
   unsigned int :4;
   unsigned int SPIROV:1;
   unsigned int :1;
   unsigned int BUFELM8:1;
   unsigned int BUFELM9:1;
   unsigned int BUFELM2:1;
   unsigned int :2;
   unsigned int SPISIDL:1;
   unsigned int :1;
   unsigned int SPIEN:1;
} SPI1STATbits;
#word SPI1STATbits = 0x240
#word SPI1STAT = 0x240

struct SPI1CON1BITS {
   unsigned int PPRE0:1;
   unsigned int PPRE1:1;
   unsigned int SPRE2:1;
   unsigned int SPRE3:1;
   unsigned int SPRE4:1;
   unsigned int MSTEN:1;
   unsigned int CKP:1;
   unsigned int SSEN:1;
   unsigned int CKE:1;
   unsigned int SMP:1;
   unsigned int MODE16:1;
   unsigned int DISSDO:1;
   unsigned int DISSCK:1;
} SPI1CON1bits;
#word SPI1CON1bits = 0x242
#word SPI1CON1 = 0x242

struct SPI1CON2BITS {
   unsigned int ENHBUF:1;
   unsigned int FRMDEL:1;
   unsigned int :11;
   unsigned int FRMPOL:1;
   unsigned int FRMSYNC:1;
   unsigned int FRMEN:1;
} SPI1CON2bits;
#word SPI1CON2bits = 0x244
#word SPI1CON2 = 0x244

#word SPI1BUF = 0x248

struct SPI2STATBITS {
   unsigned int SPIRBF:1;
   unsigned int SPITBF:1;
   unsigned int :4;
   unsigned int SPIROV:1;
   unsigned int :1;
   unsigned int BUFELM8:1;
   unsigned int BUFELM9:1;
   unsigned int BUFELM2:1;
   unsigned int :2;
   unsigned int SPISIDL:1;
   unsigned int :1;
   unsigned int SPIEN:1;
} SPI2STATbits;
#word SPI2STATbits = 0x260
#word SPI2STAT = 0x260

struct SPI2CON1BITS {
   unsigned int PPRE0:1;
   unsigned int PPRE1:1;
   unsigned int SPRE2:1;
   unsigned int SPRE3:1;
   unsigned int SPRE4:1;
   unsigned int MSTEN:1;
   unsigned int CKP:1;
   unsigned int SSEN:1;
   unsigned int CKE:1;
   unsigned int SMP:1;
   unsigned int MODE16:1;
   unsigned int DISSDO:1;
   unsigned int DISSCK:1;
} SPI2CON1bits;
#word SPI2CON1bits = 0x262
#word SPI2CON1 = 0x262

struct SPI2CON2BITS {
   unsigned int ENHBUF:1;
   unsigned int FRMDEL:1;
   unsigned int :11;
   unsigned int FRMPOL:1;
   unsigned int FRMSYNC:1;
   unsigned int FRMEN:1;
} SPI2CON2bits;
#word SPI2CON2bits = 0x264
#word SPI2CON2 = 0x264

#word SPI2BUF = 0x268

struct TRISABITS {
   unsigned int TRISA0:1;
   unsigned int TRISA1:1;
   unsigned int TRISA2:1;
   unsigned int TRISA3:1;
   unsigned int TRISA4:1;
   unsigned int TRISA5:1;
   unsigned int TRISA6:1;
   unsigned int TRISA7:1;
   unsigned int :1;
   unsigned int TRISA9:1;
   unsigned int TRISA10:1;
   unsigned int :3;
   unsigned int TRISA14:1;
   unsigned int TRISA15:1;
} TRISAbits;
#word TRISAbits = 0x2C0
#word TRISA = 0x2C0

struct PORTABITS {
   unsigned int RA0:1;
   unsigned int RA1:1;
   unsigned int RA2:1;
   unsigned int RA3:1;
   unsigned int RA4:1;
   unsigned int RA5:1;
   unsigned int RA6:1;
   unsigned int RA7:1;
   unsigned int :1;
   unsigned int RA9:1;
   unsigned int RA10:1;
   unsigned int :3;
   unsigned int RA14:1;
   unsigned int RA15:1;
} PORTAbits;
#word PORTAbits = 0x2C2
#word PORTA = 0x2C2

struct LATABITS {
   unsigned int LATA0:1;
   unsigned int LATA1:1;
   unsigned int LATA2:1;
   unsigned int LATA3:1;
   unsigned int LATA4:1;
   unsigned int LATA5:1;
   unsigned int LATA6:1;
   unsigned int LATA7:1;
   unsigned int :1;
   unsigned int LATA9:1;
   unsigned int LATA10:1;
   unsigned int :3;
   unsigned int LATA14:1;
   unsigned int LATA15:1;
} LATAbits;
#word LATAbits = 0x2C4
#word LATA = 0x2C4

struct TRISBBITS {
   unsigned int TRISB0:1;
   unsigned int TRISB1:1;
   unsigned int TRISB2:1;
   unsigned int TRISB3:1;
   unsigned int TRISB4:1;
   unsigned int TRISB5:1;
   unsigned int TRISB6:1;
   unsigned int TRISB7:1;
   unsigned int TRISB8:1;
   unsigned int TRISB9:1;
   unsigned int TRISB10:1;
   unsigned int TRISB11:1;
   unsigned int TRISB12:1;
   unsigned int TRISB13:1;
   unsigned int TRISB14:1;
   unsigned int TRISB15:1;
} TRISBbits;
#word TRISBbits = 0x2C6
#word TRISB = 0x2C6

struct PORTBBITS {
   unsigned int RB0:1;
   unsigned int RB1:1;
   unsigned int RB2:1;
   unsigned int RB3:1;
   unsigned int RB4:1;
   unsigned int RB5:1;
   unsigned int RB6:1;
   unsigned int RB7:1;
   unsigned int RB8:1;
   unsigned int RB9:1;
   unsigned int RB10:1;
   unsigned int RB11:1;
   unsigned int RB12:1;
   unsigned int RB13:1;
   unsigned int RB14:1;
   unsigned int RB15:1;
} PORTBbits;
#word PORTBbits = 0x2C8
#word PORTB = 0x2C8

struct LATBBITS {
   unsigned int LATB0:1;
   unsigned int LATB1:1;
   unsigned int LATB2:1;
   unsigned int LATB3:1;
   unsigned int LATB4:1;
   unsigned int LATB5:1;
   unsigned int LATB6:1;
   unsigned int LATB7:1;
   unsigned int LATB8:1;
   unsigned int LATB9:1;
   unsigned int LATB10:1;
   unsigned int LATB11:1;
   unsigned int LATB12:1;
   unsigned int LATB13:1;
   unsigned int LATB14:1;
   unsigned int LATB15:1;
} LATBbits;
#word LATBbits = 0x2CA
#word LATB = 0x2CA

struct TRISCBITS {
   unsigned int :1;
   unsigned int TRISC1:1;
   unsigned int TRISC2:1;
   unsigned int TRISC3:1;
   unsigned int TRISC4:1;
   unsigned int :7;
   unsigned int TRISC12:1;
   unsigned int TRISC13:1;
   unsigned int TRISC14:1;
   unsigned int TRISC15:1;
} TRISCbits;
#word TRISCbits = 0x2CC
#word TRISC = 0x2CC

struct PORTCBITS {
   unsigned int :1;
   unsigned int RC1:1;
   unsigned int RC2:1;
   unsigned int RC3:1;
   unsigned int RC4:1;
   unsigned int :7;
   unsigned int RC12:1;
   unsigned int RC13:1;
   unsigned int RC14:1;
   unsigned int RC15:1;
} PORTCbits;
#word PORTCbits = 0x2CE
#word PORTC = 0x2CE

struct LATCBITS {
   unsigned int :1;
   unsigned int LATC1:1;
   unsigned int LATC2:1;
   unsigned int LATC3:1;
   unsigned int LATC4:1;
   unsigned int :7;
   unsigned int LATC12:1;
   unsigned int LATC13:1;
   unsigned int LATC14:1;
   unsigned int LATC15:1;
} LATCbits;
#word LATCbits = 0x2D0
#word LATC = 0x2D0

struct TRISDBITS {
   unsigned int TRISD0:1;
   unsigned int TRISD1:1;
   unsigned int TRISD2:1;
   unsigned int TRISD3:1;
   unsigned int TRISD4:1;
   unsigned int TRISD5:1;
   unsigned int TRISD6:1;
   unsigned int TRISD7:1;
   unsigned int TRISD8:1;
   unsigned int TRISD9:1;
   unsigned int TRISD10:1;
   unsigned int TRISD11:1;
   unsigned int TRISD12:1;
   unsigned int TRISD13:1;
   unsigned int TRISD14:1;
   unsigned int TRISD15:1;
} TRISDbits;
#word TRISDbits = 0x2D2
#word TRISD = 0x2D2

struct PORTDBITS {
   unsigned int RD0:1;
   unsigned int RD1:1;
   unsigned int RD2:1;
   unsigned int RD3:1;
   unsigned int RD4:1;
   unsigned int RD5:1;
   unsigned int RD6:1;
   unsigned int RD7:1;
   unsigned int RD8:1;
   unsigned int RD9:1;
   unsigned int RD10:1;
   unsigned int RD11:1;
   unsigned int RD12:1;
   unsigned int RD13:1;
   unsigned int RD14:1;
   unsigned int RD15:1;
} PORTDbits;
#word PORTDbits = 0x2D4
#word PORTD = 0x2D4

struct LATDBITS {
   unsigned int LATD0:1;
   unsigned int LATD1:1;
   unsigned int LATD2:1;
   unsigned int LATD3:1;
   unsigned int LATD4:1;
   unsigned int LATD5:1;
   unsigned int LATD6:1;
   unsigned int LATD7:1;
   unsigned int LATD8:1;
   unsigned int LATD9:1;
   unsigned int LATD10:1;
   unsigned int LATD11:1;
   unsigned int LATD12:1;
   unsigned int LATD13:1;
   unsigned int LATD14:1;
   unsigned int LATD15:1;
} LATDbits;
#word LATDbits = 0x2D6
#word LATD = 0x2D6

struct TRISEBITS {
   unsigned int TRISE0:1;
   unsigned int TRISE1:1;
   unsigned int TRISE2:1;
   unsigned int TRISE3:1;
   unsigned int TRISE4:1;
   unsigned int TRISE5:1;
   unsigned int TRISE6:1;
   unsigned int TRISE7:1;
   unsigned int TRISE8:1;
   unsigned int TRISE9:1;
   unsigned int TRISE10:1;
   unsigned int TRISE11:1;
   unsigned int TRISE12:1;
   unsigned int TRISE13:1;
   unsigned int TRISE14:1;
   unsigned int TRISE15:1;
} TRISEbits;
#word TRISEbits = 0x2D8
#word TRISE = 0x2D8

struct PORTEBITS {
   unsigned int RE0:1;
   unsigned int RE1:1;
   unsigned int RE2:1;
   unsigned int RE3:1;
   unsigned int RE4:1;
   unsigned int RE5:1;
   unsigned int RE6:1;
   unsigned int RE7:1;
   unsigned int RE8:1;
   unsigned int RE9:1;
   unsigned int RE10:1;
   unsigned int RE11:1;
   unsigned int RE12:1;
   unsigned int RE13:1;
   unsigned int RE14:1;
   unsigned int RE15:1;
} PORTEbits;
#word PORTEbits = 0x2DA
#word PORTE = 0x2DA

struct LATEBITS {
   unsigned int LATE0:1;
   unsigned int LATE1:1;
   unsigned int LATE2:1;
   unsigned int LATE3:1;
   unsigned int LATE4:1;
   unsigned int LATE5:1;
   unsigned int LATE6:1;
   unsigned int LATE7:1;
   unsigned int LATE8:1;
   unsigned int LATE9:1;
   unsigned int LATE10:1;
   unsigned int LATE11:1;
   unsigned int LATE12:1;
   unsigned int LATE13:1;
   unsigned int LATE14:1;
   unsigned int LATE15:1;
} LATEbits;
#word LATEbits = 0x2DC
#word LATE = 0x2DC

struct TRISFBITS {
   unsigned int TRISF0:1;
   unsigned int TRISF1:1;
   unsigned int TRISF2:1;
   unsigned int TRISF3:1;
   unsigned int TRISF4:1;
   unsigned int TRISF5:1;
   unsigned int TRISF6:1;
   unsigned int TRISF7:1;
   unsigned int TRISF8:1;
   unsigned int :3;
   unsigned int TRISF12:1;
   unsigned int TRISF13:1;
} TRISFbits;
#word TRISFbits = 0x2DE
#word TRISF = 0x2DE

struct PORTFBITS {
   unsigned int RF0:1;
   unsigned int RF1:1;
   unsigned int RF2:1;
   unsigned int RF3:1;
   unsigned int RF4:1;
   unsigned int RF5:1;
   unsigned int RF6:1;
   unsigned int RF7:1;
   unsigned int RF8:1;
   unsigned int :3;
   unsigned int RF12:1;
   unsigned int RF13:1;
} PORTFbits;
#word PORTFbits = 0x2E0
#word PORTF = 0x2E0

struct LATFBITS {
   unsigned int LATF0:1;
   unsigned int LATF1:1;
   unsigned int LATF2:1;
   unsigned int LATF3:1;
   unsigned int LATF4:1;
   unsigned int LATF5:1;
   unsigned int LATF6:1;
   unsigned int LATF7:1;
   unsigned int LATF8:1;
   unsigned int :3;
   unsigned int LATF12:1;
   unsigned int LATF13:1;
} LATFbits;
#word LATFbits = 0x2E2
#word LATF = 0x2E2

struct TRISGBITS {
   unsigned int TRISG0:1;
   unsigned int TRISG1:1;
   unsigned int TRISG2:1;
   unsigned int TRISG3:1;
   unsigned int :2;
   unsigned int TRISG6:1;
   unsigned int TRISG7:1;
   unsigned int TRISG8:1;
   unsigned int TRISG9:1;
   unsigned int :2;
   unsigned int TRISG12:1;
   unsigned int TRISG13:1;
   unsigned int TRISG14:1;
   unsigned int TRISG15:1;
} TRISGbits;
#word TRISGbits = 0x2E4
#word TRISG = 0x2E4

struct PORTGBITS {
   unsigned int RG0:1;
   unsigned int RG1:1;
   unsigned int RG2:1;
   unsigned int RG3:1;
   unsigned int :2;
   unsigned int RG6:1;
   unsigned int RG7:1;
   unsigned int RG8:1;
   unsigned int RG9:1;
   unsigned int :2;
   unsigned int RG12:1;
   unsigned int RG13:1;
   unsigned int RG14:1;
   unsigned int RG15:1;
} PORTGbits;
#word PORTGbits = 0x2E6
#word PORTG = 0x2E6

struct LATGBITS {
   unsigned int LATG0:1;
   unsigned int LATG1:1;
   unsigned int LATG2:1;
   unsigned int LATG3:1;
   unsigned int :2;
   unsigned int LATG6:1;
   unsigned int LATG7:1;
   unsigned int LATG8:1;
   unsigned int LATG9:1;
   unsigned int :2;
   unsigned int LATG12:1;
   unsigned int LATG13:1;
   unsigned int LATG14:1;
   unsigned int LATG15:1;
} LATGbits;
#word LATGbits = 0x2E8
#word LATG = 0x2E8

struct PADCFG1BITS {
   unsigned int PMPTTL:1;
   unsigned int RTSECSEL:1;
} PADCFG1bits;
#word PADCFG1bits = 0x2FC
#word PADCFG1 = 0x2FC

#word ADC1BUF0 = 0x300

#word ADC1BUF1 = 0x302

#word ADC1BUF2 = 0x304

#word ADC1BUF3 = 0x306

#word ADC1BUF4 = 0x308

#word ADC1BUF5 = 0x30A

#word ADC1BUF6 = 0x30C

#word ADC1BUF7 = 0x30E

#word ADC1BUF8 = 0x310

#word ADC1BUF9 = 0x312

#word ADC1BUFA = 0x314

#word ADC1BUFB = 0x316

#word ADC1BUFC = 0x318

#word ADC1BUFD = 0x31A

#word ADC1BUFE = 0x31C

#word ADC1BUFF = 0x31E

struct AD1CON1BITS {
   unsigned int DONE:1;
   unsigned int SAMP:1;
   unsigned int ASAM:1;
   unsigned int :2;
   unsigned int SSRC5:1;
   unsigned int SSRC6:1;
   unsigned int SSRC7:1;
   unsigned int FORM8:1;
   unsigned int FORM1:1;
   unsigned int :3;
   unsigned int ADSIDL:1;
   unsigned int :1;
   unsigned int ADON:1;
} AD1CON1bits;
#word AD1CON1bits = 0x320
#word AD1CON1 = 0x320

struct AD1CON2BITS {
   unsigned int ALTS:1;
   unsigned int BUFM:1;
   unsigned int SMPI:4;
   unsigned int :1;
   unsigned int BUFS:1;
   unsigned int :2;
   unsigned int CSCNA:1;
   unsigned int :2;
   unsigned int VCFG13:1;
   unsigned int VCFG14:1;
   unsigned int VCFG2:1;
} AD1CON2bits;
#word AD1CON2bits = 0x322
#word AD1CON2 = 0x322

struct AD1CON3BITS {
   unsigned int ADCS0:1;
   unsigned int ADCS1:1;
   unsigned int ADCS2:1;
   unsigned int ADCS3:1;
   unsigned int ADCS4:1;
   unsigned int ADCS5:1;
   unsigned int ADCS6:1;
   unsigned int ADCS7:1;
   unsigned int SAMC8:1;
   unsigned int SAMC9:1;
   unsigned int SAMC10:1;
   unsigned int SAMC11:1;
   unsigned int SAMC4:1;
   unsigned int :2;
   unsigned int ADRC:1;
} AD1CON3bits;
#word AD1CON3bits = 0x324
#word AD1CON3 = 0x324

struct AD1CHSBITS {
   unsigned int CH0SA0:1;
   unsigned int CH0SA1:1;
   unsigned int CH0SA2:1;
   unsigned int CH0SA3:1;
   unsigned int :3;
   unsigned int CH0NA:1;
   unsigned int CH0SB8:1;
   unsigned int CH0SB9:1;
   unsigned int CH0SB10:1;
   unsigned int CH0SB3:1;
   unsigned int :2;
   unsigned int CH0NB14:1;
   unsigned int CH0NB1:1;
} AD1CHSbits;
#word AD1CHSbits = 0x328
#word AD1CHS = 0x328

#word AD1PCFG = 0x32C

#word AD1CSSL = 0x330

struct PMCONBITS {
   unsigned int RDSP:1;
   unsigned int WRSP:1;
   unsigned int BEP:1;
   unsigned int CS1P:1;
   unsigned int CS2P:1;
   unsigned int ALP:1;
   unsigned int CSF6:1;
   unsigned int CSF7:1;
   unsigned int PTRDEN:1;
   unsigned int PTWREN:1;
   unsigned int PTBEEN:1;
   unsigned int ADRMUX11:1;
   unsigned int ADRMUX12:1;
   unsigned int PSIDL:1;
   unsigned int :1;
   unsigned int PMPEN:1;
} PMCONbits;
#word PMCONbits = 0x600
#word PMCON = 0x600

struct PMMODEBITS {
   unsigned int WAITE0:1;
   unsigned int WAITE1:1;
   unsigned int WAITM2:1;
   unsigned int WAITM3:1;
   unsigned int WAITM4:1;
   unsigned int WAITM5:1;
   unsigned int WAITB6:1;
   unsigned int WAITB7:1;
   unsigned int MODE8:1;
   unsigned int MODE9:1;
   unsigned int MODE10:1;
   unsigned int INCM11:1;
   unsigned int INCM12:1;
   unsigned int IRQM13:1;
   unsigned int IRQM14:1;
   unsigned int BUSY:1;
} PMMODEbits;
#word PMMODEbits = 0x602
#word PMMODE = 0x602

struct PMADDRBITS {
   union {
      struct {
         unsigned int ADDR0:1;
         unsigned int ADDR1:1;
         unsigned int ADDR2:1;
         unsigned int ADDR3:1;
         unsigned int ADDR4:1;
         unsigned int ADDR5:1;
         unsigned int ADDR6:1;
         unsigned int ADDR7:1;
         unsigned int ADDR8:1;
         unsigned int ADDR9:1;
         unsigned int ADDR10:1;
         unsigned int ADDR11:1;
         unsigned int ADDR12:1;
         unsigned int ADDR13:1;
         unsigned int CS14:1;
         unsigned int CS1:1;
      };






      struct {
         unsigned int OB0E:1;
         unsigned int OB1E:1;
         unsigned int OB2E:1;
         unsigned int OB3E:1;
         unsigned int :2;
         unsigned int OBUF:1;
         unsigned int OBE:1;
         unsigned int IB0F:1;
         unsigned int IB1F:1;
         unsigned int IB2F:1;
         unsigned int IB3F:1;
         unsigned int :2;
         unsigned int IBOV:1;
         unsigned int IBF:1;
      };
   };
} PMSTATbits;
#word PMSTATbits = 0x60E
#word PMSTAT = 0x60E

#word ALRMVAL = 0x620

struct ALCFGRPTBITS {
   unsigned int ARPT0:1;
   unsigned int ARPT1:1;
   unsigned int ARPT2:1;
   unsigned int ARPT3:1;
   unsigned int ARPT4:1;
   unsigned int ARPT5:1;
   unsigned int ARPT6:1;
   unsigned int ARPT7:1;
   unsigned int APTR8:1;
   unsigned int APTR9:1;
   unsigned int AMASK10:1;
   unsigned int AMASK11:1;
   unsigned int AMASK12:1;
   unsigned int AMASK13:1;
   unsigned int CHIME:1;
   unsigned int ALRMEN:1;
} ALCFGRPTbits;
#word ALCFGRPTbits = 0x622
#word ALCFGRPT = 0x622

#word RTCVAL = 0x624

struct RCFGCALBITS {
   unsigned int CAL0:1;
   unsigned int CAL1:1;
   unsigned int CAL2:1;
   unsigned int CAL3:1;
   unsigned int CAL4:1;
   unsigned int CAL5:1;
   unsigned int CAL6:1;
   unsigned int CAL7:1;
   unsigned int RTCPTR8:1;
   unsigned int RTCPTR9:1;
   unsigned int RTCOE:1;
   unsigned int HALFSEC:1;
   unsigned int RTCSYNC:1;
   unsigned int RTCWREN:1;
   unsigned int :1;
   unsigned int RTCEN:1;
} RCFGCALbits;
#word RCFGCALbits = 0x626
#word RCFGCAL = 0x626

struct CMCONBITS {
   unsigned int C1POS:1;
   unsigned int C1NEG:1;
   unsigned int C2POS:1;
   unsigned int C2NEG:1;
   unsigned int C1INV:1;
   unsigned int C2INV:1;
   unsigned int C1OUT:1;
   unsigned int C2OUT:1;
   unsigned int C1OUTEN:1;
   unsigned int C2OUTEN:1;
   unsigned int C1EN:1;
   unsigned int C2EN:1;
   unsigned int C1EVT:1;
   unsigned int C2EVT:1;
   unsigned int :1;
   unsigned int CMIDL:1;
} CMCONbits;
#word CMCONbits = 0x630
#word CMCON = 0x630

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
#word CVRCONbits = 0x632
#word CVRCON = 0x632

struct CRCCONBITS {
   unsigned int PLEN0:1;
   unsigned int PLEN1:1;
   unsigned int PLEN2:1;
   unsigned int PLEN3:1;
   unsigned int CRCGO:1;
   unsigned int :1;
   unsigned int CRCMPT:1;
   unsigned int CRCFUL:1;
   unsigned int VWORD8:1;
   unsigned int VWORD9:1;
   unsigned int VWORD10:1;
   unsigned int VWORD11:1;
   unsigned int VWORD12:1;
   unsigned int CSIDL:1;
} CRCCONbits;
#word CRCCONbits = 0x640
#word CRCCON = 0x640

#word CRCXOR = 0x642

#word CRCDAT = 0x644

#word CRCWDAT = 0x646

struct ODCABITS {
   unsigned int ODCA0:1;
   unsigned int ODCA1:1;
   unsigned int ODCA2:1;
   unsigned int ODCA3:1;
   unsigned int ODCA4:1;
   unsigned int ODCA5:1;
   unsigned int ODCA6:1;
   unsigned int ODCA7:1;
   unsigned int :1;
   unsigned int ODCA9:1;
   unsigned int ODCA10:1;
   unsigned int :3;
   unsigned int ODCA14:1;
   unsigned int ODCA15:1;
} ODCAbits;
#word ODCAbits = 0x6C0
#word ODCA = 0x6C0

#word ODCB = 0x6C6

struct ODCCBITS {
   unsigned int :1;
   unsigned int ODCC1:1;
   unsigned int ODCC2:1;
   unsigned int ODCC3:1;
   unsigned int ODCC4:1;
   unsigned int :7;
   unsigned int ODCC12:1;
   unsigned int ODCC13:1;
   unsigned int ODCC14:1;
   unsigned int ODCC15:1;
} ODCCbits;
#word ODCCbits = 0x6CC
#word ODCC = 0x6CC

#word ODCD = 0x6D2

#word ODCE = 0x6D8

struct ODCFBITS {
   unsigned int ODCF0:1;
   unsigned int ODCF1:1;
   unsigned int ODCF2:1;
   unsigned int ODCF3:1;
   unsigned int ODCF4:1;
   unsigned int ODCF5:1;
   unsigned int ODCF6:1;
   unsigned int ODCF7:1;
   unsigned int ODCF8:1;
   unsigned int :3;
   unsigned int ODCF12:1;
   unsigned int ODCF13:1;
} ODCFbits;
#word ODCFbits = 0x6DE
#word ODCF = 0x6DE

struct ODCGBITS {
   unsigned int ODCG0:1;
   unsigned int ODCG1:1;
   unsigned int ODCG2:1;
   unsigned int ODCG3:1;
   unsigned int :2;
   unsigned int ODCG6:1;
   unsigned int ODCG7:1;
   unsigned int ODCG8:1;
   unsigned int ODCG9:1;
   unsigned int :2;
   unsigned int ODCG12:1;
   unsigned int ODCG13:1;
   unsigned int ODCG14:1;
   unsigned int ODCG15:1;
} ODCGbits;
#word ODCGbits = 0x6E4
#word ODCG = 0x6E4

struct RCONBITS {
   unsigned int POR:1;
   unsigned int BOR:1;
   unsigned int IDLE:1;
   unsigned int SLEEP:1;
   unsigned int WDTO:1;
   unsigned int SWDTEN:1;
   unsigned int SWR:1;
   unsigned int EXTR:1;
   unsigned int VREGS:1;
   unsigned int CM:1;
   unsigned int :4;
   unsigned int IOPR:1;
   unsigned int TRAPR:1;
} RCONbits;
#word RCONbits = 0x740
#word RCON = 0x740

struct OSCCONBITS {
   unsigned int OSWEN:1;
   unsigned int SOSCEN:1;
   unsigned int :1;
   unsigned int CF:1;
   unsigned int :1;
   unsigned int LOCK:1;
   unsigned int :1;
   unsigned int CLKLOCK:1;
   unsigned int NOSC8:1;
   unsigned int NOSC9:1;
   unsigned int NOSC2:1;
   unsigned int :1;
   unsigned int COSC12:1;
   unsigned int COSC13:1;
   unsigned int COSC2:1;
} OSCCONbits;
#word OSCCONbits = 0x742
#word OSCCON = 0x742

struct CLKDIVBITS {
   unsigned int :8;
   unsigned int RCDIV8:1;
   unsigned int RCDIV9:1;
   unsigned int RCDIV10:1;
   unsigned int DOZEN:1;
   unsigned int DOZE12:1;
   unsigned int DOZE13:1;
   unsigned int DOZE14:1;
   unsigned int ROI:1;
} CLKDIVbits;
#word CLKDIVbits = 0x744
#word CLKDIV = 0x744

#word OSCTUN = 0x748

struct NVMCONBITS {
   unsigned int NVMOP0:1;
   unsigned int NVMOP1:1;
   unsigned int NVMOP2:1;
   unsigned int NVMOP3:1;
   unsigned int :2;
   unsigned int ERASE:1;
   unsigned int :6;
   unsigned int WRERR:1;
   unsigned int WREN:1;
   unsigned int WR:1;
} NVMCONbits;
#word NVMCONbits = 0x760
#word NVMCON = 0x760

#word NVMKEY = 0x766

struct PMD1BITS {
   unsigned int ADCM:1;
   unsigned int :2;
   unsigned int SPI1MD:1;
   unsigned int SPI2MD:1;
   unsigned int U1MD:1;
   unsigned int U2MD:1;
   unsigned int I2C1MD:1;
   unsigned int :3;
   unsigned int T1MD:1;
   unsigned int T2MD:1;
   unsigned int T3MD:1;
   unsigned int T4MD:1;
   unsigned int T5MD:1;
} PMD1bits;
#word PMD1bits = 0x770
#word PMD1 = 0x770

struct PMD2BITS {
   unsigned int _0C1MD:1;
   unsigned int OC2MD:1;
   unsigned int OC3MD:1;
   unsigned int OC4MD:1;
   unsigned int OC5MD:1;
   unsigned int :3;
   unsigned int IC1MD:1;
   unsigned int IC2MD:1;
   unsigned int IC3MD:1;
   unsigned int IC4MD:1;
   unsigned int IC5MD:1;
} PMD2bits;
#word PMD2bits = 0x772
#word PMD2 = 0x772

struct PMD3BITS {
   unsigned int :1;
   unsigned int I2CMD:1;
   unsigned int :5;
   unsigned int CRCPMD:1;
   unsigned int PMPMD:1;
   unsigned int RTCCMD:1;
   unsigned int CMPMD:1;
} PMD3bits;
#word PMD3bits = 0x774
#word PMD3 = 0x774

