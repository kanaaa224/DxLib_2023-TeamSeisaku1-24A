#pragma once

#ifndef APPLE_H
#define APPLE_H

//�}�N����`
#define APPLE_MAX 10; //�����S�̉�ʓ��̍ő吔

//�^��`

struct Apple
{
	int flg;			//�g�p�t���O
	int type;			//�^�C�v
	int img;			//�摜
	int x, y, w, h;		//���W�A���A����
	int speed;			//�ړ����x
	int point;			//�X�R�A���Z�|�C���g
};

typedef enum
{
	Apple_ID_Red = 0,
	Apple_ID_Blue,
	Apple_ID_Gold,
	Apple_ID_Poison,
	//-----------------------------
	E_Apple_ID_END,//�ԕ�
}Apple_ID;

//�v���g�^�C�v�錾
int CreateApple(void);	//�����S��������
int FallAplle(void);	//�����S��������

#endif