#include<windows.h> 
int WINAPI WinMain( HINSTANCE hInstance,HINSTANCE hPrevInstance , LPSTR CpCmdline , int nCmdShow) 
{ 
MessageBox( NULL , L"hello" , L"Window", MB_OK); 

return NULL; 
} 

int WINAPI WinMain2( HINSTANCE hInstance, HINSTANCE hPreviousInst, LPSTR CpCmaline,int nCmdShow) 
{ 
HWND hMainWnd2; 
WNDCLASSEX w; 
if (!RegisterClassEx(&w)) 
{ 

MessageBox( NULL , L"ERROR NOT CHECKED" , L"Window", MB_OK); 

return NULL; 
} 
hMainWnd2 = CreateWindow (NULL , L"Полноценная оконная процедура", WS_OVERLAPPEDWINDOW | WS_VSCROLL , CW_USEDEFAULT, NULL, CW_USEDEFAULT , NULL, 
HWND(NULL), NULL , HINSTANCE(hInstance) , NULL); 
if (!hMainWnd2) 
{ 
MessageBox( NULL , L"ERROR NOT CREATED" , L"Window", MB_OK); 

return NULL; 
} 

ShowWindow(hMainWnd2, nCmdShow); 
UpdateWindow(hMainWnd2); 
}