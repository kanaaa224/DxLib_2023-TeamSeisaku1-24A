#include"DxLib.h"
#include"PadInput.h"
#include"player.h"

int Stick;
int FPScount = 0;

void PlayerControll() {
	Stick = GetStickX();	//�X�e�B�b�N�̏�Ԏ擾
	//�E����
	if (Stick > 2000 && Stick < 25000) {
		player.speed = 5;
		FPScount = 0;
	}
	//������
	else if (Stick < -2000 && Stick > -25000) {
		player.speed = -5;
		FPScount = 0;
	}
	//�E�_�b�V��
	else if (Stick >= 25000) {
		if (FPScount < 30) {
			player.speed += 1;
			FPScount++;
		}
	}
	//���_�b�V��
	else if(Stick <= -25000) {
		if (FPScount < 30) {
			player.speed -= 1;
			FPScount++;
		}
	}
	//�����~�܂�
	else{
		player.speed = 0;
		FPScount = 0;
	}

	player.x += player.speed;
	DrawCircle(player.x, player.y, 15, 0xffffff, TRUE);//(��)
}