#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	wxButton *button_start = nullptr;
	wxButton *button_stop = nullptr;
	wxListBox *list_log = nullptr;

	void OnButtonClick(wxCommandEvent& event);
};