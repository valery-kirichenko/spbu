#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
    //MessageBox(NULL, L"Hey, hello, cruel world!", L"Note", MB_OK);
	HWND hMainWind;
    WNDCLASSEX W;
    RegisterClassEx(&W);
    hMainWind=CreateWindow(0, L"window", CW_USEDEFAULT, CW_USEDEFAULT,NULL,CW_USEDEFAULT, NULL, HWND(NULL),NULL,HINSTANCE(hInstance),NULL);
	ShowWindow(hMainWind, 1);
	while(true) UpdateWindow(hMainWind);

    return 0;
} 
