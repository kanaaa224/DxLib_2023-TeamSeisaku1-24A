#pragma once

static XINPUT_STATE OldKey;
static XINPUT_STATE NowKey;
static XINPUT_STATE KeyFlg;

void InputController();		//コントローラーの入力
int JudgeButton(unsigned char data);		//ボタンの入力
int JudgeReleaseButton(unsigned char data);		//ボタンを離したとき
int GetStickX();		//左スティックのX軸
int GetStickY();		//左スティックのY軸
	