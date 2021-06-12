// CBalanceDetail.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CBalanceDetail.h"
#include "afxdialogex.h"
//sang edit
#include "BankingDefine.h"
//end sang edit

// CBalanceDetail dialog

IMPLEMENT_DYNAMIC(CBalanceDetail, CDialogEx)

CBalanceDetail::CBalanceDetail(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BALANCE_DETAIL, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CBalanceDetail::~CBalanceDetail()
{
}

void CBalanceDetail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_TEXT_HEADER, m_balanceDetailTextHeader);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_MONEY_TEXT, m_balanceDetailMoneyText);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_MONEY_VALUE, m_balanceDetailMoneyValue);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_TRANSACTION_FEE_TEXT, m_balanceDetailTransactionFeeText);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_TRANSACTION_FEE_VALUE, m_balanceDetailTransactionFeeValue);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_VAT_TEXT, m_balanceDetailVatText);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_VAT_VALUE, m_balanceDetailVatValue);
	DDX_Control(pDX, IDC_STATIC_BALANCE_DETAIL_BILL_QUESTION_TEXT, m_balanceDetailBillQuestionText);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_DETAIL_BILL_QUESTION_YES, m_balanceDetailBillAnswerYes);
	DDX_Control(pDX, IDC_BUTTON_BALANCE_DETAIL_BILL_QUESTION_NO, m_balanceDetailBillAnswerNo);
}


BEGIN_MESSAGE_MAP(CBalanceDetail, CDialogEx)
END_MESSAGE_MAP()


// CBalanceDetail message handlers
//sang
BOOL CBalanceDetail::OnInitDialog()
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

void CBalanceDetail::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBalanceDetail::OnPaint()
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
HCURSOR CBalanceDetail::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBalanceDetail::LayoutControl()
{
	CRect rect;
	GetClientRect(&rect);
	MoveWindow(rect.left, rect.top, WIDTH_APP, HEIGHT_APP);
	//text header
	m_balanceDetailTextHeader.MoveWindow(X_TEXT_BALANCE_HEADER, Y_TEXT_BALANCE_HEADER, WIDTH_TEXT_BALANCE_DEFAULT, HEIGHT_TEXT_BALANCE_DEFAULT);
	m_balanceDetailTextHeader.SetWindowTextW(_T("Giao dịch vấn tin số dư"));
	//valude balance money
	m_balanceDetailMoneyText.MoveWindow(X_TEXT_BALANCE_MONEY, Y_TEXT_BALANCE_MONEY, WIDTH_TEXT_BALANCE_MONEY, HEIGHT_TEXT_BALANCE_MONEY);
	m_balanceDetailMoneyText.SetWindowTextW(_T("Số dư tài khoản hiện tại của quý khách"));
	m_balanceDetailMoneyValue.MoveWindow(X_BALANCE_MONEY_VALUE, Y_BALANCE_MONEY_VALUE, WIDTH_BALANCE_MONEY_VALUE, HEIGHT_BALANCE_MONEY_VALUE);
	m_balanceDetailMoneyValue.SetWindowTextW(_T("1 000 000 000"));
	//transaction fee
	m_balanceDetailTransactionFeeText.MoveWindow(X_TEXT_BALANCE_TRANSACTION_FEE, Y_TEXT_BALANCE_TRANSACTION_FEE, WIDTH_TEXT_BALANCE_TRANSACTION_FEE, HEIGHT_TEXT_BALANCE_TRANSACTION_FEE);
	m_balanceDetailTransactionFeeText.SetWindowTextW(_T("Số dư tài khoản hiện tại của quý khách"));
	m_balanceDetailTransactionFeeValue.MoveWindow(X_BALANCE_TRANSACTION_FEE_VALUE, Y_BALANCE_TRANSACTION_FEE_VALUE, WIDTH_BALANCE_TRANSACTION_FEE_VALUE, HEIGHT_BALANCE_TRANSACTION_FEE_VALUE);
	m_balanceDetailTransactionFeeValue.SetWindowTextW(_T("0. 000 000 000"));
	//vat
	m_balanceDetailVatText.MoveWindow(X_TEXT_BALANCE_VAT, Y_TEXT_BALANCE_VAT, WIDTH_TEXT_BALANCE_VAT, HEIGHT_TEXT_BALANCE_VAT);
	m_balanceDetailVatText.SetWindowTextW(_T("VAT"));
	m_balanceDetailVatValue.MoveWindow(X_BALANCE_VAT_VALUE, Y_BALANCE_VAT_VALUE, WIDTH_BALANCE_VAT_VALUE, HEIGHT_BALANCE_VAT_VALUE);
	m_balanceDetailVatValue.SetWindowTextW(_T("0. 000 000 000"));
	//bill text
	m_balanceDetailBillQuestionText.MoveWindow(X_TEXT_BALANCE_BILL_QUESTION, Y_TEXT_BALANCE_BILL_QUESTION, WIDTH_TEXT_BALANCE_BILL_QUESTION, HEIGHT_TEXT_BALANCE_BILL_QUESTION);
	m_balanceDetailBillQuestionText.SetWindowTextW(_T("Quý khách có muốn in hóa đơn không"));
	//bill answer yes/no
	m_balanceDetailBillAnswerYes.MoveWindow(X_BUTTON_BALANCE_YES, Y_BUTTON_BALANCE_YES, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceDetailBillAnswerYes.SetWindowTextW(_T("Có"));

	m_balanceDetailBillAnswerNo.MoveWindow(X_BUTTON_BALANCE_NO, Y_BUTTON_BALANCE_NO, WIDTH_BUTTON_BALANCE_DEFAULT, HEIGHT_BUTTON_BALANCE_DEFAULT);
	m_balanceDetailBillAnswerNo.SetWindowTextW(_T("Không"));

}