#include "My_PID.h"

#define FILTER_Turn_0 0.8f
#define FILTER_Turn_1 0.1f
#define FILTER_Turn_2 0.07f
#define FILTER_Turn_3 0.03f

MY_turn price = {0};
Incremental Speed = {0};//�ٶȻ�
void pid_clear()
{
    /***************************************ת��*******************************/

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
�������ܣ�pid������ʼ��
��ڲ�����NULL
����  ֵ��NULL
****************************************************************/
 void mypid_init()
{
    pid_clear();


    /***************************************ת��*******************************/
    //�ڻ�
    price.kp = 4; //����//5
    price.kd = 1; //΢��//2


    //�⻷
    price.in_kp = 8; // adc����Ȩֵ//3.45 2.95
    price.in_kd = 4;  // adc�ϴ�Ȩֵ0.6

    //����
    price.maxOutput = 2199;


//    //�ٶȻ�
   Speed.target_val = 800;
   Speed.ki = 0.3;
   Speed.kp = 3;
   Speed.maxOutput = 3190;


}
void DerectError_Get(MY_turn *pid, float erro) //�⻷
{
    pid->in_ek = erro;

    pid->target_val = pid->in_kp * pid->in_ek
                      +
                      pid->in_kd * (pid->in_ek - pid->in_ek1);

    pid->in_ek1 = pid->in_ek;

    pid->target_val_last = pid->target_val;
}


void Direction_out(MY_turn *pid)//�ڻ�
{
   // pid->target_val = 0; //������仰����ʾת��ֻ���ڻ����⻷���Ϊ0

    pid->ek = pid->target_val - IMUdata.GYRO_Z * (1.0f / 16U);

    pid->output_val = pid->kp * pid->ek + pid->kd * (pid->ek - pid->ek1);

    pid->ek2 = pid->ek1; //�������ϴ����
    pid->ek1 = pid->ek;  //�����ϴ����

    pid-> Pre1_Error[3] = pid->Pre1_Error[2];
    pid-> Pre1_Error[2] = pid->Pre1_Error[1];
    pid-> Pre1_Error[1] = pid->Pre1_Error[0];
    pid-> Pre1_Error[0] = pid->output_val;

    pid->output_val =   (pid-> Pre1_Error[0] * FILTER_Turn_0) +
                        (pid-> Pre1_Error[1] * FILTER_Turn_1) +
                        (pid-> Pre1_Error[2] * FILTER_Turn_2) +
                        (pid-> Pre1_Error[3] * FILTER_Turn_3) ;
    pid->output_val_last = pid->output_val;

    pid->output_val = func_limit(pid->output_val, price.maxOutput); //ת�����Ʒ���
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


void PID_DT(Incremental *pid)//����ʽ
{
  
    pid->ek1 = pid->ek;//�����ϴ����
    pid->ek  = (pid->target_val - pid->now);//���㵱ǰ���

    pid->pid_delta += ((pid->kp * (pid->ek - pid->ek1)

                                + pid->ki * pid->ek));

    pid->pid_delta = func_limit(pid->pid_delta, pid->maxOutput);

    pid->output_val = (int16_t)pid->pid_delta;
}