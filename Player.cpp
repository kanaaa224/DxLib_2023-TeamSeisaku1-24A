#include"DxLib.h"
#include"PadInput.h"
#include"player.h"

int Stick;
int FPScount = 0;

void PlayerControll() {
	Stick = GetStickX();	//�X�e�B�b�N�̏�Ԏ擾

	PlayerLimit(player.x);

	//�E����
	if (Stick > WALK_RIGHT && Stick < RUN_RIGHT) {
		if (PlayerLimit(player.x) == 0) {
			player.speed = WALK_SPEED;
		}
		FPScount = 0;
	}
	//������
	else if (Stick < WALK_LEFT && Stick > RUN_LEFT) {
		if (PlayerLimit(player.x) == 0) {
			player.speed = WALK_SPEED * -1;
		}
		FPScount = 0;
	}
	//�E�_�b�V��
	else if (Stick >= RUN_RIGHT) {
		if (PlayerLimit(player.x) == 0) {
			if (FPScount < 30) {
				player.speed += SPEED_UP;
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
			if (FPScount < 30) {
				player.speed -= SPEED_UP;
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