// CWaitingMsgDialog.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CWaitingMsgDialog.h"
#include "afxdialogex.h"
#include "BankingDefine.h"

#define ID_WAITING_DLG 0
#define WAITING_TIMER 3000 //3 seconds

// CWaitingMsgDialog dialog

IMPLEMENT_DYNAMIC(CWaitingMsgDialog, CDialogEx)

CWaitingMsgDialog::CWaitingMsgDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MSG_WAITING, pParent)
{

}

CWaitingMsgDialog::~CWaitingMsgDialog()
{
}

void CWaitingMsgDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	/*
		Begin PhuLH1: 10.06
	*/
	DDX_Control(pDX, IDC_WAITING_TEXT, m_staticText);
	/*
		End PhuLH1: 10.06
	*/
}


BEGIN_MESSAGE_MAP(CWaitingMsgDialog, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CWaitingMsgDialog message handlers

BOOL CWaitingMsgDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*
		Begin PhuLH1: 10.06
	*/
	// set text cho static text (thay đổi property caption)
	m_staticText.SetWindowTextW(_T("Đang thực hiện giao dịch ...\r\nVui lòng chờ"));
	// set timer hiển thị cho dialog
	SetTimer(ID_WAITING_DLG, WAITING_TIMER, NULL);
	/*
		End PhuLH1: 10.06
	*/

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

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CWaitingMsgDialog::LayoutControl()
{
	/*
		PhuLH1:
		http://www.equestionanswers.com/vcpp/dialog-middle-of-desktop.php
		https://stackoverflow.com/questions/771109/how-to-move-controls-to-the-middle-of-an-mfc-form
	*/

	CRect rectControl;
	GetClientRect(&rectControl);
	MoveWindow(rectControl.left, rectControl.top, WIDTH_APP, HEIGHT_APP);
}



HBRUSH CWaitingMsgDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDC_WAITING_TEXT)
	{
		pDC->SetTextColor(RGB(0, 60, 197));
	}

	return hbr;
}


void CWaitingMsgDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	EndDialog(ID_WAITING_DLG);

	CDialogEx::OnTimer(nIDEvent);
}

