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

#ifndef _APP_RESOURCES_H_
#define _APP_RESOURCES_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface ""
#endif


extern char const *FONT_NAME_COURIER_NEW;
extern char const *FONT_NAME_TAHOMA;
extern char const *FONT_NAME_WXNORMAL_FONT;

/*!
 * Control identifiers
 */
#include <wx/wx.h>
#include <wx/image.h>

////@begin control identifiers
#define ID_POPUP_EDIT 10063
#define ID_POPUP_EDIT_TRUST 10087
#define ID_POPUP_DELETE 10088
#define ID_POPUP_EXPORT 10095
#define ID_SETTINGS_SET_DEFAULT 10098
#define ID_FILEMANAGER_ENCRYPT 10099
#define ID_FILEMANAGER_DECRYPT 10100
#define ID_FILEMANAGER_SIGN 10101
#define ID_FILEMANAGER_VERIFY 10102
////@end control identifiers

class AppResources {
public:
	AppResources() {
	}

	/*!
	 * Resource functions
	 */

////@begin AppResources resource functions
	/// Menu creation function for ID_POPUP
	static wxMenu* CreateMenuMenu();

	/// Menu creation function for ID_SETTINGS_MENU
	static wxMenu* CreateSettingsMenu();

	/// Menu creation function for ID_FILEMANAGER_MENU
	static wxMenu* CreateFileManagerMenu();

	/// Retrieves bitmap resources
	static wxBitmap GetBitmapResource(const wxString &name);

	/// Retrieves icon resources
	static wxIcon GetIconResource(const wxString &name);
////@end AppResources resource functions

};

#endif
// _APP_RESOURCES_H_
