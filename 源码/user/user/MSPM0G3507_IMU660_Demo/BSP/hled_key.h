#ifndef _HLED_KEY_H_
#define _HLED_KEY_H_

#include "headfile.h"
//PA0是LED

#define Key1 (DL_GPIO_readPins(KEY_key1_PORT,KEY_key1_PIN) == 0) //PB21
#define Key2 (DL_GPIO_readPins(KEY_key2_PORT,KEY_key2_PIN) != 0) //PA18
#define Key3 (DL_GPIO_readPins(KEY_key3_PORT,KEY_key3_PIN) == 0) //PB8
#define Key4 (DL_GPIO_readPins(KEY_key4_PORT,KEY_key4_PIN) == 0) //PB9
#define Key5 (DL_GPIO_readPins(KEY_key5_PORT,KEY_key5_PIN) == 0) //PB11
#define Key6 (DL_GPIO_readPins(KEY_key6_PORT,KEY_key6_PIN) == 0) //PB20
#define Key7 (DL_GPIO_readPins(KEY_key7_PORT,KEY_key7_PIN) == 0) //PB20 
#define Key8 (DL_GPIO_readPins(KEY_key8_PORT,KEY_key8_PIN) == 0) //PB20  

/*板载红色LED开*/
#define LED_Board_ON  DL_GPIO_clearPins  (GPIOA,DL_GPIO_PIN_0)
/*板载红色LED关*/
#define LED_Board_OFF DL_GPIO_setPins    (GPIOA,DL_GPIO_PIN_0)

//高电平触发
#define BEEP_OFF DL_GPIO_clearPins         (GPIOA,DL_GPIO_PIN_27)
#define BEEP_ON  DL_GPIO_setPins       (GPIOA,DL_GPIO_PIN_27)
// 定义颜色枚举类型
typedef enum 
{
    BLACK,    // 黑色BB
    RED,      // 红色
    GREEN,    // 绿色
    BLUE,     // 蓝色
    YELLOW,   // 黄色
    MAGENTA,  // 品红色
    CYAN,     // 青色
    WHITE     // 白色
} Color;





uint8_t key_scan(void);
void RGB_led(Color color);
void BEEP_time(void);
extern uint8_t BEEP_Count;

#endif