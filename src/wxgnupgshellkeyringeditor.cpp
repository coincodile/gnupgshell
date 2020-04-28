/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellkeyringeditor.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 15:45:44
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellkeyringeditor.h"
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
////@end includes

#include "wxgnupgshellkeyringeditor.h"
#include "wxGnuPGShellAboutDialog.h"
#include "wxgnupgshellapp.h"
#include "wxgnupgshelltrust.h"
#include "wxgnupgshelleditkey.h"
#include "wxgnupgshellfilemanager.h"
#include "wxgnupgshellsettings.h"
#include "wxgnupgshellbackup.h"
#include <wx/busyinfo.h>
#include <wx/textdlg.h>
#include "wxgnupgshellkeygenwizard.h"
#include <wx/propgrid/propgrid.h>
#include <wx/config.h>
#include "wxgnupgshelleditkey.h"
#include "app_resources.h"
#include "wxGnuPGShellImportKey.h"
#include "wxGnuPGShellRevokeKey.h"

////@begin XPM images
#include "wxwin32x32.xpm"
#include "exit-16x16x32b.xpm"
#include "settings-16x16x32b.xpm"
#include "refresh-16x16x32b.xpm"
#include "new.xpm"
#include "delete-16x16x32b.xpm"
#include "retreive-16x16x32b.xpm"
#include "send-16x16x32b.xpm"
#include "file_manager-16x16x32b.xpm"
#include "htmbook.xpm"
////@end XPM images

/*!
 * wxGnuPGShellKeyringEditor type definition
 */

IMPLEMENT_CLASS(wxGnuPGShellKeyringEditor, wxFrame)

/*!
 * wxGnuPGShellKeyringEditor event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellKeyringEditor, wxFrame )

////@begin wxGnuPGShellKeyringEditor event table entries
EVT_CLOSE( wxGnuPGShellKeyringEditor::OnCloseWindow )
EVT_WINDOW_DESTROY( wxGnuPGShellKeyringEditor::OnDestroy )

EVT_MENU( wxID_EXIT, wxGnuPGShellKeyringEditor::OnEXITClick )

EVT_MENU( ID_SELECT_LANGUAGE, wxGnuPGShellKeyringEditor::OnSelectLanguageClick )

EVT_MENU( ID_MENU_CLEAR_LOG, wxGnuPGShellKeyringEditor::OnMenuClearLogClick )

EVT_MENU( ID_MENU_PREFERENCES, wxGnuPGShellKeyringEditor::OnMenuPreferencesClick )

EVT_MENU( ID_MENU_REFRESH, wxGnuPGShellKeyringEditor::OnMenuRefreshClick )
EVT_UPDATE_UI( ID_MENU_REFRESH, wxGnuPGShellKeyringEditor::OnMenuRefreshUpdate )

EVT_MENU( ID_MENU_UPDATE_TRUSTDB, wxGnuPGShellKeyringEditor::OnMenuUpdateTrustdbClick )
EVT_UPDATE_UI( ID_MENU_UPDATE_TRUSTDB, wxGnuPGShellKeyringEditor::OnMenuUpdateTrustdbUpdate )

EVT_MENU( ID_MENU_KEY_PUB, wxGnuPGShellKeyringEditor::OnMenuKeyPubClick )
EVT_UPDATE_UI( ID_MENU_KEY_PUB, wxGnuPGShellKeyringEditor::OnMenuKeyPubUpdate )

EVT_MENU( ID_MENU_KEY_SEC, wxGnuPGShellKeyringEditor::OnMenuKeySecClick )
EVT_UPDATE_UI( ID_MENU_KEY_SEC, wxGnuPGShellKeyringEditor::OnMenuKeySecUpdate )

EVT_MENU( ID_MENU_SELECT_ALL, wxGnuPGShellKeyringEditor::OnMenuSelectAllClick )
EVT_UPDATE_UI( ID_MENU_SELECT_ALL, wxGnuPGShellKeyringEditor::OnMenuSelectAllUpdate )

EVT_MENU( ID_MENU_NEW_KEY, wxGnuPGShellKeyringEditor::OnMenuNewKeyClick )
EVT_UPDATE_UI( ID_MENU_NEW_KEY, wxGnuPGShellKeyringEditor::OnMenuNewKeyUpdate )

EVT_MENU( ID_MENU_DEL_KEY, wxGnuPGShellKeyringEditor::OnMenuDelKeyClick )
EVT_UPDATE_UI( ID_MENU_DEL_KEY, wxGnuPGShellKeyringEditor::OnMenuDelKeyUpdate )

EVT_MENU( ID_MENU_EDIT_KEY, wxGnuPGShellKeyringEditor::OnMenuEditKeyClick )
EVT_UPDATE_UI( ID_MENU_EDIT_KEY, wxGnuPGShellKeyringEditor::OnMenuEditKeyUpdate )

EVT_MENU( ID_MENU_OWNER_TRUST, wxGnuPGShellKeyringEditor::OnMenuOwnerTrustClick )
EVT_UPDATE_UI( ID_MENU_OWNER_TRUST, wxGnuPGShellKeyringEditor::OnMenuOwnerTrustUpdate )

EVT_MENU( ID_MENU_REVOKE_KEY, wxGnuPGShellKeyringEditor::OnMENUREVOKEKEYClick )
EVT_UPDATE_UI( ID_MENU_REVOKE_KEY, wxGnuPGShellKeyringEditor::OnMENUREVOKEKEYUpdate )

EVT_MENU( ID_MENU_IMPORT_KEY, wxGnuPGShellKeyringEditor::OnMenuImportKeyClick )
EVT_UPDATE_UI( ID_MENU_IMPORT_KEY, wxGnuPGShellKeyringEditor::OnMenuImportKeyUpdate )

EVT_MENU( ID_MENU_EXPORT_KEY, wxGnuPGShellKeyringEditor::OnMenuExportKeyClick )
EVT_UPDATE_UI( ID_MENU_EXPORT_KEY, wxGnuPGShellKeyringEditor::OnMenuExportKeyUpdate )

EVT_MENU( ID_MENU_RETRIEVE_KEY, wxGnuPGShellKeyringEditor::OnMenuRetrieveKeyClick )
EVT_UPDATE_UI( ID_MENU_RETRIEVE_KEY, wxGnuPGShellKeyringEditor::OnMenuRetrieveKeyUpdate )

EVT_MENU( ID_MENU_SEND_KEYS, wxGnuPGShellKeyringEditor::OnMenuSendKeysClick )
EVT_UPDATE_UI( ID_MENU_SEND_KEYS, wxGnuPGShellKeyringEditor::OnMenuSendKeysUpdate )

EVT_MENU( ID_MENU_FILEMANAGER, wxGnuPGShellKeyringEditor::OnMenuFilemanagerClick )
EVT_UPDATE_UI( ID_MENU_FILEMANAGER, wxGnuPGShellKeyringEditor::OnMenuFilemanagerUpdate )

EVT_MENU( ID_MENU_CLEAR_PASS_CACHE, wxGnuPGShellKeyringEditor::OnMENUCLEARPASSCACHEClick )

EVT_MENU( wxID_ABOUT, wxGnuPGShellKeyringEditor::OnABOUTClick )

EVT_MENU( ID_KE_TOOL_EDIT, wxGnuPGShellKeyringEditor::OnMenuEditKeyClick )
EVT_UPDATE_UI( ID_KE_TOOL_EDIT, wxGnuPGShellKeyringEditor::OnKeToolEditUpdate )

EVT_MENU( ID_KE_TOOL_DELETE, wxGnuPGShellKeyringEditor::OnMenuDelKeyClick )
EVT_UPDATE_UI( ID_KE_TOOL_DELETE, wxGnuPGShellKeyringEditor::OnKeToolDeleteUpdate )

EVT_MENU( ID_KE_TOOL_IMPORT, wxGnuPGShellKeyringEditor::OnMenuImportKeyClick )
EVT_UPDATE_UI( ID_KE_TOOL_IMPORT, wxGnuPGShellKeyringEditor::OnKeToolImportUpdate )

EVT_MENU( ID_KE_TOOL_EXPORT, wxGnuPGShellKeyringEditor::OnMenuExportKeyClick )
EVT_UPDATE_UI( ID_KE_TOOL_EXPORT, wxGnuPGShellKeyringEditor::OnKeToolExportUpdate )

EVT_MENU( ID_KE_TOOL_REFRESH, wxGnuPGShellKeyringEditor::OnMenuRefreshClick )
EVT_UPDATE_UI( ID_KE_TOOL_REFRESH, wxGnuPGShellKeyringEditor::OnKeToolRefreshUpdate )

EVT_MENU( ID_KE_TOOL_FILES, wxGnuPGShellKeyringEditor::OnMenuFilemanagerClick )
EVT_UPDATE_UI( ID_KE_TOOL_FILES, wxGnuPGShellKeyringEditor::OnKeToolFilesUpdate )

EVT_LIST_ITEM_SELECTED( ID_KE_KEYLIST, wxGnuPGShellKeyringEditor::OnKeKeylistSelected )

EVT_UPDATE_UI( ID_KE_STAT_BAR, wxGnuPGShellKeyringEditor::OnKESTATBARUpdate )

////@end wxGnuPGShellKeyringEditor event table entries

EVT_MENU( ID_POPUP_EDIT, wxGnuPGShellKeyringEditor::OnMenuEditKeyClick )
EVT_UPDATE_UI( ID_POPUP_EDIT, wxGnuPGShellKeyringEditor::OnKeToolEditUpdate )
EVT_MENU( ID_POPUP_DELETE, wxGnuPGShellKeyringEditor::OnMenuDelKeyClick )
EVT_MENU( ID_POPUP_EDIT_TRUST, wxGnuPGShellKeyringEditor::OnMenuOwnerTrustClick )
EVT_MENU( ID_POPUP_EXPORT, wxGnuPGShellKeyringEditor::OnMenuExportKeyClick )

END_EVENT_TABLE()

/*!
 * wxGnuPGShellKeyringEditor constructors
 */

wxGnuPGShellKeyringEditor::wxGnuPGShellKeyringEditor() {
	Init();
}

wxGnuPGShellKeyringEditor::wxGnuPGShellKeyringEditor(wxWindow *parent,
		wxWindowID id, const wxString &caption, const wxPoint &pos,
		const wxSize &size, long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellKeyringEditor creator
 */

bool wxGnuPGShellKeyringEditor::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellKeyringEditor creation
	wxFrame::Create(parent, id, caption, pos, size, style);

	CreateControls();
	SetIcon(GetIconResource(wxT("wxwin32x32.xpm")));
	Centre();
////@end wxGnuPGShellKeyringEditor creation
	return true;
}

/*!
 * wxGnuPGShellKeyringEditor destructor
 */

wxGnuPGShellKeyringEditor::~wxGnuPGShellKeyringEditor() {
	// Avoiding memory leaks
	wxAuiNotebook *noteBook = wxDynamicCast(m_keyProperty->GetParent(),
			wxAuiNotebook);
	while (noteBook->GetPageCount()) {
		noteBook->RemovePage(0);
	}
	wxDELETE(m_popupMenu);
////@begin wxGnuPGShellKeyringEditor destruction
	GetAuiManager().UnInit();
////@end wxGnuPGShellKeyringEditor destruction
}

/*!
 * Member initialisation
 */

void wxGnuPGShellKeyringEditor::Init() {
////@begin wxGnuPGShellKeyringEditor member initialisation
	m_keyListCtrl = NULL;
	m_statusBar = NULL;
	m_auiNotebook = NULL;
	m_keyProperty = NULL;
	m_logText = NULL;
////@end wxGnuPGShellKeyringEditor member initialisation
}

/*!
 * Control creation for wxGnuPGShellKeyringEditor
 */

void wxGnuPGShellKeyringEditor::CreateControls() {
////@begin wxGnuPGShellKeyringEditor content construction
	wxGnuPGShellKeyringEditor *itemFrame1 = this;

	GetAuiManager().SetManagedWindow(this);

	wxMenuBar *menuBar = new wxMenuBar;
	wxMenu *itemMenu3 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu3, wxID_EXIT,
				_("E&xit\tAlt+F4"), _T(""), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("exit-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu3->Append(menuItem);
	}
	menuBar->Append(itemMenu3, _("&File"));
	wxMenu *itemMenu5 = new wxMenu;
	itemMenu5->Append(ID_SELECT_LANGUAGE, _("&Language..."),
			_("Select interface language"), wxITEM_NORMAL);
	itemMenu5->AppendSeparator();
	itemMenu5->Append(ID_MENU_CLEAR_LOG, _("&Clear log"), _T(""),
			wxITEM_NORMAL);
	itemMenu5->AppendSeparator();
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu5, ID_MENU_PREFERENCES,
				_("&Preferences..."), _("Program settings"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("settings-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu5->Append(menuItem);
	}
	menuBar->Append(itemMenu5, _("&View"));
	wxMenu *itemMenu11 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu11, ID_MENU_REFRESH,
				_("&Refresh\tF5"), _("Reread keyring"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("refresh-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu11->Append(menuItem);
	}
	itemMenu11->Append(ID_MENU_UPDATE_TRUSTDB, _("Refresh &Trust DB"),
			_("Update trust information"), wxITEM_NORMAL);
	itemMenu11->AppendSeparator();
	itemMenu11->Append(ID_MENU_KEY_PUB, _("P&ublic Keyring"),
			_("Show keys in public keyring"), wxITEM_RADIO);
	itemMenu11->Check(ID_MENU_KEY_PUB, true);
	itemMenu11->Append(ID_MENU_KEY_SEC, _("&Secret Keyring"),
			_("Show keys in secret keyring"), wxITEM_RADIO);
	itemMenu11->AppendSeparator();
	itemMenu11->Append(ID_MENU_SELECT_ALL, _("Select &All\tCtrl+A"),
			_("Select all keys in current keyring"), wxITEM_NORMAL);
	itemMenu11->AppendSeparator();
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu11, ID_MENU_NEW_KEY,
				_("Generate &New...\tCtrl+N"), _("Generate new key"),
				wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("new.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu11->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu11, ID_MENU_DEL_KEY,
				_("&Delete...\tDel"), _("Delete selected keys from keyring"),
				wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("delete-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu11->Append(menuItem);
	}
	itemMenu11->Enable(ID_MENU_DEL_KEY, false);
	itemMenu11->AppendSeparator();
	itemMenu11->Append(ID_MENU_EDIT_KEY, _("&Edit...\tCtrl+E"),
			_("Allow to change key properties"), wxITEM_NORMAL);
	itemMenu11->Enable(ID_MENU_EDIT_KEY, false);
	itemMenu11->Append(ID_MENU_OWNER_TRUST, _("Set &Owner Trust..."),
			_("Set or change owner trust of selected keys"), wxITEM_NORMAL);
	itemMenu11->AppendSeparator();
	itemMenu11->Append(ID_MENU_REVOKE_KEY, _("Revoke..."), _T(""),
			wxITEM_NORMAL);
	itemMenu11->AppendSeparator();
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu11, ID_MENU_IMPORT_KEY,
				_("&Import..."), _("Import keys from files"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("retreive-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu11->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu11, ID_MENU_EXPORT_KEY,
				_("E&xport..."), _("Export selected keys to files"),
				wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("send-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu11->Append(menuItem);
	}
	itemMenu11->Enable(ID_MENU_EXPORT_KEY, false);
	menuBar->Append(itemMenu11, _("&Keys"));
	wxMenu *itemMenu30 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu30, ID_MENU_RETRIEVE_KEY,
				_("&Retrieve Keys..."),
				_("Get key from default keyserver by it's ID"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("retreive-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu30->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu30, ID_MENU_SEND_KEYS,
				_("&Send Keys..."),
				_("Send selected keys to default keyserver"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("send-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu30->Append(menuItem);
	}
	itemMenu30->Enable(ID_MENU_SEND_KEYS, false);
	menuBar->Append(itemMenu30, _("&Server"));
	wxMenu *itemMenu33 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu33, ID_MENU_FILEMANAGER,
				_("&Filemanager"),
				_("Run filemanager for encrypt/decrypt files"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(
						wxT("file_manager-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu33->Append(menuItem);
	}
	itemMenu33->Append(ID_MENU_CLEAR_PASS_CACHE, _("&Clear Passphrase Cache"),
			_T(""), wxITEM_NORMAL);
	menuBar->Append(itemMenu33, _("&Tools"));
	wxMenu *itemMenu36 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu36, wxID_ABOUT,
				_("&About...\tF1"), _T(""), wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("htmbook.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu36->Append(menuItem);
	}
	menuBar->Append(itemMenu36, _("&Help"));
	itemFrame1->SetMenuBar(menuBar);

	wxToolBar *itemToolBar38 = new wxToolBar(itemFrame1,
			ID_TOOLBAR_KEYRING_EDITOR, wxDefaultPosition, wxDefaultSize,
			wxTB_FLAT | wxTB_HORIZONTAL | wxTB_NODIVIDER);
	itemToolBar38->SetToolBitmapSize(wxSize(32, 32));
	wxBitmap itemtool39Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/pen_yellow.ico")));
	wxBitmap itemtool39BitmapDisabled;
	itemToolBar38->AddTool(ID_KE_TOOL_EDIT, _("Edit"), itemtool39Bitmap,
			itemtool39BitmapDisabled, wxITEM_NORMAL, _("Edit"), wxEmptyString);
	wxBitmap itemtool40Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/delete.ico")));
	wxBitmap itemtool40BitmapDisabled;
	itemToolBar38->AddTool(ID_KE_TOOL_DELETE, _("Delete"), itemtool40Bitmap,
			itemtool40BitmapDisabled, wxITEM_NORMAL, _("Delete"),
			wxEmptyString);
	wxBitmap itemtool41Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/retreive.ico")));
	wxBitmap itemtool41BitmapDisabled;
	itemToolBar38->AddTool(ID_KE_TOOL_IMPORT, _("Import"), itemtool41Bitmap,
			itemtool41BitmapDisabled, wxITEM_NORMAL, _("Import"),
			wxEmptyString);
	wxBitmap itemtool42Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/send.ico")));
	wxBitmap itemtool42BitmapDisabled;
	itemToolBar38->AddTool(ID_KE_TOOL_EXPORT, _("Export"), itemtool42Bitmap,
			itemtool42BitmapDisabled, wxITEM_NORMAL, _("Export"),
			wxEmptyString);
	itemToolBar38->AddSeparator();
	wxBitmap itemtool44Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/refresh.ico")));
	wxBitmap itemtool44BitmapDisabled;
	itemToolBar38->AddTool(ID_KE_TOOL_REFRESH, _("Refresh"), itemtool44Bitmap,
			itemtool44BitmapDisabled, wxITEM_NORMAL, _("Refresh"),
			_("Refresh key list"));
	itemToolBar38->AddSeparator();
	wxBitmap itemtool46Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/file_manager.ico")));
	wxBitmap itemtool46BitmapDisabled;
	itemToolBar38->AddTool(ID_KE_TOOL_FILES, _("Files"), itemtool46Bitmap,
			itemtool46BitmapDisabled, wxITEM_NORMAL, _("File Manager"),
			_("Open Filemanager"));
	itemToolBar38->Realize();
	itemFrame1->GetAuiManager().AddPane(itemToolBar38,
			wxAuiPaneInfo().ToolbarPane().Name(_T("Pane1")).Top().Layer(10).LeftDockable(
					false).RightDockable(false).CaptionVisible(false).CloseButton(
					false).DestroyOnClose(false).Resizable(false).Floatable(
					false).Gripper(true));

	m_keyListCtrl = new wxGnuPGKeyListCtrl(itemFrame1, ID_KE_KEYLIST,
			wxDefaultPosition, wxSize(100, 100), wxLC_REPORT | wxLC_VIRTUAL);
	itemFrame1->GetAuiManager().AddPane(m_keyListCtrl,
			wxAuiPaneInfo().Name(_T("Pane2")).Caption(_T("Public keyring")).Centre().MinSize(
					wxSize(-1, 200)).CloseButton(false).DestroyOnClose(false).Resizable(
					true).Floatable(false).PaneBorder(false));

	m_statusBar = new wxStatusBar(itemFrame1, ID_KE_STAT_BAR, wxST_SIZEGRIP);
	m_statusBar->SetFieldsCount(4);
	itemFrame1->SetStatusBar(m_statusBar);

	m_auiNotebook = new wxAuiNotebook(itemFrame1, ID_KE_MAIN_NOTEBOOK,
			wxDefaultPosition, wxSize(-1, 150), wxNO_BORDER);

	m_keyProperty = new wxPropertyGrid(m_auiNotebook, ID_KE_KEYPROPERTY,
			wxDefaultPosition, wxSize(100, 200), wxNO_BORDER);

	m_auiNotebook->AddPage(m_keyProperty, _("Properties"), false);

	m_logText = new wxTextCtrl(m_auiNotebook, ID_KE_LOGTEXT, _T(""),
			wxDefaultPosition, wxDefaultSize,
			wxTE_MULTILINE | wxTE_READONLY | wxNO_BORDER);
	m_logText->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Courier New")));

	m_auiNotebook->AddPage(m_logText, _("Log"), false);

	itemFrame1->GetAuiManager().AddPane(m_auiNotebook,
			wxAuiPaneInfo().Name(_T("InfoBar")).Bottom().BestSize(
					wxSize(-1, 200)).CaptionVisible(false).CloseButton(false).DestroyOnClose(
					false).Resizable(true).Floatable(false).PaneBorder(false));

	GetAuiManager().Update();

	// Connect events and objects
	itemFrame1->Connect(ID_WXGNUPGSHELLKEYRINGEDITOR, wxEVT_DESTROY,
			wxWindowDestroyEventHandler(wxGnuPGShellKeyringEditor::OnDestroy),
			NULL, this);
	m_keyListCtrl->Connect(ID_KE_KEYLIST, wxEVT_CONTEXT_MENU,
			wxContextMenuEventHandler(wxGnuPGShellKeyringEditor::OnContextMenu),
			NULL, this);
////@end wxGnuPGShellKeyringEditor content construction
	wxLog *oldTarget = wxLog::SetActiveTarget(new wxLogTextCtrl(m_logText));
	wxDELETE(oldTarget);
	wxLogMessage
	(_("GUI Created"));

#ifndef __WXMSW__
	m_keyListCtrl->Connect(wxID_ANY, wxEVT_RIGHT_DOWN,
			wxMouseEventHandler(wxGnuPGShellKeyringEditor::OnKeyListRightDown),
			NULL, this);
#endif
	m_popupMenu = NULL;

	//wxGetApp().SetLogWindow(m_logText);
	m_keyRing = _("Public");
	m_isPublicKeyring = true;
	m_isSelectedAll = false;
	FillKeyListColumns();
	m_keyListCtrl->SetItemCount(
			static_cast<long>(wxGetApp().GetKeyList().GetCount()));
	// property grid
	FillProperties();

	LoadWindowsSettings();
}

void wxGnuPGShellKeyringEditor::FillProperties() {
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxPGProperty(_("User Name"), wxT("UserName"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Key ID"), wxT("KeyID"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Fingerprint"),
							wxT("Fingerprint"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Expires at"), wxT("ExpiresAt"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Owner Trust"), wxT("OwnerTrust"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Key Validity"),
							wxT("KeyValidity"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Key Type"), wxT("KeyType"))));
	m_keyProperty->SetPropertyReadOnly(
			m_keyProperty->Append(
					new wxStringProperty(_("Created at"), wxT("CreatedAt"))));
}

void wxGnuPGShellKeyringEditor::FillKeyListColumns() {
	if (!m_keyListCtrl->GetColumnCount()) {
		m_keyListCtrl->InsertColumn(0, _("User ID"));
		m_keyListCtrl->InsertColumn(1, _("Key ID"));
		m_keyListCtrl->InsertColumn(2, _("Type"));
		m_keyListCtrl->InsertColumn(3, _("Owner Trust"));
		m_keyListCtrl->InsertColumn(4, _("Expiry Date"));
	}
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellKeyringEditor::ShowToolTips() {
	return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellKeyringEditor::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellKeyringEditor bitmap retrieval
	wxUnusedVar(name);
	if (name == _T("exit-16x16x32b.xpm")) {
		wxBitmap bitmap(exit_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("settings-16x16x32b.xpm")) {
		wxBitmap bitmap(settings_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("refresh-16x16x32b.xpm")) {
		wxBitmap bitmap(refresh_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("new.xpm")) {
		wxBitmap bitmap(new_xpm);
		return bitmap;
	} else if (name == _T("delete-16x16x32b.xpm")) {
		wxBitmap bitmap(delete_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("retreive-16x16x32b.xpm")) {
		wxBitmap bitmap(retreive_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("send-16x16x32b.xpm")) {
		wxBitmap bitmap(send_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("file_manager-16x16x32b.xpm")) {
		wxBitmap bitmap(file_manager_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("htmbook.xpm")) {
		wxBitmap bitmap(htmbook_xpm);
		return bitmap;
	} else if (name == _T("art/pen_yellow.ico")) {
		wxIcon icon(_T("art/pen_yellow.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/delete.ico")) {
		wxIcon icon(_T("art/delete.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/retreive.ico")) {
		wxIcon icon(_T("art/retreive.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/send.ico")) {
		wxIcon icon(_T("art/send.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/refresh.ico")) {
		wxIcon icon(_T("art/refresh.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/file_manager.ico")) {
		wxIcon icon(_T("art/file_manager.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	}
	return wxNullBitmap;
////@end wxGnuPGShellKeyringEditor bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellKeyringEditor::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellKeyringEditor icon retrieval
	wxUnusedVar(name);
	if (name == _T("wxwin32x32.xpm")) {
		wxIcon icon(wxwin32x32_xpm);
		return icon;
	}
	return wxNullIcon;
////@end wxGnuPGShellKeyringEditor icon retrieval
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
 */

void wxGnuPGShellKeyringEditor::OnEXITClick(wxCommandEvent &event) {
	Close();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
 */

void wxGnuPGShellKeyringEditor::OnABOUTClick(wxCommandEvent &event) {
	wxGnuPGShellAboutDialog *dlg = new wxGnuPGShellAboutDialog(this);
	dlg->ShowModal();
	dlg->Destroy();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_FILEMANAGER
 */

void wxGnuPGShellKeyringEditor::OnMenuFilemanagerClick(wxCommandEvent &event) {
	// Show filemanager
	wxGnuPGShellFileManager *fileManagerDlg = new wxGnuPGShellFileManager(this);
	fileManagerDlg->Show();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REFRESH
 */

void wxGnuPGShellKeyringEditor::OnMenuRefreshClick(wxCommandEvent &event) {
	RefreshKeyList();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SELECT_ALL
 */

void wxGnuPGShellKeyringEditor::OnMenuSelectAllClick(wxCommandEvent &event) {
	int n = m_keyListCtrl->GetItemCount();
	int select = m_isSelectedAll ? 0 : wxLIST_STATE_SELECTED;
	m_isSelectedAll = !m_isSelectedAll;

	for (int i = 0; i < n; i++) {
		m_keyListCtrl->SetItemState(i, select, wxLIST_STATE_SELECTED);
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_PREFERENCES
 */

void wxGnuPGShellKeyringEditor::OnMenuPreferencesClick(wxCommandEvent &event) {
	wxGnuPGShellSettings *setDlg = new wxGnuPGShellSettings(this);

	if (setDlg->ShowModal() == wxID_OK) {
		wxGetApp().m_defaultKeyServer = setDlg->m_defServerCombo->GetString(
				setDlg->m_defServerCombo->GetSelection());
		wxGetApp().m_defKey = setDlg->m_keyListCtrl->GetItemText(
				setDlg->m_selectedKey);
		wxGetApp().UseCache(setDlg->m_useCache->GetValue());
		wxGetApp().SetCacheTime(setDlg->m_cacheTime->GetValue());

		// save items from server combo to wxGetApp().m_serverList
		wxGetApp().m_serverList.Clear();
		wxString item;
		for (wxUint16 it = 0; it < setDlg->m_defServerCombo->GetCount(); it++) {
			item = setDlg->m_defServerCombo->GetString(it);
			if (item != wxEmptyString) {
				wxGetApp().m_serverList.Add(item);
			}
		}
	}
	setDlg->Destroy();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_NEW_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuNewKeyClick(wxCommandEvent &event) {
	// generate keys
	m_auiNotebook->SetSelection(1);
	if (wxGetApp().GenerateKey()) {
		wxSleep(1);
		RefreshKeyList();
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_DEL_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuDelKeyClick(wxCommandEvent &event) {
	// delete keys
	bool delSecret = false;
	if (wxMessageBox(_("You really want to delete selected keys?"),
			_("Delete keys"), wxYES_NO) == wxYES) {
		delSecret = wxMessageBox(_("Delete secret keys also?"),
				_("Delete secret keys"), wxYES_NO) == wxYES;
		wxBusyInfo *info = new wxBusyInfo(_("Please wait, deleting keys..."),
				this);

		wxArrayLong list;
		long index = m_keyListCtrl->GetFirstSelected();
		while (index != wxNOT_FOUND) {
			list.Add(index);
			index = m_keyListCtrl->GetNextSelected(index);
		}
		// reverse direction
		for (int i = static_cast<int>(list.GetCount()) - 1; i > -1; i--) {
			if (delSecret) {
				wxGetApp().DeleteKeyPair(wxGetApp().GetKeyId(list.Item(i)),
						wxGetApp().GetKeyFingerprint(list.Item(i)),
						list.Item(i));
			} else {
				wxGetApp().DeleteKey(wxGetApp().GetKeyId(list.Item(i)),
						list.Item(i));
			}
		}
		wxDELETE(info);
		RefreshKeyList();
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SIGN_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuEditKeyClick(wxCommandEvent &event) {
	// edit selected key
	wxGnuPGShellEditKey *editDlg = new wxGnuPGShellEditKey(this);
	long index = m_keyListCtrl->GetFirstSelected();
	wxGnuPGKey *key = wxGetApp().GetKey(index);

	if (key) {
		editDlg->m_userName->SetLabel(key->Name);
		editDlg->m_keyID->SetLabel(key->Id);
		editDlg->m_expiryDate->SetLabel(key->GetExpireDateString());
		editDlg->ShowModal();
		RefreshKeyList();
	}
	editDlg->Destroy();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_OWNER_TRUST
 */

void wxGnuPGShellKeyringEditor::OnMenuOwnerTrustClick(wxCommandEvent &event) {
	unsigned long index = m_keyListCtrl->GetFirstSelected();
	wxGnuPGKey *key = NULL;

	if ((key = wxGetApp().GetKey(index))) {
		// show trust dialog
		wxGnuPGShellTrust *trustDlg = new wxGnuPGShellTrust(this);
		trustDlg->m_trustKeyID->SetLabel(key->Id);
		trustDlg->m_trustName->SetLabel(key->Name);
		trustDlg->m_trust = key->TrustLevel;
		trustDlg->SetTrust();

		if (trustDlg->ShowModal() == wxID_OK) {
			int trust = trustDlg->GetTrust();
			if (wxMessageBox(_("Do you really want to change owner trust?"),
					_("Change owner trust"), wxYES_NO) == wxYES) {
				if (wxGetApp().SetOwnerTrust(wxGetApp().GetKeyId(index),
						trust)) {
					RefreshKeyList();
				}
			}
		}
		trustDlg->Destroy();
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_IMPORT_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuImportKeyClick(wxCommandEvent &event) {
	wxUnusedVar(event);
	wxGnuPGShellBackup *backup = new wxGnuPGShellBackup(this);
	backup->m_importKey = true;

	backup->m_keyId->SetLabel(wxT("*"));
	if (backup->ShowModal() == wxID_OK) {
		for (wxUint8 it = 0; it < backup->m_paths.GetCount(); it++) {
			wxGetApp().ImportKey(backup->m_paths[it]);
		}

		wxSleep(1);
		RefreshKeyList();
	}
	backup->Destroy();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_EXPORT_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuExportKeyClick(wxCommandEvent &event) {
	wxGnuPGShellBackup *backup = new wxGnuPGShellBackup(this);
	backup->m_importKey = false;

	long index = m_keyListCtrl->GetFirstSelected();
	while (index != wxNOT_FOUND) {
		backup->m_keyId->SetLabel(wxGetApp().GetKeyId(index));
		backup->m_keyName->SetLabel(wxGetApp().GetKey(index)->Name);
		if (backup->ShowModal() == wxID_OK) {
			wxGetApp().ExportKey(wxGetApp().GetKeyId(index),
					backup->m_fileName->GetValue(),
					backup->m_isArmor->IsChecked());
		}
		index = m_keyListCtrl->GetNextSelected(index);
	}
	backup->Destroy();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_RETRIEVE_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuRetrieveKeyClick(wxCommandEvent &event) {
	wxGnuPGShellImportKey *dlg = new wxGnuPGShellImportKey(this);

	if (dlg->ShowModal() == wxID_OK) {
		long index = dlg->m_resultKeyList->GetFirstSelected();
		unsigned int count = 0;
		wxString keyId;
		wxBusyInfo *info = new wxBusyInfo(_("Please wait, requesting key..."),
				this);

		while (index != wxNOT_FOUND) {
			keyId = dlg->m_resultKeyList->GetItemText(index);
			wxGetApp().RecvKeys(
					dlg->m_importServer->GetString(
							dlg->m_importServer->GetSelection()), keyId);
			index = dlg->m_resultKeyList->GetNextSelected(index);
			count++;
		}
		wxDELETE(info);

		if (count > 0) {
			RefreshKeyList();
		}
	}
	dlg->Destroy();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SEND_KEYS
 */

void wxGnuPGShellKeyringEditor::OnMenuSendKeysClick(wxCommandEvent &event) {
	wxString keys = wxT("");
	//wxString status;

	if (wxMessageBox(
			_("You really want to send your selected keys to default server?"),
			_("Send keys"), wxYES_NO) == wxYES) {
		long index = m_keyListCtrl->GetFirstSelected();
		while (index != wxNOT_FOUND) {
			keys.Append(wxGetApp().GetKeyId(index) + wxT(" "));
			index = m_keyListCtrl->GetNextSelected(index);
		}
		wxBusyInfo *info = new wxBusyInfo(_("Please wait, sending keys..."),
				this);
		bool res = wxGetApp().SendKeys(wxGetApp().m_defaultKeyServer, keys);
		wxDELETE(info);
		if (!res) {
			wxMessageBox(_("Error sending keys. See log for details"),
					_("Error sending keys"), wxOK);
		}
	}
}

/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_KE_KEYLIST
 */

void wxGnuPGShellKeyringEditor::OnKeKeylistSelected(wxListEvent &event) {
	UpdateProperties(event.GetIndex());
}

void wxGnuPGShellKeyringEditor::UpdateProperties(const int index) {
	wxGnuPGKey *key = wxGetApp().GetKey(index);
	if (key) {
		m_keyProperty->SetPropertyValue(wxT("UserName"), key->Name);
		m_keyProperty->SetPropertyValue(wxT("KeyID"), key->Id);
		m_keyProperty->SetPropertyValue(wxT("Fingerprint"), key->Fingerprint);
		m_keyProperty->SetPropertyValue(wxT("ExpiresAt"),
				key->GetExpireDateString());
		m_keyProperty->SetPropertyValue(wxT("CreatedAt"),
				key->GetCreationDateString());
		m_keyProperty->SetPropertyValue(wxT("OwnerTrust"),
				key->GetTrustString());
		m_keyProperty->SetPropertyValue(wxT("KeyType"), key->Algorithm);
		m_keyProperty->SetPropertyValue(wxT("KeyValidity"),
				key->GetValidityString());
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_KEY_PUB
 */

void wxGnuPGShellKeyringEditor::OnMenuKeyPubClick(wxCommandEvent &event) {
	m_isPublicKeyring = true;
	m_keyRing = _("Public");
	wxGetApp().ListPublicKeys();
	RefreshKeyList();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_KEY_SEC
 */

void wxGnuPGShellKeyringEditor::OnMenuKeySecClick(wxCommandEvent &event) {
	m_isPublicKeyring = false;
	m_keyRing = _("Secret");
	wxGetApp().ListSecretKeys();
	RefreshKeyList();
}

void wxGnuPGShellKeyringEditor::RefreshKeyList() {
	wxBusyInfo *info = new wxBusyInfo(_("Please wait, refreshing keyring..."),
			this);
	wxSleep(1);
	wxGetApp().UpdateTrustDB();

	wxGetApp().RefreshKeyList();
	m_keyListCtrl->DeleteAllItems();
	m_keyListCtrl->SetItemCount(
			static_cast<long>(wxGetApp().GetKeyList().GetCount()));
	m_keyListCtrl->RefreshItems(0, m_keyListCtrl->GetItemCount());

	wxString paneCaption = m_keyRing + _(" keyring");
	m_auiManager.GetPane(m_keyListCtrl).Caption(paneCaption);
	m_auiManager.Update();
	wxDELETE(info);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_SEND_KEYS
 */

void wxGnuPGShellKeyringEditor::OnMenuSendKeysUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetFirstSelected() > -1);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_SELECT_LANGUAGE
 */

void wxGnuPGShellKeyringEditor::OnSelectLanguageClick(wxCommandEvent &event) {
	wxUnusedVar(event);
	if (wxGetApp().SelectLanguage()) {
		wxGetApp().RecreateGUI();
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_DEL_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuDelKeyUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetFirstSelected() > -1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_SIGN_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuEditKeyUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetSelectedItemCount() == 1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_OWNER_TRUST
 */

void wxGnuPGShellKeyringEditor::OnMenuOwnerTrustUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetFirstSelected() > -1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_EXPORT_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuExportKeyUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetFirstSelected() > -1);
}

/*!
 * wxEVT_CLOSE_WINDOW event handler for ID_WXGNUPGSHELLKEYRINGEDITOR
 */

void wxGnuPGShellKeyringEditor::OnCloseWindow(wxCloseEvent &event) {
	// save positions
	SaveWindowsSettings();
	event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_UPDATE_TRUSTDB
 */

void wxGnuPGShellKeyringEditor::OnMenuUpdateTrustdbClick(
		wxCommandEvent &event) {
	wxUnusedVar(event);
	RefreshKeyList();
}

void wxGnuPGShellKeyringEditor::SaveWindowsSettings() {
	wxListItem item;
	wxConfig *config = new wxConfig(wxGetApp().GetAppName());

	// save columns widths
	for (wxByte it = 0; it < m_keyListCtrl->GetColumnCount(); it++) {
		item.m_col = it;
		item.m_mask = wxLIST_MASK_TEXT;
		if (m_keyListCtrl->GetColumn(it, item)) {
			config->Write(item.m_text, m_keyListCtrl->GetColumnWidth(it));
		}
	}

	wxSize size = this->GetSize();

	config->Write(wxT("Editor Left"), size.GetX());
	config->Write(wxT("Editor Top"), size.GetY());
	config->Write(wxT("Editor width"), size.GetWidth());
	config->Write(wxT("Editor height"), size.GetHeight());

	wxDELETE(config);
}

void wxGnuPGShellKeyringEditor::LoadWindowsSettings() {
	wxListItem item;
	wxConfig *config = new wxConfig(wxGetApp().GetAppName());
	long width = 100;

	// save columns widths
	for (wxByte it = 0; it < m_keyListCtrl->GetColumnCount(); it++) {
		item.m_col = it;
		item.m_mask = wxLIST_MASK_TEXT;
		if (m_keyListCtrl->GetColumn(it, item)) {
			if (config->Read(item.GetText(), &width)) {
				m_keyListCtrl->SetColumnWidth(it, width);
			}
		}
	}

	wxRect rect;

	if (config->Read(wxT("Editor Left"), &rect.x)) { // if there one item
		config->Read(wxT("Editor Top"), &rect.y);
		config->Read(wxT("Editor width"), &rect.width);
		config->Read(wxT("Editor height"), &rect.height);
		SetSize(rect, wxSIZE_AUTO);
	}

	wxDELETE(config);
}

/*!
 * wxEVT_DESTROY event handler for ID_WXGNUPGSHELLKEYRINGEDITOR
 */

void wxGnuPGShellKeyringEditor::OnDestroy(wxWindowDestroyEvent &event) {
	event.Skip();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_TOOL_EXPORT
 */

void wxGnuPGShellKeyringEditor::OnKeToolExportUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetFirstSelected() > -1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_TOOL_DELETE
 */

void wxGnuPGShellKeyringEditor::OnKeToolDeleteUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetFirstSelected() > -1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_TOOL_EDIT
 */

void wxGnuPGShellKeyringEditor::OnKeToolEditUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			wxGetApp().IsReady() && m_keyListCtrl->GetSelectedItemCount() == 1);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_CLEAR_LOG
 */

void wxGnuPGShellKeyringEditor::OnMenuClearLogClick(wxCommandEvent &event) {
	m_logText->Clear();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_REFRESH
 */

void wxGnuPGShellKeyringEditor::OnMenuRefreshUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_UPDATE_TRUSTDB
 */

void wxGnuPGShellKeyringEditor::OnMenuUpdateTrustdbUpdate(
		wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_KEY_PUB
 */

void wxGnuPGShellKeyringEditor::OnMenuKeyPubUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_KEY_SEC
 */

void wxGnuPGShellKeyringEditor::OnMenuKeySecUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_SELECT_ALL
 */

void wxGnuPGShellKeyringEditor::OnMenuSelectAllUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_NEW_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuNewKeyUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_IMPORT_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuImportKeyUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_RETRIEVE_KEY
 */

void wxGnuPGShellKeyringEditor::OnMenuRetrieveKeyUpdate(
		wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_FILEMANAGER
 */

void wxGnuPGShellKeyringEditor::OnMenuFilemanagerUpdate(
		wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_TOOL_IMPORT
 */

void wxGnuPGShellKeyringEditor::OnKeToolImportUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_TOOL_REFRESH
 */

void wxGnuPGShellKeyringEditor::OnKeToolRefreshUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_TOOL_FILES
 */

void wxGnuPGShellKeyringEditor::OnKeToolFilesUpdate(wxUpdateUIEvent &event) {
	event.Enable(wxGetApp().IsReady());
}

/*!
 * wxEVT_CONTEXT_MENU event handler for ID_KE_KEYLIST
 */

void wxGnuPGShellKeyringEditor::OnContextMenu(wxContextMenuEvent &event) {
	if (!m_popupMenu) {
		m_popupMenu = AppResources::CreateMenuMenu();
	}
	int flags;
	if (m_keyListCtrl->HitTest(
			m_keyListCtrl->ScreenToClient(event.GetPosition()), flags,
			NULL) != wxNOT_FOUND) {
		PopupMenu(m_popupMenu);
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_KE_STAT_BAR
 */

void wxGnuPGShellKeyringEditor::OnKESTATBARUpdate(wxUpdateUIEvent &event) {
	if (wxGetApp().IsReady()) {
		try {
			m_statusBar->SetStatusText(
					wxString::Format(_("Total keys: %d"),
							m_keyListCtrl->GetItemCount()), 0);
			m_statusBar->SetStatusText(
					wxString::Format(_("Selected keys: %d"),
							m_keyListCtrl->GetSelectedItemCount()), 1);
			return;
			m_statusBar->SetStatusText(
					wxString::Format(_("Default key: %s"),
							wxGetApp().m_defKey.GetData()), 2);
			m_statusBar->SetStatusText(
					wxString::Format(_("Status: %s"),
							wxGetApp().IsReady() ? _("Ready") : _("Failed")),
					3);
		} catch (...) {
		}
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REVOKE_KEY
 */

void wxGnuPGShellKeyringEditor::OnMENUREVOKEKEYClick(wxCommandEvent &event) {
	wxGnuPGShellRevokeKey *dlg = new wxGnuPGShellRevokeKey(this);
	long index = m_keyListCtrl->GetFirstSelected();
	wxUint16 successCount = 0;

	while (index != wxNOT_FOUND) {
		wxString keyId = wxGetApp().GetKeyId(index);

		dlg->m_ids->SetValue(keyId);
		dlg->m_names->SetValue(m_keyListCtrl->GetItemText(index));

		if (dlg->ShowModal() == wxID_OK) {
			if (wxGetApp().GenRevoke(keyId, dlg->m_outputFile->GetValue(),
					wxString::Format(wxT("%d"),
							dlg->m_reasonRadio->GetSelection()),
					dlg->m_ownReason->GetValue(),
					dlg->m_passphrase->GetValue())) {
				successCount++;
			}

		}
		index = m_keyListCtrl->GetNextSelected(index);
	}
	if (successCount > 0) {
		wxMessageBox(
				wxString::Format(
						_(
								"Revocation certificates successfully generated for %d keys."),
						successCount), _("Finish"));
	} else {
		wxMessageBox(_("No revocation certificates has been generated."),
				_("Finish"));
	}

	dlg->Destroy();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_REVOKE_KEY
 */

void wxGnuPGShellKeyringEditor::OnMENUREVOKEKEYUpdate(wxUpdateUIEvent &event) {
	event.Enable(
			m_keyListCtrl->GetSelectedItemCount() > 0 && !m_isPublicKeyring);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_CLEAR_PASS_CACHE
 */

void wxGnuPGShellKeyringEditor::OnMENUCLEARPASSCACHEClick(
		wxCommandEvent &event) {
	wxGetApp().ClearPassCache();
}

void wxGnuPGShellKeyringEditor::OnKeyListRightDown(wxMouseEvent &event) {
	if (!m_popupMenu) {
		m_popupMenu = AppResources::CreateMenuMenu();
	}
	int flags;
	if (m_keyListCtrl->HitTest(event.GetPosition(), flags, NULL) != wxNOT_FOUND) {
		PopupMenu(m_popupMenu);
	}
}
