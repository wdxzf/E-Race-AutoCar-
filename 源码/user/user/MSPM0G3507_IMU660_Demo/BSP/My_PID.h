#ifndef MY_PID_H_
#define MY_PID_H_
#include "headfile.h"

typedef struct
{
    float Pre1_Error[4];//误差滤波
    float kp,//比例
          kd,//微分
          in_kp,//adc本次权值
          in_kd,//adc上次权值
          in_kT;
    
    float target_val,   //目标值
          target_val_last;//上次目标值
    //内环偏差
    float   ek,          //偏差值
            ek1,     //上一个偏差值
            ek2;     //上上个偏差值
    //外环偏差
      float  in_ek,          //偏差值
            in_ek1,     //上一个偏差值
            in_ek2;     //上上个偏差值
      
    float output_val,//输出值
          output_val_last,
          maxOutput;//输出、输出限幅
    
    uint8_t COUNTS;//内外环计数器
}MY_turn;//转向环

typedef struct
{
    int16_t target_val,   //目标值
                 now;   //当前值

    int16_t ek,          //偏差值
         ek1;     //上一个偏差值

    float pid_delta;   //增量式计算输出
    
    int16_t output_val;//输出值
    
    float kp, 
          ki;   //比例、积分、微分系数

    int16_t maxOutput;//输出、输出限幅
    //float maxIntegral

}Incremental;//增量式

void mypid_init(void);
void DifferControl(float erro, MY_turn *pid);
void PID_DT(Incremental *pid);//增量式
extern MY_turn price;
extern Incremental Speed;//速度环
#endif