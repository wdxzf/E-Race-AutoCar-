#ifndef _HLED_KEY_H_
#define _HLED_KEY_H_

#include "headfile.h"
//PA0��LED

#define Key1 (DL_GPIO_readPins(KEY_key1_PORT,KEY_key1_PIN) == 0) //PB21
#define Key2 (DL_GPIO_readPins(KEY_key2_PORT,KEY_key2_PIN) != 0) //PA18
#define Key3 (DL_GPIO_readPins(KEY_key3_PORT,KEY_key3_PIN) == 0) //PB8
#define Key4 (DL_GPIO_readPins(KEY_key4_PORT,KEY_key4_PIN) == 0) //PB9
#define Key5 (DL_GPIO_readPins(KEY_key5_PORT,KEY_key5_PIN) == 0) //PB11
#define Key6 (DL_GPIO_readPins(KEY_key6_PORT,KEY_key6_PIN) == 0) //PB20
#define Key7 (DL_GPIO_readPins(KEY_key7_PORT,KEY_key7_PIN) == 0) //PB20 
#define Key8 (DL_GPIO_readPins(KEY_key8_PORT,KEY_key8_PIN) == 0) //PB20  

/*���غ�ɫLED��*/
#define LED_Board_ON  DL_GPIO_clearPins  (GPIOA,DL_GPIO_PIN_0)
/*���غ�ɫLED��*/
#define LED_Board_OFF DL_GPIO_setPins    (GPIOA,DL_GPIO_PIN_0)

//�ߵ�ƽ����
#define BEEP_OFF DL_GPIO_clearPins         (GPIOA,DL_GPIO_PIN_27)
#define BEEP_ON  DL_GPIO_setPins       (GPIOA,DL_GPIO_PIN_27)
// ������ɫö������
typedef enum 
{
    BLACK,    // ��ɫBB
    RED,      // ��ɫ
    GREEN,    // ��ɫ
    BLUE,     // ��ɫ
    YELLOW,   // ��ɫ
    MAGENTA,  // Ʒ��ɫ
    CYAN,     // ��ɫ
    WHITE     // ��ɫ
} Color;





uint8_t key_scan(void);
void RGB_led(Color color);
void BEEP_time(void);
extern uint8_t BEEP_Count;

#endif