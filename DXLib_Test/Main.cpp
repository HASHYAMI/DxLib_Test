#include "DxLib.h"
#include <thread>
#include <iostream>


//プログラム開始位置
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		//DXライブラリの初期化
	{
		std::cerr << "DxLibの初期化に失敗しました" << std::endl;

		return -1;				//エラーが起きたら終了
	}

	const char* imagePath = "Image/TestImage.png";		//動画、画像などのパスを入れる

	//非同期で画像を読み込む関数
	auto loadImageAsync = [](const char* path, int& handle)
	{
		handle = LoadGraph(path);	//読込み
	};

	//非同期スレッド
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

	//仮想画面の作成
	//SetDrawScreen(DX_SCREEN_BACK);
	//int GraphHandle = LoadGraph(".png");		//画像パス

	WaitKey();		//入力待ち

	DxLib_End();	//Dxライブライの終了処理

	return 0;	//ソフトの終了

}