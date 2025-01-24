#include "cMain.h"

cMain::cMain() 
	: wxFrame(nullptr, wxID_ANY, "ZSA Killer (v1.2)", wxDefaultPosition, wxSize(340, 430), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{	
	// Nastaveni vlastnosti okna
	Centre();
	SetBackgroundColour(wxColour(255, 255, 255));

	// Vytvoreni prvku v okne
	button_start = new wxButton(this, 10001, "Start Killing", wxPoint(10, 10), wxSize(145, 50));
	button_stop = new wxButton(this, 10002, "Stop Killing", wxPoint(165, 10), wxSize(145, 50));
	wxStaticText* delay_text = new wxStaticText(this, wxID_ANY, "Delay:", wxPoint(10, 70), wxSize(50, 30));
	m_slider = new wxSlider(this, wxID_ANY, 250, 0, 1000, wxPoint(50, 67), wxSize(230, 30));
	m_slider_value = new wxStaticText(this, wxID_ANY, "250", wxPoint(280, 70), wxSize(50, 30));
	list_log = new wxListBox(this, wxID_ANY, wxPoint(10, 100), wxSize(300, 280));
	

	// Binding prvku
	this->Bind(wxEVT_KEY_DOWN, &cMain::OnKeyDown, this);
	button_start->Bind(wxEVT_BUTTON, &cMain::OnButtonClick, this);
	button_stop->Bind(wxEVT_BUTTON, &cMain::OnButtonClick, this);
	button_stop->Disable();
	m_slider->Bind(wxEVT_SLIDER, &cMain::OnSliderChange, this);
	
	// Inicializace
	m_logger = new cLog(list_log);
	m_thread = NULL;
}

cMain::~cMain()
{
	delete m_logger;
	delete button_start;
	delete button_stop;
	delete list_log;
	delete m_slider;
	delete m_slider_value;
}

int cMain::GetSleepTime() const
{
	return m_slider->GetValue();
}

void cMain::OnButtonClick(wxCommandEvent& event)
{
	int btnId = event.GetId();
	
	// akce podle tlacitka
	switch (btnId) {
	case 10001:
		// kliknuti na tlacitko START
        m_thread = new cThread(list_log, this);
		m_logger->AddLog("---- ZSA Killer started ----");
		
		button_start->Disable();
		SetTitle("ZSA Killer - running");
		EnableCloseButton(false);
		
		// spusteni paralelniho threadu
		m_thread->Run();
		button_stop->Enable();
		break;

	case 10002:
		// kliknuti na tlacitko STOP
		m_logger->AddLog("---- ZSA Killer stoped ----");
		
		button_stop->Disable();
		EnableCloseButton(true);
		SetTitle("ZSA Killer");
		
		// zastaveni paralelniho threadu
		m_thread->Stop();
		button_start->Enable();
		break;

	default:
		m_logger->AddLog("Button not found!", 2);
		break;
	}

	event.Skip();
}
void cMain::OnKeyDown(wxKeyEvent& event)
{
	// ochrana pokud v dobe kdy bezi paralelni thread zmacknu alt+f4
	if (event.GetKeyCode() == WXK_F4 && event.AltDown()) {
		m_thread->Stop();
		wxMilliSleep(500);
		Destroy();
	}
}

void cMain::OnSliderChange(wxCommandEvent& event)
{
	int value = m_slider->GetValue();
	m_slider_value->SetLabel(std::to_string(value));
	event.Skip();
}