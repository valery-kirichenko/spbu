#include <Windows.h>
	struct tagWNDCLASSEX{
      UINT cbSize; // величина структуры (в байтах)
      UINT style; // стиль класса окошка
      WNDPROC WndProc; // указатель на имя пользовательской функции
      int cbWndExtra; // число освобождаемых байтов в конце структуры
      int cbClsExtra; // число освобождаемых байтов при создании экземпляра приложения
      HICON hIcon; // дескриптор значка
      HICON hIconMini; // .... маленького значка (в трэе)
      HCURSOR hCursor; // .... курсора мыши
      HBRUSH hbrBack; // .... цвета фона окошка
      HINSTANCE hInst; // .... экземпляра приложения
      LPCTSTR lpszClassName; // указатель на const-строку, содержащюю имя класса
      LPCTSTR lpszMenuName; // указатель на const-строку, содержащюю имя меню, применяемого для класса
	};

	HWND CreateWindow(
                  LPСTSTR lpClassName, // имя нашего класса
                  LPCTSTR lpWindowName, // название окошка (надпись сверху)
                  DWORD dwStyle, // стиль окошка
                  int x, // позиция окошка по оси х
                  int y,  // позиция окна по оси у (отсчёт вниз)
                  int nWidth, // ширина окошка
                  int nHeight, // высота окошка
                  HWND hWndParent, // идентификатор родительского окошка
                  HMENU hMenu, // .....меню
                  HINSTANCE hInst, // дескриптор экз-ра прил-ния
                  LPVOID lParam
                  ); // указатель на данные, передаваемые из пользовательской функции

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdline,int nCommandShow)
{
	MessageBox(NULL, L"Hello World", L"Window",MB_OK);
	HWND hMainWnd;
	

	WNDCLASSEX w;
	WNDPROC WndProc;
	w.cbSize = sizeof(w);
	w.lpfnWndProc = WndProc;
	

	RegisterClassEx;
	
	if(!RegisterClassEx(&w)){
     // в случае отсутствия регистрации класса:
     MessageBox(NULL,
                L"Не получилось зарегистрировать класс!",
                L"Ошибка", MB_OK);
     return NULL; // возвращаем, следовательно, выходим из WinMain
	}


	hMainWnd = CreateWindow(w, // имя класса
                 L"Полноценная оконная процедура", // имя окна (то что сверху)
                 WS_OVERLAPPEDWINDOW | WS_VSCROLL, // режимы отображения окошка
                 CW_USEDEFAULT, // положение окна по оси х (по умолчанию)
                 NULL, // позиция окна по оси у (раз дефолт в х, то писать не нужно)
                 CW_USEDEFAULT, // ширина окошка (по умолчанию)
                 NULL, // высота окна (раз дефолт в ширине, то писать не нужно)
                 HWND(NULL), // дескриптор родительского окошка (у нас нет род. окон)
                 NULL, // дескриптор меню (у нас его нет)
				 HINSTANCE(hInst), // .... экземпляра приложения
                 NULL); // ничего не передаём из WndProc

	
	if(!hMainWnd){
    // в случае некорректного создания окна (неверные параметры и тп):
    MessageBox(NULL, L"Не получилось создать окно!", L"Ошибка", MB_OK);
    return NULL; // выходим из приложения
	}

	ShowWindow(hMainWnd,nCommandShow);
	UpdateWindow(hMainWnd);
	return NULL;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdline,int nCmdShow)
{
	
	
	return NULL;
}