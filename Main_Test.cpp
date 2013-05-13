// Main_Test.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Main_Test.h"
#include "Main_TestDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMain_TestApp

BEGIN_MESSAGE_MAP(CMain_TestApp, CWinApp)
END_MESSAGE_MAP()


// CMain_TestApp construction
CMain_TestApp::CMain_TestApp()
: CWinApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMain_TestApp object
CMain_TestApp theApp;

// CMain_TestApp initialization

BOOL CMain_TestApp::InitInstance()
{

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CMain_TestDlg dlg;
	m_pMainWnd = &dlg;

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
