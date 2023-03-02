#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <cstring>
#include "afxdialogex.h"
#include "Management.h"
#include "Student.h"

// MainDlg 对话框

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = NULL);
	virtual ~MainDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Main };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonAll();
	afx_msg void OnBnClickedButtonOthers();
	afx_msg void OnBnClickedMfcbuttonAdd();
	afx_msg void OnBnClickedRadiomaths();
	afx_msg void OnBnClickedRadioCpp();
	afx_msg void OnBnClickedRadioSexman();
	afx_msg void OnBnClickedRadioSexwoman();
	afx_msg void OnBnClickedRadioGra1();
	afx_msg void OnBnClickedRadioGra2();
	afx_msg void OnBnClickedRadioGra3();
	afx_msg void OnBnClickedRadioGra4();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonSort();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonStatisgraph();
	afx_msg void OnNMDblclkListShow(NMHDR* pNMHDR, LRESULT* pResult);

	CListCtrl m_List;		// 显示学生详细成绩的列表
	CString m_STU;		// 当前已添加的学生人数
	CString m_Num;		//	绑定学号输入框的变量
	CString m_Name;		// 绑定姓名输入框的变量
	CString m_Class;		// 绑定班级输入框的变量
	CString m_Gra;			//	年级
	CString m_Sex;			//	性别
	CString m_MathsD;	// 绑定高数平时成绩输入框的变量
	CString m_MathsT;	// 绑定高数考试成绩输入框的变量
	CString m_CppD;		//	绑定CPP平时成绩输入框的变量
	CString m_CppT;		//	绑定CPP考试成绩输入框的变量

	int m_Row;				//	list contorl控件的行号
	int m_Sort;				//	用于判断按下“排序”按钮时执行什么排序
	int SortID;					//	用于判断当前列表状态（正常/按高数/按CPP）

	double m_Aver;		//	平均值
	double m_Median;	//	中位数
	double m_Range;		//	极差
	double m_Variance;	//	方差

	Management ManagerSystem;		//	管理系统的对象
	Student temp;			//	Student类型的临时对象
	CString m_temp;		//	cstring类型的临时变量 主要用于承接 转换数据类型等等
};
