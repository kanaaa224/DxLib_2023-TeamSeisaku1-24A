#pragma once

#define WALK_RIGHT 2000		//�X�e�B�b�N�̌X�������
#define RUN_RIGHT 25000		//�v���C���[��
#define WALK_LEFT -2000		//��Ԃ�
#define RUN_LEFT -25000		//�擾

#define MOVE_LEFT_LIMIT 30		//�v���C���[��
#define MOVE_RIGHT_LIMIT 970	//�ړ�����

#define WALK_SPEED 1	//�����̃X�s�[�h
#define SPEED_UP 0.2		//�����x
#define SPEED_UP1 0.2		//�����x
#define IMAGE_RATE 0.9f	//�v���C���[�摜�̊g�嗦


class PLAYER
{
private:
	int flg;
	float x;
	int y;
	float speed;
	int BlinkFlg;

public:
	

	//�v���C���[�̈ړ�����
	//�v���C���[�����܂��͉E�[�o������ꍇ�P��Ԃ�
	//�ړ��\�ł������ꍇ�O��Ԃ�player.x��player.speed�����Z����
	int PlayerLimit();

	//�v���C���[�̑���
	void PlayerControll();
	//�v���C���[�̕`��
	void DrawPlayer();
	//�|�[�Y���̃v���C���[�̕`��
	void DrawPlayerPause();



	//�v���C���[��X���W���擾
	//�߂�l�Ńv���C���[��X���W��Ԃ�
	int ReturnPlayerX();

	//�v���C���[��Y���W���擾
	//�߂�l�Ńv���C���[��Y���W��Ԃ�
	int ReturnPlayerY();

	//�v���C���[��X���W��ݒ�
	//�����ŗ^����ꂽ�l��X���W�ɐݒ�
	void SetPlayerX(int xPos);

	//�Ń����S�擾���̓_��
	//�����ŗ^����ꂽ�l��BlinkFlg�ɐݒ�iTRUE or FALSE�j
	void SetPlayerBlinkFlg(int x);

	void SetPlayerFlg(int Pflg);
	int GetPlayerBlinkFlg();

	PLAYER();
};

