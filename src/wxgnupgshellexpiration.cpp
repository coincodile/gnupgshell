/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellexpiration.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 16:41:15
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellexpiration.h"
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

#include "wxgnupgshellexpiration.h"

////@begin XPM images
////@end XPM images


/*!
 * wxGnuPGShellExpiration type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellExpiration, wxDialog )


/*!
 * wxGnuPGShellExpiration event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellExpiration, wxDialog )

////@begin wxGnuPGShellExpiration event table entries
    EVT_RADIOBOX( ID_EXPIRATION_MODE, wxGnuPGShellExpiration::OnExpirationModeSelected )

////@end wxGnuPGShellExpiration event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellExpiration constructors
 */

wxGnuPGShellExpiration::wxGnuPGShellExpiration()
{
    Init();
}

wxGnuPGShellExpiration::wxGnuPGShellExpiration( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellExpiration creator
 */

bool wxGnuPGShellExpiration::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellExpiration creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellExpiration creation
    return true;
}


/*!
 * wxGnuPGShellExpiration destructor
 */

wxGnuPGShellExpiration::~wxGnuPGShellExpiration()
{
////@begin wxGnuPGShellExpiration destruction
////@end wxGnuPGShellExpiration destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellExpiration::Init()
{
////@begin wxGnuPGShellExpiration member initialisation
    m_expirationMode = NULL;
    m_calendarCtrl = NULL;
////@end wxGnuPGShellExpiration member initialisation
}


/*!
 * Control creation for wxGnuPGShellExpiration
 */

void wxGnuPGShellExpiration::CreateControls()
{    
////@begin wxGnuPGShellExpiration content construction
    wxGnuPGShellExpiration* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxArrayString m_expirationModeStrings;
    m_expirationModeStrings.Add(_("&never expire"));
    m_expirationModeStrings.Add(_("&expire on:"));
    m_expirationMode = new wxRadioBox( itemDialog1, ID_EXPIRATION_MODE, _T(""), wxDefaultPosition, wxDefaultSize, m_expirationModeStrings, 1, wxRA_SPECIFY_COLS );
    m_expirationMode->SetSelection(0);
    itemBoxSizer2->Add(m_expirationMode, 0, wxGROW|wxALL, 5);

    m_calendarCtrl = new wxCalendarCtrl( itemDialog1, ID_EXPIRATION_CALENDAR, wxDateTime(), wxDefaultPosition, wxDefaultSize, wxCAL_SUNDAY_FIRST|wxSUNKEN_BORDER );
    m_calendarCtrl->Enable(false);
    itemBoxSizer2->Add(m_calendarCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer5 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    wxButton* itemButton6 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer5->AddButton(itemButton6);

    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer5->AddButton(itemButton7);

    itemStdDialogButtonSizer5->Realize();

////@end wxGnuPGShellExpiration content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellExpiration::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellExpiration::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellExpiration bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellExpiration bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellExpiration::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellExpiration icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellExpiration icon retrieval
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_EXPIRATION_MODE
 */

void wxGnuPGShellExpiration::OnExpirationModeSelected( wxCommandEvent& event )
{
    if (m_expirationMode->GetSelection() == 0) {
        m_calendarCtrl->Disable();
    } else {
        m_calendarCtrl->Enable();
    }
}

