#ifndef __HARDWAREPROFILE_H__
#define __HARDWAREPROFILE_H__

#define ENC_CS_IO        LATCbits.LATC1
#define ENC_CS_TRIS      TRISCbits.TRISC1
#define ENC_SCK_TRIS     TRISCbits.TRISC3
#define ENC_SDI_TRIS     TRISCbits.TRISC4
#define ENC_SDO_TRIS     TRISCbits.TRISC5
#define ENC_RST_IO       LATCbits.LATC0
#define ENC_RST_TRIS     TRISCbits.TRISC0
#define ENC_SSPBUF       SSPBUF
#define ENC_SPISTAT      SSPSTAT
#define ENC_SPISTATbits  SSPSTATbits
#define ENC_SPICON1      SSPCON1
#define ENC_SPICON1bits  SSPCON1bits
#define ENC_SPICON2      SSPCON2
#define ENC_SPICON2bits  SSPCON2bits
#define ENC_SPI_IF       PIR1bits.SSPIF


#endif
