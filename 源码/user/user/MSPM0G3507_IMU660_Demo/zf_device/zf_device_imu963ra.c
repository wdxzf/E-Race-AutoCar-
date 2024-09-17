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

// zf_device ��ͷ�ļ�����

#include "zf_device_imu_interface.h"

// ����ͷ�ļ�
#include "zf_device_imu963ra.h"

// �˴����� ���ļ������к������嶨�� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// �������     IMU963RA ��Ϊ IIC �����������д����
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ����˵��     addr                    Ŀ���ַ
// ����˵��     reg                     Ŀ��Ĵ���
// ����˵��     data                    ����
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_write_mag_register(interface, addr, reg, data);
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_write_mag_register (imu_interface_obj_struct *interface, uint8 addr, uint8 reg, uint8 data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    uint16 timeout_count = 0;
    do{
        addr = addr << 1;
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_CONFIG   , 0x00      ); // �ӻ�0�������
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_ADD      , addr | 0  ); // ���õشżƵ�ַ��ע��������Ҫ����8λ��I2C��ַ�� 0x2C
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_SUBADD   , reg       ); // ��Ҫд��ļĴ�����ַ
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_DATAWRITE_SLV0, data      ); // ��Ҫд�������
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG , 0x4C      ); // ���ڵ�һ����������ͨѶ �������� I2C����ʹ��

        // �ȴ�ͨѶ�ɹ�
        while(!(0x80 & interface->read_8bit_register(
            IMU963RA_DEV_ADDR, 
                (IMU_INTERFACE_SPI == interface->interface_type)
                ? (IMU963RA_STATUS_MASTER | IMU963RA_SPI_R)
                : IMU963RA_STATUS_MASTER)))
        {
            if(IMU963RA_TIMEOUT_COUNT < timeout_count ++)
            {
                return_state = IMU963RA_STATE_MAG_WRITE_RIGESTER_ERROR;
                break;
            }
            interface->delay_ms(2);
        }
    }while(0);
    return return_state;
}


//-------------------------------------------------------------------------------------------------------------------
// �������     IMU963RA ��Ϊ IIC ����������ƶ�����
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ����˵��     addr                    Ŀ���ַ
// ����˵��     reg                     Ŀ��Ĵ���
// ����˵��     *data                   ����ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_read_mag_register(IMU963RA_MAG_ADDR, IMU963RA_MAG_CHIP_ID);
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_read_mag_register (imu_interface_obj_struct *interface, uint8 addr, uint8 reg, uint8 *data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    uint16              timeout_count = 0;

    do{
        addr = addr << 1;
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_ADD,        addr | 1);  // ���õشżƵ�ַ��ע��������Ҫ����8λ��I2C��ַ�� 0x2C
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_SUBADD,     reg);       // ��Ҫ��ȡ�ļĴ�����ַ
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_CONFIG,     0x01);    
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG,   0x4C);      // ���ڵ�һ����������ͨѶ �������� I2C����ʹ��
        
        // �ȴ�ͨѶ�ɹ�
        while(!(0x01 & interface->read_8bit_register(
            IMU963RA_DEV_ADDR, 
                (IMU_INTERFACE_SPI == interface->interface_type)
                ? (IMU963RA_STATUS_MASTER | IMU963RA_SPI_R)
                : IMU963RA_STATUS_MASTER)))
        {
            if(IMU963RA_TIMEOUT_COUNT < timeout_count ++)
            {
                return_state = IMU963RA_STATE_MAG_WRITE_RIGESTER_ERROR;
                break;
            }
            interface->delay_ms(2);
        }

        *data = interface->read_8bit_register(
            IMU963RA_DEV_ADDR, 
                (IMU_INTERFACE_SPI == interface->interface_type)
                ? (IMU963RA_SENSOR_HUB_1 | IMU963RA_SPI_R)
                : IMU963RA_SENSOR_HUB_1);
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ���ٶȼ����� ��չ�ӿ�
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_expansion_get_acc(interface, data_buffer);
// ��ע��Ϣ     ���ӿ�Ϊ��������ܽӿ� ����ֱ�Ӷ��û�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_expansion_get_acc (imu_interface_obj_struct *interface, imu963ra_measurement_data_struct *measurement_data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    do{
        if( interface->assert(
                NULL != measurement_data,                                       // ������ָ�� ����Ϊ��
                "*measurement_data error.",                                     // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        uint8 data[6];
        interface->read_8bit_registers(
            IMU963RA_DEV_ADDR, 
                (IMU_INTERFACE_SPI == interface->interface_type)
                ?   (IMU963RA_OUTX_L_A | IMU963RA_SPI_R)
                :   IMU963RA_OUTX_L_A,
            data, 6);
        measurement_data->x = (int16)(((uint16)data[1] << 8 | data[0]));
        measurement_data->y = (int16)(((uint16)data[3] << 8 | data[2]));
        measurement_data->z = (int16)(((uint16)data[5] << 8 | data[4]));
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ���������� ��չ�ӿ�
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_expansion_get_gyro(interface, data_buffer);
// ��ע��Ϣ     ���ӿ�Ϊ��������ܽӿ� ����ֱ�Ӷ��û�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_expansion_get_gyro (imu_interface_obj_struct *interface, imu963ra_measurement_data_struct *measurement_data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    do{
        if( interface->assert(
                NULL != measurement_data,                                       // ������ָ�� ����Ϊ��
                "*measurement_data error.",                                     // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        uint8 data[6];
        interface->read_8bit_registers(
            IMU963RA_DEV_ADDR, 
                (IMU_INTERFACE_SPI == interface->interface_type)
                ?   (IMU963RA_OUTX_L_G | IMU963RA_SPI_R)
                :   IMU963RA_OUTX_L_G,
            data, 6);
        measurement_data->x = (int16)(((uint16)data[1] << 8 | data[0]));
        measurement_data->y = (int16)(((uint16)data[3] << 8 | data[2]));
        measurement_data->z = (int16)(((uint16)data[5] << 8 | data[4]));
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA �شż����� ��չ�ӿ�
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_expansion_get_mag(interface, data_buffer);
// ��ע��Ϣ     ���ӿ�Ϊ��������ܽӿ� ����ֱ�Ӷ��û�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_expansion_get_mag (imu_interface_obj_struct *interface, imu963ra_measurement_data_struct *measurement_data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    uint16 timeout_count = 0;
    do{
        if( interface->assert(
                NULL != measurement_data,                                       // ������ָ�� ����Ϊ��
                "*measurement_data error.",                                     // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        uint8 data[6];
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x40);
        do
        {
            if(0x01 & interface->read_8bit_register(
                IMU963RA_DEV_ADDR, 
                    (IMU_INTERFACE_SPI == interface->interface_type)
                    ? (IMU963RA_STATUS_MASTER | IMU963RA_SPI_R)
                    : IMU963RA_STATUS_MASTER))
            {
                interface->read_8bit_registers(
                    IMU963RA_DEV_ADDR, 
                        (IMU_INTERFACE_SPI == interface->interface_type)
                        ?   (IMU963RA_SENSOR_HUB_1 | IMU963RA_SPI_R)
                        :   IMU963RA_SENSOR_HUB_1,
                    data, 6);
                measurement_data->x = (int16)(((uint16)data[1] << 8 | data[0]));
                measurement_data->y = (int16)(((uint16)data[3] << 8 | data[2]));
                measurement_data->z = (int16)(((uint16)data[5] << 8 | data[4]));
                break;
            }
            interface->delay_ms(2);
        }while(IMU963RA_TIMEOUT_COUNT < timeout_count ++);
        if(IMU963RA_TIMEOUT_COUNT < timeout_count)
        {
            return_state = IMU963RA_STATE_ID_CHECK_ERROR;
        }
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU963RA ����ģ�鹤������ ��չ�ӿ�
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ����˵��     item                    IMU963RA ���ò��� zf_device_imu963ra.h �� imu963ra_config_item_enum ö���嶨��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_expansion_set_config(interface, interface);
// ��ע��Ϣ     ���ӿ�Ϊ��������ܽӿ� ����ֱ�Ӷ��û�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_expansion_set_config (imu_interface_obj_struct *interface, imu963ra_config_item_enum item)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    uint8               register_temp   = 0;
    do{
        switch((item >> IMU963RA_CONFIG_TYPE_OFFSET) & IMU963RA_CONFIG_TYPE_MASK)
        {
            case 0x00:
            {
                if( interface->assert(
                            IMU963RA_ACC_OUTPUT_RATE_4_DIV      <= (item & 0x0F)
                        &&  IMU963RA_ACC_OUTPUT_RATE_128_MUL    >= (item & 0x0F),
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_ACC_OUTPUT_RATE_ERROR;
                    break;
                }
                register_temp = interface->read_8bit_register(
                IMU963RA_DEV_ADDR, 
                    (IMU_INTERFACE_SPI == interface->interface_type)
                    ? (IMU963RA_CTRL1_XL | IMU963RA_SPI_R)
                    : IMU963RA_CTRL1_XL);
                register_temp = ((register_temp & ~0xF0) |(((item & 0x0F) - 5) << 4));
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL1_XL, register_temp);
            }break;
            case 0x01:
            {
                if( interface->assert(
                            IMU963RA_ACC_RANGE_SGN_2G <= (item & 0x0F)
                        &&  IMU963RA_ACC_RANGE_SGN_16G >= (item & 0x0F),
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_ACC_RANGE_ERROR;
                    break;
                }
                register_temp = interface->read_8bit_register(
                IMU963RA_DEV_ADDR, 
                    (IMU_INTERFACE_SPI == interface->interface_type)
                    ? (IMU963RA_CTRL1_XL | IMU963RA_SPI_R)
                    : IMU963RA_CTRL1_XL);
                const uint8 acc_range_list[6] = {0x00, 0x00, 0x00, 0x08, 0x0C, 0x04};
                register_temp = ((register_temp & ~0x0C) | acc_range_list[(item & 0x0F)]);
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL1_XL, register_temp);
            }break;
            case 0x02:
            {
                if( interface->assert(
                            IMU963RA_GYRO_OUTPUT_RATE_4_DIV     <= (item & 0x0F)
                        &&  IMU963RA_GYRO_OUTPUT_RATE_128_MUL   >= (item & 0x0F),
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_GYRO_OUTPUT_RATE_ERROR;
                    break;
                }
                register_temp = interface->read_8bit_register(
                IMU963RA_DEV_ADDR, 
                    (IMU_INTERFACE_SPI == interface->interface_type)
                    ? (IMU963RA_CTRL2_G | IMU963RA_SPI_R)
                    : IMU963RA_CTRL2_G);
                register_temp = ((register_temp & ~0xF0) |(((item & 0x0F) - 5) << 4));
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL2_G, register_temp);
            }break;
            case 0x03:
            {
                if( interface->assert(
                            IMU963RA_GYRO_RANGE_SGN_125DPS  <= (item & 0x0F)
                        &&  IMU963RA_GYRO_RANGE_SGN_4000DPS >= (item & 0x0F),
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_GYRO_RANGE_ERROR;
                    break;
                }
                register_temp = interface->read_8bit_register(
                IMU963RA_DEV_ADDR, 
                    (IMU_INTERFACE_SPI == interface->interface_type)
                    ? (IMU963RA_CTRL2_G | IMU963RA_SPI_R)
                    : IMU963RA_CTRL2_G);
                const uint8 gyro_range_list[8] = {0x00, 0x00, 0x02, 0x00, 0x04, 0x08, 0x0C, 0x01};
                register_temp = ((register_temp & ~0x0F) | gyro_range_list[(item & 0x0F)]);
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL2_G, register_temp);
            }break;
            case 0x04:
            {
                if( interface->assert(
                            IMU963RA_MAG_OUTPUT_RATE_4_DIV  <= (item & 0x0F)
                        &&  IMU963RA_MAG_OUTPUT_RATE_4_MUL  >= (item & 0x0F),
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_MAG_OUTPUT_RATE_ERROR;
                    break;
                }
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x40);
                do
                {
                    imu963ra_read_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL1, &register_temp);
                    register_temp = (register_temp & ~0x0C)
                        | (((item & 0x0F) == IMU963RA_MAG_OUTPUT_RATE_4_DIV) ? (0) : (((item & 0x0F) - 7) << 2));
                    imu963ra_write_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL1, register_temp | 0x01);

                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_ADD, (IMU963RA_MAG_ADDR << 1) | 1); // ���õشżƵ�ַ��ע��������Ҫ����8λ��I2C��ַ�� 0x2C
                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_SUBADD, IMU963RA_MAG_OUTX_L);       // ��Ҫ��ȡ�ļĴ�����ַ
                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_CONFIG, 0x06);    
                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG, 0x6C);                    // ���ڵ�һ����������ͨѶ �������� I2C����ʹ��
                }while(0);
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
            }break;
            case 0x05:
            {
                if( interface->assert(
                            IMU963RA_MAG_RANGE_2G   <= (item & 0x0F)
                        &&  IMU963RA_MAG_RANGE_8G   >= (item & 0x0F),
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_MAG_RANGE_ERROR;
                    break;
                }
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x40);
                do
                {
                    imu963ra_read_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL1, &register_temp);
                    register_temp = (register_temp & ~0x30) | (((item & 0x0F) - 2) << 4);
                    imu963ra_write_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL1, register_temp | 0x01);

                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_ADD, (IMU963RA_MAG_ADDR << 1) | 1); // ���õشżƵ�ַ��ע��������Ҫ����8λ��I2C��ַ�� 0x2C
                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_SUBADD, IMU963RA_MAG_OUTX_L);       // ��Ҫ��ȡ�ļĴ�����ַ
                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_CONFIG, 0x06);    
                    interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG, 0x6C);                    // ���ڵ�һ����������ͨѶ �������� I2C����ʹ��
                }while(0);
                interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
            }break;
            default:
            {
                if( interface->assert(
                        0,
                        "item set error.",                                      // ���Ԥ�豨����Ϣ
                        ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
                {
                    return_state = IMU963RA_STATE_SET_CONFIG_ERROR;
                    break;
                }
            }break;
        }
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU963RA ���� ��� ID �Ƿ�ƥ�� ��չ�ӿ�
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_expansion_ckeck_id(interface);
// ��ע��Ϣ     ���ӿ�Ϊ��������ܽӿ� ����ֱ�Ӷ��û�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_expansion_ckeck_id (imu_interface_obj_struct *interface)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    uint8 data = 0;
    uint16 timeout_count = 0;

    do
    {
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL3_C, 0x01);               // ��λ�豸
        interface->delay_ms(2);                             
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
        do
        {
            if(IMU963RA_TIMEOUT_COUNT < timeout_count ++)
            {
                return_state = IMU963RA_STATE_ID_CHECK_ERROR;
                break;
            }
            data = interface->read_8bit_register(
                IMU963RA_DEV_ADDR, 
                    (IMU_INTERFACE_SPI == interface->interface_type)
                    ? (IMU963RA_WHO_AM_I | IMU963RA_SPI_R)
                    : IMU963RA_WHO_AM_I);
            interface->delay_ms(10);
        }while(0x6B != data);

        // ����Ҫ�� ���ٶȼ� �� �شż� ����һ������������� �������ᴦ�� power-down ģʽ���ܸ��شż�ͨ��
        // interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL1_XL, 0x10);
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL2_G,  0x10);

        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x40);
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG, 0x80);         // ��λI2C����
        interface->delay_ms(2);
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG, 0x00);         // �����λ��־
        interface->delay_ms(2);
        imu963ra_write_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL2, 0x80);// ��λ���ӵ�����
        interface->delay_ms(2);
        imu963ra_write_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL2, 0x00);
        interface->delay_ms(2);

        data = 0;
        imu963ra_read_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CHIP_ID, &data);
        if(0xff != data)
        {
            return_state = IMU963RA_STATE_ID_CHECK_ERROR;
        }
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ�� IMU963RA ��չ�ӿ�
// ����˵��     *interface              IMU963RA ��ͨ�Žӿڶ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_expansion_init(interface);
// ��ע��Ϣ     ���ӿ�Ϊ��������ܽӿ� ����ֱ�Ӷ��û�����
//-------------------------------------------------------------------------------------------------------------------
static imu963ra_state_enum imu963ra_expansion_init (imu_interface_obj_struct *interface)
{
    imu963ra_state_enum return_state    = IMU963RA_STATE_NO_ERROR;
    uint8               register_temp   = 0;
    do{
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_INT1_CTRL, 0x03);    // ���������� ���ٶ����ݾ����ж�

        if( interface->assert(
                    IMU963RA_ACC_OUTPUT_RATE_4_DIV      <= IMU963RA_ACC_OUTPUT_RATE_DEFAULT
                &&  IMU963RA_ACC_OUTPUT_RATE_128_MUL    >= IMU963RA_ACC_OUTPUT_RATE_DEFAULT,
                "IMU963RA_ACC_OUTPUT_RATE_DEFAULT set error.",                  // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_ACC_OUTPUT_RATE_ERROR;
            break;
        }
        register_temp = ((IMU963RA_ACC_OUTPUT_RATE_DEFAULT - 5) << 4);
        if( interface->assert(
                    IMU963RA_ACC_RANGE_SGN_2G   <= IMU963RA_ACC_RANGE_DEFAULT
                &&  IMU963RA_ACC_RANGE_SGN_16G  >= IMU963RA_ACC_RANGE_DEFAULT,
                "IMU963RA_ACC_RANGE_DEFAULT set error.",                  // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_ACC_RANGE_ERROR;
            break;
        }
        const uint8 acc_range_list[6] = {0x00, 0x00, 0x00, 0x08, 0x0C, 0x04};
        register_temp |= acc_range_list[IMU963RA_ACC_RANGE_DEFAULT];
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL1_XL, register_temp);

        if( interface->assert(
                    IMU963RA_GYRO_OUTPUT_RATE_4_DIV     <= IMU963RA_GYRO_OUTPUT_RATE_DEFAULT
                &&  IMU963RA_GYRO_OUTPUT_RATE_128_MUL   >= IMU963RA_GYRO_OUTPUT_RATE_DEFAULT,
                "IMU963RA_GYRO_OUTPUT_RATE_DEFAULT set error.",                  // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_GYRO_OUTPUT_RATE_ERROR;
            break;
        }
        register_temp = ((IMU963RA_GYRO_OUTPUT_RATE_DEFAULT - 5) << 4);
        if( interface->assert(
                    IMU963RA_GYRO_RANGE_SGN_125DPS  <= IMU963RA_GYRO_RANGE_DEFAULT
                &&  IMU963RA_GYRO_RANGE_SGN_4000DPS >= IMU963RA_GYRO_RANGE_DEFAULT,
                "IMU963RA_GYRO_RANGE_DEFAULT set error.",                  // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_GYRO_RANGE_ERROR;
            break;
        }
        const uint8 gyro_range_list[8] = {0x00, 0x00, 0x02, 0x00, 0x04, 0x08, 0x0C, 0x01};
        register_temp |= gyro_range_list[IMU963RA_GYRO_RANGE_DEFAULT];
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL2_G, register_temp);

        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL3_C, 0x44);               // ʹ�����������ֵ�ͨ�˲���
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL4_C, 0x02);               // ʹ�����ֵ�ͨ�˲���
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL5_C, 0x00);               // ���ٶȼ�����������������
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL6_C, 0x00);               // �������ٶȼƸ�����ģʽ �����ǵ�ͨ�˲� 133hz
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL7_G, 0x00);               // ���������Ǹ�����ģʽ �رո�ͨ�˲�
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_CTRL9_XL, 0x01);              // �ر�I3C�ӿ�

        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x40);
        do
        {
            if( interface->assert(
                        IMU963RA_MAG_OUTPUT_RATE_4_DIV  <= IMU963RA_MAG_OUTPUT_RATE_DEFAULT
                    &&  IMU963RA_MAG_OUTPUT_RATE_4_MUL  >= IMU963RA_MAG_OUTPUT_RATE_DEFAULT,
                    "IMU963RA_MAG_OUTPUT_RATE_DEFAULT set error.",                  // ���Ԥ�豨����Ϣ
                    ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
            {
                return_state = IMU963RA_STATE_SET_MAG_OUTPUT_RATE_ERROR;
                break;
            }
            register_temp =
                    (IMU963RA_MAG_OUTPUT_RATE_DEFAULT == IMU963RA_MAG_OUTPUT_RATE_4_DIV)
                ?   (0)
                :   (IMU963RA_MAG_OUTPUT_RATE_DEFAULT - 7);
            register_temp = (register_temp << 2);
            if( interface->assert(
                        IMU963RA_MAG_RANGE_2G   <= IMU963RA_MAG_RANGE_DEFAULT
                    &&  IMU963RA_MAG_RANGE_8G   >= IMU963RA_MAG_RANGE_DEFAULT,
                    "IMU963RA_MAG_RANGE_DEFAULT set error.",                  // ���Ԥ�豨����Ϣ
                    ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
            {
                return_state = IMU963RA_STATE_SET_MAG_RANGE_ERROR;
                break;
            }
            register_temp |= ((IMU963RA_MAG_RANGE_DEFAULT - 2) << 4);
            imu963ra_write_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_CONTROL1, register_temp | 0x01);
            imu963ra_write_mag_register(interface, IMU963RA_MAG_ADDR, IMU963RA_MAG_FBR, 0x01);

            interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_ADD, (IMU963RA_MAG_ADDR << 1) | 1); // ���õشżƵ�ַ��ע��������Ҫ����8λ��I2C��ַ�� 0x2C
            interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_SUBADD, IMU963RA_MAG_OUTX_L);       // ��Ҫ��ȡ�ļĴ�����ַ
            interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_SLV0_CONFIG, 0x06);    
            interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_MASTER_CONFIG, 0x6C);                    // ���ڵ�һ����������ͨѶ �������� I2C����ʹ��
        }while(0);
        interface->write_8bit_register(IMU963RA_DEV_ADDR, IMU963RA_FUNC_CFG_ACCESS, 0x00);
    }while(0);
    return return_state;
}

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
imu963ra_state_enum imu963ra_get_physical_acc (imu963ra_measurement_data_struct *measurement_data, imu963ra_acc_range_enum range,imu963ra_physical_data_struct *physical_data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    do{
        if( imu_assert(
                NULL != measurement_data,                                       // ������ָ�� ����Ϊ��
                "*measurement_data error.",                                     // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        if( imu_assert(
                    IMU963RA_ACC_RANGE_SGN_2G   <= range
                &&  IMU963RA_ACC_RANGE_SGN_16G  >= range,
                "range error.",                                                 // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_ACC_RANGE_ERROR;
            break;
        }
        if( imu_assert(
                NULL != physical_data,                                          // ������ָ�� ����Ϊ��
                "*physical_data error.",                                        // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        const float transition_factor[4] = {1000.0 / 0.061, 1000.0 / 0.122, 1000.0 / 0.244, 1000.0 / 0.488};
        physical_data->x  = (float)measurement_data->x / transition_factor[range - IMU963RA_ACC_RANGE_SGN_2G];
        physical_data->y  = (float)measurement_data->y / transition_factor[range - IMU963RA_ACC_RANGE_SGN_2G];
        physical_data->z  = (float)measurement_data->z / transition_factor[range - IMU963RA_ACC_RANGE_SGN_2G];
    }while(0);
    return return_state;
}

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
imu963ra_state_enum imu963ra_get_physical_gyro (imu963ra_measurement_data_struct *measurement_data, imu963ra_gyro_range_enum range,imu963ra_physical_data_struct *physical_data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    do{
        if( imu_assert(
                NULL != measurement_data,                                       // ������ָ�� ����Ϊ��
                "*measurement_data error.",                                     // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        if( imu_assert(
                    IMU963RA_GYRO_RANGE_SGN_125DPS  <= range
                &&  IMU963RA_GYRO_RANGE_SGN_4000DPS >= range,
                "range error.",                                                 // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_GYRO_RANGE_ERROR;
            break;
        }
        if( imu_assert(
                NULL != physical_data,                                          // ������ָ�� ����Ϊ��
                "*physical_data error.",                                        // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        const float transition_factor[6] = 
        {
            1000.0 / 4.375, 1000.0 / 8.75,  1000.0 / 17.5,
            1000.0 / 35.0,  1000.0 / 70.0,  1000.0 / 140.0,
        };
        physical_data->x  = (float)measurement_data->x / transition_factor[range - IMU963RA_GYRO_RANGE_SGN_125DPS];
        physical_data->y  = (float)measurement_data->y / transition_factor[range - IMU963RA_GYRO_RANGE_SGN_125DPS];
        physical_data->z  = (float)measurement_data->z / transition_factor[range - IMU963RA_GYRO_RANGE_SGN_125DPS];
    }while(0);
    return return_state;
}

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
imu963ra_state_enum imu963ra_get_physical_mag (imu963ra_measurement_data_struct *measurement_data, imu963ra_mag_range_enum range,imu963ra_physical_data_struct *physical_data)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    do{
        if( imu_assert(
                NULL != measurement_data,                                       // ������ָ�� ����Ϊ��
                "*measurement_data error.",                                     // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        if( imu_assert(
                    IMU963RA_MAG_RANGE_2G   <= range
                &&  IMU963RA_MAG_RANGE_8G   >= range,
                "range error.",                                                 // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_SET_MAG_RANGE_ERROR;
            break;
        }
        if( imu_assert(
                NULL != physical_data,                                          // ������ָ�� ����Ϊ��
                "*physical_data error.",                                        // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_DATA_BUFFER_ERROR;
            break;
        }
        const float transition_factor[2] = {12000, 3000};
        physical_data->x  = (float)measurement_data->x / transition_factor[range - IMU963RA_MAG_RANGE_2G];
        physical_data->y  = (float)measurement_data->y / transition_factor[range - IMU963RA_MAG_RANGE_2G];
        physical_data->z  = (float)measurement_data->z / transition_factor[range - IMU963RA_MAG_RANGE_2G];
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ���ٶȼ�����
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_acc(imu963_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_acc (imu963ra_measurement_data_struct *measurement_data)
{
    return imu963ra_expansion_get_acc(&imu_interface_default_obj, measurement_data);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA ����������
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_gyro(imu963_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_gyro (imu963ra_measurement_data_struct *measurement_data)
{
    return imu963ra_expansion_get_gyro(&imu_interface_default_obj, measurement_data);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU963RA �شż�����
// ����˵��     *measurement_data       IMU963RA �Ĳ������ݻ���ָ��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_get_mag(imu963_data_buffer);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_get_mag (imu963ra_measurement_data_struct *measurement_data)
{
    return imu963ra_expansion_get_mag(&imu_interface_default_obj, measurement_data);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU963RA ����ģ�鹤������
// ����˵��     item                    IMU963RA ���ò��� zf_device_imu963ra.h �� imu963ra_config_item_enum ö���嶨��
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_set_config(item);
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_set_config (imu963ra_config_item_enum item)
{
    return imu963ra_expansion_set_config(&imu_interface_default_obj, item);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ�� IMU963RA
// ����˵��     void
// ���ز���     imu963ra_state_enum     IMU963RA ״̬�� ��� zf_device_imu963ra.h �� imu963ra_state_enum ����
// ʹ��ʾ��     imu963ra_init(imu963_data_buffer);
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
imu963ra_state_enum imu963ra_init (void)
{
    imu963ra_state_enum return_state = IMU963RA_STATE_NO_ERROR;
    imu_delay_ms(20);                                                           // �ȴ��豸�ϵ�ɹ�
    do{
        if( imu_assert(
                !imu_interface_init(),                                          // ���û���쳣 ��ô�ӿڳ�ʼ������Ϊ 0
                "IMU interface init error.",                                    // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            return_state = IMU963RA_STATE_INTERFACE_INIT_ERROR;
            break;
        }

        if( imu_assert(
                !imu963ra_expansion_ckeck_id(&imu_interface_default_obj),       // IMU963RA �Լ� ���û���쳣 ��ô�ӿڳ�ʼ������Ϊ 0
                "imu963ra self check error.",                                   // ���Ԥ�豨����Ϣ
                ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
        {
            // �������������˶�����Ϣ ������ʾ����λ��������
            // ��ô���� IMU963RA �Լ������ʱ�˳���
            // ���һ�½�����û������ ���û������ܾ��ǻ���
            return_state = IMU963RA_STATE_SELF_CHECK_ERROR;
            break;
        }

        return_state = imu963ra_expansion_init(&imu_interface_default_obj);
    }while(0);
    if(return_state)
    {
        imu_interface_deinit();
    }
    return return_state;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
