/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshelladvkeysettings.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     10/08/2007 12:18:44
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshelladvkeysettings.h"
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

#include "wxgnupgshelladvkeysettings.h"

////@begin XPM images
////@end XPM images


/*!
 * wxGnuPGShellAdvKeySettings type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellAdvKeySettings, wxDialog )


/*!
 * wxGnuPGShellAdvKeySettings event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellAdvKeySettings, wxDialog )

////@begin wxGnuPGShellAdvKeySettings event table entries
    EVT_RADIOBUTTON( ID_ADVANCEDKEY_RADIO_DATE, wxGnuPGShellAdvKeySettings::OnAdvancedkeyRadioDateSelected )

    EVT_UPDATE_UI( ID_ADVANCEDKEY_EXPIRATION_DATE, wxGnuPGShellAdvKeySettings::OnAdvancedkeyExpirationDateUpdate )

    EVT_BUTTON( wxID_OK, wxGnuPGShellAdvKeySettings::OnOkClick )

////@end wxGnuPGShellAdvKeySettings event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellAdvKeySettings constructors
 */

wxGnuPGShellAdvKeySettings::wxGnuPGShellAdvKeySettings()
{
    Init();
}

wxGnuPGShellAdvKeySettings::wxGnuPGShellAdvKeySettings( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellAdvKeySettings creator
 */

bool wxGnuPGShellAdvKeySettings::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellAdvKeySettings creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellAdvKeySettings creation
    return true;
}


/*!
 * wxGnuPGShellAdvKeySettings destructor
 */

wxGnuPGShellAdvKeySettings::~wxGnuPGShellAdvKeySettings()
{
////@begin wxGnuPGShellAdvKeySettings destruction
////@end wxGnuPGShellAdvKeySettings destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellAdvKeySettings::Init()
{
////@begin wxGnuPGShellAdvKeySettings member initialisation
    m_keyType = NULL;
    m_generateSeparateFlag = NULL;
    m_keySize = NULL;
    m_expireNever = NULL;
    m_expirationDate = NULL;
////@end wxGnuPGShellAdvKeySettings member initialisation
}


/*!
 * Control creation for wxGnuPGShellAdvKeySettings
 */

void wxGnuPGShellAdvKeySettings::CreateControls()
{    
////@begin wxGnuPGShellAdvKeySettings content construction
    wxGnuPGShellAdvKeySettings* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    itemBoxSizer3->Add(50, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText5 = new wxStaticText( itemDialog1, wxID_STATIC, _("Key &type:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer6, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    wxArrayString m_keyTypeStrings;
    m_keyType = new wxChoice( itemDialog1, ID_ADVANCEDKEY_KEYTYPE, wxDefaultPosition, wxDefaultSize, m_keyTypeStrings, 0 );
    itemBoxSizer6->Add(m_keyType, 0, wxGROW|wxALL, 5);

    m_generateSeparateFlag = new wxCheckBox( itemDialog1, ID_ADVANCEDKEY_GEN_SEPARATE, _("Generate separate signing subkey"), wxDefaultPosition, wxDefaultSize, 0 );
    m_generateSeparateFlag->SetValue(false);
    itemBoxSizer6->Add(m_generateSeparateFlag, 0, wxALIGN_LEFT|wxRIGHT|wxTOP, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer9, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemBoxSizer9->Add(54, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemDialog1, wxID_STATIC, _("Key &size:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer9->Add(itemStaticText11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_keySize = new wxTextCtrl( itemDialog1, ID_ADVANCEDKEY_KEYSIZE, _("2048"), wxDefaultPosition, wxSize(50, -1), 0 );
    itemBoxSizer9->Add(m_keySize, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( itemDialog1, wxID_STATIC, _("1024-4096"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer9->Add(itemStaticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer14, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    itemBoxSizer14->Add(45, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemDialog1, wxID_STATIC, _("E&xpiration:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer14->Add(itemStaticText16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_expireNever = new wxRadioButton( itemDialog1, ID_ADVANCEDKEY_RADIO_NEVER, _("ne&ver"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    m_expireNever->SetValue(true);
    itemBoxSizer14->Add(m_expireNever, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    wxRadioButton* itemRadioButton18 = new wxRadioButton( itemDialog1, ID_ADVANCEDKEY_RADIO_DATE, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton18->SetValue(false);
    itemBoxSizer14->Add(itemRadioButton18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_expirationDate = new wxDatePickerCtrl( itemDialog1, ID_ADVANCEDKEY_EXPIRATION_DATE, wxDateTime(), wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
    itemBoxSizer14->Add(m_expirationDate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer20 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer20, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* itemButton21 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer20->AddButton(itemButton21);

    wxButton* itemButton22 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer20->AddButton(itemButton22);

    itemStdDialogButtonSizer20->Realize();

////@end wxGnuPGShellAdvKeySettings content construction
    m_keyType->Append(wxT("RSA"));
    m_keyType->Append(wxT("DSA"));
    m_keyType->Select(0);
}


wxString wxGnuPGShellAdvKeySettings::GetExpirationString()
{
    if (m_expireNever->GetValue()) {
        return wxT("0");
    } else {
        return m_expirationDate->GetValue().FormatISODate();
    }
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellAdvKeySettings::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellAdvKeySettings::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellAdvKeySettings bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellAdvKeySettings bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellAdvKeySettings::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellAdvKeySettings icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellAdvKeySettings icon retrieval
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_ADVANCEDKEY_RADIO_DATE
 */

void wxGnuPGShellAdvKeySettings::OnAdvancedkeyRadioDateSelected( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_ADVANCEDKEY_RADIO_DATE in wxGnuPGShellAdvKeySettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_ADVANCEDKEY_RADIO_DATE in wxGnuPGShellAdvKeySettings. 
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void wxGnuPGShellAdvKeySettings::OnOkClick( wxCommandEvent& event )
{
    if (!m_keySize->GetValue().IsNumber()) {

        wxMessageBox(_("Key length must be a number"), _("Error"), wxOK);
        m_keySize->SetValue(wxT("2048"));
        return;
    } else {
        long val = 0;
        m_keySize->GetValue().ToLong(&val);
        if (val < 1024 && val > 4096) {
            wxMessageBox(_("Key length must be a number in range 1024-4096."), _("Error"), wxOK);
            m_keySize->SetValue(wxT("2048"));
            return;
        }
    }
    event.Skip();
}


/*!
 * wxEVT_UPDATE_UI event handler for ID_ADVANCEDKEY_EXPIRATION_DATE
 */

void wxGnuPGShellAdvKeySettings::OnAdvancedkeyExpirationDateUpdate( wxUpdateUIEvent& event )
{
    event.Enable(!m_expireNever->GetValue());
}

