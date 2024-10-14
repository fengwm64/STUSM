#pragma once
#include "afxdialogex.h"


// StatisGraphDlg 对话框

class StatisGraphDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StatisGraphDlg)

public:
	StatisGraphDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StatisGraphDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_StatisGraph };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
