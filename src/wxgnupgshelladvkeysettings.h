/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshelladvkeysettings.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     10/08/2007 12:18:44
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLADVKEYSETTINGS_H_
#define _WXGNUPGSHELLADVKEYSETTINGS_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshelladvkeysettings.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/datectrl.h"
#include "wx/dateevt.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxDatePickerCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLADVKEYSETTINGS 10072
#define ID_ADVANCEDKEY_KEYTYPE 10000
#define ID_ADVANCEDKEY_GEN_SEPARATE 10089
#define ID_ADVANCEDKEY_KEYSIZE 10090
#define ID_ADVANCEDKEY_RADIO_NEVER 10091
#define ID_ADVANCEDKEY_RADIO_DATE 10092
#define ID_ADVANCEDKEY_EXPIRATION_DATE 10093
#define SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_TITLE _("Advanced Key Settings")
#define SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_IDNAME ID_WXGNUPGSHELLADVKEYSETTINGS
#define SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * wxGnuPGShellAdvKeySettings class declaration
 */

class wxGnuPGShellAdvKeySettings: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellAdvKeySettings)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellAdvKeySettings();
	wxGnuPGShellAdvKeySettings(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_SIZE, long style =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_STYLE);

	/// Creation
	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_SIZE, long style =
			SYMBOL_WXGNUPGSHELLADVKEYSETTINGS_STYLE);

	/// Destructor
	~wxGnuPGShellAdvKeySettings();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();
	wxString GetExpirationString();

////@begin wxGnuPGShellAdvKeySettings event handler declarations

/// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_ADVANCEDKEY_RADIO_DATE
	void OnAdvancedkeyRadioDateSelected(wxCommandEvent &event);

	/// wxEVT_UPDATE_UI event handler for ID_ADVANCEDKEY_EXPIRATION_DATE
	void OnAdvancedkeyExpirationDateUpdate(wxUpdateUIEvent &event);

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
	void OnOkClick(wxCommandEvent &event);

////@end wxGnuPGShellAdvKeySettings event handler declarations

////@begin wxGnuPGShellAdvKeySettings member function declarations

/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellAdvKeySettings member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellAdvKeySettings member variables
	wxChoice *m_keyType;
	wxCheckBox *m_generateSeparateFlag;
	wxTextCtrl *m_keySize;
	wxRadioButton *m_expireNever;
	wxDatePickerCtrl *m_expirationDate;
////@end wxGnuPGShellAdvKeySettings member variables
};

#endif
// _WXGNUPGSHELLADVKEYSETTINGS_H_
