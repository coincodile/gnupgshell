/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellbackup.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 16:32:34
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLBACKUP_H_
#define _WXGNUPGSHELLBACKUP_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellbackup.h"
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
#define ID_WXGNUPGSHELLBACKUP 10028
#define ID_BACKUP_KEY_ID 10031
#define ID_BACKUP_KEY_NAME 10120
#define ID_BACKUP_FILENAME 10029
#define ID_BACKUP_BROWSE 10030
#define ID_BACKUP_CHECK_ARMOR 10000
#define ID_BACKUP_CHECK_PGP 10121
#define ID_STATICLINE 10032
#define SYMBOL_WXGNUPGSHELLBACKUP_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLBACKUP_TITLE _("Export / Import")
#define SYMBOL_WXGNUPGSHELLBACKUP_IDNAME ID_WXGNUPGSHELLBACKUP
#define SYMBOL_WXGNUPGSHELLBACKUP_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLBACKUP_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellBackup class declaration
 */

class wxGnuPGShellBackup: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellBackup )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellBackup();
    wxGnuPGShellBackup( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLBACKUP_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLBACKUP_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLBACKUP_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLBACKUP_SIZE, long style = SYMBOL_WXGNUPGSHELLBACKUP_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLBACKUP_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLBACKUP_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLBACKUP_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLBACKUP_SIZE, long style = SYMBOL_WXGNUPGSHELLBACKUP_STYLE );

    /// Destructor
    ~wxGnuPGShellBackup();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

    bool m_importKey;
    wxArrayString m_paths;

////@begin wxGnuPGShellBackup event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BACKUP_BROWSE
    void OnBackupBrowseClick( wxCommandEvent& event );

////@end wxGnuPGShellBackup event handler declarations

////@begin wxGnuPGShellBackup member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellBackup member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellBackup member variables
    wxStaticText* m_keyId;
    wxStaticText* m_keyName;
    wxTextCtrl* m_fileName;
    wxCheckBox* m_isArmor;
    wxCheckBox* m_isPGP2;
////@end wxGnuPGShellBackup member variables
};

#endif
    // _WXGNUPGSHELLBACKUP_H_
