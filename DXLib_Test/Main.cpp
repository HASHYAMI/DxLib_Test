#include "DxLib.h"
#include <thread>
#include <iostream>


//�v���O�����J�n�ʒu
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		//DX���C�u�����̏�����
	{
		std::cerr << "DxLib�̏������Ɏ��s���܂���" << std::endl;

		return -1;				//�G���[���N������I��
	}

	const char* imagePath = "Image/TestImage.png";		//����A�摜�Ȃǂ̃p�X������

	//�񓯊��ŉ摜��ǂݍ��ފ֐�
	auto loadImageAsync = [](const char* path, int& handle)
	{
		handle = LoadGraph(path);	//�Ǎ���
	};

	//�񓯊��X���b�h
	int imageHandle = -1;
	std::thread loadThread(loadImageAsync, imagePath, std::ref(imageHandle));

	while (ProcessMessage() == 0) 
	{
		if (imageHandle != -1) 
		{
			ClearDrawScreen();
			DrawGraph(100, 100, imageHandle, TRUE);
		}

		ScreenFlip();
	}

	loadThread.join();

	//���z��ʂ̍쐬
	//SetDrawScreen(DX_SCREEN_BACK);
	//int GraphHandle = LoadGraph(".png");		//�摜�p�X

	WaitKey();		//���͑҂�

	DxLib_End();	//Dx���C�u���C�̏I������

	return 0;	//�\�t�g�̏I��

}