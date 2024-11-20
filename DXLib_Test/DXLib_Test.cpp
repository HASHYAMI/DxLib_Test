//#include "DxLib.h"
//
//
////プログラム開始位置
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)		//DXライブラリの初期化
//	{
//		return -1;				//エラーが起きたら終了
//	}
//
//	SetGraphMode(1920, 1080, 32);
//	//仮想画面の作成
//	SetDrawScreen(DX_SCREEN_BACK);
//	int GraphHandle = LoadGraph(".png");		//画像パス
//
//	int x = 0; 
//	int y = 0;
//	while (true)
//	{
//		ClearDrawScreen();
//
//		if (CheckHitKey(KEY_INPUT_LEFT) == 1) { x -= 8; }
//		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) { x += 8; }
//		if (CheckHitKey(KEY_INPUT_UP) == 1) { x -= 8; }
//		if (CheckHitKey(KEY_INPUT_DOWN) == 1) { x += 8; }
//
//		DrawGraph(x, y, GraphHandle, FALSE);
//		//画面の反転
//		ScreenFlip();
//		WaitTimer(20);
//		if (ProcessMessage() == -1) { break; }
//		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { break; }
//
//	}
//
//	WaitKey();		//入力待ち
//	
//	DxLib_End();	//Dxライブライの終了処理
//
//	return 0;	//ソフトの終了
//
//}

