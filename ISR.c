#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "Timer0.h"
#include "SpaceInvaders.h"
#include "Sprites.h"
#include "Timer2.h"




///////////SYSTICK//////////////////////////////////////

void Systick_Init(void){
 
 NVIC_ST_CTRL_R = 0;              //disable systick 
 NVIC_ST_RELOAD_R = 0;        //reload value
 NVIC_ST_CURRENT_R = 0;             // clear
 NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF)| 0x20000000;        //set priority
 NVIC_ST_CTRL_R = 0x0007;          // enable clock, interrupt and enable bit
 NVIC_ST_RELOAD_R = 0x13333;                 //0x13333
}




void SysTick_Handler (void)
	{
		uint32_t data;                       // ship movement
		uint32_t data2;
		
		
		data = ADC_In();
		ship.x = ((110 * data)/4095) -8;
		
		data2 = ADC2_In();
		ship2.y = ((110 * data2)/4095)+20;
	
	
//		if ( (GPIO_PORTE_DATA_R != 0x00) && (bullet.status == 0))
//		{
//			bullet.status = 1;
//			data = ADC_In();
//			bullet.x = ((110 * data) /4095)+5;
//			bullet.y = 151;
//			TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER2A
//		}
		
	}
	
