#include "DxLib.h"
#include "resourceLoad.h"
#include <string>
#include "Apple.h"
#include "main.h"
#include "UI.h"
#include "ranking.h"
#include "PadInput.h"
#include "result.h"

using std::string;
using std::to_string;


/********************************
* ���U���g���
********************************/
void DrawResult() { // ������

	//������ϊ�	���𑝕�����\���̓t�H���g���K������Ȃ����ߕ�����ɕϊ�
	std::string RED = "�ԃ����S�F" + std::to_string(AppleCount::ReturnRA());		//RED�ɐԃ����S�F���̕�������쐬�@
	std::string BLUE = "�����S�F" + std::to_string(AppleCount::ReturnBL());		//BLUE�ɐ����S�F���̕�������쐬
	std::string GOLD = "�������S�F" + std::to_string(AppleCount::ReturnGL());		//GOLD�ɋ������S�F���̕�������쐬
	std::string POISON = "�Ń����S�F" + std::to_string(AppleCount::ReturnPO());	//POISON�ɓŃ����S�F���̕�������쐬
	std::string SCORE = "�X�R�A�F" + std::to_string(AppleCount::ReturnScore());	//SCORE�ɃX�R�A�F�X�R�A�̕�������쐬

	// �w�i�\��
	DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	//���U���g
	DrawStringToHandle(320, 70, "RESULT", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);

	//�w�i�@��
	DrawBox(300, 160, 800, 550, 0xFDF5E6, TRUE);
	DrawBox(300, 160, 801, 551, 0x000000, FALSE);

	//�ԁ@�@���@�Ł@�X�R�A �̕�����(String)�𕶎�(Char)�ɕϊ�
	DrawStringToHandle(320, 180, RED.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(320, 250, BLUE.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(320, 320, GOLD.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(320, 390, POISON.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(320, 460, SCORE.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);

	// ����
	DrawStringToHandle(530, 670, "B�{�^���ł�����", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	// ���A�{�^���ŕ��򂳂��鏈��
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_B) == 1) {
		if (GetRankingFlg() == 1) {
            Game::ModeSet(INPUTNAME);
		}
		else {
            Game::ModeSet(RANKING);
		}
	};
	// �L�[�{�[�h�Ή�
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (GetRankingFlg() == 1) {
            Game::ModeSet(INPUTNAME);
		}
		else {
            Game::ModeSet(RANKING);
		}
	};

};