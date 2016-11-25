#include "stdafx.h"
#include "CantPayDialog.h"

CantPayDialog::CantPayDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* AskGrid;
	AskGrid = new wxBoxSizer(wxVERTICAL);

	okButton = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	AskGrid->Add(okButton, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(AskGrid);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	okButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CantPayDialog::OnOk), NULL, this);
}

CantPayDialog::~CantPayDialog()
{
	okButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CantPayDialog::OnOk), NULL, this);
}

void CantPayDialog::OnOk(wxCommandEvent& event) {
	EndModal(wxID_ABORT);
}