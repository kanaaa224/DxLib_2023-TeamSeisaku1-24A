#pragma once

#ifndef APPLE_H
#define APPLE_H

//�}�N����`

#define REDAPPLE 0		//�摜�̔z��ԍ��i�Ԃ�񂲁j
#define BLUEAPPLE 1		//�摜�̔z��ԍ��i��񂲁j
#define GOLDAPPLE 2		//�摜�̔z��ԍ��i����񂲁j
#define POISONAPPLE 3	//�摜�̔z��ԍ��i�ł�񂲁j
#define APPLE_MAX 10	//��񂲍ő��

//�N���X�錾
class Apple {
private:
	/*�����o�ϐ�*/
	int gRACount = 0;				//�Ԃ�񂲂̌�
	int gBACount = 0;				//��񂲂̌�
	int gGACount = 0;				//����񂲂̌�
	int gPACount = 0;				//�ł�񂲂̌�
	int gScore = 0;					//�X�R�A
	int gP = 0;						//��񂲂̊m��	

	int px1;
	int py1;
	int px2;
	int py2;

	struct  APPLE{
		int flg;			//�g�p�t���O
		int img;			//�摜
		double x, y, w, h;	//���W�A���A����
		double speed;		//�ړ����x
		int point;			//�X�R�A���Z�|�C���g
	};

	APPLE gApple[APPLE_MAX];

	/*�����o�֐�*/

public:
	/**
	*�L���ꐬ
	*void AppleInit(void)
	*��񂲂̏�����
	*����	�F�Ȃ�
	*�߂�l	�F�Ȃ�
	* �����o�ϐ���������
	*/
	void AppleInit();

	/**
	*�L���ꐬ
	*void FallApple(void)
	*��񂲂̗�������
	*����	�F�Ȃ�
	*�߂�l	�F�Ȃ�
	*/
	void FallApple();

	/**
	*�L���ꐬ
	*int CreateApple(void)
	*��񂲂̐����Ƃ�񂲂̊m������
	*����	�F�Ȃ�
	*�߂�l	�Fint�^
	*�߂�l�͂�񂲂̐��������������ꍇTRUE�A���s�����ꍇFALSE��gApple��flg�ɓ���
	*/
	int CreateApple();

	/**
	*�L���ꐬ
	*void AppleSpeed(int i)
	*��񂲂̗������x
	*����	�Fint�^ i
	*�߂�l	�F�Ȃ�
	*CreateApple�֐���������Ă���֐�
	*�����ɂ�CreateApple�֐��������Ă���gApple�̔z��ԍ��������Ă���
	*/
	void AppleSpeed(int i);

	/**
	* �k�����m
	*int HitBox(void)
	*��񂲂̓����蔻�菈��
	*����	�F�Ȃ�
	*�߂�l	�Fint�^�@
	*/
	int HitBox();

	/*
	* �k�����m
	*int HitBoxPlayer(void)
	*��񂲂̓����蔻�菈��
	*����	�F�Ȃ�
	*�߂�l	�Fint�^�@
	*/
	int HitBoxPlayer();

	/**
	*�L���ꐬ
	*void ApplePoint(int i)
	*��񂲂̃X�R�A�������J�E���g����
	*����	�Fint�^
	*�߂�l	�F�Ȃ�
	*������gApple�̔z��ԍ���HitBoxPlayer�������Ă��āA��񂲂̎�ޕʂɃX�R�A�ƌ�������
	*/
	void ApplePoint(int i);

	/**
	* �V����K
	*int ReternRA(void)
	*�Ԃ�񂲂̌���Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnRA();

	/**
	* �V����K
	*int ReternBL(void)
	*��񂲂̌���Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnBL();

	/**
	* �V����K
	*int ReternGL(void)
	*����񂲂̌���Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnGL();

	/**
	* �V����K
	*int ReternPO(void)
	*�ł�񂲂̌���Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnPO();

	/**
	* �V����K
	*int ReternRA(void)
	*�X�R�A��Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnScore();

	/**
	* �k�����m
	*int ReternAppleX(int num)
	*��񂲂�X���W��Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnAppleX(int num);

	/**
	* �k�����m
	*int ReternAppleY(int num)
	*��񂲂�Y���W��Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnAppleY(int num);

	/**
	* �k�����m
	*int ReternAppleImg(int num)
	*��񂲂�Img��Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnAppleImg(int num);

	/**
	* �k�����m
	*int ReternAppleFlg(int num)
	*��񂲂�Flg��Ԃ�
	*����	�Fint�^
	*�߂�l	�Fint�^�@
	*/
	int ReturnAppleFlg(int num);

	/**
	* �k�����m
	*void SetAppleCount(int num)
	*����	�F�Ȃ�
	*�߂�l	�Fint�^�@
	*/
	void SetAppleCount(int num);

	void GetPlayerX(int xPos);
	void GetPlayerY(int yPos);
	int GetBlinkFlg();
	int SetBlinkFlg(int flg);

	/**
	*�L���ꐬ
	*void MainAppleInit(void)
	*��񂲂̏�����
	*����	�F�Ȃ�
	*�߂�l	�F�Ȃ�
	*��񂲂̃J�E���g�A�X�R�A��������
	*/
	void MainAppleInit();
};

#endif