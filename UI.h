#pragma once

static int gFpsCnt;		//Fps�v��
static int gTimeLimit;	//��������
/*
*�֐����FDrawUserInterFace
*�����Ȃ�
*�������e
*�֐����Ăяo��
*/
void DrawUserInterFace();
/*
*�֐����FDrawTimeLimit
*�����Ȃ�
*�������e
*�������Ԃ̌v���A�\��
*/
void DrawTimeLimit();
/*
*�֐����FDrawImg
*�����Ȃ�
*�������e
*��񂲂̉摜��\������
*/
void DrawImg();
/*
*�֐����FSetUI
*����
* int cnt,int time
*�������e
*�ϐ��̏�����
*/
void SetUI(int cnt,int time);
