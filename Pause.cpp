#include "Pause.h"

int PauseFlg = 0; //�P�Ȃ�|�[�Y���O�Ȃ�ʏ�

int GetPauseFlg() {
	return PauseFlg;
}

int SetPauseFlg(int num) {
	PauseFlg = num;
	return PauseFlg;
}