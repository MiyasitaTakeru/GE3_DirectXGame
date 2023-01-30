#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include <chrono>

#include "WinApp.h"

// DirectX基盤
class DirectXCommon
{
public: // メンバ関数
	// 初期化
	void Initialize(WinApp* winApp);
	// 描画前処理
	void PreDraw();
	// 描画後処理
	void PostDraw();
	// Getter
	// デバイス取得
	ID3D12Device* GetDevice() const { return device.Get(); }

	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

private:
	void InitializeDevice();
	void InitializeCommand();
	void InitializeSwapchain();
	void InitializeRenderTargetView();
	void InitializeDepthBuffer();
	void InitializeFence();
	void InitializeFixFPS();
	void UpdateFixFPS();
private:
	WinApp* winApp = nullptr;

	// デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	// コマンド関連
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	// スワップチェーン
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	// レンダーターゲット
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	// 深度バッファ
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	// フェンス
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
	// 記録時間(FPS固定用)
	std::chrono::steady_clock::time_point reference_;
};