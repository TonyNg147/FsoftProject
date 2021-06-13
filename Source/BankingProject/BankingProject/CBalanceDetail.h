#pragma once


// CBalanceDetail dialog

class CBalanceDetail : public CDialogEx
{
	DECLARE_DYNAMIC(CBalanceDetail)

public:
	CBalanceDetail(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBalanceDetail();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BALANCE_DETAIL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;    //edit
	//edit
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//edit
	DECLARE_MESSAGE_MAP()
private:
	CStatic m_balanceDetailTextHeader;
	CStatic m_balanceDetailMoneyText;
	CStatic m_balanceDetailMoneyValue;
	CStatic m_balanceDetailTransactionFeeText;
	CStatic m_balanceDetailTransactionFeeValue;
	CStatic m_balanceDetailVatText;
	CStatic m_balanceDetailVatValue;
	CStatic m_balanceDetailBillQuestionText;
	CButton m_balanceDetailBillAnswerYes;
	CButton m_balanceDetailBillAnswerNo;
public:
	void LayoutControl();
};

