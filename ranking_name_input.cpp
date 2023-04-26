// 作：島袋

#include <string>
using std::string;
using std::to_string;

#include "DxLib.h"

#include "resourceLoad.h"
extern Image image;
extern Font font;

#include "ranking_name_input.h"
NameInput nameInput;

#include "main.h"
extern Game game;

#include "PadInput.h"
int rni_selectstate;
int rni_stickflg = 0;

char rni_alphabet[][26] = {
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
std::string rni_inputName = "";
int rni_selecter[] = { 90, 440, 35, 30, 0, 0 };
int rni_state = 0;

// 開発
int mirutame[4];

/********************************
* ランキング入力処理
********************************/
void DrawRankingNameInput() { // 島袋が担当中
    // 背景表示
    DrawGraph(0, 0, image.title, TRUE);

	// タイトル
	DrawStringToHandle(250, 50, "ランキングに登録", 0x000000, font.handle_1_64, 0xffffff);

	// 本文
	int score = 12345;
	std::string str = "スコア：" + std::to_string(score);
	DrawStringToHandle(750, 70, str.c_str(), 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(140, 150, "あなたのスコアが上位５位内に入りました！おめでとうございます。", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(110, 200, "ということで、ランキングに追加します。あなたの名前をどうぞ（強制）", 0x000000, font.handle_1_32, 0xffffff);

	// フォントサイズの設定
	//ChangeFontSize(40); // ループ内で一回のみ機能、二回目は激重になる → バグ発生中、機能しません

	DrawFormatString(600, 20, 0x000000, "%d - %d / %d - %d / %c", rni_selecter[0], rni_selecter[1], rni_selecter[4], rni_selecter[5], rni_alphabet[rni_selecter[4]][rni_selecter[5]]);

	/********************************
	* キーボード描画
	********************************/
	// キーボードエリアの背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 600, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// キーボードの要素を表示
	// テキストボックスの幅を入力文字数に追従
	int inputName_Box_Width = 820;
	if (rni_inputName.length() > 12) {
		int len = (rni_inputName.length()) - 12;
		inputName_Box_Width += (9 * len);
	}
	DrawBox(690, 360, inputName_Box_Width, 398, 0xffffff, FALSE);

	DrawString(680, 370, ">", 0xFFFFFF);
	DrawString(250, 360, "名前を英数字で入力してください", 0xFFFFFF);
	DrawString(250, 380, "左スティックでカーソル移動、Bボタンで入力", 0xFFFFFF);
	DrawString(250, 400, "Xボタンで一字削除、Yボタンで入力確定", 0xFFFFFF);

	DrawString(700, 370, rni_inputName.c_str(), 0xFFFFFF);

	SetFontSize(30);

	// アルファベット大文字の表示
	for (int i = 0; i < 26; i++) {
		DrawFormatString(100 + (i * 42), 440, 0xffffff,"%c", rni_alphabet[0][i]);
	}
	// アルファベット小文字の表示
	for (int i = 0; i < 26; i++) {
		DrawFormatString(100 + (i * 42), 490, 0xffffff, "%c", rni_alphabet[1][i]);
	}
	// 数字キーパッド表示
	for (int i = 0; i < 10; i++) {
		DrawFormatString(435 + (i * 42), 540, 0xffffff, "%c", rni_alphabet[2][i]);
	}

	// セレクター表示
	DrawBox(rni_selecter[0], rni_selecter[1], (rni_selecter[0] + rni_selecter[2]), (rni_selecter[1] + rni_selecter[3]), 0xffffff, FALSE);

	// セレクター処理
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		if (rni_selecter[1] == 440) {
			// １段目のとき
			if (rni_selecter[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// ２段目のとき
			if (rni_selecter[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// ３段目のとき
			if (rni_selecter[0] > 426) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
	} else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		if (rni_selecter[1] == 440) {
			// １段目のとき
			if (rni_selecter[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// ２段目のとき
			if (rni_selecter[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// ３段目のとき
			if (rni_selecter[0] < 804) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
	} else if (CheckHitKey(KEY_INPUT_UP)) {
		if (rni_selecter[1] != 440) {
			// １段目じゃないなら
			if (rni_selecter[1] == 540) {
				// ３段目から２段目へ移動したら差を足す
				rni_selecter[5] = (rni_selecter[5] + 8);
			}
			rni_selecter[1] -= 50;
			rni_selecter[4] -= 1;
		}
	} else if (CheckHitKey(KEY_INPUT_DOWN)) {
		if (rni_selecter[1] != 540) {
			// ３段目じゃないなら
			if (rni_selecter[1] == 490) {
				// ２段目から３段目へ移動したら差を引く
				rni_selecter[5] = (rni_selecter[5] - 8);
				if (rni_selecter[0] >= 846) {
					// ９より右にカーソルがあったら９にする
					rni_selecter[0] = 804;
					rni_selecter[5] = 9;
				} else if(rni_selecter[0] <= 384) {
					//	０より左にカーソルがあったら０にする
					rni_selecter[0] = 426;
					rni_selecter[5] = 0;
				}
			}
			rni_selecter[1] += 50;
			rni_selecter[4] += 1;
		}
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		rni_inputName += rni_alphabet[rni_selecter[4]][rni_selecter[5]];
		nameInput.inputedName = rni_inputName;
	};
	if (CheckHitKey(KEY_INPUT_DELETE)) {
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		}
	};


	if (CheckHitKey(KEY_INPUT_0)) {
		rni_inputName += "A";
	};

	

	



	/*for (int i = 0; i < (sizeof(rni_alphabet) / sizeof(rni_alphabet[0])); i++) {
		DrawFormatString(10 + (i * 20), 350, 0x000000, "%c", rni_alphabet[i]);
	}*/










	// 戻る表示
	DrawStringToHandle(520, 670, "Aボタンでスキップ", 0x000000, font.handle_1_32, 0xffffff);

	// ゲームモードセレクト処理
	if (rni_selectstate = GetStickY() > 32000 && rni_stickflg == 0) {
		//if (title.state <= 0) {
		//	title.state = 3;
		//}
		//else {
		//	title.state -= 1;
		//};
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickY() < -32000 && rni_stickflg == 0) {
		//if (title.state >= 3) {
		//	title.state = 0;
		//}
		//else {
		//	title.state += 1;
		//};
		rni_stickflg = 1;
	};
	// スティックが戻ると操作受付
	if (rni_selectstate = GetStickY() < 1200 && rni_stickflg == 1) {
		if (rni_selectstate = GetStickY() > -1200) {
			rni_stickflg = 0;
		};
	};
	// Bボタンで選択
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		//if (title.state == 0) {
		//	// スタート選択
		//	game.mode = INIT;
		//}
		//else if (title.state == 1) {
		//	// ヘルプ選択
		//	game.mode = HELP;
		//}
		//else if (title.state == 2) {
		//	// ランキング選択
		//	game.mode = RANKING;
		//}
		//else if (title.state == 3) {
		//	// 終わる選択
		//	game.mode = END;
		//};
	};

	// キーボード入力対応
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        game.mode = TITLE;
    };

	// 開発用
	//DrawCircle(mirutame[0], mirutame[1], mirutame[2], 0xffffff, FALSE);
	DrawBox(mirutame[0], mirutame[1], mirutame[0] + mirutame[2], mirutame[1] + mirutame[3], 0xffffff, FALSE);
	DrawFormatString(mirutame[0], mirutame[1], 0xffffff, "%d - %d", mirutame[0], mirutame[1]);
	if (CheckHitKey(KEY_INPUT_W)) {
		mirutame[1]--;
	};
	if (CheckHitKey(KEY_INPUT_S)) {
		mirutame[1]++;
	};
	if (CheckHitKey(KEY_INPUT_A)) {
		mirutame[0]--;
	};
	if (CheckHitKey(KEY_INPUT_D)) {
		mirutame[0]++;
	};
	if (CheckHitKey(KEY_INPUT_Q)) {
		mirutame[2]--;
	};
	if (CheckHitKey(KEY_INPUT_E)) {
		mirutame[2]++;
	};
	if (CheckHitKey(KEY_INPUT_R)) {
		mirutame[3]--;
	};
	if (CheckHitKey(KEY_INPUT_F)) {
		mirutame[3]++;
	};
};

