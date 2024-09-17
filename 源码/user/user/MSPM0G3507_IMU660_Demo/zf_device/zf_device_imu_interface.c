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
* �ļ�����          zf_device_imu_interface
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MDK 5.38a
* ����ƽ̨          MSPM0G3507
* ��������          https://seekfree.taobao.com/
********************************************************************************************************************/

/*********************************************************************************************************************
* ���ļ��������Ƿ��� IMU ������ƽ̨����
* ����Ϊ�� IMU ��صĽӿڽ��н�������
* ����ֲ���µ�ƽ̨ʱ ֻ��Ҫʵ���˱��ļ��Ľӿ�
* �Ϳ���ֱ������ SeekFree ���е� V4 �� IMU ����
********************************************************************************************************************/

// zf_common ������
#include "zf_common_debug.h"

// ����ͷ�ļ�
#include "zf_device_imu_interface.h"

// �˴����� ���ļ���ʹ�õı��������� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
imu_interface_obj_struct imu_interface_default_obj = 
{
    IMU_INTERFACE_SPI,
    imu_delay_ms,
    imu_assert,
    imu_write_8bit_register,
    imu_write_8bit_registers,
    imu_read_8bit_register,
    imu_read_8bit_registers,
};
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// �˴����� IMU ��صĽӿ�ʵ�� ���ﲻ�����û��޸�
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// �������     IMU ��ʱ
// ����˵��     ms              ������
// ���ز���     void
// ʹ��ʾ��     system_delay_ms(ms);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void imu_delay_ms (uint32 ms)
{
    delay_ms(ms);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU ���Խӿڶ���
// ����˵��     pass            �����ж�����
// ����˵��     *str            ������ЧʱӦ���������Ϣ
// ����˵��     *file           �ļ�·����Ϣ
// ����˵��     line            ��������
// ���ز���     uint8           ZF_NO_ERROR - 0 - ���� /  !ZF_NO_ERROR - !0 - �쳣
// ʹ��ʾ��     imu_assert(pass, str, file, line);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_assert (uint8 pass, char *str, char *file, int line)
{
    return (pass ? ZF_NO_ERROR : debug_message_handler(ZF_DEBUG_OUTPUT_LEVEL_DEVICE, (pass), (str), file, line));
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU SPI ͨ�Žӿ�
// ����˵��     *data_out       �������
// ����˵��     *data_in        ��������
// ����˵��     data_len        ������
// ���ز���     void
// ʹ��ʾ��     spi_transfer_8bit_register(data_out, data_in, data_len);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void spi_transfer_8bit_register (const uint8 *data_out, uint8 *data_in, uint32 data_len)
{
    while(data_len --)
    {
        DL_SPI_transmitData8(IMU_SPI_INDEX, *data_out ++);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        if(NULL != data_in)
        {
            *data_in ++ = DL_SPI_receiveData8(IMU_SPI_INDEX);
            while(DL_SPI_isBusy(IMU_SPI_INDEX));
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU д�Ĵ��� 8bit
// ����˵��     addr            IIC ������ַ �� IIC �������� 0
// ����˵��     reg             �Ĵ�����ַ
// ����˵��     data            ����
// ���ز���     void
// ʹ��ʾ��     imu_write_8bit_register(addr, reg, data);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void imu_write_8bit_register (uint8 addr, uint8 reg, uint8 data)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, data);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    IMU_CS(1);
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    soft_iic_write_8bit_register(IMU_SOFT_IIC_INDEX, addr, reg, data);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    iic_write_8bit_register(IMU_IIC_INDEX, addr, reg, data);
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU д�Ĵ��� 8bit
// ����˵��     addr            IIC ������ַ �� IIC �������� 0
// ����˵��     reg             �Ĵ�����ַ
// ����˵��     data            ���ݻ�����
// ����˵��     len             ���ݳ���
// ���ز���     void
// ʹ��ʾ��     imu_write_8bit_registers(addr, reg, data, len);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void imu_write_8bit_registers (uint8 addr, uint8 reg, const uint8 *data, uint32 len)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    uint32 send = 0;
    while(len > send)
    {
        DL_SPI_transmitData8(IMU_SPI_INDEX, *(data + send));
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        DL_SPI_receiveData8(IMU_SPI_INDEX);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        send ++;
    }
    IMU_CS(1);
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    soft_iic_write_8bit_registers(IMU_SOFT_IIC_INDEX, addr, reg, data, len);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    iic_write_8bit_registers(IMU_IIC_INDEX, addr, reg, data, len);
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU ���Ĵ��� 8bit
// ����˵��     addr            IIC ������ַ �� IIC �������� 0
// ����˵��     reg             �Ĵ�����ַ
// ���ز���     uint8           ����
// ʹ��ʾ��     imu_read_8bit_register(addr, reg);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_read_8bit_register (uint8 addr, uint8 reg)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    uint8 data = 0;
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, 0xFF);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    data = DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    IMU_CS(1);
    return data;
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    return soft_iic_read_8bit_register(IMU_SOFT_IIC_INDEX, addr, reg);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    return iic_read_8bit_register(IMU_IIC_INDEX, addr, reg);
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU ������ 8bit
// ����˵��     addr            IIC ������ַ �� IIC �������� 0
// ����˵��     reg             �Ĵ�����ַ
// ����˵��     data            ���ݻ�����
// ����˵��     len             ���ݳ���
// ���ز���     void
// ʹ��ʾ��     imu_read_8bit_registers(addr, reg, data, len);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void imu_read_8bit_registers (uint8 addr, uint8 reg, uint8 *data, uint32 len)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    uint32 read = 0;
    while(len > read)
    {
        DL_SPI_transmitData8(IMU_SPI_INDEX, 0xFF);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        *(data + read) = DL_SPI_receiveData8(IMU_SPI_INDEX);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        
        read ++;
    }
    IMU_CS(1);
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    soft_iic_read_8bit_registers(IMU_SOFT_IIC_INDEX, addr, reg, data, len);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    iic_read_8bit_registers(IMU_IIC_INDEX, addr, reg, data, len);
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU �ӿ�ע����ʼ��
// ����˵��     void
// ���ز���     uint8           0-�ɹ� 1-ʧ��
// ʹ��ʾ��     imu_interface_deinit(addr);
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_interface_deinit (void)
{
    uint8 return_state = 1;
    do
    {
        return_state = 0;
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU �ӿڳ�ʼ�� �ڲ�����
// ����˵��     void
// ���ز���     uint8           0-�ɹ� 1-ʧ��
// ʹ��ʾ��     imu_interface_init();
// ��ע��Ϣ     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_interface_init (void)
{
    uint8 return_state = 1;
    do
    {
        return_state = 0;
    }while(0);
    return return_state;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
