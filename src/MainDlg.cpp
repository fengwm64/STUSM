// MainDlg.cpp : ʵ���ļ�

#include "stdafx.h"
#include "STUSM.h"
#include "MainDlg.h"
#include "StatisGraphDlg.h"
#include "afxdialogex.h"


// MainDlg �Ի���

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


// -------------------------------------	MainDlg ��Ϣ������� ----------------------------------------

//	��ʼ������
BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//----------------------���ô��ڱ���-------------------------
	CString Title = _T("STUSM ѧ���ɼ�����ϵͳ-��ǰ�û����ƿ�212 ��Τ�� 32116160100");
	SetWindowText(Title);

	//---------------------�б�(��ͷ)��ʼ��-----------------------
	m_List.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, 150);
	m_List.InsertColumn(1, _T("�꼶"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(2, _T("�༶"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(3, _T("����"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(4, _T("�Ա�"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(5, _T("�ߵ���ѧ"), LVCFMT_CENTER, 100);
	m_List.InsertColumn(6, _T("�������������"), LVCFMT_CENTER, 135);
	//-------------------------------------------------------------

	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	//	����ѧ������
	m_STU.Format(_T("%d"), m_List.GetItemCount());
	SetDlgItemText(IDC_EDIT_STU, m_STU);

	return TRUE;	// return TRUE unless you set the focus to a control
						// �쳣:  OCX ����ҳӦ���� FALSE
}

//	�رմ���
void MainDlg::OnClose()
{	

	//------------ʵ���Ӵ��ڹر�ʱ�������ڹر�------------
	CDialog*pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	//----------------------------------------------------

	CDialogEx::OnClose();
}

//	�ػ洰�ڣ���ӱ�����
void MainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);    //��ȡ�Ի��򳤿�      
	CDC   dcBmp;             //���岢����һ���ڴ��豸����
	dcBmp.CreateCompatibleDC(&dc);             //����������DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_mainbg);    //������Դ��ͼƬ
	BITMAP   m_bitmap;                         //ͼƬ����               
	bmpBackground.GetBitmap(&m_bitmap);       //��ͼƬ����λͼ��
	//��λͼѡ����ʱ�ڴ��豸����
	CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
}


// ----------------------------------------- �ؼ�������� ----------------------------------------------

//	���Ա𡱵�ѡ��
void MainDlg::OnBnClickedRadioSexman()
{
	m_Sex = _T("��");
}
void MainDlg::OnBnClickedRadioSexwoman()
{
	m_Sex = _T("Ů");
}


//	���꼶����ѡ��
void MainDlg::OnBnClickedRadioGra1()
{
	m_Gra = _T("��һ");
}
void MainDlg::OnBnClickedRadioGra2()
{
	m_Gra = _T("���");
}
void MainDlg::OnBnClickedRadioGra3()
{
	m_Gra = _T("����");
}
void MainDlg::OnBnClickedRadioGra4()
{
	m_Gra = _T("����");
}


//	�����򡱵�ѡ��
void MainDlg::OnBnClickedRadiomaths()
{
	m_Sort = 0;
}
void MainDlg::OnBnClickedRadioCpp()
{
	m_Sort = 1;
}


//	�����ȫѡ����ť
void MainDlg::OnBnClickedButtonAll()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, TRUE);
}

//	�������ѡ����ť
void MainDlg::OnBnClickedButtonOthers()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, !m_List.GetCheck(i));
}

//	�������ӡ���ť
void MainDlg::OnBnClickedMfcbuttonAdd()
{
	//	�ӱ༭���ȡ����
	UpdateData(TRUE);
	double maths =0.4* _tcstod(m_MathsD, NULL) + 0.6*_tcstod(m_MathsT, NULL);
	double cpp =0.4* _tcstod(m_CppD, NULL) + 0.6*_tcstod(m_CppT, NULL);
	
	//	�ж��Ƿ��ȡ�˿�����
	if (!(m_Name && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT && m_Gra && m_Sex))
	{
		MessageBox(_T("���ݲ���Ϊ�գ���������"), _T("��ʾ"), MB_ICONWARNING);
		return;
	}

	//	ͨ����ʱStudent�������м�¼��ӽ�ϵͳ
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

	//	�����ݼ������Ժ�Ž�Managerment�Ķ���ManagerSystem��
	if (ManagerSystem.Iscorrect(temp))
	{
		//	���������������
		ManagerSystem.AddData(temp);

		//	�ڽ����б�ؼ����������
		int nCount = m_List.GetItemCount();
		m_List.InsertItem(nCount, m_Num);
		m_List.SetItemText(nCount, 1, m_Gra);
		m_List.SetItemText(nCount, 2, m_Class);
		m_List.SetItemText(nCount, 3, m_Name);
		m_List.SetItemText(nCount, 4, m_Sex);

		//	��������תΪcstring��
		m_temp.Format(_T("%.1f"), maths);
		m_List.SetItemText(nCount, 5, m_temp);
		m_temp.Format(_T("%.1f"), cpp);
		m_List.SetItemText(nCount, 6, m_temp);

		//	����ѧ������
		m_STU.Format("%d", nCount+1);
		SetDlgItemText(IDC_EDIT_STU, m_STU);
	}
	else
		MessageBox(_T("ѧ����ͬ��ɼ����������������"), _T("��ʾ"), MB_ICONWARNING);
}

//	���"�༭"��ť
void MainDlg::OnBnClickedButtonEdit()
{
	//	Ѱ�ұ�ѡ�е��к� ѭ��ֱ���ҵ�����ѡ��
	for (m_Row = 0; m_Row < m_List.GetItemCount(); m_Row++)
	{
		if (m_List.GetCheck(m_Row))
			break;
	}

	//	���i=���� ˵���û�û�й�ѡ
	if (m_Row == m_List.GetItemCount())
	{
		MessageBox(_T("�빴ѡһ�У�"), _T("��ʾ"), MB_ICONWARNING);
		return;
	}

	//	�ӱ༭���ȡ����
	UpdateData(TRUE);

	double maths = 0.4 * _tcstod(m_MathsD, NULL) + 0.6 * _tcstod(m_MathsT, NULL);
	double cpp = 0.4 * _tcstod(m_CppD, NULL) + 0.6 * _tcstod(m_CppT, NULL);

	//	�ж��Ƿ��п�����
	if (!(m_Name && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT && m_Gra && m_Sex))
	{
		MessageBox(_T("������Ϊ�գ���������"), _T("��ʾ"), MB_ICONWARNING);
		return;
	}

	//	��ȡ���ݷ�����ʱ����
	temp.Num = m_Num;
	temp.Name = m_Name;
	temp.Class = m_Class;
	temp.CPP = cpp;
	temp.maths = maths;
	
	//	���ù���ϵͳ�ĺ����༭����
	ManagerSystem.EditData(temp, m_Row);
	
	//	���ؼ�ԭ����ɾ���������޸ĺ����
	m_List.DeleteItem(m_Row);
	m_List.InsertItem(m_Row, m_Num);
	m_List.SetItemText(m_Row, 1, m_Gra);
	m_List.SetItemText(m_Row, 2, m_Class);
	m_List.SetItemText(m_Row, 3, m_Name);
	m_List.SetItemText(m_Row, 4, m_Sex);
	//	��������תΪcstring��
	m_temp.Format(_T("%.1f"), maths);
	m_List.SetItemText(m_Row, 5, m_temp);
	m_temp.Format(_T("%.1f"), cpp);
	m_List.SetItemText(m_Row, 6, m_temp);
}

//	���"ɾ��"��ť
void MainDlg::OnBnClickedButtonDelete()
{
	//	����ѭ������ҵ�ѡ�е��н���ɾ��
	for (m_Row = 0; m_Row < m_List.GetItemCount(); m_Row++)
	{
		if (m_List.GetCheck(m_Row))
		{
			ManagerSystem.DeleteData(m_Row);
			m_List.DeleteItem(m_Row);
			m_Row--;
		}
	}

	//	����ѧ������
	int nCount = m_List.GetItemCount();
	m_STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, m_STU);
}

//	���"����"��ť
void MainDlg::OnBnClickedButtonSort()
{
	//	ɾ��list controlȫ����Ŀ
	m_List.DeleteAllItems();

	//	��ȡ��ǰ�б�������
	int nCount = ManagerSystem.GetCount();

	//	����m_Sortִ�в�ͬ�������֧
	switch (m_Sort)
	{
	case 0:
		ManagerSystem.SortDataM();
		
		//	������������������б���
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

		//	�޸Ĵ����б�״̬�ı���
		SortID = 1;

	case 1:
		ManagerSystem.SortDataC();

		//	������������������б���
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

		//	�޸Ĵ����б�״̬�ı���
		SortID = 2;

	default:
		break;
	}

	//	����ѧ������
	m_STU.Format(_T("%d"), m_List.GetItemCount());
	SetDlgItemText(IDC_EDIT_STU, m_STU);
}

//	���"����"��ť
void MainDlg::OnBnClickedButtonSave()
{
	//	���ñ����ļ��Ի������Ϣ
	CFileDialog fDlg(FALSE, ".dat", "save", OFN_OVERWRITEPROMPT, "�����ļ�(*.dat)|*.dat", NULL);

	if (fDlg.DoModal()==IDOK)
	{
		//	��ȡ�ļ�·��
		CString sPath = fDlg.GetPathName();

		//	�����ļ�����
		CStdioFile file(sPath, CFile::modeWrite | CFile::modeCreate);

		//	����forѭ������¼д���ļ�
		for (m_Row = 0; m_Row < m_List.GetItemCount(); m_Row++)
		{
			//	��ÿ�е�����ƴ�ӳ�һ���ַ���
			m_temp = '\0';
			m_temp += m_List.GetItemText(m_Row, 0) + "#";
			m_temp += m_List.GetItemText(m_Row, 1) + "#";
			m_temp += m_List.GetItemText(m_Row, 2) + "#";
			m_temp += m_List.GetItemText(m_Row, 3) + "#";
			m_temp += m_List.GetItemText(m_Row, 4) + "#";
			m_temp += m_List.GetItemText(m_Row, 5) + "#";
			m_temp += m_List.GetItemText(m_Row, 6) + "#\n";

			//	���ļ�д��һ�м�¼
			file.WriteString(m_temp);
		}

		//	д����� �ر�д��
		file.Close();
	}
	
}

//	���"��"��ť
void MainDlg::OnBnClickedButtonOpen()
{
	//	���ô��ļ��Ի������Ϣ
	CFileDialog fDlg(TRUE, ".dat", "save", OFN_OVERWRITEPROMPT, "�����ļ�(*.dat)|*.dat", NULL);

	//	����ɹ��򿪶Ի���
	if (fDlg.DoModal() == IDOK)
	{
		//	�����ļ�����
		CStdioFile file(fDlg.GetPathName(), CFile::modeRead);

		//	��ʼ���к�
		m_Row = 0;

		//	���϶�ȡ��ֱ���ļ�β
		while (file.ReadString(m_temp))
		{
			//	����ÿһ��#��λ��
			int x = m_temp.Find("#");
			int x2 = m_temp.Find("#", x + 1);
			int x3 = m_temp.Find("#", x2 + 1);
			int x4 = m_temp.Find("#", x3 + 1);
			int x5 = m_temp.Find("#", x4 + 1);
			int x6 = m_temp.Find("#", x5 + 1);
			int x7 = m_temp.Find("#", x6 + 1);

			//	����ȡ�����ݷ���Student����ʱ����temp��
			temp.Num = m_temp.Left(x);
			temp.Grade = m_temp.Mid(x + 1, x2 - x - 1);
			temp.Class = m_temp.Mid(x2 + 1, x3 - x2 - 1);
			temp.Name = m_temp.Mid(x3 + 1, x4 - x3 - 1);
			temp.Sex = m_temp.Mid(x4 + 1, x5 - x4 - 1);
			temp.maths = _tcstod(m_temp.Mid(x5 + 1, x4 - x3 - 1), NULL);
			temp.CPP = _tcstod(m_temp.Mid(x6 + 1, x7 - x6 - 1), NULL);

			//	��ÿ��������ӽ��������ڲ�
			ManagerSystem.AddData(temp);

			//	��ÿ��������ӽ�list control�ؼ���
			m_List.InsertItem(m_Row, temp.Num);
			m_List.SetItemText(m_Row, 1, temp.Grade);
			m_List.SetItemText(m_Row, 2, temp.Class);
			m_List.SetItemText(m_Row, 3, temp.Name);
			m_List.SetItemText(m_Row, 4, temp.Sex);

			//	����Format_Temp�������ǽ��һ��bug
			//	�����������һ��98.2#����������
			//	����CString�ĸ�ʽ�����ܿ��Խ�����bug
			CString Format_Temp;

			Format_Temp.Format("%.1f", temp.maths);
			m_List.SetItemText(m_Row, 5, Format_Temp);

			Format_Temp.Format("%.1f", temp.CPP);
			m_List.SetItemText(m_Row, 6, Format_Temp);

			//	�к�++ ���´�ѭ��ʱд����һ��
			m_Row++;
		}
	}
	else
	{
		MessageBox("WTF ???	�����ǿ��Ը����������»���");
		return;
	}

	//	����ѧ������
	int nCount = m_List.GetItemCount();
	m_STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, m_STU);
}

//	���"��ͼ"��ť
void MainDlg::OnBnClickedButtonStatisgraph()
{
	//	�ȶԵ�ǰ��¼���б��� �Ա��ͼ���ڶ��ļ�
	OnBnClickedButtonSave();

	//	����һ��ģ̬�Ի���
	StatisGraphDlg dlg;
	dlg.DoModal();
}

//	˫��list control����Ӧ�¼�������ѧ������Ϣ���õ�����򷽱�����޸ģ�
void MainDlg::OnNMDblclkListShow(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	//	���ȵõ������λ��
	POSITION pos = m_List.GetFirstSelectedItemPosition();

	if (pos == NULL)
	{
		MessageBox("������ѡ��һ��", "��ʾ", MB_ICONEXCLAMATION);
		return;
	}

	//	�õ��кţ�ͨ��POSITIONת��
	m_Row = (int)m_List.GetNextSelectedItem(pos);

	//	�����еĶ�ѡ����
	m_List.SetCheck(m_Row, TRUE);

	//	��ȡ��λ��ѧ������Ϣ
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
		MessageBox("WTF????	How dare are you��");
		break;
	}

	//	���õ������
	SetDlgItemText(IDC_EDIT_Name, temp.Name);
	SetDlgItemText(IDC_EDIT_Num, temp.Num);
	SetDlgItemText(IDC_EDIT_Class, temp.Class);
	SetDlgItemText(IDC_EDIT_Mathsd, temp.mathsD);
	SetDlgItemText(IDC_EDIT_Mathst, temp.mathsT);
	SetDlgItemText(IDC_EDIT_Cppd, temp.CPPD);
	SetDlgItemText(IDC_EDIT_Cppt, temp.CPPT);

	CButton* Cwnd_radio_temp;

	//	�����Ա�ѡ��
	if (temp.Sex == "��")
	{
		//	��ȡ��ѡ���е�ָ��
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_SexMan);
		Cwnd_radio_temp->SetCheck(TRUE);
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_SexWoman);
		Cwnd_radio_temp->SetCheck(FALSE);
	}
	else
	{
		//	��ȡ��ѡ��Ů��ָ��
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_SexWoman);
		Cwnd_radio_temp->SetCheck(TRUE);
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_SexMan);
		Cwnd_radio_temp->SetCheck(FALSE);
	}
	
	//	ȡ�������꼶��ѡ��ѡ�����޸�bug��
	Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra1);
	Cwnd_radio_temp->SetCheck(FALSE);
	Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra2);
	Cwnd_radio_temp->SetCheck(FALSE);
	Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra3);
	Cwnd_radio_temp->SetCheck(FALSE);
	Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra4);
	Cwnd_radio_temp->SetCheck(FALSE);

	//	�����꼶��ѡ��
	if (temp.Grade == "��һ")
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra1);
	else if (temp.Grade == "���")
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra2);
	else if (temp.Grade == "����")
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra3);
	else
		Cwnd_radio_temp = (CButton*)GetDlgItem(IDC_RADIO_Gra4);

	Cwnd_radio_temp->SetCheck(TRUE);

	*pResult = 0;
}