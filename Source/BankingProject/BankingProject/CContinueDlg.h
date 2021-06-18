#pragma once


// CContinueDlg dialog

class CContinueDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CContinueDlg)

public:
	CContinueDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CContinueDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CONTINUE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CStatic m_ContinueText;
	CButton m_btYes;
	CButton m_btNo;
public:
	BOOL OnInitDialog();
	void LayoutControl();
	void SetFontSize();
	void SetText();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
