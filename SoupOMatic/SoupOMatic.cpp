// SoupOMatic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainFrame.h"
#include "ConfigLoader.h"
#include "MechanicManager.h"

class SoupOMatic: public wxApp {
public:
	MainFrame* frame;
	MechanicManager mechanicManager;

	bool OnInit() override {
		ConfigLoader loader("config.json");

		frame = new MainFrame(mechanicManager, loader.GetConfig(),nullptr, -1);
		frame->ShowFullScreen(true);
		SetTopWindow(frame);

		return true;
	}

	void CleanUp() override {
		//frame->Close();
	}
};

IMPLEMENT_APP_NO_MAIN(SoupOMatic);
IMPLEMENT_WX_THEME_SUPPORT;

int main(int argc, char *argv[])
{
	wxEntryStart(argc, argv);
	wxTheApp->CallOnInit();
	wxTheApp->OnRun();
	wxTheApp->CleanUp();

	return 0;
}