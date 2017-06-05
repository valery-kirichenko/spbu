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

}