#include"DxLib.h"
#include"PadInput.h"

//�R���g���[���[���͂��擾
void InputController() {
	for (int i = 0; i < 16; i++) {
		OldKey.Buttons[i] = NowKey.Buttons[i];
	}
	GetJoypadXInputState(DX_INPUT_PAD1, &NowKey);
	for (int i = 0; i < 16; i++) {
		KeyFlg.Buttons[i] = NowKey.Buttons[i] & ~OldKey.Buttons[i];     //XINPUT�͍\���̂ŊǗ�����Ă���
	}
}

int JudgeButton(unsigned char data) {
	if (KeyFlg.Buttons[data]) {
		return 1;
	}
	else{
		return 0;
	}
}