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
*                   AO[x]               查看 zf_device_tsl1401.h 中 TSL1401_AO_PINx 宏定义
*                   VCC                 3.3V电源
*                   GND                 电源地
*                   ------------------------------------
********************************************************************************************************************/

#ifndef _zf_device_tsl1401_h_
#define _zf_device_tsl1401_h_

#include "zf_common_typedef.h"

#include "board.h"
#include "ti_msp_dl_config.h"

#define TSL1401_AO_ADC_INDEX    ( ADC_FOR_CCD_INST )
#define TSL1401_AO1_PIN         ( ADC_FOR_CCD_ADCMEM_ADC_CCD1 )
#define TSL1401_AO2_PIN         ( ADC_FOR_CCD_ADCMEM_ADC_CCD2 )

// TSL1401 的控制引脚定义 多个 TSL1401 建议将控制引脚直接并联
#define TSL1401_CLK_PORT        ( CCD_CLK_PORT )
#define TSL1401_CLK_PIN         ( CCD_CLK_PIN_24_PIN )
#define TSL1401_SI_PORT         ( CCD_SI_PORT )
#define TSL1401_SI_PIN          ( CCD_SI_PIN_25_PIN )
#define TSL1401_CLK(x)          ((x) ? (DL_GPIO_setPins(TSL1401_CLK_PORT, TSL1401_CLK_PIN)): (DL_GPIO_clearPins(TSL1401_CLK_PORT, TSL1401_CLK_PIN)))
#define TSL1401_SI(x)           ((x) ? (DL_GPIO_setPins(TSL1401_SI_PORT, TSL1401_SI_PIN)): (DL_GPIO_clearPins(TSL1401_SI_PORT, TSL1401_SI_PIN)))

typedef enum                                                                    // 枚举 调试输出类型 此定义不允许用户修改
{
    TSL1401_IMAGE_SEND_1    = 0 ,
    TSL1401_IMAGE_SEND_2        ,
    TSL1401_IMAGE_SEND_ALL      ,
}tsl1401_image_send_enum;


#define TSL1401_DATA_LEN        (128 )                                          // TSL1401 数据长度

extern uint16 tsl1401_data[2][TSL1401_DATA_LEN];                                // TSL1401 数据存放数组
extern uint8 tsl1401_finish_flag;                                               // TSL1401 数据采集完成标志

void tsl1401_collect_pit_handler    (void);
void tsl1401_send_data              (UART_Regs *uart_n, tsl1401_image_send_enum send_type);
void tsl1401_init                   (void);

#endif
