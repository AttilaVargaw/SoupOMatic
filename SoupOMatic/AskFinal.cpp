#include "stdafx.h"
#include "AskFinal.h"

AskFinal::AskFinal(wxWindow* parent) : wxDialog(parent, 0, "sdf")
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* AskFinalGrid;
	AskFinalGrid = new wxBoxSizer(wxHORIZONTAL);

	Buy = new wxButton(this, wxID_ANY, wxT("Buy"), wxDefaultPosition, wxDefaultSize, 0);
	AskFinalGrid->Add(Buy, 0, wxALL | wxEXPAND, 5);

	Cancel = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	AskFinalGrid->Add(Cancel, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(AskFinalGrid);
	this->Layout();
	AskFinalGrid->Fit(this);

	this->Centre(wxBOTH);

	Buy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AskFinal::OnBuy), NULL, this);
	Cancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AskFinal::OnCancel), NULL, this);
}


AskFinal::~AskFinal()
{
}

void AskFinal::OnBuy(wxCommandEvent& event) {
	EndModal(wxID_OK);
}
void AskFinal::OnCancel(wxCommandEvent& event) {
	EndModal(wxID_ABORT);
}