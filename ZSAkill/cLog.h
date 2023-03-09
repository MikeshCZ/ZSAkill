#pragma once
#include "cMain.h"

using namespace std;

class cLog
{
public:
	cLog(cMain* mainObj);
	~cLog();
	void AddLog(string message, int level = 0);

private:
	wxListBox* m_listBox;
};