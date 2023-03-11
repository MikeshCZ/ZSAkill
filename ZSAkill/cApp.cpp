#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {}

cApp::~cApp() {}

bool cApp::OnInit() {
	win_frame = new cMain();
	win_frame->Show();
	return true;
}