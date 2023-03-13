#pragma once
#include "wx/wx.h"
#include "cLog.h"
#include "cThread.h"

class cMain : public wxFrame {
public:
	cMain();
	~cMain();

private:
	void OnButtonClick(wxCommandEvent& event);
	wxButton* button_start = nullptr;
	wxButton* button_stop = nullptr;
	wxListBox* list_log = nullptr;
	cThread* m_thread;
	cLog* m_logger;	
};