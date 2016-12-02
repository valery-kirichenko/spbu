#include <windows.h> 
int WINAPI WinMain2 ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int nCmdShow) 
{ 
MessageBox (NULL, L"Hello", L"Window", MB_OK); 
return NULL; 
} 
int WINAPI WinMain ( HINSTANCE hInst, HINSTANCE hPreviousInst, LPSTR lpCommandline,  int nCommandShow) 
{ HWND hMainWnd; 
WNDCLASSEX w; 
if(!RegisterClassEx(&w)) 
{ 
MessageBox (NULL, L"Error",L"Window", MB_OK); 
return NULL; 
} 
hMainWnd = CreateWindow(NULL, 
L"Полноценная оконная процедура", 
WS_OVERLAPPEDWINDOW | WS_VSCROLL, 
CW_USEDEFAULT,
NULL, 
CW_USEDEFAULT, 
NULL, 
HWND(NULL), 
NULL, 
HINSTANCE(hInst), 
NULL ); 
ShowWindow (hMainWnd, nCommandShow); 
UpdateWindow(hMainWnd); 
return NULL; 
}
