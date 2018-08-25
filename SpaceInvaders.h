#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "Timer0.h"




extern int16_t Convert(uint32_t data);
extern uint8_t flag;
extern uint32_t playerx;
extern int8_t alienflag;
extern int16_t convertedmissilex;
extern int16_t convertedmissiley;
extern int8_t missileflag;
extern const unsigned short SmallEnemy10pointA[];
extern const unsigned short SmallEnemy10pointB[];
extern const unsigned short SmallEnemy20pointA[];
extern const unsigned short SmallEnemy20pointB[];
extern const unsigned short SmallEnemy30pointA[];
extern const unsigned short SmallEnemy30pointB[];
extern const unsigned short Bunker0[];
extern const unsigned short Missile0[];
extern const unsigned short PlayerShip0[];
extern const unsigned short Missile0empty[];
extern const unsigned short SmallEnemy30pointAempty[];
extern const unsigned short PlayerShip0rotated[];
extern const unsigned short Missile0rotated[];
extern const unsigned short Missile0rotatedempty[];
extern uint8_t gameoverflag;
extern uint8_t winflag;
extern uint8_t level;
extern uint8_t level2flag;



void Gameover (void);