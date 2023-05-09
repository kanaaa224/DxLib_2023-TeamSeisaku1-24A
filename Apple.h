#pragma once

#ifndef APPLE_H
#define APPLE_H

//マクロ定義
#define REDAPPLE 0 
#define BLUEAPPLE 1
#define GOLDAPPLE 2
#define POISONAPPLE 3

#define LINE_NUM 7

//型定義

/************************************************
*　変数の宣言（グローバル変数:Apple.cpp内）
************************************************/
//int gAppleImg[20];	//りんごの画像変数
extern int gP;			//りんごの確率

extern int gOldTime;	//前時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数
extern int gNowTime;	//後時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数
extern int gTimeFlg;	//時間計測用の変数

extern int gFPSCount;

extern int gRACount;	//赤りんごの個数
extern int gBACount;	//青りんごの個数
extern int gGACount;	//金りんごの個数
extern int gPACount;	//毒りんごの個数
extern int gScore;		//スコア

/************************************************
*　定数の宣言
************************************************/
const int APPLE_MAX = 10;

/************************************************
*　構造体
************************************************/
struct APPLE {
	int flg;			//使用フラグ
	int img;			//画像
	double x, y, w, h;	//座標、幅、高さ
	double speed;		//移動速度
	int point;			//スコア加算ポイント
};

static struct APPLE gApple[10];

//プロトタイプ宣言
//int LoadImges(void);		//画像読込
void FallApple(void);		//リンゴ落下処理
int CreateApple(void);		//リンゴ生成
void AppleSpeed(int i);		//りんごの速度
void AppleInit(int num);		//リンゴの変数の初期化
int HitBox(void);
int HitBoxPlayer(void);
void ApplePoint(int i);		//りんごのスコア処理
int ReturnRA(void);			//gRACountがリザルト画面で使用したいので
int ReturnBL(void);
int ReturnGL(void);
int ReturnPO(void);
int ReturnScore(void);
int ReturnAppleX(int num);
int ReturnAppleY(int num);
int ReturnAppleImg(int num);
int ReturnAppleFlg(int num);
//int ReturnFPSCount(void);
void SetAppleCount(int num);




#endif