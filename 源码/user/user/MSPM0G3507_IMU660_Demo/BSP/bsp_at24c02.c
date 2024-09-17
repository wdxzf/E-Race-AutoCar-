/*
 * ������������Ӳ�������������չ����Ӳ�����Ϲ���ȫ����Դ
 * �����������www.lckfb.com
 * ����֧�ֳ�פ��̳���κμ������⻶ӭ��ʱ����ѧϰ
 * ������̳��https://oshwhub.com/forum
 * ��עbilibili�˺ţ������������塿���������ǵ����¶�̬��
 * ��������׬Ǯ���������й�����ʦΪ����
 * Change Logs:
 * Date           Author       Notes
 * 2024-07-08     LCKFB-LP    first version
 */


#include "bsp_at24c02.h"
#include "stdio.h"

// SLAVE ADDRESS+WΪ0xA0��SLAVE ADDRESS+RΪ0xA1
#define AT24C02_ADDRESS_READ                0xA0
#define AT24C02_ADDRESS_WRITE               0xA1



/******************************************************************
 * �� �� �� �ƣ�IIC_Start
 * �� �� ˵ ����IIC��ʼʱ��
 * �� �� �� �Σ���
 * �� �� �� �أ���
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
void IIC_Start(void)
{
        SDA_OUT();
        
        SDA(1);
        delay_us(5);
        SCL(1); 
        delay_us(5);
        
        SDA(0);
        delay_us(5);
        SCL(0);
        delay_us(5);
                       
}
/******************************************************************
 * �� �� �� �ƣ�IIC_Stop
 * �� �� ˵ ����IICֹͣ�ź�
 * �� �� �� �Σ���
 * �� �� �� �أ���
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
void IIC_Stop(void)
{
        SDA_OUT();
        SCL(0);
        SDA(0);
        
        SCL(1);
        delay_us(5);
        SDA(1);
        delay_us(5);
        
}

/******************************************************************
 * �� �� �� �ƣ�IIC_Send_Ack
 * �� �� ˵ ������������Ӧ����߷�Ӧ���ź�
 * �� �� �� �Σ�0����Ӧ��  1���ͷ�Ӧ��
 * �� �� �� �أ���
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
void IIC_Send_Ack(unsigned char ack)
{
        SDA_OUT();
        SCL(0);
        SDA(0);
        delay_us(5);
        if(!ack) SDA(0);
        else     SDA(1);
        SCL(1);
        delay_us(5);
        SCL(0);
        SDA(1);
}


/******************************************************************
 * �� �� �� �ƣ�I2C_WaitAck
 * �� �� ˵ �����ȴ��ӻ�Ӧ��
 * �� �� �� �Σ���
 * �� �� �� �أ�0��Ӧ��  1��ʱ��Ӧ��
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
unsigned char I2C_WaitAck(void)
{
        
    char ack = 0;
    unsigned char ack_flag = 10;
    SCL(0);
    SDA(1);
    SDA_IN();
    delay_us(5);
    SCL(1);
    delay_us(5);

    while( (SDA_GET()==1) && ( ack_flag ) )
    {
        ack_flag--;
        delay_us(5);
    }
    
    if( ack_flag <= 0 )
    {
        IIC_Stop();
        return 1;
    }
    else
    {
        SCL(0);
        SDA_OUT();
    }
    return ack;
}

/******************************************************************
 * �� �� �� �ƣ�Send_Byte
 * �� �� ˵ ����д��һ���ֽ�
 * �� �� �� �Σ�datҪд�˵�����
 * �� �� �� �أ���
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
void Send_Byte(uint8_t dat)
{
    int i = 0;
    SDA_OUT();
    SCL(0);//����ʱ�ӿ�ʼ���ݴ���
    
    for( i = 0; i < 8; i++ )
    {
        SDA( (dat & 0x80) >> 7 );
        delay_us(1);
        SCL(1);
        delay_us(5);
        SCL(0);
        delay_us(5);
        dat<<=1;
    }        
}

/******************************************************************
 * �� �� �� �ƣ�Read_Byte
 * �� �� ˵ ����IIC��ʱ��
 * �� �� �� �Σ���
 * �� �� �� �أ�����������
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
unsigned char Read_Byte(void)
{
	unsigned char i,receive=0;

	SDA_IN();//SDA����Ϊ����

	for(i=0;i<8;i++ )
	{
		SCL(0);
		delay_us(5);
		SCL(1);
		delay_us(5);
		receive<<=1;
		if( SDA_GET() )
		{        
			receive|=1;   
		}
		delay_us(5); 
	}

	SCL(0); 

	return receive;
}


 
 

/******************************************************************
 * �� �� �� �ƣ�AT24C02_WriteByte
 * �� �� ˵ ����AT24C02д��һ���ֽ�
 * �� �� �� �Σ�WordAddress Ҫд���ֽڵĵ�ַ  Data Ҫд�������
 * �� �� �� �أ���
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
void AT24C02_WriteByte(unsigned char WordAddress,unsigned char Data)
{
        IIC_Start();
        Send_Byte(AT24C02_ADDRESS_READ);
        I2C_WaitAck();
        Send_Byte(WordAddress);
        I2C_WaitAck();
        Send_Byte(Data);
        I2C_WaitAck();
        IIC_Stop();
}

/******************************************************************
 * �� �� �� �ƣ�AT24C02_ReadByte
 * �� �� ˵ ����AT24C02��ȡһ���ֽ�
 * �� �� �� �Σ�WordAddress Ҫ�����ֽڵĵ�ַ
 * �� �� �� �أ�����������
 * ��       �ߣ�LC
 * ��       ע����
******************************************************************/
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
        unsigned char Data;
        IIC_Start();
        Send_Byte(AT24C02_ADDRESS_READ);
        I2C_WaitAck();
        Send_Byte(WordAddress);
        I2C_WaitAck();
        IIC_Start();
        Send_Byte(AT24C02_ADDRESS_WRITE);
        I2C_WaitAck();
        Data=Read_Byte();
        IIC_Send_Ack(1);
        IIC_Stop();
        return Data;
}
