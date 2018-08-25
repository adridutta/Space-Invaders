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

uint32_t score = 0;
uint8_t ivdhit = 0;

void Collision (void)
{
	uint8_t index = 0;
	uint8_t xindex = 0;
	uint8_t yindex = 0;
	uint8_t flagx = 0;
	uint8_t flagy = 0;
	uint8_t flagx2 = 0;
	uint8_t flagy2 = 0;
	
	
	if (level == 1)
	{								
									if (bullet.status == 1)
									{
									while (index < 16)
									{
										while (xindex <16)                     //check right
										{
											if ((alien[index].status ==1) && (alien[index].x +xindex) == bullet.x)
											{
												flagx = 1;
											}
												xindex++;
										}	
								
										
										
										if ((alien[index].status ==1) && (alien[index].y == bullet.y))              //check y position
										{
											flagy = 1;
										}
										
										if ((flagx == 1) && (flagy == 1))
										{
											alien[index].status = 0;
											bullet.status = 0;
											score += 10;
											TIMER2_TAILR_R = 0xFFF;
											ivdhit = 1;
											TIMER2_CTL_R = 0x0000001;
										}

										
										
											index++;
											xindex = 0;
											flagx = 0;
											flagy = 0;
											
									}
	
		
	
	
	
									}


									index = 0;

									
									
									
									if (bullet2.status == 1)
									{
										
										
										while (index < 16)
										{
												
												while (yindex <10)                     //check right
												{
																if ((alien[index].status ==1) && (alien[index].y -yindex) == bullet2.y)
																{
																	flagy2 = 1;
																}
																yindex++;
										
										    }
												
												
												while (xindex < 16)
												{
															if ((alien[index].status ==1) && (alien[index].x+xindex == bullet2.x))              //check x position
																				{
																					flagx2 = 1;
																				}
																			
															xindex++;				
												}
										
												
												
												
												if ((flagx2 == 1) && (flagy2 == 1))
																{
																	alien[index].status = 0;
																	bullet2.status = 0;
																	score += 10;
																	TIMER2_TAILR_R = 0xFFF;
																	ivdhit = 1;
																	TIMER2_CTL_R = 0x0000001;
																}
										
												index++;
												xindex =0;
												yindex = 0;
												flagx2 = 0;
												flagy2 = 0;
									    
										
									  }
										
										
										
								 }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if (level == 2)
	{
		
			if (bullet.status == 1)
									{
									while (index < 20)
									{
										while (xindex <16)                     //check right
										{
											if ((alien2[index].status ==1) && (alien2[index].x +xindex) == bullet.x)
											{
												flagx = 1;
											}
												xindex++;
										}	
										
								//		while (nxindex <4)                           //check left
								//		{
								//				if ((alien[index].status ==1)&&(alien[index].x - nxindex) == bullet.x)
								//				{
								//					flagx = 1;
								//				}
								//					nxindex++;
								//		}
										
										
										if ((alien2[index].status ==1) && (alien2[index].y == bullet.y))              //check y position
										{
											flagy = 1;
										}
										
										if ((flagx == 1) && (flagy == 1))
										{
											alien2[index].status = 0;
											bullet.status = 0;
											score += 10;
											TIMER2_TAILR_R = 0xFFF;
											ivdhit = 1;
											TIMER2_CTL_R = 0x0000001;
										}

										
										
											index++;
											xindex = 0;
											flagx = 0;
											flagy = 0;
											
									}
	
		
	
	
	
									}
									
									index = 0;

									if (bullet2.status == 1)
									{
										
										
										while (index < 20)
										{
												
												while (yindex <10)                     //check y position
												{
																if ((alien2[index].status ==1) && (alien2[index].y -yindex) == bullet2.y)
																{
																	flagy2 = 1;
																}
																yindex++;
										
										    }
												
												
												while (xindex < 16)
												{
															if ((alien2[index].status ==1) && (alien2[index].x+xindex == bullet2.x))              //check x position
																				{
																					flagx2 = 1;
																				}
																			
															xindex++;				
												}
										
												
												
												
												if ((flagx2 == 1) && (flagy2 == 1))
																{
																	alien2[index].status = 0;
																	bullet2.status = 0;
																	score += 10;
																	TIMER2_TAILR_R = 0xFFF;
																	ivdhit = 1;
																	TIMER2_CTL_R = 0x0000001;
																}
										
												index++;
												xindex =0;
												yindex = 0;
												flagx2 = 0;
												flagy2 = 0;
									    
										
									  }
										
										
										
								 }
		
		
	
     }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

