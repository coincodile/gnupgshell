/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellsettings.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 16:02:04
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLSETTINGS_H_
#define _WXGNUPGSHELLSETTINGS_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellsettings.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/listctrl.h"
#include "wx/spinctrl.h"
#include "wx/statline.h"
////@end includes


#include "app_resources.h"

/*!
 * Forward declarations
 */


////@begin forward declarations
class wxListView;
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLSETTINGS 10027
#define ID_SETTINGS_KEYLIST 10000
#define ID_SETTINGS_USE_CACHE 10001
#define ID_SETTINGS_CACHE_TIME 10135
#define ID_SETTINGS_SERVER_LIST 10097
#define ID_SETTINGS_BTN_ADD 10002
#define ID_SETTINGS_BTN_DEL 10012
#define ID_SETTINGS_STATICLINE 10003
#define SYMBOL_WXGNUPGSHELLSETTINGS_STYLE wxDEFAULT_DIALOG_STYLE|wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLSETTINGS_TITLE _("Settings")
#define SYMBOL_WXGNUPGSHELLSETTINGS_IDNAME ID_WXGNUPGSHELLSETTINGS
#define SYMBOL_WXGNUPGSHELLSETTINGS_SIZE wxSize(300, 400)
#define SYMBOL_WXGNUPGSHELLSETTINGS_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellSettings class declaration
 */

class wxGnuPGShellSettings: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellSettings )
    DECLARE_EVENT_TABLE()
    wxMenu *m_popupMenu;

public:
    /// Constructors
    wxGnuPGShellSettings();
    wxGnuPGShellSettings( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLSETTINGS_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLSETTINGS_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLSETTINGS_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLSETTINGS_SIZE, long style = SYMBOL_WXGNUPGSHELLSETTINGS_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLSETTINGS_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLSETTINGS_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLSETTINGS_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLSETTINGS_SIZE, long style = SYMBOL_WXGNUPGSHELLSETTINGS_STYLE );

    /// Destructor
    ~wxGnuPGShellSettings();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();
    void FillKeyListColumns();
    void ListKeys();
    void OnSettingsSetDefaultClick( wxCommandEvent& event );

////@begin wxGnuPGShellSettings event handler declarations

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_SETTINGS_KEYLIST
    void OnSettingsKeylistSelected( wxListEvent& event );

    /// wxEVT_CONTEXT_MENU event handler for ID_SETTINGS_KEYLIST
    void OnContextMenu( wxContextMenuEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SETTINGS_USE_CACHE
    void OnSETTINGSUSECACHEClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SETTINGS_BTN_ADD
    void OnSettingsBtnAddClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SETTINGS_BTN_DEL
    void OnSettingsBtnDelClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_SETTINGS_BTN_DEL
    void OnSettingsBtnDelUpdate( wxUpdateUIEvent& event );

////@end wxGnuPGShellSettings event handler declarations

////@begin wxGnuPGShellSettings member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellSettings member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellSettings member variables
    wxListView* m_keyListCtrl;
    wxCheckBox* m_useCache;
    wxSpinCtrl* m_cacheTime;
    wxChoice* m_defServerCombo;
////@end wxGnuPGShellSettings member variables
    int m_selectedKey;
};

#endif
    // _WXGNUPGSHELLSETTINGS_H_
