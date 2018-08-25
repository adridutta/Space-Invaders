#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "Sprites.h"





//typedef struct sprites
//{
//	int16_t x;
//	int16_t y;
//	const unsigned short *mappt;
//	int16_t w;
//	int16_t h;
//	uint8_t status;             //1 alive, 0 dead
//	
//	
//} typealien;
typechar alien[16] = {
{ 16,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
{ 16,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
{ 16,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
{ 16,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1}
};

typechar alien2[20] = {
{ 16,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 80,30 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
{ 16,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 80,41 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
{ 16,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 80,52 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
{ 16,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 32,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 48,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 64,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},{ 80,63 , {SmallEnemy30pointA,SmallEnemy30pointAempty}, 16, 10, 1},
};

typechar ship ={63, 159, {PlayerShip0, PlayerShip0}, 30,8, 1};



typechar bullet = {63, 151, {Missile0, Missile0empty}, 4, 9, 0,};
typechar ship2 = {0, 100, {PlayerShip0rotated, PlayerShip0rotated,}, 8, 18, 1,};
typechar bullet2 = {16, 100, {Missile0rotated, Missile0rotatedempty}, 4, 2, 0,};

