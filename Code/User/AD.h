/* -----------------------------------------------------------------------------
/* File name   : AD.h
/* Author      : PSYM
/* Copyright(C): 2023 PSYM. All rights reserved.
/* -----------------------------------------------------------------------------
 */
#ifndef __AD_H_
#define __AD_H_

/* --------------------------------- ����ͷ�ļ� --------------------------------- */
#include "STC8Ax_DELAY.h"
#include "DigLED.h"
#include "uart_printf.h"

/* --------------------------------- ���Ͷ��� --------------------------------- */
/* None. */

/* --------------------------------- �궨�� --------------------------------- */
/* None. */

/* --------------------------------- ��չ���� --------------------------------- */
extern uint32 ave_vol; // ����ƽ����ѹֵmv

/* --------------------------------- �������� --------------------------------- */
void AD_Init();
void aveADC();

#endif /* __AD_H_ */

/*>>>>>>>>>> (C) COPYRIGHT PSYM <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/