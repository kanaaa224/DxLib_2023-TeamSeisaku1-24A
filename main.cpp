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

Image image;
Font font;
Sound sound;

Game game;
PLAYER player;

Apple apple;

int playerx;
int playery;

UI ui;
Title title;


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

	double nextTime;

	//game.mode = TITLE;

	// ���\�[�X��ǂݍ���ŁA���� .cpp �ł������o�[�ϐ��ŗ��p�\�ɂ���֐��i���܁j
	//if (ResourceLoad() == -1) return -1;
	if (image.LoadImages() == -1)return -1;
	if (sound.LoadSounds() == -1)return -1;
	if (font.LoadFonts() == -1)return -1;

	//extrun����
	//player.GetImagesClass(image);

    //apple.GetAppleImgClass(image);
    //apple.GetSoundClass(sound);
    //apple.GetFontClass(font);

	// �����L���O�f�[�^�̓Ǎ�
	if (ReadRanking() == -1) return -1;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && game.mode != 99&& !(PAD_INPUT::JudgeButton(XINPUT_BUTTON_BACK)))
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		//�R���g���[���[�̓��͂��擾
		//�R���g���[���[��MODE�������ƍ��X�e�B�b�N�Ə\���{�^���̓��͂��t�ɂȂ�
		PAD_INPUT::InputController();

		//�Q�[�����[�h�Ɖ�ʑJ��
		switch (game.mode) {
		case TITLE:
			// �^�C�g��
			title.DrawTitle();
			if (CheckSoundMem(Sound::GetSounds(SND_BGM_SUB)) == 0) {
				PlaySoundMem(Sound::GetSounds(SND_BGM_SUB), DX_PLAYTYPE_LOOP, TRUE);
			}
			break;

		case INIT:
			// �Q�[��������
			GameInit();
			StopSoundMem(Sound::GetSounds(SND_BGM_SUB));
			apple.SetBlinkFlg(0);
			player.SetPlayerX(600);
			player.SetPlayerFlg(TRUE);
			ui.SetUI(0,60);
			break;

		case MAIN:
			// �w�i�\��
			DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);
			
			// �J���p - R�L�[�ŋ������U���g
			if (CheckHitKey(KEY_INPUT_R)) {
				game.mode = RESULT;
			};
			if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_START) == 1) { //�|�[�Y
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
					PlaySoundMem(Sound::GetSounds(SND_BGM_MAIN), DX_PLAYTYPE_LOOP, TRUE);
					game.soundflg = 1;
				}
				else {
					//BGM
					PlaySoundMem(Sound::GetSounds(SND_BGM_MAIN), DX_PLAYTYPE_LOOP, FALSE);
				}

				player.PlayerControll();
				player.DrawPlayer();
				ui.DrawImg();
				ui.DrawTimeLimit();

				apple.HitBoxPlayer();
				
				//�����S
				apple.FallApple();
				
				playerx = player.ReturnPlayerX();
				apple.GetPlayerX(playerx);
				playery = player.ReturnPlayerY();
				apple.GetPlayerY(playery);

				apple.GetPlayerX(player.ReturnPlayerX());
				apple.GetPlayerY(player.ReturnPlayerY());

			}
			else {
				//BGM
				StopSoundMem(Sound::GetSounds(SND_BGM_MAIN));
				for (int i = 0; i < 10; i++) {
					if (apple.ReturnAppleFlg(i) == TRUE) {
						//�����S�̕\��
						DrawRotaGraph(apple.ReturnAppleX(i), apple.ReturnAppleY(i), 0.19, 0, apple.ReturnAppleImg(i), TRUE);
					}
				}
				player.DrawPlayerPause();
				ui.DrawImg();
				ui.DrawTimeLimit();
                apple.DrawPause();
				DrawStringToHandle(200, 310, "-- �|�[�Y�� --", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);
			}
			break;

		case HELP:
			// �w���v��ʁi���܁j
			DrawHelp();
			break;

		case RESULT:
			//BGM
			StopSoundMem(Sound::GetSounds(SND_BGM_MAIN));
			if (CheckSoundMem(Sound::GetSounds(SND_BGM_SUB)) == 0) {
				PlaySoundMem(Sound::GetSounds(SND_BGM_SUB), DX_PLAYTYPE_LOOP, TRUE);
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
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec", fps, deltaTime);*/

		/*PlayerControll();
		DrawPlayer();*/
		
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
		nextTime += 16.6666666666667;
		if (nextTime > GetNowCount()) {
			WaitTimer(nextTime - GetNowCount());
		}
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;

}
