// ��F����

#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"
#include "PadInput.h"

extern Image image;
extern Font font;

extern Game game;

int help_state = 0;

int help_selectstate;
int help_stickflg = 0;

/********************************
* �w���v��ʕ`��
********************************/
void DrawHelp() {
	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	// �^�C�g���\��
	DrawStringToHandle(180, 40, "�w���v", 0x000000, font.handle_1_128, 0xffffff);

	// �����\��
	DrawStringToHandle(680, 130, "���X�e�B�b�N�Ő�����؂肩��", 0x000000, font.handle_1_32, 0xffffff);

	// �߂�\��
	DrawStringToHandle(370, 670, "B�{�^���ŃQ�[���J�n�AA�{�^���ł��ǂ�", 0x000000, font.handle_1_32, 0xffffff);

	// �����o�[�ϐ��ɕۑ����ꂽ�X�e�[�g�ŕ\���𕪊�

	if (help_state == 0) {
		// �R���g���[���[�̃w���v�\��

		// �T�u�^�C�g���\��
		DrawStringToHandle(735, 40, "�������", 0x000000, font.handle_1_64, 0xffffff);
		DrawTriangle(1065, 55, 1105, 70, 1065, 85, 0x000000, TRUE);

		// �R���g���[���[�摜�\��
		DrawExtendGraph(330, 290, 630, 490, image.controller, TRUE);
		//DrawExtendGraph(400, 500, 500, 600, image.controller_s, TRUE);

		// B Btn
		DrawLine(587, 368, 700, 368, 0x000000);
		DrawStringToHandle(700, 345, "B�{�^���F����", 0x000000, font.handle_1_32, 0xffffff);

		// A Btn
		DrawLine(566, 392, 700, 392, 0x000000);
		DrawStringToHandle(700, 380, "A�{�^���F���ǂ�", 0x000000, font.handle_1_32, 0xffffff);

		// Left Stick
		DrawLine(436, 421, 436, 550, 0x000000);
		DrawStringToHandle(280, 550, "���X�e�B�b�N�F�v���C���[�ƁA�I�����J�[�\���̈ړ�", 0x000000, font.handle_1_32, 0xffffff);

		// Back Btn
		DrawLine(447, 350, 700, 276, 0x000000);
		DrawStringToHandle(700, 255, "BACK�{�^���F�Q�[�����I���", 0x000000, font.handle_1_32, 0xffffff);

		// Start Btn
		DrawLine(510, 350, 700, 300, 0x000000);
		DrawStringToHandle(700, 290, "START�{�^���F�|�[�Y", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (help_state == 1) {
		// �Q�[�����e�̃w���v�\��

		// �T�u�^�C�g���\��
		DrawStringToHandle(770, 40, "�Q�[������", 0x000000, font.handle_1_64, 0xffffff);
		DrawTriangle(710, 55, 670, 70, 710, 85, 0x000000, TRUE);

		// �����\��
		DrawStringToHandle(100, 220, "���́u��񂲂��Ƃ��v�́A�v���C���[�����E�ɓ����������̒P���ȃQ�[���ł��B", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(20, 270, "���ォ�烊���S�𗎂Ƃ����Ƃ������₪�点���󂯂�̂ŁA�Ń����S�����͂悯�Ȃ���A", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(300, 320, "���̃����S������ă|�C���g���������ł��������B", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(100, 370, "�������Ă��郊���S�͂S��ނł��B", 0x000000, font.handle_1_32, 0xffffff);

		// �����S�摜�\��
		DrawLine(640, 420, 640, 620, 0x000000);
		DrawLine(200, 520, 1080, 520, 0x000000);

		// �����S�̐���
		DrawExtendGraph(200, 440, 250, 490, image.apple[0], TRUE);
		DrawStringToHandle(260, 450, "�ԃ����S�F�|�C���gUP", 0x000000, font.handle_1_32, 0xffffff);

		DrawExtendGraph(670, 440, 720, 490, image.apple[1], TRUE);
		DrawStringToHandle(730, 450, "�����S�F�|�C���gUP", 0x000000, font.handle_1_32, 0xffffff);

		DrawExtendGraph(200, 550, 250, 600, image.apple[2], TRUE);
		DrawStringToHandle(260, 560, "�������S�F�|�C���gUP�{", 0x000000, font.handle_1_32, 0xffffff);

		DrawExtendGraph(670, 550, 720, 600, image.apple[3], TRUE);
		DrawStringToHandle(730, 560, "�Ń����S�F�|�C���gDOWN", 0x000000, font.handle_1_32, 0xffffff);
	};

	/********************************
	* �����\���ؑ�
	********************************/
	// �R���g���[���[����
	if (help_selectstate = GetStickX() > 32000 && help_stickflg == 0) {
		help_state = 1;
		help_stickflg = 1;
	}
	else if (help_selectstate = GetStickX() < -32000 && help_stickflg == 0) {
		help_state = 0;
		help_stickflg = 1;
	};
	// �X�e�B�b�N���߂�Ƒ����t
	if (help_selectstate = GetStickX() < 1200 && help_stickflg == 1) {
		if (help_selectstate = GetStickX() > -1200) {
			help_stickflg = 0;
		};
	};
	// A�{�^���ŏI��
	if (JudgeButton(XINPUT_BUTTON_A) == 1) {
		game.mode = TITLE;
	};
	// B�{�^���ŃQ�[���J�n
	if (JudgeButton(XINPUT_BUTTON_B) == 1) {
		game.mode = INIT;
	};

	// �L�[�{�[�h����
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		help_state = 0;
	};
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		help_state = 1;
	};
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
	if (CheckHitKey(KEY_INPUT_B)) {
		game.mode = INIT;
	};
};