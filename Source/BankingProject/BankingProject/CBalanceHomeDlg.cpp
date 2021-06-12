// CBalanceHomeDlg.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CBalanceHomeDlg.h"
#include "afxdialogex.h"
//sang edit
#include "BankingDefine.h"
#include "CBalanceDetail.h"
//end sang edit

// CBalanceHomeDlg dialog

IMPLEMENT_DYNAMIC(CBalanceHomeDlg, CDialogEx)

CBalanceHomeDlg::CBalanceHomeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BALANCE_HOME, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CBalanceHomeDlg::~CBalanceHomeDlg()
{
}

void CBalanceHomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BALANCE_HOME_TEXT_HEADER, m_balanceHomeTextHeader);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_HOME_DEFAULT, m_balanceHomeButtonDefault);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_HOME_DEPOSITS, m_balanceHomeButtonDeposits);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_HOME_SAVING, m_balanceHomeButtonSaving);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_HOME_CREDIT, m_balanceHomeButtonCredit);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_HOME_RETURN_CASH, m_balanceHomeButtonReturnCash);
}


BEGIN_MESSAGE_MAP(CBalanceHomeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BALANCE_HOME_DEFAULT, &CBalanceHomeDlg::OnBnClickedButtonBalanceHomeDefault)
END_MESSAGE_MAP()


// CBalanceHomeDlg message handlers

//sang
BOOL CBalanceHomeDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//Set Layout when start App
	LayoutControl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBalanceHomeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		/*CAboutDlg dlgAbout;
		dlgAbout.DoModal();*/
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBalanceHomeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBalanceHomeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBalanceHomeDlg::LayoutControl()
{
	CRect rect;
	GetClientRect(&rect);
	MoveWindow(rect.left, rect.top, WIDTH_APP, HEIGHT_APP);
	/*m_btTest.MoveWindow(X_BUT_TEST, Y_BUT_TEST, WIDTH_BUT_TEST, HEIGHT_BUT_TEST);*/
	m_balanceHomeTextHeader.MoveWindow(X_TEXT_BALANCE_HEADER, Y_TEXT_BALANCE_HEADER, WIDTH_TEXT_BALANCE_DEFAULT, HEIGHT_TEXT_BALANCE_DEFAULT);
	m_balanceHomeTextHeader.SetWindowTextW(_T("Mời bạn chọn loại tài khoản"));
	m_balanceHomeButtonDefault.MoveWindow(X_BUTTON_BALANCE_DEFAULT, Y_BUTTON_BALANCE_DEFAULT, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceHomeButtonDefault.SetWindowTextW(_T("Mặc định"));
	m_balanceHomeButtonDeposits.MoveWindow(X_BUTTON_BALANCE_DEPOSITS, Y_BUTTON_BALANCE_DEPOSITS, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceHomeButtonDeposits.SetWindowTextW(_T("Tiền gửi"));
	m_balanceHomeButtonSaving.MoveWindow(X_BUTTON_BALANCE_SAVING, Y_BUTTON_BALANCE_SAVING, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceHomeButtonSaving.SetWindowTextW(_T("Tiết kiệm"));
	m_balanceHomeButtonCredit.MoveWindow(X_BUTTON_BALANCE_CREDIT, Y_BUTTON_BALANCE_CREDIT, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceHomeButtonCredit.SetWindowTextW(_T("Tài khoản thẻ"));
	m_balanceHomeButtonReturnCash.MoveWindow(X_BUTTON_BALANCE_RETURN_CASH, Y_BUTTON_BALANCE_RETURN_CASH, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceHomeButtonReturnCash.SetWindowTextW(_T("Trả thẻ"));
}




void CBalanceHomeDlg::OnBnClickedButtonBalanceHomeDefault()
{
	// TODO: Add your control notification handler code here
	CBalanceDetail balanceDetail;
	balanceDetail.DoModal();
}
