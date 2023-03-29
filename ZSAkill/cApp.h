#pragma once
#include "wx/wx.h"
#include "cMain.h"

class cApp 
	: public wxApp 
{
public:
	virtual bool OnInit();
	virtual int OnExit();

private:
	cMain* win_frame = nullptr;
};