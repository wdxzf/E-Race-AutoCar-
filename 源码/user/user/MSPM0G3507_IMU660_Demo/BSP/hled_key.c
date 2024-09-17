#include "hled_key.h"


uint8_t BEEP_Count = 0;
// �ڲ���������������RGB�Ƶĸ�����ɫͨ��
static void setRGB(bool r, bool g, bool b)
{
    if (r) 
    DL_GPIO_setPins(LED_RGB_R_PORT, LED_RGB_R_PIN);  // ���ú�ɫͨ��
    else 
    DL_GPIO_clearPins(LED_RGB_R_PORT, LED_RGB_R_PIN); // �����ɫͨ��

    if (g) 
    DL_GPIO_setPins(LED_RGB_G_PORT, LED_RGB_G_PIN);  // ������ɫͨ��
    else 
    DL_GPIO_clearPins(LED_RGB_G_PORT, LED_RGB_G_PIN); // �����ɫͨ��
    
    if (b) 
    DL_GPIO_setPins(LED_RGB_B_PORT, LED_RGB_B_PIN);  // ������ɫͨ��
    else 
    DL_GPIO_clearPins(LED_RGB_B_PORT, LED_RGB_B_PIN); // �����ɫͨ��
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
            setRGB(true, false, false);  // ��ɫ
            break;
        case GREEN:
            setRGB(false, true, false);  // ��ɫ
            break;
        case BLUE:
            setRGB(false, false, true);  // ��ɫ
            break;
        case YELLOW:
            setRGB(true, true, false);   // ��ɫ
            break;
        case MAGENTA:
            setRGB(true, false, true);   // Ʒ��ɫ
            break;
        case CYAN:
            setRGB(false, true, true);   // ��ɫ
            break;
        case WHITE:
            setRGB(true, true, true);    // ��ɫ
            break;
        case BLACK:
            setRGB(false, false, false); // ��ɫ���رգ�
            break;
    }
}
void BEEP_time()
{
    if (BEEP_Count > 0)
    {
        BEEP_Count--;
        BEEP_ON;  // �򿪷�����
        RGB_led(BLUE);
    }
    else
    {
        BEEP_OFF; // �رշ�����
         RGB_led(BLACK);
    }
}

