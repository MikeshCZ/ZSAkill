#include "cLog.h"
#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>

using chrono::system_clock;

cLog::cLog(wxListBox* list_log)
{
	m_listBox = list_log;
}

void cLog::AddLog(string message, int level) 
{
	// Vycteni casu
	auto now = system_clock::now();
	time_t time_now = system_clock::to_time_t(now);

	// Formatovani casu
	stringstream ss;
	ss << put_time(localtime(&time_now), "[%Y-%m-%d %H:%M:%S]");

	// Nastaveni urovne log hlasky
	string lvl_Message;
	switch (level)
	{
	case 1:
		lvl_Message = " | WARN | ";
		break;
	case 2:
		lvl_Message = " | ERR  | ";
		break;
	case 3:
		lvl_Message = " | DEBG | ";
		break;
	default:
		lvl_Message = " | INFO | ";
		break;
	}

	// spojeni do zpravy a zapsani do okna loggeru s oriznutim zpravy na 28 znaku
	string log_message = ss.str() + lvl_Message + trim_string(message);
	if (m_listBox->GetCount() == 20) {
		m_listBox->Delete(19);
	}
	m_listBox->Insert(log_message, 0);
}

string cLog::trim_string(const string& string)
{
	return string.substr(0, 28);
}