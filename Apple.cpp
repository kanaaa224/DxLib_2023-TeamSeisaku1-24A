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
*�@�ϐ��̏�����
************************************************/
extern int gP = 0;

extern int gTimeFlg = FALSE;//���Ԍv���p�̕ϐ�

extern int gFPSCount = 0;

extern int gRACount = 0;	//�Ԃ�񂲂̌�
extern int gBACount = 0;	//��񂲂̌�
extern int gGACount = 0;	//����񂲂̌�
extern int gPACount = 0;	//�ł�񂲂̌�
extern int gScore = 0;		//�X�R�A

using std::string;
using std::to_string;

extern Image image;		//��񂲂̉摜�ϐ�
extern Font font;
extern Sound sound;

/************************************************
*�@�����S��������
************************************************/
void FallApple(void)
{
	for (int i = 0; i < APPLE_MAX; i++) {

		if (gApple[i].flg == TRUE) {

			////�e�X�g
			//SetFontSize(16);
			//DrawFormatString(0, 0, 0xffffff, "Y:%3d", gApple[i].y);
			//DrawFormatString(100, 0, 0xffffff, "X:%3d", gApple[i].x);

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

	//gOldTime;//�O���ԁi�O���Ԃƌ㎞�Ԃ��r���Ă�񂲂��\������Ă��牽�b�������v������ϐ��j
	//gNowTime;//�㎞�ԁi�O���Ԃƌ㎞�Ԃ��r���Ă�񂲂��\������Ă��牽�b�������v������ϐ��j
	//gTimeFlg;

	//if (gTimeFlg == FALSE) {
	//	gOldTime = GetNowCount();
	//	gTimeFlg = TRUE;
	//}

	//gNowTime = GetNowCount();

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
			gApple[i].y = -150;						//�����S�̏���Y���W
			AppleSpeed(i);							//�����S�̑��x

			//����
			return gApple[i].flg = TRUE;
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
	if (gP < 59) {
		gApple[i].speed = 1;//�ԃ����S
	}
	else if (gP >= 60 && gP < 84) {
		gApple[i].speed = 2;//�����S
	}
	else if (gP >= 85 && gP < 94) {
		gApple[i].speed = 3.5;//�������S
	}
	else if (gP >= 95 && gP < 99) {
		gApple[i].speed = 0.5;//�Ń����S
	}
}

void AppleInit(int num) {
	for (int i = 0; i < APPLE_MAX; i++) {
		gApple[i].flg = FALSE;
	}
	gRACount = num;
	gBACount = num;
	gGACount = num;
	gPACount = num;
	gScore = num;
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
						gApple[j].flg = FALSE;	//�폜
					}
				}
			}
		}
	}

	return 0;

}

int HitBoxPlayer(void) {
	double sx1[10];
	double sy1[10];
	double sx2[10];
	double sy2[10];

	double px1;
	double py1;
	double px2;
	double py2;

	for (int i = 0; i < 10; i++) {
		if (gApple[i].img == image.apple[POISONAPPLE]) {//�ł�񂲂̓����蔻��
			if (gApple[i].flg == TRUE) {
				sx1[i] = gApple[i].x - 40;	//���� X
				sy1[i] = gApple[i].y - 37;	//���� Y
				sx2[i] = gApple[i].x + 40;	//�E�� X
				sy2[i] = gApple[i].y + 37;	//�E�� Y
			}
		}
		else {											//����ȊO�̓����蔻��
			if (gApple[i].flg == TRUE) {
				sx1[i] = gApple[i].x - 46;	//���� X
				sy1[i] = gApple[i].y - 43;	//���� Y
				sx2[i] = gApple[i].x + 46;	//�E�� X
				sy2[i] = gApple[i].y + 43;	//�E�� Y
			}
		}
	}

	px1 = ReturnPlayerX() - 30;
	py1 = ReturnPlayerY() - 30;
	px2 = ReturnPlayerX() + 30;
	py2 = ReturnPlayerY() + 30;

	DrawBox((int)px1, (int)py1, (int)px2, (int)py2, 0xffffff, TRUE);

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			DrawBox((int)sx1[i], (int)sy1[i], (int)sx2[i], (int)sy2[i], 0xffffff, TRUE);
		}
	}

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			
			if (px1 < sx2[i] && sx1[i] < px2 && py1 < sy2[i] && sy1[i] < py2) {
				if (gApple[i].img == image.apple[POISONAPPLE]) {
					SetPlayerBlinkFlg(1);
				}
				gApple[i].flg = FALSE;	//�폜
				ApplePoint(i);//�X�R�A����
	
			}
		}

	}
	std::string str1 = std::to_string(gRACount);
	std::string str2 = std::to_string(gBACount);
	std::string str3 = std::to_string(gGACount);

	DrawStringToHandle(1020, 400, str1.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(1120, 400, str2.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(1225, 400, str3.c_str(), 0x000000, font.handle_1_64, 0xffffff);

	SetFontSize(16);
	DrawFormatString(0, 100, 0xffffff, "Score:%d", gScore);
	DrawFormatString(0, 120, 0xffffff, "RED:%d", gRACount);
	DrawFormatString(0, 140, 0xffffff, "BLUE:%d", gBACount);
	DrawFormatString(0, 160, 0xffffff, "GOLD:%d", gGACount);
	DrawFormatString(0, 180, 0xffffff, "POISON:%d", gPACount);

	return 0;
}

/************************************************
*�@��񂲂̃X�R�A����
************************************************/
void ApplePoint(int i)
{
	if (gApple[i].img == image.apple[REDAPPLE]) {//�Ԃ��
		gScore += 100;
		gRACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == image.apple[BLUEAPPLE]) {//���
		gScore += 200;
		gBACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == image.apple[GOLDAPPLE]) {//�����
		gScore += 500;
		gGACount += 1;
		PlaySoundMem(sound.se_apple, DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == image.apple[POISONAPPLE]) {//�ł��
		gScore -= 750;
		gPACount += 1;
		if (gScore < 0) {
			gScore = 0;
		}
		PlaySoundMem(sound.se_poisonapple, DX_PLAYTYPE_BACK, TRUE);
	}
}

int ReturnRA(void) {
	return gRACount;
}

int ReturnBL(void) {
	return gBACount;
}

int ReturnGL(void) {
	return gGACount;
}

int ReturnPO(void) {
	return gPACount;
}

int ReturnScore(void) {
	return (int)gScore;
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
	gRACount = num;
	gBACount = num;
	gGACount = num;
	gPACount = num;
}


