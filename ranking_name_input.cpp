/********************************
* �����L���O���͏���
* ��ҁF����
********************************/
#include "DxLib.h"
#include "resourceLoad.h"
#include "ranking_name_input.h"
#include "main.h"
#include "Apple.h"
#include "ranking.h"
#include "PadInput.h"


/********************************
* �����L���O���͕ϐ�������
********************************/
int RankingNameInput::state = 0;
int RankingNameInput::selector[] = { 90, 440, 35, 30, 0, 0 };
std::string RankingNameInput::inputName = "";
char RankingNameInput::alphabet[][26] = {
   { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
   { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
   { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//const char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
int RankingNameInput::ctrl_state[] = {0, 0, 0, 0};


/********************************
* �����L���O���͊֐�
********************************/
void RankingNameInput::Draw() {
	// �J�n�t���O�ݒ�
	state = 1;

    // �w�i�\��
    DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	// �^�C�g��
	DrawStringToHandle(270, 50, "�����L���O�ɓo�^", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);

	// �{��
	std::string str = "�X�R�A�F" + std::to_string(AppleCount::ReturnScore());
	DrawStringToHandle(750, 70, str.c_str(), 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	DrawStringToHandle(140, 150, "���Ȃ��̃X�R�A����ʂT�ʓ��ɓ���܂����I���߂łƂ��������܂��B", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	DrawStringToHandle(110, 200, "�Ƃ������ƂŁA�����L���O�ɒǉ����܂��B���Ȃ��̖��O���ǂ����i�����j", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	/********************************
	* �L�[�{�[�h�`��
	********************************/
	// �L�[�{�[�h�G���A�̔w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 640, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �L�[�{�[�h�̗v�f��\��
	// �e�L�X�g�{�b�N�X�̕�����͕������ɒǏ]
	int inputName_Box_Width = 900;
	if (inputName.length() > 12) {
		int len = (inputName.length()) - 12;
		inputName_Box_Width += (9 * len);
	};
	DrawBox(770, 360, inputName_Box_Width, 398, 0xffffff, FALSE);

	DrawStringToHandle(760, 370, ">", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	DrawStringToHandle(350, 360, "���O���p�����œ��͂��Ă�������", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	DrawStringToHandle(350, 380, "�\���L�[�E���X�e�B�b�N�ŃJ�[�\���ړ��A", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	DrawStringToHandle(350, 400, "A�{�^���œ��́AB�{�^���ňꎚ�폜", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);

	DrawStringToHandle(780, 370, inputName.c_str(), 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);

	// �A���t�@�x�b�g�啶���E�������̕\��
	for (int i = 0; i < 26; i++) {
		str = alphabet[0][i];
		DrawStringToHandle(100 + (i * 42), 440, str.c_str(), 0xffffff, Font::GetFonts(FONT_0_32), 0xffffff);
		str = alphabet[1][i];
		DrawStringToHandle(100 + (i * 42), 490, str.c_str(), 0xffffff, Font::GetFonts(FONT_0_32), 0xffffff);
	};
	// �����L�[�p�b�h�\��
	for (int i = 0; i < 10; i++) {
		str = alphabet[2][i];
		DrawStringToHandle(435 + (i * 42), 540, str.c_str(), 0xffffff, Font::GetFonts(FONT_0_32), 0xffffff);
	};
	// ���͊m��{�^��
	if (inputName.length() > 0) {
		DrawStringToHandle(597, 595, "���͊m��", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawStringToHandle(597, 595, "���͊m��", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	};

	// �Z���N�^�[�\��
	DrawBox(selector[0], selector[1], (selector[0] + selector[2]), (selector[1] + selector[3]), 0xffffff, FALSE);

	/********************************
	* �Z���N�^�[�E���͏���
	********************************/
	if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_UP) == 1) || (ctrl_state[1] = PAD_INPUT::GetStickY() > 20000 && ctrl_state[3] == 0)) { // ���X�e�B�b�N��
		if (selector[1] != 440) { // �ŏ�i����Ȃ��Ȃ�
			if (selector[1] == 540) { // �R�i�ڂ���Q�i�ڂ�
				selector[5] = (selector[5] + 8); // �R�i�ڂ���Q�i�ڂֈړ������獷�𑫂�
			}
			else if (selector[1] == 590) { // �S�i�ڂ���R�i�ڂ�
				selector[2] = 35; // �J�[�\�������C��
				selector[5] = 4;
			};
			selector[1] -= 50; // �O�i��j�̒i��
			selector[4] -= 1; // �����z��w��p�A�h���X�̍X�V
		};
		ctrl_state[3] = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_DOWN) == 1) || (ctrl_state[1] = PAD_INPUT::GetStickY() < -20000 && ctrl_state[3] == 0)) { // ���X�e�B�b�N��
		if (selector[1] != 590) { // �ŉ��i����Ȃ��Ȃ�
			if (selector[1] == 490) { // �Q�i�ڂ���R�i�ڂ�
				selector[5] = (selector[5] - 8); // �Q�i�ڂ���R�i�ڂֈړ������獷������
				if (selector[0] >= 846) {
					// �X���E�ɃJ�[�\�����������當���z��w��p�A�h���X���X��
					selector[0] = 804;
					selector[5] = 9;
				}
				else if (selector[0] <= 384) {
					//	�O��荶�ɃJ�[�\�����������當���z��w��p�A�h���X���O��
					selector[0] = 426;
					selector[5] = 0;
				};
			}
			else if (selector[1] == 540) { // �R�i�ڂ���S�i�ڂ�
				selector[2] = 75; // �J�[�\�������{�^���ɍ��킹�čX�V
				// �u���͊m��v�{�^���ɍ��킹��
				selector[0] = 594;
				selector[5] = 0;
			};
			selector[1] += 50; // ���i���j�̒i��
			selector[4] += 1; // �����z��w��p�A�h���X�̍X�V
		};
		ctrl_state[3] = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_RIGHT) == 1) || (ctrl_state[0] = PAD_INPUT::GetStickX() > 20000 && ctrl_state[2] == 0)) { // ���X�e�B�b�N�E
		if (selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (selector[0] < 1140) { // �E�[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (selector[0] < 1140) { // �E�[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (selector[0] < 804) { // �E�[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 9;
				selector[5] = 0;
			};
		};
		ctrl_state[2] = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_LEFT) == 1) || (ctrl_state[0] = PAD_INPUT::GetStickX() < -20000 && ctrl_state[2] == 0)) { // ���X�e�B�b�N��
		if (selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (selector[0] > 90) { // ���[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (selector[0] > 90) { // ���[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (selector[0] > 426) { // ���[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 9;
				selector[5] = 9;
			};
		};
		ctrl_state[2] = 1;
	};

	// �X�e�B�b�N���߂�Ƒ����t
	if (ctrl_state[1] = PAD_INPUT::GetStickY() < 1200 && ctrl_state[3] == 1) {
		if (ctrl_state[1] = PAD_INPUT::GetStickY() > -1200) {
			ctrl_state[3] = 0;
		};
	};
	if (ctrl_state[0] = PAD_INPUT::GetStickX() < 1200 && ctrl_state[2] == 1) {
		if (ctrl_state[0] = PAD_INPUT::GetStickX() > -1200) {
			ctrl_state[2] = 0;
		};
	};

	// �\���L�[���߂�Ƒ����t
	if ((PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_UP) == 1) || (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_DOWN) == 1) || (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_LEFT) == 1) || (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_RIGHT) == 1)) {
		ctrl_state[3] = 0;
		ctrl_state[2] = 0;
	};

	// A�{�^���ŃL�[�{�[�h�J�[�\���ʒu�{�^���̌���
	if (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
		// ���͊m�肪�����ꂽ��
		if (selector[4] == 3) {
			if (inputName.length() > 0) {
                Game::ModeSet(RANKING);
			}
			else {
				// �������͂���Ă��Ȃ��̂Ōx��
			};
		}
		else {
			// Char�P�������P�o�C�g�Ƃ��čl���ĂP�O�o�C�g�܂�
			if (GetNameLength() < 10) {
				inputName += alphabet[selector[4]][selector[5]];
			}
			else {
				// 10���������Ă�̂Ōx��
			};
		};
	};

	// B�{�^���ňꕶ���폜
	if (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		// �P�����폜
		if (inputName.length() > 0) {
			inputName.erase(inputName.length() - 1);
		};
	};

	/********************************
	* �Z���N�^�[�E���͏����i�L�[�{�[�h�j
	********************************/
	if (CheckHitKey(KEY_INPUT_UP)) { // ��
		if (selector[1] != 440) { // �ŏ�i����Ȃ��Ȃ�
			if (selector[1] == 540) { // �R�i�ڂ���Q�i�ڂ�
				selector[5] = (selector[5] + 8); // �R�i�ڂ���Q�i�ڂֈړ������獷�𑫂�
			}
			else if (selector[1] == 590) { // �S�i�ڂ���R�i�ڂ�
				selector[2] = 35; // �J�[�\�������C��
				selector[5] = 4;
			};
			selector[1] -= 50; // �O�i��j�̒i��
			selector[4] -= 1; // �����z��w��p�A�h���X�̍X�V
		};
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) { // ��
		if (selector[1] != 590) { // �ŉ��i����Ȃ��Ȃ�
			if (selector[1] == 490) { // �Q�i�ڂ���R�i�ڂ�
				selector[5] = (selector[5] - 8); // �Q�i�ڂ���R�i�ڂֈړ������獷������
				if (selector[0] >= 846) {
					// �X���E�ɃJ�[�\�����������當���z��w��p�A�h���X���X��
					selector[0] = 804;
					selector[5] = 9;
				}
				else if (selector[0] <= 384) {
					//	�O��荶�ɃJ�[�\�����������當���z��w��p�A�h���X���O��
					selector[0] = 426;
					selector[5] = 0;
				};
			}
			else if (selector[1] == 540) { // �R�i�ڂ���S�i�ڂ�
				selector[2] = 75; // �J�[�\�������{�^���ɍ��킹�čX�V
				// �u���͊m��v�{�^���ɍ��킹��
				selector[0] = 594;
				selector[5] = 0;
			};
			selector[1] += 50; // ���i���j�̒i��
			selector[4] += 1; // �����z��w��p�A�h���X�̍X�V
		};
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) { // �E
		if (selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (selector[0] < 1140) { // �E�[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (selector[0] < 1140) { // �E�[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (selector[0] < 804) { // �E�[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 9;
				selector[5] = 0;
			};
		};
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) { // ��
		if (selector[1] == 440) { // �P�i�ڂ̂Ƃ�
			if (selector[0] > 90) { // ���[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 490) { // �Q�i�ڂ̂Ƃ�
			if (selector[0] > 90) { // ���[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 540) { // �R�i�ڂ̂Ƃ�
			if (selector[0] > 426) { // ���[�Ȃ�}���IUSA�A����ȊO�Ȃ�ړ�
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 9;
				selector[5] = 9;
			};
		};
	};

	// �G���^�[�L�[�ŃL�[�{�[�h�J�[�\���ʒu�{�^���̌���
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		// ���͊m�肪�����ꂽ��
		if (selector[4] == 3) {
			if (inputName.length() > 0) {
                Game::ModeSet(RANKING);
			}
			else {
				// �������͂���Ă��Ȃ��̂Ōx��
			};
		}
		else {
			// Char�P�������P�o�C�g�Ƃ��čl���ĂP�O�o�C�g�܂�
			if (GetNameLength() < 10) {
				inputName += alphabet[selector[4]][selector[5]];
			}
			else {
				// 10���������Ă�̂Ōx��
			};
		};
	};

	// �o�b�N�L�[�ňꕶ���폜
	if (CheckHitKey(KEY_INPUT_BACK)) {
		// �P�����폜
		if (inputName.length() > 0) {
			inputName.erase(inputName.length() - 1);
		};
	};

	// ESC�L�[�ŋ����I��
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        Game::ModeSet(TITLE);
	};
};

/********************************
* ���Z�b�g
********************************/
void RankingNameInput::Reset() {
	// ���O���͒l�̃��Z�b�g
	inputName = "";
	// �J�[�\���ʒu�̃��Z�b�g
	selector[0] = 90;
	selector[1] = 440;
	selector[2] = 35;
	selector[3] = 30;
	selector[4] = 0;
	selector[5] = 0;
	// �J�n�t���O�̃��Z�b�g
	state = 0;
};

/********************************
* ���͂��ꂽ���O�̎w�肵��������Ԃ�
********************************/
char RankingNameInput::GetName(int i) {
	if (GetNameLength() > 0) {
		char name[10];
		for (int i = 0; i < GetNameLength() - 1; i++) {
			name[i] = inputName[i];
		};
		return inputName.c_str()[i];
	}
	else {
		return -1;
	};
};

/********************************
* ���͂��ꂽ���O�̌�����Ԃ�
********************************/
int RankingNameInput::GetNameLength() {
	return strlen(inputName.c_str());
};

/********************************
* ���O���͂��ꂽ��
********************************/
int RankingNameInput::GetState() {
	return state;
};