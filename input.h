#pragma once
#include<windows.h>
#include<wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include "WinApp.h"

class Input
{
public:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

	//�����o�֐�
public:
	//������
	void Initialize(WinApp* winApp);
	//�X�V
	void update();
	// ����
	bool PushKey(BYTE keyNumber);
	// �L�[�̃g���K�[���`�F�b�N
	bool TriggerKey(BYTE keyNumber);

private:
	// �L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> keyboard;
	// �S�L�[�̏��
	BYTE key[256] = {};
	// �O��̑S�L�[�̏��
	BYTE keyPre[256] = {};

private:
	// WindowsAPI
	WinApp* winApp = nullptr;
};

