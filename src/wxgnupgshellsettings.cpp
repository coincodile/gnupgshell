/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellsettings.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:02:04
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellsettings.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "wxgnupgshellsettings.h"
#include "wxgnupgshellapp.h"

////@begin XPM images
#include "wxwin32x32.xpm"
////@end XPM images

/*!
 * wxGnuPGShellSettings type definition
 */

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellSettings, wxDialog)

/*!
 * wxGnuPGShellSettings event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellSettings, wxDialog )

////@begin wxGnuPGShellSettings event table entries
EVT_LIST_ITEM_SELECTED( ID_SETTINGS_KEYLIST, wxGnuPGShellSettings::OnSettingsKeylistSelected )

EVT_CHECKBOX( ID_SETTINGS_USE_CACHE, wxGnuPGShellSettings::OnSETTINGSUSECACHEClick )

EVT_BUTTON( ID_SETTINGS_BTN_ADD, wxGnuPGShellSettings::OnSettingsBtnAddClick )

EVT_BUTTON( ID_SETTINGS_BTN_DEL, wxGnuPGShellSettings::OnSettingsBtnDelClick )
EVT_UPDATE_UI( ID_SETTINGS_BTN_DEL, wxGnuPGShellSettings::OnSettingsBtnDelUpdate )

////@end wxGnuPGShellSettings event table entries
EVT_MENU( ID_SETTINGS_SET_DEFAULT, wxGnuPGShellSettings::OnSettingsSetDefaultClick )

END_EVENT_TABLE()

/*!
 * wxGnuPGShellSettings constructors
 */

wxGnuPGShellSettings::wxGnuPGShellSettings() {
	Init();
}

wxGnuPGShellSettings::wxGnuPGShellSettings(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellSettings creator
 */

bool wxGnuPGShellSettings::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellSettings creation
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
	wxDialog::Create(parent, id, caption, pos, size, style);

	CreateControls();
	SetIcon(GetIconResource(wxT("wxwin32x32.xpm")));
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
////@end wxGnuPGShellSettings creation
	return true;
}

/*!
 * wxGnuPGShellSettings destructor
 */

wxGnuPGShellSettings::~wxGnuPGShellSettings() {
////@begin wxGnuPGShellSettings destruction
////@end wxGnuPGShellSettings destruction
	wxDELETE(m_popupMenu);
}

/*!
 * Member initialisation
 */

void wxGnuPGShellSettings::Init() {
////@begin wxGnuPGShellSettings member initialisation
	m_keyListCtrl = NULL;
	m_useCache = NULL;
	m_cacheTime = NULL;
	m_defServerCombo = NULL;
////@end wxGnuPGShellSettings member initialisation
}

/*!
 * Control creation for wxGnuPGShellSettings
 */

void wxGnuPGShellSettings::CreateControls() {
////@begin wxGnuPGShellSettings content construction
	wxGnuPGShellSettings *itemDialog1 = this;

	wxBoxSizer *itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	itemDialog1->SetSizer(itemBoxSizer2);

	wxStaticBox *itemStaticBoxSizer3Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Default Key:"));
	wxStaticBoxSizer *itemStaticBoxSizer3 = new wxStaticBoxSizer(
			itemStaticBoxSizer3Static, wxVERTICAL);
	itemBoxSizer2->Add(itemStaticBoxSizer3, 1, wxGROW | wxALL, 2);

	m_keyListCtrl = new wxListView(itemDialog1, ID_SETTINGS_KEYLIST,
			wxDefaultPosition, wxSize(450, 200), wxLC_REPORT | wxLC_SINGLE_SEL);
	if (wxGnuPGShellSettings::ShowToolTips())
		m_keyListCtrl->SetToolTip(_("Right click to set default key"));
	itemStaticBoxSizer3->Add(m_keyListCtrl, 1, wxGROW | wxALL, 1);

	wxStaticBox *itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Passphrase cache"));
	wxStaticBoxSizer *itemStaticBoxSizer5 = new wxStaticBoxSizer(
			itemStaticBoxSizer5Static, wxHORIZONTAL);
	itemBoxSizer2->Add(itemStaticBoxSizer5, 0, wxGROW | wxALL, 5);

	m_useCache = new wxCheckBox(itemDialog1, ID_SETTINGS_USE_CACHE, _T(""),
			wxDefaultPosition, wxDefaultSize, 0);
	m_useCache->SetValue(false);
	itemStaticBoxSizer5->Add(m_useCache, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText7 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Keep passphrase for"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer5->Add(itemStaticText7, 0,
			wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_cacheTime = new wxSpinCtrl(itemDialog1, ID_SETTINGS_CACHE_TIME, _T("0"),
			wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 0);
	if (wxGnuPGShellSettings::ShowToolTips())
		m_cacheTime->SetToolTip(
				_("For unlimited use 0.\nWarning: It is unsecure!"));
	itemStaticBoxSizer5->Add(m_cacheTime, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticText *itemStaticText9 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("minutes."), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer5->Add(itemStaticText9, 0,
			wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticBox *itemStaticBoxSizer10Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Default keyserver:"));
	wxStaticBoxSizer *itemStaticBoxSizer10 = new wxStaticBoxSizer(
			itemStaticBoxSizer10Static, wxVERTICAL);
	itemBoxSizer2->Add(itemStaticBoxSizer10, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	itemStaticBoxSizer10->Add(itemBoxSizer11, 0, wxGROW | wxALL, 5);

	wxArrayString m_defServerComboStrings;
	m_defServerCombo = new wxChoice(itemDialog1, ID_SETTINGS_SERVER_LIST,
			wxDefaultPosition, wxDefaultSize, m_defServerComboStrings, 0);
	itemBoxSizer11->Add(m_defServerCombo, 1, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxButton *itemButton13 = new wxButton(itemDialog1, ID_SETTINGS_BTN_ADD,
			_("+"), wxDefaultPosition, wxSize(30, -1), 0);
	if (wxGnuPGShellSettings::ShowToolTips())
		itemButton13->SetToolTip(_("Add this server to server list"));
	itemBoxSizer11->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL | wxALL, 1);

	wxButton *itemButton14 = new wxButton(itemDialog1, ID_SETTINGS_BTN_DEL,
			_("-"), wxDefaultPosition, wxSize(30, -1), 0);
	if (wxGnuPGShellSettings::ShowToolTips())
		itemButton14->SetToolTip(_("Delete selected server"));
	itemBoxSizer11->Add(itemButton14, 0, wxALIGN_CENTER_VERTICAL | wxALL, 1);

	wxStaticLine *itemStaticLine15 = new wxStaticLine(itemDialog1,
			ID_SETTINGS_STATICLINE, wxDefaultPosition, wxDefaultSize,
			wxLI_HORIZONTAL);
	itemBoxSizer2->Add(itemStaticLine15, 0, wxGROW | wxALL, 5);

	wxStdDialogButtonSizer *itemStdDialogButtonSizer16 =
			new wxStdDialogButtonSizer;

	itemBoxSizer2->Add(itemStdDialogButtonSizer16, 0, wxALIGN_RIGHT | wxALL, 5);
	wxButton *itemButton17 = new wxButton(itemDialog1, wxID_CANCEL,
			_("&Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer16->AddButton(itemButton17);

	wxButton *itemButton18 = new wxButton(itemDialog1, wxID_OK, _("&OK"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer16->AddButton(itemButton18);

	itemStdDialogButtonSizer16->Realize();

	// Connect events and objects
	m_keyListCtrl->Connect(ID_SETTINGS_KEYLIST, wxEVT_CONTEXT_MENU,
			wxContextMenuEventHandler(wxGnuPGShellSettings::OnContextMenu),
			NULL, this);
////@end wxGnuPGShellSettings content construction
	FillKeyListColumns();
	m_keyListCtrl->SetColumnWidth(1, 250);
	ListKeys();

	m_defServerCombo->Append(wxGetApp().m_serverList);

	// select default server
	m_defServerCombo->SetStringSelection(wxGetApp().m_defaultKeyServer);

	// select default item
	m_selectedKey = m_keyListCtrl->FindItem(0, wxGetApp().m_defKey, true);
	if (m_selectedKey != wxNOT_FOUND) {
		m_keyListCtrl->SetItem(m_selectedKey, 2, wxT("*"));
	}

	m_useCache->SetValue(wxGetApp().IsCacheInUse());
	m_cacheTime->SetValue(wxGetApp().GetCacheTime());
	// popup menu
	m_popupMenu = AppResources::CreateSettingsMenu();
}

void wxGnuPGShellSettings::FillKeyListColumns() {
	if (!m_keyListCtrl->GetColumnCount()) {
		m_keyListCtrl->InsertColumn(0, _("Key ID"));
		m_keyListCtrl->InsertColumn(1, _("User Name"));
		m_keyListCtrl->InsertColumn(2, _("Default"));
	}
}

void wxGnuPGShellSettings::ListKeys() {
	m_keyListCtrl->DeleteAllItems();

	wxGnuPGKeyPair *key;
	wxColor cl(wxT("#F0F0F9"));
	int count = static_cast<int>(wxGetApp().GetKeyList().GetCount());
	GpgKeyList keyList = wxGetApp().GetKeyList();

	for (int i = 0; i < count; i++) {
		key = keyList[i];
		if (key) {
			m_keyListCtrl->InsertItem(i, key->m_key.Id);
			m_keyListCtrl->SetItem(i, 1, key->m_key.Name);

			if (i % 2) {
				m_keyListCtrl->SetItemBackgroundColour(i, cl);
			} // odd lines color
		}
	}
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellSettings::ShowToolTips() {
	return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellSettings::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellSettings bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
////@end wxGnuPGShellSettings bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellSettings::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellSettings icon retrieval
	wxUnusedVar(name);
	if (name == _T("wxwin32x32.xpm")) {
		wxIcon icon(wxwin32x32_xpm);
		return icon;
	}
	return wxNullIcon;
////@end wxGnuPGShellSettings icon retrieval
}

/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_SETTINGS_KEYLIST
 */

void wxGnuPGShellSettings::OnSettingsKeylistSelected(wxListEvent &event) {
	m_selectedKey = event.GetIndex();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SETTINGS_BTN_ADD
 */

void wxGnuPGShellSettings::OnSettingsBtnAddClick(wxCommandEvent &event) {
	wxString server = wxGetTextFromUser(_("Input server address"),
			_("New key server"));

	if (server != wxEmptyString) {
		m_defServerCombo->Append(server);
		if (m_defServerCombo->GetSelection() == wxNOT_FOUND) {
			m_defServerCombo->SetSelection(0);
		}
	}
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SETTINGS_BTN_DEL
 */

void wxGnuPGShellSettings::OnSettingsBtnDelClick(wxCommandEvent &event) {
	int i = m_defServerCombo->GetSelection();
	if (i != wxNOT_FOUND) {
		m_defServerCombo->Delete(i);
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_SETTINGS_BTN_DEL
 */

void wxGnuPGShellSettings::OnSettingsBtnDelUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_defServerCombo->GetSelection() != wxNOT_FOUND);
}

void wxGnuPGShellSettings::OnSettingsSetDefaultClick(wxCommandEvent &event) {
	if (m_keyListCtrl->GetFirstSelected() == wxNOT_FOUND) {
		return;
	}
	//m_selectedKey = m_keyListCtrl->GetFirtSelected();
	for (int it = 0; it < m_keyListCtrl->GetItemCount(); it++) {
		m_keyListCtrl->SetItem(it, 2, wxEmptyString);
	}

	m_selectedKey = m_keyListCtrl->GetFirstSelected();
	m_keyListCtrl->SetItem(m_selectedKey, 2, wxT("*"));
}

/*!
 * wxEVT_CONTEXT_MENU event handler for ID_SETTINGS_KEYLIST
 */

void wxGnuPGShellSettings::OnContextMenu(wxContextMenuEvent &event) {
	PopupMenu(m_popupMenu);
}

/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SETTINGS_USE_CACHE
 */

void wxGnuPGShellSettings::OnSETTINGSUSECACHEClick(wxCommandEvent &event) {
////@begin wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SETTINGS_USE_CACHE in wxGnuPGShellSettings.
	// Before editing this code, remove the block markers.
	event.Skip();
////@end wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SETTINGS_USE_CACHE in wxGnuPGShellSettings.
}

