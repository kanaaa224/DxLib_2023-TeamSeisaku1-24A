// ��F����

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

#include "DxLib.h"
#include "resourceLoad.h"
#include "ranking_name_input.h"
#include "ranking.h"
#include "Apple.h"
#include <string>
#include "main.h"

#include "PadInput.h"

extern Image image;
extern Font font;

extern Game game;

using std::string;
using std::to_string;

int gRankingImg;	//�����L���O��ʔw�i

//�����L���O�f�[�^�\����
struct RankingData {
	int number;
	char name[10];
	long score;
};

//�����L���O�f�[�^�̕ϐ��錾
struct RankingData gRanking[RANKING_DATA];

int ranking_state;

/********************************
* �����L���O
********************************/
void DrawRanking() {
	if (ranking_state == 0) {
		// �v���C�X�R�A�������L���O�̍ŉ��ʃX�R�A�𒴂��Ă����珑������
		if (GetRankingFlg() == 1) {
			// ���O���͂��ꂽ��
			if (GetRankingNameInputState() == 1) {
				if (GetInputedNameLength() <= 1) {
					// �X�R�A�������ݏ���
					for (int i = 0; i < GetInputedNameLength(); i++) {
						// �ꕶ�����擾
						gRanking[RANKING_DATA - 1].name[i] = GetInputedName(i);
					};
					gRanking[RANKING_DATA - 1].name[GetInputedNameLength()] = '\0'; // Null�����t�^
					gRanking[RANKING_DATA - 1].score = ReturnScore(); // �����L���O�f�[�^�̍ŉ��ʂɃX�R�A��o�^
					SortRanking(); // �����L���O���בւ�
					SaveRanking(); // �����L���O�f�[�^�̕ۑ�
				};
			};
		};
		ranking_state = 1; // �܂����s���Ȃ��悤��
	};

	int RgScore = 0;
	RgScore = ReturnScore();

    // �w�i�\��
    DrawGraph(0, 0, image.title, TRUE);

    DrawStringToHandle(360, 10, "�����L���O", 0x000000, font.handle_1_128, 0xffffff);

	for (int i = 0; i < RANKING_DATA; i++) {
		std::string str = std::to_string(gRanking[i].number) + "��";
		DrawStringToHandle(200, 150 + i * 100, str.c_str(), 0x000000, font.handle_1_64, 0xffffff);
		DrawStringToHandle(380, 150 + i * 100, gRanking[i].name, 0x000000, font.handle_1_64, 0xffffff);
		str = std::to_string(gRanking[i].score);
		DrawStringToHandle(1000, 150 + i * 100, str.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	};

	// �߂�\��
	DrawStringToHandle(530, 670, "A�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);
	if (JudgeButton(XINPUT_BUTTON_A) == 1) {
		game.mode = TITLE;
	};
	// �L�[�{�[�h�Ή�
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};

/********************************
* �����L���O���בւ�
********************************/
void SortRanking(void) {
	int i, j;
	RankingData work;

	//�I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			};
		};
	};

	//���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].number = 1;
	};
	//���_�������ꍇ�́A�������ʂƂ���B
	//�����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���B
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].number++;
			};
		};
	};
};

/********************************
* �����L���O�f�[�^�̕ۑ�
********************************/
int SaveRanking(void) {
	FILE* fp;
	#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("Resources/dat/rankingdata.txt", "w")) == NULL) {
		/*�G���[����*/
		printf("Ranking Data Error\n");
		return -1;
	};

	//�����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].number, gRanking[i].name, gRanking[i].score);
	};

	//�t�@�C���N���[�Y
	fclose(fp);
	return 0;
};

/********************************
* �����L���O�f�[�^�ǂݍ���
********************************/
int ReadRanking(void) {
	FILE* fp;
	#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("Resources/dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	};

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANKING_DATA; i++) {
		int dammy = fscanf(fp, "%2d %10s %d10", &gRanking[i].number, gRanking[i].name, &gRanking[i].score);
	};

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
};

/********************************
* �X�R�A�������L���O�ŉ��ʂ𒴂������̔��f��Ԃ��֐�
********************************/
int GetRankingFlg() {
	// �ŉ��ʂƌ��݂̃X�R�A���r
	if (gRanking[RANKING_DATA - 1].score <= ReturnScore()) {
		return 1;
	}
	else {
		return 0;
	};
};

/********************************
* �����L���O�t���O�ݒ�
********************************/
void SetRankingState(int flg) {
	ranking_state = flg;
};