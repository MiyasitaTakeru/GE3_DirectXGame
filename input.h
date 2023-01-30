#pragma once
#include<windows.h>
#include<wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#include "WinApp.h"

class Input
{
public:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

	//メンバ関数
public:
	//初期化
	void Initialize(WinApp* winApp);
	//更新
	void update();
	// 入力
	bool PushKey(BYTE keyNumber);
	// キーのトリガーをチェック
	bool TriggerKey(BYTE keyNumber);

private:
	// キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;
	// 全キーの状態
	BYTE key[256] = {};
	// 前回の全キーの状態
	BYTE keyPre[256] = {};

private:
	// WindowsAPI
	WinApp* winApp = nullptr;
};

