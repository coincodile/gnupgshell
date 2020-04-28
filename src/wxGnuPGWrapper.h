/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgwrapper.h
// Purpose:     wxGnuPGWrapper class
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:50:08
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

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

// fwds
class wxGnuPGWrapper;
class wxGnuPGShellApp;

enum wxGnuPGTask {
    TASK_GEN_KEY,
    TASK_GEN_REVOKE,
    TASK_LISTKEYS,
    TASK_SET_OWNERTRUST,
    TASK_REFRESH,
    TASK_SEND_KEYS,
    TASK_DEL_KEY,
    TASK_DEL_PAIR,
    TASK_SIGN_KEY,
    TASK_RECV_KEYS,
    TASK_KEY_IMPORT,
    TASK_KEY_EXPORT,
    TASK_SEC_KEY_EXPORT,
    TASK_UPDATE_TRUSTDB,
    TASK_EXPORT_TRUST,
    TASK_IMPORT_TRUST,
    TASK_CHANGE_PASS,
    TASK_CHANGE_EXPIRATION,
    TASK_SIGN_DOCUMENT,
    TASK_ENCRYPT_SIGN_DOCUMENT,
    TASK_ENCRYPT_DOCUMENT,
    TASK_ENCRYPT_SYM_DOCUMENT,
    TASK_DECRYPT_DOCUMENT,
    TASK_CLEARSIGN_DOCUMENT,
    TASK_VERIFY_FILES
};

enum KeyParseState {
    STATE_KEY,
    STATE_SUB,
};

WX_DECLARE_STRING_HASH_MAP(wxString, TaskParams);
WX_DECLARE_HASH_MAP(wxGnuPGTask, wxString, wxIntegerHash, wxIntegerEqual, SuccessKey);
WX_DECLARE_LIST(wxGnuPGKeyPair, GpgKeyList);

class wxGnuPGWrapper
{
    wxString    m_keyRing;
    wxGnuPGTask m_task;
    SuccessKey  m_successKey;
    wxString    m_gpgCmd;
    wxProcess  *m_gpgProcess;
    wxString    m_gpgPath;
    wxString    m_keyringPath;
    wxTextCtrl *m_logWindow;
    GpgKeyList  m_keyList;

    wxString    _OpenGPGProcess(const wxString cmdLine, wxOutputStream * &out, wxInputStream * &in, wxInputStream * &err);
    bool        _CallGPG(const wxString cmdLine, wxArrayString &stdOut, wxArrayString &stdErr);
    bool        _CallGPGInt(const wxString cmdLine, wxArrayString &stdIn, wxArrayString &stdOut, wxArrayString &stdErr);
    wxByte      _ParseKeys(const wxArrayString gpgOutput);
    void        _ParseFpr(const wxString line, wxGnuPGKey &key);
    void        _ParseUid(const wxString line, wxGnuPGKey &key);
    void        _ParseKey(const wxString line, wxGnuPGKey &key);
    void        _WriteLog(const wxArrayString log);
    void        _WriteLog(const wxString log);
    void        _ParseKeySearchList(const wxArrayString &list, GpgKeyList & keyList);

public:
    wxGnuPGWrapper(wxGnuPGShellApp *parent);
    ~wxGnuPGWrapper(void);

    // Automated runs task coded by task
    bool         RunTask(const wxGnuPGTask task, TaskParams & params);
    void         SetGPGPath(const wxString path);
    wxString     GetGPGPath() const;
    GpgKeyList & GetKeyList();

    // intermediate function to list keys on remote server
    bool         SearchKeys(TaskParams & params, GpgKeyList & keyList);

protected:
    // Runs gpg for key generations
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
