#include"Title.h"

int Image;				//�w�i�摜

int SoundTitle;			//�^�C�g���̉��y
int SoundMoveCorsor;	//�J�[�\���ړ��̌��ʉ�
int	SoundDecision;		//����̌��ʉ�

int LoadImages(void)
{
	if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
}

//int LoadSounds(void)
//{
//
//}

void DrawTitle(void)
{
	DrawGraph(0, 0, Image, FALSE);
}