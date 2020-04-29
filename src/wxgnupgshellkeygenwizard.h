// Purpose:getting user settings to generate a key
#ifndef _WXGNUPGSHELLKEYGENWIZARD_H_
#define _WXGNUPGSHELLKEYGENWIZARD_H_
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellkeygenwizard.h"
#endif

#include "wx/wizard.h"
#include "wx/statline.h"

class wxGnuPGShellWizPageIntro;
class wxGnuPGShellWizPageInfo;
class wxGnuPGShellWizPagePass;
class wxGnuPGShellWizPageDone;

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

/**
 * wxGnuPGShellKeyGenWizard class declaration
 *
 * This class is used to create a new GPG Key based on user configuration.
 */
class wxGnuPGShellKeyGenWizard: public wxWizard {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellKeyGenWizard)DECLARE_EVENT_TABLE()

public:
	/**
	 * Creates new instance of the wizard with default parent window.
	 */
	wxGnuPGShellKeyGenWizard();

	/**
	 * Creates new instance of the KeyGenWizard based on window and postions
	 *
	 * @param parent parent window
	 * @param id the wizard Id
	 * @param pos the location of the wizard
	 */
	wxGnuPGShellKeyGenWizard(wxWindow *parent, wxWindowID id =
	SYMBOL_WXGNUPGSHELLKEYGENWIZARD_IDNAME, const wxPoint &pos =
			wxDefaultPosition);
	~wxGnuPGShellKeyGenWizard();

	bool Create(wxWindow *parent, wxWindowID id =
	SYMBOL_WXGNUPGSHELLKEYGENWIZARD_IDNAME, const wxPoint &pos =
			wxDefaultPosition);
	void Init();


	void CreateControls();
	void OnWxgnupgshellkeygenwizardPageChanging(wxWizardEvent &event);
	void OnWxgnupgshellkeygenwizardCancel(wxWizardEvent &event);
	void OnWxgnupgshellkeygenwizardFinished(wxWizardEvent &event);
	bool Run();
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();

	wxGnuPGShellWizPageIntro *m_pageIntro;
	wxGnuPGShellWizPageInfo *m_pageInfo;
	wxGnuPGShellWizPagePass *m_pagePass;
	wxGnuPGShellWizPageDone *m_pageDone;
	wxString m_name;
	wxString m_email;
	wxString m_comment;
	wxString m_pass;
	wxString m_size;
	wxString m_keyType;
	wxString m_expire;
	bool m_isSepareteSignKey;
};

/**
 * wxGnuPGShellWizPageUserType class declaration
 */
class wxGnuPGShellWizPageUserType: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPageUserType)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPageUserType();
	wxGnuPGShellWizPageUserType(wxWizard *parent);
	~wxGnuPGShellWizPageUserType();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();
};

/**
 * wxGnuPGShellWizPageIntro class declaration
 */
class wxGnuPGShellWizPageIntro: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPageIntro)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPageIntro();
	wxGnuPGShellWizPageIntro(wxWizard *parent);
	~wxGnuPGShellWizPageIntro();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();
};

/**
 * wxGnuPGShellWizPageInfo class declaration
 */
class wxGnuPGShellWizPageInfo: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPageInfo)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPageInfo();
	wxGnuPGShellWizPageInfo(wxWizard *parent);
	~wxGnuPGShellWizPageInfo();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	void OnWizpageInfoPageChanging(wxWizardEvent &event);
	void OnWizpageinfoBtnAdvancedClick(wxCommandEvent &event);
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();

	wxTextCtrl *m_fullName;
	wxTextCtrl *m_primaryEmail;
	wxTextCtrl *m_comment;
protected:
	bool m_showMore;
};

/**
 * wxGnuPGShellWizPagePass class declaration
 */
class wxGnuPGShellWizPagePass: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPagePass)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPagePass();
	wxGnuPGShellWizPagePass(wxWizard *parent);
	~wxGnuPGShellWizPagePass();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	void OnWizpagePassPageChanging(wxWizardEvent &event);
	void OnWizpagepassPassphraseUpdated(wxCommandEvent &event);
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();

	wxTextCtrl *m_passPhrase;
	wxTextCtrl *m_passConfirmation;
};

/**
 * wxGnuPGShellWizPagePassPrpoblem class declaration
 */
class wxGnuPGShellWizPagePassPrpoblem: public wxWizardPage {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPagePassPrpoblem)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPagePassPrpoblem();
	wxGnuPGShellWizPagePassPrpoblem(wxWizard *parent);
	~wxGnuPGShellWizPagePassPrpoblem();

	bool Create(wxWizard *parent);
	void Init();
	virtual wxWizardPage* GetPrev() const;
	virtual wxWizardPage* GetNext() const;

	void CreateControls();
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();
};

/*!
 * wxGnuPGShellWizPageKeyGen class declaration
 */

class wxGnuPGShellWizPageKeyGen: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPageKeyGen)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPageKeyGen();
	wxGnuPGShellWizPageKeyGen(wxWizard *parent);
	~wxGnuPGShellWizPageKeyGen();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	wxBitmap GetBitmapResource(const wxString &name);

	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();
	wxGauge *m_overallStatus;
};

/*!
 * wxGnuPGShellWizPageDone class declaration
 */

class wxGnuPGShellWizPageDone: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPageDone)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPageDone();
	wxGnuPGShellWizPageDone(wxWizard *parent);
	~wxGnuPGShellWizPageDone();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();
};

/*!
 * wxGnuPGShellWizPageDone1 class declaration
 */

class wxGnuPGShellWizPageDone1: public wxWizardPageSimple {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellWizPageDone1)DECLARE_EVENT_TABLE()

public:
	wxGnuPGShellWizPageDone1();
	wxGnuPGShellWizPageDone1(wxWizard *parent);
	~wxGnuPGShellWizPageDone1();

	bool Create(wxWizard *parent);
	void Init();

	void CreateControls();
	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();
};

#endif
// _WXGNUPGSHELLKEYGENWIZARD_H_
