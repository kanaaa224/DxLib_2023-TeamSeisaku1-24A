#include "DxLib.h"
#include "main.h"
#include "PadInput.h"
#include "player.h"
#include "resourceLoad.h"
#include "test.h"
#include "ranking_name_input.h"

// �v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE  hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR LpCmdLine, _In_ int NCmdShow)
{
	// FPS�̌v���ƕ\�����s�����[�J���ϐ��̐錾
	LONGLONG nowTime = GetNowHiPerformanceCount();
	LONGLONG oldTime = nowTime;
	LONGLONG fpsCheckTime;
	double deltaTime = 0;
	int fpsCounter = 0;
	int fps = 0;

	// �^�C�g����ݒ�
	SetMainWindowText("��񂲂��Ƃ�");

	// ����DxLib�Ƌ������Ȃ��悤��
	SetMainWindowClassName("��񂲂��Ƃ�");

	// �E�C���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// �E�C���h�E�̃T�C�Y
	SetGraphMode(1280, 720, 32);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	// �`����ʂ𗠂ɂ���i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	// ���[�v�O��FPS�v����������
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;

	int nextTime;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && gGameMode != 99&& !(JudgeButton(XINPUT_BUTTON_BACK)))
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		//�R���g���[���[�̓��͂��擾
		//�R���g���[���[��MODE�������ƍ��X�e�B�b�N�Ə\���{�^���̓��͂��t�ɂȂ�
		InputController();

		// testtttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
		// ���\�[�X��ǂݍ���ŁA���� .cpp �ł������o�[�ϐ��ŗ��p�\�ɂ���֐�
		if (ResourceLoad() == -1) return -1;
		// �e�X�g�ŁA����cpp�t�@�C���Ő錾���ꂽ�摜�\���̊֐������s(test.cpp
		drawTest();

		// FPS�̕\��
		SetFontSize(16);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec  %d", fps, deltaTime, GetStickX());

		PlayerControll();

		// ����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		// �P���[�v���_�̃V�X�e�����Ԃ��擾
		oldTime = nowTime;
		nowTime = GetNowHiPerformanceCount();

		// �P���[�v�̎��Ԍo�߂����߂�
		deltaTime = (nowTime - oldTime) / 1000000.0F;

		// �P�b�Ԃ�FPS���v������A�P�b���Ƃɏ���������
		fpsCounter++;
		if (nowTime - fpsCheckTime > 1000000) { // 1000000(240FPS) 500000(120FPS) 250000(60FPS)
			fps = fpsCounter;
			fpsCounter = 0;
			fpsCheckTime = nowTime;
		}

		// FPS60 �Œ�
		nextTime = GetNowCount();
		nextTime += 16;
		if (nextTime > GetNowCount()) {
			WaitTimer(nextTime - GetNowCount());
		}

		//�Q�[�����[�h�Ɖ�ʑJ��
		switch (gGameMode){
		case TITLE:
			break;
		case INIT:
			break;
		case MAIN:
			break;
		case HELP:
			break;
		case RESULT:
			break;
		case INPUTNAME:
			break;
		case RANKING:
			break;
		case END:
			break;
		}
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;

}
