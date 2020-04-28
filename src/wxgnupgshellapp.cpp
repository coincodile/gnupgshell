/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellapp.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 13:51:17
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellapp.h"
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
#include "wxgnupgshellapp.h"
#include "wxgnupgshellkeygenwizard.h"
#include "wxgnupgshellkeyringeditor.h"
#include "wxGnuPGWrapper.h"
#include <wx/filename.h>
#include <wx/busyinfo.h>
#include <wx/dir.h>
////@end includes

class wxGnuPGWrapper;
////@begin XPM images
////@end XPM images

/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP(wxGnuPGShellApp)
////@end implement app

/*!
 * wxGnuPGShellApp type definition
 */

IMPLEMENT_CLASS(wxGnuPGShellApp, wxApp)

/*!
 * wxGnuPGShellApp event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellApp, wxApp )

////@begin wxGnuPGShellApp event table entries
////@end wxGnuPGShellApp event table entries
EVT_TIMER(wxID_CLEAR_TIMER, wxGnuPGShellApp::OnClearTimer)

END_EVENT_TABLE()

/*!
 * Constructor for wxGnuPGShellApp
 */

wxGnuPGShellApp::wxGnuPGShellApp() :
		m_gnuPGWrapper(NULL) {
	Init();
}

/*!
 * Member initialisation
 */

void wxGnuPGShellApp::Init() {
////@begin wxGnuPGShellApp member initialisation
////@end wxGnuPGShellApp member initialisation

	m_gnuPGWrapper = new wxGnuPGWrapper(this);
}

/*!
 * Initialisation for wxGnuPGShellApp
 */

bool wxGnuPGShellApp::OnInit() {
#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	wxImage::AddHandler(new wxICOHandler);
	wxFileName path(argv[0]);
	wxSetWorkingDirectory(
			path.GetPath(wxPATH_GET_SEPARATOR | wxPATH_GET_VOLUME));
#ifndef __WXMSW__
	//TODO: fix to share dir
	if (!wxDir::Exists(wxT("art"))) {
		if (wxDir::Exists(wxT("/usr/bin/art"))) {
			// seems installed
			wxSetWorkingDirectory(wxT("/usr/bin/"));
		}
	}
#endif

	m_timer = NULL;
	m_ready = false;
	// Restore data
	LoadConfig();

	// Check keys
	m_TranslationHelper =
			new wxTranslationHelper(*this,
					wxPathOnly(
							argv[0]) + wxFileName::GetPathSeparator() + wxT("languages"),
					true);
	RecreateGUI(false); // dont show

	m_gnuPGWrapper->GetKeyList().Clear();

	if (IsReady()) {
		wxLogMessage
		(_("Trying to list public keyring..."));
		ListPublicKeys();

		size_t count = m_gnuPGWrapper->GetKeyList().GetCount();
		if (!count) { // empty
			wxLogMessage
			(
					_(
							"Sorry, but keyring is empty or missing. Starting key generation wizard..."));
			GenerateKey();
			//wxLogMessage(_("Trying to re-list public keyring..."));
			ListPublicKeys();
		} else {
			wxLogMessage
			(_("Found %ld public keys"), count);
		}
		// start cleanup timer. Interval = 5 sec
		m_timer = new wxTimer(this, wxID_CLEAR_TIMER);
		m_timer->Start(5000);
	} else {
		wxLogMessage
		(_("GnuPG was not found!"));
	}

	wxGnuPGShellKeyringEditor *topWindow = wxDynamicCast(GetTopWindow(),
			wxGnuPGShellKeyringEditor);
	if (topWindow) {
		topWindow->Show();
		topWindow->m_keyListCtrl->SetItemCount(
				static_cast<long>(m_gnuPGWrapper->GetKeyList().GetCount()));
	}

	return true;
}

/*!
 * Cleanup for wxGnuPGShellApp
 */

int wxGnuPGShellApp::OnExit() {
	if (m_timer) {
		m_timer->Stop();
		wxDELETE(m_timer);
	}
	SaveConfig();

	//Clean all data
	wxDELETE(m_gnuPGWrapper);
	wxDELETE(m_TranslationHelper);

////@begin wxGnuPGShellApp cleanup
	return wxApp::OnExit();
////@end wxGnuPGShellApp cleanup
}

void wxGnuPGShellApp::OnClearTimer(wxTimerEvent &event) {
	wxDateTime now = wxDateTime::Now();

	if (m_cacheTime == 0) {
		return;
	}
	for (wxUint32 it = 0; it < GetKeyList().GetCount(); it++) {
		int dif = now.GetMinute() - GetKeyList()[it]->m_lastPassAccess.GetMinute();
		if (dif > m_cacheTime) {
			GetKeyList()[it]->ClearPassCache();
		}
	}
}

// Restore config from registry/file
void wxGnuPGShellApp::LoadConfig() {
	wxConfig *config = new wxConfig(wxGetApp().GetAppName());
	wxString confLine;
	m_ready = false;

#ifdef __WXMSW__
    // 1. Read GnuPGP path...
	if (!config->Read(wxT("GnuPG Path"), &confLine) || confLine.IsEmpty()) {
        wxRegKey *gpgRegKey = new wxRegKey(wxT("HKEY_LOCAL_MACHINE\\Software\\GNU\\GnuPG"));

        if (gpgRegKey->Exists()) {
            gpgRegKey->QueryValue(wxT("Install Directory"), confLine);
            m_ready = true;
        }
        wxDELETE(gpgRegKey);
    } else {
        m_ready = true;
    }

    if (!m_ready) {
        wxMessageBox(_("GnuPG was not found. Please, reinstall it."));
    } else {
        m_gnuPGWrapper->SetGPGPath(confLine);
    }
#else
	m_gnuPGWrapper->SetGPGPath(wxT(""));
	m_ready = true;
#endif

	// 2. read keyserver
	config->Read(wxT("Default Keyserver"), &m_defaultKeyServer);
	// 3. read default key
	config->Read(wxT("Default Key"), &m_defKey);
	config->Read(wxT("Use Cache"), &m_useCache);
	m_cacheTime = config->Read(wxT("Cache Time"), 01);

	LoadServerList(*config);

	// End reading configs. Cleaning
	wxDELETE(config);
}

// Save config to registry/file
void wxGnuPGShellApp::SaveConfig() {
	wxConfig *config = new wxConfig(wxGetApp().GetAppName());

	if (m_gnuPGWrapper->GetGPGPath() != wxEmptyString) {
		config->Write(wxT("GnuPG Path"), m_gnuPGWrapper->GetGPGPath());
	}

	if (m_defaultKeyServer != wxEmptyString) {
		config->Write(wxT("Default Keyserver"), m_defaultKeyServer);
	}

	if (m_defKey != wxEmptyString) {
		config->Write(wxT("Default Key"), m_defKey);
	}
	config->Write(wxT("Use Cache"), m_useCache);
	config->Write(wxT("Cache Time"), m_cacheTime);

	SaveServerList(*config);

	wxDELETE(config);
}

void wxGnuPGShellApp::SaveServerList(wxConfig &config) {
	wxString prevPath = config.GetPath();
	config.DeleteGroup(wxT("ServerList")); // clear old
	config.SetPath(wxT("ServerList"));

	for (wxUint16 it = 0; it < m_serverList.GetCount(); it++) {
		config.Write(wxString::Format(wxT("Server %d"), it), m_serverList[it]);
	}

	config.SetPath(prevPath);
}

void wxGnuPGShellApp::LoadServerList(wxConfig &config) {
	wxString prevPath = config.GetPath();
	config.SetPath(wxT("ServerList"));
	m_serverList.Clear();

	long index;
	wxString entry;
	wxString serverAddr;
	long count = 0;
	if (config.GetFirstEntry(entry, index)) {
		do {
			config.Read(entry, &serverAddr, wxT(""));
			if (serverAddr == wxEmptyString) {
				break;
			}
			m_serverList.Add(serverAddr);
			count++;
		} while (config.GetNextEntry(entry, index));
	}
	if (!count) {
		// hellish defaults
		m_serverList.Add(wxT("http://pgpkeys.mit.edu"));
		m_serverList.Add(wxT("ldap://keyserver.pgp.com"));
		m_serverList.Add(wxT("http://wwwkeys.us.pgp.net"));
		m_serverList.Add(wxT("http://wwwkeys.uk.pgp.net"));
		m_serverList.Add(wxT("http://wwwkeys.eu.pgp.net"));
		m_serverList.Add(wxT("http://wwwkeys.pl.pgp.net"));
		m_serverList.Add(wxT("http://wwwkeys.de.pgp.net"));
		m_defaultKeyServer = wxT("http://pgpkeys.mit.edu");
	}
	config.SetPath(prevPath);
}

void wxGnuPGShellApp::ListKeys(GpgKeyList &keylist) {
}

void wxGnuPGShellApp::ListKeys(wxString param, GpgKeyList &keyList) {
}

bool wxGnuPGShellApp::GenerateKey(void) {
	bool res = false;
	wxGnuPGShellKeyGenWizard *wizard = new wxGnuPGShellKeyGenWizard(NULL,
	ID_WXGNUPGSHELLKEYGENWIZARD);
	if (wizard) {
		if (wizard->Run()) {
			// fill param
			TaskParams params;
			params[wxT("name")] = wizard->m_name;
			params[wxT("email")] = wizard->m_email;
			params[wxT("comment")] = wizard->m_comment;
			params[wxT("pass")] = wizard->m_pass;
			params[wxT("cypher")] = wizard->m_keyType;
			params[wxT("length")] = wizard->m_size;
			params[wxT("expire")] =
					(wizard->m_expire == wxEmptyString) ?
							wxT("0") : wizard->m_expire;
			params[wxT("subkey")] =
					wizard->m_isSepareteSignKey ?
							wxT("Subkey-Type: ELG-E\nSubkey-Length: 1024\n") :
							wxT("");

			wxBusyInfo *info = new wxBusyInfo(
					_("Please wait, generating keys..."), GetTopWindow());
			res = m_gnuPGWrapper->RunTask(TASK_GEN_KEY, params);
			wxDELETE(info);

		}
		wizard->Destroy();
	}

	return res;
}

// EncryptDocument
//  call gpg to encrypt document. Used by FileManager
//
bool wxGnuPGShellApp::EncryptDocument(const wxString fileName,
		const wxString outFile, const wxString keyId, bool armored,
		bool overwrite) {
	TaskParams params;
	params[wxT("file")] = fileName;
	wxLogMessage
	(wxT("in: %s"), fileName.GetData());
	params[wxT("out")] = outFile;
	wxLogMessage
	(wxT("out: %s"), outFile.GetData());
	params[wxT("KeyId")] = keyId;
	wxLogMessage
	(wxT("key: %s"), keyId.GetData());
	params[wxT("armor")] = armored ? wxT(" --armor ") : wxEmptyString;
	wxLogMessage
	(wxT("armor: %s"), params[wxT("armor")].GetData());
	params[wxT("overwrite")] = overwrite ? wxT("yes") : wxEmptyString;
	wxLogMessage
	(wxT("ow: %s"), params[wxT("overwrite")].GetData());

	return m_gnuPGWrapper->RunTask(TASK_ENCRYPT_DOCUMENT, params);
}

// DecryptDocument
//  call gpg to decrypt document. Used by FileManager
//
bool wxGnuPGShellApp::DecryptDocument(const wxString fileName,
		const wxString outFile, const wxString pass, bool overwrite) {
	TaskParams params;
	params[wxT("file")] = fileName;
	params[wxT("out")] = outFile;
	params[wxT("passphrase")] = pass;
	params[wxT("overwrite")] = overwrite ? wxT("yes") : wxEmptyString;

	return m_gnuPGWrapper->RunTask(TASK_DECRYPT_DOCUMENT, params);
}

// SignDocument
//  call gpg to sign document. Used by FileManager
//
bool wxGnuPGShellApp::SignDocument(const wxString fileName,
		const wxString outFile, const wxString pass, bool armored) {
	TaskParams params;
	params[wxT("file")] = fileName;
	params[wxT("out")] = outFile;
	params[wxT("passphrase")] = pass;
	params[wxT("armor")] = armored ? wxT(" --armor ") : wxT(" ");

	return m_gnuPGWrapper->RunTask(TASK_SIGN_DOCUMENT, params);
}

// EncryptAndSignDocument
//  call gpg to sign & encrypt document. Used by FileManager
//
bool wxGnuPGShellApp::EncryptAndSignDocument(const wxString fileName,
		const wxString outFile, const wxString keyId, const wxString pass,
		bool armored, bool overwrite) {
	TaskParams params;
	params[wxT("file")] = fileName;
	params[wxT("out")] = outFile;
	params[wxT("KeyId")] = keyId;
	params[wxT("passphrase")] = pass;
	params[wxT("armor")] = armored ? wxT(" --armor ") : wxT(" ");
	params[wxT("overwrite")] = overwrite ? wxT("yes") : wxEmptyString;

	//TODO: Check sign and encryption caller func
	return m_gnuPGWrapper->RunTask(TASK_ENCRYPT_SIGN_DOCUMENT, params);
}

bool wxGnuPGShellApp::SetOwnerTrust(const wxString keyId, int trust) {
	TaskParams param;
	wxString buff;
	buff.Printf(wxT("%d"), trust); // for trust

	param[wxT("KeyID")] = keyId;
	param[wxT("trust")] = buff;
	return m_gnuPGWrapper->RunTask(TASK_SET_OWNERTRUST, param);
}

void wxGnuPGShellApp::RefreshKeyList(void) {
	TaskParams param;
	m_gnuPGWrapper->RunTask(TASK_REFRESH, param);
}

void wxGnuPGShellApp::ListPublicKeys(void) {
	TaskParams param;
	param[wxT("keyring")] = wxT("public");
	m_gnuPGWrapper->RunTask(TASK_LISTKEYS, param);
}

void wxGnuPGShellApp::ListSecretKeys(void) {
	TaskParams param;
	param[wxT("keyring")] = wxT("secret");
	m_gnuPGWrapper->RunTask(TASK_LISTKEYS, param);
}

bool wxGnuPGShellApp::SendKeys(const wxString server, const wxString keys) {
	TaskParams param;
	param[wxT("keys")] = keys;
	param[wxT("server")] = server;

	return m_gnuPGWrapper->RunTask(TASK_SEND_KEYS, param);
}

bool wxGnuPGShellApp::RecvKeys(const wxString server, const wxString keyId) {
	TaskParams param;
	wxString keyList = wxT("");
	param[wxT("KeyId")] = keyId;
	param[wxT("server")] = server;

	return m_gnuPGWrapper->RunTask(TASK_RECV_KEYS, param);
}

bool wxGnuPGShellApp::SelectLanguage() {
	wxArrayString names;
	wxArrayLong identifiers;
	m_TranslationHelper->GetInstalledLanguages(names, identifiers);

	return m_TranslationHelper->AskUserForLanguage(names, identifiers);
}

void wxGnuPGShellApp::RecreateGUI(bool show) {
	wxWindow *topwindow = GetTopWindow();
	if (topwindow) {
		SetTopWindow(NULL);
		topwindow->Destroy();
	}
	wxGnuPGShellKeyringEditor *mainWindow = new wxGnuPGShellKeyringEditor( NULL,
	ID_WXGNUPGSHELLKEYRINGEDITOR);
	SetTopWindow(mainWindow);
	mainWindow->Show(show);
}

wxString wxGnuPGShellApp::GetKeyFingerprint(wxUint32 index) {
	wxGnuPGKeyPair *key = wxGetApp().GetKeyList()[index];

	if (key) {
		return key->m_key.Fingerprint;
	} else {
		return wxEmptyString;
	}
}

// delete public key
bool wxGnuPGShellApp::DeleteKey(const wxString keyId, const int index) {
	TaskParams params;
	params[wxT("KeyId")] = keyId;
	// delete from keyring
	wxGnuPGKeyPair *key = GetKeyList()[index];
	GetKeyList().DeleteObject(key);
	return m_gnuPGWrapper->RunTask(TASK_DEL_PAIR, params);
}

// delete public and secret key
bool wxGnuPGShellApp::DeleteKeyPair(const wxString keyId,
		const wxString fingerprint, const int index) {
	TaskParams params;
	params[wxT("KeyId")] = keyId;
	params[wxT("Fingerprint")] = fingerprint;
	// delete from keyring
	wxGnuPGKeyPair *key = GetKeyList()[index];
	GetKeyList().DeleteObject(key);
	return m_gnuPGWrapper->RunTask(TASK_DEL_PAIR, params);
}

// sign key (locally?)
bool wxGnuPGShellApp::SignKey(const wxString keyId, const wxString pass) {
	TaskParams params;
	params[wxT("KeyId")] = keyId;
	params[wxT("passphrase")] = pass;

	return m_gnuPGWrapper->RunTask(TASK_SIGN_KEY, params);
}

// TODO: is these func's needed?
// backup ownertrust table
bool wxGnuPGShellApp::ExportOwnertrust(const wxString fileName) {
	return false;
}

// import ownertrust from files
bool wxGnuPGShellApp::ImportOwnertrust(const wxString files) {
	return false;
}

bool wxGnuPGShellApp::ChangePass(const wxString keyId, const wxString currPass,
		const wxString newPass) {
	TaskParams params;
	params[wxT("oldPass")] = currPass;
	params[wxT("newPass")] = newPass;
	params[wxT("KeyId")] = keyId;
	return m_gnuPGWrapper->RunTask(TASK_CHANGE_PASS, params);
}

void wxGnuPGShellApp::ExportKey(const wxString keyId, const wxString fileName,
		bool armored) {
	TaskParams params;
	params[wxT("KeyId")] = keyId;
	params[wxT("FileName")] = fileName;
	params[wxT("armor")] = armored ? wxT(" --armor ") : wxT(" ");
	m_gnuPGWrapper->RunTask(TASK_KEY_EXPORT, params);
}

void wxGnuPGShellApp::ImportKey(const wxString fileName) {
	TaskParams params;
	params[wxT("FileName")] = fileName;
	m_gnuPGWrapper->RunTask(TASK_KEY_IMPORT, params);
}

bool wxGnuPGShellApp::ChangeExpiration(const wxString keyId,
		const wxString date, const wxString pass) {
	TaskParams params;
	params[wxT("passphrase")] = pass;
	params[wxT("date")] = date;
	params[wxT("KeyId")] = keyId;
	return m_gnuPGWrapper->RunTask(TASK_CHANGE_EXPIRATION, params);
}

void wxGnuPGShellApp::UpdateTrustDB(void) {
	TaskParams params; // unused
	m_gnuPGWrapper->RunTask(TASK_UPDATE_TRUSTDB, params);
}

wxString wxGnuPGShellApp::GetKeyId(wxUint32 index) {
	wxGnuPGKeyPair *pair = GetKeyList()[index];

	if (pair) {
		return pair->m_key.Id;
	} else {
		return wxEmptyString;
	}
}

// return wxGnuPGKey* or null in list[index]
wxGnuPGKey* wxGnuPGShellApp::GetKey(wxUint32 index) {
	wxGnuPGKeyPair *pair = GetKeyList()[index];

	if (pair) {
		return &pair->m_key;
	} else {
		return NULL;
	}
}

bool wxGnuPGShellApp::SearchKeysOnServer(const wxString keyServer,
		const wxString searchKey, GpgKeyList &keyList) {
	TaskParams params;
	params[wxT("keyserver")] = keyServer;
	params[wxT("key")] = searchKey;
	return m_gnuPGWrapper->SearchKeys(params, keyList);
}

bool wxGnuPGShellApp::GenRevoke(const wxString keyId, const wxString outFile,
		const wxString reason, const wxString own, const wxString pass) {
	TaskParams params;
	params[wxT("out")] = outFile;
	params[wxT("KeyId")] = keyId;
	params[wxT("reason")] = reason;
	params[wxT("own")] = own;
	params[wxT("pass")] = pass;

	return m_gnuPGWrapper->RunTask(TASK_GEN_REVOKE, params);
}

bool wxGnuPGShellApp::EncryptSymmetric(const wxString fileName,
		const wxString outFile, const wxString pass, bool armored) {
	TaskParams params;
	params[wxT("out")] = outFile;
	params[wxT("file")] = fileName;
	params[wxT("pass")] = pass;
	params[wxT("armor")] = armored ? wxT(" --armor ") : wxEmptyString;

	return m_gnuPGWrapper->RunTask(TASK_ENCRYPT_SYM_DOCUMENT, params);
}

wxString wxGnuPGShellApp::GetPasswordForKey(const wxString keyId) {
	wxString pass = wxEmptyString;
	long index = GetKeyIndex(keyId);
	if (index != wxNOT_FOUND) {
		if (GetKeyList()[index]->IsPassCacheEmpty()) {
			pass =
					wxGetPasswordFromUser(
							wxString::Format(
									_(
											"Passphrase needed for key %s. Please, enter it."),
									keyId.GetData()), _("Passphrase needed"));
			if (pass != wxEmptyString) {
				GetKeyList()[index]->m_pass = pass;
			}
		} else {
			pass = GetKeyList()[index]->m_pass;
		}
		GetKeyList()[index]->m_lastPassAccess = wxDateTime::Now();
	}
	return pass;
}

wxString wxGnuPGShellApp::GetPasswordForKey(const wxUint32 keyId) {
	wxString pass;
	if (keyId > GetKeyList().GetCount()) {
		return wxEmptyString;
	}
	if (GetKeyList()[keyId]->IsPassCacheEmpty()) {
		pass = wxGetPasswordFromUser(
				wxString::Format(
						_("Passphrase needed for key %s. Please, enter it."),
						GetKeyList()[keyId]->m_key.Id.GetData()),
				_("Passphrase needed"));
	} else {
		pass = GetKeyList()[keyId]->m_pass;
	}
	GetKeyList()[keyId]->m_lastPassAccess = wxDateTime::Now();
	return pass;
}

long wxGnuPGShellApp::GetKeyIndex(wxString keyId) {
	for (wxUint32 it = 0; it < GetKeyList().GetCount(); it++) {
		if (GetKeyList()[it]->m_key.Id == keyId) {
			return it;
		}
	}
	return wxNOT_FOUND;
}

void wxGnuPGShellApp::ClearPassCache() {
	for (wxUint32 it = 0; it < GetKeyList().GetCount(); it++) {
		GetKeyList()[it]->ClearPassCache();
	}
}
//
//#if wxUSE_EXCEPTIONS
//void wxGnuPGShellApp::CallEventHandler(wxEvtHandler *handler,
//		wxEventFunctor &functor, wxEvent &event) const {
//}
//#endif // wxUSE_EXCEPTIONS
//
//#if wxUSE_EXCEPTIONS
//void wxGnuPGShellApp::HandleEvent(wxEvtHandler *handler, wxEventFunction func,
//		wxEvent &event) const {
//}
//#endif // wxUSE_EXCEPTIONS
//
//#if wxUSE_EXCEPTIONS
//void wxGnuPGShellApp::OnUnhandledException() {
//}
//#endif // wxUSE_EXCEPTIONS
//
//#if wxUSE_EXCEPTIONS
//bool wxGnuPGShellApp::OnExceptionInMainLoop() {
//
//	return true;
//}
//#endif // wxUSE_EXCEPTIONS
//
//#if wxUSE_EXCEPTIONS
//bool wxGnuPGShellApp::StoreCurrentException() {
//	return true;
//}
//#endif // wxUSE_EXCEPTIONS
//
//#if wxUSE_EXCEPTIONS
//void wxGnuPGShellApp::RethrowStoredException() {
//}
//#endif // wxUSE_EXCEPTIONS

