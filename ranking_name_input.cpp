// ��F����

#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define RANKING_DATA 5
#include <stdio.h>
//#include "image.h"
#include "ResourceLoad.h"
#include "ranking_name_input.h"

extern Image image;

/********************************
* �����L���O���͏���
********************************/
void drawRanking() {
    // �摜�̓ǂݍ���
    DrawGraph(0, 0, image.title, TRUE);
};







/*
void InputName(void) {

    // �����L���O�摜�\��
    DrawGraph(0, 0, gTitleImg, FALSE);

    // �t�H���g�T�C�Y�̐ݒ�
    SetFontSize(20);

    // ���O���͎w��������̕`��
    DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
    DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xFFFFFF);

    // ���O����
    DrawString(150, 310, "> ", 0xFFFFFF);
    DrawBox(160, 305, 300, 335, 0x000055, TRUE);
    if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE) == 1) {
        gRanking[RANKING_DATA - 1].score = gScore; // �����L���O�f�[�^�ɃX�R�A�o�^
        SortRanking(); // �����L���O���ёւ�
        SaveRanking(); // �����L���O�ۑ�
        gGameMode = RANKING; // �Q�[�����[�h�ύX
    };
    //gGameMode = TITLE;
};
*/



