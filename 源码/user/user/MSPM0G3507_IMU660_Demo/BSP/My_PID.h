#ifndef MY_PID_H_
#define MY_PID_H_
#include "headfile.h"

typedef struct
{
    float Pre1_Error[4];//����˲�
    float kp,//����
          kd,//΢��
          in_kp,//adc����Ȩֵ
          in_kd,//adc�ϴ�Ȩֵ
          in_kT;
    
    float target_val,   //Ŀ��ֵ
          target_val_last;//�ϴ�Ŀ��ֵ
    //�ڻ�ƫ��
    float   ek,          //ƫ��ֵ
            ek1,     //��һ��ƫ��ֵ
            ek2;     //���ϸ�ƫ��ֵ
    //�⻷ƫ��
      float  in_ek,          //ƫ��ֵ
            in_ek1,     //��һ��ƫ��ֵ
            in_ek2;     //���ϸ�ƫ��ֵ
      
    float output_val,//���ֵ
          output_val_last,
          maxOutput;//���������޷�
    
    uint8_t COUNTS;//���⻷������
}MY_turn;//ת��

typedef struct
{
    int16_t target_val,   //Ŀ��ֵ
                 now;   //��ǰֵ

    int16_t ek,          //ƫ��ֵ
         ek1;     //��һ��ƫ��ֵ

    float pid_delta;   //����ʽ�������
    
    int16_t output_val;//���ֵ
    
    float kp, 
          ki;   //���������֡�΢��ϵ��

    int16_t maxOutput;//���������޷�
    //float maxIntegral

}Incremental;//����ʽ

void mypid_init(void);
void DifferControl(float erro, MY_turn *pid);
void PID_DT(Incremental *pid);//����ʽ
extern MY_turn price;
extern Incremental Speed;//�ٶȻ�
#endif