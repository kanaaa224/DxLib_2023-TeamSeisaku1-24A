#include"DxLib.h"
#include"resourceLoad.h"
#include"PadInput.h"
#include"player.h"


int Stick;
int FPScount = 0;
extern Image image;
int FPS = 0;

void PlayerControll() {
	Stick = GetStickX();	//�X�e�B�b�N�̏�Ԏ擾

	PlayerLimit(player.x);

	//�E����
	if (Stick > WALK_RIGHT && Stick < RUN_RIGHT) {
		if (PlayerLimit(player.x) == 0) {
			if (player.speed != WALK_SPEED) {
				player.speed += 1;
			}
			else{
				player.speed = WALK_SPEED;
			}
		}
		FPScount = 0;
	}
	//������
	else if (Stick < WALK_LEFT && Stick > RUN_LEFT) {
		if (PlayerLimit(player.x) == 0) {
			if (player.speed != WALK_SPEED * -1) {
				player.speed -= 1;
			}
			else {
				player.speed = WALK_SPEED * -1;
			}
			
		}
		FPScount = 0;
	}
	//�E�_�b�V��
	else if (Stick >= RUN_RIGHT) {
		if (PlayerLimit(player.x) == 0) {
			if (player.speed < 5) {
				player.speed += 1;
			}
			else {
				if (FPScount < 20 && FPScount % 2 == 0) {
					player.speed += SPEED_UP;
				}
				FPScount++;
			}
		}
		if (player.x > MOVE_RIGHT_LIMIT) {
			//�����~�܂�̃A�j���[�V����
		}
		else {
			//����A�j���[�V����
		}
	}
	//���_�b�V��
	else if(Stick <= RUN_LEFT) {
		if (PlayerLimit(player.x) == 0) {
			if (player.speed > -5 ) {
				player.speed -= 1;
			}
			else {
				if (FPScount < 20 && FPScount % 2 == 0) {
					player.speed -= SPEED_UP;
				}
				FPScount++;
			}
			
		}
	}
	//�����~�܂�
	else{
		if (PlayerLimit(player.x) == 0) {
			//����
			if (player.speed != 0 && player.speed > 0) {
				player.speed--;
			}
			else if (player.speed != 0 && player.speed < 0) {
				player.speed++;
			}
			else {
				player.speed = 0;
				FPScount = 0;
			}
		}
	}

	
	DrawFormatString(100, 200, 0xffffff, "%d", player.x);
	DrawCircle(player.x, player.y, 15, 0xffffff, TRUE);//(��)
	//DrawRotaGraph(player.x, player.y, 0.45f, 0,image.player[5] , TRUE, FALSE);
	DrawFormatString(390, 30, 0xffffff, "%d", player.x);
	DrawFormatString(390, 60, 0xffffff, "%f", player.speed);
}

int PlayerLimit(int x) {
	//�v���C���[�̈ړ�����
	if (player.x < MOVE_LEFT_LIMIT) {
		player.speed = 0;
		player.x = 10;
		return 1;
	}
	else if (player.x > MOVE_RIGHT_LIMIT) {
		player.speed = 0;
		player.x = 1000;
		return 1;
	}
	else {
		player.x += player.speed;
		
		return 0;
	}
}
int i = 5;
void DrawPlayer() {
	if (player.speed > 0 && player.speed < 11 && player.x != 1000) {
		//DrawGraph(player.x, player.y, image.player[5],TRUE);
		if (FPS % 10 == 0) {
			i++;
			if (i > 7) {
				i = 5;
			}
		}
		if (i == 7) {
			DrawRotaGraph(player.x +30, player.y, 0.45f, 0, image.player[i], TRUE, FALSE);
		}
		else {
			DrawRotaGraph(player.x - 8, player.y, 0.45f, 0, image.player[i], TRUE, FALSE);
		}
	}
	else if (player.speed > 10 && player.x != 1000) {
		//DrawGraph(player.x, player.y, image.player[8], TRUE);
		DrawRotaGraph(player.x + 40, player.y, 0.45f, 0, image.player[8], TRUE, FALSE);
	}
	else if (player.speed < 0 && player.speed > -11 && player.x != 10) {
		//DrawGraph(player.x, player.y, image.player[5],TRUE);
		DrawRotaGraph(player.x + 8, player.y, 0.45f, 0, image.player[5], TRUE, TRUE);
	}
	else if (player.speed < -10 && player.x != 10) {
		//DrawGraph(player.x, player.y, image.player[8], TRUE);
		DrawRotaGraph(player.x - 40, player.y, 0.45f, 0, image.player[8], TRUE, TRUE);
	}
	else {
		DrawRotaGraph(player.x, player.y - 30, 0.45f, 0, image.player[1], TRUE, FALSE);
	}
	FPS++;
}