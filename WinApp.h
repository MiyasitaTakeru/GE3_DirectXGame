#pragma once
#include <Windows.h>

//WindowsAPI
class WinApp
{
	
public: //静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
public: //メンバ関数
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 終了
	void Finalize();
	// メッセージの処理
	bool ProcessMessage();

public: // getter
	HWND GetHwnd() const { return  hwnd; }
	HINSTANCE GetInstance() const { return w.hInstance; }

public: // 定数
	static const int window_width = 1280;
	static const int window_height = 720;

private:
	// ウィンドウハンドル
	HWND hwnd = nullptr;
	// ウィンドウクラスの設定
	WNDCLASSEX w{};

};