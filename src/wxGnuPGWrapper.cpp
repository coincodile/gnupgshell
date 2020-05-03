/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgwrapper.cpp
// Purpose:     wxGnuPGWrapper class
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:50:08
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#include "wxGnuPGWrapper.h"
#include <wx/listimpl.cpp>
#include "wxgnupgshellapp.h"
#include <wx/txtstrm.h>

WX_DEFINE_LIST(GpgKeyList);

wxGnuPGWrapper::wxGnuPGWrapper(wxGnuPGShellApp *parent = NULL) :
		m_task(TASK_GEN_KEY) {
	//m_app = parent;
	m_gpgProcess = NULL;
	//TODO: make it work in UNIX!
#ifdef __WXMSW__
    m_gpgCmd = wxT("gpg.exe");
#else
	m_gpgCmd = wxT("gpg");
#endif //__WXMSW__
	m_logWindow = NULL;
	m_successKey[TASK_GEN_KEY] = "KEY_CREATED";
	m_successKey[TASK_CHANGE_PASS] = "GOOD_PASSPHRASE";
	m_successKey[TASK_CHANGE_EXPIRATION] = "GOOD_PASSPHRASE";
	m_successKey[TASK_ENCRYPT_SIGN_DOCUMENT] = "END_ENCRYPTION";
	m_successKey[TASK_GEN_REVOKE] = "GOOD_PASSPHRASE";
	m_successKey[TASK_DECRYPT_DOCUMENT] = "DECRYPTION_OKAY";
	m_successKey[TASK_ENCRYPT_SYM_DOCUMENT] = "END_ENCRYPTION";
	m_successKey[TASK_SIGN_DOCUMENT] = "SIG_CREATED";
}

wxGnuPGWrapper::~wxGnuPGWrapper(void) {
	m_keyList.DeleteContents(true);
	m_keyList.Clear();
}

// Automated runs task coded by task
bool wxGnuPGWrapper::RunTask(wxGnuPGTask task, TaskParams &params) {
	// check gpg path
	if (!wxGetApp().IsReady()) {
		return false;
	}
	m_task = task;
	switch (task) {
	case TASK_GEN_KEY:
		return KeyGen(params);

	case TASK_GEN_REVOKE:
		return GenRevoke(params);

	case TASK_LISTKEYS:
		m_keyRing = params[wxT("keyring")];
		return ListKeys(params);

	case TASK_SET_OWNERTRUST:
		return SetOwnerTrust(params);

	case TASK_REFRESH:
		return ListKeys(params);

	case TASK_RECV_KEYS:
		return RecvKeys(params);

	case TASK_SIGN_KEY:
		return SignKey(params);

	case TASK_SEND_KEYS:
		return SendKeys(params);

	case TASK_UPDATE_TRUSTDB:
		return UpdateTrustDB();

	case TASK_DEL_KEY:
		return DeleteKey(params);

	case TASK_DEL_PAIR:
		return DeleteKeyPair(params);

	case TASK_KEY_EXPORT:
		return ExportKey(params);

	case TASK_KEY_IMPORT:
		return ImportKey(params);

	case TASK_ENCRYPT_DOCUMENT:
		return EncryptDocument(params);

	case TASK_ENCRYPT_SYM_DOCUMENT:
		return EncryptSymmetric(params);

	case TASK_DECRYPT_DOCUMENT:
		return DecryptDocument(params);

	case TASK_SIGN_DOCUMENT:
		return SignDocument(params);

	case TASK_CHANGE_PASS:
		return ChangePass(params);

	case TASK_CHANGE_EXPIRATION:
		return ChangeExpiration(params);

	case TASK_ENCRYPT_SIGN_DOCUMENT:
		return EcryptAndSignDocument(params);

	default:
		return false;
	}
	return false;
}

// gpg --no-secmem-warning --no-tty --batch --update-trustdb
bool wxGnuPGWrapper::UpdateTrustDB() {
	wxString cmdLine =
			wxT(
					"--no-secmem-warning --no-sk-comment --no-tty --batch --logger-fd 1 --status-fd 1 --update-trustdb");
	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

bool wxGnuPGWrapper::SignKey(TaskParams &params) {
	return false;
}

// gpg [--armor] --no-sk-comment --yes --status-fd 1 --no-tty --command-fd 0 --output <out_file> --sign <in_file>
bool wxGnuPGWrapper::SignDocument(TaskParams &params) {
	wxString cmdLine =
			wxString::Format(
					wxT(
							"%s --no-sk-comment --yes --status-fd 1 --no-tty --command-fd 0 --output \"%s\" --sign \"%s\""),
					params[wxT("armor")].GetData(),
					params[wxT("out")].GetData(),
					params[wxT("file")].GetData());

	wxArrayString in, out, err;
	in.Add(params[wxT("passphrase")] + wxT("\n"));

	return _CallGPGInt(cmdLine, in, out, err);
}

bool wxGnuPGWrapper::EncryptDocument(TaskParams &params) {
	// gpg --armor --batch --always-trust --encrypt --recipient <id> --output <out_file> <in_file>
	wxString cmdLine =
			wxString::Format(
					wxT(
							"%s --batch --yes --always-trust --encrypt --recipient %s --output \"%s\" \"%s\""),
					params[wxT("armor")].GetData(),
					params[wxT("KeyId")].GetData(),
					params[wxT("out")].GetData(),
					params[wxT("file")].GetData());

	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

bool wxGnuPGWrapper::EcryptAndSignDocument(TaskParams &params) {
	wxString cmdLine =
			wxString::Format(
					wxT(
							"%s --always-trust --yes --encrypt --sign --recipient %s --output \"%s\" \"%s\""),
					params[wxT("armor")].GetData(),
					params[wxT("KeyId")].GetData(),
					params[wxT("out")].GetData(),
					params[wxT("file")].GetData());

	wxArrayString in, out, err;
	in.Add(params[wxT("passphrase")] + wxT("\n"));

	return _CallGPGInt(cmdLine, in, out, err);
}

// gpg --output <out_file> --decrypt  --no-sk-comment --status-fd 1 --no-tty --command-fd 0 <in_file>
bool wxGnuPGWrapper::DecryptDocument(TaskParams &params) {
	wxString cmdLine =
			wxString::Format(
					wxT(
							"--decrypt --yes --no-sk-comment --status-fd 1 --no-tty --command-fd 0 --output \"%s\" \"%s\""),
					params[wxT("out")].GetData(),
					params[wxT("file")].GetData());
	wxArrayString in, out, err;
	in.Add(params[wxT("passphrase")] + wxT("\n"));

	// if need overwriting
	if (params[wxT("overwrite")] != wxEmptyString) {
		in.Add(params[wxT("overwrite")] + wxT("\n"));
	}

	return _CallGPGInt(cmdLine, in, out, err);
}

// gpg --no-sk-comment --status-fd 1 --no-tty --command-fd 0 --edit-key <id> passwd
bool wxGnuPGWrapper::ChangePass(TaskParams &params) {
	wxString cmdLine =
			wxT(
					"--no-sk-comment --status-fd 1 --no-tty --command-fd 0 --edit-key ") + params[wxT("KeyId")] + wxT(" passwd");
	wxArrayString in, out, err;

	in.Add(params[wxT("oldPass")] + wxT("\n"));
	in.Add(params[wxT("newPass")] + wxT("\n"));
	in.Add(params[wxT("newPass")] + wxT("\n"));
	in.Add(wxT("save\n"));
	return _CallGPGInt(cmdLine, in, out, err);
}

// gpg --no-sk-comment --status-fd 1 --no-tty --command-fd 0 --edit-key <id> expire
bool wxGnuPGWrapper::ChangeExpiration(TaskParams &params) {
	wxString cmdLine =
			wxT(
					"--no-sk-comment --logger-fd 1 --status-fd 1 --no-tty --command-fd 0 --edit-key ") + params[wxT("KeyId")] + wxT(" expire");
	wxArrayString in, out, err;

	in.Add(params[wxT("date")] + wxT("\n"));
	//in.Add(wxT("y\n"));
	in.Add(params[wxT("passphrase")] + wxT("\n"));
	in.Add(wxT("save\n"));
	return _CallGPGInt(cmdLine, in, out, err);
}

void wxGnuPGWrapper::SetGPGPath(const wxString path) {
	m_gpgPath = path;
}

wxString wxGnuPGWrapper::GetGPGPath() const {
	return m_gpgPath;
}

// gpg --no-tty --no-secmem-warning --fixed-list-mode --with-colons [--list-public-keys|--list-secret-keys] --with-fingerprint --with-fingerprint
bool wxGnuPGWrapper::ListKeys(TaskParams &params) {
	wxString cmdLine = wxT(
			"--no-tty --no-secmem-warning --fixed-list-mode --with-colons ");
	// if empty apply last choice
	if (params[wxT("keyring")] == wxT("")) {
		params[wxT("keyring")] = m_keyRing;
	}

	if (params[wxT("keyring")] == wxT("public")) {
		cmdLine.Append(wxT("--list-public-keys "));
	} else if (params[wxT("keyring")] == wxT("secret")) {
		cmdLine.Append(wxT("--list-secret-keys "));
	}
	cmdLine.Append(wxT("--with-fingerprint --with-fingerprint"));

	wxArrayString out, err;

	_CallGPG(cmdLine, out, err);
	m_keyList.DeleteContents(true);
	m_keyList.Clear();
	_ParseKeys(out);
	// safe operation
	return true;
}

// gpg --no-sk-comment --command-fd 0 --status-fd 1 --no-tty --logger-fd 2 --edit-key <id> trust
bool wxGnuPGWrapper::SetOwnerTrust(TaskParams &params) {
	wxString cmdLine;
	cmdLine =
			wxT(
					"--no-sk-comment --command-fd 0 --status-fd 1 --no-tty --logger-fd 2 --edit-key ") + params[wxT("KeyID")] + wxT(" trust");

	wxString path = m_gpgPath;
	if (m_gpgPath[m_gpgPath.Len() - 1] != '/') {
		path.Append('/');
	}
	path.Append(m_gpgCmd);
	wxString cmd = wxString::Format(wxT("%s %s"), path.GetData(),
			cmdLine.GetData());

	wxArrayString out, err, in;

	unsigned long trust;
	wxString paramTrust = params[wxT("trust")];
	paramTrust.ToULong(&trust);

	switch (trust) {
	case TRUST_DONT_KNOW:
		in.Add(wxT("1\n"));
		break;
	case TRUST_DO_NOT_TRUST:
		in.Add(wxT("2\n"));
		break;
	case TRUST_MARGINALLY:
		in.Add(wxT("3\n"));
		break;
	case TRUST_FULLY:
		in.Add(wxT("4\n"));
		break;
	case TRUST_ULTIMATELY:
		in.Add(wxT("5\n"));
		in.Add(wxT("y\n"));
		break;
	}
	in.Add(wxT("save\n"));

	// TODO: Fix interactive mode first
	_CallGPGInt(cmdLine, in, out, err);
	return true;
}

bool wxGnuPGWrapper::DeleteSecretKey(const wxString keyId) {
	wxString cmdLine = wxT(
			"--no-secmem-warning --no-tty --batch --yes --delete-secret-keys ");
	cmdLine.Append(keyId);
	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

bool wxGnuPGWrapper::DeleteKey(TaskParams &params) {
	wxString cmdLine = wxT(
			"--no-secmem-warning --no-tty --batch --yes --delete-key ");
	cmdLine.Append(params[wxT("KeyId")]);
	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

bool wxGnuPGWrapper::DeleteKeyPair(TaskParams &params) {
	DeleteSecretKey(params[wxT("Fingerprint")]);
	return DeleteKey(params);
}

bool wxGnuPGWrapper::ImportKey(TaskParams &params) {
	wxString cmdLine = wxT(
			"--batch --import \"") + params[wxT("FileName")] + wxT("\"");
	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

// gpg --batch [--armor] --export --output <out_file> <id>
bool wxGnuPGWrapper::ExportKey(TaskParams &params) {
	wxString cmdLine = wxT("--batch ");
	cmdLine.Append(
			params[wxT("armor")] + wxT(" --export --output \"")
					+ params[wxT("FileName")] + wxT("\" ")
					+ params[wxT("KeyId")]);
	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

// gpg --batch --keyserver <server> --search <name>
bool wxGnuPGWrapper::SearchKeys(TaskParams &params, GpgKeyList &keyList) {
	wxString cmdLine = wxT("--batch --no-secmem-warning --no-tty --keyserver ")
			+ params[wxT("keyserver")] + wxT(" --search ") + params[wxT("key")];
	wxArrayString out, err;
	_CallGPG(cmdLine, out, err);
	_ParseKeySearchList(out, keyList);
	return keyList.GetCount() > 0;
}

bool wxGnuPGWrapper::SendKeys(TaskParams &params) {
	wxString cmdLine = wxT("--send-keys --keyserver ");
	cmdLine.Append(params[wxT("server")]);
	cmdLine.Append(wxT(" "));
	cmdLine.Append(params[wxT("keys")]);

	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

bool wxGnuPGWrapper::RecvKeys(TaskParams &params) {
	wxString cmdLine = wxT("--recv-keys --keyserver ");
	cmdLine.Append(params[wxT("server")]);
	cmdLine.Append(wxT(" "));
	cmdLine.Append(params[wxT("KeyId")]);

	wxArrayString out, err;

	return _CallGPG(cmdLine, out, err);
}

// generate revocation certificate
// gpg --yes --status-fd 1 --output %s --gen-revoke %s
bool wxGnuPGWrapper::GenRevoke(TaskParams &params) {
	wxString cmdLine =
			wxString::Format(
					wxT(
							"--yes --no-secmem-warning --no-tty --logger-fd 1 --command-fd 0 --status-fd 1 --output \"%s\" --gen-revoke %s"),
					params[wxT("out")].GetData(),
					params[wxT("KeyId")].GetData());
	wxArrayString in, out, err;

	in.Add(wxT("y\n"));
	in.Add(params[wxT("reason")] + wxT("\n"));
	if (params[wxT("own")] != wxEmptyString) {
		in.Add(params[wxT("own")] + wxT("\n\n"));
	} else {
		in.Add(wxT("\n"));
	}
	in.Add(wxT("y\n"));
	in.Add(params[wxT("pass")] + wxT("\n"));

	return _CallGPGInt(cmdLine, in, out, err);
}

// generate key *not in batch mode*
bool wxGnuPGWrapper::KeyGen(TaskParams &params) {
	wxString cmdLine;
	cmdLine = wxT("--no-secmem-warning --batch --status-fd 1 --gen-key");

	wxArrayString out, err, in;
	if (params[wxT("cypher")] == wxT("DILITHIUM")) {
		in.Add(wxT("Key-Type: DILITHIUM\n"));
	} else if (params[wxT("cypher")] == wxT("RSA")) {
		in.Add(wxT("Key-Type: RSA\n"));
	} else {
		in.Add(wxT("Key-Type: DSA\n"));
		in.Add(wxT("Subkey-Type: ELG-E\n"));
		in.Add(wxT("Subkey-Length: 1024\n"));
	}
	in.Add(wxT("Passphrase: ") + params[wxT("pass")] + wxT("\n"));
	in.Add(wxT("Key-Length: ") + params[wxT("length")] + wxT("\n"));
	in.Add(wxT("Name-Real: ") + params[wxT("name")] + wxT("\n"));
	if (params[wxT("comment")] != wxEmptyString) {
		in.Add(wxT("Name-Comment: ") + params[wxT("comment")] + wxT("\n"));
	}
	in.Add(wxT("Name-Email: ") + params[wxT("email")] + wxT("\n"));
	in.Add(wxT("Expire-Date: ") + params[wxT("expire")] + wxT("\n"));
	in.Add(wxT("%commit\n"));
	in.Add(wxT("%echo Done\n"));

	return _CallGPGInt(cmdLine, in, out, err);
} /* KeyGen */

// Opens pgp process, redirects its io pipes and return opened streams.
wxString wxGnuPGWrapper::_OpenGPGProcess(const wxString cmdLine,
		wxOutputStream *&in, wxInputStream *&out, wxInputStream *&err) {
	wxString path = m_gpgPath;

#ifdef __WXMSW__
    if (m_gpgPath[m_gpgPath.Len()-1] != wxT('/')) {
        path.Append(wxT('/'));
    }
    path.Append(m_gpgCmd);
    wxString cmd = wxString::Format(wxT("%s %s"), path.GetData(), cmdLine.GetData());
#else
	wxString cmd = wxString::Format(wxT("%s %s"), m_gpgCmd.GetData(),
			cmdLine.GetData());
#endif

	m_gpgProcess = wxProcess::Open(cmd);

	if (!m_gpgProcess) {
		return wxEmptyString;
	}
	m_gpgProcess->Redirect();

	out = m_gpgProcess->GetInputStream();
	err = m_gpgProcess->GetErrorStream();
	in = m_gpgProcess->GetOutputStream();

	if (!out) {
		return wxEmptyString;
	}
	return cmd;
}

// interactive gpg call, open in stream and communicate with gpg
bool wxGnuPGWrapper::_CallGPGInt(const wxString cmdLine, wxArrayString &stdIn,
		wxArrayString &stdOut, wxArrayString &stdErr) {
	wxInputStream *out = NULL;
	wxInputStream *err = NULL;
	wxOutputStream *in = NULL;
	bool success = false;

	stdOut.Clear();
	wxString cmd = _OpenGPGProcess(cmdLine, in, out, err);
	_WriteLog(wxT("[CMD] ") + cmd);

	if (cmd != wxEmptyString) {
		wxString msg;

		// Write to gpg
		wxTextOutputStream inText(*in);
		wxTextInputStream outText(*out);
		wxTextInputStream errText(*err);
		stdErr.Clear();

		for (wxUint8 it = 0; it < stdIn.GetCount(); it++) {
			inText.WriteString(stdIn[it]);
		}
		m_gpgProcess->CloseOutput();

		while (m_gpgProcess->IsInputOpened()) {
			// Read from stdout...
			while (out->CanRead()) {
				msg = outText.ReadLine();
				//TODO: bug here
				if (!msg.empty()) {
					stdOut.Add(msg);
					_WriteLog(msg);
					if (!success) {
						if (msg.Find(m_successKey[m_task]) != wxNOT_FOUND) {
							success = true;
						}
					}
				}
			}

			// ...then from stderr
			while (err->CanRead()) {
				msg = errText.ReadLine();
				if (!msg.empty()) {
					stdErr.Add(msg);
					_WriteLog(msg);
				}
			}
		}
	} // END if (cmd != wxEmptyString)

	return success; // if errors
} // END _CallGPGInt

// Invoke gpg call
bool wxGnuPGWrapper::_CallGPG(const wxString cmdLine, wxArrayString &stdOut,
		wxArrayString &stdErr) {
	wxInputStream *out = NULL;
	wxInputStream *err = NULL;
	wxOutputStream *in = NULL;

	stdOut.Clear();
	wxString cmd = _OpenGPGProcess(cmdLine, in, out, err);
	_WriteLog(wxT("[CMD] ") + cmd);

	if (cmd != wxEmptyString) {
		wxString msg;

		// Read first from stdout...
		wxTextInputStream outText(*out);
		m_gpgProcess->CloseOutput();

		while (m_gpgProcess->IsInputOpened()) {
			while (out->CanRead()) {
				msg = outText.ReadLine();
				if (!msg.empty()) {
					stdOut.Add(msg);
				}
			}

			stdErr.Clear();
			// ...then from stderr
			if (err->CanRead()) {
				wxTextInputStream errText(*err);

				while (err->CanRead()) {
					msg = errText.ReadLine();
					if (!msg.empty()) {
						stdErr.Add(msg);
					}
				}
			}
		}

		_WriteLog(wxT("[OUT] "));
		_WriteLog(stdOut);
		// show error message
		if (stdErr.Count() != 0) {
			_WriteLog(wxT("[ERR] "));
			_WriteLog(stdErr);
		}
	}

	return stdErr.Count() == 0; // if errors
}

void wxGnuPGWrapper::_ParseFpr(const wxString line, wxGnuPGKey &key) {
	wxStringTokenizer tk(line, wxT(":"));
	wxString token = tk.GetNextToken();

	if (token == wxT("fpr")) {
		do {
			token = tk.GetNextToken();
		} while (token == wxT(""));
		key.Fingerprint = token;
	}
}

void wxGnuPGWrapper::_ParseUid(const wxString line, wxGnuPGKey &key) {
	wxStringTokenizer tk(line, wxT(":"));
	wxString token = tk.GetNextToken();
	wxByte pos = 1;
	//wxByte len = static_cast<wxByte>(tk.CountTokens());
	//wxUint32 num = 0;
	wxRegEx reName;

	while (tk.HasMoreTokens()) {
		wxString token = tk.GetNextToken();
		pos++;
		switch (pos) {
		case 8: // Used for serial number in crt records
			key.UserIDHash = token;
			break;
		case 9: // Ownertrust (primary public keys only)
			break;
		case 10: // User-ID
			if (reName.Compile(
					wxT("(.*?\\s.*?\\s.*?)\\s(\\(.*?\\))?\\s*(\\<(.*?)\\>)?"),
					wxRE_ADVANCED | wxRE_ICASE)) {
				if (reName.Matches(token)) {
					key.Name = reName.GetMatch(token, 1);
					key.Email = reName.GetMatch(token, 3);
					key.Comment = reName.GetMatch(token, 2);
				}
			}
			key.Name = token;
			break;
		case 11: // Signature class
			break;
		case 12: // Key capabilities
			break;
		}
	}
}

void wxGnuPGWrapper::_ParseKey(const wxString line, wxGnuPGKey &key) {
	wxStringTokenizer tk(line, wxT(":"));
	wxString token = tk.GetNextToken();
	wxByte pos = 1;
	//wxByte len = static_cast<wxByte>(tk.CountTokens());
	wxUint32 num = 0;
	wxRegEx reName;

	while (tk.HasMoreTokens()) {
		wxString token = tk.GetNextToken();
		pos++;
		switch (pos) {
		case 2: // A letter describing the calculated trust
			key.TrustLevel = key.TRUST[token];
			break;
		case 3: // length of key in bits
			token.ToULong(reinterpret_cast<unsigned long*>(&num));
			key.Length = num;
			break;
		case 4: // Algorithm
			token.ToULong(reinterpret_cast<unsigned long*>(&num));
			key.Algorithm = key.ALGORITHM[num];
			break;
		case 5: // KeyID
			key.Id = token.Right(8);
			break;
		case 6: // Creation Date (in UTC)
			token.ToULong(reinterpret_cast<unsigned long*>(&num));
			key.CreationDate = wxDateTime(static_cast<time_t>(num));
			break;
		case 7: // Key or user ID/user attribute expiration date or empty if none
			if (!token.IsEmpty()) {
				token.ToULong(reinterpret_cast<unsigned long*>(&num));
				key.ExpirationDate = wxDateTime(static_cast<time_t>(num));
			}
			break;
		case 8: // Used for serial number in crt records
			break;
		case 9: // Ownertrust (primary public keys only)
			key.TrustLevel = key.TRUST[token];
			break;
		case 10: // User-ID

			if (reName.Compile(
					wxT("(.*?\\s.*?\\s.*?)\\s(\\(.*?\\))?\\s*(\\<(.*?)\\>)?"),
					wxRE_ADVANCED)) {
				if (reName.Matches(token)) {
					key.Name = reName.GetMatch(token, 1);
					key.Email = reName.GetMatch(token, 3);
					key.Comment = reName.GetMatch(token, 2);
				}
			}
			key.Name = token;
			break;
		case 11: // Signature class
			break;
		case 12: // Key capabilities
			break;
		}
	}
}

// parse list-keys output and return new key count
//
wxByte wxGnuPGWrapper::_ParseKeys(const wxArrayString gpgOutput) {
	wxGnuPGKeyPair *pair = NULL;
	wxGnuPGKey *key = NULL;
	wxByte keyCount = 0;

	for (wxByte it = 0; it < gpgOutput.Count(); it++) {
		wxStringTokenizer tk(gpgOutput[it], wxT(":"));
		wxString token = tk.GetNextToken();

		KeyParseState state = STATE_KEY;

		// skip trust db statistic
		if (token == wxT("tru")) {
			continue;
		}

		// new keypair found
		if (token == wxT("pub") || token == wxT("sec")) {
			state = STATE_KEY;

			pair = new wxGnuPGKeyPair(token == wxT("pub"));
			m_keyList.Append(pair);
			keyCount++;
			_ParseKey(gpgOutput[it], pair->m_key);
		}
		// secondary key. Always _after_ pub/sec!
		if (token == wxT("sub") || token == wxT("ssb")) {
			state = STATE_SUB;
			_ParseKey(gpgOutput[it], pair->m_subKey);
		}
		// fingerprint
		if (token == wxT("fpr")) {
			key = (state == STATE_KEY) ? &(pair->m_key) : &(pair->m_subKey);
			_ParseFpr(gpgOutput[it], *key);
		}
		// user id
		if (token == wxT("uid")) {
			key = (state == STATE_KEY) ? &(pair->m_key) : &(pair->m_subKey);
			_ParseUid(gpgOutput[it], *key);
		}
	}
	return static_cast<wxByte>(m_keyList.GetCount());
}

GpgKeyList& wxGnuPGWrapper::GetKeyList() {
	return m_keyList;
}

void wxGnuPGWrapper::_WriteLog(const wxArrayString log) {
	wxString logMsg;
	for (wxUint32 it = 0; it < log.Count(); it++) {
		if (log[it] != wxEmptyString) {
			logMsg.Append(log[it] + wxT("\n"));
		}
	}
	wxLogMessage
	(logMsg);
}

void wxGnuPGWrapper::_WriteLog(const wxString log) {
	wxString pr = wxT("%"), prpr = wxT("%%");
	wxString line = log;
	if (line != wxEmptyString) {
		line.Replace(pr.GetData(), prpr.GetData(), true);
		wxLogMessage
		(line);
	}
}

// Extracts key info from search-key-on-server results
//
void wxGnuPGWrapper::_ParseKeySearchList(const wxArrayString &list,
		GpgKeyList &keyList) {
	keyList.DeleteContents(true);
	keyList.Clear();

	unsigned long it = 0;
	wxString token;
	wxGnuPGKeyPair *pair = NULL;

	while (it < list.Count()) {
		// search result (%d)
		if (list.Item(it)[0] == wxT('(')) {
			// cut off name / e-mail
			int pos = list.Item(it).Find(wxT(")"));
			if (pos != wxNOT_FOUND) {
				pair = NULL;

				wxString item = list[it];
				item.Remove(0, pos + 2);
				item.Trim();

				pair = new wxGnuPGKeyPair(true);
				pair->m_key.Name = item;
				it++;
			}
		}
		if (list[it].Find(_("created:")) != wxNOT_FOUND) {
			// parse key prop line : 2048 bit RSA key CA57AD7C, created: 2004-12-06
			wxStringTokenizer tk(list.Item(it), wxT(" ,"));

			// extract ID
			for (int t = 0; t < 7; t++) {
				token = tk.GetNextToken();
			}
			if (pair) {
				pair->m_key.Id = token;
				keyList.Append(pair);
			}
		}
		it++;
	}
}

bool wxGnuPGWrapper::EncryptSymmetric(TaskParams &params) {
	wxString cmdLine =
			wxString::Format(
					wxT(
							"--yes %s --output \"%s\" --no-sk-comment --status-fd 1 --no-tty --command-fd 0 --symmetric \"%s\""),
					params[wxT("armor")].GetData(),
					params[wxT("out")].GetData(),
					params[wxT("file")].GetData());

	wxArrayString in, out, err;
	in.Add(params[wxT("pass")] + wxT("\n"));
	in.Add(params[wxT("pass")] + wxT("\n"));

	return _CallGPGInt(cmdLine, in, out, err);
}
