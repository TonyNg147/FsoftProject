
// BankingProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BankingProject.h"
#include "BankingProjectDlg.h"
#include "afxdialogex.h"
#include "BankingDefine.h"
/*
SangTH5 include
*/
#include "CBalanceHomeDlg.h"
/*
end SangTH5 include
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	BOOL OnInitDialog();
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();
	return TRUE;
}

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBankingProjectDlg dialog



CBankingProjectDlg::CBankingProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BANKINGPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBankingProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_TEST, m_btTest);
}

BEGIN_MESSAGE_MAP(CBankingProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_PHULH1_WAITINGSCR, &CBankingProjectDlg::OnPhulh1WaitingscMain)

	/*
	*   SangTH5 edit 10/06
	*/
	ON_COMMAND(ID_SANGTH5_BALANCEDLG, &CBankingProjectDlg::OnSangth5Balancedlg)
	/*
	*   end SangTH5 edit 10/06
	*/

	ON_COMMAND(ID_TRANGPT24_WITHDRAW, &CBankingProjectDlg::OnTrangpt24Withdraw)
	ON_COMMAND(ID_TRANGPT24_ANOTHER, &CBankingProjectDlg::OnTrangpt24Another)

	ON_COMMAND(ID_PHULH1_CONTINUESCR, &CBankingProjectDlg::OnPhulh1Continuescr)
	ON_COMMAND(ID_PHULH1_MAINSCR, &CBankingProjectDlg::OnPhulh1Mainscr)
END_MESSAGE_MAP()


// CBankingProjectDlg message handlers

BOOL CBankingProjectDlg::OnInitDialog()
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
  
	m_waitingMsgDlg.Create(IDD_DIALOG_MSG_WAITING, this);

	m_menu.LoadMenuW(IDR_MENU_MAIN); // nhớ commit IDR_MENU_MAIN
	SetMenu(&m_menu);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBankingProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBankingProjectDlg::OnPaint()
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
HCURSOR CBankingProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBankingProjectDlg::LayoutControl()
{
	CRect rectControl;
	GetClientRect(&rectControl);
	MoveWindow(rectControl.left, rectControl.top, WIDTH_APP, HEIGHT_APP);
	m_btTest.MoveWindow(X_BUT_TEST, Y_BUT_TEST, WIDTH_BUT_TEST, HEIGHT_BUT_TEST);
}

void CBankingProjectDlg::OnPhulh1WaitingscMain()
{
	// TODO: Add your command handler code here
	CWaitingMsgDialog waitingDlg;
	waitingDlg.DoModal();
}

/*
	SangTH5 edit
*/
void CBankingProjectDlg::OnSangth5Balancedlg()
{
	// TODO: Add your command handler code here
	CBalanceHomeDlg balanceDlg;
	balanceDlg.DoModal();
}
/*
	end SangTH5 edit
*/

void CBankingProjectDlg::OnTrangpt24Withdraw()
{
	// TODO: Add your command handler code here
	CWithdrawDlg withdrawDlg;
	withdrawDlg.DoModal();
}

void CBankingProjectDlg::OnTrangpt24Another()
{
	// TODO: Add your command handler code here
	CWithdrawAnother0 withdrawAnotherDlg;
	withdrawAnotherDlg.DoModal();
}

void CBankingProjectDlg::OnPhulh1Continuescr()
{
	// TODO: Add your command handler code here
	CContinueDlg continueDlg;
	continueDlg.DoModal();
}


void CBankingProjectDlg::OnPhulh1Mainscr()
{
	// TODO: Add your command handler code here
	CMainDlg mainDlg;
	mainDlg.DoModal();
}
