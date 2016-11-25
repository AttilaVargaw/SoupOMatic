#include "stdafx.h"

class CantPayDialog : public wxDialog
{
private:

protected:
	wxButton* okButton;

	virtual void OnOk(wxCommandEvent& event);
public:

	CantPayDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("There was a problem while chechking your card."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION);
	~CantPayDialog();

};
