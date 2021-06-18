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
	DDX_Control(pDX, IDC_STATIC_MAIN_TEXT, m_staticMainScrTopText);
	DDX_Control(pDX, IDC_BUTTON_WIDTHDRAW, m_btMainScrWithdraw);
	DDX_Control(pDX, IDC_BUTTON_BALANCE, m_btMainScrBalance);
	DDX_Control(pDX, IDC_BUTTON_CHANGE_PIN, m_btMainScrChangePin);
	DDX_Control(pDX, IDC_BUTTON_TRANSFER_MONEY, m_btMainScrTransferMoney);
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
	SetText();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainDlg::SetFontSize()
{
	// test lan 1 (work)
	int text_fontHeight = 40;
	int button_fontHeight = 35;

	const wchar_t *fontName = L"Roboto";

	CFont *text_font = new CFont();
	CFont *button_font = new CFont();
	LOGFONT text_logfont;
	LOGFONT button_logfont;
	memset(&text_logfont, 0, sizeof(LOGFONT));			// Clear out structure.
	memset(&button_logfont, 0, sizeof(LOGFONT));		// Clear out structure.
	text_logfont.lfHeight = text_fontHeight;			// Request a 20-pixel-high font
	button_logfont.lfHeight = button_fontHeight;		// Request a 20-pixel-high font

#pragma warning(suppress : 4996)
	wcscpy(text_logfont.lfFaceName, fontName);			// with font face name.
#pragma warning(suppress : 4996)
	wcscpy(button_logfont.lfFaceName, fontName);		// with font face name.

	text_font->CreateFontIndirect(&text_logfont);		// Create the font.
	button_font->CreateFontIndirect(&button_logfont);	// Create the font.

	CWnd *m_staticMainScrTopText = GetDlgItem(IDC_STATIC_MAIN_TEXT);
	CWnd *m_btMainScrWithdraw = GetDlgItem(IDC_BUTTON_WIDTHDRAW);
	CWnd *m_btMainScrBalance = GetDlgItem(IDC_BUTTON_BALANCE);
	CWnd *m_btMainScrChangePin = GetDlgItem(IDC_BUTTON_CHANGE_PIN);
	CWnd *m_btMainScrTransferMoney = GetDlgItem(IDC_BUTTON_TRANSFER_MONEY);
	if (   m_staticMainScrTopText != NULL 
		|| m_btMainScrWithdraw != NULL 
		|| m_btMainScrBalance != NULL
		|| m_btMainScrChangePin != NULL
		|| m_btMainScrTransferMoney != NULL
		)
	{
		m_staticMainScrTopText->SetFont(text_font);
		m_btMainScrWithdraw->SetFont(button_font);
		m_btMainScrBalance->SetFont(button_font);
		m_btMainScrChangePin->SetFont(button_font);
		m_btMainScrTransferMoney->SetFont(button_font);
	}
}

void CMainDlg::SetText()
{
	CString strTopText = L"Xin vui lòng lựa chọn giao dịch";
	m_staticMainScrTopText.SetWindowTextW(strTopText);

	CString strWithdraw = L"Rút tiền";
	m_btMainScrWithdraw.SetWindowTextW(strWithdraw);

	CString strBalance = L"Xem số dư";
	m_btMainScrBalance.SetWindowTextW(strBalance);
	
	CString strChangePin = L"Đổi PIN";
	m_btMainScrChangePin.SetWindowTextW(strChangePin);

	CString strTransferMoney = L"Chuyển khoản";
	m_btMainScrTransferMoney.SetWindowTextW(strTransferMoney);

	SetFontSize();
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

	m_staticMainScrTopText.MoveWindow(
		(dlgW - WIDTH_TEXT) / 2, 50,
		WIDTH_TEXT, HEIGHT_TEXT
	);

	m_btMainScrWithdraw.MoveWindow(
		X_BUT_MAIN_WITHDRAW, Y_BUT_MAIN_WITHDRAW,
		W_BUTTON, H_BUTTON
	);

	m_btMainScrBalance.MoveWindow(
		X_BUT_MAIN_BALANCE, Y_BUT_MAIN_BALANCE,
		W_BUTTON, H_BUTTON
	);

	m_btMainScrChangePin.MoveWindow(
		X_BUT_MAIN_CHANGE_PIN, Y_BUT_MAIN_CHANGE_PIN,
		W_BUTTON, H_BUTTON
	);

	m_btMainScrTransferMoney.MoveWindow(
		X_BUT_MAIN_TRANSFER_MONEY, Y_BUT_MAIN_TRANSFER_MONEY,
		W_BUTTON, H_BUTTON
	);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_WIDTHDRAW, &CMainDlg::OnBnClickedButtonWidthdraw)
	ON_BN_CLICKED(IDC_BUTTON_BALANCE, &CMainDlg::OnBnClickedButtonBalance)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_PIN, &CMainDlg::OnBnClickedButtonChangePin)
	ON_BN_CLICKED(IDC_BUTTON_TRANSFER_MONEY, &CMainDlg::OnBnClickedButtonTransferMoney)
END_MESSAGE_MAP()


// CMainDlg message handlers


void CMainDlg::OnBnClickedButtonWidthdraw()
{
	// TODO: Add your control notification handler code here
	CWithdrawDlg toWithdrawDlg;
	toWithdrawDlg.DoModal();
}


void CMainDlg::OnBnClickedButtonBalance()
{
	// TODO: Add your control notification handler code here
	CBalanceHomeDlg toBalanceDlg;
	toBalanceDlg.DoModal();
}


void CMainDlg::OnBnClickedButtonChangePin()
{
	// TODO: Add your control notification handler code here
}


void CMainDlg::OnBnClickedButtonTransferMoney()
{
	// TODO: Add your control notification handler code here
}
