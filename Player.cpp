#include"DxLib.h"
#include"resourceLoad.h"
#include"PadInput.h"
#include"player.h"
#include"Apple.h"

int Stick;
int FPScount = 0;
int Run = 0;
int Walk = 0;
int Stop = 0;
int RunImg;
int WalkImg;
int StopImg;
int FPS = 0;
int BlinkFPSFlg = 0;

Image playerimage;


void PLAYER::PlayerControll() {
	Stick = PAD_INPUT::GetStickX();	//�X�e�B�b�N�̏�Ԏ擾

	PlayerLimit();

	//�E����
	if (Stick > WALK_RIGHT && Stick < RUN_RIGHT) {
		if (PlayerLimit() == 0) {
			if (speed > WALK_SPEED) {
				speed -= 0.2;
			}
			else if (speed < WALK_SPEED) {
				speed += 0.2;
			}
			else{
				speed = WALK_SPEED;
			}
		}
		FPScount = 0;
	}
	//������
	else if (Stick < WALK_LEFT && Stick > RUN_LEFT) {
		if (PlayerLimit() == 0) {
			if (speed < WALK_SPEED * -1) {
				speed += 0.2;
			}
			else if (speed > WALK_SPEED * -1) {
				speed -= 0.2;
			}
			else {
				speed = WALK_SPEED * -1;
			}
			
		}
		FPScount = 0;
	}
	//�E�_�b�V��
	else if (Stick >= RUN_RIGHT) {
		if (PlayerLimit() == 0) {
			if (speed < 3) {
				speed += 0.2;
			}
			else {
				if (FPScount < 30 && FPScount % 2 == 0) {
					speed += SPEED_UP;
				}
				FPScount++;
			}
		}
	}
	//���_�b�V��
	else if(Stick <= RUN_LEFT) {
		if (PlayerLimit() == 0) {
			if (speed > -3 ) {
				speed -= 0.2;
			}
			else {
				if (FPScount < 30 && FPScount % 2 == 0) {
					speed -= SPEED_UP;
				}
				FPScount++;
			}
		}
	}
	//�����~�܂�
	else if (Stick <= WALK_RIGHT && Stick >= WALK_LEFT) {
		if (PlayerLimit() == 0) {
			//����
			if (speed <= 0.2 && speed >= -0.2) {
				speed = 0;
				FPScount = 0;
			}
			else if (speed > 0) {
				speed -= 0.2;
			}
			else if (speed < 0) {
				speed += 0.2;
			}
			else{
				speed = 0;
				FPScount = 0;
			}
		}
	}
}

int PLAYER::PlayerLimit() {
	//�v���C���[�̈ړ�����
	if (x < MOVE_LEFT_LIMIT) {
		speed = 0;
		x = MOVE_LEFT_LIMIT;
		return 1;
	}
	else if (x > MOVE_RIGHT_LIMIT) {
		speed = 0;
		x = MOVE_RIGHT_LIMIT;
		return 1;
	}
	else {
		x += speed;
		
		return 0;
	}
}

void PLAYER::DrawPlayer() {
    RunImg = Image::GetImages(IMG_RUN, Run);
    WalkImg = Image::GetImages(IMG_WALK, Walk);
    StopImg = Image::GetImages(IMG_STOP, Stop);
	if (flg == TRUE) {
		//�E����
		if (speed > 0 && speed < 3 && x != MOVE_RIGHT_LIMIT) {
			if (FPS % 10 == 0) {
				Walk++;
				if (Walk > 2) {
					Walk = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, WalkImg, TRUE, TRUE);
		}
		//�E�_�b�V��
		else if (speed > 3 && x != MOVE_RIGHT_LIMIT) {
			if (FPS % 5 == 0) {
				Run += 2;
				if (Run > 7) {
					Run = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, RunImg, TRUE, TRUE);

		}
		//������
		else if (speed < 0 && speed > -3 && x != MOVE_LEFT_LIMIT) {
			if (FPS % 10 == 0) {
				Walk++;
				if (Walk > 2) {
					Walk = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, WalkImg, TRUE, FALSE);
		}
		//���_�b�V��
		else if (speed < -2 && x != MOVE_LEFT_LIMIT) {
			if (FPS % 5 == 0) {
				Run += 2;
				if (Run > 7) {
					Run = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, RunImg, TRUE, FALSE);
		}
		//���E�̓���ւ��̍ۂɂ�������Ȃ��Ȃ�悤��
		else if ((Stick < 500 && Stick > -500) || x <= MOVE_LEFT_LIMIT || x >= MOVE_RIGHT_LIMIT) {
            Stop = 0;
			DrawRotaGraph(x, y, IMAGE_RATE, 0, StopImg, TRUE, FALSE);
		}
		//�����~�܂�
		else {
            Stop = 1;
			DrawRotaGraph(x, y, IMAGE_RATE, 0, StopImg, TRUE, FALSE);
		}
	}

	if (BlinkFlg == 0) {
		FPS++;
	}
	

	//�Ń����S�擾���̓_��
	SetPlayerBlinkFlg(Apple::GetBlinkFlg());
	if (BlinkFlg == 1) {
		//FPS�J�E���g������(��x����)
		if (BlinkFPSFlg == 0) {
			FPS = 0;
			BlinkFPSFlg = 1;
		}
		//20f���Ƃɐ؂�ւ�
		if (FPS % 21 == 0) {
			if (flg == TRUE) {
				flg = FALSE;
			}
			else if (flg == FALSE) {
				flg = TRUE;
			}
		}
		FPS++;
		//120f�ŏI��
		if (FPS % 120 == 0) {
			SetPlayerBlinkFlg(0);
			BlinkFPSFlg = 0;
			flg = TRUE;
            Apple::SetBlinkFlg(0);
		}
	}
}

//�|�[�Y���̃v���C���[�̕`��
void PLAYER::DrawPlayerPause() {
	if (flg == TRUE) {
		//�E����
		if (speed > 0 && speed < 3 && x != MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, WalkImg, TRUE, TRUE);
		}
		//�E�_�b�V��
		else if (speed > 2 && x != MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, RunImg, TRUE, TRUE);
		}
		//������
		else if (speed < 0 && speed > -3 && x != MOVE_LEFT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, WalkImg, TRUE, FALSE);
		}
		//���_�b�V��
		else if (speed < -2 && x != MOVE_LEFT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, RunImg, TRUE, FALSE);
		}
		//������
		else if ((Stick < 500 && Stick > -500) || x <= MOVE_LEFT_LIMIT || x >= MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, StopImg, TRUE, FALSE);
		}
		//�����~�܂�
		else {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, StopImg, TRUE, FALSE);
		}
	}
}


int PLAYER::ReturnPlayerX() {
	return x;
}
int PLAYER::ReturnPlayerY() {
	return y;
}

void PLAYER::SetPlayerX(int xPos) {
	x = xPos;
}

void PLAYER::SetPlayerBlinkFlg(int x) {
	BlinkFlg = x;
}

PLAYER::PLAYER() {
	flg = TRUE;
	x = 600;
	y = 600;
	speed = 0;
	BlinkFlg = 0;
}

void PLAYER::SetPlayerFlg(int Pflg) {
	flg = Pflg;
}

int PLAYER::GetPlayerBlinkFlg() {
	return BlinkFlg;
}

void PLAYER::GetImagesClass(Image& player) {
	playerimage = player;
}
