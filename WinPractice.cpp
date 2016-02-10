#include<Windows.h>


static LRESULT CALLBACK MainWindowProc(HWND hWindow, UINT uiMsg, WPARAM wParam, LPARAM lParam );

HINSTANCE hInstAplic = NULL;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpLinhaComando, int ModoDeExibir)

{
	
	hInstAplic = hInstance;
	char WinClass[] = "WinPractice - Window 1";
	WNDCLASSEX wndjPri; 
	wndjPri.hInstance = hInstance;
	wndjPri.lpszClassName = WinClass;
	wndjPri.lpfnWndProc = MainWindowProc;
	wndjPri.cbClsExtra = NULL;
	wndjPri.cbSize = sizeof(WNDCLASSEX);
	wndjPri.lpszMenuName = NULL;

	wndjPri.hbrBackground = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
	wndjPri.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndjPri.hIcon = NULL;
	wndjPri.hIconSm= NULL;
	wndjPri.style = CS_HREDRAW | CS_VREDRAW;
	
	if (!RegisterClassEx(&wndjPri))
		return 0;

	HWND hWindow = CreateWindowEx(0, WinClass, "Main Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	if (hWindow == NULL)
		return 0;

	ShowWindow(hWindow, ModoDeExibir);
	UpdateWindow(hWindow);
	
	MSG winMsg;
		
	while (GetMessage(&winMsg, NULL, 0, 0))
	{
		TranslateMessage(&winMsg);
		DispatchMessage(&winMsg);
	}

	return 0;
}

static LRESULT CALLBACK MainWindowProc(HWND hWindow, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uiMsg)
	{
	case WM_DESTROY:
			PostQuitMessage(0);
	default:
		return DefWindowProc(hWindow,uiMsg, wParam, lParam);
	}

}
