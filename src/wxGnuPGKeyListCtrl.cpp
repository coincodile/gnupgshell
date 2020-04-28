#include "wxGnuPGKeyListCtrl.h"
#include "wxgnupgshellapp.h"

wxGnuPGKeyListCtrl::wxGnuPGKeyListCtrl(wxWindow *parent, wxWindowID id,
		const wxPoint &pos, const wxSize &size, long style,
		const wxValidator &validator, const wxString &name) :
		m_attr(NULL) {
	Create(parent, id, pos, size, style, validator, name);
}

wxGnuPGKeyListCtrl::~wxGnuPGKeyListCtrl() {
	wxDELETE(m_attr);
}

bool wxGnuPGKeyListCtrl::Create(wxWindow *parent, wxWindowID id,
		const wxPoint &pos, const wxSize &size, long style,
		const wxValidator &validator, const wxString &name) {
	bool res = wxListView::Create(parent, id, pos, size, style, validator,
			name);
	if (res) {
		m_attr = new wxListItemAttr(
				wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT),
				wxColour(wxT("#F0F0F9")),
				wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
	}
	return res;
}

wxString wxGnuPGKeyListCtrl::OnGetItemText(long item, long column) const {
	if (item < 0
			|| item > static_cast<long>(wxGetApp().GetKeyList().GetCount())) {
		return wxEmptyString;
	}

	// return text
	wxGnuPGKeyPair *key = wxGetApp().GetKeyList()[item];
//	if (node) {
//		wxGnuPGKeyPair *key = node->GetData();
		if (key) {
			switch (column) {
			case 0: // key id
				return key->m_key.Name;
			case 1:
				return key->m_key.Id;
			case 2:
				return key->m_key.Algorithm;
			case 3:
				return key->m_key.GetTrustString();
			case 4:
				return key->m_key.GetExpireDateString();
			default:
				break;
			}
		}
//	}
	return wxEmptyString;
}

wxListItemAttr* wxGnuPGKeyListCtrl::OnGetItemAttr(long item) const {
	if (item % 2) { //background odd items
		return m_attr;
	}
	return NULL;
}
