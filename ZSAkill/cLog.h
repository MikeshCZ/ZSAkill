#pragma once
#include "wx/wx.h"

class cLog {
public:
	cLog(wxListBox* list_log);
	~cLog();
	void AddLog(std::string message, int level = 0);

private:
	wxListBox* m_listBox;
};