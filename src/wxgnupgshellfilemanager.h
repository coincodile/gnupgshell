/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellfilemanager.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 17:31:25
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLFILEMANAGER_H_
#define _WXGNUPGSHELLFILEMANAGER_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellfilemanager.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/aui/framemanager.h"
#include "wx/frame.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/listctrl.h"
////@end includes
#include <wx/aui/aui.h>
/*!
 * Forward declarations
 */

////@begin forward declarations
class wxStatusBar;
class wxListView;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLFILEMANAGER 10109
#define ID_MENU_ADD 10111
#define ID_MENU_REMOVE 10112
#define ID_MENU_REMOVE_ALL 10044
#define ID_MENU_SIGN_FILE 10058
#define ID_MENU_ENCRYPT_FILE 10059
#define ID_MENU_DECRYPT_FILE 10062
#define ID_FILE_TOOLBAR 10113
#define ID_TOOL_OPEN 10115
#define ID_TOOL_CLEAR 10116
#define ID_TOOL_SIGN 10075
#define ID_TOOL_ENCRYPT 10076
#define ID_TOOL_DECRYPT 10077
#define ID_FILE_STATUSBAR 10117
#define ID_GNUPGKEYLIST_CTRL 11000
#define SYMBOL_WXGNUPGSHELLFILEMANAGER_STYLE wxDEFAULT_FRAME_STYLE|wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLFILEMANAGER_TITLE _("GnuPG Shell - File Manager")
#define SYMBOL_WXGNUPGSHELLFILEMANAGER_IDNAME ID_WXGNUPGSHELLFILEMANAGER
#define SYMBOL_WXGNUPGSHELLFILEMANAGER_SIZE wxSize(500, 300)
#define SYMBOL_WXGNUPGSHELLFILEMANAGER_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellFileManager class declaration
 */

class wxGnuPGShellFileManager: public wxFrame
{    
    DECLARE_CLASS( wxGnuPGShellFileManager )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellFileManager();
    wxGnuPGShellFileManager( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLFILEMANAGER_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLFILEMANAGER_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLFILEMANAGER_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLFILEMANAGER_SIZE, long style = SYMBOL_WXGNUPGSHELLFILEMANAGER_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLFILEMANAGER_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLFILEMANAGER_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLFILEMANAGER_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLFILEMANAGER_SIZE, long style = SYMBOL_WXGNUPGSHELLFILEMANAGER_STYLE );

    /// Destructor
    ~wxGnuPGShellFileManager();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

    bool        AddFileToList();
    void        AddFileToList(const int pos, const wxString fileName);
    wxMenu    * m_popupMenu;
    
    //bool        EncryptUseKey(const wxString newName, const wxString keyId, bool armored);
    //bool        EncryptUsePass(const wxString newName, const wxString pass, bool armored);
    wxString    GetNewFileName(const wxString fileName, const wxString extension);

////@begin wxGnuPGShellFileManager event handler declarations

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_ADD
    void OnMenuAddClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REMOVE
    void OnMenuRemoveClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_MENU_REMOVE
    void OnMenuRemoveUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REMOVE_ALL
    void OnMenuRemoveAllClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_MENU_REMOVE_ALL
    void OnMenuRemoveAllUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
    void OnExitClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SIGN_FILE
    void OnMenuSignFileClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_MENU_SIGN_FILE
    void OnMenuSignFileUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_ENCRYPT_FILE
    void OnMenuEncryptFileClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_MENU_ENCRYPT_FILE
    void OnMenuEncryptFileUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_DECRYPT_FILE
    void OnMenuDecryptFileClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_MENU_DECRYPT_FILE
    void OnMenuDecryptFileUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_OPEN
    void OnToolOpenClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CLEAR
    void OnToolClearClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_CLEAR
    void OnToolClearUpdate( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_SIGN
    void OnToolSignUpdate( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_ENCRYPT
    void OnToolEncryptUpdate( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_DECRYPT
    void OnToolDecryptUpdate( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_FILE_STATUSBAR
    void OnFILESTATUSBARUpdate( wxUpdateUIEvent& event );

    /// wxEVT_CONTEXT_MENU event handler for ID_GNUPGKEYLIST_CTRL
    void OnContextMenu( wxContextMenuEvent& event );

////@end wxGnuPGShellFileManager event handler declarations

////@begin wxGnuPGShellFileManager member function declarations

    /// Returns the AUI manager object
    wxAuiManager& GetAuiManager() { return m_auiManager; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellFileManager member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellFileManager member variables
    wxAuiManager m_auiManager;
    wxStatusBar* m_statusBar;
    wxListView* m_fileList;
////@end wxGnuPGShellFileManager member variables
};

#endif
    // _WXGNUPGSHELLFILEMANAGER_H_
