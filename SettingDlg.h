#pragma once


// SettingDlg dialog

class SettingDlg : public CDialog
{
	DECLARE_DYNAMIC(SettingDlg)

public:
	SettingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SettingDlg();

// Dialog Data
	enum { IDD = IDD_SETDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCountreset();
};
