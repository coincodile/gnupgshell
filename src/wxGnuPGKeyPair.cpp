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

#include "wxGnuPGKeyPair.h"

wxGnuPGKeyPair::wxGnuPGKeyPair(bool pub = true) {
	m_isPublic = pub;
	m_lastPassAccess = wxDateTime::Now();
}

wxGnuPGKeyPair::~wxGnuPGKeyPair(void) {
}

bool wxGnuPGKeyPair::IsPublic() const {
	return m_isPublic;
}
