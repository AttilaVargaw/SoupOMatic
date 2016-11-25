#pragma once

class AskFinal : public wxDialog
{
	wxButton* Buy;
	wxButton* Cancel;

	void OnBuy(wxCommandEvent& event);
	void OnCancel(wxCommandEvent& event);

public:
	AskFinal(wxWindow* parent);
	~AskFinal();
};