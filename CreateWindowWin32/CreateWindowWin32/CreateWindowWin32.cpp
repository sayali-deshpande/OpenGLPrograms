// CreateWindow.cpp : Basic window 
//
#include "windows.h"

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine,  int iCmdShow)
{
	//Variable declarations
	WNDCLASS wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("Win32 Window");

	//intialization of windows class
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = szAppName;

	//Register class
	RegisterClass(&wndClass);

	//Create window
	hwnd = CreateWindow(szAppName, 
		   TEXT("My First Window"),
		   WS_OVERLAPPEDWINDOW,
		   CW_USEDEFAULT,
		   CW_USEDEFAULT,
		   CW_USEDEFAULT,
		   CW_USEDEFAULT,
		   NULL,
		   NULL,
		   hInstance,
		   NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}

	return(DefWindowProc(hWnd, message, wParam, lParam));
}