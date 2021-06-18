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

void CContinueDlg::SetFontSize()
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

	CWnd *m_ContinueText = GetDlgItem(IDC_STATIC_CONTINUE_TEXT);
	CWnd *m_btYes = GetDlgItem(IDC_BUTTON_YES);
	CWnd *m_btNo = GetDlgItem(IDC_BUTTON_NO);
	if (m_ContinueText != NULL || m_btYes != NULL || m_btNo != NULL)
	{
		m_ContinueText->SetFont(text_font);
		m_btYes->SetFont(button_font);
		m_btNo->SetFont(button_font);
	}
}

void CContinueDlg::SetText()
{
	CString strContinueText = L"Quý khách có muốn thực hiện giao dịch khác?";
	m_ContinueText.SetWindowTextW(strContinueText);

	CString strYes = L"Có";
	m_btYes.SetWindowTextW(strYes);

	CString strNo = L"Không";
	m_btNo.SetWindowTextW(strNo);

	SetFontSize();
}

void CContinueDlg::LayoutControl()
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

	m_ContinueText.MoveWindow(
		(dlgW - WIDTH_TEXT) / 2, rect.top + (HEIGHT_TEXT / 2),
		WIDTH_TEXT, HEIGHT_TEXT
	);

	m_btNo.MoveWindow(
		X_BUT_NO, Y_BUT_NO,
		W_BUTTON, H_BUTTON
	);
	
	m_btYes.MoveWindow(
		X_BUT_YES, Y_BUT_YES,
		W_BUTTON, H_BUTTON
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

