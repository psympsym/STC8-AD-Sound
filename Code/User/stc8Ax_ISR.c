/*-------------------------------------------------------------------
/*      (C) Copyright 2021-2022, nbufe. All Rights Reserved
/*-------------------------------------------------------------------
/* File name   : STC8Ax_ISR.c
/* Description :
/* Author      : nbufe
/*-------------------------------------------------------------------
/* Update note:
/* ---------   -----------   ----------------------------------------
/*   Date        Author                       Note
/* ---------   -----------   ----------------------------------------
/*
/*
**/

/* 包含头文件 -------------------------------------------------------*/
#include "STC8Ax_ISR.h"

/* 私有类型定义 -----------------------------------------------------*/
/* None. */

/* 私有宏定义 -------------------------------------------------------*/
/* None. */

/* 私有变量 ---------------------------------------------------------*/
uint8 time1 = 0;

/* 扩展变量 ---------------------------------------------------------*/
/* None. */

/* 私有函数原形 -----------------------------------------------------*/
/* None. */

/* 函数体 -----------------------------------------------------------*/
/* 第四区 系统中断处理 */
/**
 * 功能：定时中断函数
 * 参数：None
 * 返回：None
 * 说明：
 */
void TIMER0_ISR() interrupt TIMER0_VECTOR
{
    TF0 = 0; // 清除中断标志
    TR0 = 0; // 关中断

	if (++time1 % 20 == 0)
	{
		DigLED_Display();
	    KeyScan();
	}

	if (Keysign == 1 || Keysign == 2)
		LED1();
	else if (Keysign == 3 || Keysign == 4)
        LED2();

    TH0 = 0xFF; // 重装初始值(65535-20)=65515=0xFFEB
    TL0 = 0xEB;
    TR0 = 1; // 开中断
}

/*>>>>>>>>>> (C) COPYRIGHT NBUFE <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/
