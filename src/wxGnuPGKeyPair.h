/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgkeypair.h
// Purpose:     wxGnuPGKeyPair class
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:50:08
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGKEYPAIR_H_
#define _WXGNUPGKEYPAIR_H_

#include <wx/wx.h>
#include <wx/datetime.h>
#include <wx/string.h>
#include <wx/hashmap.h>
#include "wxGnuPGKey.h"

class wxGnuPGShellApp;

class wxGnuPGKeyPair {
	wxString m_pass;
	wxDateTime m_lastPassAccess;

public:
	wxGnuPGKeyPair(bool pub);
	~wxGnuPGKeyPair(void);
	bool IsPublic(void) const;
	bool m_isPublic;
	wxGnuPGKey m_key;
	wxGnuPGKey m_subKey;
	bool IsPassCacheEmpty() const {
		return m_pass.IsEmpty();
	}
	void ClearPassCache() {
		m_pass.Clear();
	}

protected:
	friend class wxGnuPGShellApp;
};

#endif // _WXGNUPGKEYPAIR_H_
