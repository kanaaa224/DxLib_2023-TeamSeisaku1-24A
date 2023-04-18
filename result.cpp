#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* ���U���g���
********************************/
void DrawResult() {
	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	DrawStringToHandle(340, 140, "���U���g���", 0x000000, font.handle_1_32, 0xffffff);

	// �߂�\��
	DrawStringToHandle(420, 670, "ESC�L�[�܂���B�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

	// Space �Ń^�C�g��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};