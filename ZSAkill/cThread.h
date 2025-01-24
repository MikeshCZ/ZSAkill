#pragma once
#include "wx/wx.h"
#include "cLog.h"

class cMain;

class cThread 
	: public wxThread 
{
public:
	cThread(wxListBox* list_box, cMain* main_window);
	virtual ~cThread();
	void Stop();

protected:
	virtual void* Entry();

private:
	cLog* m_logger;
	bool m_running;
	cMain* m_main_window;
};