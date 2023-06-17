/*-------------------------------------------------------------------
/*      (C) Copyright 2023, PSYM. All Rights Reserved
/*-------------------------------------------------------------------
/* File name   : LED.c
/* Description :
/* Author      : PSYM
/*-------------------------------------------------------------------
/* Update note:
/* -----------   -----------   --------------------------------------
/*    Date         Author                       Note
/* -----------   -----------   --------------------------------------
/* 2023-05-23,     psym
/*   17:04
**/

/* ����ͷ�ļ� -------------------------------------------------------*/
#include "LED.h"

/* ˽�����Ͷ��� -----------------------------------------------------*/
/* None. */

/* ˽�к궨�� -------------------------------------------------------*/
#define LED8X_COL P6 // 8x8��������ɨ��˿�
#define LED8X_ROW P7 // 8x8��������ɨ��˿�

/* ˽�б��� ---------------------------------------------------------*/
code uint8 IMAGES[] = { 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00 };
const int IMAGES_LEN = sizeof(IMAGES)/8;

uint8 index;

/* ��չ���� ---------------------------------------------------------*/
int hight[] = { 1, 2, 3, 4, 5, 6, 7, 8, };

/* ˽�к���ԭ�� -----------------------------------------------------*/
/* None. */

/* ������ -----------------------------------------------------------*/

/**
 * @brief  LED8X8��������ʾ
 * @param  row: �к�
 * @retval None
 * @note   None
 */
void LED()
{
    for (index = 0; index < 8; index++)
    {
        LED8X_COL = 0x00; // ��Ӱ
        LED8X_ROW = IMAGES[hight[index]];
        LED8X_COL = _cror_(0x80, index); // ��ɨ��
    }
}

/*>>>>>>>>>> (C) COPYRIGHT PSYM <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/