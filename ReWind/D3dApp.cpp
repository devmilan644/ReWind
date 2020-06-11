#include "D3dApp.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	return D3DApp::GetApp()->MsgProc(hWnd, msg, wParam, lParam);

}


D3DApp* D3DApp::mApp = nullptr;
D3DApp::D3DApp(HINSTANCE hInstance) :
	m_hInst(hInstance)
{
	mApp = this;
}
D3DApp::~D3DApp()
{

}
D3DApp* D3DApp::GetApp()
{
	return mApp;
}

HINSTANCE D3DApp::AppInst() const
{
	return m_hInst;
}

HWND D3DApp::MainWnd() const
{
	return m_hWnd;
}

int D3DApp::Run()
{
	MSG msg = { 0 };

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

bool D3DApp::Initialize()
{
	if (!InitMainWindow()) { return false; }

	return true;
}

LRESULT D3DApp::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	
	case WM_ACTIVATE:
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool D3DApp::InitMainWindow()
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInst;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"DirectX Application";

	if (!RegisterClass(&wc)) {
		MessageBox(0, L"Failed to Register Class", 0, 0);
		return false;
	}

	RECT ClientRect = { 0,0,mClientWidth, mClientHeight };
	AdjustWindowRect(&ClientRect, WS_OVERLAPPEDWINDOW, false);
	int width = ClientRect.right - ClientRect.left;
	int height = ClientRect.bottom - ClientRect.top;

	m_hWnd = CreateWindow(L"DirectX Application", mWndCaption.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		0, 0, m_hInst, 0);

	if (!m_hWnd) {
		MessageBox(0, L"Failed to Create Window", 0, 0);
		return false;
	}

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}
