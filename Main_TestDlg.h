// Main_TestDlg.h : header file
//
#include "Scope.h"
#pragma once#include "afxwin.h"


// CMain_TestDlg dialog
class CMain_TestDlg : public CDialog
{
	// Construction
public:
	CMain_TestDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = IDD_MAIN_TEST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	CScope	m_wndScope;
	bool btest;
	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTest();
	afx_msg void OnBnClickedStudy();
	afx_msg void OnBnClickedSens();
	afx_msg void OnBnClickedSet();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButton m_btn_start;
};
