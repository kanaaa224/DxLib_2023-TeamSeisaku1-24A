#pragma once

static XINPUT_STATE OldKey;
static XINPUT_STATE NowKey;
static XINPUT_STATE KeyFlg;

void InputController();		//�R���g���[���[�̓���
int JudgeButton(unsigned char data);		//�{�^���̓���
int JudgeReleaseButton(unsigned char data);		//�{�^���𗣂����Ƃ�
int GetStickX();		//���X�e�B�b�N��X��
int GetStickY();		//���X�e�B�b�N��Y��
	