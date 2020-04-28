/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshelleditkey.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 17:04:48
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshelleditkey.h"
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

#include "wxgnupgshelleditkey.h"
#include "wxgnupgshellpasskey.h"
#include "wxgnupgshellexpiration.h"
#include "wxgnupgshellapp.h"

////@begin XPM images
#include "wxwin32x32.xpm"
////@end XPM images


/*!
 * wxGnuPGShellEditKey type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellEditKey, wxDialog )


/*!
 * wxGnuPGShellEditKey event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellEditKey, wxDialog )

////@begin wxGnuPGShellEditKey event table entries
    EVT_BUTTON( ID_EDITKEY_CHPASSKEY, wxGnuPGShellEditKey::OnEditkeyChpasskeyClick )

    EVT_BUTTON( ID_EDITKEY_CHEXPIRATION, wxGnuPGShellEditKey::OnEditkeyChexpirationClick )

////@end wxGnuPGShellEditKey event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellEditKey constructors
 */

wxGnuPGShellEditKey::wxGnuPGShellEditKey()
{
    Init();
}

wxGnuPGShellEditKey::wxGnuPGShellEditKey( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellEditKey creator
 */

bool wxGnuPGShellEditKey::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellEditKey creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("wxwin32x32.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellEditKey creation
    return true;
}


/*!
 * wxGnuPGShellEditKey destructor
 */

wxGnuPGShellEditKey::~wxGnuPGShellEditKey()
{
////@begin wxGnuPGShellEditKey destruction
////@end wxGnuPGShellEditKey destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellEditKey::Init()
{
////@begin wxGnuPGShellEditKey member initialisation
    m_userName = NULL;
    m_keyID = NULL;
    m_expiryDate = NULL;
////@end wxGnuPGShellEditKey member initialisation
}


/*!
 * Control creation for wxGnuPGShellEditKey
 */

void wxGnuPGShellEditKey::CreateControls()
{
////@begin wxGnuPGShellEditKey content construction
    wxGnuPGShellEditKey* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("User name:"), wxDefaultPosition, wxSize(60, -1), wxALIGN_RIGHT );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_userName = new wxStaticText( itemDialog1, ID_EDITKEY_USERNAME, _("<user_name>"), wxDefaultPosition, wxSize(300, -1), wxALIGN_LEFT );
    m_userName->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("wxNORMAL_FONT")));
    itemBoxSizer3->Add(m_userName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer6, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemDialog1, wxID_STATIC, _("Key ID:"), wxDefaultPosition, wxSize(60, -1), wxALIGN_RIGHT );
    itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_keyID = new wxStaticText( itemDialog1, ID_EDITKEY_KEYID, _("<key_id>"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
    m_keyID->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("wxNORMAL_FONT")));
    itemBoxSizer6->Add(m_keyID, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton9 = new wxButton( itemDialog1, ID_EDITKEY_CHPASSKEY, _("Change &passkey"), wxDefaultPosition, wxDefaultSize, 0 );
    if (ShowToolTips())
        itemButton9->SetToolTip(_("Change key passpharse. You must know the old one."));
    itemBoxSizer2->Add(itemButton9, 0, wxALIGN_RIGHT|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer10Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Expiration"));
    wxStaticBoxSizer* itemStaticBoxSizer10 = new wxStaticBoxSizer(itemStaticBoxSizer10Static, wxHORIZONTAL);
    itemBoxSizer2->Add(itemStaticBoxSizer10, 1, wxGROW|wxALL, 5);

    m_expiryDate = new wxStaticText( itemDialog1, ID_EDITKEY_EXPIRYDATE, _("<never expires>"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    m_expiryDate->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("wxNORMAL_FONT")));
    itemStaticBoxSizer10->Add(m_expiryDate, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton12 = new wxButton( itemDialog1, ID_EDITKEY_CHEXPIRATION, _("Change &expiration"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer10->Add(itemButton12, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    wxStaticLine* itemStaticLine13 = new wxStaticLine( itemDialog1, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine13, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer14, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton15 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer14->Add(itemButton15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

////@end wxGnuPGShellEditKey content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellEditKey::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellEditKey::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellEditKey bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellEditKey bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellEditKey::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellEditKey icon retrieval
    wxUnusedVar(name);
    if (name == _T("wxwin32x32.xpm"))
    {
        wxIcon icon(wxwin32x32_xpm);
        return icon;
    }
    return wxNullIcon;
////@end wxGnuPGShellEditKey icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EDITKEY_CHPASSKEY
 */

void wxGnuPGShellEditKey::OnEditkeyChpasskeyClick( wxCommandEvent& event )
{
    wxGnuPGShellPassKey *passDlg = new wxGnuPGShellPassKey(this);
    passDlg->m_userName->SetLabel(m_userName->GetLabel());
    passDlg->m_keyID->SetLabel(m_keyID->GetLabel());
    if (passDlg->ShowModal() == wxID_OK) {
        // need to change passphrase
        if (wxGetApp().ChangePass(m_keyID->GetLabel(), passDlg->m_currPass->GetValue(), passDlg->m_passKey->GetValue())) {
            wxMessageBox(_("Passkey was changed successfully!"), _("Success"));
        } else {
            wxMessageBox(_("Passkey was not changed due to errors. Look to the log windows for details."), _("Error"));
        }
    }
    passDlg->Destroy();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EDITKEY_CHEXPIRATION
 */

void wxGnuPGShellEditKey::OnEditkeyChexpirationClick( wxCommandEvent& event )
{
    wxGnuPGShellExpiration *expDlg = new wxGnuPGShellExpiration(this);
    if (expDlg->ShowModal() == wxID_OK) {
        wxString date = expDlg->m_expirationMode->GetSelection() > 0 ? expDlg->m_calendarCtrl->GetDate().FormatISODate() : wxT("0");
        m_expiryDate->SetLabel(expDlg->m_expirationMode->GetSelection() > 0 ? expDlg->m_calendarCtrl->GetDate().FormatISODate() : wxString(_("Never")));
        wxString pass = wxGetApp().GetPasswordForKey(m_keyID->GetLabel());
        if (pass != wxEmptyString) {
            if (wxGetApp().ChangeExpiration(m_keyID->GetLabel(), date, pass)) {
                wxMessageBox(_("Expiration date was changed successfully!"), _("Success"));
            } else {
                wxMessageBox(_("Expiration date was not changed due to errors. Look to the log windows for details."), _("Error"));
                wxGetApp().ClearPassCache();
            }
        }
    }
    expDlg->Destroy();
}
