/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgkey.cpp
// Purpose:     wxGnuPGKey class
// Author:      cod
// Modified by:
// Created:     03/08/2007 16:50:08
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#include "wxGnuPGKey.h"

wxGnuPGKey::wxGnuPGKey(void) :
		Length(0),
		TrustLevel(TRUST_DONT_KNOW),
		m_hasExpirationDate(false) {
	TRUST[wxT("o")] = TRUST[wxT("-")] = TRUST[wxT("q")] = TRUST_DONT_KNOW;
	TRUST[wxT("i")] = TRUST_INVALID_KEY;
	TRUST[wxT("d")] = TRUST_DISABLED_KEY;
	TRUST[wxT("r")] = TRUST_REVOKED_KEY;
	TRUST[wxT("e")] = TRUST_EXPIRED_KEY;
	TRUST[wxT("n")] = TRUST_DO_NOT_TRUST;
	TRUST[wxT("m")] = TRUST_MARGINALLY;
	TRUST[wxT("f")] = TRUST_FULLY;
	TRUST[wxT("u")] = TRUST_ULTIMATELY;

	ALGORITHM[1] = _("RSA");
	ALGORITHM[16] = _("Elgamal");
	ALGORITHM[17] = _("DSA");
	ALGORITHM[20] = _("Elgamal");

	TRUST_STRING[TRUST_DONT_KNOW] = _("Don't know");
	TRUST_STRING[TRUST_DO_NOT_TRUST] = _("Do not trust");
	TRUST_STRING[TRUST_MARGINALLY] = _("Marginally");
	TRUST_STRING[TRUST_FULLY] = _("Fully");
	TRUST_STRING[TRUST_ULTIMATELY] = _("Ultimately");
	TRUST_STRING[TRUST_INVALID_KEY] = _("Invalid key");
	TRUST_STRING[TRUST_DISABLED_KEY] = _("Disabled key");
	TRUST_STRING[TRUST_REVOKED_KEY] = _("Revoked key");
	TRUST_STRING[TRUST_EXPIRED_KEY] = _("Expired key");
	ExpirationDate = wxDateTime(static_cast<time_t>(0));
	CreationDate = wxDateTime(static_cast<time_t>(0));
}

wxGnuPGKey::~wxGnuPGKey(void) {
}

wxString wxGnuPGKey::GetTrustString() {
	return TRUST_STRING[TrustLevel];
}

wxString wxGnuPGKey::GetValidityString() {
	return (TrustLevel != TRUST_INVALID_KEY) ?
			wxString(_("Fully Valid")) : TRUST_STRING[TRUST_INVALID_KEY];
}

wxString wxGnuPGKey::GetExpireDateString() {
	wxString ret;
	if (TrustLevel == TRUST_EXPIRED_KEY) {
		return TRUST_STRING[TRUST_EXPIRED_KEY];
	}
	if (ExpirationDate == wxDateTime(static_cast<time_t>(0))) {
		ret = _("Never");
	} else {
		ret = ExpirationDate.FormatISODate();

	}
	return ret;
}

wxString wxGnuPGKey::GetCreationDateString() const {
	return CreationDate.FormatISODate();
}
