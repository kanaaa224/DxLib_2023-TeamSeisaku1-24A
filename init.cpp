#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include"init.h"

extern Image image;
extern Font font;

extern Game game;

Init ini;

/********************************
* �Q�[��������
********************************/
void GameInit() {
	game.mode = MAIN;

	ini.StartTime = GetNowCount();
};