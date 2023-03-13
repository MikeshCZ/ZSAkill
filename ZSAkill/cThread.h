// cThread.h

#pragma once
#include "wx/wx.h"
#include "cLog.h"

using namespace std;

class cThread : public wxThread {
public:
	cThread(wxListBox* list_box);
	virtual ~cThread();
	virtual void* Entry();
	void Stop();

private:
	cLog* m_logger;
	bool m_running;
};