#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <cstring>
#include "afxdialogex.h"


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
	
	afx_msg void OnBnClickedButtonAll();
	afx_msg void OnBnClickedButtonOthers();
	afx_msg void OnBnClickedMfcbuttonAdd();
	afx_msg void OnPaint();

	// 年级
	afx_msg void OnBnClickedRadioGra1();
	afx_msg void OnBnClickedRadioGra2();
	afx_msg void OnBnClickedRadioGra3();
	afx_msg void OnBnClickedRadioGra4();

	afx_msg void OnBnClickedRadiomaths();
	afx_msg void OnBnClickedRadioCpp();
	afx_msg void OnBnClickedRadioMan();
	afx_msg void OnBnClickedRadioWoman();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonSort();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonStatisgraph();

	CListCtrl m_List;	// 显示学生详细成绩的列表

	CString m_STU;	// 当前已添加的学生人数

	CString m_Num;	//	绑定学号输入框的变量

	CString m_Name;	// 绑定姓名输入框的变量

	CString m_Class;	// 绑定班级输入框的变量

	CString m_Gra;		//	年级

	CString m_Sex;		//	性别

	CString m_MathsD;	// 绑定高数平时成绩输入框的变量
	CString m_MathsT;	// 绑定高数考试成绩输入框的变量

	CString m_CppD;		//	绑定CPP平时成绩输入框的变量
	CString m_CppT;		//	绑定CPP考试成绩输入框的变量
};
