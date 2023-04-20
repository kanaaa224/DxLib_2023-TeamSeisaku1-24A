#pragma once

#ifndef APPLE_H
#define APPLE_H

//�}�N����`
#define REDAPPLE 0
#define BULEAPPLE 3
#define GOLDAPPLE 4
#define POISONAPPLE 12

#define LINE_NUM 7

//�^��`

/************************************************
*�@�\����
************************************************/
static struct APPLE {
	int flg;			//�g�p�t���O
	int img;			//�摜
	double x, y, w, h;	//���W�A���A����
	double speed;		//�ړ����x
	int point;			//�X�R�A���Z�|�C���g
};

static struct APPLE gApple[10];

//�v���g�^�C�v�錾
//int LoadImges(void);		//�摜�Ǎ�
void FallApple(void);		//�����S��������
int CreateApple(void);		//�����S����
void AppleSpeed(int i);		//��񂲂̑��x
void AppleInit(void);		//�����S�̕ϐ��̏�����
int HitBox(void);
int HitBoxPlayer(void);
void ApplePoint(int i);		//��񂲂̃X�R�A����

#endif