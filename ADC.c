// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Last Modified: 4/10/2016
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "tm4c123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
void ADC_Init(void){
 // --UUU-- Complete this(copy from Lab8)
	uint32_t delay;
	SYSCTL_RCGCGPIO_R |= 0x08;      // init portd
	SYSCTL_RCGCGPIO_R |= 0x10;
	
	delay =  SYSCTL_RCGCGPIO_R;        //NOP
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	
	
	
	GPIO_PORTD_DIR_R &= 0xFFFFFFFB;     //set direction register
	GPIO_PORTE_DIR_R &= ~0x10;
	GPIO_PORTD_AFSEL_R |= 0x04;
	GPIO_PORTE_AFSEL_R |= 0x10;
	GPIO_PORTD_DEN_R &= 0xFFFFFFFB;
	GPIO_PORTE_DEN_R &= ~0x10;
	GPIO_PORTD_AMSEL_R |= 0x04;
	GPIO_PORTE_AMSEL_R |= 0x10;
//	SYSCTL_RCGC0_R |= 0x00010000;
//	
//	delay = SYSCTL_RCGCGPIO_R;
	
	
  SYSCTL_RCGCADC_R |= 0x01;
	SYSCTL_RCGCADC_R |= 0x02;
	
	
	delay++;
	delay++;
	delay++;
	delay++;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	delay =  SYSCTL_RCGCGPIO_R;
	
	
	ADC0_PC_R = 0x01;
	ADC0_SSPRI_R = 0x0123;
	ADC0_ACTSS_R &= ~0x0008;
	ADC0_EMUX_R &= ~0xF000;
  ADC0_SSMUX3_R = (ADC0_SSMUX3_R & 0xFFFFFFF0) +5;
	//ADC0_SSMUX0_R = (ADC0_SSMUX0_R & 0xFFFFFFF0) +9;
	ADC0_SSCTL3_R = 0x0006;
	//ADC0_SSCTL0_R = 0x0006;
	ADC0_IM_R &= ~0x0008;
	ADC0_ACTSS_R |= 0x0008;
	
	ADC1_PC_R = 0x01;
	ADC1_SSPRI_R = 0x0123;
	ADC1_ACTSS_R &= ~0x0008;
	ADC1_EMUX_R &= ~0xF000;
	ADC1_SSMUX3_R = (ADC1_SSMUX3_R  & 0xFFFFFFF0) + 9;
	ADC1_SSCTL3_R = 0x0006;
	ADC1_IM_R &= ~0x0008;
	ADC1_ACTSS_R |= 0x0008;
	
	
	
	
}

//------------ADC_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
uint32_t ADC_In(void){  
  
	uint32_t Data;
	
	ADC0_PSSI_R = 0x0008;
	while ((ADC0_RIS_R & 0x08)== 0) {};
		Data = ADC0_SSFIFO3_R&0xFFF;
	ADC0_ISC_R = 0x0008;
	return Data;
	
	
}


uint32_t ADC2_In (void)
{
	uint32_t result = 0;
	
	ADC1_PSSI_R = 0x0008;
	while ((ADC1_RIS_R&0x08) == 0) {};
	result = ADC1_SSFIFO3_R&0xFFF;
	ADC1_ISC_R = 0x0008;
	return (result);
	
}









