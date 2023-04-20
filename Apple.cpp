/************************************************
*�@��񂲂̏����v���O����
*�@����F�L���A�V��
************************************************/
#include "DxLib.h"
#include "Apple.h"
#include "resourceLoad.h"
#include "player.h"

/************************************************
*�@�ϐ��̐錾�i�O���[�o���ϐ��j
************************************************/
//int gAppleImg[20];	//��񂲂̉摜�ϐ�
int gP;					//��񂲂̊m��

int gOldTime;			//�O���ԁi�O���Ԃƌ㎞�Ԃ��r���Ă�񂲂��\������Ă��牽�b�������v������ϐ�
int gNowTime;			//�㎞�ԁi�O���Ԃƌ㎞�Ԃ��r���Ă�񂲂��\������Ă��牽�b�������v������ϐ�
int gTimeFlg = FALSE;	//���Ԍv���p�̕ϐ�

int gFPSCount = 0;

int gRACount = 0;	//�Ԃ�񂲂̌�
int gBACount = 0;	//��񂲂̌�
int gGACount = 0;	//����񂲂̌�
int gPACount = 0;	//�ł�񂲂̌�
int gScore = 0;		//�X�R�A

extern Image image;		//��񂲂̉摜�ϐ�

/************************************************
*�@�萔�̐錾
************************************************/
const int APPLE_MAX = 10;

/************************************************
*�@�摜�Ǎ�
************************************************/
//int LoadImges(void)
//{
//	//��񂲉摜�f�[�^�̕����ǂݍ���
//	if (LoadDivGraph("images/Apple.png", 20, 5, 4, 700, 620, gAppleImg) == -1)return -1;
//}

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
			DrawRotaGraph(gApple[i].x, gApple[i].y, 0.19, 0, gApple[i].img, TRUE);

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
	gP = 0;

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

/************************************************
*�@��񂲂̓����蔻��
************************************************/
int HitBox(void)
{
	int sx1[10];
	int sy1[10];
	int sx2[10];
	int sy2[10];

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
	int sx1[10];
	int sy1[10];
	int sx2[10];
	int sy2[10];

	int px1;
	int py1;
	int px2;
	int py2;

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			sx1[i] = gApple[i].x - 51;	//���� X
			sy1[i] = gApple[i].y - 50;	//���� Y
			sx2[i] = gApple[i].x + 51;	//�E�� X
			sy2[i] = gApple[i].y + 50;	//�E�� Y
		}
	}

	px1 = ReturnPlayerX() - 30;
	py1 = ReturnPlayerY() - 30;
	px2 = ReturnPlayerX() + 30;
	py2 = ReturnPlayerY() + 30;

	DrawBox(px1, py1, px2, py2, 0xffffff, TRUE);

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			DrawBox(sx1[i], sy1[i], sx2[i], sy2[i], 0xffffff, TRUE);
		}
		DrawFormatString(390, 100, 0xffffff, "%d", sy1[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {

			if (px1 < sx2[i] && sx1[i] < px2 && py1 < sy2[i] && sy1[i] < py2) {
				gApple[i].flg = FALSE;	//�폜
				ApplePoint(i);
			}

			
			/*if (py1 < sy2[i]) {
				gApple[i].flg = FALSE;
			}*/
		}
	}
	
	SetFontSize(16);
	DrawFormatString(0, 100, 0xffffff, "Score:%d", gScore);
	DrawFormatString(0, 120, 0xffffff, "RED:%d", gRACount);
	DrawFormatString(0, 140, 0xffffff, "BULE:%d", gBACount);
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
	}
	if (gApple[i].img == image.apple[BLUEAPPLE]) {//���
		gScore += 200;
		gBACount += 1;
	}
	if (gApple[i].img == image.apple[GOLDAPPLE]) {//�����
		gScore += 500;
		gGACount += 1;
	}
	if (gApple[i].img == image.apple[POISONAPPLE]) {//�ł��
		gScore -= 750;
		gPACount += 1;
		if (gScore < 0) {
			gScore = 0;
		}
	}
}