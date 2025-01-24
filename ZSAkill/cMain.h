#pragma once
#include "wx/wx.h"
#include "cLog.h"
#include "cThread.h"

class cMain 
	: public wxFrame 
{
public:
	cMain();
	virtual ~cMain();
	int GetSleepTime() const;

private:
	void OnButtonClick(wxCommandEvent& event);
	void OnKeyDown(wxKeyEvent& event);
	void OnSliderChange(wxCommandEvent& event);
	wxButton* button_start = nullptr;
	wxButton* button_stop = nullptr;
	wxListBox* list_log = nullptr;
	wxSlider* m_slider;
	cThread* m_thread;
	cLog* m_logger;
	wxStaticText* m_slider_value;
};