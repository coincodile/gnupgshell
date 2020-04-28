/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshelltrust.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:50:08
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshelltrust.h"
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

#include "wxgnupgshelltrust.h"
#include "wxGnuPGKey.h"

////@begin XPM images
////@end XPM images

/*!
 * wxGnuPGShellTrust type definition
 */

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellTrust, wxDialog)

/*!
 * wxGnuPGShellTrust event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellTrust, wxDialog )

////@begin wxGnuPGShellTrust event table entries
////@end wxGnuPGShellTrust event table entries

END_EVENT_TABLE()

/*!
 * wxGnuPGShellTrust constructors
 */

wxGnuPGShellTrust::wxGnuPGShellTrust() {
	Init();
}

wxGnuPGShellTrust::wxGnuPGShellTrust(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellTrust creator
 */

bool wxGnuPGShellTrust::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellTrust creation
	SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
	wxDialog::Create(parent, id, caption, pos, size, style);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
////@end wxGnuPGShellTrust creation
	return true;
}

/*!
 * wxGnuPGShellTrust destructor
 */

wxGnuPGShellTrust::~wxGnuPGShellTrust() {
////@begin wxGnuPGShellTrust destruction
////@end wxGnuPGShellTrust destruction
}

/*!
 * Member initialisation
 */

void wxGnuPGShellTrust::Init() {
////@begin wxGnuPGShellTrust member initialisation
	m_trustName = NULL;
	m_trustKeyID = NULL;
	m_isTrustUnknown = NULL;
	m_isTrustNever = NULL;
	m_isTrustMarginal = NULL;
	m_isTrustFull = NULL;
	m_isTrustUltimate = NULL;
////@end wxGnuPGShellTrust member initialisation
}

/*!
 * Control creation for wxGnuPGShellTrust
 */

void wxGnuPGShellTrust::CreateControls() {
////@begin wxGnuPGShellTrust content construction
	wxGnuPGShellTrust *itemDialog1 = this;

	wxBoxSizer *itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	itemDialog1->SetSizer(itemBoxSizer2);

	wxBoxSizer *itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW | wxALL, 0);

	wxStaticText *itemStaticText4 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("User name:"), wxDefaultPosition, wxSize(60, -1), 0);
	itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_trustName = new wxStaticText(itemDialog1, ID_TRUST_NAME, _("Static text"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer3->Add(m_trustName, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer6, 0, wxGROW | wxALL, 0);

	wxStaticText *itemStaticText7 = new wxStaticText(itemDialog1, wxID_STATIC,
			_("Key ID:"), wxDefaultPosition, wxSize(60, -1), 0);
	itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_trustKeyID = new wxStaticText(itemDialog1, ID_TRUST_ID, _("Static text"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer6->Add(m_trustKeyID, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticBox *itemStaticBoxSizer9Static = new wxStaticBox(itemDialog1,
			wxID_ANY, _("Owner Trust"));
	wxStaticBoxSizer *itemStaticBoxSizer9 = new wxStaticBoxSizer(
			itemStaticBoxSizer9Static, wxVERTICAL);
	itemBoxSizer2->Add(itemStaticBoxSizer9, 0, wxGROW | wxALL, 5);

	m_isTrustUnknown = new wxRadioButton(itemDialog1, ID_RADIO_UNKNOWN,
			_("&Unknown"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
	m_isTrustUnknown->SetValue(true);
	itemStaticBoxSizer9->Add(m_isTrustUnknown, 1, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText11 =
			new wxStaticText(itemDialog1, wxID_STATIC,
					_(
							"You don't know how much to trust this\nuser to verify other people's keys."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer9->Add(itemStaticText11, 0, wxALIGN_LEFT | wxALL, 5);

	m_isTrustNever = new wxRadioButton(itemDialog1, ID_RADIO_NEVER, _("&Never"),
			wxDefaultPosition, wxDefaultSize, 0);
	m_isTrustNever->SetValue(false);
	itemStaticBoxSizer9->Add(m_isTrustNever, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText13 =
			new wxStaticText(itemDialog1, wxID_STATIC,
					_(
							"You don't trust this user at all to verify\nthe validity of other people's keys at all."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer9->Add(itemStaticText13, 0, wxALIGN_LEFT | wxALL, 5);

	m_isTrustMarginal = new wxRadioButton(itemDialog1, ID_RADIO_MARGINAL,
			_("&Marginal"), wxDefaultPosition, wxDefaultSize, 0);
	m_isTrustMarginal->SetValue(false);
	itemStaticBoxSizer9->Add(m_isTrustMarginal, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText15 =
			new wxStaticText(itemDialog1, wxID_STATIC,
					_(
							"You don't trust this user's ability to verify the validity of other\npeople's keys enough to  consider keys valid based on his/her\nsole word.\nHowever, provided this user's key is valid, you will consider a\nkey signed by this user valid if it is also signed by at least other\ntwo marginally trusted users with valid keys."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer9->Add(itemStaticText15, 0, wxALIGN_LEFT | wxALL, 5);

	m_isTrustFull = new wxRadioButton(itemDialog1, ID_RADIO_FULL, _("&Full"),
			wxDefaultPosition, wxDefaultSize, 0);
	m_isTrustFull->SetValue(false);
	itemStaticBoxSizer9->Add(m_isTrustFull, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText17 =
			new wxStaticText(itemDialog1, wxID_STATIC,
					_(
							"You trust this user's ability to verify the validity of other\npeople's keys so much, that you'll consider valid any key\nsigned by him/her, provided this user's key is valid."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer9->Add(itemStaticText17, 0, wxALIGN_LEFT | wxALL, 5);

	m_isTrustUltimate = new wxRadioButton(itemDialog1, ID_RADIO_ULTIMATE,
			_("Ul&timate"), wxDefaultPosition, wxDefaultSize, 0);
	m_isTrustUltimate->SetValue(false);
	itemStaticBoxSizer9->Add(m_isTrustUltimate, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText19 =
			new wxStaticText(itemDialog1, wxID_STATIC,
					_(
							"You consider this key valid, and trust the user so much that\nyou will consider any key signed by him/her fully valid."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer9->Add(itemStaticText19, 0, wxALIGN_LEFT | wxALL, 5);

	itemStaticBoxSizer9->Add(5, 5, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText21 =
			new wxStaticText(itemDialog1, wxID_STATIC,
					_(
							"(Warning: This is intended to be used for keys you own. Don't \nuse it with other people's key unless you really know what you\nare doing)"),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticBoxSizer9->Add(itemStaticText21, 0, wxALIGN_LEFT | wxALL, 5);

	wxBoxSizer *itemBoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer22, 0, wxALIGN_RIGHT | wxALL, 0);

	wxStdDialogButtonSizer *itemStdDialogButtonSizer23 =
			new wxStdDialogButtonSizer;

	itemBoxSizer22->Add(itemStdDialogButtonSizer23, 0,
			wxALIGN_CENTER_VERTICAL | wxALL, 5);
	wxButton *itemButton24 = new wxButton(itemDialog1, wxID_OK, _("&OK"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer23->AddButton(itemButton24);

	wxButton *itemButton25 = new wxButton(itemDialog1, wxID_CANCEL,
			_("&Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	itemStdDialogButtonSizer23->AddButton(itemButton25);

	itemStdDialogButtonSizer23->Realize();

////@end wxGnuPGShellTrust content construction
	SetTrust();
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellTrust::ShowToolTips() {
	return true;
}

void wxGnuPGShellTrust::SetTrust() {
	switch (m_trust) {
	case TRUST_FULLY:
		m_isTrustFull->SetValue(true);
		break;
	case TRUST_ULTIMATELY:
		m_isTrustUltimate->SetValue(true);
		break;
	case TRUST_MARGINALLY:
		m_isTrustMarginal->SetValue(true);
		break;
	case TRUST_DO_NOT_TRUST:
		m_isTrustNever->SetValue(true);
		break;
	case TRUST_DONT_KNOW:
	default:
		m_isTrustUnknown->SetValue(true);
	}
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellTrust::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellTrust bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
////@end wxGnuPGShellTrust bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellTrust::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellTrust icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
////@end wxGnuPGShellTrust icon retrieval
}

int wxGnuPGShellTrust::GetTrust(void) {
	if (m_isTrustFull->GetValue()) {
		return TRUST_FULLY;
	}
	if (m_isTrustUltimate->GetValue()) {
		return TRUST_ULTIMATELY;
	}
	if (m_isTrustMarginal->GetValue()) {
		return TRUST_MARGINALLY;
	}
	if (m_isTrustNever->GetValue()) {
		return TRUST_DO_NOT_TRUST;
	}
	if (m_isTrustUnknown->GetValue()) {
		return TRUST_DONT_KNOW;
	}

	return TRUST_DONT_KNOW;
}
