#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <cstring>
#include "afxdialogex.h"
#include "Management.h"
#include "Student.h"

// MainDlg �Ի���

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = NULL);
	virtual ~MainDlg();

// �Ի�������
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

	CListCtrl m_List;		// ��ʾѧ����ϸ�ɼ����б�
	CString m_STU;		// ��ǰ����ӵ�ѧ������
	CString m_Num;		//	��ѧ�������ı���
	CString m_Name;	// �����������ı���
	CString m_Class;		// �󶨰༶�����ı���
	CString m_Gra;		//	�꼶
	CString m_Sex;			//	�Ա�
	CString m_MathsD;	// �󶨸���ƽʱ�ɼ������ı���
	CString m_MathsT;	// �󶨸������Գɼ������ı���
	CString m_CppD;		//	��CPPƽʱ�ɼ������ı���
	CString m_CppT;		//	��CPP���Գɼ������ı���

	int m_Row;				//	list contorl�ؼ����к�
	int m_Sort;				//	�����жϰ��¡����򡱰�ťʱִ��ʲô����
	int SortID;				//	�����жϵ�ǰ�б�״̬������/������/��CPP��

	double m_Aver;		//	ƽ��ֵ
	double m_Median;	//	��λ��
	double m_Range;	//	����
	double m_Variance;	//	����

	Management ManagerSystem;		//	����ϵͳ�Ķ���
	Student temp;									//	Student���͵���ʱ����
	CString m_temp;								//	cstring���͵���ʱ���� ��Ҫ���ڳн� ת���������͵ȵ�
};
