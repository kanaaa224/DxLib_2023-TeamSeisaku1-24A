/************************************************
*�@��񂲂̏����v���O����
*�@����F�L���A�V��
************************************************/
#include "DxLib.h"
#include "Apple.h"
#include "resourceLoad.h"
#include "player.h"
#include<string>

/************************************************
*�@�ϐ��̐錾�i�O���[�o���ϐ�:Apple.cpp���j
************************************************/
//int gAppleImg[20];	//��񂲂̉摜�ϐ�
int gP = 0;				//��񂲂̊m��

int gFPSCount = 0;

using std::string;
using std::to_string;

extern Image image;			//��񂲂̉摜
extern Font font;			//�t�H���g
extern Sound sound;			//�T�E���h

int px1;
int py1;
int px2;
int py2;

int AppleBlinkFlg;

/************************************************
*�@�萔�̐錾
************************************************/
const int APPLE_MAX = 10;//��񂲂̍ő��

Apple apple;

/************************************************
*�@�����S��������
************************************************/
void FallApple(void)
{
	for (int i = 0; i < APPLE_MAX; i++) {

		if (gApple[i].flg == TRUE) {
			//�����S�̕\��
			DrawRotaGraph((int)gApple[i].x, (int)gApple[i].y, 0.19, 0, gApple[i].img, TRUE);

			//�^���������Ɉړ�
			gApple[i].y += gApple[i].speed;

			//��񂲂̍��W���P�O�O�O�ɂȂ������񂲂�����
			if (gApple[i].y > 1000 + gApple[i].h) {
				gApple[i].flg = FALSE;
				gApple[i].y = 0;
			}

		}

	}

	if ((gFPSCount++) % 25 == 0) {//�Q�T�t���[�����Ƃɐ���������񂲂̐����`�F�b�N
		CreateApple();
		HitBox();
	}

}

/************************************************
*�@�����S�������m��
************************************************/
int CreateApple(void)
{

	//��񂲊m��
	int AppleImg = image.apple[0];

	gP = GetRand(99);//100%

	if (gP < 59) {
		AppleImg = image.apple[REDAPPLE];//�ԃ����S
	}
	else if (gP >= 60 && gP < 84) {
		AppleImg = image.apple[BLUEAPPLE];//�����S
	}
	else if (gP >= 85 && gP < 94) {
		AppleImg = image.apple[GOLDAPPLE];//�������S
	}
	else if (gP >= 95 && gP < 99) {
		AppleImg = image.apple[POISONAPPLE];//�Ń����S
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i].img = AppleImg;				//�����S�̉摜
			gApple[i].x = 70 + (GetRand(6) * 130);	//��񂲂̃��[������
			gApple[i].y = -100;						//�����S�̏���Y���W
			AppleSpeed(i);							//�����S�̑��x
			gApple[i].flg = TRUE;
			//HitBox();
			//����
			return TRUE;
		}
	}
	//���s
	return FALSE;
}

/************************************************
*�@�����S�̑��x
************************************************/
void AppleSpeed(int i)
{
	if (gApple[i].img == image.apple[REDAPPLE]) {
		gApple[i].speed = 1;//�ԃ����S
	}
	else if (gApple[i].img == image.apple[BLUEAPPLE]) {
		gApple[i].speed = 2;//�����S
	}
	else if (gApple[i].img == image.apple[GOLDAPPLE]) {
		gApple[i].speed = 3.5;//�������S
	}
	else if (gApple[i].img == image.apple[POISONAPPLE]) {
		gApple[i].speed = 0.5;//�Ń����S
	}
}

/************************************************
*�@�e��񂲂̃J�E���g�ϐ��̏�����
************************************************/
void AppleInit() 
{
	for (int i = 0; i < APPLE_MAX; i++) {
		gApple[i].flg = FALSE;
	}
	apple.gRACount = 0;
	apple.gBACount = 0;
	apple.gGACount = 0;
	apple.gPACount = 0;
	apple.gScore = 0;
}

/************************************************
*�@��񂲂̓����蔻��
************************************************/
int HitBox(void)
{
	double sx1[10];
	double sy1[10];
	double sx2[10];
	double sy2[10];

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			sx1[i] = gApple[i].x - 31;	//���� X
			sy1[i] = gApple[i].y - 60;	//���� Y
			sx2[i] = gApple[i].x + 31;	//�E�� X
			sy2[i] = gApple[i].y + 60;	//�E�� Y
		}
	}

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			for (int j = 0; j < 10; j++) {
				if (gApple[i].img == gApple[j].img) {
					if (sx1[i] == sx1[j] && sx2[j] == sx2[i] && sy1[i] < sy1[j] && sy1[j] < sy2[i]) {
						gApple[i].flg = FALSE;	//�폜
					}
				}
			}
		}
	}

	return 0;

}

/******************************************************
* �v���C���[�̓����蔻�聕�v���C���[�Ƃ�񂲂̐ڐG����
******************************************************/
int HitBoxPlayer(void) {
	double sx1[10];
	double sy1[10];
	double sx2[10];
	double sy2[10];

	

	for (int i = 0; i < 10; i++) {
		if (gApple[i].img == image.apple[POISONAPPLE]) {//�ł�񂲂̓����蔻��
			if (gApple[i].flg == TRUE) {
				sx1[i] = gApple[i].x - 40;	//���� X
				sy1[i] = gApple[i].y - 37;	//���� Y
				sx2[i] = gApple[i].x + 40;	//�E�� X
				sy2[i] = gApple[i].y + 37;	//�E�� Y
			}
		}
		else {											//�ł�񂲈ȊO�̓����蔻��
			if (gApple[i].flg == TRUE) {
				sx1[i] = gApple[i].x - 46;	//���� X
				sy1[i] = gApple[i].y - 43;	//���� Y
				sx2[i] = gApple[i].x + 46;	//�E�� X
				sy2[i] = gApple[i].y + 43;	//�E�� Y
			}
		}
	}

	if (GetBlinkFlg() == 0) {	//�_�Œ��͓�����Ȃ��悤��
		for (int i = 0; i < 10; i++) {
			if (gApple[i].flg == TRUE) {

				if (px1 < sx2[i] && sx1[i] < px2 && py1 < sy2[i] && sy1[i] < py2) {
					if (gApple[i].img == image.apple[POISONAPPLE]) {
						//player.SetPlayerBlinkFlg(1);
						SetBlinkFlg(1);
					}
					gApple[i].flg = FALSE;	//�폜
					ApplePoint(i);//�X�R�A����

				}
			}
		}
	}
	std::string str1 = std::to_string(apple.gRACount);
	std::string str2 = std::to_string(apple.gBACount);
	std::string str3 = std::to_string(apple.gGACount);

	DrawStringToHandle(1020, 400, str1.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(1120, 400, str2.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(1225, 400, str3.c_str(), 0x000000, font.handle_1_64, 0xffffff);

	return 0;
}

/************************************************
*�@��񂲂̃X�R�A����
************************************************/
void ApplePoint(int i)
{
	if (gApple[i].img == image.apple[REDAPPLE]) {//�Ԃ��
		apple.gScore += 100;
		apple.gRACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == image.apple[BLUEAPPLE]) {//���
		apple.gScore += 200;
		apple.gBACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == image.apple[GOLDAPPLE]) {//�����
		apple.gScore += 500;
		apple.gGACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == image.apple[POISONAPPLE]) {//�ł��
		apple.gScore -= 750;
		apple.gPACount += 1;
		if (apple.gScore < 0) {
			apple.gScore = 0;
		}
		PlaySoundMem(sound.se_poisonapple, DX_PLAYTYPE_BACK, TRUE);
	}
}

/************************************************
*�@���̑��֐�
************************************************/
int ReturnRA(void) {
	return apple.gRACount;
}

int ReturnBL(void) {
	return apple.gBACount;
}

int ReturnGL(void) {
	return apple.gGACount;
}

int ReturnPO(void) {
	return apple.gPACount;
}

int ReturnScore(void) {
	return (int)apple.gScore;
}

int ReturnAppleX(int num) {
	return (int)gApple[num].x;
}

int ReturnAppleY(int num) {
	return (int)gApple[num].y;
}

int ReturnAppleImg(int num) {
	return gApple[num].img;
}


int ReturnAppleFlg(int num) {
	return gApple[num].flg;
}

void SetAppleCount(int num) {
	apple.gRACount = num;
	apple.gBACount = num;
	apple.gGACount = num;
	apple.gPACount = num;
}


void GetPlayerX(int xPos) {
	px1 = xPos - 30;
	/*py1 = player.ReturnPlayerY() - 90;*/
	px2 = xPos + 30;
	//py2 = player.ReturnPlayerY() + 120;
}

void GetPlayerY(int yPos) {
	//px1 = player.ReturnPlayerX() - 30;
	py1 = yPos - 90;
	//px2 = player.ReturnPlayerX() + 30;
	py2 = yPos + 120;
}

int GetBlinkFlg() {
	return AppleBlinkFlg;
}

int SetBlinkFlg(int flg) {
	AppleBlinkFlg = flg;
	return AppleBlinkFlg;
}