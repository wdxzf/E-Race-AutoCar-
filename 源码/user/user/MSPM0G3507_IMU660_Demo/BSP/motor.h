#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "headfile.h"

#define PulseMPS 0.014 //ÂÖÖáÏµÊı
typedef struct
{
    float Lenth;       //¾àÀë  ·À¶¶
} Step;/***************¾àÀë***************/

int16_t Speed_Get(void);
void motor_turn(int32_t speedL,int32_t speedR);

extern Step Step1;
#endif