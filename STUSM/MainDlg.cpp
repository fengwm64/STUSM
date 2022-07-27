// MainDlg.cpp : 实现文件

#include "stdafx.h"
#include "STUSM.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "Student.h"
#include "Management.h"

//声明全局变量
Management ManagerSystem;
CString STU = _T("0");
CString m_MathsD, m_MathsT;
CString m_CppD, m_CppT;

// MainDlg 对话框

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainDlg::IDD, pParent)
	, m_Num(_T(""))
	, m_Name(_T(""))
	, m_Class(_T(""))
	, m_MathsD(_T(""))
	, m_MathsT(_T(""))
	, m_CppD(_T(""))
	, m_CppT(_T(""))
	, m_STU(_T(""))
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Show, m_List);

	DDX_Text(pDX, IDC_EDIT_Num, m_Num);
	DDX_Text(pDX, IDC_EDIT_Name, m_Name);
	DDX_Text(pDX, IDC_EDIT_Class, m_Class);
	DDX_Text(pDX, IDC_EDIT_Mathsd, m_MathsD);
	DDX_Text(pDX, IDC_EDIT_Mathst, m_MathsT);
	DDX_Text(pDX, IDC_EDIT_Cppd, m_CppD);
	DDX_Text(pDX, IDC_EDIT_Cppt, m_CppT);
	DDX_Text(pDX, IDC_EDIT_STU, m_STU);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_ALL, &MainDlg::OnBnClickedButtonAll)
	ON_BN_CLICKED(IDC_BUTTON_Others, &MainDlg::OnBnClickedButtonOthers)
	ON_BN_CLICKED(IDC_MFCBUTTON_Add, &MainDlg::OnBnClickedMfcbuttonAdd)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_Gra1, &MainDlg::OnBnClickedRadioGra1)
	ON_BN_CLICKED(IDC_RADIO_Gra2, &MainDlg::OnBnClickedRadioGra2)
	ON_BN_CLICKED(IDC_RADIO_Gra3, &MainDlg::OnBnClickedRadioGra3)
	ON_BN_CLICKED(IDC_RADIO_Gra4, &MainDlg::OnBnClickedRadioGra4)
	ON_BN_CLICKED(IDC_RADIO_maths, &MainDlg::OnBnClickedRadiomaths)
	ON_BN_CLICKED(IDC_RADIO_CPP, &MainDlg::OnBnClickedRadioCpp)
	ON_BN_CLICKED(IDC_RADIO_Man, &MainDlg::OnBnClickedRadioMan)
	ON_BN_CLICKED(IDC_RADIO_Woman, &MainDlg::OnBnClickedRadioWoman)
	ON_BN_CLICKED(IDC_BUTTON_Edit, &MainDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_Delete, &MainDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_Sort, &MainDlg::OnBnClickedButtonSort)
	ON_BN_CLICKED(IDC_BUTTON_Save, &MainDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_Open, &MainDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_StatisGraph, &MainDlg::OnBnClickedButtonStatisgraph)
END_MESSAGE_MAP()


// MainDlg 消息处理程序


void MainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);    //获取对话框长宽      
	CDC   dcBmp;             //定义并创建一个内存设备环境
	dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_mainbg);    //载入资源中图片
	BITMAP   m_bitmap;                         //图片变量               
	bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
	//将位图选入临时内存设备环境
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//调用函数显示图片StretchBlt显示形状可变
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
}


void MainDlg::OnClose()
{	

	//------------实现子窗口关闭时将父窗口关闭------------
	CDialog*pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	//----------------------------------------------------

	CDialogEx::OnClose();
}


BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//----------------------设置窗口标题-------------------------
	CString Title = _T("STUSM 学生成绩管理系统-当前用户：计科212 冯韦铭 32116160100");
	SetWindowText(Title);

	//---------------------列表(表头)初始化-----------------------
	m_List.InsertColumn(0, _T("学号"), LVCFMT_CENTER, 150);
	m_List.InsertColumn(1, _T("年级"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(2, _T("班级"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(3, _T("姓名"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(4, _T("性别"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(5, _T("高等数学"), LVCFMT_CENTER, 100);
	m_List.InsertColumn(6, _T("面向对象程序设计"), LVCFMT_CENTER, 135);

	//-------------------------------------------------------------
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	SetDlgItemText(IDC_EDIT_STU, STU);

	////-----------------------创建测试数据--------------------------
	//CString num = _T("321161601");
	//CString nj = _T("大一");
	//CString sex = _T("男");	
	//CString classna = _T("计科212");
	//CString name = _T("冯韦铭");
	//CString math = _T("100");
	//CString cpp = _T("100");

	//for (int i = 0; i < 20; i++)
	//{
	//	num.Format(_T("3211616010%d"), i);
	//	m_List.InsertItem(i, num);
	//	m_List.SetItemText(i, 1, nj);
	//	m_List.SetItemText(i, 2, classna);
	//	m_List.SetItemText(i, 3, name);
	//	m_List.SetItemText(i, 4, sex);
	//	m_List.SetItemText(i, 5, math);
	//	m_List.SetItemText(i, 6, cpp);
	//}
	
	//更新学生人数
	STU.Format(_T("%d"),m_List.GetItemCount());
	SetDlgItemText(IDC_EDIT_STU, STU);

	return TRUE;	// return TRUE unless you set the focus to a control
						// 异常:  OCX 属性页应返回 FALSE
}

//点击“全选”按钮
void MainDlg::OnBnClickedButtonAll()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, TRUE);
}

//点击“反选”按钮
void MainDlg::OnBnClickedButtonOthers()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, !m_List.GetCheck(i));
}


CString T_G;//表示年级
void MainDlg::OnBnClickedRadioGra1()
{
	// TODO:  在此添加控件通知处理程序代码
	T_G = _T("大一");
}
void MainDlg::OnBnClickedRadioGra2()
{
	// TODO:  在此添加控件通知处理程序代码
		T_G = _T("大二");
}
void MainDlg::OnBnClickedRadioGra3()
{
	// TODO:  在此添加控件通知处理程序代码
	T_G = _T("大三");
}
void MainDlg::OnBnClickedRadioGra4()
{
	// TODO:  在此添加控件通知处理程序代码
	T_G = _T("大四");
}


CString T_sex;
void MainDlg::OnBnClickedRadioMan()
{
	// TODO:  在此添加控件通知处理程序代码
	T_sex = _T("男");
}
void MainDlg::OnBnClickedRadioWoman()
{
	// TODO:  在此添加控件通知处理程序代码
	T_sex = _T("女");
}


void MainDlg::OnBnClickedMfcbuttonAdd()///点击“添加”按钮
{
	Student temp;
	CString T_temp;

	//--------------从编辑框获取数据------------------
	UpdateData(TRUE);
	double maths =0.4* _tcstod(m_MathsD, NULL) + 0.6*_tcstod(m_MathsT, NULL);
	double cpp =0.4* _tcstod(m_CppD, NULL) + 0.6*_tcstod(m_CppT, NULL);


	//-------------判断是否获取了空数据---------------
	if (m_Name && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT)
	{
		MessageBox(_T("数据不能为空！请检查输入"), _T("提示"), MB_ICONWARNING);
		return;
	}

	temp.Num = m_Num;
	temp.Grade = T_G;
	temp.Name = m_Name;
	temp.Sex = T_sex;
	temp.Class = m_Class;
	temp.CPP = cpp;
	temp.maths = maths;

	//将数据检查合理性后放进Managerment的对象ManagerSystem内
	if (ManagerSystem.Iscorrect(temp))
	{
		//在容器内添加数据
		ManagerSystem.AddData(temp);
		int nCount = m_List.GetItemCount();

		//在界面列表控件中添加数据
		m_List.InsertItem(nCount, m_Num);
		m_List.SetItemText(nCount, 1, T_G);
		m_List.SetItemText(nCount, 2, m_Class);
		m_List.SetItemText(nCount, 3, m_Name);
		m_List.SetItemText(nCount, 4, T_sex);
		//将浮点型转为cstring型
		T_temp.Format(_T("%.1f"), maths);
		m_List.SetItemText(nCount, 5, T_temp);
		T_temp.Format(_T("%.1f"), cpp);
		m_List.SetItemText(nCount, 6, T_temp);

		//更新学生人数
		STU.Format("%d", nCount+1);
		SetDlgItemText(IDC_EDIT_STU, STU);
	}
	else
	{
		MessageBox(_T("学号雷同或成绩输入错误！请检查输入"), _T("提示"), MB_ICONWARNING);
	}
}

void MainDlg::OnBnClickedButtonEdit()//点击"编辑"按钮
{
	// TODO: 在此添加控件通知处理程序代码
	Student temp;
	int i;
	for (i = 0; i < m_List.GetItemCount(); i++)
	{
		if (m_List.GetCheck(i))
			break;
	}
	if (i == m_List.GetItemCount())
	{
		return;
	}
	CString m_Name, m_Num, m_Class, T_temp;
	//--------------从编辑框获取数据------------------
	GetDlgItemText(IDC_EDIT_Name, m_Name);
	GetDlgItemText(IDC_EDIT_Num, m_Num);
	GetDlgItemText(IDC_EDIT_Class, m_Class);

	GetDlgItemText(IDC_EDIT_Mathsd, m_MathsD);
	GetDlgItemText(IDC_EDIT_Mathst, m_MathsT);
	double maths = 0.4 * _tcstod(m_MathsD, NULL) + 0.6 * _tcstod(m_MathsT, NULL);

	GetDlgItemText(IDC_EDIT_Cppd, m_CppD);
	GetDlgItemText(IDC_EDIT_Cppt, m_CppT);
	double cpp = 0.4 * _tcstod(m_CppD, NULL) + 0.6 * _tcstod(m_CppT, NULL);

	//-------------判断是否获取了空数据---------------
	if (m_Name == "" && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT)
	{
		MessageBox(_T("数据不能为空！请检查输入"), _T("提示"), MB_ICONWARNING);
		return;
	}

	//获取数据放入对象
	temp.Num = m_Num;
	temp.Grade = T_G;
	temp.Name = m_Name;
	temp.Sex = T_sex;
	temp.Class = m_Class;
	temp.CPP = cpp;
	temp.maths = maths;

	ManagerSystem.EditData(temp, i);
	
	m_List.DeleteItem(i);
	m_List.InsertItem(i, m_Num);
	m_List.SetItemText(i, 1, T_G);
	m_List.SetItemText(i, 2, m_Class);
	m_List.SetItemText(i, 3, m_Name);
	m_List.SetItemText(i, 4, T_sex);
	//将浮点型转为cstring型
	T_temp.Format(_T("%.1f"), maths);
	m_List.SetItemText(i, 5, T_temp);
	T_temp.Format(_T("%.1f"), cpp);
	m_List.SetItemText(i, 6, T_temp);
}

void MainDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_List.GetItemCount(); i++)
	{
		if (m_List.GetCheck(i))
		{
			ManagerSystem.DeleteData(i);
			m_List.DeleteItem(i);
			i--;
		}
	}
	//更新学生人数
	int nCount = m_List.GetItemCount();
	STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, STU);
}

int s;
void MainDlg::OnBnClickedRadiomaths()
{
	// TODO:  在此添加控件通知处理程序代码
	s = 0;
}
void MainDlg::OnBnClickedRadioCpp()
{
	// TODO:  在此添加控件通知处理程序代码
	s = 1;
}

void MainDlg::OnBnClickedButtonSort()
{
	// TODO: 在此添加控件通知处理程序代码
	m_List.DeleteAllItems();
	int nCount = ManagerSystem.GetCount();
	CString temp;
	switch (s)
	{
	case 0:
		ManagerSystem.SortDataM();
		
		for (int i = 0; i < nCount; i++)
		{
			m_List.InsertItem(i, ManagerSystem.SortM[i].Num);
			m_List.SetItemText(i, 1, ManagerSystem.SortM[i].Grade);
			m_List.SetItemText(i, 2, ManagerSystem.SortM[i].Class);
			m_List.SetItemText(i, 3, ManagerSystem.SortM[i].Name);
			m_List.SetItemText(i, 4, ManagerSystem.SortM[i].Sex);
			temp.Format(_T("%.1f"), ManagerSystem.SortM[i].maths);
			m_List.SetItemText(i, 5, temp);
			temp.Format(_T("%.1f"), ManagerSystem.SortM[i].CPP);
			m_List.SetItemText(i, 6, temp);
		}
		//更新学生人数
		STU.Format(_T("%d"), m_List.GetItemCount());
		SetDlgItemText(IDC_EDIT_STU, STU);
		break;
	case 1:
		ManagerSystem.SortDataC();

		for (int i = 0; i < nCount; i++)
		{
			m_List.InsertItem(i, ManagerSystem.SortC[i].Num);
			m_List.SetItemText(i, 1, ManagerSystem.SortC[i].Grade);
			m_List.SetItemText(i, 2, ManagerSystem.SortC[i].Class);
			m_List.SetItemText(i, 3, ManagerSystem.SortC[i].Name);
			m_List.SetItemText(i, 4, ManagerSystem.SortC[i].Sex);
			temp.Format(_T("%.1f"), ManagerSystem.SortC[i].maths);
			m_List.SetItemText(i, 5, temp);
			temp.Format(_T("%.1f"), ManagerSystem.SortC[i].CPP);
			m_List.SetItemText(i, 6, temp);
		}
		//更新学生人数
		STU.Format(_T("%d"), m_List.GetItemCount());
		SetDlgItemText(IDC_EDIT_STU, STU);
		break;
	default:
		break;
	}
}

void MainDlg::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fDlg(FALSE, ".dat", "save", OFN_OVERWRITEPROMPT, "数据文件(*.dat)|*.dat", NULL);
	if (fDlg.DoModal()==IDOK)
	{
		CString sPath = fDlg.GetPathName();
		//创建文件对象
		CStdioFile file(sPath, CFile::modeWrite | CFile::modeCreate);
		CString temp;
		for (int i = 0; i < m_List.GetItemCount(); i++)
		{
			temp += m_List.GetItemText(i, 0) + "#";
			temp += m_List.GetItemText(i, 1) + "#";
			temp += m_List.GetItemText(i, 2) + "#";
			temp += m_List.GetItemText(i, 3) + "#";
			temp += m_List.GetItemText(i, 4) + "#";
			temp += m_List.GetItemText(i, 5) + "#";
			temp += m_List.GetItemText(i, 6) + "#\n";

			file.WriteString(temp);
		}

		file.Close();
	}
	
}

void MainDlg::OnBnClickedButtonOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fDlg(TRUE, ".dat", "save", OFN_OVERWRITEPROMPT, "数据文件(*.dat)|*.dat", NULL);
	if (fDlg.DoModal() == IDOK)
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeRead);
		CString temp;
		CString m_Name, m_Num, m_Class, T_temp, T_maths, T_cpp;
		Student Stemp;
		int i = 0;
		while (file.ReadString(temp))
		{

			int x = temp.Find("#");
			int x2 = temp.Find("#", x + 1);
			int x3 = temp.Find("#", x2 + 1);
			int x4 = temp.Find("#", x3 + 1);
			int x5 = temp.Find("#", x4 + 1);
			int x6 = temp.Find("#", x5 + 1);
			int x7 = temp.Find("#", x6 + 1);

			Stemp.Num = temp.Left(x);
			Stemp.Grade = temp.Mid(x + 1, x2 - x - 1);
			Stemp.Class = temp.Mid(x2 + 1, x3 - x2 - 1);
			Stemp.Name = temp.Mid(x3 + 1, x4 - x3 - 1);
			Stemp.Sex = temp.Mid(x4 + 1, x5 - x4 - 1);
			Stemp.maths = _tcstod(temp.Mid(x5 + 1, x4 - x3 - 1), NULL);
			Stemp.CPP = _tcstod(temp.Mid(x6 + 1, x7 - x6 - 1), NULL);
			ManagerSystem.AddData(Stemp);

			m_List.InsertItem(i, Stemp.Num);
			m_List.SetItemText(i, 1, Stemp.Grade);
			m_List.SetItemText(i, 2, Stemp.Class);
			m_List.SetItemText(i, 3, Stemp.Name);
			m_List.SetItemText(i, 4, Stemp.Sex);
			CString Format_Gra;
			Format_Gra.Format("%.1f", Stemp.maths);
			m_List.SetItemText(i, 5, Format_Gra);
			Format_Gra.Format("%.1f", Stemp.CPP);
			m_List.SetItemText(i, 6, Format_Gra);

			i++;
		}
		
	}

	//更新学生人数
	int nCount = m_List.GetItemCount();
	STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, STU);
}

void MainDlg::OnBnClickedButtonStatisgraph()
{
	// TODO: 在此添加控件通知处理程序代码
}
