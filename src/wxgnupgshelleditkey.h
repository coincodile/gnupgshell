/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshelleditkey.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 17:04:48
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLEDITKEY_H_
#define _WXGNUPGSHELLEDITKEY_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshelleditkey.h"
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
#define ID_WXGNUPGSHELLEDITKEY 10040
#define ID_EDITKEY_USERNAME 10046
#define ID_EDITKEY_KEYID 10047
#define ID_EDITKEY_CHPASSKEY 10041
#define ID_EDITKEY_EXPIRYDATE 10045
#define ID_EDITKEY_CHEXPIRATION 10042
#define ID_STATICLINE1 10043
#define SYMBOL_WXGNUPGSHELLEDITKEY_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLEDITKEY_TITLE _("Edit Key")
#define SYMBOL_WXGNUPGSHELLEDITKEY_IDNAME ID_WXGNUPGSHELLEDITKEY
#define SYMBOL_WXGNUPGSHELLEDITKEY_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLEDITKEY_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * wxGnuPGShellEditKey class declaration
 */

class wxGnuPGShellEditKey: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellEditKey)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellEditKey();
	wxGnuPGShellEditKey(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLEDITKEY_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLEDITKEY_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLEDITKEY_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLEDITKEY_SIZE, long style =
			SYMBOL_WXGNUPGSHELLEDITKEY_STYLE);

	/// Creation
	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLEDITKEY_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLEDITKEY_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLEDITKEY_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLEDITKEY_SIZE, long style =
			SYMBOL_WXGNUPGSHELLEDITKEY_STYLE);

	/// Destructor
	~wxGnuPGShellEditKey();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();

////@begin wxGnuPGShellEditKey event handler declarations

/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EDITKEY_CHPASSKEY
	void OnEditkeyChpasskeyClick(wxCommandEvent &event);

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EDITKEY_CHEXPIRATION
	void OnEditkeyChexpirationClick(wxCommandEvent &event);

////@end wxGnuPGShellEditKey event handler declarations

////@begin wxGnuPGShellEditKey member function declarations

/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellEditKey member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellEditKey member variables
	wxStaticText *m_userName;
	wxStaticText *m_keyID;
	wxStaticText *m_expiryDate;
////@end wxGnuPGShellEditKey member variables
};

#endif
// _WXGNUPGSHELLEDITKEY_H_
