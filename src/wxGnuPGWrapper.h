// Purpose:     wxGnuPGWrapper class to run task and with gpg
#ifndef _WXGNUPGWRAPPER_H_
#define _WXGNUPGWRAPPER_H_

#include <wx/wx.h>
#include <wx/hashmap.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/tokenzr.h>
#include <wx/regex.h>
#include <wx/textctrl.h>

#include "wxGnuPGKey.h"
#include "wxGnuPGKeyPair.h"

// FWDS
class wxGnuPGWrapper;
class wxGnuPGShellApp;

/**
 * List of all supported task
 */
enum wxGnuPGTask {
	TASK_GEN_KEY, /**< TASK_GEN_KEY */
	TASK_GEN_REVOKE, /**< TASK_GEN_REVOKE */
	TASK_LISTKEYS, /**< TASK_LISTKEYS */
	TASK_SET_OWNERTRUST, /**< TASK_SET_OWNERTRUST */
	TASK_REFRESH, /**< TASK_REFRESH */
	TASK_SEND_KEYS, /**< TASK_SEND_KEYS */
	TASK_DEL_KEY, /**< TASK_DEL_KEY */
	TASK_DEL_PAIR, /**< TASK_DEL_PAIR */
	TASK_SIGN_KEY, /**< TASK_SIGN_KEY */
	TASK_RECV_KEYS, /**< TASK_RECV_KEYS */
	TASK_KEY_IMPORT, /**< TASK_KEY_IMPORT */
	TASK_KEY_EXPORT, /**< TASK_KEY_EXPORT */
	TASK_SEC_KEY_EXPORT, /**< TASK_SEC_KEY_EXPORT */
	TASK_UPDATE_TRUSTDB, /**< TASK_UPDATE_TRUSTDB */
	TASK_EXPORT_TRUST, /**< TASK_EXPORT_TRUST */
	TASK_IMPORT_TRUST, /**< TASK_IMPORT_TRUST */
	TASK_CHANGE_PASS, /**< TASK_CHANGE_PASS */
	TASK_CHANGE_EXPIRATION, /**< TASK_CHANGE_EXPIRATION */
	TASK_SIGN_DOCUMENT, /**< TASK_SIGN_DOCUMENT */
	TASK_ENCRYPT_SIGN_DOCUMENT,/**< TASK_ENCRYPT_SIGN_DOCUMENT */
	TASK_ENCRYPT_DOCUMENT, /**< TASK_ENCRYPT_DOCUMENT */
	TASK_ENCRYPT_SYM_DOCUMENT, /**< TASK_ENCRYPT_SYM_DOCUMENT */
	TASK_DECRYPT_DOCUMENT, /**< TASK_DECRYPT_DOCUMENT */
	TASK_CLEARSIGN_DOCUMENT, /**< TASK_CLEARSIGN_DOCUMENT */
	TASK_VERIFY_FILES /**< TASK_VERIFY_FILES */
};

/**
 * The state of the parsed key
 */
enum KeyParseState {
	STATE_KEY, /**< STATE_KEY */
	STATE_SUB, /**< STATE_SUB */
};

/**
 * @class TaskParams
 *
 * TaskParams is a map to store parameters.
 *
 * All parameters are passed to gpg tasks by a map of key-value. This
 * is a class to store parameters and used in task.
 *
 * @see std::unordered_map
 */
WX_DECLARE_STRING_HASH_MAP(wxString, TaskParams);

WX_DECLARE_HASH_MAP(wxGnuPGTask, wxString, wxIntegerHash, wxIntegerEqual,
		SuccessKey);

/**
 * @class GpgKeyList
 *
 * List of GpgKey Pair
 *
 * This is required to have a list of key pairs in all parts of the application.
 * For example, to show list of ready to use keys. This is a list of key to use
 * in the application.
 *
 * @see std::list
 */
WX_DECLARE_LIST(wxGnuPGKeyPair, GpgKeyList);

/**
 * A wrapper of GnuPG
 *
 * This class is responsible to manage all GPG requests and handle results.
 * For example, you can run key generation task and getting new list of keys.
 *
 */
class wxGnuPGWrapper {
	wxString m_keyRing;
	wxGnuPGTask m_task;
	SuccessKey m_successKey;
	wxString m_gpgCmd;
	wxProcess *m_gpgProcess;
	wxString m_gpgPath;
	wxString m_keyringPath;
	wxTextCtrl *m_logWindow;
	GpgKeyList m_keyList;

	wxString _OpenGPGProcess(const wxString cmdLine, wxOutputStream *&out,
			wxInputStream *&in, wxInputStream *&err);
	bool _CallGPG(const wxString cmdLine, wxArrayString &stdOut,
			wxArrayString &stdErr);
	bool _CallGPGInt(const wxString cmdLine, wxArrayString &stdIn,
			wxArrayString &stdOut, wxArrayString &stdErr);
	wxByte _ParseKeys(const wxArrayString gpgOutput);
	void _ParseFpr(const wxString line, wxGnuPGKey &key);
	void _ParseUid(const wxString line, wxGnuPGKey &key);
	void _ParseKey(const wxString line, wxGnuPGKey &key);
	void _WriteLog(const wxArrayString log);
	void _WriteLog(const wxString log);
	void _ParseKeySearchList(const wxArrayString &list, GpgKeyList &keyList);

public:
	wxGnuPGWrapper(wxGnuPGShellApp *parent);
	~wxGnuPGWrapper(void);

	// Automated runs task coded by task
	bool RunTask(const wxGnuPGTask task, TaskParams &params);
	void SetGPGPath(const wxString path);
	wxString GetGPGPath() const;
	GpgKeyList& GetKeyList();

	// intermediate function to list keys on remote server
	bool SearchKeys(TaskParams &params, GpgKeyList &keyList);

protected:
	/**
	 * Generates a key based on parameters
	 *
	 * GnuPG is often used as a backend engine by other software. To help with this
	 * a machine interface has been defined to have an unambiguous way to do this.
	 * This class converts user parameters into a text stream and send to gpg to
	 * run a task. Parameters differs based on a task.
	 *
	 * @param params to used in generation
	 * @return true if the process is successful.
	 */
	bool KeyGen(TaskParams &params);
	bool ListKeys(TaskParams &params);
	bool SetOwnerTrust(TaskParams &param);
	bool SendKeys(TaskParams &params);
	bool RecvKeys(TaskParams &params);
	bool UpdateTrustDB();
	bool DeleteSecretKey(const wxString keyId);
	bool DeleteKey(TaskParams &params);
	bool DeleteKeyPair(TaskParams &params);
	bool ImportKey(TaskParams &params);
	bool ExportKey(TaskParams &params);
	bool SignKey(TaskParams &params);
	bool EncryptDocument(TaskParams &params);
	bool EncryptSymmetric(TaskParams &params);
	bool DecryptDocument(TaskParams &params);
	bool EcryptAndSignDocument(TaskParams &params);
	bool SignDocument(TaskParams &params);
	bool ChangePass(TaskParams &params);
	bool ChangeExpiration(TaskParams &params);
	bool GenRevoke(TaskParams &params);
};

#endif // _WXGNUPGWRAPPER_H_
