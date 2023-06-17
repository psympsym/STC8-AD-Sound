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

/* ����ͷ�ļ� -------------------------------------------------------*/
#include "STC8Ax_ISR.h"

/* ˽�����Ͷ��� -----------------------------------------------------*/
/* None. */

/* ˽�к궨�� -------------------------------------------------------*/
/* None. */

/* ˽�б��� ---------------------------------------------------------*/
uint8 time1 = 0;

/* ��չ���� ---------------------------------------------------------*/
/* None. */

/* ˽�к���ԭ�� -----------------------------------------------------*/
/* None. */

/* ������ -----------------------------------------------------------*/
/* ������ ϵͳ�жϴ��� */
/**
 * ���ܣ���ʱ�жϺ���
 * ������None
 * ���أ�None
 * ˵����
 */
void TIMER0_ISR() interrupt TIMER0_VECTOR
{
    TF0 = 0; // ����жϱ�־
    TR0 = 0; // ���ж�

	if (++time1 % 200 == 0)
	{
		DigLED_Display();
	    KeyScan();
	}

	LED();

    TH0 = 0xFF; // ��װ��ʼֵ(65535-20)=65515=0xFFEB
    TL0 = 0xEB;
    TR0 = 1; // ���ж�
}

/*>>>>>>>>>> (C) COPYRIGHT NBUFE <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/