#pragma once
#include "stdafx.h"
#include "MainFrame.h"
#include "ParsedItem.h"
#include "ConfigLoader.h"
#include "MechanicManager.h"

class MainFrame : public wxFrame
{
	wxScrolledWindow* ItemScroller;
	wxScrolledWindow* FlavoursScroller;
	wxStaticText* ItemDescription;
	wxButton* PayButton;
	wxBoxSizer* Flavours;
	wxBoxSizer* Items;
	wxBoxSizer* SideGrid;

	void onPay(wxCommandEvent& event);
	void onClickOnSoup(wxCommandEvent& event);
	void onClickOnCream(wxCommandEvent& event);

	std::map<int, ParsedItem> soupsWithCodes;
	std::map<int, ParsedItem> creamWithCodes;

	std::map<int, wxButton*> soupButtons;
	std::map<int, wxButton*> creamButtons;

	int currentCream;
	int selectedSoup;

	MechanicManager mechanicManager;

public:
	MainFrame(MechanicManager mechanicManager,ConfigFile config, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(751, 462), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~MainFrame();

};