#include "D3DApp.h"

class MainWindow : public D3DApp {

public :
	MainWindow(HINSTANCE hInstance);
	~MainWindow();
	virtual bool Initialize() override;

private:

};

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	PSTR cmdLine,
	int showCmd) {
	
	MainWindow theApp(hInstance);
	if (!theApp.Initialize()) {
		return 0;
	}
	return theApp.Run();

}

MainWindow::MainWindow(HINSTANCE hInstance)
	: D3DApp(hInstance)
{
}

MainWindow::~MainWindow()
{
}

bool MainWindow::Initialize()
{
	if (!D3DApp::Initialize()) {
		return false;
	}
	return true;
}
