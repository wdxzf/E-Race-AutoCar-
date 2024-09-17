/*********************************************************************************************************************
* MSPM0G3507 Opensourec Library ����MSPM0G3507 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
* 
* ���ļ��� MSPM0G3507 ��Դ���һ����
* 
* MSPM0G3507 ��Դ�� ��������
* �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
* 
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
* 
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
* 
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
* �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
* 
* �ļ�����          zf_device_imu963ra
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MDK 5.38a
* ����ƽ̨          MSPM0G3507
* ��������          https://seekfree.taobao.com/
********************************************************************************************************************/

/*********************************************************************************************************************
* ���߶���          �鿴 zf_device_imu_interface.h �нӿ���Դ����
********************************************************************************************************************/

#ifndef _zf_device_imu963ra_h
#define _zf_device_imu963ra_h

// zf_common �� ���Ͷ��� ����
#include "zf_common_typedef.h"

// �˴��о� ��ǰ֧�ֵĺ����б�
// ���������ڱ������в鿴��Ӧע�� ���嶨����ת����Ӧ��������鿴
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// imu963ra_get_physical_acc                                                    // ��ȡ IMU963RA ���ٶȼ�����������
// imu963ra_get_physical_gyro                                                   // ��ȡ IMU963RA ����������������
// imu963ra_get_physical_mag                                                    // ��ȡ IMU963RA �شż�����������

// imu963ra_get_acc                                                             // ��ȡ IMU963RA ���ٶȼ�����
// imu963ra_get_gyro                                                            // ��ȡ IMU963RA ����������
// imu963ra_get_mag                                                             // ��ȡ IMU963RA �شż�����

// imu963ra_set_config                                                          // IMU963RA ����ģ�鹤������
// imu963ra_init                                                                // ��ʼ�� IMU963RA
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴����� IMU963RA ��صĽṹ�����ݹ���ϸ�� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// IMU963RA_ACC_OUTPUT_RATE_BASE ��ӦĬ�ϵ� IMU963RA �ļ��ٶȼ��������Ƶ�� ʵ��Ϊ 52Hz
// ʵ�ʻ�����ƫ�� ��Ҫȥ�鿴��Ӧ��оƬ�ֲ� ��˶�Ӧ�ӵ͵��߿�������Ϊ
// IMU963RA_ACC_OUTPUT_RATE_4_DIV       ->  12.5    Hz
// IMU963RA_ACC_OUTPUT_RATE_2_DIV       ->  26      Hz
// IMU963RA_ACC_OUTPUT_RATE_BASE        ->  52      Hz
// IMU963RA_ACC_OUTPUT_RATE_2_MUL       ->  104     Hz
// IMU963RA_ACC_OUTPUT_RATE_4_MUL       ->  208     Hz
// IMU963RA_ACC_OUTPUT_RATE_8_MUL       ->  416     Hz
// IMU963RA_ACC_OUTPUT_RATE_16_MUL      ->  833     Hz
// IMU963RA_ACC_OUTPUT_RATE_32_MUL      ->  1666    Hz
// IMU963RA_ACC_OUTPUT_RATE_64_MUL      ->  3332    Hz
// IMU963RA_ACC_OUTPUT_RATE_128_MUL     ->  6667    Hz
typedef enum
{
    IMU963RA_ACC_OUTPUT_RATE_4_DIV  = 6 ,                                       // ���ٶȼ����Ƶ�� 4  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_2_DIV      ,                                       // ���ٶȼ����Ƶ�� 2  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_BASE       ,                                       // ���ٶȼ����Ƶ�ʻ���Ƶ�� (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_2_MUL      ,                                       // ���ٶȼ����Ƶ�� 2  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_4_MUL      ,                                       // ���ٶȼ����Ƶ�� 4  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_8_MUL      ,                                       // ���ٶȼ����Ƶ�� 8  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_16_MUL     ,                                       // ���ٶȼ����Ƶ�� 16 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_32_MUL     ,                                       // ���ٶȼ����Ƶ�� 32 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_64_MUL     ,                                       // ���ٶȼ����Ƶ�� 64 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU963RA_ACC_OUTPUT_RATE_128_MUL    ,                                       // ���ٶȼ����Ƶ�� 128��Ƶ (ACC = Accelerometer ���ٶȼ�)
}imu963ra_acc_output_rate_enum;

typedef enum
{
    IMU963RA_ACC_RANGE_SGN_2G       = 2 ,                                       // ���ٶȼ����� ��2 g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
    IMU963RA_ACC_RANGE_SGN_4G           ,                                       // ���ٶȼ����� ��4 g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
    IMU963RA_ACC_RANGE_SGN_8G           ,                                       // ���ٶȼ����� ��8 g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
    IMU963RA_ACC_RANGE_SGN_16G          ,                                       // ���ٶȼ����� ��16g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
}imu963ra_acc_range_enum;

// IMU963RA_GYRO_OUTPUT_RATE_BASE ��ӦĬ�ϵ� IMU963RA ���������������Ƶ�� ʵ��Ϊ 52Hz
// ʵ�ʻ�����ƫ�� ��Ҫȥ�鿴��Ӧ��оƬ�ֲ� ��˶�Ӧ�ӵ͵��߿�������Ϊ
// IMU963RA_GYRO_OUTPUT_RATE_4_DIV      ->  12.5    Hz
// IMU963RA_GYRO_OUTPUT_RATE_2_DIV      ->  26      Hz
// IMU963RA_GYRO_OUTPUT_RATE_BASE       ->  52      Hz
// IMU963RA_GYRO_OUTPUT_RATE_2_MUL      ->  104     Hz
// IMU963RA_GYRO_OUTPUT_RATE_4_MUL      ->  208     Hz
// IMU963RA_GYRO_OUTPUT_RATE_8_MUL      ->  416     Hz
// IMU963RA_GYRO_OUTPUT_RATE_16_MUL     ->  833     Hz
// IMU963RA_GYRO_OUTPUT_RATE_32_MUL     ->  1666    Hz
// IMU963RA_GYRO_OUTPUT_RATE_64_MUL     ->  3332    Hz
// IMU963RA_GYRO_OUTPUT_RATE_128_MUL    ->  6667    Hz
typedef enum
{
    IMU963RA_GYRO_OUTPUT_RATE_4_DIV = 6 ,                                       // ���������Ƶ�� 4  ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_2_DIV     ,                                       // ���������Ƶ�� 2  ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_BASE      ,                                       // ���������Ƶ�ʻ���Ƶ�� (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_2_MUL     ,                                       // ���������Ƶ�� 2  ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_4_MUL     ,                                       // ���������Ƶ�� 4  ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_8_MUL     ,                                       // ���������Ƶ�� 8  ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_16_MUL    ,                                       // ���������Ƶ�� 16 ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_32_MUL    ,                                       // ���������Ƶ�� 32 ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_64_MUL    ,                                       // ���������Ƶ�� 64 ��Ƶ (GYRO = Gyroscope ������)
    IMU963RA_GYRO_OUTPUT_RATE_128_MUL   ,                                       // ���������Ƶ�� 128��Ƶ (GYRO = Gyroscope ������)
}imu963ra_gyro_output_rate_enum;

typedef enum
{
    IMU963RA_GYRO_RANGE_SGN_125DPS  = 2 ,                                       // ���������� ��125DPS  (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU963RA_GYRO_RANGE_SGN_250DPS      ,                                       // ���������� ��250DPS  (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU963RA_GYRO_RANGE_SGN_500DPS      ,                                       // ���������� ��500DPS  (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU963RA_GYRO_RANGE_SGN_1000DPS     ,                                       // ���������� ��1000DPS (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU963RA_GYRO_RANGE_SGN_2000DPS     ,                                       // ���������� ��2000DPS (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU963RA_GYRO_RANGE_SGN_4000DPS     ,                                       // ���������� ��4000DPS (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
}imu963ra_gyro_range_enum;

// IMU963RA_MAG_OUTPUT_RATE_BASE ��ӦĬ�ϵ� IMU963RA �Ĵ������������Ƶ�� ʵ��Ϊ 50Hz
// ʵ�ʻ�����ƫ�� ��Ҫȥ�鿴��Ӧ��оƬ�ֲ� ��˶�Ӧ�ӵ͵��߿�������Ϊ
// IMU963RA_MAG_OUTPUT_RATE_4_DIV       ->  10      Hz
// IMU963RA_MAG_OUTPUT_RATE_BASE        ->  50      Hz
// IMU963RA_MAG_OUTPUT_RATE_2_MUL       ->  100     Hz
// IMU963RA_MAG_OUTPUT_RATE_4_MUL       ->  200     Hz
typedef enum
{
    IMU963RA_MAG_OUTPUT_RATE_4_DIV  = 6 ,                                       // ���������Ƶ�� 4  ��Ƶ (MAG = Magnetometer ������)
    IMU963RA_MAG_OUTPUT_RATE_BASE   = 8 ,                                       // ���������Ƶ�ʻ���Ƶ�� (MAG = Magnetometer ������)
    IMU963RA_MAG_OUTPUT_RATE_2_MUL      ,                                       // ���������Ƶ�� 2  ��Ƶ (MAG = Magnetometer ������)
    IMU963RA_MAG_OUTPUT_RATE_4_MUL      ,                                       // ���������Ƶ�� 4  ��Ƶ (MAG = Magnetometer ������)
}imu963ra_mag_output_rate_enum;

typedef enum
{
    IMU963RA_MAG_RANGE_2G           = 2 ,                                       // ���������� 2G (MAG = Magnetometer ������) (G = Gs ��˹)
    IMU963RA_MAG_RANGE_8G               ,                                       // ���������� 8G (MAG = Magnetometer ������) (G = Gs ��˹)
}imu963ra_mag_range_enum;

#define IMU963RA_TIMEOUT_COUNT              ( 32 )                              // IMU963RA ��ʱ����

#define IMU963RA_ACC_OUTPUT_RATE_DEFAULT    ( IMU963RA_ACC_OUTPUT_RATE_BASE   ) // ��������Ĭ�ϵ� ���ٶȼ�  ��ʼ�����Ƶ��
#define IMU963RA_ACC_RANGE_DEFAULT          ( IMU963RA_ACC_RANGE_SGN_8G       ) // ��������Ĭ�ϵ� ���ٶȼ�  ��ʼ������
#define IMU963RA_GYRO_OUTPUT_RATE_DEFAULT   ( IMU963RA_GYRO_OUTPUT_RATE_4_MUL ) // ��������Ĭ�ϵ� ������    ��ʼ�����Ƶ��
#define IMU963RA_GYRO_RANGE_DEFAULT         ( IMU963RA_GYRO_RANGE_SGN_2000DPS ) // ��������Ĭ�ϵ� ������    ��ʼ������
#define IMU963RA_MAG_OUTPUT_RATE_DEFAULT    ( IMU963RA_MAG_OUTPUT_RATE_BASE   ) // ��������Ĭ�ϵ� ������    ��ʼ�����Ƶ��
#define IMU963RA_MAG_RANGE_DEFAULT          ( IMU963RA_MAG_RANGE_8G           ) // ��������Ĭ�ϵ� ������    ��ʼ������

#define IMU963RA_CONFIG_TYPE_OFFSET         ( 4     )                           // �ۼƵ�λ��λ�ƺ�� 16bit ��ʼ
#define IMU963RA_CONFIG_TYPE_MASK           ( 0x0F  )                           // ͬ��������Ҫ��ӵ����ŷ��ù������� ����Ҳ�� 4bit �������Ϊ 0xF

#define IMU963RA_CONFIG_VALUE_OFFSET        ( 0     )                           // �ۼƵ�λ��λ�ƺ�� 16bit ��ʼ
#define IMU963RA_CONFIG_VALUE_MASK          ( 0x0F  )                           // ͬ��������Ҫ��ӵ����ŷ��ù������� ����Ҳ�� 4bit �������Ϊ 0xF

typedef enum                                                                    // ö�� IMU963RA ����ѡ�� ��ö�ٶ��岻�����û��޸�
{
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_4_DIV           = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_4_DIV   )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_2_DIV           = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_2_DIV   )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_BASE            = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_BASE    )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_2_MUL           = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_2_MUL   )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_4_MUL           = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_4_MUL   )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_8_MUL           = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_8_MUL   )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_16_MUL          = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_16_MUL  )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_32_MUL          = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_32_MUL  )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_64_MUL          = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_64_MUL  )   ,
    IMU963RA_CONFIG_ACC_OUTPUT_RATE_128_MUL         = ((0x00 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_OUTPUT_RATE_128_MUL )   ,

    IMU963RA_CONFIG_ACC_RANGE_SGN_2G                = ((0x01 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_RANGE_SGN_2G    )       ,
    IMU963RA_CONFIG_ACC_RANGE_SGN_4G                = ((0x01 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_RANGE_SGN_4G    )       ,
    IMU963RA_CONFIG_ACC_RANGE_SGN_8G                = ((0x01 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_RANGE_SGN_8G    )       ,
    IMU963RA_CONFIG_ACC_RANGE_SGN_16G               = ((0x01 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_ACC_RANGE_SGN_16G   )       ,

    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_4_DIV          = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_4_DIV  )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_2_DIV          = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_2_DIV  )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_BASE           = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_BASE   )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_2_MUL          = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_2_MUL  )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_4_MUL          = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_4_MUL  )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_8_MUL          = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_8_MUL  )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_16_MUL         = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_16_MUL )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_32_MUL         = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_32_MUL )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_64_MUL         = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_64_MUL )   ,
    IMU963RA_CONFIG_GYRO_OUTPUT_RATE_128_MUL        = ((0x02 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_OUTPUT_RATE_128_MUL)   ,

    IMU963RA_CONFIG_GYRO_RANGE_SGN_125DPS           = ((0x03 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_RANGE_SGN_125DPS   )   ,
    IMU963RA_CONFIG_GYRO_RANGE_SGN_250DPS           = ((0x03 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_RANGE_SGN_250DPS   )   ,
    IMU963RA_CONFIG_GYRO_RANGE_SGN_500DPS           = ((0x03 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_RANGE_SGN_500DPS   )   ,
    IMU963RA_CONFIG_GYRO_RANGE_SGN_1000DPS          = ((0x03 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_RANGE_SGN_1000DPS  )   ,
    IMU963RA_CONFIG_GYRO_RANGE_SGN_2000DPS          = ((0x03 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_RANGE_SGN_2000DPS  )   ,
    IMU963RA_CONFIG_GYRO_RANGE_SGN_4000DPS          = ((0x03 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_GYRO_RANGE_SGN_4000DPS  )   ,

    IMU963RA_CONFIG_MAG_OUTPUT_RATE_4_DIV           = ((0x04 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_MAG_OUTPUT_RATE_4_DIV   )   ,
    IMU963RA_CONFIG_MAG_OUTPUT_RATE_BASE            = ((0x04 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_MAG_OUTPUT_RATE_BASE    )   ,
    IMU963RA_CONFIG_MAG_OUTPUT_RATE_2_MUL           = ((0x04 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_MAG_OUTPUT_RATE_2_MUL   )   ,
    IMU963RA_CONFIG_MAG_OUTPUT_RATE_4_MUL           = ((0x04 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_MAG_OUTPUT_RATE_4_MUL   )   ,

    IMU963RA_CONFIG_MAG_RANGE_2G                    = ((0x05 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_MAG_RANGE_2G    )           ,
    IMU963RA_CONFIG_MAG_RANGE_8G                    = ((0x05 << IMU963RA_CONFIG_TYPE_OFFSET) | IMU963RA_MAG_RANGE_8G    )           ,
}imu963ra_config_item_enum;

typedef enum
{
    IMU963RA_INTERFACE_SPI      ,
    IMU963RA_INTERFACE_SOFT_IIC ,
    IMU963RA_INTERFACE_IIC      ,
}imu963ra_interface_type_enum;

typedef enum
{
    IMU963RA_STATE_NO_ERROR                     ,

    IMU963RA_STATE_DATA_BUFFER_ERROR            ,
    IMU963RA_STATE_INTERFACE_INIT_ERROR         ,
    IMU963RA_STATE_ID_CHECK_ERROR               ,
    IMU963RA_STATE_SELF_CHECK_ERROR             ,
    IMU963RA_STATE_SET_CONFIG_ERROR             ,
    IMU963RA_STATE_SET_ACC_OUTPUT_RATE_ERROR    ,
    IMU963RA_STATE_SET_ACC_RANGE_ERROR          ,
    IMU963RA_STATE_SET_GYRO_OUTPUT_RATE_ERROR   ,
    IMU963RA_STATE_SET_GYRO_RANGE_ERROR         ,
    IMU963RA_STATE_SET_MAG_OUTPUT_RATE_ERROR    ,
    IMU963RA_STATE_SET_MAG_RANGE_ERROR          ,

    IMU963RA_STATE_MAG_WRITE_RIGESTER_ERROR     ,
    IMU963RA_STATE_MAG_ID_CHECK_ERROR           ,
    IMU963RA_STATE_MAG_SET_CONFIG_ERROR         ,
}imu963ra_state_enum;

typedef struct                                                                  // IMU963RA ���ݸ�ʽģ�� ���ڴ洢 IMU963RA ������
{
    int16       x   ;                                                           // X ���ԭʼ����
    int16       y   ;                                                           // Y ���ԭʼ����
    int16       z   ;                                                           // Z ���ԭʼ����
}imu963ra_measurement_data_struct;

typedef struct                                                                  // IMU963RA ���ݸ�ʽģ�� ���ڴ洢 IMU963RA ������
{
    float       x   ;                                                           // X �������������
    float       y   ;                                                           // Y �������������
    float       z   ;                                                           // Z �������������
}imu963ra_physical_data_struct;
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴����� IMU963RA ����������ڲ����� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���� IMU963RA �ڲ���ַ
#define IMU963RA_DEV_ADDR                           ( 0x6B )                    // 7bit ��ַ��ʽ SA0�ӵأ�0x6A SA0������0x6B ģ��Ĭ������
#define IMU963RA_SPI_W                              ( 0x00 )
#define IMU963RA_SPI_R                              ( 0x80 )

#define IMU963RA_FUNC_CFG_ACCESS                    ( 0x01 )
#define IMU963RA_PIN_CTRL                           ( 0x02 )
#define IMU963RA_S4S_TPH_L                          ( 0x04 )
#define IMU963RA_S4S_TPH_H                          ( 0x05 )
#define IMU963RA_S4S_RR                             ( 0x06 )
#define IMU963RA_FIFO_CTRL1                         ( 0x07 )
#define IMU963RA_FIFO_CTRL2                         ( 0x08 )
#define IMU963RA_FIFO_CTRL3                         ( 0x09 )
#define IMU963RA_FIFO_CTRL4                         ( 0x0A )
#define IMU963RA_COUNTER_BDR_REG1                   ( 0x0B )
#define IMU963RA_COUNTER_BDR_REG2                   ( 0x0C )
#define IMU963RA_INT1_CTRL                          ( 0x0D )
#define IMU963RA_INT2_CTRL                          ( 0x0E )
#define IMU963RA_WHO_AM_I                           ( 0x0F )
#define IMU963RA_CTRL1_XL                           ( 0x10 )
#define IMU963RA_CTRL2_G                            ( 0x11 )
#define IMU963RA_CTRL3_C                            ( 0x12 )
#define IMU963RA_CTRL4_C                            ( 0x13 )
#define IMU963RA_CTRL5_C                            ( 0x14 )
#define IMU963RA_CTRL6_C                            ( 0x15 )
#define IMU963RA_CTRL7_G                            ( 0x16 )
#define IMU963RA_CTRL8_XL                           ( 0x17 )
#define IMU963RA_CTRL9_XL                           ( 0x18 )
#define IMU963RA_CTRL10_C                           ( 0x19 )
#define IMU963RA_ALL_INT_SRC                        ( 0x1A )
#define IMU963RA_WAKE_UP_SRC                        ( 0x1B )
#define IMU963RA_TAP_SRC                            ( 0x1C )
#define IMU963RA_D6D_SRC                            ( 0x1D )
#define IMU963RA_STATUS_REG                         ( 0x1E )
#define IMU963RA_OUT_TEMP_L                         ( 0x20 )
#define IMU963RA_OUT_TEMP_H                         ( 0x21 )
#define IMU963RA_OUTX_L_G                           ( 0x22 )
#define IMU963RA_OUTX_H_G                           ( 0x23 )
#define IMU963RA_OUTY_L_G                           ( 0x24 )
#define IMU963RA_OUTY_H_G                           ( 0x25 )
#define IMU963RA_OUTZ_L_G                           ( 0x26 )
#define IMU963RA_OUTZ_H_G                           ( 0x27 )
#define IMU963RA_OUTX_L_A                           ( 0x28 )
#define IMU963RA_OUTX_H_A                           ( 0x29 )
#define IMU963RA_OUTY_L_A                           ( 0x2A )
#define IMU963RA_OUTY_H_A                           ( 0x2B )
#define IMU963RA_OUTZ_L_A                           ( 0x2C )
#define IMU963RA_OUTZ_H_A                           ( 0x2D )
#define IMU963RA_EMB_FUNC_STATUS_MAINPAGE           ( 0x35 )
#define IMU963RA_FSM_STATUS_A_MAINPAGE              ( 0x36 )
#define IMU963RA_FSM_STATUS_B_MAINPAGE              ( 0x37 )
#define IMU963RA_STATUS_MASTER_MAINPAGE             ( 0x39 )
#define IMU963RA_FIFO_STATUS1                       ( 0x3A )
#define IMU963RA_FIFO_STATUS2                       ( 0x3B )
#define IMU963RA_TIMESTAMP0                         ( 0x40 )
#define IMU963RA_TIMESTAMP1                         ( 0x41 )
#define IMU963RA_TIMESTAMP2                         ( 0x42 )
#define IMU963RA_TIMESTAMP3                         ( 0x43 )
#define IMU963RA_TAP_CFG0                           ( 0x56 )
#define IMU963RA_TAP_CFG1                           ( 0x57 )
#define IMU963RA_TAP_CFG2                           ( 0x58 )
#define IMU963RA_TAP_THS_6D                         ( 0x59 )
#define IMU963RA_INT_DUR2                           ( 0x5A )
#define IMU963RA_WAKE_UP_THS                        ( 0x5B )
#define IMU963RA_WAKE_UP_DUR                        ( 0x5C )
#define IMU963RA_FREE_FALL                          ( 0x5D )
#define IMU963RA_MD1_CFG                            ( 0x5E )
#define IMU963RA_MD2_CFG                            ( 0x5F )
#define IMU963RA_S4S_ST_CMD_CODE                    ( 0x60 )
#define IMU963RA_S4S_DT_REG                         ( 0x61 )
#define IMU963RA_I3C_BUS_AVB                        ( 0x62 )
#define IMU963RA_INTERNAL_FREQ_FINE                 ( 0x63 )
#define IMU963RA_INT_OIS                            ( 0x6F )
#define IMU963RA_CTRL1_OIS                          ( 0x70 )
#define IMU963RA_CTRL2_OIS                          ( 0x71 )
#define IMU963RA_CTRL3_OIS                          ( 0x72 )
#define IMU963RA_X_OFS_USR                          ( 0x73 )
#define IMU963RA_Y_OFS_USR                          ( 0x74 )
#define IMU963RA_Z_OFS_USR                          ( 0x75 )
#define IMU963RA_FIFO_DATA_OUT_TAG                  ( 0x78 )
#define IMU963RA_FIFO_DATA_OUT_X_L                  ( 0x79 )
#define IMU963RA_FIFO_DATA_OUT_X_H                  ( 0x7A )
#define IMU963RA_FIFO_DATA_OUT_Y_L                  ( 0x7B )
#define IMU963RA_FIFO_DATA_OUT_Y_H                  ( 0x7C )
#define IMU963RA_FIFO_DATA_OUT_Z_L                  ( 0x7D )
#define IMU963RA_FIFO_DATA_OUT_Z_H                  ( 0x7E )

// ������������ؼĴ��� ��Ҫ��FUNC_CFG_ACCESS��SHUB_REG_ACCESSλ����Ϊ1������ȷ����
#define IMU963RA_SENSOR_HUB_1                       ( 0x02 ) 
#define IMU963RA_SENSOR_HUB_2                       ( 0x03 ) 
#define IMU963RA_SENSOR_HUB_3                       ( 0x04 ) 
#define IMU963RA_SENSOR_HUB_4                       ( 0x05 ) 
#define IMU963RA_SENSOR_HUB_5                       ( 0x06 ) 
#define IMU963RA_SENSOR_HUB_6                       ( 0x07 ) 
#define IMU963RA_SENSOR_HUB_7                       ( 0x08 ) 
#define IMU963RA_SENSOR_HUB_8                       ( 0x09 ) 
#define IMU963RA_SENSOR_HUB_9                       ( 0x0A ) 
#define IMU963RA_SENSOR_HUB_10                      ( 0x0B ) 
#define IMU963RA_SENSOR_HUB_11                      ( 0x0C ) 
#define IMU963RA_SENSOR_HUB_12                      ( 0x0D ) 
#define IMU963RA_SENSOR_HUB_13                      ( 0x0E ) 
#define IMU963RA_SENSOR_HUB_14                      ( 0x0F ) 
#define IMU963RA_SENSOR_HUB_15                      ( 0x10 ) 
#define IMU963RA_SENSOR_HUB_16                      ( 0x11 ) 
#define IMU963RA_SENSOR_HUB_17                      ( 0x12 ) 
#define IMU963RA_SENSOR_HUB_18                      ( 0x13 ) 
#define IMU963RA_MASTER_CONFIG                      ( 0x14 ) 
#define IMU963RA_SLV0_ADD                           ( 0x15 ) 
#define IMU963RA_SLV0_SUBADD                        ( 0x16 ) 
#define IMU963RA_SLV0_CONFIG                        ( 0x17 ) 
#define IMU963RA_SLV1_ADD                           ( 0x18 ) 
#define IMU963RA_SLV1_SUBADD                        ( 0x19 ) 
#define IMU963RA_SLV1_CONFIG                        ( 0x1A ) 
#define IMU963RA_SLV2_ADD                           ( 0x1B ) 
#define IMU963RA_SLV2_SUBADD                        ( 0x1C ) 
#define IMU963RA_SLV2_CONFIG                        ( 0x1D ) 
#define IMU963RA_SLV3_ADD                           ( 0x1E ) 
#define IMU963RA_SLV3_SUBADD                        ( 0x1F ) 
#define IMU963RA_SLV3_CONFIG                        ( 0x20 ) 
#define IMU963RA_DATAWRITE_SLV0                     ( 0x21 ) 
#define IMU963RA_STATUS_MASTER                      ( 0x22 )

#define IMU963RA_MAG_ADDR                           ( 0x0D )                    // 7λIIC��ַ
#define IMU963RA_MAG_OUTX_L                         ( 0x00 )
#define IMU963RA_MAG_CONTROL1                       ( 0x09 )
#define IMU963RA_MAG_CONTROL2                       ( 0x0A )
#define IMU963RA_MAG_FBR                            ( 0x0B )
#define IMU963RA_MAG_CHIP_ID                        ( 0x0D )
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴��о� ���ļ������к������� [ ���а����궨�庯�� ] ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ���ٶȼ�����������
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     range                   IMU963RA ���ٶ����� ��� zf_device_imu963ra.h �� imu963ra_acc_range_enum ����
// ����˵��     *physical_data          IMU963RA �����������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_physical_acc(imu963_data_buffer, range, physical_data);
// ��ע��Ϣ     �������̽�������������
//              ���ٶȼ����� ��2  g   ��ȡ���ļ��ٶȼ����ݳ��� (1000.0 / 0.061) ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//              ���ٶȼ����� ��4  g   ��ȡ���ļ��ٶȼ����ݳ��� (1000.0 / 0.122) ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//              ���ٶȼ����� ��8  g   ��ȡ���ļ��ٶȼ����ݳ��� (1000.0 / 0.244) ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//              ���ٶȼ����� ��16 g   ��ȡ���ļ��ٶȼ����ݳ��� (1000.0 / 0.488) ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_physical_acc (imu963ra_measurement_data_struct *measurement_data, imu963ra_acc_range_enum range,imu963ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ����������������
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     range                   IMU963RA ���ٶ����� ��� zf_device_imu963ra.h �� imu963ra_gyro_range_enum ����
// ����˵��     *physical_data          IMU963RA �����������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_physical_gyro(imu963_data_buffer, range, physical_data);
// ��ע��Ϣ     �������̽�������������
//              ���������� ��125  dps    ��ȡ�������������ݳ��� (1000.0 / 4.375)  ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��250  dps    ��ȡ�������������ݳ��� (1000.0 / 8.75 )  ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��500  dps    ��ȡ�������������ݳ��� (1000.0 / 17.5 )  ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��1000 dps    ��ȡ�������������ݳ��� (1000.0 / 35.0 )  ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��2000 dps    ��ȡ�������������ݳ��� (1000.0 / 70.0 )  ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��4000 dps    ��ȡ�������������ݳ��� (1000.0 / 140.0)  ����ת��Ϊ������λ������ ��λΪ ��/s
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_physical_gyro (imu963ra_measurement_data_struct *measurement_data, imu963ra_gyro_range_enum range,imu963ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA �شż�����������
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     range                   IMU963RA ���ٶ����� ��� zf_device_imu963ra.h �� imu963ra_mag_range_enum ����
// ����˵��     *physical_data          IMU963RA �����������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_physical_mag(imu963_data_buffer, range, physical_data);
// ��ע��Ϣ     �������̽�������������
//              �شż����� 2G   ��ȡ���ĵشż����ݳ��� 12000 ����ת��Ϊ������λ������ ��λΪ G(��˹)
//              �شż����� 8G   ��ȡ���ĵشż����ݳ���  3000 ����ת��Ϊ������λ������ ��λΪ G(��˹)
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_physical_mag (imu963ra_measurement_data_struct *measurement_data, imu963ra_mag_range_enum range,imu963ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ���ٶȼ�����
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_acc(imu963_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_acc (imu963ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ����������
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_gyro(imu963_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_gyro (imu963ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA �شż�����
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_mag(imu963_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_mag (imu963ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU963RA ����ģ�鹤������
// ����˵��     item                    IMU963RA ���ò��� zf_device_imu963ra.h �� imu963ra_config_item_enum ö���嶨��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_set_config(item);
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_set_config (imu963ra_config_item_enum item);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ�� IMU963RA
// ����˵��     void
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_init(imu963_data_buffer);
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_init (void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#endif
