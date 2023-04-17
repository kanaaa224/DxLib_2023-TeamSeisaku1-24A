// ��F����

#include "DxLib.h"
#include "resourceLoad.h"
#include "help.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

Help help;

int mirutame[3];

/********************************
* �w���v��ʕ`��
********************************/
void DrawHelp() {
	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	// �^�C�g���\��
	DrawStringToHandle(180, 40, "�w���v", 0x000000, font.handle_1_128, 0xffffff);

	// �����\��
	DrawStringToHandle(650, 130, "���L�[�܂��͍��X�e�B�b�N�Ő؂肩��", 0x000000, font.handle_1_32, 0xffffff);

	// �߂�\��
	DrawStringToHandle(420, 670, "ESC�L�[�܂���B�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

	// �����o�[�ϐ��ɕۑ����ꂽ�X�e�[�g�ŕ\���𕪊�
	if (help.state == 0) {
		// �R���g���[���[�̃w���v�\��

		// �R���g���[���[�摜�\��
		DrawExtendGraph(200, 300, 500, 500, image.controller, TRUE);
		DrawExtendGraph(400, 500, 500, 600, image.controller_s, TRUE);

		// �T�u�^�C�g���\��
		DrawStringToHandle(700, 40, "�������", 0x000000, font.handle_1_64, 0xffffff);

		DrawCircle(250, 350, 20, 0xffffff, FALSE);
	}
	else if (help.state == 1) {
		// �Q�[�����e�̃w���v�\��
		
		// �T�u�^�C�g���\��
		DrawStringToHandle(700, 40, "�Q�[������", 0x000000, font.handle_1_64, 0xffffff);




	}

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		help.state = 0;
	};
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		help.state = 1;
	};

	// ��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};

	// �J���p
	DrawCircle(mirutame[0], mirutame[1], mirutame[2], 0xffffff, FALSE);
	DrawFormatString(mirutame[0], mirutame[1], 0xffffff, "%d - %d", mirutame[0], mirutame[1]);
	if (CheckHitKey(KEY_INPUT_W)) {
		mirutame[1]--;
	};
	if (CheckHitKey(KEY_INPUT_S)) {
		mirutame[1]++;
	};
	if (CheckHitKey(KEY_INPUT_A)) {
		mirutame[0]--;
	};
	if (CheckHitKey(KEY_INPUT_D)) {
		mirutame[0]++;
	};
	if (CheckHitKey(KEY_INPUT_Q)) {
		mirutame[2]++;
	};
	if (CheckHitKey(KEY_INPUT_E)) {
		mirutame[2]--;
	};
};