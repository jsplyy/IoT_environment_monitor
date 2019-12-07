/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-07     yangjie      first implementation
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/* 配置 LED 灯引脚 */
#define LED_PIN     PIN_LED_R

static rt_timer_t timer1;
static void timeout1(void *parameter);

//timer2_thread
static rt_timer_t timer2;
static void timeout2(void *parameter);

static void timeout1(void *parameter)
{
	static int pin_status = 0;
	pin_status = ~pin_status;
	rt_pin_write(LED_PIN, pin_status);
	LOG_D("timer callback");
}

int main(void)
{
    unsigned int count = 1;
	



    /* 设置 LED 引脚为输出模式 */
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

	
    timer1 = rt_timer_create("timer1",timeout1,RT_NULL,1000,RT_TIMER_FLAG_PERIODIC|RT_TIMER_FLAG_SOFT_TIMER);
		if (timer1 != RT_NULL) rt_timer_start(timer1);

//    while (RT_TRUE)
//    {
//			;
////        /* LED 灯亮 */
////        rt_pin_write(LED_PIN, PIN_LOW);
////        LOG_D("led on, count: %d", count);
////        rt_thread_mdelay(500);

////        /* LED 灯灭 */
////        rt_pin_write(LED_PIN, PIN_HIGH);
////        LOG_D("led off");
////        rt_thread_mdelay(500);

////        count++;
//    }

    return 0;
}
