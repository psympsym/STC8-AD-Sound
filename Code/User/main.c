/*-------------------------------------------------------------------
/*      (C) Copyright 2021-2022, nbufe. All Rights Reserved
/*-------------------------------------------------------------------
/* File name   : main.c
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
#include "main.h"

/* 私有类型定义 -----------------------------------------------------*/
/* None. */

/* 私有宏定义 -------------------------------------------------------*/
/* None. */

/* 私有变量 ---------------------------------------------------------*/
int i = 0;
int temp = 0;

/* 扩展变量 ---------------------------------------------------------*/
/* None. */

/* 私有函数原形 -----------------------------------------------------*/
/* None. */

/* 函数体 -----------------------------------------------------------*/
/*
 * 功能: 主函数
 * 参数: None
 * 返回: None
 * 说明: None
 */
void main()
{
    System_Init();
    Delay_ms(500);
    Peripheral_Init();

    while (1)
    {
        aveADC();

        switch (Keysign)
        {
        case 1:
            // 计算高度
            temp = ave_vol / 100;
            temp = temp < 1 ? 1 : temp;
            temp = temp > 18 ? 18 : temp;
            temp = (temp - 1) / 2;
            for (i = 0; i < 7; i++)
            {
                hight[i] = hight[i + 1];
            }
            hight[i] = temp;
            break;
        case 2:
            // 计算高度
            temp = ave_vol / 100;
            temp = temp < 1 ? 1 : temp;
            temp = temp > 18 ? 18 : temp;
            temp = (temp - 1) / 2;
            for (i = 0; i < 8; i++)
            {
                hight[i] = temp;
            }
            break;
        case 3:
            temp = ave_vol / 100;
            temp = temp < 1 ? 1 : temp;
            temp = temp > 18 ? 18 : temp;
            temp = temp / 4;
            for (i = 0; i < 7; i++)
            {
                hight[i] = hight[i + 1];
            }
            hight[i] = temp;
            break;
		case 4:
            temp = ave_vol / 100;
            temp = temp < 1 ? 1 : temp;
            temp = temp > 18 ? 18 : temp;
            temp = temp / 4;
            for (i = 0; i < 8; i++)
            {
                hight[i] = temp;
            }
			break;
        default:
            break;
        }

        // 设置数码管显示
        DisplayLoad(3, ave_vol / 10000 % 10, 0);
        DisplayLoad(2, ave_vol / 1000 % 10, 1);
        DisplayLoad(1, ave_vol / 100 % 10, 0);
        DisplayLoad(0, ave_vol / 10 % 10, 0);
        printf("ave_vol=%.3fV\n", ave_vol / 1000.0);
        printf("hight=%d\n", temp);
    }
}

/*>>>>>>>>>> (C) COPYRIGHT NBUFE <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/
