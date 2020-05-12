#ifndef _WXGNUPGSHELLAPP_H_
#define _WXGNUPGSHELLAPP_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxgnupgshellapp.h"
#endif

#include <wx/image.h>
#include <wx/config.h>
#include <wx/dirdlg.h>
#include <wx/timer.h>
#include <wx/datetime.h>

#include "wxgnupgshellkeyringeditor.h"
#include "wxGnuPGWrapper.h"
#include "wxTranslationHelper/wxTranslationHelper.h"

class wxGnuPGShellApp: public wxApp {
DECLARE_CLASS( wxGnuPGShellApp )DECLARE_EVENT_TABLE()
	wxTimer *m_timer;
	unsigned short m_cacheTime;
	bool m_useCache;

public:
	/// Constructor
	wxGnuPGShellApp();
	void Init();
	bool OnInit();
	int OnExit();

	wxString m_defaultKeyServer;
	wxArrayString m_serverList;
	wxString m_defKey;
	GpgKeyList& GetKeyList() {
		return m_gnuPGWrapper->GetKeyList();
	}
	wxString GetKeyId(wxUint32 index);
	wxString GetKeyFingerprint(wxUint32 index);
	wxGnuPGKey* GetKey(wxUint32 index);
	long GetKeyIndex(wxString keyId);

	// ***** GnuPG interface *****
	void ListKeys(GpgKeyList &keylist);
	void ListKeys(wxString param, GpgKeyList &keylist);

	void ListPublicKeys(void);  // switch to public keyring
	void ListSecretKeys(void);  // switch to secret keyring
	void RefreshKeyList(void);  // relist keys

	bool SendKeys(const wxString server, const wxString keys);
	bool RecvKeys(const wxString server, const wxString keyId);
	bool SetOwnerTrust(const wxString keyId, int trust);
	bool DeleteKey(const wxString keyId, const int index);  // delete public key
	bool DeleteKeyPair(const wxString keyId, const wxString fingerprint,
			const int index);  // delete public and secret key
	bool SignKey(const wxString keyId, const wxString pass); // sign key (locally?)
	bool ExportOwnertrust(const wxString fileName);   // backup ownertrust table
	bool ImportOwnertrust(const wxString files); // import ownertrust from files
	bool GenerateKey(void);
	void UpdateTrustDB(void);
	void ExportKey(const wxString keyId, const wxString fileName, bool armored);
	void ImportKey(const wxString fileName);
	bool ChangePass(const wxString keyId, const wxString currPass,
			const wxString newPass);
	bool ChangeExpiration(const wxString keyId, const wxString date,
			const wxString pass);
	bool GenRevoke(const wxString keyId, const wxString outFile,
			const wxString reason, const wxString own, const wxString pass);

	//=== Filemanager functions ===

	bool EncryptDocument(const wxString fileName, const wxString outFile,
			const wxString keyId, bool armored, bool overwrite);
	bool EncryptSymmetric(const wxString fileName, const wxString outFile,
			const wxString pass, bool armored);
	bool SignDocument(const wxString fileName, const wxString outFile,
			const wxString pass, bool armored);
	bool VerifyDocument(const wxString fileName, const wxString outFile,
			bool armored);
	bool DecryptDocument(const wxString fileName, const wxString outFile,
			const wxString pass, bool overwrite);
	bool EncryptAndSignDocument(const wxString fileName, const wxString outFile,
			const wxString keyId, const wxString pass, bool armored,
			bool overwrite);

	//=== END Filemanager functions ===

	bool SearchKeysOnServer(const wxString keyServer, const wxString searchKey,
			GpgKeyList &keyList);
	wxString GetPasswordForKey(const wxString keyId);
	wxString GetPasswordForKey(const wxUint32 keyId);

	// ***** END GnuPG interface *****


	// Translation
	bool SelectLanguage();
	void RecreateGUI(bool show = true);

	void ClearPassCache();
	bool IsReady() {
		return m_ready;
	}
	void UseCache(bool use = true) {
		m_useCache = use;
	}
	bool IsCacheInUse() const {
		return m_useCache;
	}
	unsigned char GetCacheTime() const {
		return m_cacheTime;
	}
	void SetCacheTime(unsigned char time) {
		UseCache();
		m_cacheTime = time;
	}

protected:
	wxTranslationHelper *m_TranslationHelper;
	wxGnuPGWrapper *m_gnuPGWrapper;       // Wrapper of gpg facilities
	bool m_ready;

	/**
	 * Loading System Configuration
	 *
	 * In windows we are looking in RegEdit
	 *
	 * HKEY_CURRENT_USER\\Software\\gnupgshell
	 *
	 * In Linux we use following file
	 *
	 * $hoem/.gnupgshell
	 */
	void LoadConfig();
	void SaveConfig();
	void SaveServerList(wxConfig &config);
	void LoadServerList(wxConfig &config);

	void OnClearTimer(wxTimerEvent &event);
	enum {
		wxID_CLEAR_TIMER = 30000
	};
};

/*
 * Application instance declaration
 */
DECLARE_APP(wxGnuPGShellApp)

#endif // _WXGNUPGSHELLAPP_H_
