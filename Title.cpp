// ��F���܁A�ʏ�

#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"
#include "PadInput.h"

extern Image image;
extern Font font;

extern Game game;
extern Sound sound;

int title_state = 0;

int title_selectstate;
int title_stickflg = 0;

/********************************
* �^�C�g��
********************************/
void DrawTitle() {
	// �w�i�\��
	DrawGraph(0, 0, image.title, TRUE);

	// �^�C�g���\��
	DrawStringToHandle(350, 150, "��񂲂��Ƃ�", 0x000000, font.handle_1_128, 0xffffff);

	// �Q�[�����[�h�Z���N�g�̍���
	DrawStringToHandle(630, 350, "�X�^�[�g", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 400, "�w���v", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 450, "�����L���O", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 500, "�I���", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(380, 670, "���X�e�B�b�N�őI�����AB�{�^���Ō���", 0x000000, font.handle_1_32, 0xffffff);
	//DrawStringToHandle(500, 640, "T�L�[�ł肻�[���e�X�g", 0x000000, font.handle_1_32, 0xffffff);

	// �Q�[�����[�h�Z���N�g�̃J�[�\������
	if (title_state == 0) {
		DrawStringToHandle(570, 350, "��", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title_state == 1) {
		DrawStringToHandle(570, 400, "��", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title_state == 2) {
		DrawStringToHandle(570, 450, "��", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title_state == 3) {
		DrawStringToHandle(570, 500, "��", 0x000000, font.handle_1_32, 0xffffff);
	};

	/********************************
	* �Q�[�����[�h�Z���N�g����
	********************************/
	// �R���g���[���[����
	if (title_selectstate = GetStickY() > 32000 && title_stickflg == 0) {
		if (CheckSoundMem(sound.se_corsor) == 0) {
			PlaySoundMem(sound.se_corsor, DX_PLAYTYPE_BACK, TRUE);
		}
		if (title_state <= 0) {
			title_state = 3;
		}
		else {
			title_state -= 1;
		};
		title_stickflg = 1;
	}
	else if (title_selectstate = GetStickY() < -32000 && title_stickflg == 0) {
		if (CheckSoundMem(sound.se_corsor) == 0) {
			PlaySoundMem(sound.se_corsor, DX_PLAYTYPE_BACK, TRUE);
		}
		if (title_state >= 3) {
			title_state = 0;
		}
		else {
			title_state += 1;
		};
		title_stickflg = 1;
	};
	// �X�e�B�b�N���߂�Ƒ����t
	if (title_selectstate = GetStickY() < 1200 && title_stickflg == 1) {
		if (title_selectstate = GetStickY() > -1200) {
			title_stickflg = 0;
		};
	};
	// B�{�^���őI��
	if (JudgeButton(XINPUT_BUTTON_B) == 1) {
		if (CheckSoundMem(sound.se_selct) == 0) {
			PlaySoundMem(sound.se_selct, DX_PLAYTYPE_BACK, TRUE);
		}
		if (title_state == 0) {
			// �X�^�[�g�I��
			game.mode = INIT;
		}
		else if (title_state == 1) {
			// �w���v�I��
			game.mode = HELP;
		}
		else if (title_state == 2) {
			// �����L���O�I��
			game.mode = RANKING;
		}
		else if (title_state == 3) {
			// �I���I��
			game.mode = END;
		};
	};

	// �L�[�{�[�h���͑Ή�
	if (CheckHitKey(KEY_INPUT_1)) {
		title_state = 0;
	} else if (CheckHitKey(KEY_INPUT_2)) {
		title_state = 1;
	} else if (CheckHitKey(KEY_INPUT_3)) {
		title_state = 2;
	} else if (CheckHitKey(KEY_INPUT_4)) {
		title_state = 3;
	};
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (title_state == 0) {
			// �X�^�[�g�I��
			game.mode = INIT;
		}
		else if (title_state == 1) {
			// �w���v�I��
			game.mode = HELP;
		}
		else if (title_state == 2) {
			// �����L���O�I��
			game.mode = RANKING;
		}
		else if (title_state == 3) {
			// �I���I��
			game.mode = END;
		};
	};
	if (CheckHitKey(KEY_INPUT_T)) {
		game.mode = TEST;
	};


	// BGM SE �����ɏ������Abgm.cpp�ŉ�ʕʂɐ��䂳����H
	
};



















// ���߂�A�A

//int Image;				//�w�i�摜

//int SoundTitle;			//�^�C�g���̉��y
//int SoundMoveCorsor;	//�J�[�\���ړ��̌��ʉ�
//int	SoundDecision;		//����̌��ʉ�

//int LoadImages(void)
//{
//	if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
//}
//int FontHandle;

//int LoadImages(void)
//{
//	LPCSTR font_path = "Resources/font/���傩���������i�����Łj.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
//
//	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
//	}
//	else {
//		// �t�H���g�Ǎ��G���[����
//		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
//	}
//
//	//if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
//}

//int LoadSounds(void)
//{
//
//}

//void DrawTitle(void)
//{
//
//	//FontHandle= CreateFontToHandle("���傩���������i�����Łj", 128,9 , DX_FONTTYPE_EDGE);
//
//	//DrawGraph(0, 0, Image, TRUE);
//
//	///*ChangeFont("���傩���������i�����Łj");
//	//ChangeFontType(DX_FONTTYPE_EDGE);
//	//SetFontSize(128);
//	//DrawString(340, 140, "��񂲂��Ƃ�", 0x000000, 0xffffff);*/
//
//	//DrawStringToHandle(340, 140, "��񂲂��Ƃ�", 0x000000, FontHandle, 0xffffff);
//	//	
//
//	//DrawGraph(0, 0, image.title, FALSE);
//}
