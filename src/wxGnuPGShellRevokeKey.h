/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellRevokeKey.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     20/09/2007 13:45:20
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLREVOKEKEY_H_
#define _WXGNUPGSHELLREVOKEKEY_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxGnuPGShellRevokeKey.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/statline.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLREVOKEKEY 10061
#define ID_REVOKEKEY_IDS 10079
#define ID_REVOKEKEY_NAMES 10128
#define ID_TEXTCTRL 10001
#define ID_BUTTON 10002
#define ID_REASON_RADIOBOX 10000
#define ID_OWN_REASON_TEXT 10129
#define ID_REVOKEKEY_PASS 10130
#define SYMBOL_WXGNUPGSHELLREVOKEKEY_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_WXGNUPGSHELLREVOKEKEY_TITLE _("Revoke key")
#define SYMBOL_WXGNUPGSHELLREVOKEKEY_IDNAME ID_WXGNUPGSHELLREVOKEKEY
#define SYMBOL_WXGNUPGSHELLREVOKEKEY_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLREVOKEKEY_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellRevokeKey class declaration
 */

class wxGnuPGShellRevokeKey: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellRevokeKey )
    DECLARE_EVENT_TABLE()

    bool m_goodPath;

public:
    /// Constructors
    wxGnuPGShellRevokeKey();
    wxGnuPGShellRevokeKey( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLREVOKEKEY_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLREVOKEKEY_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLREVOKEKEY_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLREVOKEKEY_SIZE, long style = SYMBOL_WXGNUPGSHELLREVOKEKEY_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLREVOKEKEY_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLREVOKEKEY_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLREVOKEKEY_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLREVOKEKEY_SIZE, long style = SYMBOL_WXGNUPGSHELLREVOKEKEY_STYLE );

    /// Destructor
    ~wxGnuPGShellRevokeKey();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellRevokeKey event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnBUTTONClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for wxID_OK
    void OnOKUpdate( wxUpdateUIEvent& event );

////@end wxGnuPGShellRevokeKey event handler declarations

////@begin wxGnuPGShellRevokeKey member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellRevokeKey member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellRevokeKey member variables
    wxTextCtrl* m_ids;
    wxTextCtrl* m_names;
    wxTextCtrl* m_outputFile;
    wxRadioBox* m_reasonRadio;
    wxTextCtrl* m_ownReason;
    wxTextCtrl* m_passphrase;
////@end wxGnuPGShellRevokeKey member variables
};

#endif
    // _WXGNUPGSHELLREVOKEKEY_H_
