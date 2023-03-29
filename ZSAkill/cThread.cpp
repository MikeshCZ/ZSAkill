#include "cThread.h"
#include "cProcessKill.h"

using std::wstring;

cThread::cThread(wxListBox* list_box) 
	: wxThread(wxTHREAD_DETACHED), m_running(false) 
{
	m_logger = new cLog(list_box);
}

cThread::~cThread() 
{
	delete m_logger;
}

void* cThread::Entry() 
{
	m_running = true;
	wstring processName[4] { L"ZSAService.exe", L"ZSATunnel.exe", L"ZSATrayManager.exe", L"ZSATray.exe" };
	cProcessKill killer[4] { processName[0], processName[1], processName[2], processName[3] };

	int kill_done = 0;
	bool killed[4] {};

	while (m_running) {
		// kill all ZSA
		for (int i = 0; i < 4; i++)	killed[i] = killer[i].killProcess();
		
		// write to log if process found and killed
		if (killed[0]) m_logger->AddLog("ZSAService killed");
		if (killed[1]) m_logger->AddLog("ZSATunnel killed");
		if (killed[2]) m_logger->AddLog("ZSATray Man. killed");
		if (killed[3]) m_logger->AddLog("ZSATray killed");

		if (any_of(begin(killed), end(killed), [](bool val) { return val; })) {
			// reset counter if some kill is done
			kill_done = 0;
		}
		else {
			// write to log when there is no process killed for longer time
			kill_done++;

			// m_logger->AddLog(std::to_string(i), 3); // DEBUG
			if (kill_done >= 100)
			{
				m_logger->AddLog("Process not found", 1);
				kill_done = 0;
			}
		}
		wxMilliSleep(250);
	}

	return nullptr;
}

void cThread::Stop() 
{
	m_running = false;
}