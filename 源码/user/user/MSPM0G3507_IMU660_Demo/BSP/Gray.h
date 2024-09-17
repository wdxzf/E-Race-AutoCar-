#ifndef _GRAY_H
#define _GRAY_H
#include "headfile.h"

#define Gray0 DL_GPIO_readPins(Gray_Gray_0_PORT,Gray_Gray_0_PIN)  
#define Gray1 DL_GPIO_readPins(Gray_Gray_1_PORT,Gray_Gray_1_PIN) 
#define Gray2 DL_GPIO_readPins(Gray_Gray_2_PORT,Gray_Gray_2_PIN)
#define Gray3 DL_GPIO_readPins(Gray_Gray_3_PORT,Gray_Gray_3_PIN)
#define Gray4 DL_GPIO_readPins(Gray_Gray_4_PORT,Gray_Gray_4_PIN)
#define Gray5 DL_GPIO_readPins(Gray_Gray_5_PORT,Gray_Gray_5_PIN)
#define Gray6 DL_GPIO_readPins(Gray_Gray_6_PORT,Gray_Gray_6_PIN) 
#define Gray7 DL_GPIO_readPins(Gray_Gray_7_PORT,Gray_Gray_7_PIN) 
#define Gray8 DL_GPIO_readPins(Gray_Gray_8_PORT,Gray_Gray_8_PIN) 
#define Gray9 DL_GPIO_readPins(Gray_Gray_9_PORT,Gray_Gray_9_PIN) 
#define Gray10 DL_GPIO_readPins(Gray_Gray_10_PORT,Gray_Gray_10_PIN)
#define Gray11 DL_GPIO_readPins(Gray_Gray_11_PORT,Gray_Gray_11_PIN) 


float Gray_erro(void);
void Gray_get();

extern bool Gray_Val[12];
#endif