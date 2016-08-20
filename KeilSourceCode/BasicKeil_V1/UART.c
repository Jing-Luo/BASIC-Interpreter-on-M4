// UART.c
// By VangleLiu and ArlenLuo
#include <stdint.h>
#include "UART.h"
#include <stdio.h>

#define GPIO_PORTA_AFSEL_R      (*((volatile uint32_t *)0x40058420))
#define GPIO_PORTA_DEN_R        (*((volatile uint32_t *)0x4005851C))
#define GPIO_PORTA_AMSEL_R      (*((volatile uint32_t *)0x40058528))
#define GPIO_PORTA_PCTL_R       (*((volatile uint32_t *)0x4005852C))
#define UART0_DR_R              (*((volatile uint32_t *)0x4000C000))
#define UART0_FR_R              (*((volatile uint32_t *)0x4000C018))
#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART0_IBRD_R            (*((volatile uint32_t *)0x4000C024))
#define UART0_FBRD_R            (*((volatile uint32_t *)0x4000C028))
#define UART0_LCRH_R            (*((volatile uint32_t *)0x4000C02C))
#define UART_LCRH_WLEN_8        0x00000060  // 8 bit word length
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART0_CTL_R             (*((volatile uint32_t *)0x4000C030))
#define UART_CTL_HSE            0x00000020  // High-Speed Enable
#define UART_CTL_UARTEN         0x00000001  // UART Enable
#define UART0_CC_R              (*((volatile uint32_t *)0x4000CFC8))
#define UART_CC_CS_M            0x0000000F  // UART Baud Clock Source
#define UART_CC_CS_SYSCLK       0x00000000  // System clock (based on clock
                                            // source and divisor factor)
#define UART_CC_CS_PIOSC        0x00000005  // PIOSC
#define SYSCTL_ALTCLKCFG_R      (*((volatile uint32_t *)0x400FE138))
#define SYSCTL_ALTCLKCFG_ALTCLK_M                                             \
                                0x0000000F  // Alternate Clock Source
#define SYSCTL_ALTCLKCFG_ALTCLK_PIOSC                                         \
                                0x00000000  // PIOSC
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCGPIO_R0      0x00000001  // GPIO Port A Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R       (*((volatile uint32_t *)0x400FE618))
#define SYSCTL_RCGCUART_R0      0x00000001  // UART Module 0 Run Mode Clock
                                            // Gating Control
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))
#define SYSCTL_PRGPIO_R0        0x00000001  // GPIO Port A Peripheral Ready
#define SYSCTL_PRUART_R         (*((volatile uint32_t *)0x400FEA18))
#define SYSCTL_PRUART_R0        0x00000001  // UART Module 0 Peripheral Ready

//------------UART_Init------------
// Initialize the UART for 115,200 baud rate (clock from 16 MHz PIOSC),
// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
// Input: none
// Output: none
void UARTInit(void){
                                        // activate clock for UART0
  SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
                                        // activate clock for Port A
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
                                        // allow time for clock to stabilize
  while((SYSCTL_PRUART_R&SYSCTL_PRUART_R0) == 0){};
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART0_IBRD_R = 8;                     // IBRD = int(16,000,000 / (16 * 115,200)) = int(8.681)
  UART0_FBRD_R = 44;                    // FBRD = round(0.6806 * 64) = 44
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
                                        // UART gets its clock from the alternate clock source as defined by SYSCTL_ALTCLKCFG_R
  UART0_CC_R = (UART0_CC_R&~UART_CC_CS_M)+UART_CC_CS_PIOSC;
                                        // the alternate clock source is the PIOSC (default)
  SYSCTL_ALTCLKCFG_R = (SYSCTL_ALTCLKCFG_R&~SYSCTL_ALTCLKCFG_ALTCLK_M)+SYSCTL_ALTCLKCFG_ALTCLK_PIOSC;
  UART0_CTL_R &= ~UART_CTL_HSE;         // high-speed disable; divide clock by 16 rather than 8 (default)
  UART0_CTL_R |= UART_CTL_UARTEN;       // enable UART
                                        // allow time for clock to stabilize
  while((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R0) == 0){};
  GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA
}



//------------UART_InChar------------
// Wait for new serial port input
// Input: none
// Output: ASCII code for key typed
char UART_InChar(void){
  while((UART0_FR_R&UART_FR_RXFE) != 0);
  return((char)(UART0_DR_R&0xFF));
}

void UART_InString(char*buff){
	int i = 0;
	char tmpchar;
	while (1)
	{
		tmpchar = UART_InChar();
		if (tmpchar == '\n')
		{
			break;
		}
		UART_OutChar(tmpchar);
		buff[i++] = tmpchar;
	}
	int j = 0;
	for (j = 0; j < i; j++)
	{
		if (buff[j] == '\r')
		{
			buff[j] = '\0';
			printf("\n");
		}
	}
}

//------------UART_OutChar------------
// Output 8-bit to serial port
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UART_OutChar(char data){
  while((UART0_FR_R&UART_FR_TXFF) != 0);
  UART0_DR_R = data;
}

// Print a character to UART.
int fputc(int ch, FILE *f){
  if((ch == 10) || (ch == 13) || (ch == 27)){
    UART_OutChar(13);
    UART_OutChar(10);
    return 1;
  }
  UART_OutChar(ch);
  return 1;
}

// Get a character from UART.
int fgetc(FILE *f){
  return UART_InChar();
}

// Function called when file error occurs.
int ferror(FILE *f){
  /* Your implementation of ferror */
  return EOF;
}

//Use UART to send a string
void UART_OutString(const char *cMessage)
{
	while(*cMessage!='\0')
	{
		UART_OutChar(*(cMessage++));
	}
}

void Delay(void)
{
	int i;
	for(i = 0; i < 200000; i++);
}
