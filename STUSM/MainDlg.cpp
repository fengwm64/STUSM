// MainDlg.cpp : 实现文件

#include "stdafx.h"
#include "STUSM.h"
#include "MainDlg.h"
#include "afxdialogex.h"


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
	m_Row = -1;
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
	ON_BN_CLICKED(IDC_RADIO_maths, &MainDlg::OnBnClickedRadiomaths)
	ON_BN_CLICKED(IDC_RADIO_CPP, &MainDlg::OnBnClickedRadioCpp)
	ON_BN_CLICKED(IDC_BUTTON_Edit, &MainDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_Delete, &MainDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_Sort, &MainDlg::OnBnClickedButtonSort)
	ON_BN_CLICKED(IDC_BUTTON_Save, &MainDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_Open, &MainDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_StatisGraph, &MainDlg::OnBnClickedButtonStatisgraph)
	ON_BN_CLICKED(IDC_RADIO_SexMan, &MainDlg::OnBnClickedRadioSexman)
	ON_BN_CLICKED(IDC_RADIO_SexWoman, &MainDlg::OnBnClickedRadioSexwoman)
	ON_BN_CLICKED(IDC_RADIO_Gra1, &MainDlg::OnBnClickedRadioGra1)
	ON_BN_CLICKED(IDC_RADIO_Gra2, &MainDlg::OnBnClickedRadioGra2)
	ON_BN_CLICKED(IDC_RADIO_Gra3, &MainDlg::OnBnClickedRadioGra3)
	ON_BN_CLICKED(IDC_RADIO_Gra4, &MainDlg::OnBnClickedRadioGra4)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_Show, &MainDlg::OnNMDblclkListShow)
END_MESSAGE_MAP()


// -------------------------------------	MainDlg 消息处理程序 ----------------------------------------

//	初始化窗口
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
	m_STU.Format(_T("%d"), m_List.GetItemCount());
	SetDlgItemText(IDC_EDIT_STU, m_STU);

	return TRUE;	// return TRUE unless you set the focus to a control
						// 异常:  OCX 属性页应返回 FALSE
}

//	关闭窗口
void MainDlg::OnClose()
{	

	//------------实现子窗口关闭时将父窗口关闭------------
	CDialog*pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	//----------------------------------------------------

	CDialogEx::OnClose();
}

//	重绘窗口（添加背景）
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
	CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//调用函数显示图片StretchBlt显示形状可变
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
}


// ----------------------------------------- 控件处理程序 ----------------------------------------------

//	“性别”单选框
void MainDlg::OnBnClickedRadioSexman()
{
	m_Sex = _T("男");
}
void MainDlg::OnBnClickedRadioSexwoman()
{
	m_Sex = _T("女");
}


//	“年级”单选框
void MainDlg::OnBnClickedRadioGra1()
{
	m_Gra = _T("大一");
}
void MainDlg::OnBnClickedRadioGra2()
{
	m_Gra = _T("大二");
}
void MainDlg::OnBnClickedRadioGra3()
{
	m_Gra = _T("大三");
}
void MainDlg::OnBnClickedRadioGra4()
{
	m_Gra = _T("大四");
}


//	“排序”单选框
void MainDlg::OnBnClickedRadiomaths()
{
	m_Sort = 0;
}
void MainDlg::OnBnClickedRadioCpp()
{
	m_Sort = 1;
}


//	点击“全选”按钮
void MainDlg::OnBnClickedButtonAll()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, TRUE);
}

//	点击“反选”按钮
void MainDlg::OnBnClickedButtonOthers()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, !m_List.GetCheck(i));
}

//	点击“添加”按钮
void MainDlg::OnBnClickedMfcbuttonAdd()
{
	//	从编辑框获取数据
	UpdateData(TRUE);
	double maths =0.4* _tcstod(m_MathsD, NULL) + 0.6*_tcstod(m_MathsT, NULL);
	double cpp =0.4* _tcstod(m_CppD, NULL) + 0.6*_tcstod(m_CppT, NULL);
	
	//	判断是否获取了空数据
	if (!(m_Name && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT && m_Gra && m_Sex))
	{
		MessageBox(_T("数据不能为空！请检查输入"), _T("提示"), MB_ICONWARNING);
		return;
	}

	//	创建临时Student对象添加进系统
	Student temp;
	CString m_temp;

	temp.Num = m_Num;
	temp.Grade = m_Gra;
	temp.Name = m_Name;
	temp.Sex = m_Sex;
	temp.Class = m_Class;

	temp.mathsD = m_MathsD;
	temp.mathsT = m_MathsT;
	temp.maths = maths;

	temp.CPPD = m_CppD;
	temp.CPPT = m_CppT;
	temp.CPP = cpp;

	//将数据检查合理性后放进Managerment的对象ManagerSystem内
	if (ManagerSystem.Iscorrect(temp))
	{
		//在容器内添加数据
		ManagerSystem.AddData(temp);

		//在界面列表控件中添加数据
		int nCount = m_List.GetItemCount();
		m_List.InsertItem(nCount, m_Num);
		m_List.SetItemText(nCount, 1, m_Gra);
		m_List.SetItemText(nCount, 2, m_Class);
		m_List.SetItemText(nCount, 3, m_Name);
		m_List.SetItemText(nCount, 4, m_Sex);

		//将浮点型转为cstring型
		m_temp.Format(_T("%.1f"), maths);
		m_List.SetItemText(nCount, 5, m_temp);
		m_temp.Format(_T("%.1f"), cpp);
		m_List.SetItemText(nCount, 6, m_temp);

		//更新学生人数
		m_STU.Format("%d", nCount+1);
		SetDlgItemText(IDC_EDIT_STU, m_STU);
	}
	else
		MessageBox(_T("学号雷同或成绩输入错误！请检查输入"), _T("提示"), MB_ICONWARNING);
}

//	点击"编辑"按钮
void MainDlg::OnBnClickedButtonEdit()
{
	//	寻找被选中的行号 循环直到找到被勾选项
	for (m_Row = 0; m_Row < m_List.GetItemCount(); m_Row++)
	{
		if (m_List.GetCheck(m_Row))
			break;
	}

	//	如果i=行数 说明用户没有勾选
	if (m_Row == m_List.GetItemCount())
	{
		MessageBox(_T("请勾选一行！"), _T("提示"), MB_ICONWARNING);
		return;
	}

	//	从编辑框获取数据
	UpdateData(TRUE);
	double maths = 0.4 * _tcstod(m_MathsD, NULL) + 0.6 * _tcstod(m_MathsT, NULL);
	double cpp = 0.4 * _tcstod(m_CppD, NULL) + 0.6 * _tcstod(m_CppT, NULL);

	//	判断是否有空数据
	if (!(m_Name && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT && m_Gra && m_Sex))
	{
		MessageBox(_T("有数据为空！请检查输入"), _T("提示"), MB_ICONWARNING);
		return;
	}

	//	获取数据放入临时对象
	temp.Num = m_Num;
	temp.Grade = m_Gra;
	temp.Name = m_Name;
	temp.Sex = m_Sex;
	temp.Class = m_Class;
	temp.CPP = cpp;
	temp.maths = maths;

	//	检查编辑后数据合理性
	if (!(ManagerSystem.Iscorrect(temp)))
	{
		MessageBox(_T("学号雷同或成绩输入错误！请检查输入"), _T("提示"), MB_ICONWARNING);
		return;
	}
	
	//	利用管理系统的函数编辑容器
	ManagerSystem.EditData(temp, m_Row);
	
	//	将控件原来行删除并插入修改后的行
	m_List.DeleteItem(m_Row);
	m_List.InsertItem(m_Row, m_Num);
	m_List.SetItemText(m_Row, 1, m_Gra);
	m_List.SetItemText(m_Row, 2, m_Class);
	m_List.SetItemText(m_Row, 3, m_Name);
	m_List.SetItemText(m_Row, 4, m_Sex);
	//	将浮点型转为cstring型
	m_temp.Format(_T("%.1f"), maths);
	m_List.SetItemText(m_Row, 5, m_temp);
	m_temp.Format(_T("%.1f"), cpp);
	m_List.SetItemText(m_Row, 6, m_temp);
}

//	点击"删除"按钮
void MainDlg::OnBnClickedButtonDelete()
{
	//	利用循环逐个找到选中的行进行删除
	for (m_Row = 0; m_Row < m_List.GetItemCount(); m_Row++)
	{
		if (m_List.GetCheck(m_Row))
		{
			ManagerSystem.DeleteData(m_Row);
			m_List.DeleteItem(m_Row);
			m_Row--;
		}
	}

	//	更新学生人数
	int nCount = m_List.GetItemCount();
	m_STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, m_STU);
}

//	点击"排序"按钮
void MainDlg::OnBnClickedButtonSort()
{
	//	删除list control全部项目
	m_List.DeleteAllItems();

	//	获取当前列表总行数
	int nCount = ManagerSystem.GetCount();

	//	根据m_Sort执行不同的排序分支
	switch (m_Sort)
	{
	case 0:
		ManagerSystem.SortDataM();
		
		//	将排序后的数据输出到列表中
		for (m_Row = 0; m_Row < nCount; m_Row++)
		{
			m_List.InsertItem(m_Row, ManagerSystem.SortM[m_Row].Num);
			m_List.SetItemText(m_Row, 1, ManagerSystem.SortM[m_Row].Grade);
			m_List.SetItemText(m_Row, 2, ManagerSystem.SortM[m_Row].Class);
			m_List.SetItemText(m_Row, 3, ManagerSystem.SortM[m_Row].Name);
			m_List.SetItemText(m_Row, 4, ManagerSystem.SortM[m_Row].Sex);
			m_temp.Format(_T("%.1f"), ManagerSystem.SortM[m_Row].maths);
			m_List.SetItemText(m_Row, 5, m_temp);
			m_temp.Format(_T("%.1f"), ManagerSystem.SortM[m_Row].CPP);
			m_List.SetItemText(m_Row, 6, m_temp);
		}

	case 1:
		ManagerSystem.SortDataC();

		//	将排序后的数据输出到列表中
		for (m_Row = 0; m_Row < nCount; m_Row++)
		{
			m_List.InsertItem(m_Row, ManagerSystem.SortC[m_Row].Num);
			m_List.SetItemText(m_Row, 1, ManagerSystem.SortC[m_Row].Grade);
			m_List.SetItemText(m_Row, 2, ManagerSystem.SortC[m_Row].Class);
			m_List.SetItemText(m_Row, 3, ManagerSystem.SortC[m_Row].Name);
			m_List.SetItemText(m_Row, 4, ManagerSystem.SortC[m_Row].Sex);
			m_temp.Format(_T("%.1f"), ManagerSystem.SortC[m_Row].maths);
			m_List.SetItemText(m_Row, 5, m_temp);
			m_temp.Format(_T("%.1f"), ManagerSystem.SortC[m_Row].CPP);
			m_List.SetItemText(m_Row, 6, m_temp);
		}

	default:
		break;
	}

	//	更新学生人数
	m_STU.Format(_T("%d"), m_List.GetItemCount());
	SetDlgItemText(IDC_EDIT_STU, m_STU);
}

//	点击"保存"按钮
void MainDlg::OnBnClickedButtonSave()
{
	//	设置保存文件对话框的信息
	CFileDialog fDlg(FALSE, ".dat", "save", OFN_OVERWRITEPROMPT, "数据文件(*.dat)|*.dat", NULL);

	if (fDlg.DoModal()==IDOK)
	{
		//	获取文件路径
		CString sPath = fDlg.GetPathName();

		//	创建文件对象
		CStdioFile file(sPath, CFile::modeWrite | CFile::modeCreate);

		//	利用for循环将记录写入文件
		for (m_Row = 0; m_Row < m_List.GetItemCount(); m_Row++)
		{
			//	将每列的数据拼接成一行字符串
			m_temp = '\0';
			m_temp += m_List.GetItemText(m_Row, 0) + "#";
			m_temp += m_List.GetItemText(m_Row, 1) + "#";
			m_temp += m_List.GetItemText(m_Row, 2) + "#";
			m_temp += m_List.GetItemText(m_Row, 3) + "#";
			m_temp += m_List.GetItemText(m_Row, 4) + "#";
			m_temp += m_List.GetItemText(m_Row, 5) + "#";
			m_temp += m_List.GetItemText(m_Row, 6) + "#\n";

			//	向文件写入一行记录
			file.WriteString(m_temp);
		}

		//	写入完毕 关闭写入
		file.Close();
	}
	
}

//	点击"打开"按钮
void MainDlg::OnBnClickedButtonOpen()
{
	CFileDialog fDlg(TRUE, ".dat", "save", OFN_OVERWRITEPROMPT, "数据文件(*.dat)|*.dat", NULL);
	if (fDlg.DoModal() == IDOK)
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeRead);
		CString m_temp;
		CString m_Name, m_Num, m_Class, m_temp, T_maths, T_cpp;
		Student Stemp;
		m_Row = 0;
		while (file.ReadString(m_temp))
		{

			int x = m_temp.Find("#");
			int x2 = m_temp.Find("#", x + 1);
			int x3 = m_temp.Find("#", x2 + 1);
			int x4 = m_temp.Find("#", x3 + 1);
			int x5 = m_temp.Find("#", x4 + 1);
			int x6 = m_temp.Find("#", x5 + 1);
			int x7 = m_temp.Find("#", x6 + 1);

			Stemp.Num = m_temp.Left(x);
			Stemp.Grade = m_temp.Mid(x + 1, x2 - x - 1);
			Stemp.Class = m_temp.Mid(x2 + 1, x3 - x2 - 1);
			Stemp.Name = m_temp.Mid(x3 + 1, x4 - x3 - 1);
			Stemp.Sex = m_temp.Mid(x4 + 1, x5 - x4 - 1);
			Stemp.maths = _tcstod(m_temp.Mid(x5 + 1, x4 - x3 - 1), NULL);
			Stemp.CPP = _tcstod(m_temp.Mid(x6 + 1, x7 - x6 - 1), NULL);
			ManagerSystem.AddData(Stemp);

			m_List.InsertItem(m_Row, Stemp.Num);
			m_List.SetItemText(m_Row, 1, Stemp.Grade);
			m_List.SetItemText(m_Row, 2, Stemp.Class);
			m_List.SetItemText(m_Row, 3, Stemp.Name);
			m_List.SetItemText(m_Row, 4, Stemp.Sex);
			CString Format_Gra;
			Format_Gra.Format("%.1f", Stemp.maths);
			m_List.SetItemText(m_Row, 5, Format_Gra);
			Format_Gra.Format("%.1f", Stemp.CPP);
			m_List.SetItemText(m_Row, 6, Format_Gra);

			m_Row++;
		}
		
	}

	//更新学生人数
	int nCount = m_List.GetItemCount();
	m_STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, m_STU);
}

//	点击"绘图"按钮
void MainDlg::OnBnClickedButtonStatisgraph()
{
	// TODO: 在此添加控件通知处理程序代码
}

//	双击list control的响应事件（将该学生的信息设置到输入框方便进行修改）
void MainDlg::OnNMDblclkListShow(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	//	首先得到点击的位置
	POSITION pos = m_List.GetFirstSelectedItemPosition();

	if (pos == NULL)
	{
		MessageBox("请至少选择一项", "提示", MB_ICONEXCLAMATION);
		return;
	}

	//	得到行号，通过POSITION转化
	m_Row = (int)m_List.GetNextSelectedItem(pos);

	//	将该行的多选框勾上
	m_List.SetCheck(m_Row, TRUE);

	//	获取该位置学生的信息
	switch (SortID)
	{
	case 0:
		temp = ManagerSystem.Pstu[m_Row];
		break;
	case 1:
		temp = ManagerSystem.SortM[m_Row];
		break;
	case 2:
		temp = ManagerSystem.SortC[m_Row];
		break;
	default:
		MessageBox("WTF????	How dare are you！");
		break;
	}

	//	设置到输入框
	SetDlgItemText(IDC_EDIT_Name, temp.Name);
	SetDlgItemText(IDC_EDIT_Num, temp.Num);
	SetDlgItemText(IDC_EDIT_Class, temp.Class);

	CButton* Cwnd_radio_temp;
	//	设置性别单选框
	if (m_Sex == "男")
	{
		//	获取单选框男的指针
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_SexMan);
		Cwnd_radio_temp->SetCheck(TRUE);
	}
	else
	{
		//	获取单选框女的指针
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_SexWoman);
		Cwnd_radio_temp->SetCheck(TRUE);
	}

	//	设置年级单选框
	if (m_Gra == "大一")
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra1);
	if (m_Gra == "大二")
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra2);
	if (m_Gra == "大三")
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra3);
	else
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra4);
	Cwnd_radio_temp->SetCheck(TRUE);

	SetDlgItemText(IDC_EDIT_Mathsd, temp.mathsD);
	SetDlgItemText(IDC_EDIT_Mathst, temp.mathsT);
	SetDlgItemText(IDC_EDIT_Cppd, temp.CPPD);
	SetDlgItemText(IDC_EDIT_Cppt, temp.CPPT);

	*pResult = 0;
}