// CWithdrawDlg.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CWithdrawDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "BankingDefine.h"


// CWithdrawDlg dialog

IMPLEMENT_DYNAMIC(CWithdrawDlg, CDialogEx)


CWithdrawDlg::CWithdrawDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_WITHDRAW, pParent)
{

}

CWithdrawDlg::~CWithdrawDlg()
{
}

void CWithdrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VALUE_0, m_InputMoney);
	DDX_Control(pDX, IDC_VALUE_1, m_FiveMillions);
	DDX_Control(pDX, IDC_VALUE_2, m_ThreeMillions);
	DDX_Control(pDX, IDC_VALUE_3, m_FiveHundreds);
	DDX_Control(pDX, IDC_VALUE_4, m_TwoMillions);
	DDX_Control(pDX, IDC_VALUE_5, m_OneMillions);
	DDX_Control(pDX, IDC_VALUE_6, m_Another);
}


BEGIN_MESSAGE_MAP(CWithdrawDlg, CDialogEx)
END_MESSAGE_MAP()


BOOL CWithdrawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
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

	LayoutControl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}
// CWithdrawDlg message handlers
void CWithdrawDlg::LayoutControl() // Change button size
{
	CRect rect;
	GetClientRect(&rect);
	MoveWindow(rect.left, rect.top, 550, 450);
	m_FiveMillions.MoveWindow(50, 100, WIDTH_BUTTON, HEIGHT_BUTTON);
	m_ThreeMillions.MoveWindow(50, 150, WIDTH_BUTTON, HEIGHT_BUTTON);
	m_FiveHundreds.MoveWindow(50, 200, WIDTH_BUTTON, HEIGHT_BUTTON);
	m_TwoMillions.MoveWindow(300, 100, WIDTH_BUTTON, HEIGHT_BUTTON);
	m_OneMillions.MoveWindow(300, 150, WIDTH_BUTTON, HEIGHT_BUTTON);
	m_Another.MoveWindow(300, 200, WIDTH_BUTTON, HEIGHT_BUTTON);
}