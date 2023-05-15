// ��F����

#include "DxLib.h"

#include "resourceLoad.h"
extern Image image;
extern Font font;

#include "ranking_name_input.h"

#include "main.h"
extern Game game;

#include "PadInput.h"
int rni_selectstateX;
int rni_selectstateY;
int rni_stickflgX = 0;
int rni_stickflgY = 0;

char rni_alphabet[][26] = {
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

std::string rni_inputName = "";
int rni_selector[] = { 90, 440, 35, 30, 0, 0 };
int rni_state = 0;

#include "Apple.h"
#include "ranking.h"

/********************************
* �����L���O���͏���
********************************/
void DrawRankingNameInput() { // ���܂��S�����A���͂��ꂽ���O��Ԃ��֐��ƁASetFontSize�g�p�ɂ��FPS�ቺ���ȊO����
	// �J�n�t���O�ݒ�
	rni_state = 1;

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

	// �J���p
	//DrawFormatString(600, 20, 0x000000, "%d - %d / %d - %d / %d - %d / %c / %d", rni_selector[0], rni_selector[1], rni_selector[2], rni_selector[3], rni_selector[4], rni_selector[5], rni_alphabet[rni_selector[4]][rni_selector[5]], strlen(rni_inputName.c_str()));
	//DrawFormatString(600, 20, 0x000000, "%d - %d", GetStickX(), GetStickY());

	/********************************
	* �L�[�{�[�h�`��
	********************************/
	// �L�[�{�[�h�G���A�̔w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 640, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �L�[�{�[�h�̗v�f��\��
	// �e�L�X�g�{�b�N�X�̕�����͕������ɒǏ]
	int inputName_Box_Width = 820;
	if (rni_inputName.length() > 12) {
		int len = (rni_inputName.length()) - 12;
		inputName_Box_Width += (9 * len);
	}
	DrawBox(690, 360, inputName_Box_Width, 398, 0xffffff, FALSE);

	DrawStringToHandle(680, 370, ">", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 360, "���O���p�����œ��͂��Ă�������", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 380, "���X�e�B�b�N�ŃJ�[�\���ړ��AA�{�^���œ���", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 400, "B�{�^���ňꎚ�폜", 0xffffff, font.handle_0_16, 0xffffff);

	DrawStringToHandle(700, 370, rni_inputName.c_str(), 0xffffff, font.handle_0_16, 0xffffff);

	SetFontSize(32);
	// �A���t�@�x�b�g�啶���E�������̕\��
	for (int i = 0; i < 26; i++) {
		//DrawStringToHandle(100 + (i * 42), 440, rni_alphabet[0][i], 0xffffff, font.handle_0_32, 0xffffff); // ���
		DrawFormatString(100 + (i * 42), 440, 0xffffff, "%c", rni_alphabet[0][i]);
		DrawFormatString(100 + (i * 42), 490, 0xffffff, "%c", rni_alphabet[1][i]);
	};
	// �����L�[�p�b�h�\��
	for (int i = 0; i < 10; i++) {
		DrawFormatString(435 + (i * 42), 540, 0xffffff, "%c", rni_alphabet[2][i]);
	};
	// ���͊m��{�^��
	if (rni_inputName.length() > 0) {
		DrawStringToHandle(597, 595, "���͊m��", 0xffffff, font.handle_0_16, 0xffffff);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawStringToHandle(597, 595, "���͊m��", 0xffffff, font.handle_0_16, 0xffffff);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	};

	// �Z���N�^�[�\��
	DrawBox(rni_selector[0], rni_selector[1], (rni_selector[0] + rni_selector[2]), (rni_selector[1] + rni_selector[3]), 0xffffff, FALSE);

	/********************************
	* �Z���N�^�[�E���͏���
	********************************/
	if (rni_selectstateY = GetStickY() > 20000 && rni_stickflgY == 0) { // ���X�e�B�b�N��
		if (rni_selector[1] != 440) { // �ŏ�i����Ȃ��Ȃ�
			if (rni_selector[1] == 540) { // �R�i�ڂ���Q�i�ڂ�
				rni_selector[5] = (rni_selector[5] + 8); // �R�i�ڂ���Q�i�ڂֈړ������獷�𑫂�
			}
			else if (rni_selector[1] == 590) { // �S�i�ڂ���R�i�ڂ�
				rni_selector[2] = 35; // �J�[�\�������C��
				rni_selector[5] = 4;
			};
			rni_selector[1] -= 50; // �O�i��j�̒i��
			rni_selector[4] -= 1; // �����z��w��p�A�h���X�̍X�V
		};
		rni_stickflgY = 1;
	}
	else if (rni_selectstateY = GetStickY() < -20000 && rni_stickflgY == 0) { // ���X�e�B�b�N��
		if (rni_selector[1] != 590) { // �ŉ��i����Ȃ��Ȃ�
			if (rni_selector[1] == 490) { // �Q�i�ڂ���R�i�ڂ�
				rni_selector[5] = (rni_selector[5] - 8); // �Q�i�ڂ���R�i�ڂֈړ������獷������
				if (rni_selector[0] >= 846) {
					// �X���E�ɃJ�[�\�����������當���z��w��p�A�h���X���X��
					rni_selector[0] = 804;
					rni_selector[5] = 9;
				}
				else if (rni_selector[0] <= 384) {
					//	�O��荶�ɃJ�[�\�����������當���z��w��p�A�h���X���O��
					rni_selector[0] = 426;
					rni_selector[5] = 0;
				};
			}
			else if (rni_selector[1] == 540) { // �R�i�ڂ���S�i�ڂ�
				rni_selector[2] = 75; // �J�[�\�������{�^���ɍ��킹�čX�V
				// �u���͊m��v�{�^���ɍ��킹��
				rni_selector[0] = 594;
				rni_selector[5] = 0;
			};
			rni_selector[1] += 50; // ���i���j�̒i��
			rni_selector[4] += 1; // �����z��w��p�A�h���X�̍X�V
		};
		rni_stickflgY = 1;
	}
	else if (rni_selectstateX = GetStickX() > 20000 && rni_stickflgX == 0) { // ���X�e�B�b�N��
		if (rni_selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (rni_selector[0] < 1140) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (rni_selector[0] < 1140) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (rni_selector[0] < 804) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		};
		rni_stickflgX = 1;
	}
	else if (rni_selectstateX = GetStickX() < -20000 && rni_stickflgX == 0) { // ���X�e�B�b�N�E
		if (rni_selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (rni_selector[0] > 90) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (rni_selector[0] > 90) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (rni_selector[0] > 426) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		};
		rni_stickflgX = 1;
	};

	// �X�e�B�b�N���߂�Ƒ����t
	if (rni_selectstateY = GetStickY() < 1200 && rni_stickflgY == 1) {
		if (rni_selectstateY = GetStickY() > -1200) {
			rni_stickflgY = 0;
		};
	};
	if (rni_selectstateX = GetStickX() < 1200 && rni_stickflgX == 1) {
		if (rni_selectstateX = GetStickX() > -1200) {
			rni_stickflgX = 0;
		};
	};

	// A�{�^���ŃL�[�{�[�h�J�[�\���ʒu�{�^���̌���
	if (JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
		// ���͊m�肪�����ꂽ��
		if (rni_selector[4] == 3) {
			if (rni_inputName.length() > 0) {
				game.mode = RANKING;
			}
			else {
				// �������͂���Ă��Ȃ��̂Ōx��
			};
		}
		else {
			// Char�P�������P�o�C�g�Ƃ��čl���ĂP�O�o�C�g�܂�
			if (GetInputedNameLength() < 10) {
				rni_inputName += rni_alphabet[rni_selector[4]][rni_selector[5]];
			}
			else {
				// 10���������Ă�̂Ōx��
			};
		};
	};

	// B�{�^���ňꕶ���폜
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		// �P�����폜
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		};
	};

	/********************************
	* �Z���N�^�[�E���͏����i�L�[�{�[�h�j
	********************************/
	if (CheckHitKey(KEY_INPUT_UP)) { // ��
		if (rni_selector[1] != 440) { // �ŏ�i����Ȃ��Ȃ�
			if (rni_selector[1] == 540) { // �R�i�ڂ���Q�i�ڂ�
				rni_selector[5] = (rni_selector[5] + 8); // �R�i�ڂ���Q�i�ڂֈړ������獷�𑫂�
			}
			else if (rni_selector[1] == 590) { // �S�i�ڂ���R�i�ڂ�
				rni_selector[2] = 35; // �J�[�\�������C��
				rni_selector[5] = 4;
			};
			rni_selector[1] -= 50; // �O�i��j�̒i��
			rni_selector[4] -= 1; // �����z��w��p�A�h���X�̍X�V
		};
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) { // ��
		if (rni_selector[1] != 590) { // �ŉ��i����Ȃ��Ȃ�
			if (rni_selector[1] == 490) { // �Q�i�ڂ���R�i�ڂ�
				rni_selector[5] = (rni_selector[5] - 8); // �Q�i�ڂ���R�i�ڂֈړ������獷������
				if (rni_selector[0] >= 846) {
					// �X���E�ɃJ�[�\�����������當���z��w��p�A�h���X���X��
					rni_selector[0] = 804;
					rni_selector[5] = 9;
				}
				else if (rni_selector[0] <= 384) {
					//	�O��荶�ɃJ�[�\�����������當���z��w��p�A�h���X���O��
					rni_selector[0] = 426;
					rni_selector[5] = 0;
				};
			}
			else if (rni_selector[1] == 540) { // �R�i�ڂ���S�i�ڂ�
				rni_selector[2] = 75; // �J�[�\�������{�^���ɍ��킹�čX�V
				// �u���͊m��v�{�^���ɍ��킹��
				rni_selector[0] = 594;
				rni_selector[5] = 0;
			};
			rni_selector[1] += 50; // ���i���j�̒i��
			rni_selector[4] += 1; // �����z��w��p�A�h���X�̍X�V
		};
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) { // ��
		if (rni_selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (rni_selector[0] < 1140) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (rni_selector[0] < 1140) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (rni_selector[0] < 804) {
				// �E�[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		};
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) { // �E
		if (rni_selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (rni_selector[0] > 90) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (rni_selector[0] > 90) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (rni_selector[0] > 426) {
				// ���[�Ȃ�j���A����ȊO�Ȃ�ړ�
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		};
	};

	// �G���^�[�L�[�ŃL�[�{�[�h�J�[�\���ʒu�{�^���̌���
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		// ���͊m�肪�����ꂽ��
		if (rni_selector[4] == 3) {
			if (rni_inputName.length() > 0) {
				game.mode = RANKING;
			}
			else {
				// �������͂���Ă��Ȃ��̂Ōx��
			};
		}
		else {
			// Char�P�������P�o�C�g�Ƃ��čl���ĂP�O�o�C�g�܂�
			if (GetInputedNameLength() < 10) {
				rni_inputName += rni_alphabet[rni_selector[4]][rni_selector[5]];
			}
			else {
				// 10���������Ă�̂Ōx��
			};
		};
	};

	// �o�b�N�L�[�ňꕶ���폜
	if (CheckHitKey(KEY_INPUT_BACK)) {
		// �P�����폜
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		};
	};

	// ESC�L�[�ŋ����I��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};

/********************************
* ���Z�b�g
********************************/
void ResetRankingNameInput() {
	// ���O���͒l�̃��Z�b�g
	rni_inputName = "";
	// �J�[�\���ʒu�̃��Z�b�g
	rni_selector[0] = 90;
	rni_selector[1] = 440;
	rni_selector[2] = 35;
	rni_selector[3] = 30;
	rni_selector[4] = 0;
	rni_selector[5] = 0;
	// �J�n�t���O�̃��Z�b�g
	rni_state = 0;
};

/********************************
* ���͂��ꂽ���O�̎w�肵��������Ԃ�
********************************/
char GetInputedName(int i) {
	if (GetInputedNameLength() > 0) {
		char name[10];
		for (int i = 0; i < GetInputedNameLength() - 1; i++) {
			name[i] = rni_inputName[i];
		};
		return rni_inputName.c_str()[i];
	}
	else {
		return -1;
	};
};

/********************************
* ���͂��ꂽ���O�̌�����Ԃ�
********************************/
int GetInputedNameLength() {
	return strlen(rni_inputName.c_str());
};

/********************************
* ���O���͂��ꂽ��
********************************/
int GetRankingNameInputState() {
	return rni_state;
};