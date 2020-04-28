/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellpasskey.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 17:18:28
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellpasskey.h"
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

#include "wxgnupgshellpasskey.h"

////@begin XPM images
#include "wxwin32x32.xpm"
////@end XPM images


/*!
 * wxGnuPGShellPassKey type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellPassKey, wxDialog )


/*!
 * wxGnuPGShellPassKey event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellPassKey, wxDialog )

////@begin wxGnuPGShellPassKey event table entries
    EVT_BUTTON( wxID_OK, wxGnuPGShellPassKey::OnOkClick )
    EVT_UPDATE_UI( wxID_OK, wxGnuPGShellPassKey::OnOkUpdate )

////@end wxGnuPGShellPassKey event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellPassKey constructors
 */

wxGnuPGShellPassKey::wxGnuPGShellPassKey()
{
    Init();
}

wxGnuPGShellPassKey::wxGnuPGShellPassKey( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellPassKey creator
 */

bool wxGnuPGShellPassKey::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellPassKey creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("wxwin32x32.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellPassKey creation
    return true;
}


/*!
 * wxGnuPGShellPassKey destructor
 */

wxGnuPGShellPassKey::~wxGnuPGShellPassKey()
{
////@begin wxGnuPGShellPassKey destruction
////@end wxGnuPGShellPassKey destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellPassKey::Init()
{
////@begin wxGnuPGShellPassKey member initialisation
    m_userName = NULL;
    m_keyID = NULL;
    m_currPass = NULL;
    m_passKey = NULL;
    m_passConfirm = NULL;
////@end wxGnuPGShellPassKey member initialisation
}


/*!
 * Control creation for wxGnuPGShellPassKey
 */

void wxGnuPGShellPassKey::CreateControls()
{    
////@begin wxGnuPGShellPassKey content construction
    wxGnuPGShellPassKey* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 5);

    wxStaticBitmap* itemStaticBitmap4 = new wxStaticBitmap( itemDialog1, wxID_STATIC, wxNullBitmap, wxDefaultPosition, wxSize(48, 48), 0 );
    itemBoxSizer3->Add(itemStaticBitmap4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer5, 1, wxALIGN_BOTTOM|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("Please enter passkey for the folowing key:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText6, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer7, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1, wxID_STATIC, _("User name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(itemStaticText8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_userName = new wxStaticText( itemDialog1, ID_PASSKEY_USERNAME, _("<user_name>"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(m_userName, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxBoxSizer* itemBoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer10, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText11 = new wxStaticText( itemDialog1, wxID_STATIC, _("Key ID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer10->Add(itemStaticText11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_keyID = new wxStaticText( itemDialog1, ID_PASSKEY_KEYID, _("<key_id>"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer10->Add(m_keyID, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( itemDialog1, wxID_STATIC, _("Current passkey:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText13, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_currPass = new wxTextCtrl( itemDialog1, ID_PASSKEY_CURRENT_PASS, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    itemBoxSizer5->Add(m_currPass, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText15 = new wxStaticText( itemDialog1, wxID_STATIC, _("New passkey:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText15, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_passKey = new wxTextCtrl( itemDialog1, ID_PASSKEY_PASS, _T(""), wxDefaultPosition, wxSize(300, -1), wxTE_PASSWORD );
    itemBoxSizer5->Add(m_passKey, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText17 = new wxStaticText( itemDialog1, wxID_STATIC, _("Confirm passkey:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText17, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_passConfirm = new wxTextCtrl( itemDialog1, ID_PASSKEY_CONFIRM, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    itemBoxSizer5->Add(m_passConfirm, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine19 = new wxStaticLine( itemDialog1, ID_STATICLINE2, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine19, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer20, 0, wxALIGN_RIGHT|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer21 = new wxStdDialogButtonSizer;

    itemBoxSizer20->Add(itemStdDialogButtonSizer21, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);
    wxButton* itemButton22 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton22->SetDefault();
    itemStdDialogButtonSizer21->AddButton(itemButton22);

    wxButton* itemButton23 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer21->AddButton(itemButton23);

    itemStdDialogButtonSizer21->Realize();

////@end wxGnuPGShellPassKey content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellPassKey::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellPassKey::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellPassKey bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellPassKey bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellPassKey::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellPassKey icon retrieval
    wxUnusedVar(name);
    if (name == _T("wxwin32x32.xpm"))
    {
        wxIcon icon(wxwin32x32_xpm);
        return icon;
    }
    return wxNullIcon;
////@end wxGnuPGShellPassKey icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void wxGnuPGShellPassKey::OnOkClick( wxCommandEvent& event )
{
    event.Skip();
}


/*!
 * wxEVT_UPDATE_UI event handler for wxID_OK
 */

void wxGnuPGShellPassKey::OnOkUpdate( wxUpdateUIEvent& event )
{
    event.Enable(m_passConfirm->GetValue() == m_passKey->GetValue());
}

