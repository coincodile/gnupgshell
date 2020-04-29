/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellbackup.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:32:34
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellbackup.h"
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
#include "wxgnupgshellbackup.h"
#include "app_resources.h"
////@end includes

////@begin XPM images
////@end XPM images

/*!
 * wxGnuPGShellBackup type definition
 */

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellBackup, wxDialog)

/*!
 * wxGnuPGShellBackup event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellBackup, wxDialog )

////@begin wxGnuPGShellBackup event table entries
EVT_BUTTON( ID_BACKUP_BROWSE, wxGnuPGShellBackup::OnBackupBrowseClick )

////@end wxGnuPGShellBackup event table entries

END_EVENT_TABLE()

/*!
 * wxGnuPGShellBackup constructors
 */

wxGnuPGShellBackup::wxGnuPGShellBackup() :
		m_importKey(false) {
	Init();
}

wxGnuPGShellBackup::wxGnuPGShellBackup(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellBackup creator
 */

bool wxGnuPGShellBackup::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellBackup creation
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
	wxDialog::Create(parent, id, caption, pos, size, style);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
////@end wxGnuPGShellBackup creation
	return true;
}

/*!
 * wxGnuPGShellBackup destructor
 */

wxGnuPGShellBackup::~wxGnuPGShellBackup() {
////@begin wxGnuPGShellBackup destruction
////@end wxGnuPGShellBackup destruction
}

/*!
 * Member initialisation
 */

void wxGnuPGShellBackup::Init() {
////@begin wxGnuPGShellBackup member initialisation
	m_keyId = NULL;
	m_keyName = NULL;
	m_fileName = NULL;
	m_isArmor = NULL;
	m_isPGP2 = NULL;
////@end wxGnuPGShellBackup member initialisation
}

/*!
 * Control creation for wxGnuPGShellBackup
 */

void wxGnuPGShellBackup::CreateControls() {
////@begin wxGnuPGShellBackup content construction
	wxGnuPGShellBackup *itemDialog1 = this;

	wxBoxSizer *itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	itemDialog1->SetSizer(itemBoxSizer2);

	wxBoxSizer *itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText4 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Key ID:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText4->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL,
					wxFONTWEIGHT_NORMAL, false, FONT_NAME_TAHOMA));
	itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_keyId = new wxStaticText(itemDialog1, ID_BACKUP_KEY_ID, _("<key_id>"),
			wxDefaultPosition, wxDefaultSize, wxSTATIC_BORDER);
	m_keyId->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer3->Add(m_keyId, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText6 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Name:"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText6->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL,
					wxFONTWEIGHT_NORMAL, false, FONT_NAME_TAHOMA));
	itemBoxSizer3->Add(itemStaticText6, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_keyName = new wxStaticText(itemDialog1, ID_BACKUP_KEY_NAME, _("<name>"),
			wxDefaultPosition, wxDefaultSize, wxSTATIC_BORDER);
	m_keyName->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer3->Add(m_keyName, 1, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer8, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText9 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("&File:"), wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer8->Add(itemStaticText9, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_fileName = new wxTextCtrl(itemDialog1, ID_BACKUP_FILENAME, _T(""),
			wxDefaultPosition, wxSize(300, -1), wxTE_READONLY);
	itemBoxSizer8->Add(m_fileName, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxButton *itemButton11 = new wxButton(itemDialog1, ID_BACKUP_BROWSE,
			_("&Browse..."), wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer8->Add(itemButton11, 0, wxGROW | wxALL, 5);

	wxStaticBox *itemStaticBoxSizer12Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Options"));
	wxStaticBoxSizer *itemStaticBoxSizer12 = new wxStaticBoxSizer(
			itemStaticBoxSizer12Static, wxVERTICAL);
	itemBoxSizer2->Add(itemStaticBoxSizer12, 0, wxGROW | wxALL, 5);

	m_isArmor = new wxCheckBox(itemDialog1, ID_BACKUP_CHECK_ARMOR,
			_("Armor (ASCII-armored text)"), wxDefaultPosition, wxDefaultSize,
			0);
	m_isArmor->SetValue(true);
	itemStaticBoxSizer12->Add(m_isArmor, 0, wxALIGN_LEFT | wxALL, 5);

	m_isPGP2 = new wxCheckBox(itemDialog1, ID_BACKUP_CHECK_PGP,
			_("PGP 2.x compatible"), wxDefaultPosition, wxDefaultSize, 0);
	m_isPGP2->SetValue(false);
	itemStaticBoxSizer12->Add(m_isPGP2, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticLine *itemStaticLine15 = new wxStaticLine(itemDialog1,
	ID_STATICLINE, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer2->Add(itemStaticLine15, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer16, 0, wxALIGN_RIGHT | wxALL, 5);

	wxStdDialogButtonSizer *itemStdDialogButtonSizer17 =
			new wxStdDialogButtonSizer;

	itemBoxSizer16->Add(itemStdDialogButtonSizer17, 0, wxALIGN_BOTTOM | wxALL,
			0);
	wxButton *itemButton18 = new wxButton(itemDialog1, wxID_OK, _("&OK"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer17->AddButton(itemButton18);

	wxButton *itemButton19 = new wxButton(itemDialog1, wxID_CANCEL,
			_("&Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer17->AddButton(itemButton19);

	itemStdDialogButtonSizer17->Realize();

////@end wxGnuPGShellBackup content construction
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellBackup::ShowToolTips() {
	return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellBackup::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellBackup bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
////@end wxGnuPGShellBackup bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellBackup::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellBackup icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
////@end wxGnuPGShellBackup icon retrieval
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BACKUP_BROWSE
 */

void wxGnuPGShellBackup::OnBackupBrowseClick(wxCommandEvent &event) {
	long style =
			m_importKey ?
					wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE | wxFD_OPEN :
					wxFD_SAVE | wxFD_OVERWRITE_PROMPT;
	wxString name = m_keyName->GetLabel();
	name.Replace(wxString(wxT("<")), wxString(wxT("(")));
	name.Replace(wxString(wxT(">")), wxString(wxT(")")));

	name = m_importKey ?
			wxString(wxEmptyString) :
			wxString::Format(wxT("%s_%s.asc"), m_keyId->GetLabel().GetData(),
					name.GetData());

	wxFileDialog *fd =
			new wxFileDialog(this, _("Select file"), wxEmptyString, name,
					_(
							"ASC files (*.asc)|*.asc|PGP files (*.pgp)|*.pgp)|All files (*.*)|*.*"),
					style);

	if (fd->ShowModal() == wxID_OK) {
		if (m_importKey) {
			fd->GetPaths(m_paths);
		} // fill list in import case only
		m_fileName->SetValue(fd->GetPath()); // show first file name in edit
	}
	wxDELETE(fd);
}

