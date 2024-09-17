/*********************************************************************************************************************
* MSPM0G3507 Opensourec Library 即（MSPM0G3507 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
* 
* 本文件是 MSPM0G3507 开源库的一部分
* 
* MSPM0G3507 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
* 
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
* 
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
* 
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
* 
* 文件名称          zf_device_tsl1401
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK 5.38a
* 适用平台          MSPM0G3507
* 店铺链接          https://seekfree.taobao.com/
* 
* 修改记录
* 日期              作者                备注
* 2022-08-10        Teternal            first version
********************************************************************************************************************/
/*********************************************************************************************************************
* 接线定义：
*                   ------------------------------------
*                   模块管脚            单片机管脚
*                   CLK                 查看 zf_device_tsl1401.h 中 TSL1401_CLK_PIN 宏定义
*                   SI                  查看 zf_device_tsl1401.h 中 TSL1401_SI_PIN 宏定义
*                   AO[x]               查看 zf_device_tsl1401.h 中 TSL1401_AO_PIN_BUFFER 宏定义
*                   VCC                 3.3V电源
*                   GND                 电源地
*                   ------------------------------------
********************************************************************************************************************/

#include "zf_device_tsl1401.h"

uint16 tsl1401_data[2][TSL1401_DATA_LEN];                                       // TSL1401 数据存放数组

static uint8 tsl1401_init_state = 0;
uint8 tsl1401_finish_flag;                                                      // TSL1401 数据准备就绪标志位

void ccd_soft_delay (volatile long tick)
{
    while(tick --);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     TSL1401 线阵 TSL1401 数据采集
// 参数说明     void
// 返回参数     void
// 使用示例     tsl1401_collect_pit_handler();
// 备注信息     该函数在 isr.c 中对应 TSL1401_PIT_INDEX 的中断服务函数调用
//-------------------------------------------------------------------------------------------------------------------
void tsl1401_collect_pit_handler (void)
{
    uint8 i = 0;

    TSL1401_CLK(1);
    ccd_soft_delay(10);
    TSL1401_SI(0);
    ccd_soft_delay(10);
    TSL1401_CLK(0);
    ccd_soft_delay(10);
    TSL1401_SI(1);
    ccd_soft_delay(10);
    TSL1401_CLK(1);
    ccd_soft_delay(10);
    TSL1401_SI(0);
    ccd_soft_delay(10);

    for(i = 0; i < TSL1401_DATA_LEN; i ++)
    {
        TSL1401_CLK(0);
        DL_ADC12_startConversion(TSL1401_AO_ADC_INDEX);
        while(DL_ADC12_IIDX_MEM1_RESULT_LOADED != DL_ADC12_getPendingInterrupt(TSL1401_AO_ADC_INDEX));
        tsl1401_data[0][i] = DL_ADC12_getMemResult(TSL1401_AO_ADC_INDEX, TSL1401_AO1_PIN);
        tsl1401_data[1][i] = DL_ADC12_getMemResult(TSL1401_AO_ADC_INDEX, TSL1401_AO2_PIN);
        TSL1401_CLK(1);
        ccd_soft_delay(10);
    }
    //采集完成标志位置1
    tsl1401_finish_flag = 1;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     TSL1401 线阵 CCD 图像发送至上位机查看图像
// 参数说明     uart_n          串口号
// 参数说明     index           对应接入的哪个 TSL1401 [0-1]
// 返回参数     void
// 使用示例     tsl1401_send_data(DEBUG_UART_INDEX, 1);
// 备注信息     调用该函数前请先初始化串口
//-------------------------------------------------------------------------------------------------------------------
void tsl1401_send_data (UART_Regs *uart_n, tsl1401_image_send_enum send_type)
{
    uint32 loop_temp = 0;
    uint8 send_data = 127;
    
    uint8 image_send_const[8] = {0xAA, 0x02, 0x51, 0x08, 128, 0, 0, 1};
    if(TSL1401_IMAGE_SEND_ALL == send_type)
    {
        image_send_const[2] = 0x53;
    }
    
    loop_temp = 0;
    while(8 > loop_temp)
    {
        while(DL_UART_isBusy(uart_n) == true);
        DL_UART_Main_transmitData(uart_n, image_send_const[loop_temp ++]);
    }

    uint8 image_send_head[4] = {0xAA, 0x03, 0x41, 0x08};
    if(TSL1401_IMAGE_SEND_ALL == send_type)
    {
        image_send_head[2] = 0x43;
    }
    
    loop_temp = 0;
    while(4 > loop_temp)
    {
        while(DL_UART_isBusy(uart_n) == true);
        DL_UART_Main_transmitData(uart_n, image_send_head[loop_temp ++]);
    }
    
    switch(send_type)
    {
        case TSL1401_IMAGE_SEND_1:
        {
            uint8 image_send_data_head[3];
            image_send_data_head[0] = 128;
            image_send_data_head[1] = 0;
            image_send_data_head[2] = 1;
            
            loop_temp = 0;
            while(3 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, image_send_data_head[loop_temp ++]);
            }

            loop_temp = 0;
            while(128 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, 255 - (tsl1401_data[0][loop_temp ++] >> 4));
            }
        }break;
        case TSL1401_IMAGE_SEND_2:
        {
            uint8 image_send_data_head[3];
            image_send_data_head[0] = 128;
            image_send_data_head[1] = 0;
            image_send_data_head[2] = 1;
            
            loop_temp = 0;
            while(3 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, image_send_data_head[loop_temp ++]);
            }

            loop_temp = 0;
            while(128 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, 255 - (tsl1401_data[1][loop_temp ++] >> 4));
            }
        }break;
        case TSL1401_IMAGE_SEND_ALL:
        {
            uint8 image_send_data_head[3];
            image_send_data_head[0] = 128;
            image_send_data_head[1] = 0;
            image_send_data_head[2] = 7;
            
            loop_temp = 0;
            while(3 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, image_send_data_head[loop_temp ++]);
            }

            loop_temp = 0;
            while(128 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, 127 - (tsl1401_data[0][loop_temp ++] >> 5));
            }
            
            loop_temp = 0;
            while(128 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, 127);
                loop_temp ++;
            }
            
            loop_temp = 0;
            while(128 > loop_temp)
            {
                while(DL_UART_isBusy(uart_n) == true);
                DL_UART_Main_transmitData(uart_n, 255 - (tsl1401_data[1][loop_temp ++] >> 5));
            }
        }break;
    }
    
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     TSL1401 线阵 TSL1401 初始化
// 参数说明     void
// 返回参数     void
// 使用示例     tsl1401_init();
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
void tsl1401_init (void)     
{
    NVIC_EnableIRQ(PIT_FOR_CCD_INST_INT_IRQN);
    DL_TimerG_startCounter(PIT_FOR_CCD_INST);
}


void PIT_FOR_CCD_INST_IRQHandler(void)
{
            tsl1401_collect_pit_handler();
    switch( DL_TimerG_getPendingInterrupt(PIT_FOR_CCD_INST) )
    {
        case DL_TIMER_IIDX_LOAD:
            break;
        default://其他的定时器中断
            break;
    }
}
