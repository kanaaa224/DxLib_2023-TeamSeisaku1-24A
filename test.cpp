// ��F����

#include "DxLib.h"
#include "resourceLoad.h"

extern Image image;
extern Font font;

// �^�C�g���摜�\��
void drawTest() {
    DrawGraph(0, 0, image.title, TRUE);
	
	DrawStringToHandle(400, 40, "��񂲂��Ƃ�", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(400, 90, "��񂲂��Ƃ�", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(400, 150, "��񂲂��Ƃ�", 0x000000, font.handle_1_128, 0xffffff);

	DrawRotaGraph(100, 150, 0.5f, 0, image.player[0], TRUE);
	DrawRotaGraph(150, 400, 0.5f, 0, image.apple[0], TRUE);

	/*
	ChangeFont("���傩���������i�����Łj");
	ChangeFontType(DX_FONTTYPE_EDGE);
	SetFontSize(128);
	DrawString(340, 140, "��񂲂��Ƃ�", 0x000000, 0xffffff);
	*/
};