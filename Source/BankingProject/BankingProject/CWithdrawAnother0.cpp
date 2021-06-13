// CWithdrawAnother0.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "BankingDefine.h"
#include "CWithdrawAnother0.h"
#include "afxdialogex.h"


// CWithdrawAnother0 dialog

IMPLEMENT_DYNAMIC(CWithdrawAnother0, CDialogEx)

CWithdrawAnother0::CWithdrawAnother0(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_WITHDRAW_ANOTHER, pParent)
{

}

CWithdrawAnother0::~CWithdrawAnother0()
{
}

void CWithdrawAnother0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ANOTHER_INPUT, m_InputMoney);
	DDX_Control(pDX, IDC_ANOTHER_MINMAX, m_MinMaxMoney);
	DDX_Control(pDX, IDC_ANOTHER_YES, m_Yes);
	DDX_Control(pDX, IDC_ANOTHER_EDIT, m_EditMoney);
	DDX_Control(pDX, IDC_ANOTHER_WRONG, m_Wrong);
}
BEGIN_MESSAGE_MAP(CWithdrawAnother0, CDialogEx)
END_MESSAGE_MAP()

BOOL CWithdrawAnother0::OnInitDialog()
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


	// TODO: Add extra initialization here
	LayoutControl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CWithdrawAnother0::LayoutControl() // Change button size
{
	CRect rect;
	GetClientRect(&rect);
	MoveWindow(rect.left, rect.top, 550, 450);
	m_Yes.MoveWindow(50, 100, WIDTH_BUTTON, HEIGHT_BUTTON);
	m_Wrong.MoveWindow(50, 150, WIDTH_BUTTON, HEIGHT_BUTTON);
}

// CWithdrawAnother0 message handlers
