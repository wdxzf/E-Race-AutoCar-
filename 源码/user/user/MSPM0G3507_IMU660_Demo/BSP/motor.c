#include "motor.h"

Step Step1 = {0};
static void L_control(uint8_t dir, uint32_t speed)
{
   
    if( dir == 1 )
    {
      DL_GPIO_setPins(Motor_PORT,Motor_L1_PIN);
      DL_GPIO_clearPins(Motor_PORT,Motor_L2_PIN);
    }
    else
    {
      DL_GPIO_clearPins(Motor_PORT,Motor_L1_PIN);
      DL_GPIO_setPins(Motor_PORT,Motor_L2_PIN);
    }
      DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,speed,GPIO_PWM_Motor_C0_IDX);
}

static void R_control(uint8_t dir, uint32_t speed)
{
    
    if( dir == 1 )
    {
      DL_GPIO_clearPins(Motor_PORT,Motor_R1_PIN);
      DL_GPIO_setPins(Motor_PORT,Motor_R2_PIN);
    }
    else
    {
      DL_GPIO_setPins(Motor_PORT,Motor_R1_PIN);
      DL_GPIO_clearPins(Motor_PORT,Motor_R2_PIN);
    }
     DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,speed,GPIO_PWM_Motor_C1_IDX);//PA25
}

void motor_turn(int32_t speedL,int32_t speedR)//右，左
{
    
    speedL = func_limit(speedL ,3199);
    speedR = func_limit(speedR ,3199);

    if(speedL < 0)L_control(0, -speedL);
    else L_control(1, speedL);
  
    if(speedR < 0)R_control(1, -speedR);
    else R_control(0, speedR);
}

int16_t Speed_Get(void)
{
    static int16_t previousSpeed[10] = {0};
    int16_t averageSpeed = 0;
    int16_t speed_val = encoder_L + encoder_R;
    
    // 清空编码器
    encoder_L = 0;
    encoder_R = 0;

    // 更新历史速度值并计算累计和
    for (uint8_t i = 9; i > 0; i--)
    {
        previousSpeed[i] = previousSpeed[i - 1];
        averageSpeed += previousSpeed[i];
    }

    previousSpeed[0] = speed_val;
    averageSpeed += previousSpeed[0];

    //Step1.Lenth = (Step1.flag ^ 0x01) ? 0 : Step1.Lenth + averageSpeed * dt;
    Step1.Lenth += averageSpeed * PulseMPS;

    return averageSpeed ;// 计算平均速度并返回
}