// ��F���܁A�ʏ�

#include "DxLib.h"
#include <stdlib.h>
#include "title.h"
#include "resourceLoad.h"
#include "PadInput.h"

extern Image image;
extern Font font;

Title title;

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

	// �Q�[�����[�h�Z���N�g�̃J�[�\������
	if (title.state == 0) {
		DrawStringToHandle(570, 350, "��", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title.state == 1) {
		DrawStringToHandle(570, 400, "��", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title.state == 2) {
		DrawStringToHandle(570, 450, "��", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title.state == 3) {
		DrawStringToHandle(570, 500, "��", 0x000000, font.handle_1_32, 0xffffff);
	};


	//if ((selector_current_value = GetStickY()) <= -32000) { //CheckHitKey(KEY_INPUT_M) != 0
	//	

	//	if (selector_current_value >= 1) {
	//		if (title.state >= 3) {
	//			title.state = 0;
	//		}
	//		else {
	//			title.state += 1;
	//		};
	//	};
	//};

	if ((title.selector_current_value = GetStickY()) <= -32000) { //CheckHitKey(KEY_INPUT_M) != 0
		title.selector_current_value = abs(title.selector_current_value);

		if (title.selector_current_value - title.selector_prev_value > 1) {
			

			if (title.state >= 3) {
				title.state = 0;
			}
			else {
				title.state += 1;
			};
		};
		title.selector_prev_value = abs(GetStickY());
	};

	// �Q�[�����[�h�Z���N�g����

	// BGM SE �����ɏ������Abgm.cpp�ŉ�ʕʂɐ��䂳����H

};



















// �炢�₲�߂�A�A







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
