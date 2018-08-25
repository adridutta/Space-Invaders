#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "SpaceInvaders.h"

int16_t Convert(uint32_t data);
void Player1 (void);
void Aliens (void);
void Missile (void);
int16_t ConvertY (void);

uint8_t oldflag = 0;
uint32_t missilex = 0;
int16_t counter = 5;
int16_t convertedval = 0;







int16_t Convert(uint32_t data)
	{	
	return ((110 * data)/4095);

	}
	
	
	
	
	
void Player1 (void)
	{
		ST7735_DrawBitmap(Convert(playerx), 159, PlayerShip0, 18,8);
		flag = 0;
		alienflag ^= 0x01;
	}
	
	
void Aliens (void)
{
	if (alienflag == 0)
		{
		ST7735_DrawBitmap(0, 9, SmallEnemy10pointA, 16,10);
		ST7735_DrawBitmap(20,9, SmallEnemy30pointA, 16,10);
		ST7735_DrawBitmap(40, 9, SmallEnemy30pointA, 16,10);
		ST7735_DrawBitmap(60, 9, SmallEnemy30pointA, 16,10);
		ST7735_DrawBitmap(80, 9, SmallEnemy30pointA, 16,10);
		ST7735_DrawBitmap(100, 9, SmallEnemy30pointA, 16,10);
		
	  }
	
	else 
	{
		ST7735_DrawBitmap(0, 9, SmallEnemy10pointB, 16,10);
		ST7735_DrawBitmap(20,9, SmallEnemy30pointB, 16,10);
		ST7735_DrawBitmap(40, 9, SmallEnemy30pointB, 16,10);
		ST7735_DrawBitmap(60, 9, SmallEnemy30pointB, 16,10);
		ST7735_DrawBitmap(80, 9, SmallEnemy30pointB, 16,10);
		ST7735_DrawBitmap(100, 9, SmallEnemy30pointB, 16,10);
	}
	
}





void Missile (void)
{
	
	if (oldflag == 0)                            //create new missile
	{
		missilex = playerx;
		ST7735_DrawBitmap((Convert(missilex)+5), 145, Missile0, 4, 9);
		oldflag = 1;
	}
	
	
	else
	{
		ST7735_DrawBitmap((Convert(missilex)+5), ConvertY(), Missile0, 4, 9);
	}
	
}




int16_t ConvertY (void)
{
	
	convertedval = 145 - counter;
	counter += 5;
	if (convertedval == 0)
	{
		missileflag = 0;
		oldflag = 0;
		counter = 0;
	}
	
	return (convertedval);
	
}

