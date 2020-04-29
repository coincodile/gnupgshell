/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellexpiration.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 16:41:15
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLEXPIRATION_H_
#define _WXGNUPGSHELLEXPIRATION_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellexpiration.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/calctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxCalendarCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLEXPIRATION 10033
#define ID_EXPIRATION_MODE 10034
#define ID_EXPIRATION_CALENDAR 10035
#define SYMBOL_WXGNUPGSHELLEXPIRATION_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLEXPIRATION_TITLE _("Expire date")
#define SYMBOL_WXGNUPGSHELLEXPIRATION_IDNAME ID_WXGNUPGSHELLEXPIRATION
#define SYMBOL_WXGNUPGSHELLEXPIRATION_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLEXPIRATION_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * wxGnuPGShellExpiration class declaration
 */

class wxGnuPGShellExpiration: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellExpiration)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellExpiration();
	wxGnuPGShellExpiration(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLEXPIRATION_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLEXPIRATION_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLEXPIRATION_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLEXPIRATION_SIZE, long style =
			SYMBOL_WXGNUPGSHELLEXPIRATION_STYLE);

	/// Creation
	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLEXPIRATION_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLEXPIRATION_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLEXPIRATION_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLEXPIRATION_SIZE, long style =
			SYMBOL_WXGNUPGSHELLEXPIRATION_STYLE);

	/// Destructor
	~wxGnuPGShellExpiration();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();

////@begin wxGnuPGShellExpiration event handler declarations

/// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_EXPIRATION_MODE
	void OnExpirationModeSelected(wxCommandEvent &event);

////@end wxGnuPGShellExpiration event handler declarations

////@begin wxGnuPGShellExpiration member function declarations

/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellExpiration member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellExpiration member variables
	wxRadioBox *m_expirationMode;
	wxCalendarCtrl *m_calendarCtrl;
////@end wxGnuPGShellExpiration member variables
};

#endif
// _WXGNUPGSHELLEXPIRATION_H_
