#pragma once
#include "stdafx.h"

class Pin : public wxDialog
{
private:

protected:
	wxButton* Cancel;
	void OnCancel(wxCommandEvent& event);

public:

	Pin(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Use the keyboard"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(270, 64), long style = wxDEFAULT_DIALOG_STYLE);
	~Pin();

};