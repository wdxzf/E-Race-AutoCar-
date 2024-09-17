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
* �ļ�����          zf_device_imu660ra
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MDK 5.38a
* ����ƽ̨          MSPM0G3507
* ��������          https://seekfree.taobao.com/
********************************************************************************************************************/

/*********************************************************************************************************************
* ���߶���          �鿴 zf_device_imu_interface.h �нӿ���Դ����
********************************************************************************************************************/

#ifndef _zf_device_imu660ra_h_
#define _zf_device_imu660ra_h_

// zf_common �� ���Ͷ��� ����
#include "zf_common_typedef.h"


// �˴��о� ��ǰ֧�ֵĺ����б�
// ���������ڱ������в鿴��Ӧע�� ���嶨����ת����Ӧ��������鿴
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// imu660ra_get_physical_acc                                                    // ��ȡ IMU660RA ���ٶȼ�����������
// imu660ra_get_physical_gyro                                                   // ��ȡ IMU660RA ����������������

// imu660ra_get_acc                                                             // ��ȡ IMU660RA ���ٶȼ�����
// imu660ra_get_gyro                                                            // ��ȡ IMU660RA ����������

// imu660ra_set_config                                                          // IMU660RA ����ģ�鹤������
// imu660ra_init                                                                // ��ʼ�� IMU660RA
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴����� IMU660RA ��صĽṹ�����ݹ���ϸ�� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// IMU660RA_ACC_OUTPUT_RATE_BASE ��ӦĬ�ϵ� IMU660RA �ļ��ٶȼ��������Ƶ�� ʵ��Ϊ 50Hz
// ʵ�ʻ�����ƫ�� ��Ҫȥ�鿴��Ӧ��оƬ�ֲ� ��˶�Ӧ�ӵ͵��߿�������Ϊ
// IMU660RA_ACC_OUTPUT_RATE_64_DIV      ->  0.78    Hz
// IMU660RA_ACC_OUTPUT_RATE_32_DIV      ->  1.5     Hz
// IMU660RA_ACC_OUTPUT_RATE_16_DIV      ->  3.1     Hz
// IMU660RA_ACC_OUTPUT_RATE_8_DIV       ->  6.25    Hz
// IMU660RA_ACC_OUTPUT_RATE_4_DIV       ->  12.5    Hz
// IMU660RA_ACC_OUTPUT_RATE_2_DIV       ->  25      Hz
// IMU660RA_ACC_OUTPUT_RATE_BASE        ->  50      Hz
// IMU660RA_ACC_OUTPUT_RATE_2_MUL       ->  100     Hz
// IMU660RA_ACC_OUTPUT_RATE_4_MUL       ->  200     Hz
// IMU660RA_ACC_OUTPUT_RATE_8_MUL       ->  400     Hz
// IMU660RA_ACC_OUTPUT_RATE_16_MUL      ->  800     Hz
// IMU660RA_ACC_OUTPUT_RATE_32_MUL      ->  1600    Hz
typedef enum
{
    IMU660RA_ACC_OUTPUT_RATE_64_DIV = 2 ,                                       // ���ٶȼ����Ƶ�� 64 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_32_DIV     ,                                       // ���ٶȼ����Ƶ�� 32 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_16_DIV     ,                                       // ���ٶȼ����Ƶ�� 16 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_8_DIV      ,                                       // ���ٶȼ����Ƶ�� 8  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_4_DIV      ,                                       // ���ٶȼ����Ƶ�� 4  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_2_DIV      ,                                       // ���ٶȼ����Ƶ�� 2  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_BASE       ,                                       // ���ٶȼ����Ƶ�ʻ���Ƶ�� (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_2_MUL      ,                                       // ���ٶȼ����Ƶ�� 2  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_4_MUL      ,                                       // ���ٶȼ����Ƶ�� 4  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_8_MUL      ,                                       // ���ٶȼ����Ƶ�� 8  ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_16_MUL     ,                                       // ���ٶȼ����Ƶ�� 16 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
    IMU660RA_ACC_OUTPUT_RATE_32_MUL     ,                                       // ���ٶȼ����Ƶ�� 32 ��Ƶ (ACC = Accelerometer ���ٶȼ�)
}imu660ra_acc_output_rate_enum;

typedef enum
{
    IMU660RA_ACC_RANGE_SGN_2G       = 2 ,                                       // ���ٶȼ����� ��2 g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
    IMU660RA_ACC_RANGE_SGN_4G           ,                                       // ���ٶȼ����� ��4 g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
    IMU660RA_ACC_RANGE_SGN_8G           ,                                       // ���ٶȼ����� ��8 g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
    IMU660RA_ACC_RANGE_SGN_16G          ,                                       // ���ٶȼ����� ��16g (ACC = Accelerometer ���ٶȼ�) (SGN = signum �������� ��ʾ������Χ) (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
}imu660ra_acc_range_enum;

// IMU660RA_GYRO_OUTPUT_RATE_BASE ��ӦĬ�ϵ� IMU660RA ���������������Ƶ�� ʵ��Ϊ 50Hz
// ʵ�ʻ�����ƫ�� ��Ҫȥ�鿴��Ӧ��оƬ�ֲ� ��˶�Ӧ�ӵ͵��߿�������Ϊ
// IMU660RA_GYRO_OUTPUT_RATE_2_DIV      -> 25       Hz
// IMU660RA_GYRO_OUTPUT_RATE_BASE       -> 50       Hz
// IMU660RA_GYRO_OUTPUT_RATE_2_MUL      -> 100      Hz
// IMU660RA_GYRO_OUTPUT_RATE_4_MUL      -> 200      Hz
// IMU660RA_GYRO_OUTPUT_RATE_8_MUL      -> 400      Hz
// IMU660RA_GYRO_OUTPUT_RATE_16_MUL     -> 800      Hz
// IMU660RA_GYRO_OUTPUT_RATE_32_MUL     -> 1600     Hz
// IMU660RA_GYRO_OUTPUT_RATE_64_MUL     -> 3200     Hz
typedef enum
{
    IMU660RA_GYRO_OUTPUT_RATE_2_DIV = 7 ,                                       // ���������Ƶ�� 2  ��Ƶ (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_BASE      ,                                       // ���������Ƶ�ʻ���Ƶ�� (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_2_MUL     ,                                       // ���������Ƶ�� 2  ��Ƶ (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_4_MUL     ,                                       // ���������Ƶ�� 4  ��Ƶ (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_8_MUL     ,                                       // ���������Ƶ�� 8  ��Ƶ (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_16_MUL    ,                                       // ���������Ƶ�� 16 ��Ƶ (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_32_MUL    ,                                       // ���������Ƶ�� 32 ��Ƶ (GYRO = Gyroscope ������)
    IMU660RA_GYRO_OUTPUT_RATE_64_MUL    ,                                       // ���������Ƶ�� 64 ��Ƶ (GYRO = Gyroscope ������)
}imu660ra_gyro_output_rate_enum;

typedef enum
{
    IMU660RA_GYRO_RANGE_SGN_125DPS  = 2 ,                                       // ���������� ��125DPS  (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU660RA_GYRO_RANGE_SGN_250DPS      ,                                       // ���������� ��250DPS  (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU660RA_GYRO_RANGE_SGN_500DPS      ,                                       // ���������� ��500DPS  (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU660RA_GYRO_RANGE_SGN_1000DPS     ,                                       // ���������� ��1000DPS (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
    IMU660RA_GYRO_RANGE_SGN_2000DPS     ,                                       // ���������� ��2000DPS (GYRO = Gyroscope ������) (SGN = signum �������� ��ʾ������Χ) (DPS = Degree Per Second ���ٶȵ�λ ��/S)
}imu660ra_gyro_range_enum;

#define IMU660RA_TIMEOUT_COUNT              ( 10 )                              // IMU660RA ��ʱ����

#define IMU660RA_ACC_OUTPUT_RATE_DEFAULT    ( IMU660RA_ACC_OUTPUT_RATE_BASE   ) // ��������Ĭ�ϵ� ���ٶȼ�  ��ʼ�����Ƶ��
#define IMU660RA_ACC_RANGE_DEFAULT          ( IMU660RA_ACC_RANGE_SGN_8G       ) // ��������Ĭ�ϵ� ���ٶȼ�  ��ʼ������
#define IMU660RA_GYRO_OUTPUT_RATE_DEFAULT   ( IMU660RA_GYRO_OUTPUT_RATE_4_MUL ) // ��������Ĭ�ϵ� ������    ��ʼ�����Ƶ��
#define IMU660RA_GYRO_RANGE_DEFAULT         ( IMU660RA_GYRO_RANGE_SGN_2000DPS ) // ��������Ĭ�ϵ� ������    ��ʼ������

#define IMU660RA_CONFIG_TYPE_OFFSET         ( 4     )                           // �ۼƵ�λ��λ�ƺ�� 16bit ��ʼ
#define IMU660RA_CONFIG_TYPE_MASK           ( 0x0F  )                           // ͬ��������Ҫ��ӵ����ŷ��ù������� ����Ҳ�� 4bit �������Ϊ 0xF

#define IMU660RA_CONFIG_VALUE_OFFSET        ( 0     )                           // �ۼƵ�λ��λ�ƺ�� 16bit ��ʼ
#define IMU660RA_CONFIG_VALUE_MASK          ( 0x0F  )                           // ͬ��������Ҫ��ӵ����ŷ��ù������� ����Ҳ�� 4bit �������Ϊ 0xF

typedef enum                                                                    // ö�� IMU660RA ����ѡ�� ��ö�ٶ��岻�����û��޸�
{
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_64_DIV          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_64_DIV) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_32_DIV          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_32_DIV) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_16_DIV          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_16_DIV) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_8_DIV           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_8_DIV ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_4_DIV           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_4_DIV ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_2_DIV           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_2_DIV ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_BASE            = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_BASE  ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_2_MUL           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_2_MUL ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_4_MUL           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_4_MUL ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_8_MUL           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_8_MUL ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_16_MUL          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_16_MUL) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_32_MUL          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_32_MUL) ,

    IMU660RA_CONFIG_ACC_RANGE_SGN_2G                = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_2G    )   ,
    IMU660RA_CONFIG_ACC_RANGE_SGN_4G                = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_4G    )   ,
    IMU660RA_CONFIG_ACC_RANGE_SGN_8G                = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_8G    )   ,
    IMU660RA_CONFIG_ACC_RANGE_SGN_16G               = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_16G   )   ,

    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_2_DIV          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_2_DIV ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_BASE           = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_BASE  ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_2_MUL          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_2_MUL ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_4_MUL          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_4_MUL ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_8_MUL          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_8_MUL ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_16_MUL         = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_16_MUL),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_32_MUL         = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_32_MUL),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_64_MUL         = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_64_MUL),

    IMU660RA_CONFIG_GYRO_RANGE_SGN_125DPS           = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_125DPS ) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_250DPS           = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_250DPS ) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_500DPS           = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_500DPS ) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_1000DPS          = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_1000DPS) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_2000DPS          = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_2000DPS) ,
}imu660ra_config_item_enum;

typedef enum
{
    IMU660RA_INTERFACE_SPI      ,
    IMU660RA_INTERFACE_SOFT_IIC ,
    IMU660RA_INTERFACE_IIC      ,
}imu660ra_interface_type_enum;

typedef enum
{
    IMU660RA_STATE_NO_ERROR                     ,

    IMU660RA_STATE_DATA_BUFFER_ERROR            ,
    IMU660RA_STATE_INTERFACE_INIT_ERROR         ,
    IMU660RA_STATE_ID_CHECK_ERROR               ,
    IMU660RA_STATE_SELF_CHECK_ERROR             ,
    IMU660RA_STATE_SET_CONFIG_ERROR             ,
    IMU660RA_STATE_SET_ACC_OUTPUT_RATE_ERROR    ,
    IMU660RA_STATE_SET_ACC_RANGE_ERROR          ,
    IMU660RA_STATE_SET_GYRO_OUTPUT_RATE_ERROR   ,
    IMU660RA_STATE_SET_GYRO_RANGE_ERROR         ,
}imu660ra_state_enum;

typedef struct                                                                  // IMU660RA ���ݸ�ʽģ�� ���ڴ洢 IMU660RA ������
{
    int16       x   ;                                                           // X ���ԭʼ����
    int16       y   ;                                                           // Y ���ԭʼ����
    int16       z   ;                                                           // Z ���ԭʼ����
}imu660ra_measurement_data_struct;

typedef struct                                                                  // IMU660RA ���ݸ�ʽģ�� ���ڴ洢 IMU660RA ������
{
    float       x   ;                                                           // X �������������
    float       y   ;                                                           // Y �������������
    float       z   ;                                                           // Z �������������
}imu660ra_physical_data_struct;
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴����� IMU660RA ����������ڲ����� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���� IMU660RA �ڲ���ַ
#define IMU660RA_DEV_ADDR           ( 0x69 )                                    // 7bit ��ַ��ʽ SA0�ӵأ�0x68 SA0������0x69 ģ��Ĭ������
#define IMU660RA_SPI_W              ( 0x00 )
#define IMU660RA_SPI_R              ( 0x80 )

#define IMU660RA_CHIP_ID            ( 0x00 )
#define IMU660RA_PWR_CONF           ( 0x7C )
#define IMU660RA_PWR_CTRL           ( 0x7D )
#define IMU660RA_INIT_CTRL          ( 0x59 )
#define IMU660RA_INIT_DATA          ( 0x5E )
#define IMU660RA_INT_STA            ( 0x21 )
#define IMU660RA_ACC_ADDRESS        ( 0x0C )
#define IMU660RA_GYRO_ADDRESS       ( 0x12 )
#define IMU660RA_ACC_CONF           ( 0x40 )
#define IMU660RA_ACC_RANGE          ( 0x41 )
#define IMU660RA_GYR_CONF           ( 0x42 )
#define IMU660RA_GYR_RANGE          ( 0x43 )
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴��о� ���ļ������к������� [ ���а����궨�庯�� ] ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU660RA ���ٶȼ�����������
// ����˵��     *measurement_data       IMU660RA �Ĳ������ݻ���ָ��
// ���ز���     range                   IMU660RA ���ٶ����� ��� zf_device_imu660ra.h �� imu660ra_acc_range_enum ����
// ����˵��     *physical_data          IMU660RA �����������ݻ���ָ��
// ���ز���     imu660ra_state_enum     IMU660RA ״̬�� ��� zf_device_imu660ra.h �� imu660ra_state_enum ����
// ʹ��ʾ��     imu660ra_get_physical_acc(imu660_data_buffer, range, physical_data);
// ��ע��Ϣ     �������̽�������������
//              ���ٶȼ����� ��2  g   ��ȡ���ļ��ٶȼ����ݳ��� 16384  ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//              ���ٶȼ����� ��4  g   ��ȡ���ļ��ٶȼ����ݳ��� 8192   ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//              ���ٶȼ����� ��8  g   ��ȡ���ļ��ٶȼ����ݳ��� 4096   ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//              ���ٶȼ����� ��16 g   ��ȡ���ļ��ٶȼ����ݳ��� 2048   ����ת��Ϊ������λ������ (g �����������ٶ� ����ѧ���� һ������� g ȡ 9.8 m/s^2 Ϊ��׼ֵ)
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_physical_acc (imu660ra_measurement_data_struct *measurement_data, imu660ra_acc_range_enum range,imu660ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU660RA ����������������
// ����˵��     *measurement_data       IMU660RA �Ĳ������ݻ���ָ��
// ���ز���     range                   IMU660RA ���ٶ����� ��� zf_device_imu660ra.h �� imu660ra_gyro_range_enum ����
// ����˵��     *physical_data          IMU660RA �����������ݻ���ָ��
// ���ز���     imu660ra_state_enum     IMU660RA ״̬�� ��� zf_device_imu660ra.h �� imu660ra_state_enum ����
// ʹ��ʾ��     imu660ra_get_physical_gyro(imu660_data_buffer, range, physical_data);
// ��ע��Ϣ     �������̽�������������
//              ���������� ��125  dps    ��ȡ�������������ݳ��� 262.4   ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��250  dps    ��ȡ�������������ݳ��� 131.2   ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��500  dps    ��ȡ�������������ݳ��� 65.6    ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��1000 dps    ��ȡ�������������ݳ��� 32.8    ����ת��Ϊ������λ������ ��λΪ ��/s
//              ���������� ��2000 dps    ��ȡ�������������ݳ��� 16.4    ����ת��Ϊ������λ������ ��λΪ ��/s
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_physical_gyro (imu660ra_measurement_data_struct *measurement_data, imu660ra_gyro_range_enum range,imu660ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU660RA ���ٶȼ�����
// ����˵��     *measurement_data       IMU660RA �Ĳ������ݻ���ָ��
// ���ز���     imu660ra_state_enum     IMU660RA ״̬�� ��� zf_device_imu660ra.h �� imu660ra_state_enum ����
// ʹ��ʾ��     imu660ra_get_acc(imu660_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_acc (imu660ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU660RA ����������
// ����˵��     *measurement_data       IMU660RA �Ĳ������ݻ���ָ��
// ���ز���     imu660ra_state_enum     IMU660RA ״̬�� ��� zf_device_imu660ra.h �� imu660ra_state_enum ����
// ʹ��ʾ��     imu660ra_get_gyro(imu660_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_gyro (imu660ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU660RA ����ģ�鹤������
// ����˵��     item                    IMU660RA ���ò��� zf_device_imu660ra.h �� imu660ra_config_item_enum ö���嶨��
// ���ز���     imu660ra_state_enum     IMU660RA ״̬�� ��� zf_device_imu660ra.h �� imu660ra_state_enum ����
// ʹ��ʾ��     imu660ra_set_config(item);
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_set_config (imu660ra_config_item_enum item);

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ�� IMU660RA
// ����˵��     void
// ���ز���     imu660ra_state_enum     IMU660RA ״̬�� ��� zf_device_imu660ra.h �� imu660ra_state_enum ����
// ʹ��ʾ��     imu660ra_init(imu660_data_buffer);
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_init (void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

extern imu660ra_measurement_data_struct acc_data, gyro_data;
#endif

