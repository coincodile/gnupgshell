#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxGnuPGShellImportKey.h"
#endif

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wxGnuPGShellImportKey.h"
#include "wxGnuPGWrapper.h"
#include "wxgnupgshellapp.h"
#include <wx/busyinfo.h>

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellImportKey, wxDialog)
BEGIN_EVENT_TABLE( wxGnuPGShellImportKey, wxDialog ) EVT_TEXT( ID_IMPORTKEY_KEY_ID, wxGnuPGShellImportKey::OnIMPORTKEYKEYIDUpdated )
EVT_TEXT( ID_IMPORTKEY_KEY_NAME, wxGnuPGShellImportKey::OnIMPORTKEYKEYNAMEUpdated )
EVT_BUTTON( ID_IMPORTKEY_FIND, wxGnuPGShellImportKey::OnIMPORTKEYFINDClick )
EVT_UPDATE_UI( ID_IMPORTKEY_FIND, wxGnuPGShellImportKey::OnIMPORTKEYFINDUpdate )
EVT_BUTTON( ID_IMPORTKEY_CLEAR, wxGnuPGShellImportKey::OnIMPORTKEYCLEARClick )
EVT_UPDATE_UI( wxID_OK, wxGnuPGShellImportKey::OnOKUpdate )
END_EVENT_TABLE()

wxGnuPGShellImportKey::wxGnuPGShellImportKey() {
	Init();
}

wxGnuPGShellImportKey::wxGnuPGShellImportKey(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

bool wxGnuPGShellImportKey::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
	wxDialog::Create(parent, id, caption, pos, size, style);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
	return true;
}

wxGnuPGShellImportKey::~wxGnuPGShellImportKey() {
}

void wxGnuPGShellImportKey::Init() {
	m_importServer = NULL;
	m_keyIdText = NULL;
	m_keyNameText = NULL;
	m_resultKeyList = NULL;
}

void wxGnuPGShellImportKey::CreateControls() {
	wxGnuPGShellImportKey *itemDialog1 = this;

	wxBoxSizer *itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	itemDialog1->SetSizer(itemBoxSizer2);

	wxStaticText *itemStaticText3 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Choose server:"), wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT | wxALL, 5);

	wxArrayString m_importServerStrings;
	m_importServer = new wxChoice(itemDialog1, ID_IMPORTKEY_SERVER,
			wxDefaultPosition, wxSize(300, -1), m_importServerStrings, 0);
	itemBoxSizer2->Add(m_importServer, 0, wxGROW | wxALL, 5);

	wxStaticBox *itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Key to import"));
	wxStaticBoxSizer *itemStaticBoxSizer5 = new wxStaticBoxSizer(
			itemStaticBoxSizer5Static, wxVERTICAL);
	itemBoxSizer2->Add(itemStaticBoxSizer5, 0, wxGROW | wxALL, 5);

	wxFlexGridSizer *itemFlexGridSizer6 = new wxFlexGridSizer(2, 2, 0, 0);
	itemFlexGridSizer6->AddGrowableCol(1);
	itemStaticBoxSizer5->Add(itemFlexGridSizer6, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText7 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Key ID:"), wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer6->Add(itemStaticText7, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_keyIdText = new wxTextCtrl(itemDialog1, ID_IMPORTKEY_KEY_ID, _T(""),
			wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer6->Add(m_keyIdText, 0,
			wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText9 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Name:"), wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer6->Add(itemStaticText9, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_keyNameText = new wxTextCtrl(itemDialog1, ID_IMPORTKEY_KEY_NAME, _T(""),
			wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer6->Add(m_keyNameText, 0,
			wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	wxButton *itemButton12 = new wxButton(itemDialog1, ID_IMPORTKEY_FIND,
			_("Search"), wxDefaultPosition, wxDefaultSize, 0);
	itemButton12->SetDefault();
	itemBoxSizer11->Add(itemButton12, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxButton *itemButton13 = new wxButton(itemDialog1, ID_IMPORTKEY_CLEAR,
			_("Clear"), wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer11->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer14, 0, wxGROW | wxALL, 5);

	wxStaticLine *itemStaticLine15 = new wxStaticLine(itemDialog1, wxID_STATIC,
			wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer14->Add(itemStaticLine15, 1, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticText *itemStaticText16 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Search results:"), wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer14->Add(itemStaticText16, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticLine *itemStaticLine17 = new wxStaticLine(itemDialog1, wxID_STATIC,
			wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer14->Add(itemStaticLine17, 1, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	m_resultKeyList = new wxListView(itemDialog1, ID_IMPORTKEY_RESULT_LIST,
			wxDefaultPosition, wxSize(400, 100),
			wxLC_REPORT | wxLC_SORT_ASCENDING);
	itemBoxSizer2->Add(m_resultKeyList, 1, wxGROW | wxALL, 5);

	wxStdDialogButtonSizer *itemStdDialogButtonSizer19 =
			new wxStdDialogButtonSizer;

	itemBoxSizer2->Add(itemStdDialogButtonSizer19, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
	wxButton *itemButton20 = new wxButton(itemDialog1, wxID_OK, _("&Import"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer19->AddButton(itemButton20);

	wxButton *itemButton21 = new wxButton(itemDialog1, wxID_CANCEL,
			_("&Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer19->AddButton(itemButton21);

	itemStdDialogButtonSizer19->Realize();

	// Connect events and objects
	m_keyIdText->Connect(ID_IMPORTKEY_KEY_ID, wxEVT_LEFT_DOWN,
			wxMouseEventHandler(wxGnuPGShellImportKey::OnLeftDownImportKey),
			NULL, this);
	m_keyIdText->Connect(ID_IMPORTKEY_KEY_ID, wxEVT_SET_FOCUS,
			wxFocusEventHandler(wxGnuPGShellImportKey::OnKeyIdSetFocus), NULL,
			this);
	m_keyNameText->Connect(ID_IMPORTKEY_KEY_NAME, wxEVT_LEFT_DOWN,
			wxMouseEventHandler(wxGnuPGShellImportKey::OnLeftDownImportName),
			NULL, this);
	m_keyNameText->Connect(ID_IMPORTKEY_KEY_NAME, wxEVT_SET_FOCUS,
			wxFocusEventHandler(wxGnuPGShellImportKey::OnKeyNameSetFocus), NULL,
			this);
	FillColumns();

	m_importServer->Clear();
	m_importServer->Append(wxGetApp().m_serverList);
	// select default server
	m_importServer->SetStringSelection(wxGetApp().m_defaultKeyServer);
}

bool wxGnuPGShellImportKey::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellImportKey::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellImportKey::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

void wxGnuPGShellImportKey::OnIMPORTKEYKEYIDUpdated(wxCommandEvent &event) {
	event.Skip();
}

void wxGnuPGShellImportKey::OnIMPORTKEYKEYNAMEUpdated(wxCommandEvent &event) {
	event.Skip();
}

void wxGnuPGShellImportKey::FillColumns() {
	m_resultKeyList->InsertColumn(0, _("Key ID"), wxLIST_FORMAT_LEFT, 100);
	m_resultKeyList->InsertColumn(1, _("Name"), wxLIST_FORMAT_LEFT, 300);
}

void wxGnuPGShellImportKey::OnOKUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_resultKeyList->GetSelectedItemCount() > 0);
}

void wxGnuPGShellImportKey::OnIMPORTKEYFINDClick(wxCommandEvent &event) {
	wxString key =
			m_keyIdText->GetValue() == wxEmptyString ?
					m_keyNameText->GetValue() : m_keyIdText->GetValue();
	GpgKeyList list;
	wxBusyInfo *info = new wxBusyInfo(_("Please wait, searching key..."), this);
	if (wxGetApp().SearchKeysOnServer(
			m_importServer->GetString(m_importServer->GetSelection()), key,
			list)) {
		for (unsigned int i = 0; i < list.GetCount(); i++) {
			wxGnuPGKeyPair *key = list[i];
			long index = m_resultKeyList->InsertItem(
					m_resultKeyList->GetItemCount(), key->m_key.Id);
			m_resultKeyList->SetItem(index, 1, key->m_key.Name);
		}
	}
	wxDELETE(info);
}

void wxGnuPGShellImportKey::OnIMPORTKEYFINDUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			!(m_keyIdText->GetValue() == wxEmptyString
					&& m_keyNameText->GetValue() == wxEmptyString));
}

void wxGnuPGShellImportKey::OnLeftDownImportKey(wxMouseEvent &event) {
	//m_keyNameText->SetValue(wxEmptyString);
	event.Skip();
}

void wxGnuPGShellImportKey::OnLeftDownImportName(wxMouseEvent &event) {
	//m_keyIdText->SetValue(wxEmptyString);
	event.Skip();
}

void wxGnuPGShellImportKey::OnKeyIdSetFocus(wxFocusEvent &event) {
	m_keyNameText->Clear();
}

void wxGnuPGShellImportKey::OnKeyNameSetFocus(wxFocusEvent &event) {
	m_keyIdText->Clear();
}

void wxGnuPGShellImportKey::OnIMPORTKEYCLEARClick(wxCommandEvent &event) {
	m_resultKeyList->DeleteAllItems();
}

