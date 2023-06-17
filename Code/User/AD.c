/*-------------------------------------------------------------------------------
/*       (C) Copyright 2023, PSYM. All Rights Reserved 
/*-------------------------------------------------------------------------------
/* File name   : AD.c
/* Description : 
/* Author      : PSYM
/*-------------------------------------------------------------------------------
/* Update note:
/* -----------   -----------   --------------------------------------------------
/*    Date         Author                              Note
/* -----------   -----------   --------------------------------------------------
/* 2023-06-08       PSYM
/*   14:50
**/

/* ---------------------------------- 包含头文件 ---------------------------------- */
#include "AD.h"

/* ---------------------------------- 私有宏定义 ---------------------------------- */
#define VCC 3300 // 电源电压mv
#define ADC_RES_12BIT 4096 // 12位采样分辨率

/* ---------------------------------- 私有类型定义 ---------------------------------- */
sbit ADC_IO = P0 ^ 0; // ADC通道选择端口
sbit ADC_CFG = 0xDE; // ADC配置寄存器

/* ---------------------------------- 私有变量 ---------------------------------- */
uint16 ADC_Value = 0; // ADC转换结果
uint32 voltage = 0; // 实际电压值

/* ---------------------------------- 扩展变量 ---------------------------------- */
uint32 ave_vol = 0; // 6次电压平均值

/* ---------------------------------- 私有函数原型 ---------------------------------- */
void AD_Start();
void Sampl();

/* ---------------------------------- 函数体 ---------------------------------- */

/**
 * @brief: None
 * @param: None
 * @return: None
 * @note: None
 */
void AD_Init()
{
    ADC_CONTR &= 0xF0; // 清除模拟通道选择位
    ADC_CONTR |= 0x08; // 设置ADC模拟通道 P0.0

    ADC_CFG &= 0x00; // 清除所有标志位
    ADC_CFG |= 0x00; // 设置ADC转换结果为左对齐
    ADC_CFG |= 0x0F; // 设置ADC时钟频率

	AD_Start(); // 开启ADC转换
}

void AD_Start()
{
    ADC_CONTR |= 0x80; // 开启ADC电源
	Delay_ms(1);
    ADC_CONTR |= 0x40; // 启动ADC转换
}

/**
 * @brief: 采样转换
*/
void Sampl()
{
    // 启动ADC转换
	AD_Start();

    //等待ADC转换完成，ADC转换完成ADC_CONTR的第5位会自动被置1
	while (!(ADC_CONTR & 0x20))
		;

    // 读取ADC转换结果， 左对齐需将ADC_RES左移4位再与ADC_RESL右移4位
	ADC_Value = ADC_RES << 4;
	ADC_Value |= ADC_RESL >> 4;

    // 将AD值转换为电压值
	voltage = VCC * (uint32)ADC_Value / ADC_RES_12BIT;

    // 清除ADC转换完成标志位
	ADC_CONTR &= 0xDF;
}

/**
 * @brief: 滤波
 * @param: None
 * @return: None
 * @note: None
 */
void aveADC()
{
    uint8 i = 0;
    uint16 max = 0;
    uint16 min = 0;
    uint32 sum = 0;

    for (i = 0; i < 6; i++)
    {
        Sampl();
        sum += voltage;
        if (voltage > max)
        {
            max = voltage;
        }
        if (voltage < min)
        {
            min = voltage;
        }
    }
    ave_vol = (sum - max - min) / 4;
}
/*>>>>>>>>>> (C) COPYRIGHT PSYM <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/
