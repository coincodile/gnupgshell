/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellAboutDialog.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     11/08/2007 00:15:33
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxGnuPGShellAboutDialog.h"
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
#include "wxGnuPGShellAboutDialog.h"
#include "app_resources.h"
////@end includes

////@begin XPM images
#include "wxGnuPGShellAboutHeader.xpm"
#include "powered_by_wxwidgets_88x31.xpm"
////@end XPM images

/*!
 * wxGnuPGShellAboutDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellAboutDialog, wxDialog)

/*!
 * wxGnuPGShellAboutDialog event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellAboutDialog, wxDialog )

////@begin wxGnuPGShellAboutDialog event table entries
////@end wxGnuPGShellAboutDialog event table entries

END_EVENT_TABLE()

/*!
 * wxGnuPGShellAboutDialog constructors
 */

wxGnuPGShellAboutDialog::wxGnuPGShellAboutDialog() {
	Init();
}

wxGnuPGShellAboutDialog::wxGnuPGShellAboutDialog(wxWindow *parent,
		wxWindowID id, const wxString &caption, const wxPoint &pos,
		const wxSize &size, long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellAboutDialog creator
 */

bool wxGnuPGShellAboutDialog::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellAboutDialog creation
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
	wxDialog::Create(parent, id, caption, pos, size, style);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
////@end wxGnuPGShellAboutDialog creation
	return true;
}

/*!
 * wxGnuPGShellAboutDialog destructor
 */

wxGnuPGShellAboutDialog::~wxGnuPGShellAboutDialog() {
////@begin wxGnuPGShellAboutDialog destruction
////@end wxGnuPGShellAboutDialog destruction
}

/*!
 * Member initialisation 
 */

void wxGnuPGShellAboutDialog::Init() {
////@begin wxGnuPGShellAboutDialog member initialisation
	m_addrLink = NULL;
////@end wxGnuPGShellAboutDialog member initialisation
}

/*!
 * Control creation for wxGnuPGShellAboutDialog
 */

void wxGnuPGShellAboutDialog::CreateControls() {
////@begin wxGnuPGShellAboutDialog content construction
	wxGnuPGShellAboutDialog *itemDialog1 = this;

	wxBoxSizer *itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	itemDialog1->SetSizer(itemBoxSizer2);

	wxStaticBitmap *itemStaticBitmap3 = new wxStaticBitmap(itemDialog1,
			wxID_STATIC,
			itemDialog1->GetBitmapResource(wxT("wxGnuPGShellAboutHeader.xpm")),
			wxDefaultPosition, wxSize(250, 140), 0);
	itemBoxSizer2->Add(itemStaticBitmap3, 0, wxALIGN_CENTER_HORIZONTAL | wxALL,
			5);

	wxStaticText *itemStaticText4 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("GnuPG Shell - v1.0"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText4->SetFont(
			wxFont(8, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL,
					wxFONTWEIGHT_BOLD, false, FONT_NAME_TAHOMA));
	itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_CENTER_HORIZONTAL | wxALL,
			5);

	wxStaticBox *itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Project Team"));
	wxStaticBoxSizer *itemStaticBoxSizer5 = new wxStaticBoxSizer(
			itemStaticBoxSizer5Static, wxVERTICAL);
	itemBoxSizer2->Add(itemStaticBoxSizer5, 0, wxGROW | wxALL, 5);

	wxTextCtrl *itemTextCtrl6 =
			new wxTextCtrl(itemDialog1, ID_ABOUT_VENDOR_TEXTCTRL,
					_(
							"Volodymir (T-Rex) Tryapichko \n    http://wxwidgets.info\nAndrew S. Bulavinov \n   A.Bulavinov@gmail.com\nWill Spencer\n   will.spencer@tech-faq.com\n"),
					wxDefaultPosition, wxSize(-1, 100),
					wxTE_MULTILINE | wxTE_READONLY);
	itemStaticBoxSizer5->Add(itemTextCtrl6, 1, wxGROW | wxALL, 5);

	m_addrLink = new wxHyperlinkCtrl(itemDialog1, ID_HYPER_ADDR,
			_("Project Homepage"),
			_T("http://www.tech-faq.com/gnupg-shell.shtml"), wxDefaultPosition,
			wxDefaultSize, wxHL_DEFAULT_STYLE);
	itemBoxSizer2->Add(m_addrLink, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	wxStaticText *itemStaticText8 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Contact e-mail:"), wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer2->Add(itemStaticText8, 0,
			wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT | wxTOP, 5);

	wxHyperlinkCtrl *itemHyperlinkCtrl9 = new wxHyperlinkCtrl(itemDialog1,
	ID_HYPERLINKCTRL1, _("gnupg-shell@tech-faq.com"),
			_T("mailto:gnupg-shell@tech-faq.com"), wxDefaultPosition,
			wxDefaultSize, wxHL_DEFAULT_STYLE);
	itemBoxSizer2->Add(itemHyperlinkCtrl9, 0, wxALIGN_CENTER_HORIZONTAL | wxALL,
			5);

	wxStaticBitmap *itemStaticBitmap10 = new wxStaticBitmap(itemDialog1,
			wxID_STATIC,
			itemDialog1->GetBitmapResource(
					wxT("powered_by_wxwidgets_88x31.xpm")), wxDefaultPosition,
			wxSize(88, 31), 0);
	itemBoxSizer2->Add(itemStaticBitmap10, 0, wxALIGN_CENTER_HORIZONTAL | wxALL,
			5);

	wxButton *itemButton11 = new wxButton(itemDialog1, wxID_OK, _("&OK"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer2->Add(itemButton11, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

////@end wxGnuPGShellAboutDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellAboutDialog::ShowToolTips() {
	return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellAboutDialog::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellAboutDialog bitmap retrieval
	wxUnusedVar(name);
	if (name == _T("wxGnuPGShellAboutHeader.xpm")) {
		wxBitmap bitmap(wxGnuPGShellAboutHeader_xpm);
		return bitmap;
	} else if (name == _T("powered_by_wxwidgets_88x31.xpm")) {
		wxBitmap bitmap(powered_by_wxwidgets_88x31_xpm);
		return bitmap;
	}
	return wxNullBitmap;
////@end wxGnuPGShellAboutDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellAboutDialog::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellAboutDialog icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
////@end wxGnuPGShellAboutDialog icon retrieval
}
