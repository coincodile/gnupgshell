/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellkeygenwizard.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     10/08/2007 11:10:50
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellkeygenwizard.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "wxgnupgshellkeygenwizard.h"
#include "wxgnupgshelladvkeysettings.h"


////@begin XPM images
#include "wizard.xpm"
////@end XPM images


/*!
 * wxGnuPGShellKeyGenWizard type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellKeyGenWizard, wxWizard )


/*!
 * wxGnuPGShellKeyGenWizard event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellKeyGenWizard, wxWizard )

////@begin wxGnuPGShellKeyGenWizard event table entries
    EVT_WIZARD_PAGE_CHANGING( ID_WXGNUPGSHELLKEYGENWIZARD, wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardPageChanging )
    EVT_WIZARD_CANCEL( ID_WXGNUPGSHELLKEYGENWIZARD, wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardCancel )
    EVT_WIZARD_FINISHED( ID_WXGNUPGSHELLKEYGENWIZARD, wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardFinished )

////@end wxGnuPGShellKeyGenWizard event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellKeyGenWizard constructors
 */

wxGnuPGShellKeyGenWizard::wxGnuPGShellKeyGenWizard()
{
    Init();
}

wxGnuPGShellKeyGenWizard::wxGnuPGShellKeyGenWizard( wxWindow* parent, wxWindowID id, const wxPoint& pos )
{
    Init();
    Create(parent, id, pos);
}


/*!
 * wxGnuPGShellKeyGenWizard creator
 */

bool wxGnuPGShellKeyGenWizard::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos )
{
////@begin wxGnuPGShellKeyGenWizard creation
    SetExtraStyle(wxWIZARD_EX_HELPBUTTON);
    wxBitmap wizardBitmap(GetBitmapResource(wxT("wizard.xpm")));
    wxWizard::Create( parent, id, _("PGP Key Generation Assistant"), wizardBitmap, pos, wxCAPTION|wxRESIZE_BORDER );

    CreateControls();
////@end wxGnuPGShellKeyGenWizard creation
    m_name = wxT("");
    m_email = wxT("user@mail.com");
    m_comment = wxT("");
    m_pass = wxT("");
    m_size = wxT("2048");
    m_keyType = wxT("DSA");
    wxString m_expire = wxT("0");
    //bool m_isSepareteSignKey = false;

    return true;
}


/*!
 * wxGnuPGShellKeyGenWizard destructor
 */

wxGnuPGShellKeyGenWizard::~wxGnuPGShellKeyGenWizard()
{
////@begin wxGnuPGShellKeyGenWizard destruction
////@end wxGnuPGShellKeyGenWizard destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellKeyGenWizard::Init()
{
////@begin wxGnuPGShellKeyGenWizard member initialisation
    m_pageIntro = NULL;
    m_pageInfo = NULL;
    m_pagePass = NULL;
    m_pageDone = NULL;
////@end wxGnuPGShellKeyGenWizard member initialisation
}


/*!
 * Control creation for wxGnuPGShellKeyGenWizard
 */

void wxGnuPGShellKeyGenWizard::CreateControls()
{
////@begin wxGnuPGShellKeyGenWizard content construction
    wxWizard* itemWizard1 = this;

    m_pageIntro = new wxGnuPGShellWizPageIntro( itemWizard1 );
    itemWizard1->GetPageAreaSizer()->Add(m_pageIntro);

    m_pageInfo = new wxGnuPGShellWizPageInfo( itemWizard1 );
    itemWizard1->GetPageAreaSizer()->Add(m_pageInfo);

    m_pagePass = new wxGnuPGShellWizPagePass( itemWizard1 );
    itemWizard1->GetPageAreaSizer()->Add(m_pagePass);

    m_pageDone = new wxGnuPGShellWizPageDone( itemWizard1 );
    itemWizard1->GetPageAreaSizer()->Add(m_pageDone);

    wxWizardPageSimple* lastPage = NULL;
    if (lastPage)
        wxWizardPageSimple::Chain(lastPage, m_pageIntro);
    lastPage = m_pageIntro;
    if (lastPage)
        wxWizardPageSimple::Chain(lastPage, m_pageInfo);
    lastPage = m_pageInfo;
    if (lastPage)
        wxWizardPageSimple::Chain(lastPage, m_pagePass);
    lastPage = m_pagePass;
    if (lastPage)
        wxWizardPageSimple::Chain(lastPage, m_pageDone);
    lastPage = m_pageDone;
////@end wxGnuPGShellKeyGenWizard content construction
}


/*!
 * Runs the wizard.
 */

bool wxGnuPGShellKeyGenWizard::Run()
{
    wxWindowList::compatibility_iterator node = GetChildren().GetFirst();
    while (node)
    {
        wxWizardPage* startPage = wxDynamicCast(node->GetData(), wxWizardPage);
        if (startPage) return RunWizard(startPage);
        node = node->GetNext();
    }
    return false;
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellKeyGenWizard::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellKeyGenWizard::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellKeyGenWizard bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("wizard.xpm"))
    {
        wxBitmap bitmap(wizard_xpm);
        return bitmap;
    }
    return wxNullBitmap;
////@end wxGnuPGShellKeyGenWizard bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellKeyGenWizard::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellKeyGenWizard icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellKeyGenWizard icon retrieval
}


/*!
 * wxGnuPGShellWizPageUserType type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPageUserType, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPageUserType event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageUserType, wxWizardPageSimple )

////@begin wxGnuPGShellWizPageUserType event table entries
////@end wxGnuPGShellWizPageUserType event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPageUserType constructors
 */

wxGnuPGShellWizPageUserType::wxGnuPGShellWizPageUserType()
{
    Init();
}

wxGnuPGShellWizPageUserType::wxGnuPGShellWizPageUserType( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * WizardPage creator
 */

bool wxGnuPGShellWizPageUserType::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPageUserType creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPageUserType creation
    return true;
}


/*!
 * wxGnuPGShellWizPageUserType destructor
 */

wxGnuPGShellWizPageUserType::~wxGnuPGShellWizPageUserType()
{
////@begin wxGnuPGShellWizPageUserType destruction
////@end wxGnuPGShellWizPageUserType destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPageUserType::Init()
{
////@begin wxGnuPGShellWizPageUserType member initialisation
////@end wxGnuPGShellWizPageUserType member initialisation
}


/*!
 * Control creation for WizardPage
 */

void wxGnuPGShellWizPageUserType::CreateControls()
{
////@begin wxGnuPGShellWizPageUserType content construction
    wxGnuPGShellWizPageUserType* itemWizardPageSimple2 = this;

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemWizardPageSimple2->SetSizer(itemBoxSizer3);

    wxStaticText* itemStaticText4 = new wxStaticText( itemWizardPageSimple2, wxID_STATIC, _("User Type"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText4->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer3->Add(itemStaticText4, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer5, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer5->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemWizardPageSimple2, wxID_STATIC, _("This assistant will help you configure PGP and initialize your keys."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    //wxStaticLine* itemStaticLine8 = new wxStaticLine( itemWizardPageSimple2, ID_WIZPAGEUSERTYPE_LINE, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    //itemBoxSizer3->Add(itemStaticLine8, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer9, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer9->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer9->Add(itemBoxSizer11, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemWizardPageSimple2, wxID_STATIC, _("Please select one."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(itemStaticText12, 0, wxGROW|wxALL, 5);

////@end wxGnuPGShellWizPageUserType content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPageUserType::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPageUserType::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPageUserType bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPageUserType bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageUserType::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPageUserType icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPageUserType icon retrieval
}


/*!
 * wxGnuPGShellWizPageIntro type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPageIntro, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPageIntro event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageIntro, wxWizardPageSimple )

////@begin wxGnuPGShellWizPageIntro event table entries
////@end wxGnuPGShellWizPageIntro event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPageIntro constructors
 */

wxGnuPGShellWizPageIntro::wxGnuPGShellWizPageIntro()
{
    Init();
}

wxGnuPGShellWizPageIntro::wxGnuPGShellWizPageIntro( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * WizardPage1 creator
 */

bool wxGnuPGShellWizPageIntro::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPageIntro creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPageIntro creation
    return true;
}


/*!
 * wxGnuPGShellWizPageIntro destructor
 */

wxGnuPGShellWizPageIntro::~wxGnuPGShellWizPageIntro()
{
////@begin wxGnuPGShellWizPageIntro destruction
////@end wxGnuPGShellWizPageIntro destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPageIntro::Init()
{
////@begin wxGnuPGShellWizPageIntro member initialisation
////@end wxGnuPGShellWizPageIntro member initialisation
}


/*!
 * Control creation for WizardPage1
 */

void wxGnuPGShellWizPageIntro::CreateControls()
{
////@begin wxGnuPGShellWizPageIntro content construction
    wxGnuPGShellWizPageIntro* itemWizardPageSimple2 = this;

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemWizardPageSimple2->SetSizer(itemBoxSizer3);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer4->Add(itemBoxSizer6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemWizardPageSimple2, wxID_STATIC, _("PGP Key Generation Assistant"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText7->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer6->Add(5, 5, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemWizardPageSimple2, wxID_STATIC, _("This assistant will help you generate new PGP key."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemStaticText9, 0, wxALIGN_LEFT|wxALL, 5);

////@end wxGnuPGShellWizPageIntro content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPageIntro::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPageIntro::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPageIntro bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPageIntro bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageIntro::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPageIntro icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPageIntro icon retrieval
}


/*!
 * wxGnuPGShellWizPageInfo type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPageInfo, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPageInfo event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageInfo, wxWizardPageSimple )

////@begin wxGnuPGShellWizPageInfo event table entries
    EVT_WIZARD_PAGE_CHANGING( -1, wxGnuPGShellWizPageInfo::OnWizpageInfoPageChanging )

    EVT_BUTTON( ID_WIZPAGEINFO_BTN_ADVANCED, wxGnuPGShellWizPageInfo::OnWizpageinfoBtnAdvancedClick )

////@end wxGnuPGShellWizPageInfo event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPageInfo constructors
 */

wxGnuPGShellWizPageInfo::wxGnuPGShellWizPageInfo()
: m_showMore(false)
{
    Init();
}

wxGnuPGShellWizPageInfo::wxGnuPGShellWizPageInfo( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * wxGnuPGShellWizPageInfo creator
 */

bool wxGnuPGShellWizPageInfo::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPageInfo creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPageInfo creation
    return true;
}


/*!
 * wxGnuPGShellWizPageInfo destructor
 */

wxGnuPGShellWizPageInfo::~wxGnuPGShellWizPageInfo()
{
////@begin wxGnuPGShellWizPageInfo destruction
////@end wxGnuPGShellWizPageInfo destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPageInfo::Init()
{
////@begin wxGnuPGShellWizPageInfo member initialisation
    m_fullName = NULL;
    m_primaryEmail = NULL;
    m_comment = NULL;
////@end wxGnuPGShellWizPageInfo member initialisation
}


/*!
 * Control creation for wxGnuPGShellWizPageInfo
 */

void wxGnuPGShellWizPageInfo::CreateControls()
{
////@begin wxGnuPGShellWizPageInfo content construction
    wxGnuPGShellWizPageInfo* itemWizardPageSimple10 = this;

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxVERTICAL);
    itemWizardPageSimple10->SetSizer(itemBoxSizer11);

    wxStaticText* itemStaticText12 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("Name and Email Assignment"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText12->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer11->Add(itemStaticText12, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer11->Add(itemBoxSizer13, 0, wxGROW|wxALL, 5);

    itemBoxSizer13->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText15 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("Every key pair must have a name associated with it. The name and Email address let your correspondents know that the public key they are using belongs to you."), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText15->Wrap(400);
    itemBoxSizer13->Add(itemStaticText15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine16 = new wxStaticLine( itemWizardPageSimple10, ID_STATICLINE3, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer11->Add(itemStaticLine16, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer11->Add(itemBoxSizer17, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer17->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer17->Add(itemBoxSizer19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer20 = new wxFlexGridSizer(5, 3, 0, 0);
    itemFlexGridSizer20->AddGrowableCol(2);
    itemBoxSizer19->Add(itemFlexGridSizer20, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText21 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("Full Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer20->Add(itemStaticText21, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_fullName = new wxTextCtrl( itemWizardPageSimple10, ID_WIZPAGEINFO_FULLNAME, _("New Name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer20->Add(m_fullName, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer20->Add(5, 5, 1, wxGROW|wxGROW|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer20->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxStaticText* itemStaticText25 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("(Name must be at least 5 characters long)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText25->SetFont(wxFont(8, wxSWISS, wxITALIC, wxNORMAL, false, wxT("Tahoma")));
    itemFlexGridSizer20->Add(itemStaticText25, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 0);

    itemFlexGridSizer20->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxStaticText* itemStaticText27 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("Primary Email:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer20->Add(itemStaticText27, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_primaryEmail = new wxTextCtrl( itemWizardPageSimple10, ID_WIZPAGEINFO_EMAIL, _("user@host.com"), wxDefaultPosition, wxSize(200, -1), 0 );
    if (ShowToolTips())
        m_primaryEmail->SetToolTip(_("Email in user@host.domain format"));
    itemFlexGridSizer20->Add(m_primaryEmail, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer20->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText30 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer20->Add(itemStaticText30, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_comment = new wxTextCtrl( itemWizardPageSimple10, ID_WIZPAGEINFO_COMMENT, _("New Key"), wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer20->Add(m_comment, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer20->Add(5, 5, 1, wxGROW|wxGROW|wxALL, 5);

    wxStaticText* itemStaticText33 = new wxStaticText( itemWizardPageSimple10, wxID_STATIC, _("Click advanced for more key settings."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer19->Add(itemStaticText33, 0, wxALIGN_LEFT|wxALL, 5);

    wxButton* itemButton34 = new wxButton( itemWizardPageSimple10, ID_WIZPAGEINFO_BTN_ADVANCED, _("Ad&vanced..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer19->Add(itemButton34, 0, wxALIGN_LEFT|wxALL, 5);

////@end wxGnuPGShellWizPageInfo content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPageInfo::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPageInfo::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPageInfo bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPageInfo bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageInfo::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPageInfo icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPageInfo icon retrieval
}


/*!
 * wxGnuPGShellWizPagePass type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPagePass, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPagePass event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPagePass, wxWizardPageSimple )

////@begin wxGnuPGShellWizPagePass event table entries
    EVT_WIZARD_PAGE_CHANGING( -1, wxGnuPGShellWizPagePass::OnWizpagePassPageChanging )

    EVT_TEXT( ID_WIZPAGEPASS_PASSPHRASE, wxGnuPGShellWizPagePass::OnWizpagepassPassphraseUpdated )

////@end wxGnuPGShellWizPagePass event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPagePass constructors
 */

wxGnuPGShellWizPagePass::wxGnuPGShellWizPagePass()
{
    Init();
}

wxGnuPGShellWizPagePass::wxGnuPGShellWizPagePass( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * wxGnuPGShellWizPagePass creator
 */

bool wxGnuPGShellWizPagePass::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPagePass creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPagePass creation
    return true;
}


/*!
 * wxGnuPGShellWizPagePass destructor
 */

wxGnuPGShellWizPagePass::~wxGnuPGShellWizPagePass()
{
////@begin wxGnuPGShellWizPagePass destruction
////@end wxGnuPGShellWizPagePass destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPagePass::Init()
{
////@begin wxGnuPGShellWizPagePass member initialisation
    m_passPhrase = NULL;
    m_passConfirmation = NULL;
////@end wxGnuPGShellWizPagePass member initialisation
}


/*!
 * Control creation for wxGnuPGShellWizPagePass
 */

void wxGnuPGShellWizPagePass::CreateControls()
{
////@begin wxGnuPGShellWizPagePass content construction
    wxGnuPGShellWizPagePass* itemWizardPageSimple35 = this;

    wxBoxSizer* itemBoxSizer36 = new wxBoxSizer(wxVERTICAL);
    itemWizardPageSimple35->SetSizer(itemBoxSizer36);

    wxStaticText* itemStaticText37 = new wxStaticText( itemWizardPageSimple35, wxID_STATIC, _("Passphrase Assignment"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText37->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer36->Add(itemStaticText37, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer38 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer38, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer38->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText40 = new wxStaticText( itemWizardPageSimple35, wxID_STATIC, _("Your private key will be protected by a passphrase. It is important to keep this passprase secret and do not write it down."), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText40->Wrap(400);
    itemBoxSizer38->Add(itemStaticText40, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine41 = new wxStaticLine( itemWizardPageSimple35, ID_STATICLINE4, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer36->Add(itemStaticLine41, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer42 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer42, 0, wxGROW|wxALL, 5);

    itemBoxSizer42->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer42->Add(itemBoxSizer44, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText45 = new wxStaticText( itemWizardPageSimple35, wxID_STATIC, _("Your passphrase should be at least 8 characters long and should contain non-alphabetic characters."), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText45->Wrap(350);
    itemBoxSizer44->Add(itemStaticText45, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer46 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer44->Add(itemBoxSizer46, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    itemBoxSizer46->Add(10, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText48 = new wxStaticText( itemWizardPageSimple35, wxID_STATIC, _("&Passphrase:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer46->Add(itemStaticText48, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_passPhrase = new wxTextCtrl( itemWizardPageSimple35, ID_WIZPAGEPASS_PASSPHRASE, _T(""), wxDefaultPosition, wxSize(-1, 50), wxTE_MULTILINE|wxTE_PASSWORD );
    itemBoxSizer46->Add(m_passPhrase, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer50 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer44->Add(itemBoxSizer50, 0, wxGROW|wxALL, 5);

    itemBoxSizer50->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText52 = new wxStaticText( itemWizardPageSimple35, wxID_STATIC, _("&Confirmation:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer50->Add(itemStaticText52, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_passConfirmation = new wxTextCtrl( itemWizardPageSimple35, ID_WIZPAGEPASS_CONFIRMATION, _T(""), wxDefaultPosition, wxSize(-1, 50), wxTE_MULTILINE|wxTE_PASSWORD );
    itemBoxSizer50->Add(m_passConfirmation, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end wxGnuPGShellWizPagePass content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPagePass::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPagePass::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPagePass bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPagePass bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPagePass::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPagePass icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPagePass icon retrieval
}


/*!
 * wxGnuPGShellWizPagePassPrpoblem type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPagePassPrpoblem, wxWizardPage )


/*!
 * wxGnuPGShellWizPagePassPrpoblem event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPagePassPrpoblem, wxWizardPage )

////@begin wxGnuPGShellWizPagePassPrpoblem event table entries
////@end wxGnuPGShellWizPagePassPrpoblem event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPagePassPrpoblem constructors
 */

wxGnuPGShellWizPagePassPrpoblem::wxGnuPGShellWizPagePassPrpoblem()
{
    Init();
}

wxGnuPGShellWizPagePassPrpoblem::wxGnuPGShellWizPagePassPrpoblem( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * wxGnuPGShellWizPagePassPrpoblem creator
 */

bool wxGnuPGShellWizPagePassPrpoblem::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPagePassPrpoblem creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPage::Create( parent, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPagePassPrpoblem creation
    return true;
}


/*!
 * wxGnuPGShellWizPagePassPrpoblem destructor
 */

wxGnuPGShellWizPagePassPrpoblem::~wxGnuPGShellWizPagePassPrpoblem()
{
////@begin wxGnuPGShellWizPagePassPrpoblem destruction
////@end wxGnuPGShellWizPagePassPrpoblem destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPagePassPrpoblem::Init()
{
////@begin wxGnuPGShellWizPagePassPrpoblem member initialisation
////@end wxGnuPGShellWizPagePassPrpoblem member initialisation
}


/*!
 * Control creation for wxGnuPGShellWizPagePassPrpoblem
 */

void wxGnuPGShellWizPagePassPrpoblem::CreateControls()
{
////@begin wxGnuPGShellWizPagePassPrpoblem content construction
    wxGnuPGShellWizPagePassPrpoblem* itemWizardPage63 = this;

    wxBoxSizer* itemBoxSizer64 = new wxBoxSizer(wxVERTICAL);
    itemWizardPage63->SetSizer(itemBoxSizer64);

    wxStaticText* itemStaticText65 = new wxStaticText( itemWizardPage63, wxID_STATIC, _("Passphrase Problem"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText65->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer64->Add(itemStaticText65, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer66 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer64->Add(itemBoxSizer66, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer66->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText68 = new wxStaticText( itemWizardPage63, wxID_STATIC, _("Your passphrase is potential security hazard because of the following:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer66->Add(itemStaticText68, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer70 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer64->Add(itemBoxSizer70, 0, wxGROW|wxALL, 5);

    itemBoxSizer70->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer72 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer70->Add(itemBoxSizer72, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end wxGnuPGShellWizPagePassPrpoblem content construction
}


/*!
 * Gets the previous page.
 */

wxWizardPage* wxGnuPGShellWizPagePassPrpoblem::GetPrev() const
{
    // TODO: return the previous page
    return NULL;
}


/*!
 * Gets the next page.
 */

wxWizardPage* wxGnuPGShellWizPagePassPrpoblem::GetNext() const
{
    // TODO: return the next page
    return NULL;
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPagePassPrpoblem::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPagePassPrpoblem::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPagePassPrpoblem bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPagePassPrpoblem bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPagePassPrpoblem::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPagePassPrpoblem icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPagePassPrpoblem icon retrieval
}


/*!
 * wxGnuPGShellWizPageKeyGen type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPageKeyGen, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPageKeyGen event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageKeyGen, wxWizardPageSimple )

////@begin wxGnuPGShellWizPageKeyGen event table entries
////@end wxGnuPGShellWizPageKeyGen event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPageKeyGen constructors
 */

wxGnuPGShellWizPageKeyGen::wxGnuPGShellWizPageKeyGen()
{
    Init();
}

wxGnuPGShellWizPageKeyGen::wxGnuPGShellWizPageKeyGen( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * wxGnuPGShellWizPageKeyGen creator
 */

bool wxGnuPGShellWizPageKeyGen::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPageKeyGen creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPageKeyGen creation
    return true;
}


/*!
 * wxGnuPGShellWizPageKeyGen destructor
 */

wxGnuPGShellWizPageKeyGen::~wxGnuPGShellWizPageKeyGen()
{
////@begin wxGnuPGShellWizPageKeyGen destruction
////@end wxGnuPGShellWizPageKeyGen destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPageKeyGen::Init()
{
////@begin wxGnuPGShellWizPageKeyGen member initialisation
    m_overallStatus = NULL;
////@end wxGnuPGShellWizPageKeyGen member initialisation
}


/*!
 * Control creation for wxGnuPGShellWizPageKeyGen
 */

void wxGnuPGShellWizPageKeyGen::CreateControls()
{
////@begin wxGnuPGShellWizPageKeyGen content construction
////@end wxGnuPGShellWizPageKeyGen content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPageKeyGen::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPageKeyGen::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPageKeyGen bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPageKeyGen bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageKeyGen::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPageKeyGen icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPageKeyGen icon retrieval
}


/*!
 * wxGnuPGShellWizPageDone type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPageDone, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPageDone event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageDone, wxWizardPageSimple )

////@begin wxGnuPGShellWizPageDone event table entries
////@end wxGnuPGShellWizPageDone event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPageDone constructors
 */

wxGnuPGShellWizPageDone::wxGnuPGShellWizPageDone()
{
    Init();
}

wxGnuPGShellWizPageDone::wxGnuPGShellWizPageDone( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * wxGnuPGShellWizPageDone creator
 */

bool wxGnuPGShellWizPageDone::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPageDone creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPageDone creation
    return true;
}


/*!
 * wxGnuPGShellWizPageDone destructor
 */

wxGnuPGShellWizPageDone::~wxGnuPGShellWizPageDone()
{
////@begin wxGnuPGShellWizPageDone destruction
////@end wxGnuPGShellWizPageDone destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPageDone::Init()
{
////@begin wxGnuPGShellWizPageDone member initialisation
////@end wxGnuPGShellWizPageDone member initialisation
}


/*!
 * Control creation for wxGnuPGShellWizPageDone
 */

void wxGnuPGShellWizPageDone::CreateControls()
{
////@begin wxGnuPGShellWizPageDone content construction
    wxGnuPGShellWizPageDone* itemWizardPageSimple54 = this;

    wxBoxSizer* itemBoxSizer55 = new wxBoxSizer(wxVERTICAL);
    itemWizardPageSimple54->SetSizer(itemBoxSizer55);

    wxStaticText* itemStaticText56 = new wxStaticText( itemWizardPageSimple54, wxID_STATIC, _("Congratulations!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText56->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer55->Add(itemStaticText56, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer57 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer55->Add(itemBoxSizer57, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer57->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText59 = new wxStaticText( itemWizardPageSimple54, wxID_STATIC, _("All required information has been collected."), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText59->Wrap(400);
    itemBoxSizer57->Add(itemStaticText59, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine60 = new wxStaticLine( itemWizardPageSimple54, ID_STATICLINE7, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer55->Add(itemStaticLine60, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer61 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer55->Add(itemBoxSizer61, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer61->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText63 = new wxStaticText( itemWizardPageSimple54, wxID_STATIC, _(" Your new key will generated after Finish button press."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer61->Add(itemStaticText63, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end wxGnuPGShellWizPageDone content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPageDone::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPageDone::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPageDone bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPageDone bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageDone::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPageDone icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPageDone icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_WIZPAGEINFO_BTN_ADVANCED
 */

// Show advanced key settings dialog
void wxGnuPGShellWizPageInfo::OnWizpageinfoBtnAdvancedClick( wxCommandEvent& event )
{
    wxGnuPGShellAdvKeySettings *advancedKeySettingsDlg = new wxGnuPGShellAdvKeySettings(GetParent());
    if (advancedKeySettingsDlg->ShowModal()  == wxID_OK) {
        wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_keyType = advancedKeySettingsDlg->m_keyType->GetLabel();
        wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_expire = advancedKeySettingsDlg->GetExpirationString();
        wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_size = advancedKeySettingsDlg->m_keySize->GetValue();
        wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_isSepareteSignKey = advancedKeySettingsDlg->m_generateSeparateFlag->GetValue();
    }
    advancedKeySettingsDlg->Destroy();
}


/*!
 * wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WXGNUPGSHELLKEYGENWIZARD
 */

void wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardPageChanging( wxWizardEvent& event )
{
////@begin wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WXGNUPGSHELLKEYGENWIZARD in wxGnuPGShellKeyGenWizard.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WXGNUPGSHELLKEYGENWIZARD in wxGnuPGShellKeyGenWizard.
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_WIZPAGEPASS_PASSPHRASE
 */

void wxGnuPGShellWizPagePass::OnWizpagepassPassphraseUpdated( wxCommandEvent& event )
{
    //TODO: check for length
////@begin wxEVT_COMMAND_TEXT_UPDATED event handler for ID_WIZPAGEPASS_PASSPHRASE in wxGnuPGShellWizPagePass.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_TEXT_UPDATED event handler for ID_WIZPAGEPASS_PASSPHRASE in wxGnuPGShellWizPagePass.
}


/*!
 * wxEVT_WIZARD_CANCEL event handler for ID_WXGNUPGSHELLKEYGENWIZARD
 */

void wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardCancel( wxWizardEvent& event )
{
    if ( wxMessageBox(_("Do you really want to cancel key generation?"), _("Cancel key generation wizard"),
        wxICON_QUESTION | wxYES_NO, this) != wxYES )
    {
        // not confirmed
        event.Veto();
    }
}


/*!
 * wxEVT_WIZARD_FINISHED event handler for ID_WXGNUPGSHELLKEYGENWIZARD
 */

void wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardFinished( wxWizardEvent& event )
{
////@begin wxEVT_WIZARD_FINISHED event handler for ID_WXGNUPGSHELLKEYGENWIZARD in wxGnuPGShellKeyGenWizard.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_WIZARD_FINISHED event handler for ID_WXGNUPGSHELLKEYGENWIZARD in wxGnuPGShellKeyGenWizard.
}


/*!
 * wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WIZPAGE_INFO
 */

void wxGnuPGShellWizPageInfo::OnWizpageInfoPageChanging( wxWizardEvent& event )
{
    if (m_primaryEmail->GetValue().Find(wxT("@")) == wxNOT_FOUND ) {
        wxMessageBox(_("Invalid e-mail"), _("Error"), wxOK);
        event.Veto();
    } else {
        if (m_fullName->GetValue().Len() < 5) {
            wxMessageBox(_("Full name is too short!"), _("Error"), wxOK);
            event.Veto();
        } else {
            wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_name = m_fullName->GetValue();
            wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_email = m_primaryEmail->GetValue();
            wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_comment = m_comment->GetValue();
            return;
        }
    }
} /* OnWizpageInfoPageChanging */


/*!
 * wxEVT_WIZARD_PAGE_CHANGING event handler for ID_WIZPAGE_PASS
 */

void wxGnuPGShellWizPagePass::OnWizpagePassPageChanging( wxWizardEvent& event )
{
    if (m_passPhrase->GetValue().Len() < 3) {
        wxMessageBox(_("Passphrase is too short! Enter at least 3 chars."), _("Error"), wxOK);
        event.Veto();
    } else {
        if (m_passPhrase->GetValue() != m_passConfirmation->GetValue()) {
            wxMessageBox(_("Passphrase and confirmation missmaches!"), _("Error"), wxOK);
            event.Veto();
        } else {
            wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_pass = m_passPhrase->GetValue();
            return;
        }
    }
}

/*!
 * wxGnuPGShellWizPageDone1 type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellWizPageDone1, wxWizardPageSimple )


/*!
 * wxGnuPGShellWizPageDone1 event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageDone1, wxWizardPageSimple )

////@begin wxGnuPGShellWizPageDone1 event table entries
////@end wxGnuPGShellWizPageDone1 event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellWizPageDone1 constructors
 */

wxGnuPGShellWizPageDone1::wxGnuPGShellWizPageDone1()
{
    Init();
}

wxGnuPGShellWizPageDone1::wxGnuPGShellWizPageDone1( wxWizard* parent )
{
    Init();
    Create( parent );
}


/*!
 * wxGnuPGShellWizPageDone1 creator
 */

bool wxGnuPGShellWizPageDone1::Create( wxWizard* parent )
{
////@begin wxGnuPGShellWizPageDone1 creation
    wxBitmap wizardBitmap(wxNullBitmap);
    wxWizardPageSimple::Create( parent, NULL, NULL, wizardBitmap );

    CreateControls();
    if (GetSizer())
        GetSizer()->Fit(this);
////@end wxGnuPGShellWizPageDone1 creation
    return true;
}


/*!
 * wxGnuPGShellWizPageDone1 destructor
 */

wxGnuPGShellWizPageDone1::~wxGnuPGShellWizPageDone1()
{
////@begin wxGnuPGShellWizPageDone1 destruction
////@end wxGnuPGShellWizPageDone1 destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellWizPageDone1::Init()
{
////@begin wxGnuPGShellWizPageDone1 member initialisation
////@end wxGnuPGShellWizPageDone1 member initialisation
}


/*!
 * Control creation for wxGnuPGShellWizPageDone1
 */

void wxGnuPGShellWizPageDone1::CreateControls()
{
////@begin wxGnuPGShellWizPageDone1 content construction
    wxGnuPGShellWizPageDone1* itemWizardPageSimple41 = this;

    wxBoxSizer* itemBoxSizer42 = new wxBoxSizer(wxVERTICAL);
    itemWizardPageSimple41->SetSizer(itemBoxSizer42);

    wxStaticText* itemStaticText43 = new wxStaticText( itemWizardPageSimple41, wxID_STATIC, _("Congratulations!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText43->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer42->Add(itemStaticText43, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer42->Add(itemBoxSizer44, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer44->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText46 = new wxStaticText( itemWizardPageSimple41, wxID_STATIC, _("All required information has been collected."), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText46->Wrap(400);
    itemBoxSizer44->Add(itemStaticText46, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer48 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer42->Add(itemBoxSizer48, 0, wxALIGN_LEFT|wxALL, 5);

    itemBoxSizer48->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText50 = new wxStaticText( itemWizardPageSimple41, wxID_STATIC, _(" Your new key will generated after Finish button press."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer48->Add(itemStaticText50, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end wxGnuPGShellWizPageDone1 content construction
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellWizPageDone1::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellWizPageDone1::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellWizPageDone1 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellWizPageDone1 bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageDone1::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellWizPageDone1 icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellWizPageDone1 icon retrieval
}
