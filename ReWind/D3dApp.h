#pragma once
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")

#include <Windows.h>
#include <string>

class D3DApp
{
protected:
	D3DApp(HINSTANCE hInstance);
	D3DApp(const D3DApp& rhs) = delete;
	D3DApp& operator=(const D3DApp& rhs) = delete;
	virtual ~D3DApp();

public:
	static D3DApp* GetApp();	//singleton


	HINSTANCE AppInst() const;
	HWND MainWnd() const;

	int Run();
	virtual bool Initialize();
	virtual LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:

	bool InitMainWindow();


protected:

	static D3DApp* mApp;
	HINSTANCE m_hInst = nullptr; //application instance handle
	HWND m_hWnd = nullptr;	// main window handle
	int mClientWidth = 800;
	int mClientHeight = 600;
	std::wstring mWndCaption = L"Created by DevMilan";
};

