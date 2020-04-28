/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellSelectRecipient.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     23/08/2007 10:51:44
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLSELECTRECIPIENT_H_
#define _WXGNUPGSHELLSELECTRECIPIENT_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxGnuPGShellSelectRecipient.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/statline.h"
#include "wx/listctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxListView;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLSELECTRECIPIENT 10021
#define ID_RECEPIENT_ASYNC 10131
#define ID_RECIPIENT_KEYLIST 10022
#define ID_RECEPIENT_SYNC 10132
#define ID_RECEPIENT_PASS 10133
#define ID_RECEPIENT_REPEAT 10134
#define ID_RECIPIENT_ARMOR 10078
#define ID_STATICLINE5 10074
#define SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_TITLE _("Select Recipient")
#define SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_IDNAME ID_WXGNUPGSHELLSELECTRECIPIENT
#define SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_SIZE wxSize(400, 400)
#define SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGnuPGShellSelectRecipient class declaration
 */

class wxGnuPGShellSelectRecipient: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellSelectRecipient )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellSelectRecipient();
    wxGnuPGShellSelectRecipient( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_SIZE, long style = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_IDNAME, const wxString& caption = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_TITLE, const wxPoint& pos = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_POSITION, const wxSize& size = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_SIZE, long style = SYMBOL_WXGNUPGSHELLSELECTRECIPIENT_STYLE );

    /// Destructor
    ~wxGnuPGShellSelectRecipient();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();
    void FillKeyList();

////@begin wxGnuPGShellSelectRecipient event handler declarations

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RECEPIENT_ASYNC
    void OnRECEPIENTASYNCSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RECEPIENT_SYNC
    void OnRECEPIENTSYNCSelected( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for wxID_OK
    void OnOkUpdate( wxUpdateUIEvent& event );

////@end wxGnuPGShellSelectRecipient event handler declarations

////@begin wxGnuPGShellSelectRecipient member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellSelectRecipient member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellSelectRecipient member variables
    wxRadioButton* m_useKey;
    wxListView* m_recKeyList;
    wxRadioButton* m_usePass;
    wxTextCtrl* m_pass;
    wxTextCtrl* m_repeat;
    wxCheckBox* m_needArmor;
////@end wxGnuPGShellSelectRecipient member variables
};

#endif
    // _WXGNUPGSHELLSELECTRECIPIENT_H_
