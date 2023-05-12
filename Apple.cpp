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
*�@�ϐ��̐錾
************************************************/
int gFPSCount = 0;

using std::string;
using std::to_string;

extern Image image;			//��񂲂̉摜
extern Font font;			//�t�H���g
extern Sound sound;			//�T�E���h

int AppleBlinkFlg;

/************************************************
*�@�I�u�W�F�N�g�錾
************************************************/
Apple apple;
PlayerBox PB;

/************************************************
*�@������
************************************************/
void AppleInit(void) {
	for (int i = 0; i < APPLE_MAX; i++) {
		apple.gApple[i].flg = 0;						
		apple.gApple[i].img = 0;
		apple.gApple[i].x = 0;
		apple.gApple[i].y = 0;
		apple.gApple[i].w = 0;
		apple.gApple[i].h  =0;
		apple.gApple[i].speed = 0;
		apple.gApple[i].point = 0;
	}
}


/************************************************
*�@�����S��������
************************************************/
void FallApple(void)
{
	for (int i = 0; i < APPLE_MAX; i++) {

		if (apple.gApple[i].flg == TRUE) {
			//�����S�̕\��
			DrawRotaGraph((int)apple.gApple[i].x, (int)apple.gApple[i].y, 0.19, 0, apple.gApple[i].img, TRUE);

			//�^���������Ɉړ�
			apple.gApple[i].y += apple.gApple[i].speed;

			//��񂲂̍��W���P�O�O�O�ɂȂ������񂲂�����
			if (apple.gApple[i].y > 1000 + apple.gApple[i].h) {
				apple.gApple[i].flg = FALSE;
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

	apple.gP = GetRand(99);//100%

	if (apple.gP < 59) {
		AppleImg = image.apple[REDAPPLE];//�ԃ����S
	}
	else if (apple.gP >= 60 && apple.gP < 84) {
		AppleImg = image.apple[BLUEAPPLE];//�����S
	}
	else if (apple.gP >= 85 && apple.gP < 94) {
		AppleImg = image.apple[GOLDAPPLE];//�������S
	}
	else if (apple.gP >= 95 && apple.gP < 99) {
		AppleImg = image.apple[POISONAPPLE];//�Ń����S
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		if (apple.gApple[i].flg == FALSE) {
			apple.gApple[i].img = AppleImg;				//�����S�̉摜
			apple.gApple[i].x = 70 + (GetRand(6) * 130);	//��񂲂̃��[������
			apple.gApple[i].y = -50;						//�����S�̏���Y���W
			AppleSpeed(i);							//�����S�̑��x

			//����
			return apple.gApple[i].flg = TRUE;
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
	if (apple.gApple[i].img == image.apple[REDAPPLE]) {
		apple.gApple[i].speed = 1;//�ԃ����S
	}
	else if (apple.gApple[i].img == image.apple[BLUEAPPLE]) {
		apple.gApple[i].speed = 2;//�����S
	}
	else if (apple.gApple[i].img == image.apple[GOLDAPPLE]) {
		apple.gApple[i].speed = 3.5;//�������S
	}
	else if (apple.gApple[i].img == image.apple[POISONAPPLE]) {
		apple.gApple[i].speed = 0.5;//�Ń����S
	}
}

/************************************************
*�@�e��񂲂̃J�E���g�ϐ��̏�����
************************************************/
//void AppleInit(void) 
//{
//	for (int i = 0; i < APPLE_MAX; i++) {
//		apple.flg[9] = FALSE;
//	}
//	apple.gRACount = 0;
//	apple.gBACount = 0;
//	apple.gGACount = 0;
//	apple.gPACount = 0;
//	apple.gScore = 0;
//}

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
		if (apple.gApple[i].flg == TRUE) {
			sx1[i] = apple.gApple[i].x - 31;	//���� X
			sy1[i] = apple.gApple[i].y - 60;	//���� Y
			sx2[i] = apple.gApple[i].x + 31;	//�E�� X
			sy2[i] = apple.gApple[i].y + 60;	//�E�� Y
		}
	}

	for (int i = 0; i < 10; i++) {
		if (apple.gApple[i].flg == TRUE) {
			for (int j = 0; j < 10; j++) {
				if (apple.gApple[i].img == apple.gApple[i].img) {
					if (sx1[i] == sx1[j] && sx2[j] == sx2[i] && sy1[i] < sy1[j] && sy1[j] < sy2[i]) {
						apple.gApple[i].flg = FALSE;	//�폜
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
		if (apple.gApple[i].img == image.apple[POISONAPPLE]) {//�ł�񂲂̓����蔻��
			if (apple.gApple[i].flg == TRUE) {
				sx1[i] = apple.gApple[i].x - 40;	//���� X
				sy1[i] = apple.gApple[i].y - 37;	//���� Y
				sx2[i] = apple.gApple[i].x + 40;	//�E�� X
				sy2[i] = apple.gApple[i].y + 37;	//�E�� Y
			}
		}
		else {											//�ł�񂲈ȊO�̓����蔻��
			if (apple.gApple[i].flg == TRUE) {
				sx1[i] = apple.gApple[i].x - 46;	//���� X
				sy1[i] = apple.gApple[i].y - 43;	//���� Y
				sx2[i] = apple.gApple[i].x + 46;	//�E�� X
				sy2[i] = apple.gApple[i].y + 43;	//�E�� Y
			}
		}
	}

	/*px1 = player.ReturnPlayerX() - 30;
	py1 = player.ReturnPlayerY() - 90;
	px2 = player.ReturnPlayerX() + 30;
	py2 = player.ReturnPlayerY() + 120;*/

	//�v���C���[�Ƃ�񂲂��ڐG�������񂲂�������
	for (int i = 0; i < 10; i++) {
		if (apple.gApple[i].flg == TRUE) {
			
			if (PB.px1 < sx2[i] && sx1[i] < PB.px2 && PB.py1 < sy2[i] && sy1[i] < PB.py2) {
				if (apple.gApple[i].img == image.apple[POISONAPPLE]) {
					//player.SetPlayerBlinkFlg(1);
					SetBlinkFlg(1);
				}
				apple.gApple[i].flg = FALSE;	//�폜
				ApplePoint(i);//�X�R�A����
	
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
	if (apple.gApple[i].img == image.apple[REDAPPLE]) {//�Ԃ��
		apple.gScore += 100;
		apple.gRACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (apple.gApple[i].img == image.apple[BLUEAPPLE]) {//���
		apple.gScore += 200;
		apple.gBACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (apple.gApple[i].img == image.apple[GOLDAPPLE]) {//�����
		apple.gScore += 500;
		apple.gGACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (apple.gApple[i].img == image.apple[POISONAPPLE]) {//�ł��
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
	return (int)apple.gApple[num].x;
}

int ReturnAppleY(int num) {
	return (int)apple.gApple[num].y;
}

int ReturnAppleImg(int num) {
	return apple.gApple[num].img;
}


int ReturnAppleFlg(int num) {
	return apple.gApple[num].flg;
}

void SetAppleCount(int num) {
	apple.gRACount = num;
	apple.gBACount = num;
	apple.gGACount = num;
	apple.gPACount = num;
}


void GetPlayerX(int xPos) {
	PB.px1 = xPos - 30;
	/*py1 = player.ReturnPlayerY() - 90;*/
	PB.px2 = xPos + 30;
	//py2 = player.ReturnPlayerY() + 120;
}

void GetPlayerY(int yPos) {
	//px1 = player.ReturnPlayerX() - 30;
	PB.py1 = yPos - 90;
	//px2 = player.ReturnPlayerX() + 30;
	PB.py2 = yPos + 120;
}

int GetBlinkFlg() {
	return AppleBlinkFlg;
}

int SetBlinkFlg(int flg) {
	AppleBlinkFlg = flg;
	return AppleBlinkFlg;
}