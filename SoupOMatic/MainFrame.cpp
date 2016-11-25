#include "stdafx.h"
#include "MainFrame.h"
#include "AskFinal.h"
#include "PinDialog.h"
#include "MechanicManager.h"

MainFrame::MainFrame(MechanicManager mechanicManager, ConfigFile config, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id = wxID_ANY, title, pos, size, style), currentCream(-1), selectedSoup(-1), mechanicManager(mechanicManager)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxGridSizer* MainGrid;
	MainGrid = new wxGridSizer(1, 0, 0, 0);

	wxBoxSizer* ItemSide;
	ItemSide = new wxBoxSizer(wxVERTICAL);

	ItemScroller = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	ItemScroller->SetScrollRate(5, 5);

	Items = new wxBoxSizer(wxVERTICAL);

	ItemScroller->SetSizer(Items);
	ItemScroller->Layout();
	Items->Fit(ItemScroller);
	ItemSide->Add(ItemScroller, 1, wxEXPAND | wxALL, 5);

	FlavoursScroller = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	FlavoursScroller->SetScrollRate(5, 5);
	Flavours = new wxBoxSizer(wxVERTICAL);

	FlavoursScroller->SetSizer(Flavours);
	FlavoursScroller->Layout();
	Flavours->Fit(FlavoursScroller);
	ItemSide->Add(FlavoursScroller, 1, wxEXPAND | wxALL, 5);


	MainGrid->Add(ItemSide, 1, wxEXPAND, 5);

	SideGrid = new wxBoxSizer(wxVERTICAL);

	ItemDescription = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	ItemDescription->Wrap(-1);
	ItemDescription->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_CAPTIONTEXT));
	ItemDescription->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	ItemDescription->SetMinSize(wxSize(-1, 800));

	SideGrid->Add(ItemDescription, 0, wxALL | wxEXPAND, 5);

	wxGridSizer* PayGrid;
	PayGrid = new wxGridSizer(0, 2, 0, 0);

	PayButton = new wxButton(this, wxID_ANY, wxT("Pay"), wxDefaultPosition, wxDefaultSize, 0);
	PayGrid->Add(PayButton, 0, wxALL | wxEXPAND, 5);

	SideGrid->Add(PayGrid, 0, wxALL | wxEXPAND, 5);
	MainGrid->Add(SideGrid, 1, wxEXPAND, 5);

	this->SetSizer(MainGrid);
	this->Layout();
	this->Centre(wxBOTH);

	PayButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::onPay), NULL, this);

	for (auto it : config.soups) {
		auto button = new wxButton(ItemScroller, it.getCode(), it.GetName());
		button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::onClickOnSoup), this);
		Items->Add(button, 0, wxEXPAND | wxALL, 5);
		soupsWithCodes.emplace(it.getCode(), it);
		soupButtons.emplace(it.getCode(), button);
	}

	for (auto it : config.flavours) {
		auto button = new wxButton(FlavoursScroller, it.getCode(), it.GetName());
		button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::onClickOnCream), this);
		Flavours->Add(button, 0, wxEXPAND | wxALL, 5);
		creamWithCodes.emplace(it.getCode(), it);
		creamButtons.emplace(it.getCode(), button);
	}
}

void MainFrame::onClickOnSoup(wxCommandEvent& event) {
	int clickedId = event.GetId();

	ItemDescription->SetLabelText(soupsWithCodes[clickedId].GetText());
	SideGrid->Layout();

	auto currentButton = soupButtons.at(clickedId);

	if (selectedSoup != clickedId) {
		currentButton->SetBackgroundColour(wxColour(0, 255, 255, 0));

		if (selectedSoup > 0) {
			soupButtons.at(selectedSoup)->SetBackgroundColour(wxColour(240, 240, 240, 0));
		}

		selectedSoup = clickedId;
	}
}

void MainFrame::onClickOnCream(wxCommandEvent & event)
{
	int clickedId = event.GetId();

	auto currentButton = creamButtons.at(clickedId);

	if (currentCream != clickedId) {
		currentButton->SetBackgroundColour(wxColour(0, 255, 255, 0));

		if (currentCream > 0) {
			creamButtons.at(currentCream)->SetBackgroundColour(wxColour(240, 240, 240, 0));
		}

		currentCream = clickedId;
	}
	else {
		currentCream = -1;
		currentButton->SetBackgroundColour(wxColour(240, 240, 240, 0));
	}
}

MainFrame::~MainFrame()
{
	PayButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::onPay), NULL, this);
}

void MainFrame::onPay(wxCommandEvent& event) {
	AskFinal final(this);
	if (final.ShowModal() == wxID_OK) {
		Pin pin(this);

		if (mechanicManager.CanPay()) {
			mechanicManager.ServeFromSlot(selectedSoup, currentCream);
		}
		else {
			pin.ShowModal();
		}
	}
}