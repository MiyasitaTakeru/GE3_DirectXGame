#include "DirectXCommon.h"
#include "input.h"
#include "WinApp.h"

#include "Sprite.h"
#include "SpriteCommon.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
 
#pragma region 基盤システム初期化
    // WinAPI
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();

    // DxCommon
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    // Input
    Input* input = nullptr;
    input = new Input();
    input->Initialize(winApp);

    // SpriteCommon
    SpriteCommon* spriteCommon = nullptr;
    spriteCommon = new SpriteCommon();
    spriteCommon->Initialize();

#pragma endregion

#pragma region 最初のシーン初期化
    // Sprite
    Sprite* sprite = nullptr;
    sprite = new Sprite();
    sprite->Initialize();

#pragma endregion

    // ゲームループ
    while (true) {
#pragma region 基盤システム更新
        // windowsのメッセージ処理
        if (winApp->ProcessMessage()) {
            // ゲームループを抜ける
            break;
        }
        // 入力の更新
        input->update();
#pragma endregion

#pragma region 最初のシーン更新

#pragma endregion
        // 描画前処理
        dxCommon->PreDraw();

#pragma region 最初のシーン描画

#pragma endregion
        // 描画後処理
        dxCommon->PostDraw();
    }

#pragma region 最初のシーン終了

#pragma endregion

#pragma region 基盤システム終了
    // SpriteCommon
    delete spriteCommon;
    spriteCommon = nullptr;

    // Sprite
    delete sprite;
    sprite = nullptr;

    // Input
    delete input;
    input = nullptr;

    // DxCommon
    delete dxCommon;
    dxCommon = nullptr;

    // WinApp
    winApp->Finalize();
    delete winApp;
    winApp = nullptr;
#pragma endregion
    return 0;
}
