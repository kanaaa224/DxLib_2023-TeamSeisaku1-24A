#pragma once

class UI
{
private:
	int gFpsCnt;	//Fps�v��
	int gTimeLimit;	//��������

public:
	/*
	*�֐����FDrawTimeLimit
	*�����Ȃ�
	*�������e
	*�������Ԃ̌v���A�\��
	*/
	void DrawTimeLimit();
	/*
	*�֐����FDrawImg
	*�����Ȃ�
	*�������e
	*��񂲂̉摜��\������
	*/
	void DrawImg();
	/*
	*�֐����FSetUI
	*����
	* int cnt,int time
	*�������e
	*�ϐ��̏�����
	*/
	void SetUI(int cnt, int time);
};
