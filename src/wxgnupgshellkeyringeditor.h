/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellkeyringeditor.h
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 15:45:44
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLKEYRINGEDITOR_H_
#define _WXGNUPGSHELLKEYRINGEDITOR_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellkeyringeditor.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/aui/framemanager.h"
#include "wx/frame.h"
#include "wx/toolbar.h"
#include "wx/listctrl.h"
#include "wx/statusbr.h"
#include "wx/aui/auibook.h"
////@end includes
#include "wxGnuPGKeyListCtrl.h"
#include <wx/dcclient.h>
#include <wx/scrolwin.h>
#include <wx/propgrid/propgrid.h>
/*!
 * Forward declarations
 */

////@begin forward declarations
class wxGnuPGKeyListCtrl;
class wxStatusBar;
class wxAuiNotebook;
class wxPropertyGrid;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLKEYRINGEDITOR 10013
#define ID_SELECT_LANGUAGE 10125
#define ID_MENU_CLEAR_LOG 10018
#define ID_MENU_PREFERENCES 10014
#define ID_MENU_REFRESH 10066
#define ID_MENU_UPDATE_TRUSTDB 10126
#define ID_MENU_KEY_PUB 10114
#define ID_MENU_KEY_SEC 10118
#define ID_MENU_SELECT_ALL 10011
#define ID_MENU_NEW_KEY 10067
#define ID_MENU_DEL_KEY 10068
#define ID_MENU_EDIT_KEY 10069
#define ID_MENU_OWNER_TRUST 10071
#define ID_MENU_REVOKE_KEY 10127
#define ID_MENU_IMPORT_KEY 10080
#define ID_MENU_EXPORT_KEY 10081
#define ID_MENU_RETRIEVE_KEY 10084
#define ID_MENU_SEND_KEYS 10085
#define ID_MENU_FILEMANAGER 10086
#define ID_MENU_CLEAR_PASS_CACHE 10136
#define ID_TOOLBAR_KEYRING_EDITOR 10016
#define ID_KE_TOOL_EDIT 10015
#define ID_KE_TOOL_DELETE 10017
#define ID_KE_TOOL_IMPORT 10019
#define ID_KE_TOOL_EXPORT 10020
#define ID_KE_TOOL_REFRESH 10023
#define ID_KE_TOOL_FILES 10024
#define ID_KE_KEYLIST 10000
#define ID_KE_STAT_BAR 10026
#define ID_KE_MAIN_NOTEBOOK 10007
#define ID_KE_KEYPROPERTY 10009
#define ID_KE_LOGTEXT 10008
#define SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_TITLE _("GnuPG Shell v1.0 - Keyring Editor")
#define SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_IDNAME ID_WXGNUPGSHELLKEYRINGEDITOR
#define SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_SIZE wxSize(800, 550)
#define SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * wxGnuPGShellKeyringEditor class declaration
 */

class wxGnuPGShellKeyringEditor: public wxFrame {
DECLARE_CLASS( wxGnuPGShellKeyringEditor )DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellKeyringEditor();
	wxGnuPGShellKeyringEditor(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_SIZE, long style =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_STYLE);

	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_SIZE, long style =
			SYMBOL_WXGNUPGSHELLKEYRINGEDITOR_STYLE);

	/// Destructor
	~wxGnuPGShellKeyringEditor();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();

	/// Insert columns in key editor list
	void FillKeyListColumns();
	void UpdateProperties(const int index);
	void RefreshKeyList();
	void FillProperties();
	void SaveWindowsSettings();
	void LoadWindowsSettings();
	void OnKeyListRightDown(wxMouseEvent &event);

////@begin wxGnuPGShellKeyringEditor event handler declarations

/// wxEVT_CLOSE_WINDOW event handler for ID_WXGNUPGSHELLKEYRINGEDITOR
	void OnCloseWindow(wxCloseEvent &event);

	/// wxEVT_DESTROY event handler for ID_WXGNUPGSHELLKEYRINGEDITOR
	void OnDestroy(wxWindowDestroyEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
	void OnEXITClick(wxCommandEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_SELECT_LANGUAGE
	void OnSelectLanguageClick(wxCommandEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_CLEAR_LOG
	void OnMenuClearLogClick(wxCommandEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_PREFERENCES
	void OnMenuPreferencesClick(wxCommandEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REFRESH
	void OnMenuRefreshClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_REFRESH
	void OnMenuRefreshUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_UPDATE_TRUSTDB
	void OnMenuUpdateTrustdbClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_UPDATE_TRUSTDB
	void OnMenuUpdateTrustdbUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_KEY_PUB
	void OnMenuKeyPubClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_KEY_PUB
	void OnMenuKeyPubUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_KEY_SEC
	void OnMenuKeySecClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_KEY_SEC
	void OnMenuKeySecUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SELECT_ALL
	void OnMenuSelectAllClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_SELECT_ALL
	void OnMenuSelectAllUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_NEW_KEY
	void OnMenuNewKeyClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_NEW_KEY
	void OnMenuNewKeyUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_DEL_KEY
	void OnMenuDelKeyClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_DEL_KEY
	void OnMenuDelKeyUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_EDIT_KEY
	void OnMenuEditKeyClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_EDIT_KEY
	void OnMenuEditKeyUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_OWNER_TRUST
	void OnMenuOwnerTrustClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_OWNER_TRUST
	void OnMenuOwnerTrustUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REVOKE_KEY
	void OnMENUREVOKEKEYClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_REVOKE_KEY
	void OnMENUREVOKEKEYUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_IMPORT_KEY
	void OnMenuImportKeyClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_IMPORT_KEY
	void OnMenuImportKeyUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_EXPORT_KEY
	void OnMenuExportKeyClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_EXPORT_KEY
	void OnMenuExportKeyUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_RETRIEVE_KEY
	void OnMenuRetrieveKeyClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_RETRIEVE_KEY
	void OnMenuRetrieveKeyUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SEND_KEYS
	void OnMenuSendKeysClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_SEND_KEYS
	void OnMenuSendKeysUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_FILEMANAGER
	void OnMenuFilemanagerClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_MENU_FILEMANAGER
	void OnMenuFilemanagerUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_CLEAR_PASS_CACHE
	void OnMENUCLEARPASSCACHEClick(wxCommandEvent &event);

	/// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
	void OnABOUTClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_TOOL_EDIT
	void OnKeToolEditUpdate(wxUpdateUIEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_TOOL_DELETE
	void OnKeToolDeleteUpdate(wxUpdateUIEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_TOOL_IMPORT
	void OnKeToolImportUpdate(wxUpdateUIEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_TOOL_EXPORT
	void OnKeToolExportUpdate(wxUpdateUIEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_TOOL_REFRESH
	void OnKeToolRefreshUpdate(wxUpdateUIEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_TOOL_FILES
	void OnKeToolFilesUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_KE_KEYLIST
	void OnKeKeylistSelected(wxListEvent &event);

	/// wxEVT_CONTEXT_MENU event handler for ID_KE_KEYLIST
	void OnContextMenu(wxContextMenuEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_KE_STAT_BAR
	void OnKESTATBARUpdate(wxUpdateUIEvent &event);

////@end wxGnuPGShellKeyringEditor event handler declarations

////@begin wxGnuPGShellKeyringEditor member function declarations

/// Returns the AUI manager object
	wxAuiManager& GetAuiManager() {
		return m_auiManager;
	}

	/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellKeyringEditor member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellKeyringEditor member variables
	wxAuiManager m_auiManager;
	wxGnuPGKeyListCtrl *m_keyListCtrl;
	wxStatusBar *m_statusBar;
	wxAuiNotebook *m_auiNotebook;
	wxPropertyGrid *m_keyProperty;
	wxTextCtrl *m_logText;
////@end wxGnuPGShellKeyringEditor member variables
	bool m_isSelectedAll;
	wxString m_keyRing;
	bool m_isPublicKeyring;
	wxMenu *m_popupMenu;
};

#endif
// _WXGNUPGSHELLKEYRINGEDITOR_H_
