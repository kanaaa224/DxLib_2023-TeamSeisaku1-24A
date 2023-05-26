/********************************
* �w���v��ʏ���
* ��ҁF����
********************************/
#include "DxLib.h"
#include "help.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"


/********************************
* �w���v�ϐ�������
********************************/
int Help::state = 0;


/********************************
* �w���v��ʕ`��
********************************/
void Help::Draw() {
	// �w�i�\��
	DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	// �^�C�g���\��
	DrawStringToHandle(180, 40, "�w���v", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

	// �����\��
	DrawStringToHandle(680, 130, "���X�e�B�b�N�Ő�����؂肩��", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	// �߂�\��
	DrawStringToHandle(370, 670, "B�{�^���ŃQ�[���J�n�AA�{�^���ł��ǂ�", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	// �����o�[�ϐ��ɕۑ����ꂽ�X�e�[�g�ŕ\���𕪊�

	if (state == 0) {
		// �R���g���[���[�̃w���v�\��

		// �T�u�^�C�g���\��
		DrawStringToHandle(735, 40, "�������", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
		DrawTriangle(1065, 55, 1105, 70, 1065, 85, 0x000000, TRUE);

		// �R���g���[���[�摜�\��
		DrawExtendGraph(330, 290, 630, 490, Image::GetImages(IMG_CONTROLLER, 0), TRUE);
		//DrawExtendGraph(400, 500, 500, 600, image.controller_s, TRUE);

		// B Btn
		DrawLine(587, 368, 700, 368, 0x000000);
		DrawStringToHandle(700, 345, "B�{�^���F����", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// A Btn
		DrawLine(566, 392, 700, 392, 0x000000);
		DrawStringToHandle(700, 380, "A�{�^���F���ǂ�", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// Left Stick
		DrawLine(436, 421, 436, 550, 0x000000);
		DrawStringToHandle(280, 550, "���X�e�B�b�N�F�v���C���[�ƁA�I�����J�[�\���̈ړ�", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// Back Btn
		DrawLine(447, 350, 700, 276, 0x000000);
		DrawStringToHandle(700, 255, "BACK�{�^���F�Q�[�����I���", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// Start Btn
		DrawLine(510, 350, 700, 300, 0x000000);
		DrawStringToHandle(700, 290, "START�{�^���F�|�[�Y", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 1) {
		// �Q�[�����e�̃w���v�\��

		// �T�u�^�C�g���\��
		DrawStringToHandle(770, 40, "�Q�[������", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
		DrawTriangle(710, 55, 670, 70, 710, 85, 0x000000, TRUE);

		// �����\��
		DrawStringToHandle(100, 220, "���́u��񂲂��Ƃ��v�́A�v���C���[�����E�ɓ����������̒P���ȃQ�[���ł��B", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
		DrawStringToHandle(20, 270, "���ォ�烊���S�𗎂Ƃ����Ƃ������₪�点���󂯂�̂ŁA�Ń����S�����͂悯�Ȃ���A", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
		DrawStringToHandle(300, 320, "���̃����S������ă|�C���g���������ł��������B", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
		DrawStringToHandle(100, 370, "�������Ă��郊���S�͂S��ނł��B", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		/*
		����20XX�N�BIT�Z�p���}�����𐋂��邱�̐��̒��ŁA�����Ƃ��J�������Ő�[��AI���\�����Ă��܂��A��X�l�ނ�G�Ƃ݂Ȃ��Ă��܂��B
		����AI�͐��{�̖h�q�V�X�e���▯�O��PC��������A���ɂ��@�BVS�l�ނ̐푈���N���낤�Ƃ��Ă����B
		
		�����Ă��̍��A����Ȏ�����͂����Ȃ�������l���A�����L���͎����̑̂��S�g�����߂ł��邱�ƂɔY�݂������Ă���A���ɉ������Ă��Ȃ�����������œ������悤�ƍl���Ă����B
		����Ȃ�����A�ނ�C++�̍ŏ��̓��ł���u�|�C���^�v�𗝉����邽�߂̏C�s���s�����߁u��񂲂��Ƃ��̐X�v�ւƌ��������B���̌�̔ނ̉^���Ƃ�...
		*/

		// �����S�摜�\��
		DrawLine(640, 420, 640, 620, 0x000000);
		DrawLine(200, 520, 1080, 520, 0x000000);

		// �����S�̐���
		DrawExtendGraph(200, 440, 250, 490, Image::GetImages(IMG_APPLE, 0), TRUE);
		DrawStringToHandle(260, 450, "�ԃ����S�F�|�C���gUP", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		DrawExtendGraph(670, 440, 720, 490, Image::GetImages(IMG_APPLE, 1), TRUE);
		DrawStringToHandle(730, 450, "�����S�F�|�C���gUP", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		DrawExtendGraph(200, 550, 250, 600, Image::GetImages(IMG_APPLE, 2), TRUE);
		DrawStringToHandle(260, 560, "�������S�F�|�C���gUP�{", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		DrawExtendGraph(670, 550, 720, 600, Image::GetImages(IMG_APPLE, 3), TRUE);
		DrawStringToHandle(730, 560, "�Ń����S�F�|�C���gDOWN", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	};

	/********************************
	* �����\���ؑ�
	********************************/
	// �R���g���[���[����
	if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_RIGHT) == 1) || (PAD_INPUT::GetStickX() > 3200)) {
		state = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_LEFT) == 1) || (PAD_INPUT::GetStickX() < -32000)) {
		state = 0;
	};
	// A�{�^���ŏI��
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_A) == 1) {
        Game::ModeSet(TITLE);
	};
	// B�{�^���ŃQ�[���J�n
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_B) == 1) {
        Game::ModeSet(INIT);
	};

	// �L�[�{�[�h����
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		state = 0;
	};
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		state = 1;
	};
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        Game::ModeSet(TITLE);
	};
	if (CheckHitKey(KEY_INPUT_B)) {
        Game::ModeSet(INIT);
	};
};