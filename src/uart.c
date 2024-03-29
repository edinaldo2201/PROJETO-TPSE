#include "uart.h"

/*
 * =====================================================================================
 *
 *       Filename:  uart.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/02/2017 10:39:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  José Adrian Nascimento Silva, jadriannassilva@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  putCh
 *  Description:  
 * =====================================================================================
 */
void putCh(char c){

	while(!(HWREG(UART0_LSR) & (1<<5)));

	HWREG(UART0_THR) = c;

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getCh
 *  Description:  
 * =====================================================================================
 */
char getCh(){

	while(!(HWREG(UART0_LSR) & (1<<0)));

	return(HWREG(UART0_RHR));

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  putString
 *  Description:  
 * =====================================================================================
 */
int putString(char *str, unsigned int length){

	for(int i = 0; i < length; i++){
    	putCh(str[i]);
	}
	return(length);

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getString
 *  Description:  
 * =====================================================================================
 */
int getString(char *buf, unsigned int length){

	for(int i = 0; i < length; i ++){
    	buf[i] = getCh();
   	}
	return(length);
	
}
