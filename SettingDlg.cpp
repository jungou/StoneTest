// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Main_Test.h"
#include "SettingDlg.h"


// SettingDlg dialog

IMPLEMENT_DYNAMIC(SettingDlg, CDialog)

SettingDlg::SettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SettingDlg::IDD, pParent)
{

}

SettingDlg::~SettingDlg()
{
}

void SettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SettingDlg, CDialog)
	ON_BN_CLICKED(IDC_COUNTRESET, &SettingDlg::OnBnClickedCountreset)
END_MESSAGE_MAP()


// SettingDlg message handlers

void SettingDlg::OnBnClickedCountreset()
{
	// TODO: Add your control notification handler code here
}
