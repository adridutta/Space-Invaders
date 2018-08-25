#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "Timer0.h"
#include "ISR.h"
#include "Portinit.h"
#include "Timer1.h"
#include "print.h"
#include "Collision.h"
#include "DAC.h"
#include "Timer2.h"
#include "Spaceinvaders.h"


void Level2 (void);










void Level2 (void)
{
	uint8_t index = 0;
	
	while (1){
	
	while (index <20)
	{
		
		
		if (alien2[index].status == 1)                                                                             //see if alien is alive
		
		{
			ST7735_DrawBitmap(alien2[index].x, alien2[index].y, alien2[index].mappt[0], alien2[index].w, alien2[index].h); 
		}
		
		else
		{
			ST7735_DrawBitmap(alien2[index].x, alien2[index].y, alien2[index].mappt[1], alien2[index].w, alien2[index].h);
		}
		
		ST7735_DrawBitmap(ship.x, ship.y,ship.mappt[0],ship.w,ship.h);
		ST7735_DrawBitmap(ship2.x, ship2.y,ship2.mappt[0],ship2.w,ship2.h);
		
		if (bullet.status == 1)
		{
			ST7735_DrawBitmap(bullet.x, bullet.y, bullet.mappt[0], bullet.w,bullet.h);
		}
		else
		{
			ST7735_DrawBitmap(bullet.x, bullet.y, bullet.mappt[1], bullet.w,bullet.h);
		}
		if (bullet2.status == 1)
		{
			ST7735_DrawBitmap(bullet2.x, bullet2.y, bullet.mappt[0], bullet2.w,bullet2.h);
		}
		else
		{
			ST7735_DrawBitmap(bullet2.x, bullet2.y, bullet2.mappt[1], bullet2.w,bullet.h);
		}
		
		
		
		
		ST7735_SetCursor(7,0);
		LCD_OutDec(score);
		if (score == 360)
		{

			
			ST7735_FillScreen(0x0000); 
			ST7735_SetCursor (6,6);
			ST7735_OutString("You Won!");
			winflag = 1;
			TIMER2_TAILR_R = 0x08ff;
			TIMER2_CTL_R = 0x000001;

			while (1) {};
		}
		
		
		index++;
	
	}
		index = 0;
}
}	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	


