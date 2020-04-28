/////////////////////////////////////////////////////////////////////////////
// Name:        wxGnuPGShellSelectRecipient.cpp
// Purpose:     
// Author:      cod
// Modified by: 
// Created:     23/08/2007 10:51:44
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "wxGnuPGShellSelectRecipient.h"
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

#include "wxGnuPGShellSelectRecipient.h"
#include "wxgnupgshellapp.h"
#include "wxGnuPGKeyPair.h"


////@begin XPM images
#include "wxwin32x32.xpm"
////@end XPM images


/*!
 * wxGnuPGShellSelectRecipient type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGnuPGShellSelectRecipient, wxDialog )


/*!
 * wxGnuPGShellSelectRecipient event table definition
 */

BEGIN_EVENT_TABLE( wxGnuPGShellSelectRecipient, wxDialog )

////@begin wxGnuPGShellSelectRecipient event table entries
    EVT_RADIOBUTTON( ID_RECEPIENT_ASYNC, wxGnuPGShellSelectRecipient::OnRECEPIENTASYNCSelected )

    EVT_RADIOBUTTON( ID_RECEPIENT_SYNC, wxGnuPGShellSelectRecipient::OnRECEPIENTSYNCSelected )

    EVT_UPDATE_UI( wxID_OK, wxGnuPGShellSelectRecipient::OnOkUpdate )

////@end wxGnuPGShellSelectRecipient event table entries

END_EVENT_TABLE()


/*!
 * wxGnuPGShellSelectRecipient constructors
 */

wxGnuPGShellSelectRecipient::wxGnuPGShellSelectRecipient()
{
    Init();
}

wxGnuPGShellSelectRecipient::wxGnuPGShellSelectRecipient( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * wxGnuPGShellSelectRecipient creator
 */

bool wxGnuPGShellSelectRecipient::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxGnuPGShellSelectRecipient creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("wxwin32x32.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxGnuPGShellSelectRecipient creation
    return true;
}


/*!
 * wxGnuPGShellSelectRecipient destructor
 */

wxGnuPGShellSelectRecipient::~wxGnuPGShellSelectRecipient()
{
////@begin wxGnuPGShellSelectRecipient destruction
////@end wxGnuPGShellSelectRecipient destruction
}


/*!
 * Member initialisation
 */

void wxGnuPGShellSelectRecipient::Init()
{
////@begin wxGnuPGShellSelectRecipient member initialisation
    m_useKey = NULL;
    m_recKeyList = NULL;
    m_usePass = NULL;
    m_pass = NULL;
    m_repeat = NULL;
    m_needArmor = NULL;
////@end wxGnuPGShellSelectRecipient member initialisation
}


/*!
 * Control creation for wxGnuPGShellSelectRecipient
 */

void wxGnuPGShellSelectRecipient::CreateControls()
{    
////@begin wxGnuPGShellSelectRecipient content construction
    wxGnuPGShellSelectRecipient* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("\nSelect recepient for asymmetric or passphrase for symmetric encryption\n"), wxDefaultPosition, wxSize(-1, 45), wxALIGN_CENTRE|wxST_NO_AUTORESIZE );
    itemStaticText3->Wrap(300);
    itemStaticText3->SetBackgroundColour(wxColour(255, 255, 255));
    itemStaticText3->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Tahoma")));
    itemBoxSizer2->Add(itemStaticText3, 0, wxGROW, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer4, 0, wxGROW|wxALL, 5);

    m_useKey = new wxRadioButton( itemDialog1, ID_RECEPIENT_ASYNC, _("Use key"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    m_useKey->SetValue(true);
    itemBoxSizer4->Add(m_useKey, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine6 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer4->Add(itemStaticLine6, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_recKeyList = new wxListView( itemDialog1, ID_RECIPIENT_KEYLIST, wxDefaultPosition, wxSize(400, 200), wxLC_REPORT|wxLC_SINGLE_SEL );
    itemBoxSizer2->Add(m_recKeyList, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer8, 0, wxGROW|wxALL, 5);

    m_usePass = new wxRadioButton( itemDialog1, ID_RECEPIENT_SYNC, _("Use password"), wxDefaultPosition, wxDefaultSize, 0 );
    m_usePass->SetValue(false);
    itemBoxSizer8->Add(m_usePass, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine10 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer8->Add(itemStaticLine10, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer11 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer11->AddGrowableCol(1);
    itemBoxSizer2->Add(itemFlexGridSizer11, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemDialog1, wxID_STATIC, _("Passphrase:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(itemStaticText12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_pass = new wxTextCtrl( itemDialog1, ID_RECEPIENT_PASS, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    m_pass->Enable(false);
    itemFlexGridSizer11->Add(m_pass, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText14 = new wxStaticText( itemDialog1, wxID_STATIC, _("Repeat:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(itemStaticText14, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_repeat = new wxTextCtrl( itemDialog1, ID_RECEPIENT_REPEAT, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    m_repeat->Enable(false);
    itemFlexGridSizer11->Add(m_repeat, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_needArmor = new wxCheckBox( itemDialog1, ID_RECIPIENT_ARMOR, _("Armor"), wxDefaultPosition, wxDefaultSize, 0 );
    m_needArmor->SetValue(true);
    itemBoxSizer2->Add(m_needArmor, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticLine* itemStaticLine17 = new wxStaticLine( itemDialog1, ID_STATICLINE5, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine17, 0, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer18 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer18, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* itemButton19 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer18->AddButton(itemButton19);

    wxButton* itemButton20 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer18->AddButton(itemButton20);

    itemStdDialogButtonSizer18->Realize();

////@end wxGnuPGShellSelectRecipient content construction
    m_recKeyList->InsertColumn(0, _("Key ID"));
    m_recKeyList->InsertColumn(1, _("User Name"), wxLIST_FORMAT_LEFT, 300);

    FillKeyList();
}


/*!
 * Should we show tooltips?
 */

bool wxGnuPGShellSelectRecipient::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxGnuPGShellSelectRecipient::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGnuPGShellSelectRecipient bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGnuPGShellSelectRecipient bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxGnuPGShellSelectRecipient::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGnuPGShellSelectRecipient icon retrieval
    wxUnusedVar(name);
    if (name == _T("wxwin32x32.xpm"))
    {
        wxIcon icon(wxwin32x32_xpm);
        return icon;
    }
    return wxNullIcon;
////@end wxGnuPGShellSelectRecipient icon retrieval
}


/*!
 * wxEVT_UPDATE_UI event handler for wxID_OK
 */

void wxGnuPGShellSelectRecipient::OnOkUpdate( wxUpdateUIEvent& event )
{
    bool enable = m_useKey->GetValue() ? m_recKeyList->GetSelectedItemCount() > 0 : (m_pass->GetValue() != wxEmptyString && m_pass->GetValue() == m_repeat->GetValue()) ;
    event.Enable(enable);
}

void wxGnuPGShellSelectRecipient::FillKeyList()
{
    m_recKeyList->DeleteAllItems();

//    GpgKeyList::Node * node;
//    wxColor cl(wxT("#F0F0F9"));
//    int count = static_cast<int>(wxGetApp().GetKeyList().GetCount());
//
//    for ( int i=0; i < count; i++ ) {
//        node = wxGetApp().GetKeyList().Item(i);
//
//        if(node) {
//            wxGnuPGKeyPair * key = node->GetData();
//
//            if ( key ) {
//                m_recKeyList->InsertItem(i, key->m_key.Id);
//                m_recKeyList->SetItem(i, 1, key->m_key.Name);
//
//                if (i%2) { m_recKeyList->SetItemBackgroundColour(i, cl); } // odd lines color
//            }
//        }
//    }
	if(m_recKeyList->GetItemCount())
	{
		m_recKeyList->Select(0);
	}
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RECEPIENT_ASYNC
 */

void wxGnuPGShellSelectRecipient::OnRECEPIENTASYNCSelected( wxCommandEvent& event )
{
    m_pass->Enable(false);
    m_repeat->Enable(false);
    m_recKeyList->Enable();
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RECEPIENT_SYNC
 */

void wxGnuPGShellSelectRecipient::OnRECEPIENTSYNCSelected( wxCommandEvent& event )
{
    m_pass->Enable();
    m_repeat->Enable();
    m_recKeyList->Enable(false);
}

