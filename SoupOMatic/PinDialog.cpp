#include "stdafx.h"
#include "PinDialog.h"

Pin::Pin(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* AskGrid;
	AskGrid = new wxBoxSizer(wxVERTICAL);

	Cancel = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	AskGrid->Add(Cancel, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(AskGrid);
	this->Layout();

	this->Centre(wxBOTH);

	Cancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Pin::OnCancel), NULL, this);
}

Pin::~Pin()
{
	Cancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Pin::OnCancel), NULL, this);

}

void Pin::OnCancel(wxCommandEvent& event) {
	EndModal(wxID_ABORT);
}
