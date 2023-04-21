#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include"UI.h"

extern Image image;
extern Font font;

extern Game game;
extern UI ui;

/********************************
* ���U���g���
********************************/
void DrawResult() { // ������
	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	DrawStringToHandle(160, 180, "�ԃ����S", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 250, "�����S", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 320, "�������S", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 390, "�Ń����S", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(220, 460, "�X�R�A", 0x000000, font.handle_1_64, 0xffffff);

	// �߂�\��
	DrawStringToHandle(530, 670, "A�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

	// Space �Ń^�C�g��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};