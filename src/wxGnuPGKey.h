/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgkey.h
// Purpose:     wxGnuPGKey class 
// Author:      cod
// Modified by: 
// Created:     03/08/2007 16:50:08
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGNUPGKEY_H_
#define _WXGNUPGKEY_H_

#include <wx/wx.h>
#include <wx/datetime.h>
#include <wx/string.h>
#include <wx/hashmap.h>

enum TRUST_POLICY {
	TRUST_DONT_KNOW = 1,
	TRUST_DO_NOT_TRUST,
	TRUST_MARGINALLY,
	TRUST_FULLY,
	TRUST_ULTIMATELY,
	TRUST_INVALID_KEY,
	TRUST_DISABLED_KEY,
	TRUST_REVOKED_KEY,
	TRUST_EXPIRED_KEY,
};

WX_DECLARE_STRING_HASH_MAP( TRUST_POLICY, KeyTrust );
WX_DECLARE_HASH_MAP( wxByte, wxString, wxIntegerHash, wxIntegerEqual, KeyAlgorithm );
WX_DECLARE_HASH_MAP( TRUST_POLICY, wxString, wxIntegerHash, wxIntegerEqual, TrustString );

// wxGnuPGKey class implements gpg key entity
//
class wxGnuPGKey {
public:
	wxGnuPGKey(void);
	~wxGnuPGKey(void);
	//translate hash
	KeyTrust TRUST;
	//translate hash
	KeyAlgorithm ALGORITHM;
	TrustString TRUST_STRING;

	wxDateTime ExpirationDate;
	wxDateTime CreationDate;
	wxString Name;
	wxString Email;
	wxString Comment;
	wxString Fingerprint;
	wxString Id;
	wxString Algorithm;
	// hash of the user ID contents
	wxString UserIDHash;
	wxUint32 Length;
	TRUST_POLICY TrustLevel;
	wxString GetTrustString();
	wxString GetValidityString();
	wxString GetExpireDateString();
	wxString GetCreationDateString() const;
private:
	bool m_hasExpirationDate;
};

#endif
