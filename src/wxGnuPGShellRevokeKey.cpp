/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellRevokeKey.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     20/09/2007 13:45:20
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxGnuPGShellRevokeKey.h"
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

#include "wxGnuPGShellRevokeKey.h"

////@begin XPM images
////@end XPM images

/*!
 * wxGnuPGShellRevokeKey type definition
 */

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellRevokeKey, wxDialog)

/*!
 * wxGnuPGShellRevokeKey event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellRevokeKey, wxDialog )

////@begin wxGnuPGShellRevokeKey event table entries
EVT_BUTTON( ID_BUTTON, wxGnuPGShellRevokeKey::OnBUTTONClick )

EVT_UPDATE_UI( wxID_OK, wxGnuPGShellRevokeKey::OnOKUpdate )

////@end wxGnuPGShellRevokeKey event table entries

END_EVENT_TABLE()

/*!
 * wxGnuPGShellRevokeKey constructors
 */

wxGnuPGShellRevokeKey::wxGnuPGShellRevokeKey() {
	Init();
}

wxGnuPGShellRevokeKey::wxGnuPGShellRevokeKey(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellRevokeKey creator
 */

bool wxGnuPGShellRevokeKey::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellRevokeKey creation
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
	wxDialog::Create(parent, id, caption, pos, size, style);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
////@end wxGnuPGShellRevokeKey creation
	return true;
}

/*!
 * wxGnuPGShellRevokeKey destructor
 */

wxGnuPGShellRevokeKey::~wxGnuPGShellRevokeKey() {
////@begin wxGnuPGShellRevokeKey destruction
////@end wxGnuPGShellRevokeKey destruction
}

/*!
 * Member initialisation
 */

void wxGnuPGShellRevokeKey::Init() {
////@begin wxGnuPGShellRevokeKey member initialisation
	m_ids = NULL;
	m_names = NULL;
	m_outputFile = NULL;
	m_reasonRadio = NULL;
	m_ownReason = NULL;
	m_passphrase = NULL;
////@end wxGnuPGShellRevokeKey member initialisation
}

/*!
 * Control creation for wxGnuPGShellRevokeKey
 */

void wxGnuPGShellRevokeKey::CreateControls() {
////@begin wxGnuPGShellRevokeKey content construction
	wxGnuPGShellRevokeKey *itemDialog1 = this;

	wxBoxSizer *itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	itemDialog1->SetSizer(itemBoxSizer2);

	wxStaticText *itemStaticText3 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("\nCreate a revocation certificate for this key(s)\n"),
			wxDefaultPosition, wxSize(-1, 40), wxALIGN_CENTRE);
	itemStaticText3->SetBackgroundColour(wxColour(255, 255, 255));
	itemStaticText3->SetFont(
			wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
	itemBoxSizer2->Add(itemStaticText3, 0, wxGROW | wxALL, 0);

	wxFlexGridSizer *itemFlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
	itemFlexGridSizer4->AddGrowableCol(1);
	itemBoxSizer2->Add(itemFlexGridSizer4, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText5 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Key ID:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText5->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
	itemFlexGridSizer4->Add(itemStaticText5, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_ids = new wxTextCtrl(itemDialog1, ID_REVOKEKEY_IDS, _T(""),
			wxDefaultPosition, wxSize(150, -1), wxTE_READONLY);
	itemFlexGridSizer4->Add(m_ids, 0, wxGROW | wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticText *itemStaticText7 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("User Name:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText7->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
	itemFlexGridSizer4->Add(itemStaticText7, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_names = new wxTextCtrl(itemDialog1, ID_REVOKEKEY_NAMES, _T(""),
			wxDefaultPosition, wxSize(150, -1), wxTE_READONLY);
	itemFlexGridSizer4->Add(m_names, 0,
			wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText9 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Output:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText9->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
	itemFlexGridSizer4->Add(itemStaticText9, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	itemFlexGridSizer4->Add(itemBoxSizer10, 0,
			wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_outputFile = new wxTextCtrl(itemDialog1, ID_TEXTCTRL,
			_("Select output file..."), wxDefaultPosition, wxSize(200, -1),
			wxTE_READONLY);
	itemBoxSizer10->Add(m_outputFile, 1,
			wxALIGN_CENTER_VERTICAL | wxRIGHT | wxTOP | wxBOTTOM, 5);

	wxButton *itemButton12 = new wxButton(itemDialog1, ID_BUTTON,
			_("Browse..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
	itemBoxSizer10->Add(itemButton12, 0,
			wxALIGN_CENTER_VERTICAL | wxLEFT | wxTOP | wxBOTTOM, 5);

	wxArrayString m_reasonRadioStrings;
	m_reasonRadioStrings.Add(_("&No reason"));
	m_reasonRadioStrings.Add(_("Key has been &compromised"));
	m_reasonRadioStrings.Add(_("Key is &superseeded"));
	m_reasonRadioStrings.Add(_("&Key is no &longer used"));
	m_reasonRadio = new wxRadioBox(itemDialog1, ID_REASON_RADIOBOX,
			_("Reason for the revocation"), wxDefaultPosition, wxDefaultSize,
			m_reasonRadioStrings, 0, wxRA_SPECIFY_ROWS);
	m_reasonRadio->SetSelection(0);
	itemBoxSizer2->Add(m_reasonRadio, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText14 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Your own reason:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText14->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
	itemBoxSizer2->Add(itemStaticText14, 0, wxALIGN_LEFT | wxALL, 5);

	m_ownReason = new wxTextCtrl(itemDialog1, ID_OWN_REASON_TEXT, _T(""),
			wxDefaultPosition, wxSize(-1, 75), wxTE_MULTILINE);
	itemBoxSizer2->Add(m_ownReason, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer16, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText17 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Passphrase:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText17->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
	itemBoxSizer16->Add(itemStaticText17, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	m_passphrase = new wxTextCtrl(itemDialog1, ID_REVOKEKEY_PASS, _T(""),
			wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
	itemBoxSizer16->Add(m_passphrase, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticLine *itemStaticLine19 = new wxStaticLine(itemDialog1, wxID_STATIC,
			wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer2->Add(itemStaticLine19, 0, wxGROW | wxALL, 5);

	wxStdDialogButtonSizer *itemStdDialogButtonSizer20 =
			new wxStdDialogButtonSizer;

	itemBoxSizer2->Add(itemStdDialogButtonSizer20, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
	wxButton *itemButton21 = new wxButton(itemDialog1, wxID_OK, _("&OK"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer20->AddButton(itemButton21);

	wxButton *itemButton22 = new wxButton(itemDialog1, wxID_CANCEL,
			_("&Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer20->AddButton(itemButton22);

	itemStdDialogButtonSizer20->Realize();

////@end wxGnuPGShellRevokeKey content construction
	m_goodPath = false;
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellRevokeKey::ShowToolTips() {
	return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellRevokeKey::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellRevokeKey bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
////@end wxGnuPGShellRevokeKey bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellRevokeKey::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellRevokeKey icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
////@end wxGnuPGShellRevokeKey icon retrieval
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_REVOKEKEY_BTN
 */

void wxGnuPGShellRevokeKey::OnBUTTONClick(wxCommandEvent &event) {
	wxFileDialog *fd =
			new wxFileDialog(this, _("Select output file"), wxEmptyString,
					wxString::Format(wxT("%s_revoke.asc"),
							m_ids->GetValue().GetData()),
					_(
							"ASC files (*.asc)|*.asc|PGP files (*.pgp)|*.pgp)|All files (*.*)|*.*"),
					wxFD_SAVE);

	m_goodPath = false;
	if (fd->ShowModal() == wxID_OK) {
		m_outputFile->SetValue(fd->GetPath()); // show first file name in edit
		m_goodPath = true;
	}
	wxDELETE(fd);
}

/*!
 * wxEVT_UPDATE_UI event handler for wxID_OK
 */

void wxGnuPGShellRevokeKey::OnOKUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_passphrase->GetValue() != wxEmptyString && m_goodPath);
}

