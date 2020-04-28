/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellpasskey.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 17:18:28
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLPASSKEY_H_
#define _WXGNUPGSHELLPASSKEY_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellpasskey.h"
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
#define ID_WXGNUPGSHELLPASSKEY 10048
#define ID_PASSKEY_USERNAME 10051
#define ID_PASSKEY_KEYID 10052
#define ID_PASSKEY_CURRENT_PASS 10083
#define ID_PASSKEY_PASS 10049
#define ID_PASSKEY_CONFIRM 10073
#define ID_STATICLINE2 10050
#define SYMBOL_WXGNUPGSHELLPASSKEY_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLPASSKEY_TITLE _("Change passphrase")
#define SYMBOL_WXGNUPGSHELLPASSKEY_IDNAME ID_WXGNUPGSHELLPASSKEY
#define SYMBOL_WXGNUPGSHELLPASSKEY_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLPASSKEY_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * wxGnuPGShellPassKey class declaration
 */

class wxGnuPGShellPassKey: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellPassKey)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellPassKey();
	wxGnuPGShellPassKey(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLPASSKEY_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLPASSKEY_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLPASSKEY_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLPASSKEY_SIZE, long style =
			SYMBOL_WXGNUPGSHELLPASSKEY_STYLE);

	/// Creation
	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLPASSKEY_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLPASSKEY_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLPASSKEY_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLPASSKEY_SIZE, long style =
			SYMBOL_WXGNUPGSHELLPASSKEY_STYLE);

	/// Destructor
	~wxGnuPGShellPassKey();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();

////@begin wxGnuPGShellPassKey event handler declarations

/// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
	void OnOkClick(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for wxID_OK
	void OnOkUpdate(wxUpdateUIEvent &event);

////@end wxGnuPGShellPassKey event handler declarations

////@begin wxGnuPGShellPassKey member function declarations

/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellPassKey member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellPassKey member variables
	wxStaticText *m_userName;
	wxStaticText *m_keyID;
	wxTextCtrl *m_currPass;
	wxTextCtrl *m_passKey;
	wxTextCtrl *m_passConfirm;
////@end wxGnuPGShellPassKey member variables
};

#endif
// _WXGNUPGSHELLPASSKEY_H_
