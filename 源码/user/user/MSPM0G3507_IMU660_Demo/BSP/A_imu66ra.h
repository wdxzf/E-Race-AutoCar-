#ifndef _A_IMU66RA_H_
#define _A_IMU66RA_H_

#include "headfile.h"

//ICM����
typedef struct
    {

    float GYRO_Z;
    //�Ƕ�
     float Yaw;
    //Y����ٶ�

    float YawVelocity;
    float YawVelocity_offset_1,
          YawVelocity_offset_2;//ƫ�����ٶ�ƫ��
    
    uint8 flag;//icm���ֱ�־λ
}IMU660RA;


void ICM_OneOrderFilter(void);
void GyroOffsets(uint16 count_g);
extern IMU660RA IMUdata; 
#endif