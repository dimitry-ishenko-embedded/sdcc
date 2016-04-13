/*
 * This definitions of the PIC12LF1612 MCU.
 *
 * This file is part of the GNU PIC library for SDCC, originally
 * created by Molnar Karoly <molnarkaroly@users.sf.net> 2016.
 *
 * This file is generated automatically by the cinc2h.pl, 2016-04-13 17:23:05 UTC.
 *
 * SDCC is licensed under the GNU Public license (GPL) v2. Note that
 * this license covers the code to the compiler and other executables,
 * but explicitly does not cover any code or objects generated by sdcc.
 *
 * For pic device libraries and header files which are derived from
 * Microchip header (.inc) and linker script (.lkr) files Microchip
 * requires that "The header files should state that they are only to be
 * used with authentic Microchip devices" which makes them incompatible
 * with the GPL. Pic device libraries and header files are located at
 * non-free/lib and non-free/include directories respectively.
 * Sdcc should be run with the --use-non-free command line option in
 * order to include non-free header files and libraries.
 *
 * See http://sdcc.sourceforge.net/ for the latest information on sdcc.
 */

#include <pic12lf1612.h>

//==============================================================================

__at(0x0000) __sfr INDF0;

__at(0x0001) __sfr INDF1;

__at(0x0002) __sfr PCL;

__at(0x0003) __sfr STATUS;
__at(0x0003) volatile __STATUSbits_t STATUSbits;

__at(0x0004) __sfr FSR0;

__at(0x0004) __sfr FSR0L;

__at(0x0005) __sfr FSR0H;

__at(0x0006) __sfr FSR1;

__at(0x0006) __sfr FSR1L;

__at(0x0007) __sfr FSR1H;

__at(0x0008) __sfr BSR;
__at(0x0008) volatile __BSRbits_t BSRbits;

__at(0x0009) __sfr WREG;

__at(0x000A) __sfr PCLATH;

__at(0x000B) __sfr INTCON;
__at(0x000B) volatile __INTCONbits_t INTCONbits;

__at(0x000C) __sfr PORTA;
__at(0x000C) volatile __PORTAbits_t PORTAbits;

__at(0x0011) __sfr PIR1;
__at(0x0011) volatile __PIR1bits_t PIR1bits;

__at(0x0012) __sfr PIR2;
__at(0x0012) volatile __PIR2bits_t PIR2bits;

__at(0x0013) __sfr PIR3;
__at(0x0013) volatile __PIR3bits_t PIR3bits;

__at(0x0014) __sfr PIR4;
__at(0x0014) volatile __PIR4bits_t PIR4bits;

__at(0x0015) __sfr TMR0;

__at(0x0016) __sfr TMR1;

__at(0x0016) __sfr TMR1L;

__at(0x0017) __sfr TMR1H;

__at(0x0018) __sfr T1CON;
__at(0x0018) volatile __T1CONbits_t T1CONbits;

__at(0x0019) __sfr T1GCON;
__at(0x0019) volatile __T1GCONbits_t T1GCONbits;

__at(0x001A) __sfr T2TMR;

__at(0x001A) __sfr TMR2;

__at(0x001B) __sfr PR2;

__at(0x001B) __sfr T2PR;

__at(0x001C) __sfr T2CON;
__at(0x001C) volatile __T2CONbits_t T2CONbits;

__at(0x001D) __sfr T2HLT;
__at(0x001D) volatile __T2HLTbits_t T2HLTbits;

__at(0x001E) __sfr T2CLKCON;
__at(0x001E) volatile __T2CLKCONbits_t T2CLKCONbits;

__at(0x001F) __sfr T2RST;
__at(0x001F) volatile __T2RSTbits_t T2RSTbits;

__at(0x008C) __sfr TRISA;
__at(0x008C) volatile __TRISAbits_t TRISAbits;

__at(0x0091) __sfr PIE1;
__at(0x0091) volatile __PIE1bits_t PIE1bits;

__at(0x0092) __sfr PIE2;
__at(0x0092) volatile __PIE2bits_t PIE2bits;

__at(0x0093) __sfr PIE3;
__at(0x0093) volatile __PIE3bits_t PIE3bits;

__at(0x0094) __sfr PIE4;
__at(0x0094) volatile __PIE4bits_t PIE4bits;

__at(0x0095) __sfr OPTION_REG;
__at(0x0095) volatile __OPTION_REGbits_t OPTION_REGbits;

__at(0x0096) __sfr PCON;
__at(0x0096) volatile __PCONbits_t PCONbits;

__at(0x0098) __sfr OSCTUNE;
__at(0x0098) volatile __OSCTUNEbits_t OSCTUNEbits;

__at(0x0099) __sfr OSCCON;
__at(0x0099) volatile __OSCCONbits_t OSCCONbits;

__at(0x009A) __sfr OSCSTAT;
__at(0x009A) volatile __OSCSTATbits_t OSCSTATbits;

__at(0x009B) __sfr ADRES;

__at(0x009B) __sfr ADRESL;

__at(0x009C) __sfr ADRESH;

__at(0x009D) __sfr ADCON0;
__at(0x009D) volatile __ADCON0bits_t ADCON0bits;

__at(0x009E) __sfr ADCON1;
__at(0x009E) volatile __ADCON1bits_t ADCON1bits;

__at(0x009F) __sfr ADCON2;
__at(0x009F) volatile __ADCON2bits_t ADCON2bits;

__at(0x010C) __sfr LATA;
__at(0x010C) volatile __LATAbits_t LATAbits;

__at(0x0111) __sfr CM1CON0;
__at(0x0111) volatile __CM1CON0bits_t CM1CON0bits;

__at(0x0112) __sfr CM1CON1;
__at(0x0112) volatile __CM1CON1bits_t CM1CON1bits;

__at(0x0115) __sfr CMOUT;
__at(0x0115) volatile __CMOUTbits_t CMOUTbits;

__at(0x0116) __sfr BORCON;
__at(0x0116) volatile __BORCONbits_t BORCONbits;

__at(0x0117) __sfr FVRCON;
__at(0x0117) volatile __FVRCONbits_t FVRCONbits;

__at(0x0118) __sfr DAC1CON0;
__at(0x0118) volatile __DAC1CON0bits_t DAC1CON0bits;

__at(0x0119) __sfr DAC1CON1;
__at(0x0119) volatile __DAC1CON1bits_t DAC1CON1bits;

__at(0x011C) __sfr ZCD1CON;
__at(0x011C) volatile __ZCD1CONbits_t ZCD1CONbits;

__at(0x011D) __sfr APFCON;
__at(0x011D) volatile __APFCONbits_t APFCONbits;

__at(0x018C) __sfr ANSELA;
__at(0x018C) volatile __ANSELAbits_t ANSELAbits;

__at(0x0191) __sfr PMADR;

__at(0x0191) __sfr PMADRL;

__at(0x0192) __sfr PMADRH;

__at(0x0193) __sfr PMDAT;

__at(0x0193) __sfr PMDATL;

__at(0x0194) __sfr PMDATH;

__at(0x0195) __sfr PMCON1;
__at(0x0195) volatile __PMCON1bits_t PMCON1bits;

__at(0x0196) __sfr PMCON2;

__at(0x020C) __sfr WPUA;
__at(0x020C) volatile __WPUAbits_t WPUAbits;

__at(0x028C) __sfr ODCONA;
__at(0x028C) volatile __ODCONAbits_t ODCONAbits;

__at(0x0291) __sfr CCPR1;

__at(0x0291) __sfr CCPR1L;

__at(0x0292) __sfr CCPR1H;

__at(0x0293) __sfr CCP1CON;
__at(0x0293) volatile __CCP1CONbits_t CCP1CONbits;

__at(0x0294) __sfr CCP1CAP;
__at(0x0294) volatile __CCP1CAPbits_t CCP1CAPbits;

__at(0x0298) __sfr CCPR2;

__at(0x0298) __sfr CCPR2L;

__at(0x0299) __sfr CCPR2H;

__at(0x029A) __sfr CCP2CON;
__at(0x029A) volatile __CCP2CONbits_t CCP2CONbits;

__at(0x029B) __sfr CCP2CAP;
__at(0x029B) volatile __CCP2CAPbits_t CCP2CAPbits;

__at(0x029E) __sfr CCPTMRS;
__at(0x029E) volatile __CCPTMRSbits_t CCPTMRSbits;

__at(0x030C) __sfr SLRCONA;
__at(0x030C) volatile __SLRCONAbits_t SLRCONAbits;

__at(0x038C) __sfr INLVLA;
__at(0x038C) volatile __INLVLAbits_t INLVLAbits;

__at(0x0391) __sfr IOCAP;

__at(0x0392) __sfr IOCAN;

__at(0x0393) __sfr IOCAF;

__at(0x0413) __sfr T4TMR;

__at(0x0413) __sfr TMR4;

__at(0x0414) __sfr PR4;

__at(0x0414) __sfr T4PR;

__at(0x0415) __sfr T4CON;
__at(0x0415) volatile __T4CONbits_t T4CONbits;

__at(0x0416) __sfr T4HLT;
__at(0x0416) volatile __T4HLTbits_t T4HLTbits;

__at(0x0417) __sfr T4CLKCON;
__at(0x0417) volatile __T4CLKCONbits_t T4CLKCONbits;

__at(0x0418) __sfr T4RST;
__at(0x0418) volatile __T4RSTbits_t T4RSTbits;

__at(0x041A) __sfr T6TMR;

__at(0x041A) __sfr TMR6;

__at(0x041B) __sfr PR6;

__at(0x041B) __sfr T6PR;

__at(0x041C) __sfr T6CON;
__at(0x041C) volatile __T6CONbits_t T6CONbits;

__at(0x041D) __sfr T6HLT;
__at(0x041D) volatile __T6HLTbits_t T6HLTbits;

__at(0x041E) __sfr T6CLKCON;
__at(0x041E) volatile __T6CLKCONbits_t T6CLKCONbits;

__at(0x041F) __sfr T6RST;
__at(0x041F) volatile __T6RSTbits_t T6RSTbits;

__at(0x0691) __sfr CWG1DBR;
__at(0x0691) volatile __CWG1DBRbits_t CWG1DBRbits;

__at(0x0692) __sfr CWG1DBF;
__at(0x0692) volatile __CWG1DBFbits_t CWG1DBFbits;

__at(0x0693) __sfr CWG1AS0;
__at(0x0693) volatile __CWG1AS0bits_t CWG1AS0bits;

__at(0x0694) __sfr CWG1AS1;
__at(0x0694) volatile __CWG1AS1bits_t CWG1AS1bits;

__at(0x0695) __sfr CWG1OCON0;
__at(0x0695) volatile __CWG1OCON0bits_t CWG1OCON0bits;

__at(0x0696) __sfr CWG1CON0;
__at(0x0696) volatile __CWG1CON0bits_t CWG1CON0bits;

__at(0x0697) __sfr CWG1CON1;
__at(0x0697) volatile __CWG1CON1bits_t CWG1CON1bits;

__at(0x0698) __sfr CWG1OCON1;
__at(0x0698) volatile __CWG1OCON1bits_t CWG1OCON1bits;

__at(0x0699) __sfr CWG1CLKCON;
__at(0x0699) volatile __CWG1CLKCONbits_t CWG1CLKCONbits;

__at(0x069A) __sfr CWG1ISM;
__at(0x069A) volatile __CWG1ISMbits_t CWG1ISMbits;

__at(0x0711) __sfr WDTCON0;
__at(0x0711) volatile __WDTCON0bits_t WDTCON0bits;

__at(0x0712) __sfr WDTCON1;
__at(0x0712) volatile __WDTCON1bits_t WDTCON1bits;

__at(0x0713) __sfr WDTPSL;
__at(0x0713) volatile __WDTPSLbits_t WDTPSLbits;

__at(0x0714) __sfr WDTPSH;
__at(0x0714) volatile __WDTPSHbits_t WDTPSHbits;

__at(0x0715) __sfr WDTTMR;
__at(0x0715) volatile __WDTTMRbits_t WDTTMRbits;

__at(0x0718) __sfr SCANLADR;

__at(0x0718) __sfr SCANLADRL;
__at(0x0718) volatile __SCANLADRLbits_t SCANLADRLbits;

__at(0x0719) __sfr SCANLADRH;
__at(0x0719) volatile __SCANLADRHbits_t SCANLADRHbits;

__at(0x071A) __sfr SCANHADR;

__at(0x071A) __sfr SCANHADRL;
__at(0x071A) volatile __SCANHADRLbits_t SCANHADRLbits;

__at(0x071B) __sfr SCANHADRH;
__at(0x071B) volatile __SCANHADRHbits_t SCANHADRHbits;

__at(0x071C) __sfr SCANCON0;
__at(0x071C) volatile __SCANCON0bits_t SCANCON0bits;

__at(0x071D) __sfr SCANTRIG;
__at(0x071D) volatile __SCANTRIGbits_t SCANTRIGbits;

__at(0x0791) __sfr CRCDAT;

__at(0x0791) __sfr CRCDATL;
__at(0x0791) volatile __CRCDATLbits_t CRCDATLbits;

__at(0x0792) __sfr CRCDATH;
__at(0x0792) volatile __CRCDATHbits_t CRCDATHbits;

__at(0x0793) __sfr CRCACC;

__at(0x0793) __sfr CRCACCL;
__at(0x0793) volatile __CRCACCLbits_t CRCACCLbits;

__at(0x0794) __sfr CRCACCH;
__at(0x0794) volatile __CRCACCHbits_t CRCACCHbits;

__at(0x0795) __sfr CRCSHIFT;

__at(0x0795) __sfr CRCSHIFTL;
__at(0x0795) volatile __CRCSHIFTLbits_t CRCSHIFTLbits;

__at(0x0796) __sfr CRCSHIFTH;
__at(0x0796) volatile __CRCSHIFTHbits_t CRCSHIFTHbits;

__at(0x0797) __sfr CRCXOR;

__at(0x0797) __sfr CRCXORL;
__at(0x0797) volatile __CRCXORLbits_t CRCXORLbits;

__at(0x0798) __sfr CRCXORH;
__at(0x0798) volatile __CRCXORHbits_t CRCXORHbits;

__at(0x0799) __sfr CRCCON0;
__at(0x0799) volatile __CRCCON0bits_t CRCCON0bits;

__at(0x079A) __sfr CRCCON1;
__at(0x079A) volatile __CRCCON1bits_t CRCCON1bits;

__at(0x0D8C) __sfr SMT1TMR;

__at(0x0D8C) __sfr SMT1TMRL;
__at(0x0D8C) volatile __SMT1TMRLbits_t SMT1TMRLbits;

__at(0x0D8D) __sfr SMT1TMRH;
__at(0x0D8D) volatile __SMT1TMRHbits_t SMT1TMRHbits;

__at(0x0D8E) __sfr SMT1TMRU;
__at(0x0D8E) volatile __SMT1TMRUbits_t SMT1TMRUbits;

__at(0x0D8F) __sfr SMT1CPR;

__at(0x0D8F) __sfr SMT1CPRL;
__at(0x0D8F) volatile __SMT1CPRLbits_t SMT1CPRLbits;

__at(0x0D90) __sfr SMT1CPRH;
__at(0x0D90) volatile __SMT1CPRHbits_t SMT1CPRHbits;

__at(0x0D91) __sfr SMT1CPRU;
__at(0x0D91) volatile __SMT1CPRUbits_t SMT1CPRUbits;

__at(0x0D92) __sfr SMT1CPW;

__at(0x0D92) __sfr SMT1CPWL;
__at(0x0D92) volatile __SMT1CPWLbits_t SMT1CPWLbits;

__at(0x0D93) __sfr SMT1CPWH;
__at(0x0D93) volatile __SMT1CPWHbits_t SMT1CPWHbits;

__at(0x0D94) __sfr SMT1CPWU;
__at(0x0D94) volatile __SMT1CPWUbits_t SMT1CPWUbits;

__at(0x0D95) __sfr SMT1PR;

__at(0x0D95) __sfr SMT1PRL;
__at(0x0D95) volatile __SMT1PRLbits_t SMT1PRLbits;

__at(0x0D96) __sfr SMT1PRH;
__at(0x0D96) volatile __SMT1PRHbits_t SMT1PRHbits;

__at(0x0D97) __sfr SMT1PRU;
__at(0x0D97) volatile __SMT1PRUbits_t SMT1PRUbits;

__at(0x0D98) __sfr SMT1CON0;
__at(0x0D98) volatile __SMT1CON0bits_t SMT1CON0bits;

__at(0x0D99) __sfr SMT1CON1;
__at(0x0D99) volatile __SMT1CON1bits_t SMT1CON1bits;

__at(0x0D9A) __sfr SMT1STAT;
__at(0x0D9A) volatile __SMT1STATbits_t SMT1STATbits;

__at(0x0D9B) __sfr SMT1CLK;
__at(0x0D9B) volatile __SMT1CLKbits_t SMT1CLKbits;

__at(0x0D9C) __sfr SMT1SIG;
__at(0x0D9C) volatile __SMT1SIGbits_t SMT1SIGbits;

__at(0x0D9D) __sfr SMT1WIN;
__at(0x0D9D) volatile __SMT1WINbits_t SMT1WINbits;

__at(0x0D9E) __sfr SMT2TMR;

__at(0x0D9E) __sfr SMT2TMRL;
__at(0x0D9E) volatile __SMT2TMRLbits_t SMT2TMRLbits;

__at(0x0D9F) __sfr SMT2TMRH;
__at(0x0D9F) volatile __SMT2TMRHbits_t SMT2TMRHbits;

__at(0x0DA0) __sfr SMT2TMRU;
__at(0x0DA0) volatile __SMT2TMRUbits_t SMT2TMRUbits;

__at(0x0DA1) __sfr SMT2CPR;

__at(0x0DA1) __sfr SMT2CPRL;
__at(0x0DA1) volatile __SMT2CPRLbits_t SMT2CPRLbits;

__at(0x0DA2) __sfr SMT2CPRH;
__at(0x0DA2) volatile __SMT2CPRHbits_t SMT2CPRHbits;

__at(0x0DA3) __sfr SMT2CPRU;
__at(0x0DA3) volatile __SMT2CPRUbits_t SMT2CPRUbits;

__at(0x0DA4) __sfr SMT2CPW;

__at(0x0DA4) __sfr SMT2CPWL;
__at(0x0DA4) volatile __SMT2CPWLbits_t SMT2CPWLbits;

__at(0x0DA5) __sfr SMT2CPWH;
__at(0x0DA5) volatile __SMT2CPWHbits_t SMT2CPWHbits;

__at(0x0DA6) __sfr SMT2CPWU;
__at(0x0DA6) volatile __SMT2CPWUbits_t SMT2CPWUbits;

__at(0x0DA7) __sfr SMT2PR;

__at(0x0DA7) __sfr SMT2PRL;
__at(0x0DA7) volatile __SMT2PRLbits_t SMT2PRLbits;

__at(0x0DA8) __sfr SMT2PRH;
__at(0x0DA8) volatile __SMT2PRHbits_t SMT2PRHbits;

__at(0x0DA9) __sfr SMT2PRU;
__at(0x0DA9) volatile __SMT2PRUbits_t SMT2PRUbits;

__at(0x0DAA) __sfr SMT2CON0;
__at(0x0DAA) volatile __SMT2CON0bits_t SMT2CON0bits;

__at(0x0DAB) __sfr SMT2CON1;
__at(0x0DAB) volatile __SMT2CON1bits_t SMT2CON1bits;

__at(0x0DAC) __sfr SMT2STAT;
__at(0x0DAC) volatile __SMT2STATbits_t SMT2STATbits;

__at(0x0DAD) __sfr SMT2CLK;
__at(0x0DAD) volatile __SMT2CLKbits_t SMT2CLKbits;

__at(0x0DAE) __sfr SMT2SIG;
__at(0x0DAE) volatile __SMT2SIGbits_t SMT2SIGbits;

__at(0x0DAF) __sfr SMT2WIN;
__at(0x0DAF) volatile __SMT2WINbits_t SMT2WINbits;

__at(0x0FE4) __sfr STATUS_SHAD;
__at(0x0FE4) volatile __STATUS_SHADbits_t STATUS_SHADbits;

__at(0x0FE5) __sfr WREG_SHAD;

__at(0x0FE6) __sfr BSR_SHAD;

__at(0x0FE7) __sfr PCLATH_SHAD;

__at(0x0FE8) __sfr FSR0L_SHAD;

__at(0x0FE9) __sfr FSR0H_SHAD;

__at(0x0FEA) __sfr FSR1L_SHAD;

__at(0x0FEB) __sfr FSR1H_SHAD;

__at(0x0FED) __sfr STKPTR;

__at(0x0FEE) __sfr TOSL;

__at(0x0FEF) __sfr TOSH;
