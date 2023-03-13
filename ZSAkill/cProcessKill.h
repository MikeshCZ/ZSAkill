#pragma once
#include "cMain.h"

class cProcessKill {
public:
	cProcessKill(const std::wstring& processName);
	~cProcessKill();
	bool killProcess();

private:
	std::wstring m_processName;
};

