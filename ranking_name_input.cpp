// ��F����

#include <string>
using std::string;
using std::to_string;

#include "DxLib.h"

#include "resourceLoad.h"
extern Image image;
extern Font font;

#include "ranking_name_input.h"
NameInput nameInput;

#include "main.h"
extern Game game;

#include "PadInput.h"
int rni_selectstate;
int rni_stickflg = 0;

char rni_alphabet[][26] = {
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
std::string rni_inputName = "";
int rni_selecter[] = { 90, 440, 35, 30, 0, 0 };
int rni_state = 0;

#include "Apple.h"

// �J��
int mirutame[4];

/********************************
* �����L���O���͏���
********************************/
void DrawRankingNameInput() { // ���܂��S����
    // �w�i�\��
    DrawGraph(0, 0, image.title, TRUE);

	// �^�C�g��
	DrawStringToHandle(250, 50, "�����L���O�ɓo�^", 0x000000, font.handle_1_64, 0xffffff);

	// �{��
	std::string str = "�X�R�A�F" + std::to_string(ReturnScore());
	DrawStringToHandle(750, 70, str.c_str(), 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(140, 150, "���Ȃ��̃X�R�A����ʂT�ʓ��ɓ���܂����I���߂łƂ��������܂��B", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(110, 200, "�Ƃ������ƂŁA�����L���O�ɒǉ����܂��B���Ȃ��̖��O���ǂ����i�����j", 0x000000, font.handle_1_32, 0xffffff);

	// �t�H���g�T�C�Y�̐ݒ�
	//ChangeFontSize(40); // ���[�v���ň��̂݋@�\�A���ڂ͌��d�ɂȂ� �� �o�O�������A�@�\���܂���

	DrawFormatString(600, 20, 0x000000, "%d - %d / %d - %d / %c / %d", rni_selecter[0], rni_selecter[1], rni_selecter[4], rni_selecter[5], rni_alphabet[rni_selecter[4]][rni_selecter[5]], rni_inputName.capacity() * sizeof(char));

	/********************************
	* �L�[�{�[�h�`��
	********************************/
	// �L�[�{�[�h�G���A�̔w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 600, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �L�[�{�[�h�̗v�f��\��
	// �e�L�X�g�{�b�N�X�̕�����͕������ɒǏ]
	int inputName_Box_Width = 820;
	if (rni_inputName.length() > 12) {
		int len = (rni_inputName.length()) - 12;
		inputName_Box_Width += (9 * len);
	}
	DrawBox(690, 360, inputName_Box_Width, 398, 0xffffff, FALSE);

	DrawString(680, 370, ">", 0xFFFFFF);
	DrawString(250, 360, "���O���p�����œ��͂��Ă�������", 0xFFFFFF);
	DrawString(250, 380, "���X�e�B�b�N�ŃJ�[�\���ړ��AB�{�^���œ���", 0xFFFFFF);
	DrawString(250, 400, "X�{�^���ňꎚ�폜�AY�{�^���œ��͊m��", 0xFFFFFF);

	DrawString(700, 370, rni_inputName.c_str(), 0xFFFFFF);

	SetFontSize(30);

	// �A���t�@�x�b�g�啶���̕\��
	for (int i = 0; i < 26; i++) {
		DrawFormatString(100 + (i * 42), 440, 0xffffff,"%c", rni_alphabet[0][i]);
	}
	// �A���t�@�x�b�g�������̕\��
	for (int i = 0; i < 26; i++) {
		DrawFormatString(100 + (i * 42), 490, 0xffffff, "%c", rni_alphabet[1][i]);
	}
	// �����L�[�p�b�h�\��
	for (int i = 0; i < 10; i++) {
		DrawFormatString(435 + (i * 42), 540, 0xffffff, "%c", rni_alphabet[2][i]);
	}

	// �Z���N�^�[�\��
	DrawBox(rni_selecter[0], rni_selecter[1], (rni_selecter[0] + rni_selecter[2]), (rni_selecter[1] + rni_selecter[3]), 0xffffff, FALSE);

	// �Z���N�^�[����
	/********************************
	* �Q�[�����[�h�Z���N�g����
	********************************/
	// �R���g���[���[����
	if (rni_selectstate = GetStickY() > 32000 && rni_stickflg == 0) {
		// ���X�e�B�b�N��
		//if (title.state <= 0) {
		//	title.state = 3;
		//}
		//else {
		//	title.state -= 1;
		//};
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickY() < -32000 && rni_stickflg == 0) {
		// ���X�e�B�b�N��
		//if (title.state >= 3) {
		//	title.state = 0;
		//}
		//else {
		//	title.state += 1;
		//};
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickX() > 32000 && rni_stickflg == 0) {
		// ���X�e�B�b�N��

		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickX() < -32000 && rni_stickflg == 0) {
		// ���X�e�B�b�N�E

		rni_stickflg = 1;
	};
	// �X�e�B�b�N���߂�Ƒ����t
	if (rni_selectstate = GetStickY() < 1200 && rni_stickflg == 1) {
		if (rni_selectstate = GetStickY() > -1200) {
			rni_stickflg = 0;
		};
	};
	// B�{�^���őI��
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		//if (title.state == 0) {
		//	// �X�^�[�g�I��
		//	game.mode = INIT;
		//}
		//else if (title.state == 1) {
		//	// �w���v�I��
		//	game.mode = HELP;
		//}
		//else if (title.state == 2) {
		//	// �����L���O�I��
		//	game.mode = RANKING;
		//}
		//else if (title.state == 3) {
		//	// �I���I��
		//	game.mode = END;
		//};
	};

	// �L�[�{�[�h����
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		if (rni_selecter[1] == 440) {
			// �P�i�ڂ̂Ƃ�
			if (rni_selecter[0] > 90) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// �Q�i�ڂ̂Ƃ�
			if (rni_selecter[0] > 90) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// �R�i�ڂ̂Ƃ�
			if (rni_selecter[0] > 426) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
	} else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		if (rni_selecter[1] == 440) {
			// �P�i�ڂ̂Ƃ�
			if (rni_selecter[0] < 1140) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// �Q�i�ڂ̂Ƃ�
			if (rni_selecter[0] < 1140) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// �R�i�ڂ̂Ƃ�
			if (rni_selecter[0] < 804) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
	} else if (CheckHitKey(KEY_INPUT_UP)) {
		if (rni_selecter[1] != 440) {
			// �P�i�ڂ���Ȃ��Ȃ�
			if (rni_selecter[1] == 540) {
				// �R�i�ڂ���Q�i�ڂֈړ������獷�𑫂�
				rni_selecter[5] = (rni_selecter[5] + 8);
			}
			rni_selecter[1] -= 50;
			rni_selecter[4] -= 1;
		}
	} else if (CheckHitKey(KEY_INPUT_DOWN)) {
		if (rni_selecter[1] != 540) {
			// �R�i�ڂ���Ȃ��Ȃ�
			if (rni_selecter[1] == 490) {
				// �Q�i�ڂ���R�i�ڂֈړ������獷������
				rni_selecter[5] = (rni_selecter[5] - 8);
				if (rni_selecter[0] >= 846) {
					// �X���E�ɃJ�[�\������������X�ɂ���
					rni_selecter[0] = 804;
					rni_selecter[5] = 9;
				} else if(rni_selecter[0] <= 384) {
					//	�O��荶�ɃJ�[�\������������O�ɂ���
					rni_selecter[0] = 426;
					rni_selecter[5] = 0;
				}
			}
			rni_selecter[1] += 50;
			rni_selecter[4] += 1;
		}
	}
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		if ((rni_inputName.capacity() * sizeof(char)) <= 10) {
			rni_inputName += rni_alphabet[rni_selecter[4]][rni_selecter[5]];
			nameInput.inputedName = rni_inputName;
		}
	}
	if (CheckHitKey(KEY_INPUT_BACK)) {
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		}
	}

	if(CheckHitKey(KEY_INPUT_SPACE)) {
		if (rni_state) {

		}
	
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	}

	



	// �J���p
	//DrawCircle(mirutame[0], mirutame[1], mirutame[2], 0xffffff, FALSE);
	DrawBox(mirutame[0], mirutame[1], mirutame[0] + mirutame[2], mirutame[1] + mirutame[3], 0xffffff, FALSE);
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
		mirutame[2]--;
	};
	if (CheckHitKey(KEY_INPUT_E)) {
		mirutame[2]++;
	};
	if (CheckHitKey(KEY_INPUT_R)) {
		mirutame[3]--;
	};
	if (CheckHitKey(KEY_INPUT_F)) {
		mirutame[3]++;
	};
};

