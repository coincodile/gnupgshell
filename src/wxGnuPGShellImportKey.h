// Purpose: Settings to import key

#ifndef _WXGNUPGSHELLIMPORTKEY_H_
#define _WXGNUPGSHELLIMPORTKEY_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "wxGnuPGShellImportKey.h"
#endif

#include "wx/statline.h"
#include "wx/listctrl.h"

class wxListView;

#define ID_WXGNUPGSHELLIMPORTKEY 10102
#define ID_IMPORTKEY_SERVER 10103
#define ID_IMPORTKEY_KEY_ID 10110
#define ID_IMPORTKEY_KEY_NAME 10119
#define ID_IMPORTKEY_FIND 10001
#define ID_IMPORTKEY_CLEAR 10123
#define ID_IMPORTKEY_RESULT_LIST 10000
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_TITLE _("Import Key")
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_IDNAME ID_WXGNUPGSHELLIMPORTKEY
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_SIZE wxSize(400, 300)
#define SYMBOL_WXGNUPGSHELLIMPORTKEY_POSITION wxDefaultPosition

class wxGnuPGShellImportKey: public wxDialog {
	DECLARE_DYNAMIC_CLASS (wxGnuPGShellImportKey)DECLARE_EVENT_TABLE()

public:
	/// Constructors
	wxGnuPGShellImportKey();
	wxGnuPGShellImportKey(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_SIZE, long style =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_STYLE);
	~wxGnuPGShellImportKey();

	bool Create(wxWindow *parent, wxWindowID id =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_IDNAME, const wxString &caption =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_TITLE, const wxPoint &pos =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_POSITION, const wxSize &size =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_SIZE, long style =
			SYMBOL_WXGNUPGSHELLIMPORTKEY_STYLE);
	void Init();

	/// Creates the controls and sizers
	void CreateControls();
	void FillColumns();
	void OnIMPORTKEYKEYIDUpdated(wxCommandEvent &event);
	void OnLeftDownImportKey(wxMouseEvent &event);
	void OnKeyIdSetFocus(wxFocusEvent &event);
	void OnIMPORTKEYKEYNAMEUpdated(wxCommandEvent &event);
	void OnLeftDownImportName(wxMouseEvent &event);
	void OnKeyNameSetFocus(wxFocusEvent &event);
	void OnIMPORTKEYFINDClick(wxCommandEvent &event);
	void OnIMPORTKEYFINDUpdate(wxUpdateUIEvent &event);
	void OnIMPORTKEYCLEARClick(wxCommandEvent &event);
	void OnOKUpdate(wxUpdateUIEvent &event);

	wxBitmap GetBitmapResource(const wxString &name);
	wxIcon GetIconResource(const wxString &name);
	static bool ShowToolTips();

	wxChoice *m_importServer;
	wxTextCtrl *m_keyIdText;
	wxTextCtrl *m_keyNameText;
	wxListView *m_resultKeyList;
};

#endif
// _WXGNUPGSHELLIMPORTKEY_H_
