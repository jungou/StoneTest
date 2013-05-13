// Main_TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Main_Test.h"
#include "Main_TestDlg.h"
#include "SettingDlg.h"
#include "SplashWnd.h"


#pragma comment(lib,"WinMM.Lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMain_TestDlg dialog

CMain_TestDlg::CMain_TestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMain_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMain_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCOPE, m_wndScope);
	DDX_Control(pDX, ID_TEST, m_btn_start);
}

BEGIN_MESSAGE_MAP(CMain_TestDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	ON_BN_CLICKED(ID_TEST, &CMain_TestDlg::OnBnClickedTest)
	ON_BN_CLICKED(IDC_STUDY, &CMain_TestDlg::OnBnClickedStudy)
	ON_BN_CLICKED(IDC_SENS, &CMain_TestDlg::OnBnClickedSens)
	ON_BN_CLICKED(IDC_SET, &CMain_TestDlg::OnBnClickedSet)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMain_TestDlg message handlers

BOOL CMain_TestDlg::OnInitDialog()
{
	CSplashWnd::ShowSplashScreen(this);
	Sleep(3000);
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// determine the rectangle for the control

	m_wndScope.SetTitle(_T("µçÑ¹"));
	m_wndScope.SetValueString(_T("µçÑ¹"),_T("·ü"));
	btest = false;

	// TODO: Add extra initialization here
	ShowWindow(SW_SHOWMAXIMIZED);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CMain_TestDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_MAIN_TEST_DIALOG_WIDE) : 
		MAKEINTRESOURCE(IDD_MAIN_TEST_DIALOG));
	}
}
#endif


void CMain_TestDlg::OnBnClickedTest()
{
	// TODO: Add your control notification handler code here
	if(!btest)
	{
		SetTimer(1,20,NULL);
		m_btn_start.SetWindowText(_T("stop"));
		btest = true;
	}
	else
	{
		KillTimer(1);
		m_btn_start.SetWindowText(_T("start"));
		btest = false;
	}

}

void CMain_TestDlg::OnBnClickedStudy()
{
	// TODO: Add your control notification handler code here
}

void CMain_TestDlg::OnBnClickedSens()
{
	// TODO: Add your control notification handler code here
}

void CMain_TestDlg::OnBnClickedSet()
{
	// TODO: Add your control notification handler code here
	SettingDlg mysettindlg;
	mysettindlg.DoModal();
}



void CMain_TestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

#if 1
	static double dTime = 0; //::timeGetTime()/1000.0;
	dTime+=0.1;
#else
	double dTime = ::timeGetTime()/1000.0;
#endif 
	double dValue[3];
#if 1
	dValue[0] = 4*sin(dTime+2);
	m_wndScope.AddValue(dTime,dValue[0]);

	m_wndScope.SetValue(dValue[0]);
	m_wndScope.UpdateCurve();

	CDialog::OnTimer(nIDEvent);
#endif 
}
