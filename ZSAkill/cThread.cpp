#include "cThread.h"

#include "cProcessKill.h"

cThread::cThread(wxListBox* list_box) : wxThread(wxTHREAD_DETACHED), m_running(false) {
	m_logger = new cLog(list_box);

}

cThread::~cThread() {}

void* cThread::Entry() {
	m_running = true;
	std::wstring processName = L"Notepad.exe";
	cProcessKill killer(processName);

	while (m_running) {
		if (killer.killProcess()) {
			m_logger->AddLog("Killed successfully");
		}
		else {
			m_logger->AddLog("Proccess not found");
		}
		m_logger->AddLog("In the loop");
		wxMilliSleep(1000);
	}

	return nullptr;
}

void cThread::Stop() {
	m_running = false;
}