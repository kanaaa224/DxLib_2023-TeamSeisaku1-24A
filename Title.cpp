#include"Title.h"
#include"resourceLoad.h"

extern Image image;

//int Image;				//�w�i�摜

int SoundTitle;			//�^�C�g���̉��y
int SoundMoveCorsor;	//�J�[�\���ړ��̌��ʉ�
int	SoundDecision;		//����̌��ʉ�

//int LoadImages(void)
//{
//	if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
//}
int FontHandle;

int LoadImages(void)
{
	LPCSTR font_path = "Resources/font/���傩���������i�����Łj.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X

	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}

	if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
}

//int LoadSounds(void)
//{
//
//}



void DrawTitle(void)
{
	FontHandle= CreateFontToHandle("���傩���������i�����Łj", 128,9 , DX_FONTTYPE_EDGE);

	DrawGraph(0, 0, Image, TRUE);

	/*ChangeFont("���傩���������i�����Łj");
	ChangeFontType(DX_FONTTYPE_EDGE);
	SetFontSize(128);
	DrawString(340, 140, "��񂲂��Ƃ�", 0x000000, 0xffffff);*/

	DrawStringToHandle(340, 140, "��񂲂��Ƃ�", 0x000000, FontHandle, 0xffffff);
		

	DrawGraph(0, 0, image.title, FALSE);
}