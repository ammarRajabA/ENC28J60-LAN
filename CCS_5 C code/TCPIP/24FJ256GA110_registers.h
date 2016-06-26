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

struct CNPD1BITS {
   unsigned int CN0PDE:1;
   unsigned int CN1PDE:1;
   unsigned int CN2PDE:1;
   unsigned int CN3PDE:1;
   unsigned int CN4PDE:1;
   unsigned int CN5PDE:1;
   unsigned int CN6PDE:1;
   unsigned int CN7PDE:1;
   unsigned int CN8PDE:1;
   unsigned int CN9PDE:1;
   unsigned int CN10PDE:1;
   unsigned int CN11PDE:1;
   unsigned int CN12PDE:1;
   unsigned int CN13PDE:1;
   unsigned int CN14PDE:1;
   unsigned int CN15PDE:1;
} CNPD1bits;
#word CNPD1bits = 0x054
#word CNPD1 = 0x054

struct CNPD2BITS {
   unsigned int CN16PDE:1;
   unsigned int CN17PDE:1;
   unsigned int CN18PDE:1;
   unsigned int CN19PDE:1;
   unsigned int CN20PDE:1;
   unsigned int CN21PDE:1;
   unsigned int CN22PDE:1;
   unsigned int CN23PDE:1;
   unsigned int CN24PDE:1;
   unsigned int CN25PDE:1;
   unsigned int CN26PDE:1;
   unsigned int CN27PDE:1;
   unsigned int CN28PDE:1;
   unsigned int CN29PDE:1;
   unsigned int CN30PDE:1;
   unsigned int CN31PDE:1;
} CNPD2bits;
#word CNPD2bits = 0x056
#word CNPD2 = 0x056

struct CNPD3BITS {
   unsigned int CN32PDE:1;
   unsigned int CN33PDE:1;
   unsigned int CN34PDE:1;
   unsigned int CN35PDE:1;
   unsigned int CN36PDE:1;
   unsigned int CN37PDE:1;
   unsigned int CN38PDE:1;
   unsigned int CN39PDE:1;
   unsigned int CN40PDE:1;
   unsigned int CN41PDE:1;
   unsigned int CN42PDE:1;
   unsigned int CN43PDE:1;
   unsigned int CN44PDE:1;
   unsigned int CN45PDE:1;
   unsigned int CN46PDE:1;
   unsigned int CN47PDE:1;
} CNPD3bits;
#word CNPD3bits = 0x058
#word CNPD3 = 0x058

struct CNPD4BITS {
   unsigned int CN48PDE:1;
   unsigned int CN49PDE:1;
   unsigned int CN50PDE:1;
   unsigned int CN51PDE:1;
   unsigned int CN52PDE:1;
   unsigned int CN53PDE:1;
   unsigned int CN54PDE:1;
   unsigned int CN55PDE:1;
   unsigned int CN56PDE:1;
   unsigned int CN57PDE:1;
   unsigned int CN58PDE:1;
   unsigned int CN59PDE:1;
   unsigned int CN60PDE:1;
   unsigned int CN61PDE:1;
   unsigned int CN62PDE:1;
   unsigned int CN63PDE:1;
} CNPD4bits;
#word CNPD4bits = 0x05A
#word CNPD4 = 0x05A

struct CNPD5BITS {
   unsigned int CN64PDE:1;
   unsigned int CN65PDE:1;
   unsigned int CN66PDE:1;
   unsigned int CN67PDE:1;
   unsigned int CN68PDE:1;
   unsigned int CN69PDE:1;
   unsigned int CN70PDE:1;
   unsigned int CN71PDE:1;
   unsigned int :2;
   unsigned int CN74PDE:1;
   unsigned int CN75PDE:1;
   unsigned int CN76PDE:1;
   unsigned int CN77PDE:1;
   unsigned int CN78PDE:1;
   unsigned int CN79PDE:1;
} CNPD5bits;
#word CNPD5bits = 0x05C
#word CNPD5 = 0x05C

struct CNPD6BITS {
   unsigned int CN80PDE:1;
   unsigned int CN81PDE:1;
   unsigned int CN82PDE:1;
} CNPD6bits;
#word CNPD6bits = 0x05E
#word CNPD6 = 0x05E

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
   unsigned int CN22IE:1;
   unsigned int CN23IE:1;
   unsigned int CN24IE:1;
   unsigned int CN25E:1;
   unsigned int CN26IE:1;
   unsigned int CN27IE:1;
   unsigned int CN28IE:1;
   unsigned int CN29IE:1;
   unsigned int CN30IE:1;
   unsigned int CN31IE:1;
} CNEN2bits;
#word CNEN2bits = 0x062
#word CNEN2 = 0x062

struct CNEN3BITS {
   unsigned int CN32IE:1;
   unsigned int CN33IE:1;
   unsigned int CN34IE:1;
   unsigned int CN35IE:1;
   unsigned int CN36IE:1;
   unsigned int CN37IE:1;
   unsigned int CN38IE:1;
   unsigned int CN39IE:1;
   unsigned int CN40IE:1;
   unsigned int CN41IE:1;
   unsigned int CN42IE:1;
   unsigned int CN43IE:1;
   unsigned int CN44IE:1;
   unsigned int CN45IE:1;
   unsigned int CN46IE:1;
   unsigned int CN47IE:1;
} CNEN3bits;
#word CNEN3bits = 0x064
#word CNEN3 = 0x064

struct CNEN4BITS {
   unsigned int CN48IE:1;
   unsigned int CN49IE:1;
   unsigned int CN50IE:1;
   unsigned int CN51IE:1;
   unsigned int CN52IE:1;
   unsigned int CN53IE:1;
   unsigned int CN54IE:1;
   unsigned int CN55IE:1;
   unsigned int CN56IE:1;
   unsigned int CN57IE:1;
   unsigned int CN58IE:1;
   unsigned int CN59IE:1;
   unsigned int CN60IE:1;
   unsigned int CN61IE:1;
   unsigned int CN62IE:1;
   unsigned int CN63IE:1;
} CNEN4bits;
#word CNEN4bits = 0x066
#word CNEN4 = 0x066

struct CNEN5BITS {
   unsigned int CN64IE:1;
   unsigned int CN65IE:1;
   unsigned int CN66IE:1;
   unsigned int CN67IE:1;
   unsigned int CN68IE:1;
   unsigned int CN69IE:1;
   unsigned int CN70IE:1;
   unsigned int CN71IE:1;
   unsigned int :2;
   unsigned int CN74IE:1;
   unsigned int CN75IE:1;
   unsigned int CN76IE:1;
   unsigned int CN77IE:1;
   unsigned int CN78IE:1;
   unsigned int CN79IE:1;
} CNEN5bits;
#word CNEN5bits = 0x068
#word CNEN5 = 0x068

struct CNEN6BITS {
   unsigned int CN80IE:1;
   unsigned int CN81IE:1;
   unsigned int CN82IE:1;
} CNEN6bits;
#word CNEN6bits = 0x06A
#word CNEN6 = 0x06A

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
#word CNPU1bits = 0x06C
#word CNPU1 = 0x06C

struct CNPU2BITS {
   unsigned int CN16PUE:1;
   unsigned int CN17PUE:1;
   unsigned int CN18PUE:1;
   unsigned int CN19PUE:1;
   unsigned int CN20PUE:1;
   unsigned int CN21PUE:1;
   unsigned int CN22PUE:1;
   unsigned int CN23PUE:1;
   unsigned int CN24PUE:1;
   unsigned int CN25PUE:1;
   unsigned int CN26PUE:1;
   unsigned int CN27PUE:1;
   unsigned int CN28PUE:1;
   unsigned int CN29PUE:1;
   unsigned int CN30PUE:1;
   unsigned int CN31PUE:1;
} CNPU2bits;
#word CNPU2bits = 0x06E
#word CNPU2 = 0x06E

struct CNPU3BITS {
   unsigned int CN32PUE:1;
   unsigned int CN33PUE:1;
   unsigned int CN34PUE:1;
   unsigned int CN35PUE:1;
   unsigned int CN36PUE:1;
   unsigned int CN37PUE:1;
   unsigned int CN38PUE:1;
   unsigned int CN39PUE:1;
   unsigned int CN40PUE:1;
   unsigned int CN41PUE:1;
   unsigned int CN42PUE:1;
   unsigned int CN43PUE:1;
   unsigned int CN44PUE:1;
   unsigned int CN45PUE:1;
   unsigned int CN46PUE:1;
   unsigned int CN47PUE:1;
} CNPU3bits;
#word CNPU3bits = 0x070
#word CNPU3 = 0x070

struct CNPU4BITS {
   unsigned int CN48PUE:1;
   unsigned int CN49PUE:1;
   unsigned int CN50PUE:1;
   unsigned int CN51PUE:1;
   unsigned int CN52PUE:1;
   unsigned int CN53PUE:1;
   unsigned int CN54PUE:1;
   unsigned int CN55PUE:1;
   unsigned int CN56PUE:1;
   unsigned int CN57PUE:1;
   unsigned int CN58PUE:1;
   unsigned int CN59PUE:1;
   unsigned int CN60PUE:1;
   unsigned int CN61PUE:1;
   unsigned int CN62PUE:1;
   unsigned int CN63PUE:1;
} CNPU4bits;
#word CNPU4bits = 0x072
#word CNPU4 = 0x072

struct CNPU5BITS {
   unsigned int CN64PUE:1;
   unsigned int CN65PUE:1;
   unsigned int CN66PUE:1;
   unsigned int CN67PUE:1;
   unsigned int CN68PUE:1;
   unsigned int CN69PUE:1;
   unsigned int CN70PUE:1;
   unsigned int CN71PUE:1;
   unsigned int :2;
   unsigned int CN74PUE:1;
   unsigned int CN75PUE:1;
   unsigned int CN76PUE:1;
   unsigned int CN77PUE:1;
   unsigned int CN78PUE:1;
   unsigned int CN79PUE:1;
} CNPU5bits;
#word CNPU5bits = 0x074
#word CNPU5 = 0x074

struct CNPU6BITS {
   unsigned int CN80PUE:1;
   unsigned int CN81PUE:1;
   unsigned int CN82PUE:1;
} CNPU6bits;
#word CNPU6bits = 0x076
#word CNPU6 = 0x076

struct INTCON1BITS {
   unsigned int :1;
   unsigned int OSCFAIL:1;
   unsigned int STKERR:1;
   unsigned int ADDRERR:1;
   unsigned int MATHERR:1;
   unsigned int :10;
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
   unsigned int SPF1IF:1;
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
   unsigned int CMIF:1;
   unsigned int CNIF:1;
   unsigned int INT1IF:1;
   unsigned int :1;
   unsigned int IC7IF:1;
   unsigned int IC8IF:1;
   unsigned int :1;
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
   unsigned int SPF2IF:1;
   unsigned int SPI2IF:1;
   unsigned int :3;
   unsigned int IC3IF:1;
   unsigned int IC4IF:1;
   unsigned int IC5IF:1;
   unsigned int IC6IF:1;
   unsigned int OC5IF:1;
   unsigned int OC6IF:1;
   unsigned int OC7IF:1;
   unsigned int OC8IF:1;
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
   unsigned int RTCIF:1;
} IFS3bits;
#word IFS3bits = 0x08A
#word IFS3 = 0x08A

struct IFS4BITS {
   unsigned int :1;
   unsigned int U1ERIF:1;
   unsigned int U2ERIF:1;
   unsigned int CRCIF:1;
   unsigned int :4;
   unsigned int LVDIF:1;
   unsigned int :4;
   unsigned int CTMUIF:1;
} IFS4bits;
#word IFS4bits = 0x08C
#word IFS4 = 0x08C

struct IFS5BITS {
   unsigned int :1;
   unsigned int U3ERIF:1;
   unsigned int U3RXIF:1;
   unsigned int U3TXIF:1;
   unsigned int SI2C3IF:1;
   unsigned int MI2C3IF:1;
   unsigned int :1;
   unsigned int U4ERIF:1;
   unsigned int U4RXIF:1;
   unsigned int U4TXIF:1;
   unsigned int SPF3IF:1;
   unsigned int SPI3IF:1;
   unsigned int OC9IF:1;
   unsigned int IC9IF:1;
} IFS5bits;
#word IFS5bits = 0x08E
#word IFS5 = 0x08E

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
   unsigned int SPF1IE:1;
   unsigned int SPI1IE:1;
   unsigned int U1RXIE:1;
   unsigned int U1TXIE:1;
   unsigned int AD1IE:1;
} IEC0bits;
#word IEC0bits = 0x094
#word IEC0 = 0x094

struct IEC1BITS {
   unsigned int SI2C1IE:1;
   unsigned int MI2C1IE:1;
   unsigned int CMIE:1;
   unsigned int CNIE:1;
   unsigned int INT1IE:1;
   unsigned int :1;
   unsigned int IC7IE:1;
   unsigned int IC8IE:1;
   unsigned int :1;
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
   unsigned int SPF2IE:1;
   unsigned int SPI2IE:1;
   unsigned int :3;
   unsigned int IC3IE:1;
   unsigned int IC4IE:1;
   unsigned int IC5IE:1;
   unsigned int IC6IE:1;
   unsigned int OC5IE:1;
   unsigned int OC6IE:1;
   unsigned int OC7IE:1;
   unsigned int OC8IE:1;
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
   unsigned int RTCIE:1;
} IEC3bits;
#word IEC3bits = 0x09A
#word IEC3 = 0x09A

struct IEC4BITS {
   unsigned int :1;
   unsigned int U1ERIE:1;
   unsigned int U2ERIE:1;
   unsigned int CRCIE:1;
   unsigned int :4;
   unsigned int LVDIE:1;
   unsigned int :4;
   unsigned int CTMUIE:1;
} IEC4bits;
#word IEC4bits = 0x09C
#word IEC4 = 0x09C

struct IEC5BITS {
   unsigned int :1;
   unsigned int U3ERIE:1;
   unsigned int U3RXIE:1;
   unsigned int U3TXIE:1;
   unsigned int SI2C3IE:1;
   unsigned int MI2C3IE:1;
   unsigned int :1;
   unsigned int U4ERIE:1;
   unsigned int U4RXIE:1;
   unsigned int U4TXIE:1;
   unsigned int SPF3IE:1;
   unsigned int SPI3IE:1;
   unsigned int OC9IE:1;
   unsigned int IC9IE:1;
} IEC5bits;
#word IEC5bits = 0x09E
#word IEC5 = 0x09E

struct IPC0BITS {
   /* bug
   unsigned int INT0IP0:1;
   unsigned int INT0IP1:1;
   unsigned int INT0IP2:1;
   unsigned int :1;
   unsigned int IC1IP4:1;
   unsigned int IC1IP5:1;
   unsigned int IC1IP2:1;
   unsigned int :1;
   unsigned int OC1IP8:1;
   unsigned int OC1IP9:1;
   unsigned int OC1IP2:1;
   unsigned int :1;
   unsigned int T1IP12:1;
   unsigned int T1IP13:1;
   unsigned int T1IP2:1;
   */
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
   unsigned int SPF1IP4:1;
   unsigned int SPF1IP5:1;
   unsigned int SPF1IP2:1;
   unsigned int :1;
   unsigned int SPI1IP8:1;
   unsigned int SPI1IP9:1;
   unsigned int SPI1IP2:1;
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
   unsigned int AD1IP4:1;
   unsigned int AD1IP5:1;
   unsigned int AD1IP2:1;
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
   unsigned int CMIP8:1;
   unsigned int CMIP9:1;
   unsigned int CMIP2:1;
   unsigned int :1;
   unsigned int CNIP12:1;
   unsigned int CNIP13:1;
   unsigned int CNIP2:1;
} IPC4bits;
#word IPC4bits = 0x0AC
#word IPC4 = 0x0AC

struct IPC5BITS {
   unsigned int INT1IP0:1;
   unsigned int INT1IP1:1;
   unsigned int INT1IP2:1;
   unsigned int :5;
   unsigned int IC7IP8:1;
   unsigned int IC7IP9:1;
   unsigned int IC7IP2:1;
   unsigned int :1;
   unsigned int IC8IP12:1;
   unsigned int IC8IP13:1;
   unsigned int IC8IP2:1;
} IPC5bits;
#word IPC5bits = 0x0AE
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
   unsigned int SPF2IP0:1;
   unsigned int SPF2IP1:1;
   unsigned int SPF2IP2:1;
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
   unsigned int IC6IP0:1;
   unsigned int IC6IP1:1;
   unsigned int IC6IP2:1;
   unsigned int :1;
   unsigned int OC5IP4:1;
   unsigned int OC5IP5:1;
   unsigned int OC5IP2:1;
   unsigned int :1;
   unsigned int OC6IP8:1;
   unsigned int OC6IP9:1;
   unsigned int OC6IP2:1;
   unsigned int :1;
   unsigned int OC7IP12:1;
   unsigned int OC7IP13:1;
   unsigned int OC7IP2:1;
} IPC10bits;
#word IPC10bits = 0x0B8
#word IPC10 = 0x0B8

struct IPC11BITS {
   unsigned int OC8IP0:1;
   unsigned int OC8IP1:1;
   unsigned int OC8IP2:1;
   unsigned int :1;
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
   unsigned int RTCIP8:1;
   unsigned int RTCIP9:1;
   unsigned int RTCIP2:1;
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

#word IPC18 = 0x0C8

struct IPC19BITS {
   unsigned int :4;
   unsigned int CTMUIP4:1;
   unsigned int CTMUIP5:1;
   unsigned int CTMUIP2:1;
} IPC19bits;
#word IPC19bits = 0x0CA
#word IPC19 = 0x0CA

struct IPC20BITS {
   unsigned int :4;
   unsigned int U3ERIP4:1;
   unsigned int U3ERIP5:1;
   unsigned int U3ERIP2:1;
   unsigned int :1;
   unsigned int U3RXIP8:1;
   unsigned int U3RXIP9:1;
   unsigned int U3RXIP2:1;
   unsigned int :1;
   unsigned int U3TXIP12:1;
   unsigned int U3TXIP13:1;
   unsigned int U3TXIP2:1;
} IPC20bits;
#word IPC20bits = 0x0CC
#word IPC20 = 0x0CC

struct IPC21BITS {
   unsigned int SI2C3P0:1;
   unsigned int SI2C3P1:1;
   unsigned int SI2C3P2:1;
   unsigned int :1;
   unsigned int MI2C3P4:1;
   unsigned int MI2C3P5:1;
   unsigned int MI2C3P2:1;
   unsigned int :5;
   unsigned int U4ERIP12:1;
   unsigned int U4ERIP13:1;
   unsigned int U4ERIP2:1;
} IPC21bits;
#word IPC21bits = 0x0CE
#word IPC21 = 0x0CE

struct IPC22BITS {
   unsigned int U4RXIP0:1;
   unsigned int U4RXIP1:1;
   unsigned int U4RXIP2:1;
   unsigned int :1;
   unsigned int U4TXIP4:1;
   unsigned int U4TXIP5:1;
   unsigned int U4TXIP2:1;
   unsigned int :1;
   unsigned int SPF3IP8:1;
   unsigned int SPF3IP9:1;
   unsigned int SPF3IP2:1;
   unsigned int :1;
   unsigned int SPI3IP12:1;
   unsigned int SPI3IP13:1;
   unsigned int SPI3IP2:1;
} IPC22bits;
#word IPC22bits = 0x0D0
#word IPC22 = 0x0D0

struct IPC23BITS {
   unsigned int OC9IP0:1;
   unsigned int OC9IP1:1;
   unsigned int OC9IP2:1;
   unsigned int :1;
   unsigned int IC9IP4:1;
   unsigned int IC9IP5:1;
   unsigned int IC9IP2:1;
} IPC23bits;
#word IPC23bits = 0x0D2
#word IPC23 = 0x0D2

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
   unsigned int TSYNC:1;
   unsigned int :1;
   /* //bug
   unsigned int TCKPS4:1;
   unsigned int TCKPS5:1;
   */
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

struct IC1CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC1CON1bits;
#word IC1CON1bits = 0x140
#word IC1CON1 = 0x140

struct IC1CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC1CON2bits;
#word IC1CON2bits = 0x142
#word IC1CON2 = 0x142

#word IC1BUF = 0x144

#word IC1TMR = 0x146

struct IC2CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC2CON1bits;
#word IC2CON1bits = 0x148
#word IC2CON1 = 0x148

struct IC2CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC2CON2bits;
#word IC2CON2bits = 0x14A
#word IC2CON2 = 0x14A

#word IC2BUF = 0x14C

#word IC2TMR = 0x14E

struct IC3CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC3CON1bits;
#word IC3CON1bits = 0x150
#word IC3CON1 = 0x150

struct IC3CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC3CON2bits;
#word IC3CON2bits = 0x152
#word IC3CON2 = 0x152

#word IC3BUF = 0x154

#word IC3TMR = 0x156

struct IC4CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC4CON1bits;
#word IC4CON1bits = 0x158
#word IC4CON1 = 0x158

struct IC4CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC4CON2bits;
#word IC4CON2bits = 0x15A
#word IC4CON2 = 0x15A

#word IC4BUF = 0x15C

#word IC4TMR = 0x15E

struct IC5CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC5CON1bits;
#word IC5CON1bits = 0x160
#word IC5CON1 = 0x160

struct IC5CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC5CON2bits;
#word IC5CON2bits = 0x162
#word IC5CON2 = 0x162

#word IC5BUF = 0x164

#word IC5TMR = 0x166

struct IC6CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC6CON1bits;
#word IC6CON1bits = 0x168
#word IC6CON1 = 0x168

struct IC6CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC6CON2bits;
#word IC6CON2bits = 0x16A
#word IC6CON2 = 0x16A

#word IC6BUF = 0x16C

#word IC6TMR = 0x16E

struct IC7CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC7CON1bits;
#word IC7CON1bits = 0x170
#word IC7CON1 = 0x170

struct IC7CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC7CON2bits;
#word IC7CON2bits = 0x172
#word IC7CON2 = 0x172

#word IC7BUF = 0x174

#word IC7TMR = 0x176

struct IC8CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC8CON1bits;
#word IC8CON1bits = 0x178
#word IC8CON1 = 0x178

struct IC8CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC8CON2bits;
#word IC8CON2bits = 0x17A
#word IC8CON2 = 0x17A

#word IC8BUF = 0x17C

#word IC8TMR = 0x17E

struct IC9CON1BITS {
   unsigned int ICM0:1;
   unsigned int ICM1:1;
   unsigned int ICM2:1;
   unsigned int ICBNE:1;
   unsigned int ICOV:1;
   unsigned int ICI5:1;
   unsigned int ICI1:1;
   unsigned int :3;
   unsigned int ICTSEL10:1;
   unsigned int ICTSEL11:1;
   unsigned int ICTSEL12:1;
   unsigned int ICSIDL:1;
} IC9CON1bits;
#word IC9CON1bits = 0x180
#word IC9CON1 = 0x180

struct IC9CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int :1;
   unsigned int TRIGSTAT:1;
   unsigned int ICTRIG:1;
   unsigned int IC32:1;
} IC9CON2bits;
#word IC9CON2bits = 0x182
#word IC9CON2 = 0x182

#word IC9BUF = 0x184

#word IC9TMR = 0x186

struct OC1CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC1CON1bits;
#word OC1CON1bits = 0x190
#word OC1CON1 = 0x190

struct OC1CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC1CON2bits;
#word OC1CON2bits = 0x192
#word OC1CON2 = 0x192

#word OC1RS = 0x194

#word OC1R = 0x196

#word OC1TMR = 0x198

struct OC2CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC2CON1bits;
#word OC2CON1bits = 0x19A
#word OC2CON1 = 0x19A

struct OC2CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC2CON2bits;
#word OC2CON2bits = 0x19C
#word OC2CON2 = 0x19C

#word OC2RS = 0x19E

#word OC2R = 0x1A0

#word OC2TMR = 0x1A2

struct OC3CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC3CON1bits;
#word OC3CON1bits = 0x1A4
#word OC3CON1 = 0x1A4

struct OC3CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC3CON2bits;
#word OC3CON2bits = 0x1A6
#word OC3CON2 = 0x1A6

#word OC3RS = 0x1A8

#word OC3R = 0x1AA

#word OC3TMR = 0x1AC

struct OC4CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC4CON1bits;
#word OC4CON1bits = 0x1AE
#word OC4CON1 = 0x1AE

struct OC4CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC4CON2bits;
#word OC4CON2bits = 0x1B0
#word OC4CON2 = 0x1B0

#word OC4RS = 0x1B2

#word OC4R = 0x1B4

#word OC4TMR = 0x1B6

struct OC5CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC5CON1bits;
#word OC5CON1bits = 0x1B8
#word OC5CON1 = 0x1B8

struct OC5CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC5CON2bits;
#word OC5CON2bits = 0x1BA
#word OC5CON2 = 0x1BA

#word OC5RS = 0x1BC

#word OC5R = 0x1BE

#word OC5TMR = 0x1C0

struct OC6CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC6CON1bits;
#word OC6CON1bits = 0x1C2
#word OC6CON1 = 0x1C2

struct OC6CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC6CON2bits;
#word OC6CON2bits = 0x1C4
#word OC6CON2 = 0x1C4

#word OC6RS = 0x1C6

#word OC6R = 0x1C8

#word OC6TMR = 0x1CA

struct OC7CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC7CON1bits;
#word OC7CON1bits = 0x1CC
#word OC7CON1 = 0x1CC

struct OC7CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC7CON2bits;
#word OC7CON2bits = 0x1CE
#word OC7CON2 = 0x1CE

#word OC7RS = 0x1D0

#word OC7R = 0x1D2

#word OC7TMR = 0x1D4

struct OC8CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC8CON1bits;
#word OC8CON1bits = 0x1D6
#word OC8CON1 = 0x1D6

struct OC8CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC8CON2bits;
#word OC8CON2bits = 0x1D8
#word OC8CON2 = 0x1D8

#word OC8RS = 0x1DA

#word OC8R = 0x1DC

#word OC8TMR = 0x1DE

struct OC9CON1BITS {
   unsigned int OCM0:1;
   unsigned int OCM1:1;
   unsigned int OCM2:1;
   unsigned int TRIGMODE:1;
   unsigned int OCFLT0:1;
   unsigned int :2;
   unsigned int ENFLT0:1;
   unsigned int :2;
   unsigned int OCTSEL10:1;
   unsigned int OCTSEL11:1;
   unsigned int OCTSEL12:1;
   unsigned int OCSIDL:1;
} OC9CON1bits;
#word OC9CON1bits = 0x1E0
#word OC9CON1 = 0x1E0

struct OC9CON2BITS {
   unsigned int SYNCSEL0:1;
   unsigned int SYNCSEL1:1;
   unsigned int SYNCSEL2:1;
   unsigned int SYNCSEL3:1;
   unsigned int SYNCSEL4:1;
   unsigned int OCTRIS:1;
   unsigned int TRIGSTAT:1;
   unsigned int OCTRIG:1;
   unsigned int OC32:1;
   unsigned int :3;
   unsigned int OCINV:1;
   unsigned int FLTTRIEN:1;
   unsigned int FLTOUT:1;
   unsigned int FLTMD:1;
} OC9CON2bits;
#word OC9CON2bits = 0x1E2
#word OC9CON2 = 0x1E2

#word OC9RS = 0x1E4

#word OC9R = 0x1E6

#word OC9TMR = 0x1E8

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
   unsigned int I2COV:1;
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
   unsigned int I2COV:1;
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
   unsigned int SISEL2:1;
   unsigned int SISEL3:1;
   unsigned int SISEL4:1;
   unsigned int SRXMPT:1;
   unsigned int SPIROV:1;
   unsigned int SRMPT:1;
   unsigned int SPIBEC8:1;
   unsigned int SPIBEC9:1;
   unsigned int SPIBEC2:1;
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
   unsigned int MODE16:1;  //bug was called 'MODE'
   unsigned int DISSDO:1;
   unsigned int DISSCK:1;
} SPI1CON1bits;
#word SPI1CON1bits = 0x242
#word SPI1CON1 = 0x242

struct SPI1CON2BITS {
   unsigned int SPIBEN:1;
   unsigned int SPIFE:1;
   unsigned int :11;
   unsigned int SPIFPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI1CON2bits;
#word SPI1CON2bits = 0x244
#word SPI1CON2 = 0x244

#word SPI1BUF = 0x248

struct U3MODEBITS {
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
} U3MODEbits;
#word U3MODEbits = 0x250
#word U3MODE = 0x250

struct U3STABITS {
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
} U3STAbits;
#word U3STAbits = 0x252
#word U3STA = 0x252

#word U3TXREG = 0x254

#word U3RXREG = 0x256

#word U3BRG = 0x258

struct SPI2STATBITS {
   unsigned int SPIRBF:1;
   unsigned int SPITBF:1;
   unsigned int SISEL:3;	//bug
   unsigned int SRXMPT:1;
   unsigned int SPIROV:1;
   unsigned int SRMPT:1;
   unsigned int SPIBEC:3;	//bug
   unsigned int :2;
   unsigned int SPISIDL:1;
   unsigned int :1;
   unsigned int SPIEN:1;
} SPI2STATbits;
#word SPI2STATbits = 0x260
#word SPI2STAT = 0x260

struct SPI2CON1BITS {
   unsigned int PPRE:2;	//bug
   unsigned int SPRE:3;	//bug
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
   unsigned int SPIBEN:1;
   unsigned int SPIFE:1;
   unsigned int :11;
   unsigned int SPIFPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI2CON2bits;
#word SPI2CON2bits = 0x264
#word SPI2CON2 = 0x264

#word SPI2BUF = 0x268

#word I2C3RCV = 0x270

#word I2C3TRN = 0x272

#word I2C3BRG = 0x274

struct I2C3CONBITS {
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
} I2C3CONbits;
#word I2C3CONbits = 0x276
#word I2C3CON = 0x276

struct I2C3STATBITS {
   unsigned int TBF:1;
   unsigned int RBF:1;
   unsigned int R:1;
   unsigned int S:1;
   unsigned int P:1;
   unsigned int D:1;
   unsigned int I2COV:1;
   unsigned int IWCOL:1;
   unsigned int ADD:1;
   unsigned int GCSTAT:1;
   unsigned int BCL:1;
   unsigned int :3;
   unsigned int TRSTAT:1;
   unsigned int ACKSTAT:1;
} I2C3STATbits;
#word I2C3STATbits = 0x278
#word I2C3STAT = 0x278

#word I2C3ADD = 0x27A

#word I2C3MSK = 0x27C

struct SPI3STATBITS {
   unsigned int SPIRBF:1;
   unsigned int SPITBF:1;
   unsigned int SISEL2:1;
   unsigned int SISEL3:1;
   unsigned int SISEL4:1;
   unsigned int SRXMPT:1;
   unsigned int SPIROV:1;
   unsigned int SRMPT:1;
   unsigned int SPIBEC8:1;
   unsigned int SPIBEC9:1;
   unsigned int SPIBEC2:1;
   unsigned int :2;
   unsigned int SPISIDL:1;
   unsigned int :1;
   unsigned int SPIEN:1;
} SPI3STATbits;
#word SPI3STATbits = 0x280
#word SPI3STAT = 0x280

struct SPI3CON1BITS {
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
   unsigned int MODE:1;
   unsigned int DISSDO:1;
   unsigned int DISSCK:1;
} SPI3CON1bits;
#word SPI3CON1bits = 0x282
#word SPI3CON1 = 0x282

struct SPI3CON2BITS {
   unsigned int SPIBEN:1;
   unsigned int SPIFE:1;
   unsigned int :11;
   unsigned int SPIFPOL:1;
   unsigned int SPIFSD:1;
   unsigned int FRMEN:1;
} SPI3CON2bits;
#word SPI3CON2bits = 0x284
#word SPI3CON2 = 0x284

#word SPI3BUF = 0x288

struct U4MODEBITS {
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
} U4MODEbits;
#word U4MODEbits = 0x2B0
#word U4MODE = 0x2B0

struct U4STABITS {
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
} U4STAbits;
#word U4STAbits = 0x2B2
#word U4STA = 0x2B2

#word U4TXREG = 0x2B4

#word U4RXREG = 0x2B6

#word U4BRG = 0x2B8

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
#word ODCAbits = 0x2C6
#word ODCA = 0x2C6

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
//#word TRISB = 0x2C8  //bug was called 'TRISB'
#word TRISBbits = 0x2C8
#word TRISB = 0x2C8

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
#word PORTBbits = 0x2CA
#word PORTB = 0x2CA

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
#word LATBbits = 0x2CC
#word LATB = 0x2CC

#word ODCB = 0x2CE

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
#word TRISCbits = 0x2D0
#word TRISC = 0x2D0

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
#word PORTCbits = 0x2D2
#word PORTC = 0x2D2

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
#word LATCbits = 0x2D4
#word LATC = 0x2D4

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
#word ODCCbits = 0x2D6
#word ODCC = 0x2D6

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
#word TRISDbits = 0x2D8
#word TRISD = 0x2D8

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
#word PORTDbits = 0x2DA
#word PORTD = 0x2DA

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
#word LATDbits = 0x2DC
#word LATD = 0x2DC

#word ODCD = 0x2DE

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
#word TRISEbits = 0x2E0
#word TRISE = 0x2E0

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
#word PORTEbits = 0x2E2
#word PORTE = 0x2E2

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
#word LATEbits = 0x2E4
#word LATE = 0x2E4

#word ODCE = 0x2E6

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
#word TRISFbits = 0x2E8
#word TRISF = 0x2E8

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
#word PORTFbits = 0x2EA
#word PORTF = 0x2EA

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
#word LATFbits = 0x2EC
#word LATF = 0x2EC

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
#word ODCFbits = 0x2EE
#word ODCF = 0x2EE

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
#word TRISGbits = 0x2F0
#word TRISG = 0x2F0

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
#word PORTGbits = 0x2F2
#word PORTG = 0x2F2

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
#word LATGbits = 0x2F4
#word LATG = 0x2F4

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
#word ODCGbits = 0x2F6
#word ODCG = 0x2F6

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
   /* bug
   unsigned int SMPI2:1;
   unsigned int SMPI3:1;
   unsigned int SMPI4:1;
   unsigned int SMPI3:1;
   */
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

struct AD1CHS0BITS {
   unsigned int CH0SA0:1;
   unsigned int CH0SA1:1;
   unsigned int CH0SA2:1;
   unsigned int CH0SA3:1;
   unsigned int CH0SA4:1;
   unsigned int :2;
   unsigned int CH0NA:1;
   unsigned int CH0SB8:1;
   unsigned int CH0SB9:1;
   unsigned int CH0SB10:1;
   unsigned int CH0SB3:1;
   unsigned int :2;
   unsigned int CH0NB14:1;
   unsigned int CH0NB1:1;
} AD1CHS0bits;
#word AD1CHS0bits = 0x328
#word AD1CHS0 = 0x328

#word AD1PCFGH = 0x32A

#word AD1PCFGL = 0x32C

#word AD1CSSL = 0x330

#word AD1CSSH = 0x332

struct CTMUCONBITS {
   unsigned int EDG1STAT:1;
   unsigned int EDG2STAT:1;
   unsigned int EDG1SEL2:1;
   unsigned int EDG1SEL3:1;
   unsigned int EDG1POL:1;
   unsigned int EDG2SEL5:1;
   unsigned int EDG2SEL6:1;
   unsigned int EDG2POL:1;
   unsigned int CTTRIG:1;
   unsigned int IDISSEN:1;
   unsigned int EDGSEQEN:1;
   unsigned int EDGEN:1;
   unsigned int TGEN:1;
   unsigned int CTMUSIDL:1;
   unsigned int :1;
   unsigned int CTMUEN:1;
} CTMUCONbits;
#word CTMUCONbits = 0x33C
#word CTMUCON = 0x33C

struct CTMUICONBITS {
   unsigned int :8;
   unsigned int IRNG8:1;
   unsigned int IRNG9:1;
   unsigned int ITRIM10:1;
   unsigned int ITRIM11:1;
   unsigned int ITRIM12:1;
   unsigned int ITRIM13:1;
   unsigned int ITRIM14:1;
   unsigned int ITRIM5:1;
} CTMUICONbits;
#word CTMUICONbits = 0x33E
#word CTMUICON = 0x33E

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
} PMADDRbits;
#word PMADDRbits = 0x604
#word PMADDR = 0x604

#word PMDOUT1 = 0x606

#word PMDIN1 = 0x608

#word PMDIN2 = 0x60A

#word PMAEN = 0x60C

struct PMSTATBITS {
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
   unsigned int ALRMPTR8:1;
   unsigned int ALRMPTR9:1;
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

struct CMSTATBITS {
   unsigned int C1OUT:1;
   unsigned int C2OUT:1;
   unsigned int C3OUT:1;
   unsigned int :5;
   unsigned int C1EVT:1;
   unsigned int C2EVT:1;
   unsigned int C3EVT:1;
   unsigned int :4;
   unsigned int CMIDL:1;
} CMSTATbits;
#word CMSTATbits = 0x630
#word CMSTAT = 0x630

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

struct CM1CONBITS {
   unsigned int CCH0:1;
   unsigned int CCH1:1;
   unsigned int :2;
   unsigned int CREF:1;
   unsigned int :1;
   unsigned int EVPOL6:1;
   unsigned int EVPOL7:1;
   unsigned int COUT:1;
   unsigned int CEVT:1;
   unsigned int :3;
   unsigned int CPOL:1;
   unsigned int COE:1;
   unsigned int CON:1;
} CM1CONbits;
#word CM1CONbits = 0x634
#word CM1CON = 0x634

struct CM2CONBITS {
   unsigned int CCH0:1;
   unsigned int CCH1:1;
   unsigned int :2;
   unsigned int CREF:1;
   unsigned int :1;
   unsigned int EVPOL6:1;
   unsigned int EVPOL7:1;
   unsigned int COUT:1;
   unsigned int CEVT:1;
   unsigned int :3;
   unsigned int CPOL:1;
   unsigned int COE:1;
   unsigned int CON:1;
} CM2CONbits;
#word CM2CONbits = 0x636
#word CM2CON = 0x636

struct CM3CONBITS {
   unsigned int CCH0:1;
   unsigned int CCH1:1;
   unsigned int :2;
   unsigned int CREF:1;
   unsigned int :1;
   unsigned int EVPOL6:1;
   unsigned int EVPOL7:1;
   unsigned int COUT:1;
   unsigned int CEVT:1;
   unsigned int :3;
   unsigned int CPOL:1;
   unsigned int COE:1;
   unsigned int CON:1;
} CM3CONbits;
#word CM3CONbits = 0x638
#word CM3CON = 0x638

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

struct RPINR0BITS {
   unsigned int :8;
   unsigned int INT1R8:1;
   unsigned int INT1R9:1;
   unsigned int INT1R10:1;
   unsigned int INT1R11:1;
   unsigned int INT1R12:1;
   unsigned int INT1R5:1;
} RPINR0bits;
#word RPINR0bits = 0x680
#word RPINR0 = 0x680

struct RPINR1BITS {
   unsigned int INT2R0:1;
   unsigned int INT2R1:1;
   unsigned int INT2R2:1;
   unsigned int INT2R3:1;
   unsigned int INT2R4:1;
   unsigned int INT2R5:1;
   unsigned int :2;
   unsigned int INT3R8:1;
   unsigned int INT3R9:1;
   unsigned int INT3R10:1;
   unsigned int INT3R11:1;
   unsigned int INT3R12:1;
   unsigned int INT3R5:1;
} RPINR1bits;
#word RPINR1bits = 0x682
#word RPINR1 = 0x682

struct RPINR2BITS {
   unsigned int INT4R0:1;
   unsigned int INT4R1:1;
   unsigned int INT4R2:1;
   unsigned int INT4R3:1;
   unsigned int INT4R4:1;
   unsigned int INT4R5:1;
   unsigned int :2;
   unsigned int T1CKR8:1;
   unsigned int T1CKR9:1;
   unsigned int T1CKR10:1;
   unsigned int T1CKR11:1;
   unsigned int T1CKR12:1;
   unsigned int T1CKR5:1;
} RPINR2bits;
#word RPINR2bits = 0x684
#word RPINR2 = 0x684

struct RPINR3BITS {
   unsigned int T2CKR0:1;
   unsigned int T2CKR1:1;
   unsigned int T2CKR2:1;
   unsigned int T2CKR3:1;
   unsigned int T2CKR4:1;
   unsigned int T2CKR5:1;
   unsigned int :2;
   unsigned int T3CKR8:1;
   unsigned int T3CKR9:1;
   unsigned int T3CKR10:1;
   unsigned int T3CKR11:1;
   unsigned int T3CKR12:1;
   unsigned int T3CKR5:1;
} RPINR3bits;
#word RPINR3bits = 0x686
#word RPINR3 = 0x686

struct RPINR4BITS {
   unsigned int T4CKR0:1;
   unsigned int T4CKR1:1;
   unsigned int T4CKR2:1;
   unsigned int T4CKR3:1;
   unsigned int T4CKR4:1;
   unsigned int T4CKR5:1;
   unsigned int :2;
   unsigned int T5CKR8:1;
   unsigned int T5CKR9:1;
   unsigned int T5CKR10:1;
   unsigned int T5CKR11:1;
   unsigned int T5CKR12:1;
   unsigned int T5CKR5:1;
} RPINR4bits;
#word RPINR4bits = 0x688
#word RPINR4 = 0x688

struct RPINR7BITS {
   unsigned int IC1R0:1;
   unsigned int IC1R1:1;
   unsigned int IC1R2:1;
   unsigned int IC1R3:1;
   unsigned int IC1R4:1;
   unsigned int IC1R5:1;
   unsigned int :2;
   unsigned int IC2R8:1;
   unsigned int IC2R9:1;
   unsigned int IC2R10:1;
   unsigned int IC2R11:1;
   unsigned int IC2R12:1;
   unsigned int IC2R5:1;
} RPINR7bits;
#word RPINR7bits = 0x68E
#word RPINR7 = 0x68E

struct RPINR8BITS {
   unsigned int IC3R0:1;
   unsigned int IC3R1:1;
   unsigned int IC3R2:1;
   unsigned int IC3R3:1;
   unsigned int IC3R4:1;
   unsigned int IC3R5:1;
   unsigned int :2;
   unsigned int IC4R8:1;
   unsigned int IC4R9:1;
   unsigned int IC4R10:1;
   unsigned int IC4R11:1;
   unsigned int IC4R12:1;
   unsigned int IC4R5:1;
} RPINR8bits;
#word RPINR8bits = 0x690
#word RPINR8 = 0x690

struct RPINR9BITS {
   unsigned int IC5R0:1;
   unsigned int IC5R1:1;
   unsigned int IC5R2:1;
   unsigned int IC5R3:1;
   unsigned int IC5R4:1;
   unsigned int IC5R5:1;
   unsigned int :2;
   unsigned int IC6R8:1;
   unsigned int IC6R9:1;
   unsigned int IC6R10:1;
   unsigned int IC6R11:1;
   unsigned int IC6R12:1;
   unsigned int IC6R5:1;
} RPINR9bits;
#word RPINR9bits = 0x692
#word RPINR9 = 0x692

struct RPINR10BITS {
   unsigned int IC7R0:1;
   unsigned int IC7R1:1;
   unsigned int IC7R2:1;
   unsigned int IC7R3:1;
   unsigned int IC7R4:1;
   unsigned int IC7R5:1;
   unsigned int :2;
   unsigned int IC8R8:1;
   unsigned int IC8R9:1;
   unsigned int IC8R10:1;
   unsigned int IC8R11:1;
   unsigned int IC8R12:1;
   unsigned int IC8R5:1;
} RPINR10bits;
#word RPINR10bits = 0x694
#word RPINR10 = 0x694

struct RPINR11BITS {
   unsigned int OCFAR0:1;
   unsigned int OCFAR1:1;
   unsigned int OCFAR2:1;
   unsigned int OCFAR3:1;
   unsigned int OCFAR4:1;
   unsigned int OCFAR5:1;
   unsigned int :2;
   unsigned int OCFBR8:1;
   unsigned int OCFBR9:1;
   unsigned int OCFBR10:1;
   unsigned int OCFBR11:1;
   unsigned int OCFBR12:1;
   unsigned int OCFBR5:1;
} RPINR11bits;
#word RPINR11bits = 0x696
#word RPINR11 = 0x696

struct RPINR15BITS {
   unsigned int :8;
   unsigned int IC9R8:1;
   unsigned int IC9R9:1;
   unsigned int IC9R10:1;
   unsigned int IC9R11:1;
   unsigned int IC9R12:1;
   unsigned int IC9R5:1;
} RPINR15bits;
#word RPINR15bits = 0x69E
#word RPINR15 = 0x69E

struct RPINR17BITS {
   unsigned int :8;
   unsigned int U3RXR8:1;
   unsigned int U3RXR9:1;
   unsigned int U3RXR10:1;
   unsigned int U3RXR11:1;
   unsigned int U3RXR12:1;
   unsigned int U3RXR5:1;
} RPINR17bits;
#word RPINR17bits = 0x6A2
#word RPINR17 = 0x6A2

struct RPINR18BITS {
   unsigned int U1RXR0:1;
   unsigned int U1RXR1:1;
   unsigned int U1RXR2:1;
   unsigned int U1RXR3:1;
   unsigned int U1RXR4:1;
   unsigned int U1RXR5:1;
   unsigned int :2;
   unsigned int U1CTSR8:1;
   unsigned int U1CTSR9:1;
   unsigned int U1CTSR10:1;
   unsigned int U1CTSR11:1;
   unsigned int U1CTSR12:1;
   unsigned int U1CTSR5:1;
} RPINR18bits;
#word RPINR18bits = 0x6A4
#word RPINR18 = 0x6A4

struct RPINR19BITS {
   unsigned int U2RXR0:1;
   unsigned int U2RXR1:1;
   unsigned int U2RXR2:1;
   unsigned int U2RXR3:1;
   unsigned int U2RXR4:1;
   unsigned int U2RXR5:1;
   unsigned int :2;
   unsigned int U2CTSR8:1;
   unsigned int U2CTSR9:1;
   unsigned int U2CTSR10:1;
   unsigned int U2CTSR11:1;
   unsigned int U2CTSR12:1;
   unsigned int U2CTSR5:1;
} RPINR19bits;
#word RPINR19bits = 0x6A6
#word RPINR19 = 0x6A6

struct RPINR20BITS {
   unsigned int SDI1R0:1;
   unsigned int SDI1R1:1;
   unsigned int SDI1R2:1;
   unsigned int SDI1R3:1;
   unsigned int SDI1R4:1;
   unsigned int SDI1R5:1;
   unsigned int :2;
   unsigned int SCK1R8:1;
   unsigned int SCK1R9:1;
   unsigned int SCK1R10:1;
   unsigned int SCK1R11:1;
   unsigned int SCK1R12:1;
   unsigned int SCK1R5:1;
} RPINR20bits;
#word RPINR20bits = 0x6A8
#word RPINR20 = 0x6A8

struct RPINR21BITS {
   unsigned int SS1R0:1;
   unsigned int SS1R1:1;
   unsigned int SS1R2:1;
   unsigned int SS1R3:1;
   unsigned int SS1R4:1;
   unsigned int SS1R5:1;
   unsigned int :2;
   unsigned int U3CTSR8:1;
   unsigned int U3CTSR9:1;
   unsigned int U3CTSR10:1;
   unsigned int U3CTSR11:1;
   unsigned int U3CTSR12:1;
   unsigned int U3CTSR5:1;
} RPINR21bits;
#word RPINR21bits = 0x6AA
#word RPINR21 = 0x6AA

struct RPINR22BITS {
   unsigned int SDI2R0:1;
   unsigned int SDI2R1:1;
   unsigned int SDI2R2:1;
   unsigned int SDI2R3:1;
   unsigned int SDI2R4:1;
   unsigned int SDI2R5:1;
   unsigned int :2;
   unsigned int SCK2R8:1;
   unsigned int SCK2R9:1;
   unsigned int SCK2R10:1;
   unsigned int SCK2R11:1;
   unsigned int SCK2R12:1;
   unsigned int SCK2R5:1;
} RPINR22bits;
#word RPINR22bits = 0x6AC
#word RPINR22 = 0x6AC

#word RPINR23 = 0x6AE

struct RPINR27BITS {
   unsigned int U4RXR0:1;
   unsigned int U4RXR1:1;
   unsigned int U4RXR2:1;
   unsigned int U4RXR3:1;
   unsigned int U4RXR4:1;
   unsigned int U4RXR5:1;
   unsigned int :2;
   unsigned int U4CTSR8:1;
   unsigned int U4CTSR9:1;
   unsigned int U4CTSR10:1;
   unsigned int U4CTSR11:1;
   unsigned int U4CTSR12:1;
   unsigned int U4CTSR5:1;
} RPINR27bits;
#word RPINR27bits = 0x6B6
#word RPINR27 = 0x6B6

struct RPINR28BITS {
   unsigned int SDI3R0:1;
   unsigned int SDI3R1:1;
   unsigned int SDI3R2:1;
   unsigned int SDI3R3:1;
   unsigned int SDI3R4:1;
   unsigned int SDI3R5:1;
   unsigned int :2;
   unsigned int SCK3R8:1;
   unsigned int SCK3R9:1;
   unsigned int SCK3R10:1;
   unsigned int SCK3R11:1;
   unsigned int SCK3R12:1;
   unsigned int SCK3R5:1;
} RPINR28bits;
#word RPINR28bits = 0x6B8
#word RPINR28 = 0x6B8

#word RPINR29 = 0x6BA

struct RPOR0BITS {
   unsigned int RP0R0:1;
   unsigned int RP0R1:1;
   unsigned int RP0R2:1;
   unsigned int RP0R3:1;
   unsigned int RP0R4:1;
   unsigned int RP0R5:1;
   unsigned int :2;
   unsigned int RP1R8:1;
   unsigned int RP1R9:1;
   unsigned int RP1R10:1;
   unsigned int RP1R11:1;
   unsigned int RP1R12:1;
   unsigned int RP1R5:1;
} RPOR0bits;
#word RPOR0bits = 0x6C0
#word RPOR0 = 0x6C0

struct RPOR1BITS {
   unsigned int RP2R0:1;
   unsigned int RP2R1:1;
   unsigned int RP2R2:1;
   unsigned int RP2R3:1;
   unsigned int RP2R4:1;
   unsigned int RP2R5:1;
   unsigned int :2;
   unsigned int RP3R8:1;
   unsigned int RP3R9:1;
   unsigned int RP3R10:1;
   unsigned int RP3R11:1;
   unsigned int RP3R12:1;
   unsigned int RP3R5:1;
} RPOR1bits;
#word RPOR1bits = 0x6C2
#word RPOR1 = 0x6C2

struct RPOR2BITS {
   unsigned int RP4R0:1;
   unsigned int RP4R1:1;
   unsigned int RP4R2:1;
   unsigned int RP4R3:1;
   unsigned int RP4R4:1;
   unsigned int RP4R5:1;
   unsigned int :2;
   unsigned int RP5R8:1;
   unsigned int RP5R9:1;
   unsigned int RP5R10:1;
   unsigned int RP5R11:1;
   unsigned int RP5R12:1;
   unsigned int RP5R5:1;
} RPOR2bits;
#word RPOR2bits = 0x6C4
#word RPOR2 = 0x6C4

struct RPOR3BITS {
   unsigned int RP6R0:1;
   unsigned int RP6R1:1;
   unsigned int RP6R2:1;
   unsigned int RP6R3:1;
   unsigned int RP6R4:1;
   unsigned int RP6R5:1;
   unsigned int :2;
   unsigned int RP7R8:1;
   unsigned int RP7R9:1;
   unsigned int RP7R10:1;
   unsigned int RP7R11:1;
   unsigned int RP7R12:1;
   unsigned int RP7R5:1;
} RPOR3bits;
#word RPOR3bits = 0x6C6
#word RPOR3 = 0x6C6

struct RPOR4BITS {
   unsigned int RP8R0:1;
   unsigned int RP8R1:1;
   unsigned int RP8R2:1;
   unsigned int RP8R3:1;
   unsigned int RP8R4:1;
   unsigned int RP8R5:1;
   unsigned int :2;
   unsigned int RP9R8:1;
   unsigned int RP9R9:1;
   unsigned int RP9R10:1;
   unsigned int RP9R11:1;
   unsigned int RP9R12:1;
   unsigned int RP9R5:1;
} RPOR4bits;
#word RPOR4bits = 0x6C8
#word RPOR4 = 0x6C8

struct RPOR5BITS {
   unsigned int RP10R0:1;
   unsigned int RP10R1:1;
   unsigned int RP10R2:1;
   unsigned int RP10R3:1;
   unsigned int RP10R4:1;
   unsigned int RP10R5:1;
   unsigned int :2;
   unsigned int RP11R8:1;
   unsigned int RP11R9:1;
   unsigned int RP11R10:1;
   unsigned int RP11R11:1;
   unsigned int RP11R12:1;
   unsigned int RP11R5:1;
} RPOR5bits;
#word RPOR5bits = 0x6CA
#word RPOR5 = 0x6CA

struct RPOR6BITS {
   unsigned int RP12R0:1;
   unsigned int RP12R1:1;
   unsigned int RP12R2:1;
   unsigned int RP12R3:1;
   unsigned int RP12R4:1;
   unsigned int RP12R5:1;
   unsigned int :2;
   unsigned int RP13R8:1;
   unsigned int RP13R9:1;
   unsigned int RP13R10:1;
   unsigned int RP13R11:1;
   unsigned int RP13R12:1;
   unsigned int RP13R5:1;
} RPOR6bits;
#word RPOR6bits = 0x6CC
#word RPOR6 = 0x6CC

struct RPOR7BITS {
   unsigned int RP14R0:1;
   unsigned int RP14R1:1;
   unsigned int RP14R2:1;
   unsigned int RP14R3:1;
   unsigned int RP14R4:1;
   unsigned int RP14R5:1;
   unsigned int :2;
   unsigned int RP15R8:1;
   unsigned int RP15R9:1;
   unsigned int RP15R10:1;
   unsigned int RP15R11:1;
   unsigned int RP15R12:1;
   unsigned int RP15R5:1;
} RPOR7bits;
#word RPOR7bits = 0x6CE
#word RPOR7 = 0x6CE

struct RPOR8BITS {
   unsigned int RP16R0:1;
   unsigned int RP16R1:1;
   unsigned int RP16R2:1;
   unsigned int RP16R3:1;
   unsigned int RP16R4:1;
   unsigned int RP16R5:1;
   unsigned int :2;
   unsigned int RP17R8:1;
   unsigned int RP17R9:1;
   unsigned int RP17R10:1;
   unsigned int RP17R11:1;
   unsigned int RP17R12:1;
   unsigned int RP17R5:1;
} RPOR8bits;
#word RPOR8bits = 0x6D0
#word RPOR8 = 0x6D0

struct RPOR9BITS {
   unsigned int RP18R0:1;
   unsigned int RP18R1:1;
   unsigned int RP18R2:1;
   unsigned int RP18R3:1;
   unsigned int RP18R4:1;
   unsigned int RP18R5:1;
   unsigned int :2;
   unsigned int RP19R8:1;
   unsigned int RP19R9:1;
   unsigned int RP19R10:1;
   unsigned int RP19R11:1;
   unsigned int RP19R12:1;
   unsigned int RP19R5:1;
} RPOR9bits;
#word RPOR9bits = 0x6D2
#word RPOR9 = 0x6D2

struct RPOR10BITS {
   unsigned int RP20R0:1;
   unsigned int RP20R1:1;
   unsigned int RP20R2:1;
   unsigned int RP20R3:1;
   unsigned int RP20R4:1;
   unsigned int RP20R5:1;
   unsigned int :2;
   unsigned int RP21R8:1;
   unsigned int RP21R9:1;
   unsigned int RP21R10:1;
   unsigned int RP21R11:1;
   unsigned int RP21R12:1;
   unsigned int RP21R5:1;
} RPOR10bits;
#word RPOR10bits = 0x6D4
#word RPOR10 = 0x6D4

struct RPOR11BITS {
   unsigned int RP22R0:1;
   unsigned int RP22R1:1;
   unsigned int RP22R2:1;
   unsigned int RP22R3:1;
   unsigned int RP22R4:1;
   unsigned int RP22R5:1;
   unsigned int :2;
   unsigned int RP23R8:1;
   unsigned int RP23R9:1;
   unsigned int RP23R10:1;
   unsigned int RP23R11:1;
   unsigned int RP23R12:1;
   unsigned int RP23R5:1;
} RPOR11bits;
#word RPOR11bits = 0x6D6
#word RPOR11 = 0x6D6

struct RPOR12BITS {
   unsigned int RP24R0:1;
   unsigned int RP24R1:1;
   unsigned int RP24R2:1;
   unsigned int RP24R3:1;
   unsigned int RP24R4:1;
   unsigned int RP24R5:1;
   unsigned int :2;
   unsigned int RP25R8:1;
   unsigned int RP25R9:1;
   unsigned int RP25R10:1;
   unsigned int RP25R11:1;
   unsigned int RP25R12:1;
   unsigned int RP25R5:1;
} RPOR12bits;
#word RPOR12bits = 0x6D8
#word RPOR12 = 0x6D8

struct RPOR13BITS {
   unsigned int RP26R0:1;
   unsigned int RP26R1:1;
   unsigned int RP26R2:1;
   unsigned int RP26R3:1;
   unsigned int RP26R4:1;
   unsigned int RP26R5:1;
   unsigned int :2;
   unsigned int RP27R8:1;
   unsigned int RP27R9:1;
   unsigned int RP27R10:1;
   unsigned int RP27R11:1;
   unsigned int RP27R12:1;
   unsigned int RP27R5:1;
} RPOR13bits;
#word RPOR13bits = 0x6DA
#word RPOR13 = 0x6DA

struct RPOR14BITS {
   unsigned int RP28R0:1;
   unsigned int RP28R1:1;
   unsigned int RP28R2:1;
   unsigned int RP28R3:1;
   unsigned int RP28R4:1;
   unsigned int RP28R5:1;
   unsigned int :2;
   unsigned int RP29R8:1;
   unsigned int RP29R9:1;
   unsigned int RP29R10:1;
   unsigned int RP29R11:1;
   unsigned int RP29R12:1;
   unsigned int RP29R5:1;
} RPOR14bits;
#word RPOR14bits = 0x6DC
#word RPOR14 = 0x6DC

struct RPOR15BITS {
   unsigned int RP30R0:1;
   unsigned int RP30R1:1;
   unsigned int RP30R2:1;
   unsigned int RP30R3:1;
   unsigned int RP30R4:1;
   unsigned int RP30R5:1;
   unsigned int :2;
   unsigned int RP31R8:1;
   unsigned int RP31R9:1;
   unsigned int RP31R10:1;
   unsigned int RP31R11:1;
   unsigned int RP31R12:1;
   unsigned int RP31R5:1;
} RPOR15bits;
#word RPOR15bits = 0x6DE
#word RPOR15 = 0x6DE

struct ALTRPBITS {
   unsigned int SCK1CM:1;
} ALTRPbits;
#word ALTRPbits = 0x6E2
#word ALTRP = 0x6E2

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
   unsigned int IOPUWR:1;
   unsigned int TRAPR:1;
} RCONbits;
#word RCONbits = 0x740
#word RCON = 0x740

struct OSCCONBITS {
   unsigned int OSWEN:1;
   unsigned int SOSCEN:1;
   unsigned int POSCEN:1;
   unsigned int CF:1;
   unsigned int :1;
   unsigned int LOCK:1;
   unsigned int IOLOCK:1;
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
   unsigned int :6;
   unsigned int CPDIV6:1;
   unsigned int CPDIV7:1;
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

struct REFOCONBITS {
   unsigned int :8;
   unsigned int RODIV8:1;
   unsigned int RODIV9:1;
   unsigned int RODIV10:1;
   unsigned int RODIV11:1;
   unsigned int ROSEL:1;
   unsigned int ROSSLP:1;
   unsigned int :1;
   unsigned int ROEN:1;
} REFOCONbits;
#word REFOCONbits = 0x74E
#word REFOCON = 0x74E

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
   unsigned int ADC1MD:1;
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
   unsigned int OC1MD:1;
   unsigned int OC2MD:1;
   unsigned int OC3MD:1;
   unsigned int OC4MD:1;
   unsigned int OC5MD:1;
   unsigned int OC6MD:1;
   unsigned int OC7MD:1;
   unsigned int OC8MD:1;
   unsigned int IC1MD:1;
   unsigned int IC2MD:1;
   unsigned int IC3MD:1;
   unsigned int IC4MD:1;
   unsigned int IC5MD:1;
   unsigned int IC6MD:1;
   unsigned int IC7MD:1;
   unsigned int IC8MD:1;
} PMD2bits;
#word PMD2bits = 0x772
#word PMD2 = 0x772

struct PMD3BITS {
   unsigned int :1;
   unsigned int I2CMD:1;
   unsigned int I2C3MD:1;
   unsigned int U3MD:1;
   unsigned int :3;
   unsigned int CRCMD:1;
   unsigned int PMPMD:1;
   unsigned int RTCCMD:1;
   unsigned int CMPMD:1;
} PMD3bits;
#word PMD3bits = 0x774
#word PMD3 = 0x774

struct PMD4BITS {
   unsigned int :1;
   unsigned int LVDMD:1;
   unsigned int CTMUMD:1;
   unsigned int REFOMD:1;
   unsigned int :1;
   unsigned int U4MD:1;
   unsigned int UPWMMD:1;
} PMD4bits;
#word PMD4bits = 0x776
#word PMD4 = 0x776

struct PMD5BITS {
   unsigned int OC9MD:1;
   unsigned int :7;
   unsigned int IC9MD:1;
} PMD5bits;
#word PMD5bits = 0x778
#word PMD5 = 0x778

struct PMD6BITS {
   unsigned int SPI3MD:1;
} PMD6bits;
#word PMD6bits = 0x77A
#word PMD6 = 0x77A

