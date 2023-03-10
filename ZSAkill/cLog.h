#pragma once
#include "cMain.h"

class cLog
{
public:
	cLog(cMain* mainObj);
	~cLog();
	void AddLog(std::string message, int level = 0);

private:
	wxListBox* m_listBox;
};