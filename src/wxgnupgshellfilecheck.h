/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellfilecheck.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 17:34:14
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLFILECHECK_H_
#define _WXGNUPGSHELLFILECHECK_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellfilecheck.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLFILECHECK 10053
#define ID_FILECHECK_TABBAR 10054
#define ID_FILECHECK_CLOSE 10055
#define SYMBOL_WXGNUPGSHELLFILECHECK_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLFILECHECK_TITLE _("File Check")
#define SYMBOL_WXGNUPGSHELLFILECHECK_IDNAME ID_WXGNUPGSHELLFILECHECK
#define SYMBOL_WXGNUPGSHELLFILECHECK_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLFILECHECK_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellFileCheck class declaration
 */

class wxGnuPGShellFileCheck: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellFileCheck )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellFileCheck();
    wxGnuPGShellFileCheck( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLFILECHECK_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLFILECHECK_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLFILECHECK_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLFILECHECK_SIZE, long style = SYMBOL_WXGNUPGSHELLFILECHECK_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLFILECHECK_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLFILECHECK_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLFILECHECK_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLFILECHECK_SIZE, long style = SYMBOL_WXGNUPGSHELLFILECHECK_STYLE );

    /// Destructor
    ~wxGnuPGShellFileCheck();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellFileCheck event handler declarations

    /// wxEVT_LEFT_UP event handler for ID_FILECHECK_CLOSE
    void OnLeftUp( wxMouseEvent& event );

////@end wxGnuPGShellFileCheck event handler declarations

////@begin wxGnuPGShellFileCheck member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellFileCheck member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellFileCheck member variables
    wxNotebook* m_filesTabsCtrl;
////@end wxGnuPGShellFileCheck member variables
};

#endif
    // _WXGNUPGSHELLFILECHECK_H_
