/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellImportKey.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     12/09/2007 10:34:47
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLIMPORTKEY_H_
#define _WXGNUPGSHELLIMPORTKEY_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxGnuPGShellImportKey.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/statline.h"
#include "wx/listctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxListView;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLIMPORTKEY 10102
#define ID_IMPORTKEY_SERVER 10103
#define ID_IMPORTKEY_KEY_ID 10110
#define ID_IMPORTKEY_KEY_NAME 10119
#define ID_IMPORTKEY_FIND 10001
#define ID_IMPORTKEY_CLEAR 10123
#define ID_IMPORTKEY_RESULT_LIST 10000
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_TITLE _("Import Key")
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_IDNAME ID_WXGNUPGSHELLIMPORTKEY
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellImportKey class declaration
 */

class wxGnuPGShellImportKey: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellImportKey )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellImportKey();
    wxGnuPGShellImportKey( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLIMPORTKEY_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLIMPORTKEY_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLIMPORTKEY_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLIMPORTKEY_SIZE, long style = SYMBOL_WXGNUPGSHELLIMPORTKEY_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLIMPORTKEY_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLIMPORTKEY_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLIMPORTKEY_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLIMPORTKEY_SIZE, long style = SYMBOL_WXGNUPGSHELLIMPORTKEY_STYLE );

    /// Destructor
    ~wxGnuPGShellImportKey();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();
    void FillColumns();

////@begin wxGnuPGShellImportKey event handler declarations

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_IMPORTKEY_KEY_ID
    void OnIMPORTKEYKEYIDUpdated( wxCommandEvent& event );

    /// wxEVT_LEFT_DOWN event handler for ID_IMPORTKEY_KEY_ID
    void OnLeftDownImportKey( wxMouseEvent& event );

    /// wxEVT_SET_FOCUS event handler for ID_IMPORTKEY_KEY_ID
    void OnKeyIdSetFocus( wxFocusEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_IMPORTKEY_KEY_NAME
    void OnIMPORTKEYKEYNAMEUpdated( wxCommandEvent& event );

    /// wxEVT_LEFT_DOWN event handler for ID_IMPORTKEY_KEY_NAME
    void OnLeftDownImportName( wxMouseEvent& event );

    /// wxEVT_SET_FOCUS event handler for ID_IMPORTKEY_KEY_NAME
    void OnKeyNameSetFocus( wxFocusEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMPORTKEY_FIND
    void OnIMPORTKEYFINDClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_IMPORTKEY_FIND
    void OnIMPORTKEYFINDUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMPORTKEY_CLEAR
    void OnIMPORTKEYCLEARClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for wxID_OK
    void OnOKUpdate( wxUpdateUIEvent& event );

////@end wxGnuPGShellImportKey event handler declarations

////@begin wxGnuPGShellImportKey member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellImportKey member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellImportKey member variables
    wxChoice* m_importServer;
    wxTextCtrl* m_keyIdText;
    wxTextCtrl* m_keyNameText;
    wxListView* m_resultKeyList;
////@end wxGnuPGShellImportKey member variables
};

#endif
    // _WXGNUPGSHELLIMPORTKEY_H_
