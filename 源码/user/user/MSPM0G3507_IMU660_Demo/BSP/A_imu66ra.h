#ifndef _A_IMU66RA_H_
#define _A_IMU66RA_H_

#include "headfile.h"

//ICM数据
typedef struct
    {

    float GYRO_Z;
    //角度
     float Yaw;
    //Y轴角速度

    float YawVelocity;
    float YawVelocity_offset_1,
          YawVelocity_offset_2;//偏航角速度偏置
    
    uint8 flag;//icm积分标志位
}IMU660RA;


void ICM_OneOrderFilter(void);
void GyroOffsets(uint16 count_g);
extern IMU660RA IMUdata; 
#endif