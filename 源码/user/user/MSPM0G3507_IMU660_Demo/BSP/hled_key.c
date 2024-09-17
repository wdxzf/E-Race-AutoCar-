#include "hled_key.h"


uint8_t BEEP_Count = 0;
// 内部函数，用于设置RGB灯的各个颜色通道
static void setRGB(bool r, bool g, bool b)
{
    if (r) 
    DL_GPIO_setPins(LED_RGB_R_PORT, LED_RGB_R_PIN);  // 设置红色通道
    else 
    DL_GPIO_clearPins(LED_RGB_R_PORT, LED_RGB_R_PIN); // 清除红色通道

    if (g) 
    DL_GPIO_setPins(LED_RGB_G_PORT, LED_RGB_G_PIN);  // 设置绿色通道
    else 
    DL_GPIO_clearPins(LED_RGB_G_PORT, LED_RGB_G_PIN); // 清除绿色通道
    
    if (b) 
    DL_GPIO_setPins(LED_RGB_B_PORT, LED_RGB_B_PIN);  // 设置蓝色通道
    else 
    DL_GPIO_clearPins(LED_RGB_B_PORT, LED_RGB_B_PIN); // 清除蓝色通道
}

 uint8_t key_scan(void)
{
    uint8_t key_val = 0;

    if(Key1)  key_val = 1;              
    else if(Key2)  key_val = 2;                  
    else if(Key3)  key_val = 3;
    else if(Key4)  key_val = 4;
    else if(Key5)  key_val = 5;
    else if(Key6)  key_val = 6;
    else if(Key7)  key_val = 7;
    else if(Key8)  key_val = 8;
    
    //printf("val:%d\r\n",key_val);
    return key_val;
}

void RGB_led(Color color)
{
    switch (color)
    {
        case RED:
            setRGB(true, false, false);  // 红色
            break;
        case GREEN:
            setRGB(false, true, false);  // 绿色
            break;
        case BLUE:
            setRGB(false, false, true);  // 蓝色
            break;
        case YELLOW:
            setRGB(true, true, false);   // 黄色
            break;
        case MAGENTA:
            setRGB(true, false, true);   // 品红色
            break;
        case CYAN:
            setRGB(false, true, true);   // 青色
            break;
        case WHITE:
            setRGB(true, true, true);    // 白色
            break;
        case BLACK:
            setRGB(false, false, false); // 黑色（关闭）
            break;
    }
}
void BEEP_time()
{
    if (BEEP_Count > 0)
    {
        BEEP_Count--;
        BEEP_ON;  // 打开蜂鸣器
        RGB_led(BLUE);
    }
    else
    {
        BEEP_OFF; // 关闭蜂鸣器
         RGB_led(BLACK);
    }
}

