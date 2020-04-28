/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellImportKey.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     12/09/2007 10:34:47
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxGnuPGShellImportKey.h"
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

#include "wxGnuPGShellImportKey.h"
#include "wxGnuPGWrapper.h"
#include "wxgnupgshellapp.h"
#include <wx/busyinfo.h>

////@begin XPM images
////@end XPM images


/*!
 * wxGnuPGShellImportKey type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellImportKey, wxDialog )


/*!
 * wxGnuPGShellImportKey event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellImportKey, wxDialog )

////@begin wxGnuPGShellImportKey event table entries
    EVT_TEXT( ID_IMPORTKEY_KEY_ID, wxGnuPGShellImportKey::OnIMPORTKEYKEYIDUpdated )

    EVT_TEXT( ID_IMPORTKEY_KEY_NAME, wxGnuPGShellImportKey::OnIMPORTKEYKEYNAMEUpdated )

    EVT_BUTTON( ID_IMPORTKEY_FIND, wxGnuPGShellImportKey::OnIMPORTKEYFINDClick )
    EVT_UPDATE_UI( ID_IMPORTKEY_FIND, wxGnuPGShellImportKey::OnIMPORTKEYFINDUpdate )

    EVT_BUTTON( ID_IMPORTKEY_CLEAR, wxGnuPGShellImportKey::OnIMPORTKEYCLEARClick )

    EVT_UPDATE_UI( wxID_OK, wxGnuPGShellImportKey::OnOKUpdate )

////@end wxGnuPGShellImportKey event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellImportKey constructors
 */

wxGnuPGShellImportKey::wxGnuPGShellImportKey()
{
    Init();
}

wxGnuPGShellImportKey::wxGnuPGShellImportKey( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellImportKey creator
 */

bool wxGnuPGShellImportKey::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellImportKey creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellImportKey creation
    return true;
}


/*!
 * wxGnuPGShellImportKey destructor
 */

wxGnuPGShellImportKey::~wxGnuPGShellImportKey()
{
////@begin wxGnuPGShellImportKey destruction
////@end wxGnuPGShellImportKey destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellImportKey::Init()
{
////@begin wxGnuPGShellImportKey member initialisation
    m_importServer = NULL;
    m_keyIdText = NULL;
    m_keyNameText = NULL;
    m_resultKeyList = NULL;
////@end wxGnuPGShellImportKey member initialisation
}


/*!
 * Control creation for wxGnuPGShellImportKey
 */

void wxGnuPGShellImportKey::CreateControls()
{    
////@begin wxGnuPGShellImportKey content construction
    wxGnuPGShellImportKey* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("Choose server:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString m_importServerStrings;
    m_importServer = new wxChoice( itemDialog1, ID_IMPORTKEY_SERVER, wxDefaultPosition, wxSize(300, -1), m_importServerStrings, 0 );
    itemBoxSizer2->Add(m_importServer, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Key to import"));
    wxStaticBoxSizer* itemStaticBoxSizer5 = new wxStaticBoxSizer(itemStaticBoxSizer5Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer5, 0, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer6 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer6->AddGrowableCol(1);
    itemStaticBoxSizer5->Add(itemFlexGridSizer6, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemDialog1, wxID_STATIC, _("Key ID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(itemStaticText7, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_keyIdText = new wxTextCtrl( itemDialog1, ID_IMPORTKEY_KEY_ID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_keyIdText, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemDialog1, wxID_STATIC, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(itemStaticText9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_keyNameText = new wxTextCtrl( itemDialog1, ID_IMPORTKEY_KEY_NAME, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_keyNameText, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton12 = new wxButton( itemDialog1, ID_IMPORTKEY_FIND, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton12->SetDefault();
    itemBoxSizer11->Add(itemButton12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton13 = new wxButton( itemDialog1, ID_IMPORTKEY_CLEAR, _("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer14, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine15 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer14->Add(itemStaticLine15, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemDialog1, wxID_STATIC, _("Search results:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer14->Add(itemStaticText16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine17 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer14->Add(itemStaticLine17, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_resultKeyList = new wxListView( itemDialog1, ID_IMPORTKEY_RESULT_LIST, wxDefaultPosition, wxSize(400, 100), wxLC_REPORT|wxLC_SORT_ASCENDING );
    itemBoxSizer2->Add(m_resultKeyList, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer19 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer19, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    wxButton* itemButton20 = new wxButton( itemDialog1, wxID_OK, _("&Import"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer19->AddButton(itemButton20);

    wxButton* itemButton21 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer19->AddButton(itemButton21);

    itemStdDialogButtonSizer19->Realize();

    // Connect events and objects
    m_keyIdText->Connect(ID_IMPORTKEY_KEY_ID, wxEVT_LEFT_DOWN, wxMouseEventHandler(wxGnuPGShellImportKey::OnLeftDownImportKey), NULL, this);
    m_keyIdText->Connect(ID_IMPORTKEY_KEY_ID, wxEVT_SET_FOCUS, wxFocusEventHandler(wxGnuPGShellImportKey::OnKeyIdSetFocus), NULL, this);
    m_keyNameText->Connect(ID_IMPORTKEY_KEY_NAME, wxEVT_LEFT_DOWN, wxMouseEventHandler(wxGnuPGShellImportKey::OnLeftDownImportName), NULL, this);
    m_keyNameText->Connect(ID_IMPORTKEY_KEY_NAME, wxEVT_SET_FOCUS, wxFocusEventHandler(wxGnuPGShellImportKey::OnKeyNameSetFocus), NULL, this);
////@end wxGnuPGShellImportKey content construction
    FillColumns();
    
    m_importServer->Clear();
    m_importServer->Append(wxGetApp().m_serverList);
    // select default server
    m_importServer->SetStringSelection(wxGetApp().m_defaultKeyServer);
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellImportKey::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellImportKey::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellImportKey bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellImportKey bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellImportKey::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellImportKey icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGnuPGShellImportKey icon retrieval
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_IMPORTKEY_KEY_ID
 */

void wxGnuPGShellImportKey::OnIMPORTKEYKEYIDUpdated( wxCommandEvent& event )
{
    event.Skip();
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_IMPORTKEY_KEY_NAME
 */

void wxGnuPGShellImportKey::OnIMPORTKEYKEYNAMEUpdated( wxCommandEvent& event )
{
    event.Skip();
}

void wxGnuPGShellImportKey::FillColumns()
{
    m_resultKeyList->InsertColumn(0, _("Key ID"), wxLIST_FORMAT_LEFT, 100);
    m_resultKeyList->InsertColumn(1, _("Name"), wxLIST_FORMAT_LEFT, 300);
}


/*!
 * wxEVT_UPDATE_UI event handler for wxID_OK
 */

void wxGnuPGShellImportKey::OnOKUpdate( wxUpdateUIEvent& event )
{
    event.Enable(m_resultKeyList->GetSelectedItemCount() > 0);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMPORTKEY_FIND
 */

void wxGnuPGShellImportKey::OnIMPORTKEYFINDClick( wxCommandEvent& event )
{
    wxString key = m_keyIdText->GetValue() == wxEmptyString ? m_keyNameText->GetValue() : m_keyIdText->GetValue();
    GpgKeyList list;
    wxBusyInfo *info = new wxBusyInfo(_("Please wait, searching key..."), this);
//    if ( wxGetApp().SearchKeysOnServer(m_importServer->GetString(m_importServer->GetSelection()), key, list) ) {
//        for ( unsigned int i = 0; i < list.GetCount(); i++ ) {
//            GpgKeyList::Node * node = list.Item(i);
//            if ( node ) {
//                wxGnuPGKeyPair * key = node->GetData();
//                long index = m_resultKeyList->InsertItem(m_resultKeyList->GetItemCount(), key->m_key.Id);
//                m_resultKeyList->SetItem(index, 1, key->m_key.Name);
//            }
//        }
//    }
    wxDELETE(info);
}


/*!
 * wxEVT_UPDATE_UI event handler for ID_IMPORTKEY_FIND
 */

void wxGnuPGShellImportKey::OnIMPORTKEYFINDUpdate( wxUpdateUIEvent& event )
{
    event.Enable(! (m_keyIdText->GetValue() == wxEmptyString && m_keyNameText->GetValue() == wxEmptyString) );
}


/*!
 * wxEVT_LEFT_DOWN event handler for ID_IMPORTKEY_KEY_ID
 */

void wxGnuPGShellImportKey::OnLeftDownImportKey( wxMouseEvent& event )
{
    //m_keyNameText->SetValue(wxEmptyString);
    event.Skip();
}


/*!
 * wxEVT_LEFT_DOWN event handler for ID_IMPORTKEY_KEY_NAME
 */

void wxGnuPGShellImportKey::OnLeftDownImportName( wxMouseEvent& event )
{
    //m_keyIdText->SetValue(wxEmptyString);
    event.Skip();
}


/*!
 * wxEVT_SET_FOCUS event handler for ID_IMPORTKEY_KEY_ID
 */

void wxGnuPGShellImportKey::OnKeyIdSetFocus( wxFocusEvent& event )
{
    m_keyNameText->Clear();
}


/*!
 * wxEVT_SET_FOCUS event handler for ID_IMPORTKEY_KEY_NAME
 */

void wxGnuPGShellImportKey::OnKeyNameSetFocus( wxFocusEvent& event )
{
    m_keyIdText->Clear();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMPORTKEY_CLEAR
 */

void wxGnuPGShellImportKey::OnIMPORTKEYCLEARClick( wxCommandEvent& event )
{
    m_resultKeyList->DeleteAllItems();
}

