/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellkeygenwizard.h
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     10/08/2007 11:10:50
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGSHELLKEYGENWIZARD_H_
#define _WXGNUPGSHELLKEYGENWIZARD_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellkeygenwizard.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/wizard.h"
#include "wx/statline.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxGnuPGShellWizPageIntro;
class wxGnuPGShellWizPageInfo;
class wxGnuPGShellWizPagePass;
class wxGnuPGShellWizPageDone;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGNUPGSHELLKEYGENWIZARD 10010
#define ID_WIZPAGE_INTRO 10025
#define ID_WIZPAGE_INFO 10056
#define ID_STATICLINE3 10064
#define ID_WIZPAGEINFO_FULLNAME 10065
#define ID_WIZPAGEINFO_EMAIL 10001
#define ID_WIZPAGEINFO_COMMENT 10004
#define ID_WIZPAGEINFO_BTN_ADVANCED 10070
#define ID_WIZPAGE_PASS 10057
#define ID_STATICLINE4 10082
#define ID_WIZPAGEPASS_PASSPHRASE 10094
#define ID_WIZPAGEPASS_CONFIRMATION 10096
#define ID_WIZPAGE_DONE 10060
#define ID_STATICLINE7 10104
#define SYMBOL_WXGNUPGSHELLKEYGENWIZARD_IDNAME ID_WXGNUPGSHELLKEYGENWIZARD
////@end control identifiers


/*!
 * wxGnuPGShellKeyGenWizard class declaration
 */

class wxGnuPGShellKeyGenWizard: public wxWizard
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellKeyGenWizard )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellKeyGenWizard();
    wxGnuPGShellKeyGenWizard( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLKEYGENWIZARD_IDNAME, const wxPoint& pos = wxDefaultPosition );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXGNUPGSHELLKEYGENWIZARD_IDNAME, const wxPoint& pos = wxDefaultPosition );

    /// Destructor
    ~wxGnuPGShellKeyGenWizard();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellKeyGenWizard event handler declarations

    /// wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WXGNUPGSHELLKEYGENWIZARD
    void OnWxgnupgshellkeygenwizardPageChanging( wxWizardEvent& event );

    /// wxEVT_WIZARD_CANCEL event handler for ID_WXGNUPGSHELLKEYGENWIZARD
    void OnWxgnupgshellkeygenwizardCancel( wxWizardEvent& event );

    /// wxEVT_WIZARD_FINISHED event handler for ID_WXGNUPGSHELLKEYGENWIZARD
    void OnWxgnupgshellkeygenwizardFinished( wxWizardEvent& event );

////@end wxGnuPGShellKeyGenWizard event handler declarations

////@begin wxGnuPGShellKeyGenWizard member function declarations

    /// Runs the wizard
    bool Run();

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellKeyGenWizard member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellKeyGenWizard member variables
    wxGnuPGShellWizPageIntro* m_pageIntro;
    wxGnuPGShellWizPageInfo* m_pageInfo;
    wxGnuPGShellWizPagePass* m_pagePass;
    wxGnuPGShellWizPageDone* m_pageDone;
////@end wxGnuPGShellKeyGenWizard member variables
    wxString m_name;
    wxString m_email;
    wxString m_comment;
    wxString m_pass;
    wxString m_size;
    wxString m_keyType;
    wxString m_expire;
    bool m_isSepareteSignKey;
};

/*!
 * wxGnuPGShellWizPageUserType class declaration
 */

class wxGnuPGShellWizPageUserType: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPageUserType )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPageUserType();

    wxGnuPGShellWizPageUserType( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPageUserType();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPageUserType event handler declarations

////@end wxGnuPGShellWizPageUserType event handler declarations

////@begin wxGnuPGShellWizPageUserType member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPageUserType member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPageUserType member variables
////@end wxGnuPGShellWizPageUserType member variables
};

/*!
 * wxGnuPGShellWizPageIntro class declaration
 */

class wxGnuPGShellWizPageIntro: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPageIntro )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPageIntro();

    wxGnuPGShellWizPageIntro( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPageIntro();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPageIntro event handler declarations

////@end wxGnuPGShellWizPageIntro event handler declarations

////@begin wxGnuPGShellWizPageIntro member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPageIntro member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPageIntro member variables
////@end wxGnuPGShellWizPageIntro member variables
};

/*!
 * wxGnuPGShellWizPageInfo class declaration
 */

class wxGnuPGShellWizPageInfo: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPageInfo )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPageInfo();

    wxGnuPGShellWizPageInfo( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPageInfo();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPageInfo event handler declarations

    /// wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WIZPAGE_INFO
    void OnWizpageInfoPageChanging( wxWizardEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_WIZPAGEINFO_BTN_ADVANCED
    void OnWizpageinfoBtnAdvancedClick( wxCommandEvent& event );

////@end wxGnuPGShellWizPageInfo event handler declarations

////@begin wxGnuPGShellWizPageInfo member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPageInfo member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPageInfo member variables
    wxTextCtrl* m_fullName;
    wxTextCtrl* m_primaryEmail;
    wxTextCtrl* m_comment;
////@end wxGnuPGShellWizPageInfo member variables
protected:
    bool m_showMore;
};

/*!
 * wxGnuPGShellWizPagePass class declaration
 */

class wxGnuPGShellWizPagePass: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPagePass )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPagePass();

    wxGnuPGShellWizPagePass( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPagePass();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPagePass event handler declarations

    /// wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WIZPAGE_PASS
    void OnWizpagePassPageChanging( wxWizardEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_WIZPAGEPASS_PASSPHRASE
    void OnWizpagepassPassphraseUpdated( wxCommandEvent& event );

////@end wxGnuPGShellWizPagePass event handler declarations

////@begin wxGnuPGShellWizPagePass member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPagePass member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPagePass member variables
    wxTextCtrl* m_passPhrase;
    wxTextCtrl* m_passConfirmation;
////@end wxGnuPGShellWizPagePass member variables
};

/*!
 * wxGnuPGShellWizPagePassPrpoblem class declaration
 */

class wxGnuPGShellWizPagePassPrpoblem: public wxWizardPage
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPagePassPrpoblem )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPagePassPrpoblem();

    wxGnuPGShellWizPagePassPrpoblem( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPagePassPrpoblem();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPagePassPrpoblem event handler declarations

////@end wxGnuPGShellWizPagePassPrpoblem event handler declarations

////@begin wxGnuPGShellWizPagePassPrpoblem member function declarations

    /// Gets the previous page
    virtual wxWizardPage* GetPrev() const;

    /// Gets the next page
    virtual wxWizardPage* GetNext() const;

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPagePassPrpoblem member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPagePassPrpoblem member variables
////@end wxGnuPGShellWizPagePassPrpoblem member variables
};

/*!
 * wxGnuPGShellWizPageKeyGen class declaration
 */

class wxGnuPGShellWizPageKeyGen: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPageKeyGen )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPageKeyGen();

    wxGnuPGShellWizPageKeyGen( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPageKeyGen();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPageKeyGen event handler declarations

////@end wxGnuPGShellWizPageKeyGen event handler declarations

////@begin wxGnuPGShellWizPageKeyGen member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPageKeyGen member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPageKeyGen member variables
    wxGauge* m_overallStatus;
////@end wxGnuPGShellWizPageKeyGen member variables
};

/*!
 * wxGnuPGShellWizPageDone class declaration
 */

class wxGnuPGShellWizPageDone: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPageDone )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPageDone();

    wxGnuPGShellWizPageDone( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPageDone();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPageDone event handler declarations

////@end wxGnuPGShellWizPageDone event handler declarations

////@begin wxGnuPGShellWizPageDone member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPageDone member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPageDone member variables
////@end wxGnuPGShellWizPageDone member variables
};

/*!
 * wxGnuPGShellWizPageDone1 class declaration
 */

class wxGnuPGShellWizPageDone1: public wxWizardPageSimple
{    
    DECLARE_DYNAMIC_CLASS( wxGnuPGShellWizPageDone1 )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGnuPGShellWizPageDone1();

    wxGnuPGShellWizPageDone1( wxWizard* parent );

    /// Creation
    bool Create( wxWizard* parent );

    /// Destructor
    ~wxGnuPGShellWizPageDone1();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGnuPGShellWizPageDone1 event handler declarations

////@end wxGnuPGShellWizPageDone1 event handler declarations

////@begin wxGnuPGShellWizPageDone1 member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGnuPGShellWizPageDone1 member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGnuPGShellWizPageDone1 member variables
////@end wxGnuPGShellWizPageDone1 member variables
};

#endif
    // _WXGNUPGSHELLKEYGENWIZARD_H_
