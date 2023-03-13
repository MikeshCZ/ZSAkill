// cApp.h

#pragma once
#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp {
public:
	cApp();
	virtual ~cApp();
	virtual bool OnInit();
	virtual int OnExit();

private:
	cMain* win_frame = nullptr;
};