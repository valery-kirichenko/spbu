#include <windows.h>

const int ID_BTN_KILL = 322;
LRESULT CALLBACK WinCallback(HWND hw, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hpi, LPSTR cmdline, int state) {
	WNDCLASS nclass;
	nclass.style = 0;
	nclass.cbClsExtra = nclass.cbWndExtra = 0;

	HCURSOR curs = LoadCursorFromFile(L"curs.cur");

	nclass.hIcon = NULL;
	nclass.hCursor = curs;
	nclass.hInstance = hinst;

	nclass.hbrBackground = (HBRUSH) COLOR_WINDOW;

	nclass.lpfnWndProc = WinCallback; 
	nclass.lpszMenuName = NULL;
	nclass.lpszClassName = L"TestClass";

	if (!RegisterClass(&nclass)) {
		MessageBox(NULL, L"Class is not registered", L"Error message", MB_OK);
		return FALSE;
	}

	HWND hwnd = CreateWindow(L"TestClass", L"WinAPI", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hinst, NULL);

	if (!hwnd) {
		MessageBox(NULL, L"Windows is not created", L"Error message", MB_OK);
		return FALSE;
	}

	HWND btn = CreateWindow(L"BUTTON", L"Kill me please", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 150, 150, 125, 50, hwnd, (HMENU) ID_BTN_KILL, hinst, NULL);
	SetClassLong(btn, GCL_HCURSOR, (LONG) curs);

	if(!btn){
		MessageBox(NULL, L"Button is not created", L"Error message", MB_OK);
		return FALSE;
	}

	ShowWindow(hwnd, state);
	UpdateWindow(hwnd);

	MSG msg;
	int msg_code;

	while ((msg_code = GetMessage(&msg, hwnd, 0, 0)) != 0){
		if (msg_code == -1) {
			// 
			break;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

LRESULT CALLBACK WinCallback(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
		case WM_COMMAND: {
			switch (wp) {
				case ID_BTN_KILL: {
					MessageBox(NULL, L"Well done", L"Callback message", MB_OK);
					DestroyWindow(hw);
					PostQuitMessage(0);
					break;
				}
			}
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
	}

	return DefWindowProc(hw, msg, wp, lp);
}