#include"DxLib.h"
#include"UI.h"
#include"main.h"
#include"init.h"
#include"resourceLoad.h"
#include"Apple.h"
#include <string>
#include"Pause.h"

extern Init ini;
extern Game game;
extern Image image;
extern Font font;

using std::string;
using std::to_string;

void DrawUserInterFace()
{
	//UI�̔w�i
	DrawBox(1000, 0, 1280, 780, 0xd5e458, TRUE);
	DrawBox(1000, 0, 1280, 780, 0x000000, FALSE);

	DrawTimeLimit();
	DrawImg();
}

void DrawTimeLimit()
{
	//�ϐ��𕶎���ɕϊ�
	std::string str = std::to_string(gTimeLimit);

	//�|�[�Y���ł͂Ȃ��Ȃ�v��
	if (GetPauseFlg() == 0) {
		if ((gFpsCnt++) % 28 == 0) {
			gTimeLimit = gTimeLimit - 1;
		}
	}
	//�������ԕ\��
	DrawStringToHandle(1005, 50, "��������", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(1100, 150, str.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	
	//���U���g�J��
	if (gTimeLimit <= 0)
	{
		game.mode = RESULT;
	}
}

void DrawImg()
{
	//��񂲂̉摜
	DrawRotaGraph(1030, 350, 0.125, 0, image.apple[REDAPPLE], TRUE);
	DrawRotaGraph(1140, 350, 0.125, 0, image.apple[BLUEAPPLE], TRUE);
	DrawRotaGraph(1250, 350, 0.125, 0, image.apple[GOLDAPPLE], TRUE);
}

void SetUI(int cnt, int time) {
	gFpsCnt = cnt;
	gTimeLimit = time;
}
