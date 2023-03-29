#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit()
{
	win_frame = new cMain();
	win_frame->Show();
	return true;
}

int cApp::OnExit()
{
	wxEntryCleanup();
	return 0;
}