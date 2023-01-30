#pragma once
#include <Windows.h>

//WindowsAPI
class WinApp
{
	
public: //�ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
public: //�����o�֐�
	// ������
	void Initialize();
	// �X�V
	void Update();
	// �I��
	void Finalize();
	// ���b�Z�[�W�̏���
	bool ProcessMessage();

public: // getter
	HWND GetHwnd() const { return  hwnd; }
	HINSTANCE GetInstance() const { return w.hInstance; }

public: // �萔
	static const int window_width = 1280;
	static const int window_height = 720;

private:
	// �E�B���h�E�n���h��
	HWND hwnd = nullptr;
	// �E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};

};