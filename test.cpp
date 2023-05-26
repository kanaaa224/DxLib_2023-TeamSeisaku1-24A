/********************************
* �e�X�g
* ��ҁF����
********************************/
#include "DxLib.h"
#include "test.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"


/********************************
* �e�X�g
********************************/
void Test::Draw() {
    DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);
	
	DrawStringToHandle(400, 40, "��񂲂��Ƃ�", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(400, 90, "��񂲂��Ƃ�", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(400, 150, "��񂲂��Ƃ�", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

	DrawRotaGraph(150, 400, 0.5f, 0, Image::GetImages(IMG_APPLE,0), TRUE);

	// �߂�\��
	DrawStringToHandle(530, 670, "A�{�^���ł��ǂ�", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	// A�{�^���ŏI��
	if (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
        Game::ModeSet(TITLE);
	};

	// ESC�L�[�ŏI��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        Game::ModeSet(TITLE);
	};
};