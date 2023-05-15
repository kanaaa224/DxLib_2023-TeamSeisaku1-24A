#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"
#include "player.h"
#include "title.h"
#include "test.h"
#include "help.h"
#include "ranking.h"
#include "ranking_name_input.h"
#include "end.h"
#include "init.h"
#include "result.h"
#include"UI.h"
#include "Apple.h"
#include "Pause.h"

extern Image image;
extern Font font;
extern Sound sound;

Game game;

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

	//game.mode = TITLE;

	// ���\�[�X��ǂݍ���ŁA���� .cpp �ł������o�[�ϐ��ŗ��p�\�ɂ���֐��i���܁j
	if (ResourceLoad() == -1) return -1;

	// �����L���O�f�[�^�̓Ǎ�
	if (ReadRanking() == -1) return -1;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && game.mode != 99&& !(JudgeButton(XINPUT_BUTTON_BACK)))
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		//�R���g���[���[�̓��͂��擾
		//�R���g���[���[��MODE�������ƍ��X�e�B�b�N�Ə\���{�^���̓��͂��t�ɂȂ�
		InputController();

		//�Q�[�����[�h�Ɖ�ʑJ��
		switch (game.mode) {
		case TITLE:
			// �^�C�g��
			DrawTitle();
			if (CheckSoundMem(sound.subbgm) == 0) {
				PlaySoundMem(sound.subbgm, DX_PLAYTYPE_BACK, TRUE);
			}
			break;
		case INIT:
			// �Q�[��������
			GameInit();
			StopSoundMem(sound.subbgm);
			break;
		case MAIN:
			// �w�i�\��
			DrawGraph(0, 0, image.title, TRUE);
			
			// �J���p - R�L�[�ŋ������U���g
			if (CheckHitKey(KEY_INPUT_R)) {
				game.mode = RESULT;
			};
			if (JudgeButton(XINPUT_BUTTON_START) == 1) { //�|�[�Y
				if (GetPauseFlg() == 0) {
					SetPauseFlg(1);
				}
				else {
					SetPauseFlg(0);
				}
			}
			// �v���C���[�J�n
			if (GetPauseFlg() == 0) {
				if (game.soundflg == 0) {		//�ŏ������͂��߂���Đ�
					//BGM
					PlaySoundMem(sound.mainbgm, DX_PLAYTYPE_BACK, TRUE);
					game.soundflg = 1;
				}
				else {
					//BGM
					PlaySoundMem(sound.mainbgm, DX_PLAYTYPE_BACK, FALSE);
				}

				PlayerControll();
				DrawPlayer();
				DrawUserInterFace();
				HitBoxPlayer();
				
				//�����S
				FallApple();
			}
			else {
				//BGM
				StopSoundMem(sound.mainbgm);
				for (int i = 0; i < 10; i++) {
					if (ReturnAppleFlg(i) == TRUE) {
						//�����S�̕\��
						DrawRotaGraph(ReturnAppleX(i), ReturnAppleY(i), 0.19, 0, ReturnAppleImg(i), TRUE);
					}
				}
				DrawPlayerPause();
				DrawUserInterFace();
				HitBoxPlayer();
				DrawStringToHandle(200, 310, "-- �|�[�Y�� --", 0x000000, font.handle_1_128, 0xffffff);
				//�����S
				//FallApple();
			}
			break;
		case HELP:
			// �w���v��ʁi���܁j
			DrawHelp();
			break;
		case RESULT:
			//BGM
			StopSoundMem(sound.mainbgm);
			if (CheckSoundMem(sound.subbgm) == 0) {
				PlaySoundMem(sound.subbgm, DX_PLAYTYPE_BACK, TRUE);
			}
			game.soundflg = 0;
			// ���U���g���
			DrawResult();
			break;
		case INPUTNAME:
			// �����L���O���͉�ʁi���܁j
			DrawRankingNameInput();
			break;
		case RANKING:
			// �����L���O���
			DrawRanking();
			break;
		case END:
			// �G���h���
			DrawEnd();
			break;
		case TEST:
			// �e�X�g�ŁA�摜��t�H���g�\���i���܁j�i�^�C�g����T�������Ĕ����j
			DrawTest();
			break;
		}

		// FPS�̕\��
		/*SetFontSize(16);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec  %d", fps, deltaTime, GetStickX());*/
		
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
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;

}
