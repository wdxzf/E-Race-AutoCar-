/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "headfile.h"


uint8_t pit_flag  = 0;
uint8_t Question  = 0;//第几个题目
uint8_t Question_flag = 0;//题目标志位
float question_ek = 0;
float question_eks = 0;

uint8_t is_element()
{
    int16_t l = 0, r = 0, sum = 0;;
    l = Gray_Val[0] +   Gray_Val[1] +   Gray_Val[2] + Gray_Val[3] + Gray_Val[4] + Gray_Val[5];
    r = Gray_Val[11] + Gray_Val[10] + Gray_Val[9] + Gray_Val[8] + Gray_Val[7] + Gray_Val[6] ;
    sum = l - r;
    if(sum > 0)return 1;//左
    else if(sum < 0)return 2;//右
    else if(sum == 0)
    {
        if(l == 0 && r == 0)return 3;//丢线
    }
    return 0;//正常循迹
}

void handle_initial_state()
{
    motor_turn(0, 0);
    Question_flag = 0;
    IMUdata.Yaw = 0;
    Step1.Lenth  = 0;
    //IMUdata.flag = 1;//记得删掉

}

void handle_question_1()
{
    IMUdata.flag = 1; // 开启积分标志位
    DifferControl(-IMUdata.Yaw, &price);//转向环计算
    motor_turn(800 - price.output_val, 800 + price.output_val); // 右, 左
    if (is_element() != 3 && Step1.Lenth > 850)
    {
        Question = 0;
        BEEP_Count = 30;
        Step1.Lenth  = 0;
    }
}

void handle_question_2()
{

    switch(Question_flag)
    {
    case 0: // A———>B 角度闭环
        IMUdata.flag = 1; // 开启积分标志位

        question_ek = -IMUdata.Yaw;

        if(is_element() != 3 && Step1.Lenth > 850)//找到黑线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;
    case 1: // B————>C 灰度循迹
        if(is_element() == 3)//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth = 0;
            }
            question_ek =  question_eks;
        }
        else  question_ek = Gray_erro();
        break;
    case 2: // C————>D //角度闭环
        question_ek = -185 - IMUdata.Yaw;

        if(is_element() != 3 && Step1.Lenth > 850) //找到黑线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;
    case 3: // D————>A //灰度循迹

        if(is_element() == 3 )  //丢线
        {
            if(Step1.Lenth > 850)
            {
                Question = 0;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();

        break;
    }

    DifferControl(question_ek, &price);
    motor_turn(800 - price.output_val, 800 + price.output_val); // 右, 左
    question_eks = question_ek;
}

void handle_question_2_1()
{

    switch(Question_flag)
    {
    case 0: // A———>B 角度闭环
        IMUdata.flag = 1; // 开启积分标志位

        question_ek = -IMUdata.Yaw;

        if(is_element() != 3 && Step1.Lenth > 850)//找到黑线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;
    case 1: // B————>C 灰度循迹
        if(is_element() == 3)//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth = 0;
            }
            question_ek =  question_eks;
        }
        else  question_ek = Gray_erro();
        break;
    case 2: // C————>D //角度闭环
        question_ek = 185 - IMUdata.Yaw;

        if(is_element() != 3 && Step1.Lenth > 850) //找到黑线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;
    case 3: // D————>A //灰度循迹

        if(is_element() == 3 )  //丢线
        {
            if(Step1.Lenth > 850)
            {
                Question = 0;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();

        break;
    }

    DifferControl(question_ek, &price);
    motor_turn(800 - price.output_val, 800 + price.output_val); // 右, 左
    question_eks = question_ek;
}
void handle_question_3()
{
    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw - 38;
        if(is_element() == 1 && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 1: // C——>B 灰度循迹

        if (is_element() == 3)
        {
            if (Step1.Lenth > 850 )
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();

        break;
    case 2: // B——>D //角度循迹
        question_ek = 223 - IMUdata.Yaw;
        if(is_element() == 2 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线

        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question = 0;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else  question_ek = Gray_erro();
        break;
    }
    DifferControl(question_ek, &price);
    question_eks = question_ek;
    motor_turn(800 - price.output_val, 800 + price.output_val);
    //motor_turn(1400 - price.output_val, 1400 + price.output_val);
}

void handle_question_3_1()
{
    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw + 38;
        if(is_element() == 1 && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 1: // C——>B 灰度循迹

        if (is_element() == 3)
        {
            if (Step1.Lenth > 850 )
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();

        break;
    case 2: // B——>D //角度循迹
        question_ek = -223 - IMUdata.Yaw;
        if(is_element() == 2 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线

        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question = 0;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else  question_ek = Gray_erro();
        break;
    }
    DifferControl(question_ek, &price);
    question_eks = question_ek;
    //motor_turn(900 - price.output_val, 900 + price.output_val);
    motor_turn(800 - price.output_val, 800 + price.output_val);
}

void handle_question_4()
{
    static uint8_t cnt = 0;

    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw - 39.2;//38.2

        if(is_element() == 1  && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;

    case 1: // C——>B 灰度循迹

        if(is_element() == 3 ) // 218.6 257.2&& jy901s_Data.Roll < -161.4//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;

    case 2: // B——>D //角度循迹

        question_ek = 227 - IMUdata.Yaw;
        if(is_element() == 2 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线
        question_ek = Gray_erro();
        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag = 0;
                if(++cnt >= 4)Question = 0;
                IMUdata.Yaw += 0.5;//角度补偿记得加上
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;
    }

    //内环
    price.kp = 8; //比例//5
    price.kd = 2; //微分//2

    //外环
    price.in_kp = 8; // adc本次权值//3.45 2.95
    price.in_kd = 2;  // adc上次权值0.6

    DifferControl(question_ek, &price);
    question_eks = question_ek;
    PID_DT(&Speed);//增量式
    motor_turn(1200 - price.output_val, 1200 + price.output_val);
   
}

void handle_question_4_1()
{

    static uint8_t cnt = 0;

    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw + 38;

        if(is_element() == 2  && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;

    case 1: // C——>B 灰度循迹

        if(is_element() == 3 ) // 218.6 257.2&& jy901s_Data.Roll < -161.4//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;

    case 2: // B——>D //角度循迹

        question_ek = -225 - IMUdata.Yaw;
        if(is_element() == 1 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线
        question_ek = Gray_erro();
        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag = 0;
                if(++cnt == 4)Question = 0;
                //IMUdata.Yaw -= 0.1;角度补偿记得加上
                BEEP_Count = 30;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;
    }
    DifferControl(question_ek, &price);
    question_eks = question_ek;
    motor_turn(1000 - price.output_val, 1000 + price.output_val);
}
void handle_question_4_low()
{

    static uint8_t cnt = 0;

    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw - 38;

        if(is_element() == 1  && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;

    case 1: // C——>B 灰度循迹

        if(is_element() == 3 ) // 218.6 257.2&& jy901s_Data.Roll < -161.4//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;

    case 2: // B——>D //角度循迹

        question_ek = 225 - IMUdata.Yaw;
        if(is_element() == 2 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线
        question_ek = Gray_erro();
        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag = 0;
                if(++cnt >= 4)Question = 0;
                IMUdata.Yaw += 0.1;//角度补偿记得加上
                BEEP_Count = 30;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;
    }
    DifferControl(question_ek, &price);
    question_eks = question_ek;
    motor_turn(800 - price.output_val, 800 + price.output_val);
}
void handle_question_4_low_1()
{

    static uint8_t cnt = 0;

    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw + 38;

        if(is_element() == 2  && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;

    case 1: // C——>B 灰度循迹

        if(is_element() == 3 ) // 218.6 257.2&& jy901s_Data.Roll < -161.4//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;

    case 2: // B——>D //角度循迹

        question_ek = -225 - IMUdata.Yaw;
        if(is_element() == 1 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线
        question_ek = Gray_erro();
        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag = 0;
                if(++cnt == 4)Question = 0;
                IMUdata.Yaw += 0.2;//角度补偿记得加上
                BEEP_Count = 30;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;
    }
    DifferControl(question_ek, &price);
    question_eks = question_ek;
    motor_turn(800 - price.output_val, 800 + price.output_val);
}

void handle_question_4_low_ll()
{

    static uint8_t cnt = 0;

    switch(Question_flag)
    {
    case 0: // A--C 角度闭环
        IMUdata.flag = 1; // 开启积分标志位
        question_ek = -IMUdata.Yaw - 38;

        if(is_element() == 1  && Step1.Lenth > 850) //左边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth = 0;
        }
        break;

    case 1: // C——>B 灰度循迹

        if(is_element() == 3 ) // 218.6 257.2&& jy901s_Data.Roll < -161.4//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag++;
                BEEP_Count = 30;
                Step1.Lenth  = 0;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;

    case 2: // B——>D //角度循迹

        question_ek = 225 - IMUdata.Yaw;
        if(is_element() == 2 && Step1.Lenth > 850)//右边有线
        {
            Question_flag++;
            BEEP_Count = 30;
            Step1.Lenth  = 0;
        }
        break;
    case 3: // D——>A //灰度巡线
        question_ek = Gray_erro();
        if(is_element() == 3) // -39&& jy901s_Data.Roll > -10//丢线
        {
            if(Step1.Lenth > 850)
            {
                Question_flag = 0;
                IMUdata.Yaw += 0.3;//角度补偿记得加上
                BEEP_Count = 30;
            }
            question_ek = question_eks;
        }
        else question_ek = Gray_erro();
        break;
    }
    DifferControl(question_ek, &price);
    question_eks = question_ek;
    motor_turn(800 - price.output_val, 800 + price.output_val);
}
void handle_question_test()
{
    //内环
    price.kp = 10; //比例//5
    price.kd = 2; //微分//2

    IMUdata.flag = 1; //记得删掉
    //外环
    price.in_kp = 8; // adc本次权值//3.45 2.95
    price.in_kd = 2;  // adc上次权值0.6
    DifferControl(Gray_erro(), &price);

    motor_turn(1500 - price.output_val, 1500 + price.output_val);
}

uint16_t Key_long_time = 300;
void Key_Pro(void)
{
    if(pit_flag < 4 && Question)return;
    pit_flag = 0;

    uint8_t Key_Val, Key_Up, Key_Down;
    static uint8_t Key_Old = 0;

    Key_Val  =  key_scan();
    Key_Down =  Key_Val & (Key_Val ^ Key_Old);
    Key_Up   =  ~Key_Val & (Key_Val ^ Key_Old);
    Key_Old  =  Key_Val;
    if(Key_long_time > 300)LED_Board_ON;
    else LED_Board_OFF;

    if(Key_Down)Key_long_time = 0;
    if(Key_Up)
    {
        BEEP_Count = 30;
        if(Key_long_time > 300)//长按
        {
            switch (Key_Up)
            {
            case 3:
                Question = 1;
                break;
            case 4:
                Question = 5;
                break;
            case 5:
                Question = 6;
                break;
            case 6:
                Question = 7;
                break;
            case 7:
                Question = 9;
                break;
            }
        }
        else //短按
        {
            switch (Key_Up)
            {
            case 3:
                Question = 1;
                break;
            case 4:
                Question = 2;
                break;
            case 5:
                Question = 3;
                break;
            case 6:
                Question = 4;
                break;
            case 7:
                Question = 8;
                break;
            case 8:
                Question = 10;
            break;
            }
        }
    }
}

int main (void)
{
    board_init();
    DL_TimerG_startCounter(PWM_Motor_INST);//PWMdsq开启

    while(1)
    {
        if(imu660ra_init()) printf("\r\nIMU660RA init error."); // IMU660RA 初始化失败
        else
        {
            printf("\r\nIMU660RA .");
            break;
        }
        delay_ms(100);
    }
    mypid_init();

    delay_ms(1000);
    GyroOffsets(900);
    IMUdata.flag = 1;
    BEEP_ON;
    delay_ms(10);
    BEEP_OFF;

    NVIC_EnableIRQ(GPIOA_INT_IRQn); //编码器初始化
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);//TIMER_0使能中断
    DL_TimerG_startCounter(TIMER_0_INST);//定时器0开启


    while (1)
    {
        Key_Pro();

    }
}

void TIMER_0_INST_IRQHandler(void)
{


    ICM_OneOrderFilter();//角度获取
    Gray_get();//灰度获取
    Speed.now = Speed_Get();

    switch(Question)
    {
    case 0:
        handle_initial_state();
        break;
    case 1:
        handle_question_1();
        break;
    case 2:
        handle_question_2();
        break;
    case 3:
        handle_question_3();
        break;
    case 4:
        handle_question_4();
        break;
    case 5:
        handle_question_2_1();
        break;
    case 6:
        handle_question_3_1();
        break;
    case 7:
        handle_question_4_1();
        break;
    case 8:
        handle_question_4_low();//低速完赛
        break;
    case 9:
        handle_question_4_low_1();//低速完赛顺
        break;
    case 10:
    handle_question_4_low_ll();
    break;
    }
    BEEP_time();
    if(pit_flag < 100)pit_flag++;
    if(Key_long_time < 7000)Key_long_time++;
}


