/********************************
* �^�C�g�����
* ��ҁF�ʏ�A����
********************************/
#include "DxLib.h"
#include "title.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"


int title_selectstate;
int title_stickflg = 0;


/********************************
* �^�C�g���ϐ�������
********************************/
int Title::state = 0;


/********************************
* �^�C�g����ʕ`��
********************************/
void Title::Draw() {
	// �w�i�\��
	DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	// �^�C�g���\��
	DrawStringToHandle(330, 150, "��񂲂��Ƃ�", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

	// �o�[�W�����\���i���j
	DrawStringToHandle(20, 690, "v1.2.3", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

	// �Q�[�����[�h�Z���N�g�̍���
	DrawStringToHandle(630, 350, "�X�^�[�g", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(630, 400, "�w���v", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(630, 450, "�����L���O", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(630, 500, "�I���", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	DrawStringToHandle(380, 670, "���X�e�B�b�N�őI�����AB�{�^���Ō���", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	
	// �Q�[�����[�h�Z���N�g�̃J�[�\������
	if (state == 0) {
		DrawStringToHandle(570, 350, "��", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 1) {
		DrawStringToHandle(570, 400, "��", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 2) {
		DrawStringToHandle(570, 450, "��", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 3) {
		DrawStringToHandle(570, 500, "��", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	};

	/********************************
	* �Q�[�����[�h�Z���N�g����
	********************************/
	// �R���g���[���[����
	if (title_selectstate = PAD_INPUT::GetStickY() > 32000 && title_stickflg == 0) {
		PlaySoundMem(Sound::GetSounds(SND_SE_CURSOR), DX_PLAYTYPE_BACK, TRUE);
		if (state <= 0) {
			state = 3;
		}
		else {
			state -= 1;
		};
		title_stickflg = 1;
	}
	else if (title_selectstate = PAD_INPUT::GetStickY() < -32000 && title_stickflg == 0) {
		PlaySoundMem(Sound::GetSounds(SND_SE_CURSOR), DX_PLAYTYPE_BACK, TRUE);
		if (state >= 3) {
			state = 0;
		}
		else {
			state += 1;
		};
		title_stickflg = 1;
	};
	// �X�e�B�b�N���߂�Ƒ����t
	if (title_selectstate = PAD_INPUT::GetStickY() < 32000 && title_stickflg == 1) {
		if (title_selectstate = PAD_INPUT::GetStickY() > -32000) {
			title_stickflg = 0;
		};
	};
	// B�{�^���őI��
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_B) == 1) {
		if (CheckSoundMem(Sound::GetSounds(SND_SE_SELECT)) == 0) {
			PlaySoundMem(Sound::GetSounds(SND_SE_SELECT), DX_PLAYTYPE_BACK, TRUE);
		};
		if (state == 0) {
			// �X�^�[�g�I��
            Game::ModeSet(INIT);
		}
		else if (state == 1) {
			// �w���v�I��
            Game::ModeSet(HELP);
		}
		else if (state == 2) {
			// �����L���O�I��
            Game::ModeSet(RANKING);
		}
		else if (state == 3) {
			// �I���I��
            Game::ModeSet(END);
		};
	};

	// �L�[�{�[�h���͑Ή�
	if (CheckHitKey(KEY_INPUT_1)) {
		state = 0;
	} else if (CheckHitKey(KEY_INPUT_2)) {
		state = 1;
	} else if (CheckHitKey(KEY_INPUT_3)) {
		state = 2;
	} else if (CheckHitKey(KEY_INPUT_4)) {
		state = 3;
	};
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (CheckSoundMem(Sound::GetSounds(SND_SE_SELECT)) == 0) {
			PlaySoundMem(Sound::GetSounds(SND_SE_SELECT), DX_PLAYTYPE_BACK, TRUE);
		};
		if (state == 0) {
			// �X�^�[�g�I��
            Game::ModeSet(INIT);
		}
		else if (state == 1) {
			// �w���v�I��
            Game::ModeSet(HELP);
		}
		else if (state == 2) {
			// �����L���O�I��
            Game::ModeSet(RANKING);
		}
		else if (state == 3) {
			// �I���I��
            Game::ModeSet(END);
		};
	};
	if (CheckHitKey(KEY_INPUT_T)) {
		if (CheckSoundMem(Sound::GetSounds(SND_SE_SELECT)) == 0) {
			PlaySoundMem(Sound::GetSounds(SND_SE_SELECT), DX_PLAYTYPE_BACK, TRUE);
		};
        Game::ModeSet(TEST);
	};
};