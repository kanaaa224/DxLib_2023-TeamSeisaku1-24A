// 作：島袋

#include "resourceLoad.h"
#include "DxLib.h"

Resourceload resourceload;
Image image;
Sound sound;
Font font;

int LoadImages(void)
{
	if ((image.title = LoadGraph("Resources/Images/title.png")) == -1) return -1;
	//if ((image.apple = LoadGraph("Resources/Images/apple.png")) == -1) return -1;
	return 0;
}

int LoadSounds(void)
{
	//if ((sound.bgm = LoadSound("Resources/Sounds/bgm.mp3")) == -1) return -1;
	//if ((sound.se = LoadSound("Resources/Sounds/se_1.mp3")) == -1) return -1;
	return 0;
}

int LoadFonts(void)
{
	LPCSTR font_path = "Resources/Fonts/syokakiutage.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) < 0) {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	if (font.state == 0) {
		font.handle = CreateFontToHandle("しょかきうたげ（無料版）", 128, 9, DX_FONTTYPE_EDGE);
		font.state = 1;
	}
	//if ((font.s = LoadFont("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;
	return 0;
}

int ResourceLoad(void)
{
	if (resourceload.state == 0) {
		if (LoadImages() == -1) return -1;
		if (LoadSounds() == -1) return -1;
		if (LoadFonts() == -1) return -1;
		resourceload.state = 1;
	}
	return 0;
}