#include "StdAfx.h"
#include "SplashWnd.h"
#include "resource.h"

CSplashWnd* CSplashWnd::c_pSplashWnd;

BEGIN_MESSAGE_MAP(CSplashWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

CSplashWnd::CSplashWnd(void)
/*: c_pSplashWnd(NULL)*/
{
}

CSplashWnd::~CSplashWnd(void)
{
}

void CSplashWnd::ShowSplashScreen(CWnd* pParentWnd)
{
	c_pSplashWnd = new CSplashWnd;
	if (!c_pSplashWnd->Create(pParentWnd))
		delete c_pSplashWnd;
	else
		c_pSplashWnd->UpdateWindow();
}

BOOL CSplashWnd::Create(CWnd* pParentWnd)
{
	if (!m_bitmap.LoadBitmap(IDB_SPLASH))	/*����λͼ��Դ��������Դ�ļ������*/
		return FALSE;

	BITMAP bm;
	m_bitmap.GetBitmap(&bm);

	return CreateEx(0,
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
		NULL, WS_POPUP | WS_VISIBLE, 0, 0, bm.bmWidth, bm.bmHeight, pParentWnd->GetSafeHwnd(), NULL);
	return 0;
}

int CSplashWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	// Center the window.
	CenterWindow();

	// Set a timer to destroy the splash screen.
	SetTimer(1, 1000, NULL);				/*��������ʱ��*/

	return 0;
}

void CSplashWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
	CDC dcImage;
	if (!dcImage.CreateCompatibleDC(&dc))
		return;

	BITMAP bm;
	m_bitmap.GetBitmap(&bm);

	// Paint the image.
	CBitmap* pOldBitmap = dcImage.SelectObject(&m_bitmap);
	dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &dcImage, 0, 0, SRCCOPY);
	dcImage.SelectObject(pOldBitmap);
}

void CSplashWnd::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	DestroyWindow();
	AfxGetMainWnd()->UpdateWindow();

	CWnd::OnTimer(nIDEvent);
}