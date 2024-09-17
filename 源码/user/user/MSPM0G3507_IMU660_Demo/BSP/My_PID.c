#include "My_PID.h"

#define FILTER_Turn_0 0.8f
#define FILTER_Turn_1 0.1f
#define FILTER_Turn_2 0.07f
#define FILTER_Turn_3 0.03f

MY_turn price = {0};
Incremental Speed = {0};//速度环
void pid_clear()
{
    /***************************************转向环*******************************/

    price.Pre1_Error[0] = 0;
    price.Pre1_Error[1] = 0;
    price.Pre1_Error[2] = 0;
    price.Pre1_Error[3] = 0;
    price.ek = 0;
    price.ek1 = 0,
    price.ek2 = 0;

     price.in_ek = 0;
    price.in_ek1 = 0,
    price.in_ek2 = 0;

    price.output_val = 0;

    price.target_val = 0;
    price.target_val_last = 0;

    price.COUNTS = 0;

}
/****************************************************************
函数功能：pid参数初始化
入口参数：NULL
返回  值：NULL
****************************************************************/
 void mypid_init()
{
    pid_clear();


    /***************************************转向环*******************************/
    //内环
    price.kp = 4; //比例//5
    price.kd = 1; //微分//2


    //外环
    price.in_kp = 8; // adc本次权值//3.45 2.95
    price.in_kd = 4;  // adc上次权值0.6

    //限制
    price.maxOutput = 2199;


//    //速度环
   Speed.target_val = 800;
   Speed.ki = 0.3;
   Speed.kp = 3;
   Speed.maxOutput = 3190;


}
void DerectError_Get(MY_turn *pid, float erro) //外环
{
    pid->in_ek = erro;

    pid->target_val = pid->in_kp * pid->in_ek
                      +
                      pid->in_kd * (pid->in_ek - pid->in_ek1);

    pid->in_ek1 = pid->in_ek;

    pid->target_val_last = pid->target_val;
}


void Direction_out(MY_turn *pid)//内环
{
   // pid->target_val = 0; //开启这句话，表示转向环只有内环，外环输出为0

    pid->ek = pid->target_val - IMUdata.GYRO_Z * (1.0f / 16U);

    pid->output_val = pid->kp * pid->ek + pid->kd * (pid->ek - pid->ek1);

    pid->ek2 = pid->ek1; //保存上上次误差
    pid->ek1 = pid->ek;  //保存上次误差

    pid-> Pre1_Error[3] = pid->Pre1_Error[2];
    pid-> Pre1_Error[2] = pid->Pre1_Error[1];
    pid-> Pre1_Error[1] = pid->Pre1_Error[0];
    pid-> Pre1_Error[0] = pid->output_val;

    pid->output_val =   (pid-> Pre1_Error[0] * FILTER_Turn_0) +
                        (pid-> Pre1_Error[1] * FILTER_Turn_1) +
                        (pid-> Pre1_Error[2] * FILTER_Turn_2) +
                        (pid-> Pre1_Error[3] * FILTER_Turn_3) ;
    pid->output_val_last = pid->output_val;

    pid->output_val = func_limit(pid->output_val, price.maxOutput); //转向限制幅度
}

void DifferControl(float erro, MY_turn *pid)
{
    if (pid->COUNTS == 3)
    {
        pid->COUNTS = 0;
        DerectError_Get(pid, erro);
    }
    pid->COUNTS++;
    pid->target_val = pid->target_val_last + (pid->target_val - pid->target_val_last) * pid->COUNTS / 3;
    Direction_out(pid);
}


void PID_DT(Incremental *pid)//增量式
{
  
    pid->ek1 = pid->ek;//保存上次误差
    pid->ek  = (pid->target_val - pid->now);//计算当前误差

    pid->pid_delta += ((pid->kp * (pid->ek - pid->ek1)

                                + pid->ki * pid->ek));

    pid->pid_delta = func_limit(pid->pid_delta, pid->maxOutput);

    pid->output_val = (int16_t)pid->pid_delta;
}