#include "DxLib.h"
#include "resourceLoad.h"
#include "Apple.h"
#include "main.h"
#include "UI.h"

extern Image image;
extern Font font;

extern Game game;
extern UI ui;

int RED_AppleCount = 0;
int BLUE_AppleCount = 0;
int GOLD_AppleCount = 0;
int POISON_AppleCount = 0;
int AppleScore = 0;

/********************************
* ���U���g���
********************************/
void DrawResult() { // ������

	RED_AppleCount		= ReturnRA();
	BLUE_AppleCount		= ReturnBL();
	GOLD_AppleCount		= ReturnGL();
	POISON_AppleCount	= ReturnPO();
	AppleScore			= ReturnScore();

	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	DrawBox(300, 160, 800, 550, 0xffffff, TRUE);

	//�ԁ@�@���@�Ł@�X�R�A
	DrawStringToHandle(320, 180, "�ԃ����S�F", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 250, "�����S�F", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 320, "�������S�F", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 390, "�Ń����S�F", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 460, "�X�R�A�F", 0x000000, font.handle_1_64, 0xffffff);

	//�J�E���g�\��
	DrawFormatStringFToHandle(660, 180, 0x000000, font.handle_1_64, "%d", RED_AppleCount);
	DrawFormatStringFToHandle(660, 250, 0x000000, font.handle_1_64, "%d", BLUE_AppleCount);
	DrawFormatStringFToHandle(660, 320, 0x000000, font.handle_1_64, "%d", GOLD_AppleCount);
	DrawFormatStringFToHandle(660, 390, 0x000000, font.handle_1_64, "%d", POISON_AppleCount);
	DrawFormatStringFToHandle(660, 460, 0x000000, font.handle_1_64, "%d", AppleScore);

	// �߂�\��
	DrawStringToHandle(530, 670, "A�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

	// Space �Ń^�C�g��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};