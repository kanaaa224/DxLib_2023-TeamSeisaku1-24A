#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"
#include "ranking_name_input.h"

extern Image image;
extern Font font;

extern Game game;

Init ini;

/********************************
* �Q�[��������
********************************/
void GameInit() { // ������
	game.mode = MAIN;

	ini.StartTime = GetNowCount();

	SetUI(0, 60);
	SetPlayerX(600);
	AppleInit();

	// �����L���O�̎��s�ς݃t���O�����Z�b�g
	SetRankingState(0);

	// �����L���O���͉�ʃ��Z�b�g
	ResetRankingNameInput();
};