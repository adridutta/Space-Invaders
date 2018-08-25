#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"
#include "ADC.h"
#include "Timer0.h"
#include "ISR.h"
#include "Portinit.h"
#include "Sprites.h"
#include "Timer1.h"


void Collision(void);                 //looks for collision

extern uint32_t score;
extern uint8_t ivdhit;