// ��F����

#include "DxLib.h"
#include "resourceLoad.h"

extern Image image;
extern Font font;

// �^�C�g���摜�\��
void drawHelp() {
	DrawGraph(0, 0, image.title, TRUE);
	DrawGraph(0, 0, image.controller, TRUE);
	DrawGraph(0, 0, image.controller_s, TRUE);
	DrawStringToHandle(340, 140, "�������", 0x000000, font.handle_1, 0xffffff);
};