#pragma once
#include"DxLib.h"

class PAD_INPUT {

public:
	static void InputController();		//�R���g���[���[�̓���
	static int JudgeButton(unsigned char data);		//�{�^���̓���
	static int JudgeReleaseButton(unsigned char data);		//�{�^���𗣂����Ƃ�
	static int GetStickX();		//���X�e�B�b�N��X��
	static int GetStickY();		//���X�e�B�b�N��Y��
};


	