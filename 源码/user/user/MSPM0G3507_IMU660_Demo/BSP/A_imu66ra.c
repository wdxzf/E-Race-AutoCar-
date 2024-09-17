#include "A_imu66ra.h"

IMU660RA IMUdata = {0};


void ICM_OneOrderFilter(void)
{
    float filtered_GYRO_Z = 0.0f;
    //获取角速度
    imu660ra_get_gyro(&gyro_data);
    
    filtered_GYRO_Z = (gyro_data.z > 0) ? (gyro_data.z - IMUdata.YawVelocity_offset_1) : (gyro_data.z - IMUdata.YawVelocity_offset_2);
    IMUdata.GYRO_Z = 0.2 * IMUdata.GYRO_Z + 0.8 * filtered_GYRO_Z;
    
    if (IMUdata.flag ^ 0x01)
    {
         IMUdata.Yaw = 0;
    }
    else
    {
        IMUdata.YawVelocity = IMUdata.GYRO_Z * (1.0f / 16U);
        IMUdata.Yaw += (IMUdata.YawVelocity) * dt;
    }
    
  
}


void GyroOffsets(uint16 count_g)
{

    int16 y_1 = 0, y_2 = 0;
    uint16 count1 = 0, count2 = 0;
    uint16 i;
    for (i = 0; i < count_g; i++)
    {
        imu660ra_get_gyro(&gyro_data);
        delay_ms(1);
        if (gyro_data.z > 0)
        {
            y_1 += gyro_data.z;
            count1++;
        }
        else
        {
            y_2 += gyro_data.z;
            count2++;
        }
    }

    IMUdata.YawVelocity_offset_1 = (float)y_1 / count1;
    IMUdata.YawVelocity_offset_2 = (float)y_2 / count2;
}