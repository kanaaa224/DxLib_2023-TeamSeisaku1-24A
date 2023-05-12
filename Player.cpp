#include"DxLib.h"
#include"resourceLoad.h"
#include"PadInput.h"
#include"player.h"
#include"Apple.h"

int Stick;
int FPScount = 0;
extern Image image;
int Run = 0;
int Walk = 0;
int FPS = 0;
//PLAYER player;
int BlinkFPSFlg = 0;

Apple apple;

void PLAYER::PlayerControll() {
	Stick = GetStickX();	//�X�e�B�b�N�̏�Ԏ擾

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
				if (FPScount < 25 && FPScount % 3 == 0) {
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
				if (FPScount < 25 && FPScount % 3 == 0) {
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

	
	//DrawFormatString(100, 200, 0xffffff, "%d", player.x);
	//DrawFormatString(390, 30, 0xffffff, "%d", player.x);
	DrawFormatString(390, 60, 0xffffff, "%f", speed);
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
	if (flg == TRUE) {
		//�E����
		if (speed > 0 && speed < 3 && x != MOVE_RIGHT_LIMIT) {
			if (FPS % 10 == 0) {
				Walk++;
				if (Walk > 2) {
					Walk = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, TRUE);
		}
		//�E�_�b�V��
		else if (speed > 3 && x != MOVE_RIGHT_LIMIT) {
			if (FPS % 5 == 0) {
				Run += 2;
				if (Run > 7) {
					Run = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Run[Run], TRUE, TRUE);

		}
		//������
		else if (speed < 0 && speed > -3 && x != MOVE_LEFT_LIMIT) {
			if (FPS % 10 == 0) {
				Walk++;
				if (Walk > 2) {
					Walk = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, FALSE);
		}
		//���_�b�V��
		else if (speed < -2 && x != MOVE_LEFT_LIMIT) {
			if (FPS % 5 == 0) {
				Run += 2;
				if (Run > 7) {
					Run = 0;
				}
			}
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Run[Run], TRUE, FALSE);
		}
		//���E�̓���ւ��̍ۂɂ�������Ȃ��Ȃ�悤��
		else if ((Stick < 500 && Stick > -500) || x <= MOVE_LEFT_LIMIT || x >= MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Stop[0], TRUE, FALSE);
		}
		//�����~�܂�
		else {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Stop[1], TRUE, FALSE);
		}
	}

	if (BlinkFlg == 0) {
		FPS++;
		apple.HitBoxPlayer();
	}
	

	//�Ń����S�擾���̓_��
	SetPlayerBlinkFlg(apple.GetBlinkFlg());
	if (BlinkFlg == 1) {
		//FPS�J�E���g������(��x����)
		if (BlinkFPSFlg == 0) {
			FPS = 0;
			BlinkFPSFlg = 1;
		}
		//20f���Ƃɐ؂�ւ�
		if (FPS % 30 == 0) {
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
			apple.SetBlinkFlg(0);
		}
	}
}

//�|�[�Y���̃v���C���[�̕`��
void PLAYER::DrawPlayerPause() {
	if (flg == TRUE) {
		//�E����
		if (speed > 0 && speed < 3 && x != MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, TRUE);
		}
		//�E�_�b�V��
		else if (speed > 2 && x != MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Run[Run], TRUE, TRUE);
		}
		//������
		else if (speed < 0 && speed > -3 && x != MOVE_LEFT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, FALSE);
		}
		//���_�b�V��
		else if (speed < -2 && x != MOVE_LEFT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Run[Run], TRUE, FALSE);
		}
		//������
		else if ((Stick < 500 && Stick > -500) || x <= MOVE_LEFT_LIMIT || x >= MOVE_RIGHT_LIMIT) {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Stop[0], TRUE, FALSE);
		}
		//�����~�܂�
		else {
			DrawRotaGraph(x, y, IMAGE_RATE, 0, image.Stop[1], TRUE, FALSE);
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