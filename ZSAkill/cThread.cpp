// cThread.cpp

#include "cThread.h"
#include "cProcessKill.h"

cThread::cThread(wxListBox* list_box) : wxThread(wxTHREAD_DETACHED), m_running(false) {
	m_logger = new cLog(list_box);
}

cThread::~cThread() {
	if (m_logger) delete m_logger;
}

void* cThread::Entry() {
	m_running = true;
	std::wstring processName = L"Notepad.exe";
	cProcessKill killer(processName);
	int i = 0;

	while (m_running) {
		if (killer.killProcess()) {
			m_logger->AddLog("Process killed successfully");
			i = 0;
		}
		else {
			i++;
			// m_logger->AddLog(std::to_string(i), 3); // DEBUG
			if (i >= 100)
			{
				m_logger->AddLog("Process not found", 1);
				i = 0;
			}
		}
		wxMilliSleep(250);
	}

	return nullptr;
}

void cThread::Stop() {
	m_running = false;
}