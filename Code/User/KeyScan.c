/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "KeyScan.h"

/* ---------------------------------- ˽�к궨�� --------------------------------- */
#define KEY_TIME 20 // ����ȥ��ʱ��

/* ---------------------------------- ��չ���� ---------------------------------- */
uint8 flag = 0;

/* ---------------------------------- ˽�б��� ---------------------------------- */
uint8 keysign1 = 0; // ����״̬��ʼ��

uint8 keyt1 = 0; // ����ȥ����ʱ

/* ----------------------------------- ���� ----------------------------------- */
/**
 * @brief ����ɨ��
 * @param none
 * @note �ı�Keysign��ֵ
*/
void KeyScan()
{
    if (key_sr1 == 1) // k1û������
    {
        keysign1 = 0; // ����1��־
        keyt1 = 0;
    }
    else if (keysign1 == 0) // k1�������ұ�־Ϊ0
    {
        keyt1++;
        if (keyt1 >= KEY_TIME) // ����ȥ��
        {
            keyt1 = 0;
            keysign1 = 1; // �����־�Է��ٴν���
            flag = !flag;
        }
    }
}