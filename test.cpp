// ��F����

#include "DxLib.h"
#include "resourceLoad.h"

extern Image image;
extern Font font;

// �^�C�g���摜�\��
void drawTest() {
    DrawGraph(0, 0, image.title, TRUE);
	
	DrawStringToHandle(340, 140, "��񂲂��Ƃ�", 0x000000, font.handle_1, 0xffffff);

	/*
	ChangeFont("���傩���������i�����Łj");
	ChangeFontType(DX_FONTTYPE_EDGE);
	SetFontSize(128);
	DrawString(340, 140, "��񂲂��Ƃ�", 0x000000, 0xffffff);
	*/
};