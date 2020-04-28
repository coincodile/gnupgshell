/////////////////////////////////////////////////////////////////////////////
// Name:
// Purpose:
// Author:      cod
// Modified by:
// Created:     30/08/2007 12:43:05
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation ""
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

////@begin includes
////@end includes

#include "app_resources.h"

////@begin XPM images
////@end XPM images

/*!
 * Resource functions
 */

////@begin AppResources resource functions
/*!
 * Menu creation function for ID_POPUP
 */

wxMenu* AppResources::CreateMenuMenu() {
	wxMenu *itemMenu1 = new wxMenu;
	itemMenu1->Append(ID_POPUP_EDIT, _("Edit..."), _T(""), wxITEM_NORMAL);
	itemMenu1->Append(ID_POPUP_EDIT_TRUST, _("Edit Owner Trust..."), _T(""),
			wxITEM_NORMAL);
	itemMenu1->Append(ID_POPUP_DELETE, _("Delete"), _T(""), wxITEM_NORMAL);
	itemMenu1->Append(ID_POPUP_EXPORT, _("Export"), _T(""), wxITEM_NORMAL);
	return itemMenu1;
}

/*!
 * Menu creation function for ID_SETTINGS_MENU
 */

wxMenu* AppResources::CreateSettingsMenu() {
	wxMenu *itemMenu6 = new wxMenu;
	itemMenu6->Append(ID_SETTINGS_SET_DEFAULT, _("Set Default key"), _T(""),
			wxITEM_NORMAL);
	return itemMenu6;
}

/*!
 * Menu creation function for ID_FILEMANAGER_MENU
 */

wxMenu* AppResources::CreateFileManagerMenu() {
	wxMenu *itemMenu8 = new wxMenu;
	itemMenu8->Append(ID_FILEMANAGER_ENCRYPT, _("Encrypt..."), _T(""),
			wxITEM_NORMAL);
	itemMenu8->Append(ID_FILEMANAGER_DECRYPT, _("Decrypt..."), _T(""),
			wxITEM_NORMAL);
	itemMenu8->Append(ID_FILEMANAGER_SIGN, _("Sign..."), _T(""), wxITEM_NORMAL);
	return itemMenu8;
}

////@end AppResources resource functions

/*!
 * Get bitmap resources
 */

wxBitmap AppResources::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin AppResources bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
////@end AppResources bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon AppResources::GetIconResource(const wxString &name) {
	wxUnusedVar(name);
	// Icon retrieval
////@begin AppResources icon retrieval
	wxUnusedVar(name);
	return wxNullIcon;
////@end AppResources icon retrieval
}
