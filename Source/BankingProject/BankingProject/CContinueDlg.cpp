// CContinueDlg.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CContinueDlg.h"
#include "afxdialogex.h"
#include "BankingDefine.h"


// CContinueDlg dialog

IMPLEMENT_DYNAMIC(CContinueDlg, CDialogEx)

CContinueDlg::CContinueDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CONTINUE, pParent)
{

}

CContinueDlg::~CContinueDlg()
{
}

void CContinueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_CONTINUE_TEXT, m_ContinueText);
	DDX_Control(pDX, IDC_BUTTON_YES, m_btYes);
	DDX_Control(pDX, IDC_BUTTON_NO, m_btNo);
}


BOOL CContinueDlg::OnInitDialog()
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

	//Set Layout when start App
	LayoutControl();
	SetText();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CContinueDlg::SetText()
{
	CString strContinueText = L"Quý khách có muốn thực hiện giao dịch khác?";
	m_ContinueText.SetWindowTextW(strContinueText);

	CString strYes = L"Có";
	m_btYes.SetWindowTextW(strYes);

	CString strNo = L"Không";
	m_btNo.SetWindowTextW(strNo);
}

void CContinueDlg::LayoutControl()
{
	CRect rectControl;
	GetClientRect(&rectControl);
	MoveWindow(rectControl.left, rectControl.top, WIDTH_APP, HEIGHT_APP);

	m_ContinueText.MoveWindow(
		rectControl.left,
		rectControl.top,
		WIDTH_TEXT,
		HEIGHT_TEXT
	);
}


BEGIN_MESSAGE_MAP(CContinueDlg, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CContinueDlg message handlers


HBRUSH CContinueDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_CONTINUE_TEXT)
	{
		pDC->SetTextColor(RGB(0, 60, 197));
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
