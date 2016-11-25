///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainFrame.h"
#include "ConfigLoader.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(ConfigFile config, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
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
}

MainFrame::~MainFrame()
{
	PayButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::onPay), NULL, this);
}