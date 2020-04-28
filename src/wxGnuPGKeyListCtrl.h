#ifndef _WXGNUPGKEYLISTCTRL_H_
#define _WXGNUPGKEYLISTCTRL_H_

#include <wx/listctrl.h>

class wxGnuPGKeyListCtrl: public wxListView {
public:
	wxGnuPGKeyListCtrl(wxWindow *parent, wxWindowID id, const wxPoint &pos =
			wxDefaultPosition, const wxSize &size = wxDefaultSize, long style =
			wxLC_ICON, const wxValidator &validator = wxDefaultValidator,
			const wxString &name = wxListCtrlNameStr);
	~wxGnuPGKeyListCtrl();
	virtual wxString OnGetItemText(long item, long column) const;
	virtual wxListItemAttr* OnGetItemAttr(long item) const;
	bool Create(wxWindow *parent, wxWindowID id, const wxPoint &pos =
			wxDefaultPosition, const wxSize &size = wxDefaultSize, long style =
			wxLC_ICON, const wxValidator &validator = wxDefaultValidator,
			const wxString &name = wxListCtrlNameStr);
	wxListItemAttr *m_attr;
};

#endif
