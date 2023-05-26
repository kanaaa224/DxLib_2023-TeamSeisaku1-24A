#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"
#include "ranking_name_input.h"

/********************************
* �Q�[��������
********************************/
void GameInit() {
    Game::ModeSet(MAIN);
	
    AppleCount::AppleMainInit(0, 0, 0, 0, 0);
    

	// �����L���O�̎��s�ς݃t���O�����Z�b�g
	SetRankingState(0);

	// �����L���O���͉�ʃ��Z�b�g
    RankingNameInput::Reset();
};