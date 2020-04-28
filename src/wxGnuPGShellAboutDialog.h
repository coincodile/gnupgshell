/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellAboutDialog.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     11/08/2007 00:15:33
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLABOUTDIALOG_H_
#define _WXGNUPGSHELLABOUTDIALOG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxGnuPGShellAboutDialog.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/hyperlink.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxHyperlinkCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLABOUTDIALOG 10005
#define ID_ABOUT_VENDOR_TEXTCTRL 10006
#define ID_HYPER_ADDR 10124
#define ID_HYPERLINKCTRL1 10122
#define SYMBOL_WXGNUPGSHELLABOUTDIALOG_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLABOUTDIALOG_TITLE _("About GnuPG Shell...")
#define SYMBOL_WXGNUPGSHELLABOUTDIALOG_IDNAME ID_WXGNUPGSHELLABOUTDIALOG
#define SYMBOL_WXGNUPGSHELLABOUTDIALOG_SIZE wxDefaultSize
#define SYMBOL_WXGNUPGSHELLABOUTDIALOG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxGnuPGShellAboutDialog class declaration
 */

class wxGnuPGShellAboutDialog: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellAboutDialog)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellAboutDialog();
	wxGnuPGShellAboutDialog(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_SIZE, long style =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_STYLE);

	/// Creation
	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_SIZE, long style =
			SYMBOL_WXGNUPGSHELLABOUTDIALOG_STYLE);

	/// Destructor
	~wxGnuPGShellAboutDialog();

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();

////@begin wxGnuPGShellAboutDialog event handler declarations

////@end wxGnuPGShellAboutDialog event handler declarations

////@begin wxGnuPGShellAboutDialog member function declarations

/// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString &name);
////@end wxGnuPGShellAboutDialog member function declarations

/// Should we show tooltips?
	static bool ShowToolTips();

////@begin wxGnuPGShellAboutDialog member variables
	wxHyperlinkCtrl *m_addrLink;
////@end wxGnuPGShellAboutDialog member variables
};

#endif
// _WXGNUPGSHELLABOUTDIALOG_H_
