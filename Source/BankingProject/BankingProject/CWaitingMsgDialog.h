#pragma once


// CWaitingMsgDialog dialog

class CWaitingMsgDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CWaitingMsgDialog)

public:
	CWaitingMsgDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CWaitingMsgDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MSG_WAITING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CStatic m_staticText;
public:
	BOOL OnInitDialog();
	void LayoutControl();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void SetText();
	void SetFontSize();
};
