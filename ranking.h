// ��F����

#pragma once
#define _USE_MATH_DEFINES
#define RANKING_DATA 5


//int RgScore = 0;
//
////�����L���O�f�[�^�\����
//struct RankingData {
//	int number;
//	char name[11];
//	long score;
//};
//
////�����L���O�f�[�^�̕ϐ��錾
//struct RankingData gRanking[RANKING_DATA];

void DrawRanking();
void SortRanking(void);
int SaveRanking(void);
int ReadRanking(void);

class Ranking {
public:
	int score;
	int number;
	char name;

};