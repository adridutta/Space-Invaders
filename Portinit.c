#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sprites.h"
#include "SpaceInvaders.h"
#include "Portinit.h"


void PortF_Init(void);
void PortE_Init (void);

///////PORTF/////////////////

uint32_t delay;
uint8_t shootflag = 0;
void PortF_Init(void){
// Intialize PortF for hearbeat
	
	SYSCTL_RCGCGPIO_R |= 0x20;
	
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	
	GPIO_PORTF_DIR_R |= 0x06;
	GPIO_PORTF_AFSEL_R &= ~0x06; 
	GPIO_PORTF_DEN_R |= 0x06; 
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
	GPIO_PORTF_AMSEL_R = 0; 

}





//////////PORTE/////////////

void PortE_Init (void)
{
	SYSCTL_RCGCGPIO_R |= 0x10;
	
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	delay++;
	
	
	GPIO_PORTE_DIR_R &= ~0x03;
	GPIO_PORTE_AFSEL_R &= ~0x03;
	GPIO_PORTE_DEN_R |= 0x03;
	GPIO_PORTE_PCTL_R &= ~0x000000FF;
	GPIO_PORTE_AMSEL_R &= ~0x03;
	GPIO_PORTE_IS_R &= ~0x03;
	GPIO_PORTE_IBE_R &= ~0x03;
	GPIO_PORTE_IEV_R |= 0x03;
	GPIO_PORTE_ICR_R = 0x03;
	GPIO_PORTE_IM_R |= 0x03;
	NVIC_PRI1_R = (NVIC_PRI1_R & 0xFFFFFF00) | 0x00000040;
	NVIC_EN0_R |= 0x00000010;
}



void GPIOPortE_Handler(void)
{
	uint32_t data;
	
	
if ((GPIO_PORTE_DATA_R & 0x01) != 0)
{	
	if (bullet.status == 0)
		{
			bullet.status = 1;
			data = ADC_In();
			bullet.x = ((110 * data) /4095)+5;
			bullet.y = 151;
			shootflag = 1;
			TIMER2_TAILR_R = 0x0FFF;
			TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER2A
			
		}
}	
	
	
if ((GPIO_PORTE_DATA_R & 0x02) != 0)
{
	if (bullet2.status == 0)
	{
			bullet2.status = 1;
			data = ADC2_In();
			bullet2.x = 16;                                    //((110 * data) /4095)+5;
			bullet2.y = ((110 * data) /4095)+20;
			TIMER2_TAILR_R = 0xFFF;
			TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER2A
			shootflag = 1;
	}

}
	GPIO_PORTE_ICR_R = 0x03;
	
}
