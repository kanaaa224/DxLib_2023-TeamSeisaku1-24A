// ��F����

#include "DxLib.h"
#include "resourceLoad.h"
#include "help.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

Help help;

/********************************
* �w���v��ʕ`��
********************************/
void DrawHelp() {
	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	// �R���g���[���[�摜�\��
	DrawExtendGraph(0, 0, 200, 100, image.controller, TRUE);
	DrawExtendGraph(0, 0, 100, 100, image.controller_s, TRUE);

	// �����T�C�Y�w��
	SetFontSize(10);

	// �^�C�g���\��
	DrawStringToHandle(340, 140, "�������", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(340, 200, "esc de title", 0x000000, font.handle_1_32, 0xffffff);

	help.state = 0;
	if (help.state == 0) {
		// �R���g���[���[�̃w���v�\��


	}
	else if (help.state == 1) {
		// �Q�[�����e�̃w���v�\��
		

		// �����T�C�Y�w��
		SetFontSize(10);
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};