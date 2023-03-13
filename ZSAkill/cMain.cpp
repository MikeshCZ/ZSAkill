#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "ZSA Killer", wxDefaultPosition, wxSize(340, 420), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {	
	// Nastaveni vlastnosti okna
	Centre();
	SetBackgroundColour(wxColour(255, 255, 255));
	// SetTransparent(220);

	// Vytvoreni prvku v okne
	button_start = new wxButton(this, 10001, "Start Killing", wxPoint(10, 10), wxSize(145, 50));
	button_stop = new wxButton(this, 10002, "Stop Killing", wxPoint(165, 10), wxSize(145, 50));
	list_log = new wxListBox(this, wxID_ANY, wxPoint(10, 70), wxSize(300, 300));

	// Binding prvku
	button_start->Bind(wxEVT_BUTTON, &cMain::OnButtonClick, this);
	button_stop->Bind(wxEVT_BUTTON, &cMain::OnButtonClick, this);
	button_stop->Disable();
	
	// Inicializace logeru
	m_logger = new cLog(list_log);
	
}

cMain::~cMain() {}

void cMain::OnButtonClick(wxCommandEvent& event) {
	int btnId = event.GetId();
	
	// akce podle tlacitka
	switch (btnId) {
	case 10001:
		// Initialize thread
		m_thread = new cThread(list_log);

		m_logger->AddLog("ZSA killer started");
		button_start->Disable();
		m_thread->Run();
		button_stop->Enable();
		break;

	case 10002:
		m_logger->AddLog(("ZSA killer stoped"));
		button_stop->Disable();
		m_thread->Stop();
		button_start->Enable();
		break;

	default:
		m_logger->AddLog(("Button not found!"));
		break;
	}

	event.Skip();
}