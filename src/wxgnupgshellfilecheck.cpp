/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellfilecheck.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 17:34:14
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellfilecheck.h"
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

#include "wxgnupgshellfilecheck.h"

////@begin XPM images
////@end XPM images


/*!
 * wxGnuPGShellFileCheck type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellFileCheck, wxDialog )


/*!
 * wxGnuPGShellFileCheck event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellFileCheck, wxDialog )

////@begin wxGnuPGShellFileCheck event table entries
////@end wxGnuPGShellFileCheck event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellFileCheck constructors
 */

wxGnuPGShellFileCheck::wxGnuPGShellFileCheck()
{
    Init();
}

wxGnuPGShellFileCheck::wxGnuPGShellFileCheck( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellFileCheck creator
 */

bool wxGnuPGShellFileCheck::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellFileCheck creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellFileCheck creation
    return true;
}


/*!
 * wxGnuPGShellFileCheck destructor
 */

wxGnuPGShellFileCheck::~wxGnuPGShellFileCheck()
{
////@begin wxGnuPGShellFileCheck destruction
////@end wxGnuPGShellFileCheck destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellFileCheck::Init()
{
////@begin wxGnuPGShellFileCheck member initialisation
    m_filesTabsCtrl = NULL;
////@end wxGnuPGShellFileCheck member initialisation
}


/*!
 * Control creation for wxGnuPGShellFileCheck
 */

void wxGnuPGShellFileCheck::CreateControls()
{    
////@begin wxGnuPGShellFileCheck content construction
    wxGnuPGShellFileCheck* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_filesTabsCtrl = new wxNotebook( itemDialog1, ID_FILECHECK_TABBAR, wxDefaultPosition, wxSize(300, 100), wxBK_DEFAULT );

    itemBoxSizer2->Add(m_filesTabsCtrl, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer4, 0, wxGROW|wxALL, 0);

    itemBoxSizer4->Add(100, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton6 = new wxButton( itemDialog1, ID_FILECHECK_CLOSE, _("&Close"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemButton6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    // Connect events and objects
    itemButton6->Connect(ID_FILECHECK_CLOSE, wxEVT_LEFT_UP, wxMouseEventHandler(wxGnuPGShellFileCheck::OnLeftUp), NULL, this);
////@end wxGnuPGShellFileCheck content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellFileCheck::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellFileCheck::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellFileCheck bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellFileCheck bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellFileCheck::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellFileCheck icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellFileCheck icon retrieval
}


/*!
 * wxEVT_LEFT_UP event handler for ID_FILECHECK_CLOSE
 */

void wxGnuPGShellFileCheck::OnLeftUp( wxMouseEvent& event )
{
////@begin wxEVT_LEFT_UP event handler for ID_FILECHECK_CLOSE in wxGnuPGShellFileCheck.
    // Before editing this code, remove the block markers.
////@end wxEVT_LEFT_UP event handler for ID_FILECHECK_CLOSE in wxGnuPGShellFileCheck. 
}

