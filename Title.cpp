#include"Title.h"

int Image;				//�w�i�摜

int SoundTitle;			//�^�C�g���̉��y
int SoundMoveCorsor;	//�J�[�\���ړ��̌��ʉ�
int	SoundDecision;		//����̌��ʉ�

/*�摜�ǂݍ���*/
int LoadImages(void)
{
	//�^�C�g���摜�̓ǂݍ���
	if ((Image = LoadGraph("images/title.png")) == -1)return -1;
}
//
///*�T�E���h�ǂݍ���*/
//int LoadSounds(void);
//{
//	//�^�C�g��SE�̓ǂݍ���
//	SoundTitle = LoadSoundMem();
//	SoundMoveCorsor = LoadSoundMem();
//	SoundDecision = LoadSoundMem();
//}

/*�^�C�g��*/
void DrawTitle(void)
{
	DrawString(0, 0, "Hello", 0xffffff);
	DrawGraph(0, 0, Image, FALSE);
}