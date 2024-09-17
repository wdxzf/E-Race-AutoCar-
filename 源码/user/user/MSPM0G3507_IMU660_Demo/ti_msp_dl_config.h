/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_Motor */
#define PWM_Motor_INST                                                    TIMG12
#define PWM_Motor_INST_IRQHandler                              TIMG12_IRQHandler
#define PWM_Motor_INST_INT_IRQN                                (TIMG12_INT_IRQn)
#define PWM_Motor_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Motor_C0_PORT                                             GPIOB
#define GPIO_PWM_Motor_C0_PIN                                     DL_GPIO_PIN_13
#define GPIO_PWM_Motor_C0_IOMUX                                  (IOMUX_PINCM30)
#define GPIO_PWM_Motor_C0_IOMUX_FUNC                IOMUX_PINCM30_PF_TIMG12_CCP0
#define GPIO_PWM_Motor_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Motor_C1_PORT                                             GPIOA
#define GPIO_PWM_Motor_C1_PIN                                     DL_GPIO_PIN_25
#define GPIO_PWM_Motor_C1_IOMUX                                  (IOMUX_PINCM55)
#define GPIO_PWM_Motor_C1_IOMUX_FUNC                IOMUX_PINCM55_PF_TIMG12_CCP1
#define GPIO_PWM_Motor_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (39999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_4_MHZ_115200_BAUD                                        (2)
#define UART_0_FBRD_4_MHZ_115200_BAUD                                       (11)




/* Defines for SPI_FOR_IMU */
#define SPI_FOR_IMU_INST                                                   SPI0
#define SPI_FOR_IMU_INST_IRQHandler                             SPI0_IRQHandler
#define SPI_FOR_IMU_INST_INT_IRQN                                 SPI0_INT_IRQn
#define GPIO_SPI_FOR_IMU_PICO_PORT                                        GPIOA
#define GPIO_SPI_FOR_IMU_PICO_PIN                                 DL_GPIO_PIN_9
#define GPIO_SPI_FOR_IMU_IOMUX_PICO                             (IOMUX_PINCM20)
#define GPIO_SPI_FOR_IMU_IOMUX_PICO_FUNC             IOMUX_PINCM20_PF_SPI0_PICO
#define GPIO_SPI_FOR_IMU_POCI_PORT                                        GPIOA
#define GPIO_SPI_FOR_IMU_POCI_PIN                                DL_GPIO_PIN_13
#define GPIO_SPI_FOR_IMU_IOMUX_POCI                             (IOMUX_PINCM35)
#define GPIO_SPI_FOR_IMU_IOMUX_POCI_FUNC             IOMUX_PINCM35_PF_SPI0_POCI
/* GPIO configuration for SPI_FOR_IMU */
#define GPIO_SPI_FOR_IMU_SCLK_PORT                                        GPIOA
#define GPIO_SPI_FOR_IMU_SCLK_PIN                                DL_GPIO_PIN_12
#define GPIO_SPI_FOR_IMU_IOMUX_SCLK                             (IOMUX_PINCM34)
#define GPIO_SPI_FOR_IMU_IOMUX_SCLK_FUNC             IOMUX_PINCM34_PF_SPI0_SCLK
#define GPIO_SPI_FOR_IMU_CS0_PORT                                         GPIOA
#define GPIO_SPI_FOR_IMU_CS0_PIN                                  DL_GPIO_PIN_2
#define GPIO_SPI_FOR_IMU_IOMUX_CS0                               (IOMUX_PINCM7)
#define GPIO_SPI_FOR_IMU_IOMUX_CS0_FUNC                IOMUX_PINCM7_PF_SPI0_CS0



/* Port definition for Pin Group SPI_FOR_IMU_CS */
#define SPI_FOR_IMU_CS_PORT                                              (GPIOA)

/* Defines for PIN_8: GPIOA.8 with pinCMx 19 on package pin 54 */
#define SPI_FOR_IMU_CS_PIN_8_PIN                                 (DL_GPIO_PIN_8)
#define SPI_FOR_IMU_CS_PIN_8_IOMUX                               (IOMUX_PINCM19)
/* Port definition for Pin Group PROTA */
#define PROTA_PORT                                                       (GPIOA)

/* Defines for BEEP: GPIOA.27 with pinCMx 60 on package pin 31 */
#define PROTA_BEEP_PIN                                          (DL_GPIO_PIN_27)
#define PROTA_BEEP_IOMUX                                         (IOMUX_PINCM60)
/* Defines for key1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_key1_PORT                                                    (GPIOB)
// pins affected by this interrupt request:["key1"]
#define KEY_INT_IRQN                                            (GPIOB_INT_IRQn)
#define KEY_INT_IIDX                            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define KEY_key1_IIDX                                       (DL_GPIO_IIDX_DIO21)
#define KEY_key1_PIN                                            (DL_GPIO_PIN_21)
#define KEY_key1_IOMUX                                           (IOMUX_PINCM49)
/* Defines for key2: GPIOA.18 with pinCMx 40 on package pin 11 */
#define KEY_key2_PORT                                                    (GPIOA)
#define KEY_key2_PIN                                            (DL_GPIO_PIN_18)
#define KEY_key2_IOMUX                                           (IOMUX_PINCM40)
/* Defines for key3: GPIOB.8 with pinCMx 25 on package pin 60 */
#define KEY_key3_PORT                                                    (GPIOB)
#define KEY_key3_PIN                                             (DL_GPIO_PIN_8)
#define KEY_key3_IOMUX                                           (IOMUX_PINCM25)
/* Defines for key4: GPIOB.9 with pinCMx 26 on package pin 61 */
#define KEY_key4_PORT                                                    (GPIOB)
#define KEY_key4_PIN                                             (DL_GPIO_PIN_9)
#define KEY_key4_IOMUX                                           (IOMUX_PINCM26)
/* Defines for key5: GPIOB.11 with pinCMx 28 on package pin 63 */
#define KEY_key5_PORT                                                    (GPIOB)
#define KEY_key5_PIN                                            (DL_GPIO_PIN_11)
#define KEY_key5_IOMUX                                           (IOMUX_PINCM28)
/* Defines for key6: GPIOB.20 with pinCMx 48 on package pin 19 */
#define KEY_key6_PORT                                                    (GPIOB)
#define KEY_key6_PIN                                            (DL_GPIO_PIN_20)
#define KEY_key6_IOMUX                                           (IOMUX_PINCM48)
/* Defines for key7: GPIOA.28 with pinCMx 3 on package pin 35 */
#define KEY_key7_PORT                                                    (GPIOA)
#define KEY_key7_PIN                                            (DL_GPIO_PIN_28)
#define KEY_key7_IOMUX                                            (IOMUX_PINCM3)
/* Defines for key8: GPIOA.31 with pinCMx 6 on package pin 39 */
#define KEY_key8_PORT                                                    (GPIOA)
#define KEY_key8_PIN                                            (DL_GPIO_PIN_31)
#define KEY_key8_IOMUX                                            (IOMUX_PINCM6)
/* Port definition for Pin Group Motor */
#define Motor_PORT                                                       (GPIOB)

/* Defines for L2: GPIOB.12 with pinCMx 29 on package pin 64 */
#define Motor_L2_PIN                                            (DL_GPIO_PIN_12)
#define Motor_L2_IOMUX                                           (IOMUX_PINCM29)
/* Defines for L1: GPIOB.17 with pinCMx 43 on package pin 14 */
#define Motor_L1_PIN                                            (DL_GPIO_PIN_17)
#define Motor_L1_IOMUX                                           (IOMUX_PINCM43)
/* Defines for R1: GPIOB.0 with pinCMx 12 on package pin 47 */
#define Motor_R1_PIN                                             (DL_GPIO_PIN_0)
#define Motor_R1_IOMUX                                           (IOMUX_PINCM12)
/* Defines for R2: GPIOB.7 with pinCMx 24 on package pin 59 */
#define Motor_R2_PIN                                             (DL_GPIO_PIN_7)
#define Motor_R2_IOMUX                                           (IOMUX_PINCM24)
/* Defines for Gray_0: GPIOB.2 with pinCMx 15 on package pin 50 */
#define Gray_Gray_0_PORT                                                 (GPIOB)
#define Gray_Gray_0_PIN                                          (DL_GPIO_PIN_2)
#define Gray_Gray_0_IOMUX                                        (IOMUX_PINCM15)
/* Defines for Gray_1: GPIOB.18 with pinCMx 44 on package pin 15 */
#define Gray_Gray_1_PORT                                                 (GPIOB)
#define Gray_Gray_1_PIN                                         (DL_GPIO_PIN_18)
#define Gray_Gray_1_IOMUX                                        (IOMUX_PINCM44)
/* Defines for Gray_2: GPIOA.7 with pinCMx 14 on package pin 49 */
#define Gray_Gray_2_PORT                                                 (GPIOA)
#define Gray_Gray_2_PIN                                          (DL_GPIO_PIN_7)
#define Gray_Gray_2_IOMUX                                        (IOMUX_PINCM14)
/* Defines for Gray_3: GPIOA.14 with pinCMx 36 on package pin 7 */
#define Gray_Gray_3_PORT                                                 (GPIOA)
#define Gray_Gray_3_PIN                                         (DL_GPIO_PIN_14)
#define Gray_Gray_3_IOMUX                                        (IOMUX_PINCM36)
/* Defines for Gray_4: GPIOB.19 with pinCMx 45 on package pin 16 */
#define Gray_Gray_4_PORT                                                 (GPIOB)
#define Gray_Gray_4_PIN                                         (DL_GPIO_PIN_19)
#define Gray_Gray_4_IOMUX                                        (IOMUX_PINCM45)
/* Defines for Gray_5: GPIOB.3 with pinCMx 16 on package pin 51 */
#define Gray_Gray_5_PORT                                                 (GPIOB)
#define Gray_Gray_5_PIN                                          (DL_GPIO_PIN_3)
#define Gray_Gray_5_IOMUX                                        (IOMUX_PINCM16)
/* Defines for Gray_6: GPIOB.24 with pinCMx 52 on package pin 23 */
#define Gray_Gray_6_PORT                                                 (GPIOB)
#define Gray_Gray_6_PIN                                         (DL_GPIO_PIN_24)
#define Gray_Gray_6_IOMUX                                        (IOMUX_PINCM52)
/* Defines for Gray_7: GPIOA.26 with pinCMx 59 on package pin 30 */
#define Gray_Gray_7_PORT                                                 (GPIOA)
#define Gray_Gray_7_PIN                                         (DL_GPIO_PIN_26)
#define Gray_Gray_7_IOMUX                                        (IOMUX_PINCM59)
/* Defines for Gray_8: GPIOB.15 with pinCMx 32 on package pin 3 */
#define Gray_Gray_8_PORT                                                 (GPIOB)
#define Gray_Gray_8_PIN                                         (DL_GPIO_PIN_15)
#define Gray_Gray_8_IOMUX                                        (IOMUX_PINCM32)
/* Defines for Gray_9: GPIOB.16 with pinCMx 33 on package pin 4 */
#define Gray_Gray_9_PORT                                                 (GPIOB)
#define Gray_Gray_9_PIN                                         (DL_GPIO_PIN_16)
#define Gray_Gray_9_IOMUX                                        (IOMUX_PINCM33)
/* Defines for Gray_10: GPIOB.4 with pinCMx 17 on package pin 52 */
#define Gray_Gray_10_PORT                                                (GPIOB)
#define Gray_Gray_10_PIN                                         (DL_GPIO_PIN_4)
#define Gray_Gray_10_IOMUX                                       (IOMUX_PINCM17)
/* Defines for Gray_11: GPIOA.24 with pinCMx 54 on package pin 25 */
#define Gray_Gray_11_PORT                                                (GPIOA)
#define Gray_Gray_11_PIN                                        (DL_GPIO_PIN_24)
#define Gray_Gray_11_IOMUX                                       (IOMUX_PINCM54)
/* Defines for led_r: GPIOA.0 with pinCMx 1 on package pin 33 */
#define LED_led_r_PORT                                                   (GPIOA)
#define LED_led_r_PIN                                            (DL_GPIO_PIN_0)
#define LED_led_r_IOMUX                                           (IOMUX_PINCM1)
/* Defines for RGB_R: GPIOB.26 with pinCMx 57 on package pin 28 */
#define LED_RGB_R_PORT                                                   (GPIOB)
#define LED_RGB_R_PIN                                           (DL_GPIO_PIN_26)
#define LED_RGB_R_IOMUX                                          (IOMUX_PINCM57)
/* Defines for RGB_G: GPIOB.27 with pinCMx 58 on package pin 29 */
#define LED_RGB_G_PORT                                                   (GPIOB)
#define LED_RGB_G_PIN                                           (DL_GPIO_PIN_27)
#define LED_RGB_G_IOMUX                                          (IOMUX_PINCM58)
/* Defines for RGB_B: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LED_RGB_B_PORT                                                   (GPIOB)
#define LED_RGB_B_PIN                                           (DL_GPIO_PIN_22)
#define LED_RGB_B_IOMUX                                          (IOMUX_PINCM50)
/* Port definition for Pin Group ENCODERB */
#define ENCODERB_PORT                                                    (GPIOA)

/* Defines for ELB: GPIOA.22 with pinCMx 47 on package pin 18 */
// pins affected by this interrupt request:["ELB","ELA","ERB","ERA"]
#define ENCODERB_INT_IRQN                                       (GPIOA_INT_IRQn)
#define ENCODERB_INT_IIDX                       (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define ENCODERB_ELB_IIDX                                   (DL_GPIO_IIDX_DIO22)
#define ENCODERB_ELB_PIN                                        (DL_GPIO_PIN_22)
#define ENCODERB_ELB_IOMUX                                       (IOMUX_PINCM47)
/* Defines for ELA: GPIOA.17 with pinCMx 39 on package pin 10 */
#define ENCODERB_ELA_IIDX                                   (DL_GPIO_IIDX_DIO17)
#define ENCODERB_ELA_PIN                                        (DL_GPIO_PIN_17)
#define ENCODERB_ELA_IOMUX                                       (IOMUX_PINCM39)
/* Defines for ERB: GPIOA.16 with pinCMx 38 on package pin 9 */
#define ENCODERB_ERB_IIDX                                   (DL_GPIO_IIDX_DIO16)
#define ENCODERB_ERB_PIN                                        (DL_GPIO_PIN_16)
#define ENCODERB_ERB_IOMUX                                       (IOMUX_PINCM38)
/* Defines for ERA: GPIOA.15 with pinCMx 37 on package pin 8 */
#define ENCODERB_ERA_IIDX                                   (DL_GPIO_IIDX_DIO15)
#define ENCODERB_ERA_PIN                                        (DL_GPIO_PIN_15)
#define ENCODERB_ERA_IOMUX                                       (IOMUX_PINCM37)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_Motor_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_SPI_FOR_IMU_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
