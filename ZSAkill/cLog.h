// cLog.h

#pragma once
#include "wx/wx.h"

using namespace std;

class cLog {
public:
	cLog(wxListBox* list_log);
	~cLog();
	void AddLog(string message, int level = 0);

private:
	string trim_string(const string& string);
	wxListBox* m_listBox;
};