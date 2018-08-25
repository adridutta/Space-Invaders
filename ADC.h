// put prototypes for public functions, explain what it does
// put your names here, date


#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "PLL.h"








void ADC_Init(void); //initialize adc
uint32_t ADC_In(void); // busy wait and then sends data
uint32_t ADC2_In (void);

