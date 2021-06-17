// CMainDlg.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CMainDlg.h"
#include "afxdialogex.h"
#include "BankingDefine.h"

// CMainDlg dialog

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu *pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog

	// TODO: Add extra initialization here

	//Set Layout when start App
	LayoutControl();
	//SetText();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainDlg::LayoutControl()
{
	int scrW, scrH;
	int dlgW, dlgH;
	int x, y;

	CRect rect;

	// Get Screen width and height
	scrW = GetSystemMetrics(SM_CXSCREEN);
	scrH = GetSystemMetrics(SM_CYSCREEN);

	// Get Window rect top, left, right, bottom
	this->GetWindowRect(&rect);

	// Calculate Window width and height
	dlgW = WIDTH_APP;
	dlgH = HEIGHT_APP;

	// Calculate Window left, top (x,y)
	x = (scrW - dlgW) / 2;
	y = (scrH - dlgH) / 2;

	// Reposition Window left, top (x,y)
	this->MoveWindow(x, y, dlgW, dlgH);

}

void CMainDlg::SetText()
{
	/*CString strText = L"Đang thực hiện giao dịch ...\r\nVui lòng chờ";
	m_staticText.SetWindowTextW(strText);*/
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
END_MESSAGE_MAP()


// CMainDlg message handlers
