#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = L"мой текст";
 
int WINAPI WinMain(HINSTANCE hInst,
                   HINSTANCE hPrevInst,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    TCHAR szClassName[] = L"мой класс";
    HWND hMainWnd;
    MSG msg; 
    WNDCLASSEX wc; 

    wc.cbSize        = sizeof(wc);
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WndProc; 
    wc.lpszMenuName  = NULL; 
    wc.lpszClassName = szClassName; 
    wc.cbWndExtra    = NULL; 
    wc.cbClsExtra    = NULL; 
    wc.hIcon         = LoadIcon(NULL, IDI_WINLOGO);
    wc.hIconSm       = LoadIcon(NULL, IDI_WINLOGO);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW); 
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.hInstance     = hInst;
    
	if(!RegisterClassEx(&wc))
	{
        MessageBox(NULL, L"класс не получилось зарегистрировть!", L"ошибка", MB_OK);
        return NULL;
    }

    hMainWnd = CreateWindow(
        szClassName, 
        L"оконная процедура", 
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,
        0,
        0,
        500,
        300, 
        (HWND)NULL,
        NULL, 
        HINSTANCE(hInst), 
        NULL); 

    if(!hMainWnd)
	{
        MessageBox(NULL, L"не получилось создать окно!", L"ошибка", MB_OK);
        return NULL;
    }

    ShowWindow(hMainWnd, nCmdShow);
    UpdateWindow(hMainWnd); 
    while(GetMessage(&msg, NULL, NULL, NULL))
	{
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam; 
}
 
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    HDC hDC;
    PAINTSTRUCT ps; 
    RECT rect; 
    COLORREF colorText = RGB(0, 0, 255);
    switch(uMsg){
    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps); 
        GetClientRect(hWnd, &rect); 
        SetTextColor(hDC, colorText); 
        DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
        //EndPaint(hWnd, &ps); 
        break;
    case WM_DESTROY: 
        PostQuitMessage(NULL);
        break;
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam); 
    }
    return NULL; 
}