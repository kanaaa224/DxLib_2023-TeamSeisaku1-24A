// ��F����

#define _USE_MATH_DEFINES
#define RANKING_DATA 5
#include <stdio.h>
#include <math.h>

#include "DxLib.h"
#include "resourceLoad.h"
#include "ranking_name_input.h"
#include <string>
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

extern NameInput nameInput;

using std::string;
using std::to_string;

int gRankingImg;	//�����L���O��ʔw�i

//�����L���O�f�[�^�\����
struct RankingData {
	int number;
	char name[11];
	long score;
};

//�����L���O�f�[�^�̕ϐ��錾
struct RankingData gRanking[RANKING_DATA];

/********************************
* �����L���O
********************************/
void DrawRanking() {

	//std::string RED = "�ԃ����S�F" + std::to_string(RED_AppleCount);

	nameInput.inputedName;

    // �w�i�\��
    DrawGraph(0, 0, image.title, TRUE);

    DrawStringToHandle(340, 10, "�����L���O", 0x000000, font.handle_1_128, 0xffffff);
 
    // �߂�\��
    DrawStringToHandle(530, 670, "A�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

    // ��
    if (CheckHitKey(KEY_INPUT_R)) {
        game.mode = INPUTNAME;
    };

    // ��
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        game.mode = TITLE;
    };

	SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {

		DrawFormatStringFToHandle(240, 150 + i * 100, 0x000000, font.handle_1_64, "%d�� %s %d", gRanking[i].number, gRanking[i].name, gRanking[i].score);
	}

	//DrawString(100, 450, "--- �X�y�[�X�L�[�������ă^�C�g���֖߂� ---", 0xff0000, 0);

    // �t�@�C���ǂݍ��ݑΉ�
    // �p�b�h�Ή�
};

//�����L���O���בւ�
void SortRanking(void)
{
	int i, j;
	RankingData work;

	//�I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}

	//���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].number = 1;
	}
	//���_�������ꍇ�́A�������ʂƂ���B
	//�����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���B
	for (i = 0; i < RANKING_DATA; i++) {
		for (j = i + j; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[i].score) {
				gRanking[j].number++;
			}
		}
	}
}

//�����L���O�f�[�^�̕ۑ�
int SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("Resources/dat/rankingdata.txt", "w")) == NULL) {
		/*�G���[����*/
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].number, gRanking[i].name, gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
	return 0;
}

//�����L���O�f�[�^�ǂݍ���
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("Resources/dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANKING_DATA; i++) {
		int dammy = fscanf(fp, "%d %s %d", &gRanking[i].number, gRanking[i].name, &gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}
