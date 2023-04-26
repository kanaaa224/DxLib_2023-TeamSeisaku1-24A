#include "DxLib.h"
#include "resourceLoad.h"
#include <string>
#include "Apple.h"
#include "main.h"
#include"UI.h"


extern Image image;
extern Font font;

extern Game game;
extern UI ui;

using std::string;
using std::to_string;

int RED_AppleCount = 0;
int BLUE_AppleCount = 0;
int GOLD_AppleCount = 0;
int POISON_AppleCount = 0;
int AppleScore = 0;

//int RED_AppleCount = 12345;


/********************************
* ���U���g���
********************************/

void DrawResult() { // ������

	RED_AppleCount		= ReturnRA();
	BLUE_AppleCount		= ReturnBL();
	GOLD_AppleCount		= ReturnGL();
	POISON_AppleCount	= ReturnPO();
	AppleScore			= ReturnScore();

	std::string RED = "�ԃ����S�F" + std::to_string(RED_AppleCount);
	std::string BLUE = "�����S�F" + std::to_string(BLUE_AppleCount);
	std::string GOLD = "�������S�F" + std::to_string(GOLD_AppleCount);
	std::string POISON = "�Ń����S�F" + std::to_string(POISON_AppleCount);
	std::string SCORE = "�X�R�A�F" + std::to_string(AppleScore);

	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	DrawBox(300, 160, 800, 550, 0xFDF5E6, TRUE);
	DrawBox(300, 160, 801, 551, 0x000000, FALSE);

	//�ԁ@�@���@�Ł@�X�R�A
	DrawStringToHandle(320, 180, RED.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 250, BLUE.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 320, GOLD.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 390, POISON.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 460, SCORE.c_str(), 0x000000, font.handle_1_64, 0xffffff);

	//�J�E���g�\��
	//DrawFormatStringFToHandle(660, 180,  0x000000, font.handle_1_64,  "%d", RED_AppleCount);
	
	// �߂�\��
	DrawStringToHandle(420, 670, "ESC�L�[�܂���A�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);
	//DrawStringToHandle(530, 670, "B�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

	// Space �Ń^�C�g��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};