/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshelltrust.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     03/08/2007 16:50:08
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLTRUST_H_
#define _WXGNUPGSHELLTRUST_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshelltrust.h"
#endif

/*!
 * Includes
 */

////@begin includes
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
#define ID_WXGNUPGSHELLTRUST 10036
#define ID_TRUST_NAME 10038
#define ID_TRUST_ID 10039
#define ID_RADIO_UNKNOWN 10037
#define ID_RADIO_NEVER 10105
#define ID_RADIO_MARGINAL 10106
#define ID_RADIO_FULL 10107
#define ID_RADIO_ULTIMATE 10108
#define SYMBOL_WXGNUPGSHELLTRUST_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLTRUST_TITLE _("Change Key Ownertrust")
#define SYMBOL_WXGNUPGSHELLTRUST_IDNAME ID_WXGNUPGSHELLTRUST
#define SYMBOL_WXGNUPGSHELLTRUST_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLTRUST_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * wxGnuPGShellTrust class declaration
 */

class wxGnuPGShellTrust: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellTrust)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellTrust();
	wxGnuPGShellTrust(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLTRUST_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLTRUST_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLTRUST_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLTRUST_SIZE, long style =
			SYMBOL_WXGNUPGSHELLTRUST_STYLE);

	/// Creation
	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLTRUST_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLTRUST_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLTRUST_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLTRUST_SIZE, long style =
			SYMBOL_WXGNUPGSHELLTRUST_STYLE);

	/// Destructor
	~wxGnuPGShellTrust();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();
	int GetTrust(void);
	void SetTrust();
	int m_trust;

////@begin wxGnuPGShellTrust event handler declarations

////@end wxGnuPGShellTrust event handler declarations

////@begin wxGnuPGShellTrust member function declarations

/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellTrust member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellTrust member variables
	wxStaticText *m_trustName;
	wxStaticText *m_trustKeyID;
	wxRadioButton *m_isTrustUnknown;
	wxRadioButton *m_isTrustNever;
	wxRadioButton *m_isTrustMarginal;
	wxRadioButton *m_isTrustFull;
	wxRadioButton *m_isTrustUltimate;
////@end wxGnuPGShellTrust member variables
};

#endif
// _WXGNUPGSHELLTRUST_H_
