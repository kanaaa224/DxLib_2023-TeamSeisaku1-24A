#pragma once
#include "DxLib.h"

// �摜�p�̍\����
class Image {
public:
	int handle;
	char* filename;
};

// �摜��ǂݍ��ފ֐��̃v���g�^�C�v�錾
int LoadImage(Image& image, const char* filename);

// �摜��`�悷��֐��̃v���g�^�C�v�錾
void DrawImage(Image& image, int x, int y);

/*
class IMAGE {
public:

	int Title;

	void print();
};

// �����o�[�֐��i���\�b�h�j�̒�`�Ə���
// :: �̓X�R�[�v���Z�q
void POS::print() {
	printf("x : %lf y : %lf\n", x, y);
};
*/