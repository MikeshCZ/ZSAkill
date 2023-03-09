#include "cLog.h"
#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>



cLog::cLog(cMain* mainObj)
{
	m_listBox = mainObj->list_log;
}

cLog::~cLog()
{
}

void cLog::AddLog(string message, int level)
{
	// Vycteni casu
	auto now = chrono::system_clock::now();
	time_t time_now = chrono::system_clock::to_time_t(now);

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
	default:
		lvl_Message = " | INFO | ";
		break;
	}

	// spojeni do zpravy a zapsani do okna loggeru
	string log_message = ss.str() + lvl_Message + message;
	m_listBox->AppendString(log_message);
}