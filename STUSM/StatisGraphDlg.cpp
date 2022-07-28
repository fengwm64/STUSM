// StatisGraphDlg.cpp: 实现文件
//
#include "stdafx.h"
#include "STUSM.h"
#include "afxdialogex.h"
#include "StatisGraphDlg.h"


// StatisGraphDlg 对话框

IMPLEMENT_DYNAMIC(StatisGraphDlg, CDialogEx)

StatisGraphDlg::StatisGraphDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_StatisGraph, pParent)
{

}

StatisGraphDlg::~StatisGraphDlg()
{
}

void StatisGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StatisGraphDlg, CDialogEx)
END_MESSAGE_MAP()


// StatisGraphDlg 消息处理程序
