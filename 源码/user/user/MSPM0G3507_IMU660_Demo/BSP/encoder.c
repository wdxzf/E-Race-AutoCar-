#include "encoder.h"

/*
    组中断`，此处使用了外部引脚中断测速
*/
volatile int16_t encoder_L = 0;
volatile int16_t encoder_R = 0;
void GROUP1_IRQHandler(void)
{
    uint32_t gpio_interrup = 
    DL_GPIO_getEnabledInterruptStatus(GPIOA,
    ENCODERB_ERA_PIN|ENCODERB_ERB_PIN|ENCODERB_ELA_PIN|ENCODERB_ELB_PIN);
    
    if(gpio_interrup & ENCODERB_ERA_PIN) 
    {
        if(DL_GPIO_readPins(GPIOA,ENCODERB_ERB_PIN) == 0)encoder_R++;
        else encoder_R--;
    }
    else if(gpio_interrup & ENCODERB_ERB_PIN)
    {
        if(DL_GPIO_readPins(GPIOA,ENCODERB_ERA_PIN) == 0)encoder_R--;
        else encoder_R++;
    }

    if(gpio_interrup & ENCODERB_ELA_PIN) 
    {
        if(DL_GPIO_readPins(GPIOA,ENCODERB_ELB_PIN) == 0)encoder_L--;
        else encoder_L++;
    }
    else if(gpio_interrup & ENCODERB_ELB_PIN)
    {
        if(DL_GPIO_readPins(GPIOA,ENCODERB_ELA_PIN) == 0)encoder_L++;
        else encoder_L--;
    }
    DL_GPIO_clearInterruptStatus(GPIOA,
    ENCODERB_ERA_PIN|ENCODERB_ERB_PIN|ENCODERB_ELA_PIN|ENCODERB_ELB_PIN);
}
