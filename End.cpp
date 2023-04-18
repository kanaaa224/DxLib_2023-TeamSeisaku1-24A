#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* �G���h���
********************************/
void DrawEnd() {
	// �w�i�\��
    DrawGraph(0, 0, image.title, TRUE);
	
	// Thank you for playing
	DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, font.handle_1_128, 0xffffff);

	// �ӎ�
	//SetFontSize(40); FPS�ቺ��蔭����
	//DrawFormatString(20, 200, 0x000000, "�g�p�����f�ނ̃N���W�b�g");
	//SetFontSize(32);
	DrawStringToHandle(10, 200, "�g�p�����f�ނ̃N���W�b�g", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(10, 280, "�v���C���[�摜�FAAA�l", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(10, 320, "�����S�摜�FAAA�l", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(10, 360, "�t�H���g�FAAA�l", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(520, 670, "ESC �L�[�ŕ���", 0x000000, font.handle_1_32, 0xffffff);

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = EXIT;
	};
};