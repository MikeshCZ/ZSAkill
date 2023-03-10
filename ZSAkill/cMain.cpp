#include "cMain.h"
#include "cLog.h"
#include "cProcessKill.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "ZSA Killer", wxDefaultPosition, wxSize(340, 420), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{	
	// Nastaveni vlastnosti okna
	Centre();
	SetBackgroundColour(wxColour(255, 255, 255));
	// SetTransparent(220);

	// Vytvoreni prvku v okne
	button_start = new wxButton(this, 10001, "Start Killing", wxPoint(10, 10), wxSize(145, 50));
	button_stop = new wxButton(this, 10002, "Stop Killing", wxPoint(165, 10), wxSize(145, 50));
	list_log = new wxListBox(this, 20001, wxPoint(10, 70), wxSize(300, 300));

	// Binding prvku
	button_start->Bind(wxEVT_BUTTON, &cMain::OnButtonClick, this);
	button_stop->Bind(wxEVT_BUTTON, &cMain::OnButtonClick, this);
}

cMain::~cMain()
{

}

void cMain::OnButtonClick(wxCommandEvent& event)
{
	cLog looger(this);
	std::wstring processName = L"Notepad.exe";
	
	cProcessKill killer(processName);

	int btnId = event.GetId();
	
	// akce podle tlacitka
	switch (btnId)
	{
	case 10001:
		looger.AddLog(("ZSA killer started"));
		if (killer.killProcess()) {
			// proces byl uspesne ukoncen
			looger.AddLog(("Killed successfully"));
		}
		else {
			// proces nebyl nalezen nebo nelze ukoncit
			looger.AddLog(("Proccess not found"));
		}
		break;
	case 10002:
		looger.AddLog(("ZSA killer stoped"));
		break;
	default:
		looger.AddLog(("Button not found!"));
		break;
	}

	event.Skip();
}