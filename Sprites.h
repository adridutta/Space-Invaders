#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "SpaceInvaders.h"





typedef struct sprites

{
	int16_t x;
	int16_t y;
	const unsigned short *mappt[2];
	int16_t w;
	int16_t h;
	uint8_t status;             //1 alive, 0 dead
	
	
	
} typechar;


extern typechar alien[];
extern typechar alien2[];
extern typechar ship;
extern typechar bullet;
extern typechar ship2;
extern typechar bullet2;



