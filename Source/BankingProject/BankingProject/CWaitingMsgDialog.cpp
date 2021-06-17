// CWaitingMsgDialog.cpp : implementation file
//

#include "pch.h"
#include "BankingProject.h"
#include "CWaitingMsgDialog.h"
#include "afxdialogex.h"
#include "BankingDefine.h"
#include <wchar.h>

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

	// set timer hiển thị cho dialog
	SetTimer(ID_WAITING_DLG, WAITING_TIMER, NULL);

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


void CWaitingMsgDialog::LayoutControl()
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

	// Move text to position (x,y)
	m_staticText.MoveWindow(
		(dlgW - WIDTH_TEXT) / 2, (dlgH - HEIGHT_TEXT) / 2,
		WIDTH_TEXT, HEIGHT_TEXT
	);

	// ?! Chưa vertical align được

	//Resize
	// dynamic scale
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

void CWaitingMsgDialog::SetText()
{
	CString strText = L"Đang thực hiện giao dịch ...\r\nVui lòng chờ";
	m_staticText.SetWindowTextW(strText);
}

void CWaitingMsgDialog::SetFontSize()
{
	int fontHeight = 40;
	CFont *font = new CFont();
	LOGFONT logfont;
	memset(&logfont, 0, sizeof(LOGFONT));		// Clear out structure.
	logfont.lfHeight = fontHeight;				// Request a 20-pixel-high font
	
#pragma warning(suppress : 4996)
	wcscpy(logfont.lfFaceName, L"Arial");	// with face name "Arial".
	
	font->CreateFontIndirect(&logfont);			// Create the font.

	CWnd *m_staticText = GetDlgItem(IDC_WAITING_TEXT);
	if (m_staticText != NULL)
		m_staticText->SetFont(font);
}

