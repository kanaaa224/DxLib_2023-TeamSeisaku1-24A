#include "DxLib.h"
#include "resourceLoad.h"
#include <string>
#include "Apple.h"
#include "main.h"
#include"UI.h"
#include "ranking.h"
#include "PadInput.h"
#include "result.h"

extern Image image;	
extern Font font;

extern Game game;

using std::string;
using std::to_string;

extern int RED_AppleCount		= 0;	//�ԃ����S�@���p
extern int BLUE_AppleCount		= 0;	//�����S�@���p
extern int GOLD_AppleCount		= 0;	//�������S�@���p
extern int POISON_AppleCount	= 0;	//�Ń����S�@���p
extern int AppleScore			= 0;	//�X�R�A�@�@���p

/********************************
* ���U���g���
********************************/

void DrawResult() { // ������

	//���y�уX�R�A�̎󂯓n��
	RED_AppleCount		= ReturnRA();		//return�ŕԂ����ԃ����S�̌�����
	BLUE_AppleCount		= ReturnBL();		//return�ŕԂ��������S�̌�����
	GOLD_AppleCount		= ReturnGL();		//return�ŕԂ����������S�̌�����
	POISON_AppleCount	= ReturnPO();		//return�ŕԂ����Ń����S�̌�����
	AppleScore			= ReturnScore();	//return�ŕԂ����X�R�A����

	//������ϊ�	���𑝕�����\���̓t�H���g���K������Ȃ����ߕ�����ɕϊ�
	std::string RED = "�ԃ����S�F" + std::to_string(RED_AppleCount);		//RED�ɐԃ����S�F���̕�������쐬�@
	std::string BLUE = "�����S�F" + std::to_string(BLUE_AppleCount);		//BLUE�ɐ����S�F���̕�������쐬
	std::string GOLD = "�������S�F" + std::to_string(GOLD_AppleCount);		//GOLD�ɋ������S�F���̕�������쐬
	std::string POISON = "�Ń����S�F" + std::to_string(POISON_AppleCount); //POISON�ɓŃ����S�F���̕�������쐬
	std::string SCORE = "�X�R�A�F" + std::to_string(AppleScore);			//SCORE�ɃX�R�A�F�X�R�A�̕�������쐬

	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	//���U���g
	DrawStringToHandle(320, 70, "RESULT", 0x000000, font.handle_1_64, 0xffffff);

	//�w�i�@��
	DrawBox(300, 160, 800, 550, 0xFDF5E6, TRUE);
	DrawBox(300, 160, 801, 551, 0x000000, FALSE);

	//�ԁ@�@���@�Ł@�X�R�A �̕�����(String)�𕶎�(Char)�ɕϊ�
	DrawStringToHandle(320, 180, RED.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 250, BLUE.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 320, GOLD.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 390, POISON.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 460, SCORE.c_str(), 0x000000, font.handle_1_64, 0xffffff);

	//�J�E���g�\��
	//DrawFormatStringFToHandle(660, 180,  0x000000, font.handle_1_64,  "%d", RED_AppleCount);
	
	// ����
	DrawStringToHandle(530, 670, "B�{�^���ł�����", 0x000000, font.handle_1_32, 0xffffff);
	// ���A�{�^���ŕ��򂳂��鏈��
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		if (GetRankingFlg() == 1) {
			game.mode = INPUTNAME;
		}
		else {
			game.mode = RANKING;
		}
	};
	// �L�[�{�[�h�Ή�
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (GetRankingFlg() == 1) {
			game.mode = INPUTNAME;
		}
		else {
			game.mode = RANKING;
		}
	};

	//WaitTimer(3000);
};