#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"

extern Image image;
extern Font font;

extern Game game;

int FPSCount = 0;

/********************************
* �G���h���
********************************/
void DrawEnd() { // ������
	if (FPSCount++ < 300) {

		// �w�i�\��
		DrawGraph(0, 0, image.title, TRUE);

		//�w�iBOX
		DrawBox(5, 5, 1275, 715, 0xffffff, TRUE);

		// Thank you for playing
		DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, font.handle_1_128, 0xffffff);

		//�����
		DrawStringToHandle(10, 150, "�����", 0x000000, font.handle_0_32, 0xffffff);
		DrawStringToHandle(10, 200, "���ۓd�q�r�W�l�X���w�Z", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 230, "�V����K�@�k�����m ���� ���]�@�ʏ闬���@�L���ꐬ",0x000000, font.handle_0_16, 0xffffff);

		// �ӎ�
		//SetFontSize(40); FPS�ቺ��蔭����
		//DrawFormatString(20, 200, 0x000000, "�g�p�����f�ނ̃N���W�b�g");
		//SetFontSize(32);
		DrawStringToHandle(10, 270, "�g�p�����f��", 0x000000, font.handle_0_32, 0xffffff);
		DrawStringToHandle(10, 330, "�v���C���[�摜�i�����j         pictogramming�i�L���ꐬ�jhttps://pictogramming.org/?page_id=2919", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 360, "�v���C���[�摜�i����           pictogramming�i�k�����m�jhttps://pictogramming.org/?page_id=2919", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 390, "��񂲉摜                     illustAC�i��䂱�jhttps://www.ac-illust.com/", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 420, "�Q�[���w�i�摜                 ���炷�Ƃ�@https://www.irasutoya.com/", 0x000000, font.handle_0_16, 0xffffff);

		DrawStringToHandle(10, 450, "�t�H���g                       �a�n�n�s�g�i�ڂ�̂����j�@https://booth.pm/ja", 0x000000, font.handle_0_16, 0xffffff);

		DrawStringToHandle(10, 480, "�Q�[�����C��BGM                �c�n�u�`�[�r�x�m�c�q�n�l�d�@�ishimtone�j https://dova-s.jp/", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 510, "�Q�[�����C���OBGM              �l�����l�t���@https://musmus.main.jp/", 0x000000, font.handle_0_16, 0xffffff);

		DrawStringToHandle(10, 540, "��񂲎擾��SE	                ���ʉ����{�@https://soundeffect-lab.info/", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 570, "�ł�񂲎擾��SE               ���ʉ����{�@https://soundeffect-lab.info/", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 600, "�^�C�g���ł̑I����             ���ʉ����{�@https://soundeffect-lab.info/", 0x000000, font.handle_0_16, 0xffffff);
		DrawStringToHandle(10, 630, "�^�C�g���ł̃J�[�\���ړ���SE   ���ʉ����{�@https://soundeffect-lab.info/", 0x000000, font.handle_0_16, 0xffffff);

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			game.mode = EXIT;
		};

		if (FPSCount == 300) {
			game.mode = EXIT;
		}
	}
};