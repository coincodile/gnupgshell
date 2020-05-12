/////////////////////////////////////////////////////////////////////////////
// Name:        wxgnupgshellfilemanager.cpp
// Purpose:
// Author:      cod
// Modified by:
// Created:     03/08/2007 17:31:25
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxgnupgshellfilemanager.h"
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

#include <wx/dnd.h>
#include "wxgnupgshellfilemanager.h"
#include "wxgnupgshellapp.h"
#include "wxGnuPGShellSelectRecipient.h"
#include "app_resources.h"
#include <wx/busyinfo.h>

////@begin XPM images
#include "wxwin32x32.xpm"
#include "new.xpm"
#include "delete.xpm"
#include "redo.xpm"
#include "exit-16x16x32b.xpm"
#include "sign-16x16x32b.xpm"
#include "secret-16x16x32b.xpm"
#include "public-16x16x32b.xpm"
#include "htmbook.xpm"
#include "verify.xpm"
////@end XPM images

/*!
 * wxGnuPGShellFileManager type definition
 */

IMPLEMENT_CLASS(wxGnuPGShellFileManager, wxFrame)

/*!
 * wxGnuPGShellFileManager event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellFileManager, wxFrame )

////@begin wxGnuPGShellFileManager event table entries
EVT_MENU( ID_MENU_ADD, wxGnuPGShellFileManager::OnMenuAddClick )

EVT_MENU( ID_MENU_REMOVE, wxGnuPGShellFileManager::OnMenuRemoveClick )
EVT_UPDATE_UI( ID_MENU_REMOVE, wxGnuPGShellFileManager::OnMenuRemoveUpdate )

EVT_MENU( ID_MENU_REMOVE_ALL, wxGnuPGShellFileManager::OnMenuRemoveAllClick )
EVT_UPDATE_UI( ID_MENU_REMOVE_ALL, wxGnuPGShellFileManager::OnMenuRemoveAllUpdate )

EVT_MENU( wxID_EXIT, wxGnuPGShellFileManager::OnExitClick )

EVT_MENU( ID_MENU_SIGN_FILE, wxGnuPGShellFileManager::OnMenuSignFileClick )
EVT_UPDATE_UI( ID_MENU_SIGN_FILE, wxGnuPGShellFileManager::OnMenuSignFileUpdate )
EVT_MENU( ID_MENU_VERIFY_FILE, wxGnuPGShellFileManager::OnMenuVerifyFileClick )
EVT_UPDATE_UI( ID_MENU_VERIFY_FILE, wxGnuPGShellFileManager::OnMenuVerifyFileUpdate )

EVT_MENU( ID_MENU_ENCRYPT_FILE, wxGnuPGShellFileManager::OnMenuEncryptFileClick )
EVT_UPDATE_UI( ID_MENU_ENCRYPT_FILE, wxGnuPGShellFileManager::OnMenuEncryptFileUpdate )

EVT_MENU( ID_MENU_DECRYPT_FILE, wxGnuPGShellFileManager::OnMenuDecryptFileClick )
EVT_UPDATE_UI( ID_MENU_DECRYPT_FILE, wxGnuPGShellFileManager::OnMenuDecryptFileUpdate )

EVT_MENU( ID_TOOL_OPEN, wxGnuPGShellFileManager::OnToolOpenClick )

EVT_MENU( ID_TOOL_CLEAR, wxGnuPGShellFileManager::OnToolClearClick )
EVT_UPDATE_UI( ID_TOOL_CLEAR, wxGnuPGShellFileManager::OnToolClearUpdate )

EVT_MENU( ID_TOOL_SIGN, wxGnuPGShellFileManager::OnMenuSignFileClick )
EVT_UPDATE_UI( ID_TOOL_SIGN, wxGnuPGShellFileManager::OnToolSignUpdate )
EVT_MENU( ID_TOOL_VERIFY, wxGnuPGShellFileManager::OnMenuVerifyFileClick )
EVT_UPDATE_UI( ID_TOOL_VERIFY, wxGnuPGShellFileManager::OnToolVerifyUpdate )

EVT_MENU( ID_TOOL_ENCRYPT, wxGnuPGShellFileManager::OnMenuEncryptFileClick )
EVT_UPDATE_UI( ID_TOOL_ENCRYPT, wxGnuPGShellFileManager::OnToolEncryptUpdate )

EVT_MENU( ID_TOOL_DECRYPT, wxGnuPGShellFileManager::OnMenuDecryptFileClick )
EVT_UPDATE_UI( ID_TOOL_DECRYPT, wxGnuPGShellFileManager::OnToolDecryptUpdate )

EVT_UPDATE_UI( ID_FILE_STATUSBAR, wxGnuPGShellFileManager::OnFILESTATUSBARUpdate )

////@end wxGnuPGShellFileManager event table entries
EVT_MENU( ID_FILEMANAGER_DECRYPT, wxGnuPGShellFileManager::OnMenuDecryptFileClick )
EVT_MENU( ID_FILEMANAGER_ENCRYPT, wxGnuPGShellFileManager::OnMenuEncryptFileClick )
EVT_MENU( ID_FILEMANAGER_SIGN, wxGnuPGShellFileManager::OnMenuSignFileClick )
EVT_MENU( ID_FILEMANAGER_VERIFY, wxGnuPGShellFileManager::OnMenuVerifyFileClick )

END_EVENT_TABLE()

// USE DRAG N DROP

class DnDFile: public wxFileDropTarget {
public:
	DnDFile(wxListView *pOwner) {
		m_pOwner = pOwner;
	}

	virtual bool OnDropFiles(wxCoord x, wxCoord y,
			const wxArrayString &fileNames);

private:
	wxListView *m_pOwner;
};

/*!
 * wxGnuPGShellFileManager constructors
 */

wxGnuPGShellFileManager::wxGnuPGShellFileManager() {
	Init();
}

wxGnuPGShellFileManager::wxGnuPGShellFileManager(wxWindow *parent,
		wxWindowID id, const wxString &caption, const wxPoint &pos,
		const wxSize &size, long style) {
	Init();
	Create(parent, id, caption, pos, size, style);
}

/*!
 * wxGnuPGShellFileManager creator
 */

bool wxGnuPGShellFileManager::Create(wxWindow *parent, wxWindowID id,
		const wxString &caption, const wxPoint &pos, const wxSize &size,
		long style) {
////@begin wxGnuPGShellFileManager creation
	wxFrame::Create(parent, id, caption, pos, size, style);

	CreateControls();
	SetIcon(GetIconResource(wxT("wxwin32x32.xpm")));
	Centre();
////@end wxGnuPGShellFileManager creation
	return true;
}

/*!
 * wxGnuPGShellFileManager destructor
 */

wxGnuPGShellFileManager::~wxGnuPGShellFileManager() {
	wxDELETE(m_popupMenu);
////@begin wxGnuPGShellFileManager destruction
	GetAuiManager().UnInit();
////@end wxGnuPGShellFileManager destruction
}

/*!
 * Member initialisation
 */

void wxGnuPGShellFileManager::Init() {
////@begin wxGnuPGShellFileManager member initialisation
	m_statusBar = NULL;
	m_fileList = NULL;
////@end wxGnuPGShellFileManager member initialisation
}

/*!
 * Control creation for wxGnuPGShellFileManager
 */

void wxGnuPGShellFileManager::CreateControls() {
////@begin wxGnuPGShellFileManager content construction
	wxGnuPGShellFileManager *itemFrame1 = this;

	GetAuiManager().SetManagedWindow(this);

	wxMenuBar *menuBar = new wxMenuBar;
	wxMenu *itemMenu3 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu3, ID_MENU_ADD,
				_("&Add..."), _("Add files to list"), wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("new.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu3->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu3, ID_MENU_REMOVE,
				_("&Delete From List\tDel"),
				_("Delete selected files from list"), wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("delete.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu3->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu3, ID_MENU_REMOVE_ALL,
				_("D&elete All From List"), _("Clear list"), wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("redo.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu3->Append(menuItem);
	}
	itemMenu3->AppendSeparator();
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu3, wxID_EXIT,
				_("E&xit\tAlt+F4"), _T(""), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("exit-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu3->Append(menuItem);
	}
	menuBar->Append(itemMenu3, _("&File"));
	wxMenu *itemMenu9 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu9, ID_MENU_SIGN_FILE,
				_("&Sign File"), _("Sign selected files"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("sign-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu9->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu9, ID_MENU_VERIFY_FILE,
				_("&Verify Signed File"), _("Verify the Sign Files"), wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("verify.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu9->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu9, ID_MENU_ENCRYPT_FILE,
				_("&Encrypt File"), _("Encrypt selected files"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("secret-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu9->Append(menuItem);
	}
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu9, ID_MENU_DECRYPT_FILE,
				_("&Decrypt"), _("Decrypt selected files"), wxITEM_NORMAL);
		wxBitmap bitmap(
				itemFrame1->GetBitmapResource(wxT("public-16x16x32b.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu9->Append(menuItem);
	}
	menuBar->Append(itemMenu9, _("&Edit"));
	wxMenu *itemMenu13 = new wxMenu;
	{
		wxMenuItem *menuItem = new wxMenuItem(itemMenu13, wxID_ABOUT,
				_("&About..."), _T(""), wxITEM_NORMAL);
		wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("htmbook.xpm")));
		menuItem->SetBitmap(bitmap);
		itemMenu13->Append(menuItem);
	}
	menuBar->Append(itemMenu13, _("&Help"));
	itemFrame1->SetMenuBar(menuBar);

	wxToolBar *itemToolBar15 = new wxToolBar(itemFrame1, ID_FILE_TOOLBAR,
			wxDefaultPosition, wxDefaultSize,
			wxTB_FLAT | wxTB_HORIZONTAL | wxTB_NODIVIDER);
	itemToolBar15->SetToolBitmapSize(wxSize(32, 32));
	wxBitmap itemtool16Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/add.ico")));
	wxBitmap itemtool16BitmapDisabled;
	itemToolBar15->AddTool(ID_TOOL_OPEN, _("Add"), itemtool16Bitmap,
			itemtool16BitmapDisabled, wxITEM_NORMAL, _("Add file"),
			_("Add existing file to list"));
	wxBitmap itemtool17Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/refresh.ico")));
	wxBitmap itemtool17BitmapDisabled;
	itemToolBar15->AddTool(ID_TOOL_CLEAR, _("Clear"), itemtool17Bitmap,
			itemtool17BitmapDisabled, wxITEM_NORMAL, _("Clear list"),
			_("Remove all files from list (no from disk!)"));
	itemToolBar15->AddSeparator();

	wxBitmap itemtool19Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/sign.ico")));
	wxBitmap itemtool19BitmapDisabled;
	itemToolBar15->AddTool(ID_TOOL_SIGN, _T(""), itemtool19Bitmap,
			itemtool19BitmapDisabled, wxITEM_NORMAL, _("Sign files"),
			wxEmptyString);


	wxBitmap itemtool190Bitmap(
				itemFrame1->GetBitmapResource(wxT("art/verify.ico")));
	wxBitmap itemtool190BitmapDisabled;
	itemToolBar15->AddTool(ID_TOOL_VERIFY, _T(""), itemtool190Bitmap,
			itemtool190BitmapDisabled, wxITEM_NORMAL, _("Verify files"),
			wxEmptyString);


	wxBitmap itemtool20Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/secret.ico")));
	wxBitmap itemtool20BitmapDisabled;
	itemToolBar15->AddTool(ID_TOOL_ENCRYPT, _T(""), itemtool20Bitmap,
			itemtool20BitmapDisabled, wxITEM_NORMAL, _("Encrypt files"),
			wxEmptyString);
	wxBitmap itemtool21Bitmap(
			itemFrame1->GetBitmapResource(wxT("art/public.ico")));
	wxBitmap itemtool21BitmapDisabled;
	itemToolBar15->AddTool(ID_TOOL_DECRYPT, _T(""), itemtool21Bitmap,
			itemtool21BitmapDisabled, wxITEM_NORMAL, _("Decrypt files"),
			wxEmptyString);
	itemToolBar15->Realize();
	itemFrame1->GetAuiManager().AddPane(itemToolBar15,
			wxAuiPaneInfo().ToolbarPane().Name(_T("ToolBar")).Top().Layer(10).LeftDockable(
					false).RightDockable(false).CaptionVisible(false).CloseButton(
					false).DestroyOnClose(false).Resizable(false).Floatable(
					false).Gripper(true));

	m_statusBar = new wxStatusBar(itemFrame1, ID_FILE_STATUSBAR,
			wxST_SIZEGRIP | wxNO_BORDER);
	m_statusBar->SetFieldsCount(2);
	itemFrame1->SetStatusBar(m_statusBar);

	m_fileList = new wxListView(itemFrame1, ID_GNUPGKEYLIST_CTRL,
			wxDefaultPosition, wxSize(500, 100), wxLC_REPORT | wxNO_BORDER);
	itemFrame1->GetAuiManager().AddPane(m_fileList,
			wxAuiPaneInfo().Name(_T("Pane2")).Caption(_T("File List")).Centre().MinSize(
					wxSize(-1, 200)).CloseButton(false).DestroyOnClose(false).Resizable(
					true).Floatable(false).PaneBorder(false));

	GetAuiManager().Update();

	// Connect events and objects
	m_fileList->Connect(ID_GNUPGKEYLIST_CTRL, wxEVT_CONTEXT_MENU,
			wxContextMenuEventHandler(wxGnuPGShellFileManager::OnContextMenu),
			NULL, this);
////@end wxGnuPGShellFileManager content construction

	m_fileList->SetDropTarget(new DnDFile(m_fileList));

	m_fileList->InsertColumn(0, _("File name"), wxLIST_FORMAT_LEFT, 300);
	m_fileList->InsertColumn(1, _("Encrypted"));
	m_popupMenu = AppResources::CreateFileManagerMenu();
}

// handles drop files
bool DnDFile::OnDropFiles(wxCoord, wxCoord, const wxArrayString &fileNames) {
	int filesCount = static_cast<int>(fileNames.GetCount());
	int baseIndex = m_pOwner->GetItemCount();

	for (int it = baseIndex, fit = 0; it < filesCount + baseIndex;
			it++, fit++) {
		wxDynamicCast(m_pOwner->GetParent(), wxGnuPGShellFileManager)->AddFileToList(
				it, fileNames[fit]);
		wxDynamicCast(m_pOwner->GetParent(), wxGnuPGShellFileManager)->m_fileList->Select(
				it);
	}

	return true;
}

/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellFileManager::ShowToolTips() {
	return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellFileManager::GetBitmapResource(const wxString &name) {
	// Bitmap retrieval
////@begin wxGnuPGShellFileManager bitmap retrieval
	wxUnusedVar(name);
	if (name == _T("new.xpm")) {
		wxBitmap bitmap(new_xpm);
		return bitmap;
	} else if (name == _T("delete.xpm")) {
		wxBitmap bitmap(delete_xpm);
		return bitmap;
	} else if (name == _T("redo.xpm")) {
		wxBitmap bitmap(redo_xpm);
		return bitmap;
	} else if (name == _T("exit-16x16x32b.xpm")) {
		wxBitmap bitmap(exit_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("sign-16x16x32b.xpm")) {
		wxBitmap bitmap(sign_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("verify.xpm")) {
		wxBitmap bitmap(_16f911b1da2455ebda304fb9ac651e852Tf24zZOpiJpypd);
		return bitmap;
	} else if (name == _T("secret-16x16x32b.xpm")) {
		wxBitmap bitmap(secret_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("public-16x16x32b.xpm")) {
		wxBitmap bitmap(public_16x16x32b_xpm);
		return bitmap;
	} else if (name == _T("htmbook.xpm")) {
		wxBitmap bitmap(htmbook_xpm);
		return bitmap;
	} else if (name == _T("art/add.ico")) {
		wxIcon icon(_T("art/add.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/refresh.ico")) {
		wxIcon icon(_T("art/refresh.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/sign.ico")) {
		wxIcon icon(_T("art/sign.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/verify.ico")) {
		wxIcon icon(_T("art/verify.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/secret.ico")) {
		wxIcon icon(_T("art/secret.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	} else if (name == _T("art/public.ico")) {
		wxIcon icon(_T("art/public.ico"), wxBITMAP_TYPE_ICO);
		wxBitmap bitmap;
		bitmap.CopyFromIcon(icon);
		return bitmap;
	}
	return wxNullBitmap;
////@end wxGnuPGShellFileManager bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellFileManager::GetIconResource(const wxString &name) {
	// Icon retrieval
////@begin wxGnuPGShellFileManager icon retrieval
	wxUnusedVar(name);
	if (name == _T("wxwin32x32.xpm")) {
		wxIcon icon(wxwin32x32_xpm);
		return icon;
	}
	return wxNullIcon;
////@end wxGnuPGShellFileManager icon retrieval
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
 */

void wxGnuPGShellFileManager::OnExitClick(wxCommandEvent &event) {
	Destroy();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_REMOVE
 */

void wxGnuPGShellFileManager::OnMenuRemoveUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetFirstSelected() > -1);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_ADD
 */

void wxGnuPGShellFileManager::OnMenuAddClick(wxCommandEvent &event) {
	AddFileToList();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REMOVE
 */

void wxGnuPGShellFileManager::OnMenuRemoveClick(wxCommandEvent &event) {
	long index;
	index = m_fileList->GetFirstSelected();
	while (index != -1) {
		m_fileList->DeleteItem(index);
		index = m_fileList->GetNextSelected(index);
	}
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_REMOVE_ALL
 */

void wxGnuPGShellFileManager::OnMenuRemoveAllClick(wxCommandEvent &event) {
	m_fileList->DeleteAllItems();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_REMOVE_ALL
 */

void wxGnuPGShellFileManager::OnMenuRemoveAllUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetItemCount() > 0);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_SIGN_FILE
 */

void wxGnuPGShellFileManager::OnMenuSignFileClick(wxCommandEvent &event) {
	wxString fName;
	wxString newName;

	wxString pass = wxGetApp().GetPasswordForKey(wxGetApp().m_defKey);
	if (pass == wxEmptyString) {
		return;
	}
	long index = m_fileList->GetFirstSelected();

	while (index > wxNOT_FOUND) {
		fName = m_fileList->GetItemText(index);
		newName = fName + wxT(".asc");
		if (wxFileExists(newName)) { // exists
			if (wxMessageBox(
					_("File ") + newName + _(" already exists. Overwrite?"),
					_("Overwrite confirmation"), wxYES_NO) == wxNO) {
				newName = wxFileSelector(_("Choose another file name"));
				if (newName == wxEmptyString) {
					break;
				}
			}
		}
		wxBusyInfo *info = new wxBusyInfo(
				_("Please wait, operation in progress..."), this);
		if (wxGetApp().SignDocument(fName, newName, pass, true)
				|| wxFileExists(newName)) {
			wxMessageBox(_("File ") + fName + _(" signed successfully."));
		} else {
			wxMessageBox(
					_(
							"Signing of file ") + fName + _(" failure due to errors."));
			wxGetApp().ClearPassCache();
		}

		wxDELETE(info);
		index = m_fileList->GetNextSelected(index);
	}
}



void wxGnuPGShellFileManager::OnMenuVerifyFileClick(wxCommandEvent &event) {
	wxString fName;
	wxString newName;

//	wxString pass = wxGetApp().GetPasswordForKey(wxGetApp().m_defKey);
//	if (pass == wxEmptyString) {
//		return;
//	}
	long index = m_fileList->GetFirstSelected();

	while (index > wxNOT_FOUND) {
		fName = m_fileList->GetItemText(index);
		newName = fName + wxT(".asc");
		if (!wxFileExists(newName)) { // exists
			wxMessageBox(
					_("File ") + newName + _(" not exists. There is no sign file?"),
					_("No sign file"), wxOK);
			return;
		}
		wxBusyInfo *info = new wxBusyInfo(
				_("Please wait, operation in progress..."), this);
		if (wxGetApp().VerifyDocument(fName, newName, true)
				|| wxFileExists(newName)) {
			wxMessageBox(_("File ") + fName + _(" verified successfully."));
		} else {
			wxMessageBox(
					_(
							"Verification of file ") + fName + _(" failure due to errors."));
			wxGetApp().ClearPassCache();
		}

		wxDELETE(info);
		index = m_fileList->GetNextSelected(index);
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_SIGN_FILE
 */

void wxGnuPGShellFileManager::OnMenuSignFileUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetSelectedItemCount() > 0);
}

void wxGnuPGShellFileManager::OnMenuVerifyFileUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetSelectedItemCount() > 0);
}

//bool wxGnuPGShellFileManager::EncryptUseKey(const wxString newName, const wxString keyId, bool armored)
//{
//}
//
//bool wxGnuPGShellFileManager::EncryptUsePass(const wxString newName, const wxString pass, bool armored)
//{
//}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_ENCRYPT_FILE
 */

wxString wxGnuPGShellFileManager::GetNewFileName(const wxString fileName,
		const wxString extension) {
	wxString newName = fileName + extension;
	if (wxFileExists(newName)) {
		if (wxMessageBox(
				_("File ") + newName + _(" already exists. Overwrite?"),
				_("Overwrite confirmation"), wxYES_NO) == wxNO) {
			// enter new name, if exists
			newName = wxFileSelector(_("Choose another file name"));
		}
	}
	return newName;
}

void wxGnuPGShellFileManager::OnMenuEncryptFileClick(wxCommandEvent &event) {
	wxGnuPGShellSelectRecipient *rec = new wxGnuPGShellSelectRecipient(this);
	if (rec->ShowModal() == wxID_OK) {
		wxString fName;
		wxListItem item;
		wxString newName;

		long index = m_fileList->GetFirstSelected();

		while (index != wxNOT_FOUND) {
			fName = m_fileList->GetItemText(index);

			newName = GetNewFileName(fName, wxT(".gpg"));
			if (newName == wxEmptyString) {
				index = m_fileList->GetNextSelected(index);
				continue;
			}

			item.m_itemId = index;
			item.m_mask = wxLIST_MASK_TEXT;

			wxBusyInfo *info = new wxBusyInfo(
					_("Please wait, operation in progress..."), this);

			bool result = false;
			if (rec->m_useKey->GetValue()) {
				// use key
				long recIndex = rec->m_recKeyList->GetFirstSelected();
				result = wxGetApp().EncryptDocument(fName, newName,
						wxGetApp().GetKeyId(static_cast<wxUint32>(recIndex)),
						rec->m_needArmor->GetValue(), true)
						|| wxFileExists(newName);
			} else {
				// use pass
				result = wxGetApp().EncryptSymmetric(fName, newName,
						rec->m_pass->GetValue(), rec->m_needArmor->GetValue())
						|| wxFileExists(newName);
			}
			wxDELETE(info);

			if (result) {
				// mark es Encrypted
				item.m_text = newName;
				item.m_col = 0;
				m_fileList->SetItem(item);
				item.m_text = _("Yes");
				wxMessageBox(
						_("File ") + fName + _(" encrypted successfully."));
			} else {
				item.m_text = _("No");
				wxMessageBox(
						_(
								"Encryption of file ") + fName + _(" failure due to errors."));
			}
			item.m_col = 1;
			m_fileList->SetItem(item);
			index = m_fileList->GetNextSelected(index);
		} // END while (index != wxNOT_FOUND)
	}
	rec->Destroy();
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_ENCRYPT_FILE
 */

void wxGnuPGShellFileManager::OnMenuEncryptFileUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetSelectedItemCount() > 0);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENU_DECRYPT_FILE
 */

void wxGnuPGShellFileManager::OnMenuDecryptFileClick(wxCommandEvent &event) {
	wxString fName;
	wxString newName;

	long index = m_fileList->GetFirstSelected();
	while (index > -1) {
		fName = m_fileList->GetItemText(index);
		if (fName.Right(4) == wxT(".pgp") || fName.Right(4) == wxT(".asc")
				|| fName.Right(4) == wxT(".gpg")) {
			newName = fName.Left(fName.length() - 4);

			if (wxFileExists(newName)) { // exists
				if (wxMessageBox(
						_("File ") + newName + _(" already exists. Overwrite?"),
						_("Overwrite confirmation"), wxYES_NO) == wxNO) {
					// enter new name, if exists
					newName = wxFileSelector(_("Choose another file name"));
					if (newName == wxEmptyString) {
						continue;
					}
				}
			}

			wxString pass = wxGetPasswordFromUser(
					_("Enter a passphrase to decrypt ") + fName,
					_("Passphrase needed"));
			if (pass == wxEmptyString) {
				index = m_fileList->GetNextSelected(index);
				continue;
			}

			wxBusyInfo *info = new wxBusyInfo(
					_("Please wait, operation in progress..."), this);
			if (wxGetApp().DecryptDocument(fName, newName, pass, true)) {
				wxMessageBox(
						_("File ") + fName + _(" decrypted successfully."));
			} else {
				wxMessageBox(
						_(
								"Decryption of file ") + fName + _(" failure due to errors."));
			}
			wxDELETE(info);
		}
		index = m_fileList->GetNextSelected(index);
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_MENU_DECRYPT_FILE
 */

void wxGnuPGShellFileManager::OnMenuDecryptFileUpdate(wxUpdateUIEvent &event) {
	bool encrypted = false;
	long index = m_fileList->GetFirstSelected();
	wxListItem item;
	while (index > -1) {
		item.m_itemId = index;
		item.m_mask = wxLIST_MASK_TEXT;
		item.m_col = 1;
		m_fileList->GetItem(item);
		if (item.m_text == _("Yes")) {
			encrypted = true;
			break;
		}
		index = m_fileList->GetNextSelected(index);
	}
	event.Enable(encrypted);
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_OPEN
 */

void wxGnuPGShellFileManager::OnToolOpenClick(wxCommandEvent &event) {
	AddFileToList();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CLEAR
 */

void wxGnuPGShellFileManager::OnToolClearClick(wxCommandEvent &event) {
	m_fileList->DeleteAllItems();
}

void wxGnuPGShellFileManager::AddFileToList(const int pos,
		const wxString fileName) {
	wxListItem item;
	m_fileList->InsertItem(pos, fileName);

	if (fileName.Right(4) == wxT(".gpg") || fileName.Right(4) == wxT(".pgp")
			|| fileName.Right(4) == wxT(".asc")) {
		item.m_itemId = pos;
		item.m_col = 1;
		item.m_mask = wxLIST_MASK_TEXT;
		item.SetText(_("Yes"));
		m_fileList->SetItem(item);
	}
}

// Browse for files and add them to list
bool wxGnuPGShellFileManager::AddFileToList() {
	wxFileDialog *fd = new wxFileDialog(this, _("Select file"), wxEmptyString,
			wxEmptyString, _("All files (*.*)|*.*"), wxFD_OPEN | wxFD_MULTIPLE);

	if (fd->ShowModal() == wxID_OK) {
		wxArrayString paths;
		fd->GetPaths(paths);

		for (wxUint16 it = 0; it < paths.GetCount(); it++) {
			AddFileToList(it, paths[it]);
		}
	}
	wxDELETE(fd);
	return true;
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_TOOL_CLEAR
 */

void wxGnuPGShellFileManager::OnToolClearUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetItemCount() > 0);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_TOOL_SIGN
 */

void wxGnuPGShellFileManager::OnToolSignUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetFirstSelected() > -1);
}

void wxGnuPGShellFileManager::OnToolVerifyUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetFirstSelected() > -1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_TOOL_ENCRYPT
 */

void wxGnuPGShellFileManager::OnToolEncryptUpdate(wxUpdateUIEvent &event) {
	event.Enable(m_fileList->GetFirstSelected() > -1);
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_TOOL_DECRYPT
 */

void wxGnuPGShellFileManager::OnToolDecryptUpdate(wxUpdateUIEvent &event) {
	OnMenuDecryptFileUpdate(event);
}

/*!
 * wxEVT_CONTEXT_MENU event handler for ID_GNUPGKEYLIST_CTRL
 */

void wxGnuPGShellFileManager::OnContextMenu(wxContextMenuEvent &event) {
	int flag;
	if (m_fileList->HitTest(m_fileList->ScreenToClient(event.GetPosition()),
			flag, NULL) != wxNOT_FOUND) {
		PopupMenu(m_popupMenu);
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_FILE_STATUSBAR
 */

void wxGnuPGShellFileManager::OnFILESTATUSBARUpdate(wxUpdateUIEvent &event) {
	m_statusBar->SetStatusText(
			wxString::Format(_("Total files: %d"), m_fileList->GetItemCount()),
			0);
	m_statusBar->SetStatusText(
			wxString::Format(_("Total Public keys: %d"),
					wxGetApp().GetKeyList().GetCount()), 1);

	event.Skip();
}

