#include "Input.h"
#include<cassert>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


void Input::Initialize(WinApp* winApp)
{
    // 借りてきたWinAppのインスタンスを記録
    this->winApp - winApp;

    HRESULT result;

    // DirectInputの初期化
    ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        winApp->GetInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));
    // キーボードデバイスの生成
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // 入力データ形式のセット
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
    assert(SUCCEEDED(result));
    // 排他制御レベルのセット
    result = keyboard->SetCooperativeLevel(
        winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::update()
{
    // 前回のキー入力を保存
    memcpy(keyPre, key, sizeof(key));
    // キーボード情報の取得開始
    keyboard->Acquire();
    // 全キーの入力状態を取得する
    keyboard->GetDeviceState(sizeof(key), key);
}

//入力
bool Input::PushKey(BYTE keyNumber)
{
    //押した時
    if (key[keyNumber]) {
        return true;
    }
    //押されなかった時
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    if (key[keyNumber] && !keyPre[keyNumber]) {
        return true;
    }
    return false;
}
