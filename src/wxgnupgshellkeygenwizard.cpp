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

#include "wxgnupgshellkeygenwizard.h"
#include "wxgnupgshelladvkeysettings.h"
#include "app_resources.h"

// Resources
#include "wizard.xpm"

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellKeyGenWizard, wxWizard)
BEGIN_EVENT_TABLE( wxGnuPGShellKeyGenWizard, wxWizard )

EVT_WIZARD_PAGE_CHANGING( ID_WXGNUPGSHELLKEYGENWIZARD, wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardPageChanging )
EVT_WIZARD_CANCEL( ID_WXGNUPGSHELLKEYGENWIZARD, wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardCancel )
EVT_WIZARD_FINISHED( ID_WXGNUPGSHELLKEYGENWIZARD, wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardFinished )

END_EVENT_TABLE()

wxGnuPGShellKeyGenWizard::wxGnuPGShellKeyGenWizard() {
	Init();
}

wxGnuPGShellKeyGenWizard::wxGnuPGShellKeyGenWizard(wxWindow *parent,
		wxWindowID id, const wxPoint &pos) {
	Init();
	Create(parent, id, pos);
}

bool wxGnuPGShellKeyGenWizard::Create(wxWindow *parent, wxWindowID id,
		const wxPoint &pos) {
	SetExtraStyle(wxWIZARD_EX_HELPBUTTON);
	wxBitmap wizardBitmap(GetBitmapResource(wxT("wizard.xpm")));
	wxWizard::Create(parent, id, _("PGP Key Generation Assistant"),
			wizardBitmap, pos, wxCAPTION | wxRESIZE_BORDER);

	CreateControls();

	m_name = wxT("");
	m_email = wxT("user@mail.com");
	m_comment = wxT("");
	m_pass = wxT("");
	m_size = wxT("2048");
	m_keyType = wxT("DSA");
	wxString m_expire = wxT("0");

	return true;
}

wxGnuPGShellKeyGenWizard::~wxGnuPGShellKeyGenWizard() {
}

/*!
 * Member initialisation
 */

void wxGnuPGShellKeyGenWizard::Init() {
	m_pageIntro = NULL;
	m_pageInfo = NULL;
	m_pagePass = NULL;
	m_pageDone = NULL;
}

void wxGnuPGShellKeyGenWizard::CreateControls() {
////@begin wxGnuPGShellKeyGenWizard content construction
	wxWizard *itemWizard1 = this;

	m_pageIntro = new wxGnuPGShellWizPageIntro(itemWizard1);
	itemWizard1->GetPageAreaSizer()->Add(m_pageIntro);

	m_pageInfo = new wxGnuPGShellWizPageInfo(itemWizard1);
	itemWizard1->GetPageAreaSizer()->Add(m_pageInfo);

	m_pagePass = new wxGnuPGShellWizPagePass(itemWizard1);
	itemWizard1->GetPageAreaSizer()->Add(m_pagePass);

	m_pageDone = new wxGnuPGShellWizPageDone(itemWizard1);
	itemWizard1->GetPageAreaSizer()->Add(m_pageDone);

	wxWizardPageSimple *lastPage = NULL;
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
}

bool wxGnuPGShellKeyGenWizard::Run() {
	wxWindowList::compatibility_iterator node = GetChildren().GetFirst();
	while (node) {
		wxWizardPage *startPage = wxDynamicCast(node->GetData(), wxWizardPage);
		if (startPage)
			return RunWizard(startPage);
		node = node->GetNext();
	}
	return false;
}

bool wxGnuPGShellKeyGenWizard::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellKeyGenWizard::GetBitmapResource(const wxString &name) {
	wxUnusedVar(name);
	if (name == _T("wizard.xpm")) {
		wxBitmap bitmap(wizard_xpm);
		return bitmap;
	}
	return wxNullBitmap;
}

wxIcon wxGnuPGShellKeyGenWizard::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPageUserType, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageUserType, wxWizardPageSimple ) END_EVENT_TABLE()

wxGnuPGShellWizPageUserType::wxGnuPGShellWizPageUserType() {
	Init();
}

wxGnuPGShellWizPageUserType::wxGnuPGShellWizPageUserType(wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPageUserType::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPageUserType::~wxGnuPGShellWizPageUserType() {
////@begin wxGnuPGShellWizPageUserType destruction
////@end wxGnuPGShellWizPageUserType destruction
}

void wxGnuPGShellWizPageUserType::Init() {
////@begin wxGnuPGShellWizPageUserType member initialisation
////@end wxGnuPGShellWizPageUserType member initialisation
}

void wxGnuPGShellWizPageUserType::CreateControls() {
////@begin wxGnuPGShellWizPageUserType content construction
	wxGnuPGShellWizPageUserType *itemWizardPageSimple2 = this;

	wxBoxSizer *itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
	itemWizardPageSimple2->SetSizer(itemBoxSizer3);

	wxStaticText *itemStaticText4 = new wxStaticText(itemWizardPageSimple2,
			wxID_STATIC, _("User Type"), wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText4->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer3->Add(itemStaticText4, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer3->Add(itemBoxSizer5, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer5->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText7 =
			new wxStaticText(itemWizardPageSimple2, wxID_STATIC,
					_(
							"This assistant will help you configure PGP and initialize your keys."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer5->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	//wxStaticLine* itemStaticLine8 = new wxStaticLine( itemWizardPageSimple2, ID_WIZPAGEUSERTYPE_LINE, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	//itemBoxSizer3->Add(itemStaticLine8, 0, wxGROW|wxALL, 5);

	wxBoxSizer *itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer3->Add(itemBoxSizer9, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer9->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer11 = new wxBoxSizer(wxVERTICAL);
	itemBoxSizer9->Add(itemBoxSizer11, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText12 = new wxStaticText(itemWizardPageSimple2,
			wxID_STATIC, _("Please select one."), wxDefaultPosition,
			wxDefaultSize, 0);
	itemBoxSizer11->Add(itemStaticText12, 0, wxGROW | wxALL, 5);
}

bool wxGnuPGShellWizPageUserType::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPageUserType::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellWizPageUserType::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

/*!
 * wxGnuPGShellWizPageIntro type definition
 */

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPageIntro, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageIntro, wxWizardPageSimple ) END_EVENT_TABLE()

wxGnuPGShellWizPageIntro::wxGnuPGShellWizPageIntro() {
	Init();
}

wxGnuPGShellWizPageIntro::wxGnuPGShellWizPageIntro(wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPageIntro::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPageIntro::~wxGnuPGShellWizPageIntro() {
}

void wxGnuPGShellWizPageIntro::Init() {
}

void wxGnuPGShellWizPageIntro::CreateControls() {
	wxGnuPGShellWizPageIntro *itemWizardPageSimple2 = this;

	wxBoxSizer *itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
	itemWizardPageSimple2->SetSizer(itemBoxSizer3);

	wxBoxSizer *itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer6 = new wxBoxSizer(wxVERTICAL);
	itemBoxSizer4->Add(itemBoxSizer6, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText7 = new wxStaticText(itemWizardPageSimple2,
			wxID_STATIC, _("PGP Key Generation Assistant"), wxDefaultPosition,
			wxDefaultSize, 0);
	itemStaticText7->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer6->Add(5, 5, 0, wxALIGN_LEFT | wxALL, 5);

	wxStaticText *itemStaticText9 = new wxStaticText(itemWizardPageSimple2,
			wxID_STATIC,
			_("This assistant will help you generate new PGP key."),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer6->Add(itemStaticText9, 0, wxALIGN_LEFT | wxALL, 5);
}

bool wxGnuPGShellWizPageIntro::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPageIntro::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPageIntro::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPageInfo, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageInfo, wxWizardPageSimple ) EVT_WIZARD_PAGE_CHANGING( -1, wxGnuPGShellWizPageInfo::OnWizpageInfoPageChanging )
EVT_BUTTON(ID_WIZPAGEINFO_BTN_ADVANCED,
		wxGnuPGShellWizPageInfo::OnWizpageinfoBtnAdvancedClick)
END_EVENT_TABLE()

wxGnuPGShellWizPageInfo::wxGnuPGShellWizPageInfo() :
		m_showMore(false) {
	Init();
}

wxGnuPGShellWizPageInfo::wxGnuPGShellWizPageInfo(wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPageInfo::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPageInfo::~wxGnuPGShellWizPageInfo() {
}

void wxGnuPGShellWizPageInfo::Init() {
	m_fullName = NULL;
	m_primaryEmail = NULL;
	m_comment = NULL;
}

void wxGnuPGShellWizPageInfo::CreateControls() {
	wxGnuPGShellWizPageInfo *itemWizardPageSimple10 = this;

	wxBoxSizer *itemBoxSizer11 = new wxBoxSizer(wxVERTICAL);
	itemWizardPageSimple10->SetSizer(itemBoxSizer11);

	wxStaticText *itemStaticText12 = new wxStaticText(itemWizardPageSimple10,
			wxID_STATIC, _("Name and Email Assignment"), wxDefaultPosition,
			wxDefaultSize, 0);
	itemStaticText12->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer11->Add(itemStaticText12, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer11->Add(itemBoxSizer13, 0, wxGROW | wxALL, 5);

	itemBoxSizer13->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText15 =
			new wxStaticText(itemWizardPageSimple10, wxID_STATIC,
					_(
							"Every key pair must have a name associated with it. The name and Email address let your correspondents know that the public key they are using belongs to you."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText15->Wrap(400);
	itemBoxSizer13->Add(itemStaticText15, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticLine *itemStaticLine16 = new wxStaticLine(itemWizardPageSimple10,
	ID_STATICLINE3, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer11->Add(itemStaticLine16, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer11->Add(itemBoxSizer17, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer17->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer19 = new wxBoxSizer(wxVERTICAL);
	itemBoxSizer17->Add(itemBoxSizer19, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxFlexGridSizer *itemFlexGridSizer20 = new wxFlexGridSizer(5, 3, 0, 0);
	itemFlexGridSizer20->AddGrowableCol(2);
	itemBoxSizer19->Add(itemFlexGridSizer20, 0, wxGROW | wxALL, 5);

	wxStaticText *itemStaticText21 = new wxStaticText(itemWizardPageSimple10,
			wxID_STATIC, _("Full Name:"), wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer20->Add(itemStaticText21, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_fullName = new wxTextCtrl(itemWizardPageSimple10, ID_WIZPAGEINFO_FULLNAME,
			_("New Name"), wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer20->Add(m_fullName, 0,
			wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	itemFlexGridSizer20->Add(5, 5, 1, wxGROW | wxGROW | wxLEFT | wxRIGHT, 5);

	itemFlexGridSizer20->Add(5, 5, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxLEFT
					| wxRIGHT, 5);

	wxStaticText *itemStaticText25 = new wxStaticText(itemWizardPageSimple10,
			wxID_STATIC, _("(Name must be at least 5 characters long)"),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText25->SetFont(
			wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC,
					wxFONTWEIGHT_NORMAL, false, FONT_NAME_TAHOMA));
	itemFlexGridSizer20->Add(itemStaticText25, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxLEFT
					| wxRIGHT, 0);

	itemFlexGridSizer20->Add(5, 5, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxLEFT
					| wxRIGHT, 5);

	wxStaticText *itemStaticText27 = new wxStaticText(itemWizardPageSimple10,
			wxID_STATIC, _("Primary Email:"), wxDefaultPosition, wxDefaultSize,
			0);
	itemFlexGridSizer20->Add(itemStaticText27, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_primaryEmail = new wxTextCtrl(itemWizardPageSimple10,
	ID_WIZPAGEINFO_EMAIL, _("user@host.com"), wxDefaultPosition,
			wxSize(200, -1), 0);
	if (ShowToolTips())
		m_primaryEmail->SetToolTip(_("Email in user@host.domain format"));
	itemFlexGridSizer20->Add(m_primaryEmail, 1,
			wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	itemFlexGridSizer20->Add(5, 5, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText30 = new wxStaticText(itemWizardPageSimple10,
			wxID_STATIC, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0);
	itemFlexGridSizer20->Add(itemStaticText30, 0,
			wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_comment = new wxTextCtrl(itemWizardPageSimple10, ID_WIZPAGEINFO_COMMENT,
			_("New Key"), wxDefaultPosition, wxSize(200, -1), 0);
	itemFlexGridSizer20->Add(m_comment, 0,
			wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	itemFlexGridSizer20->Add(5, 5, 1, wxGROW | wxGROW | wxALL, 5);

	wxStaticText *itemStaticText33 = new wxStaticText(itemWizardPageSimple10,
			wxID_STATIC, _("Click advanced for more key settings."),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer19->Add(itemStaticText33, 0, wxALIGN_LEFT | wxALL, 5);

	wxButton *itemButton34 = new wxButton(itemWizardPageSimple10,
	ID_WIZPAGEINFO_BTN_ADVANCED, _("Ad&vanced..."), wxDefaultPosition,
			wxDefaultSize, 0);
	itemBoxSizer19->Add(itemButton34, 0, wxALIGN_LEFT | wxALL, 5);
}

bool wxGnuPGShellWizPageInfo::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPageInfo::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPageInfo::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPagePass, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPagePass, wxWizardPageSimple ) EVT_WIZARD_PAGE_CHANGING( -1, wxGnuPGShellWizPagePass::OnWizpagePassPageChanging )
EVT_TEXT(ID_WIZPAGEPASS_PASSPHRASE,
		wxGnuPGShellWizPagePass::OnWizpagepassPassphraseUpdated)
END_EVENT_TABLE()

wxGnuPGShellWizPagePass::wxGnuPGShellWizPagePass() {
	Init();
}

wxGnuPGShellWizPagePass::wxGnuPGShellWizPagePass(wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPagePass::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPagePass::~wxGnuPGShellWizPagePass() {
}

void wxGnuPGShellWizPagePass::Init() {
	m_passPhrase = NULL;
	m_passConfirmation = NULL;
}

void wxGnuPGShellWizPagePass::CreateControls() {
	wxGnuPGShellWizPagePass *itemWizardPageSimple35 = this;

	wxBoxSizer *itemBoxSizer36 = new wxBoxSizer(wxVERTICAL);
	itemWizardPageSimple35->SetSizer(itemBoxSizer36);

	wxStaticText *itemStaticText37 = new wxStaticText(itemWizardPageSimple35,
			wxID_STATIC, _("Passphrase Assignment"), wxDefaultPosition,
			wxDefaultSize, 0);
	itemStaticText37->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer36->Add(itemStaticText37, 0, wxALIGN_LEFT | wxALL, 5);

	wxBoxSizer *itemBoxSizer38 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer36->Add(itemBoxSizer38, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer38->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText40 =
			new wxStaticText(itemWizardPageSimple35, wxID_STATIC,
					_(
							"Your private key will be protected by a passphrase. It is important to keep this passprase secret and do not write it down."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText40->Wrap(400);
	itemBoxSizer38->Add(itemStaticText40, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticLine *itemStaticLine41 = new wxStaticLine(itemWizardPageSimple35,
	ID_STATICLINE4, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer36->Add(itemStaticLine41, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer42 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer36->Add(itemBoxSizer42, 0, wxGROW | wxALL, 5);

	itemBoxSizer42->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer44 = new wxBoxSizer(wxVERTICAL);
	itemBoxSizer42->Add(itemBoxSizer44, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText45 =
			new wxStaticText(itemWizardPageSimple35, wxID_STATIC,
					_(
							"Your passphrase should be at least 8 characters long and should contain non-alphabetic characters."),
					wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText45->Wrap(350);
	itemBoxSizer44->Add(itemStaticText45, 0, wxALIGN_CENTER_HORIZONTAL | wxALL,
			5);

	wxBoxSizer *itemBoxSizer46 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer44->Add(itemBoxSizer46, 0, wxGROW | wxLEFT | wxRIGHT, 5);

	itemBoxSizer46->Add(10, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText48 = new wxStaticText(itemWizardPageSimple35,
			wxID_STATIC, _("&Passphrase:"), wxDefaultPosition, wxDefaultSize,
			0);
	itemBoxSizer46->Add(itemStaticText48, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	m_passPhrase = new wxTextCtrl(itemWizardPageSimple35,
	ID_WIZPAGEPASS_PASSPHRASE, _T(""), wxDefaultPosition, wxSize(-1, 50),
	wxTE_MULTILINE | wxTE_PASSWORD);
	itemBoxSizer46->Add(m_passPhrase, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer50 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer44->Add(itemBoxSizer50, 0, wxGROW | wxALL, 5);

	itemBoxSizer50->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText52 = new wxStaticText(itemWizardPageSimple35,
			wxID_STATIC, _("&Confirmation:"), wxDefaultPosition, wxDefaultSize,
			0);
	itemBoxSizer50->Add(itemStaticText52, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	m_passConfirmation = new wxTextCtrl(itemWizardPageSimple35,
	ID_WIZPAGEPASS_CONFIRMATION, _T(""), wxDefaultPosition, wxSize(-1, 50),
	wxTE_MULTILINE | wxTE_PASSWORD);
	itemBoxSizer50->Add(m_passConfirmation, 1, wxALIGN_CENTER_VERTICAL | wxALL,
			5);
}

bool wxGnuPGShellWizPagePass::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPagePass::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPagePass::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPagePassPrpoblem, wxWizardPage)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPagePassPrpoblem, wxWizardPage )

END_EVENT_TABLE()

wxGnuPGShellWizPagePassPrpoblem::wxGnuPGShellWizPagePassPrpoblem() {
	Init();
}

wxGnuPGShellWizPagePassPrpoblem::wxGnuPGShellWizPagePassPrpoblem(
		wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPagePassPrpoblem::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPage::Create(parent, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPagePassPrpoblem::~wxGnuPGShellWizPagePassPrpoblem() {
}

void wxGnuPGShellWizPagePassPrpoblem::Init() {
}

void wxGnuPGShellWizPagePassPrpoblem::CreateControls() {
	wxGnuPGShellWizPagePassPrpoblem *itemWizardPage63 = this;

	wxBoxSizer *itemBoxSizer64 = new wxBoxSizer(wxVERTICAL);
	itemWizardPage63->SetSizer(itemBoxSizer64);

	wxStaticText *itemStaticText65 = new wxStaticText(itemWizardPage63,
			wxID_STATIC, _("Passphrase Problem"), wxDefaultPosition,
			wxDefaultSize, 0);
	itemStaticText65->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer64->Add(itemStaticText65, 0, wxALIGN_LEFT | wxALL, 5);

	wxBoxSizer *itemBoxSizer66 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer64->Add(itemBoxSizer66, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer66->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText68 =
			new wxStaticText(itemWizardPage63, wxID_STATIC,
					_(
							"Your passphrase is potential security hazard because of the following:"),
					wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer66->Add(itemStaticText68, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxBoxSizer *itemBoxSizer70 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer64->Add(itemBoxSizer70, 0, wxGROW | wxALL, 5);

	itemBoxSizer70->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *itemBoxSizer72 = new wxBoxSizer(wxVERTICAL);
	itemBoxSizer70->Add(itemBoxSizer72, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);
}

wxWizardPage* wxGnuPGShellWizPagePassPrpoblem::GetPrev() const {
	// TODO: return the previous page
	return NULL;
}

wxWizardPage* wxGnuPGShellWizPagePassPrpoblem::GetNext() const {
	// TODO: return the next page
	return NULL;
}

bool wxGnuPGShellWizPagePassPrpoblem::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPagePassPrpoblem::GetBitmapResource(
		const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPagePassPrpoblem::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPageKeyGen, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageKeyGen, wxWizardPageSimple )

END_EVENT_TABLE()

wxGnuPGShellWizPageKeyGen::wxGnuPGShellWizPageKeyGen() {
	Init();
}

wxGnuPGShellWizPageKeyGen::wxGnuPGShellWizPageKeyGen(wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPageKeyGen::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPageKeyGen::~wxGnuPGShellWizPageKeyGen() {
}


void wxGnuPGShellWizPageKeyGen::Init() {
	m_overallStatus = NULL;
}

void wxGnuPGShellWizPageKeyGen::CreateControls() {
}

bool wxGnuPGShellWizPageKeyGen::ShowToolTips() {
	return true;
}


wxBitmap wxGnuPGShellWizPageKeyGen::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPageKeyGen::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPageDone, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageDone, wxWizardPageSimple )

END_EVENT_TABLE()

wxGnuPGShellWizPageDone::wxGnuPGShellWizPageDone() {
	Init();
}

wxGnuPGShellWizPageDone::wxGnuPGShellWizPageDone(wxWizard *parent) {
	Init();
	Create(parent);
}

bool wxGnuPGShellWizPageDone::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()){
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPageDone::~wxGnuPGShellWizPageDone() {
}

void wxGnuPGShellWizPageDone::Init() {
}


void wxGnuPGShellWizPageDone::CreateControls() {
	wxGnuPGShellWizPageDone *itemWizardPageSimple54 = this;

	wxBoxSizer *itemBoxSizer55 = new wxBoxSizer(wxVERTICAL);
	itemWizardPageSimple54->SetSizer(itemBoxSizer55);

	wxStaticText *itemStaticText56 = new wxStaticText(itemWizardPageSimple54,
			wxID_STATIC, _("Congratulations!"), wxDefaultPosition,
			wxDefaultSize, 0);
	itemStaticText56->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer55->Add(itemStaticText56, 0, wxALIGN_LEFT | wxALL, 5);

	wxBoxSizer *itemBoxSizer57 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer55->Add(itemBoxSizer57, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer57->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText59 = new wxStaticText(itemWizardPageSimple54,
			wxID_STATIC, _("All required information has been collected."),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText59->Wrap(400);
	itemBoxSizer57->Add(itemStaticText59, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxStaticLine *itemStaticLine60 = new wxStaticLine(itemWizardPageSimple54,
	ID_STATICLINE7, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	itemBoxSizer55->Add(itemStaticLine60, 0, wxGROW | wxALL, 5);

	wxBoxSizer *itemBoxSizer61 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer55->Add(itemBoxSizer61, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer61->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText63 = new wxStaticText(itemWizardPageSimple54,
			wxID_STATIC,
			_(" Your new key will generated after Finish button press."),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer61->Add(itemStaticText63, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);
}

bool wxGnuPGShellWizPageDone::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPageDone::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPageDone::GetIconResource(const wxString &name) {
	// Icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
}


// Show advanced key settings dialog
void wxGnuPGShellWizPageInfo::OnWizpageinfoBtnAdvancedClick(
		wxCommandEvent &event) {
	wxGnuPGShellAdvKeySettings *advancedKeySettingsDlg =
			new wxGnuPGShellAdvKeySettings(GetParent());
	if (advancedKeySettingsDlg->ShowModal() == wxID_OK) {
		wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_keyType =
				advancedKeySettingsDlg->getKeyType();
		wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_expire =
				advancedKeySettingsDlg->GetExpirationString();
		wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_size =
				advancedKeySettingsDlg->m_keySize->GetValue();
		wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_isSepareteSignKey =
				advancedKeySettingsDlg->m_generateSeparateFlag->GetValue();
	}
	advancedKeySettingsDlg->Destroy();
}

void wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardPageChanging(
		wxWizardEvent &event) {
	// Before editing this code, remove the block markers.
	event.Skip();
}


void wxGnuPGShellWizPagePass::OnWizpagepassPassphraseUpdated(
		wxCommandEvent &event) {
	//TODO: check for length
	// Before editing this code, remove the block markers.
	event.Skip();
}


void wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardCancel(
		wxWizardEvent &event) {
	if (wxMessageBox(_("Do you really want to cancel key generation?"),
			_("Cancel key generation wizard"),
			wxICON_QUESTION | wxYES_NO, this) != wxYES) {
		// not confirmed
		event.Veto();
	}
}


void wxGnuPGShellKeyGenWizard::OnWxgnupgshellkeygenwizardFinished(
		wxWizardEvent &event) {
	// Before editing this code, remove the block markers.
	event.Skip();
}

void wxGnuPGShellWizPageInfo::OnWizpageInfoPageChanging(wxWizardEvent &event) {
	if (m_primaryEmail->GetValue().Find(wxT("@")) == wxNOT_FOUND) {
		wxMessageBox(_("Invalid e-mail"), _("Error"), wxOK);
		event.Veto();
	} else {
		if (m_fullName->GetValue().Len() < 5) {
			wxMessageBox(_("Full name is too short!"), _("Error"), wxOK);
			event.Veto();
		} else {
			wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_name =
					m_fullName->GetValue();
			wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_email =
					m_primaryEmail->GetValue();
			wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_comment =
					m_comment->GetValue();
			return;
		}
	}
} /* OnWizpageInfoPageChanging */

void wxGnuPGShellWizPagePass::OnWizpagePassPageChanging(wxWizardEvent &event) {
	if (m_passPhrase->GetValue().Len() < 3) {
		wxMessageBox(_("Passphrase is too short! Enter at least 3 chars."),
				_("Error"), wxOK);
		event.Veto();
	} else {
		if (m_passPhrase->GetValue() != m_passConfirmation->GetValue()) {
			wxMessageBox(_("Passphrase and confirmation missmaches!"),
					_("Error"), wxOK);
			event.Veto();
		} else {
			wxDynamicCast(GetParent(), wxGnuPGShellKeyGenWizard)->m_pass =
					m_passPhrase->GetValue();
			return;
		}
	}
}

IMPLEMENT_DYNAMIC_CLASS(wxGnuPGShellWizPageDone1, wxWizardPageSimple)

BEGIN_EVENT_TABLE( wxGnuPGShellWizPageDone1, wxWizardPageSimple )

END_EVENT_TABLE()


wxGnuPGShellWizPageDone1::wxGnuPGShellWizPageDone1() {
	Init();
}

wxGnuPGShellWizPageDone1::wxGnuPGShellWizPageDone1(wxWizard *parent) {
	Init();
	Create(parent);
}


bool wxGnuPGShellWizPageDone1::Create(wxWizard *parent) {
	wxBitmap wizardBitmap(wxNullBitmap);
	wxWizardPageSimple::Create(parent, NULL, NULL, wizardBitmap);

	CreateControls();
	if (GetSizer()) {
		GetSizer()->Fit(this);
	}
	return true;
}

wxGnuPGShellWizPageDone1::~wxGnuPGShellWizPageDone1() {
}

void wxGnuPGShellWizPageDone1::Init() {
}

void wxGnuPGShellWizPageDone1::CreateControls() {
	wxGnuPGShellWizPageDone1 *itemWizardPageSimple41 = this;

	wxBoxSizer *itemBoxSizer42 = new wxBoxSizer(wxVERTICAL);
	itemWizardPageSimple41->SetSizer(itemBoxSizer42);

	wxStaticText *itemStaticText43 = new wxStaticText(itemWizardPageSimple41,
			wxID_STATIC, _("Congratulations!"), wxDefaultPosition,
			wxDefaultSize, 0);
	itemStaticText43->SetFont(
			wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
					false, FONT_NAME_TAHOMA));
	itemBoxSizer42->Add(itemStaticText43, 0, wxALIGN_LEFT | wxALL, 5);

	wxBoxSizer *itemBoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer42->Add(itemBoxSizer44, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer44->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText46 = new wxStaticText(itemWizardPageSimple41,
			wxID_STATIC, _("All required information has been collected."),
			wxDefaultPosition, wxDefaultSize, 0);
	itemStaticText46->Wrap(400);
	itemBoxSizer44->Add(itemStaticText46, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);

	wxBoxSizer *itemBoxSizer48 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer42->Add(itemBoxSizer48, 0, wxALIGN_LEFT | wxALL, 5);

	itemBoxSizer48->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticText *itemStaticText50 = new wxStaticText(itemWizardPageSimple41,
			wxID_STATIC,
			_(" Your new key will generated after Finish button press."),
			wxDefaultPosition, wxDefaultSize, 0);
	itemBoxSizer48->Add(itemStaticText50, 0, wxALIGN_CENTER_VERTICAL | wxALL,
			5);
}

bool wxGnuPGShellWizPageDone1::ShowToolTips() {
	return true;
}

wxBitmap wxGnuPGShellWizPageDone1::GetBitmapResource(const wxString &name) {
	wxUnusedVar(name);
	return wxNullBitmap;
}

wxIcon wxGnuPGShellWizPageDone1::GetIconResource(const wxString &name) {
	wxUnusedVar(name);
	return wxNullIcon;
}
