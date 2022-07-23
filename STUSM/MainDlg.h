#pragma once
#include "afxcmn.h"
#include "afxwin.h"

// MainDlg 对话框

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Main };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	// 这里是显示学生详细成绩的列表
	CListCtrl m_List;
	afx_msg void OnBnClickedButtonAll();
	afx_msg void OnBnClickedButtonOthers();
	afx_msg void OnBnClickedMfcbuttonAdd();
	afx_msg void OnPaint();
	// 年级
	afx_msg void OnBnClickedRadioGra1();
	afx_msg void OnBnClickedRadioGra2();
	afx_msg void OnBnClickedRadioGra3();
	afx_msg void OnBnClickedRadioGra4();
	CButton m_Radio1;
	afx_msg void OnBnClickedRadiomaths();
	afx_msg void OnBnClickedRadioCpp();
	afx_msg void OnBnClickedRadioMan();
	afx_msg void OnBnClickedRadioWoman();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonSort();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonOpen();
};
