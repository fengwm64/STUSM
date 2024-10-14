// STUSMDlg.cpp : ʵ���ļ�

#include "stdafx.h"
#include "STUSM.h"
#include "STUSMDlg.h"
#include "afxdialogex.h"
#include "MainDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSTUSMDlg �Ի���



CSTUSMDlg::CSTUSMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSTUSMDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_login);
}

void CSTUSMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON_Login, M_login);
}

BEGIN_MESSAGE_MAP(CSTUSMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MFCBUTTON_Login, &CSTUSMDlg::OnBnClickedMfcbuttonLogin)
	ON_BN_CLICKED(IDC_CHECK_Remember, &CSTUSMDlg::OnBnClickedCheckRemember)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSTUSMDlg ��Ϣ�������

BOOL CSTUSMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	

	//------------���İ�ť����ɫ���ı�ɫ-------------
	M_login.m_bDontUseWinXPTheme = TRUE;
	M_login.m_bDrawFocus = false;
	M_login.SetFaceColor(RGB(0, 176, 37));
	M_login.SetTextColor(RGB(255, 255, 255));


	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSTUSMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSTUSMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//------------���ñ���ͼƬ-------------
		CPaintDC   dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP_loginbg);  //�Ի���ı���ͼƬ  

		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSTUSMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Account
CString ACC = _T("32116160100");
//Password
CString PAS = _T("gzhucs");

void CSTUSMDlg::OnBnClickedMfcbuttonLogin()
{
	static int COUNT = 0;//�������
	CString account, password;
	GetDlgItemText(IDC_EDIT_Account, account);
	GetDlgItemText(IDC_EDIT_Password, password);

	//------------��¼�����ж��߼�-------------
	if (COUNT >3)
	{
		MessageBox(_T("��������������Σ������˳���"), _T("��ʾ"), MB_ICONWARNING);
		(CDialog*)AfxGetMainWnd()->DestroyWindow();
	}
	if (account == ACC&&password == PAS)
	{
		//ShowWindow(SW_HIDE);
		MainDlg main;
		main.DoModal();		
	}
	else if (account == "" || password == "")
		MessageBox(_T("�˺Ż����벻��Ϊ��"), _T("��ʾ"), MB_ICONWARNING);
	else
	{
		MessageBox(_T("�˺Ż��������!"), _T("����"), MB_ICONWARNING);
		COUNT++;
	}
}



void CSTUSMDlg::OnBnClickedCheckRemember()
{
	SetDlgItemText(IDC_EDIT_Account, ACC);
	SetDlgItemText(IDC_EDIT_Password, PAS);
}


HBRUSH CSTUSMDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)//����̬�ı�����Ϊ͸��
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT id = pWnd->GetDlgCtrlID();
	if (id == IDC_STATIC || id == IDC_CHECK_Remember)
	{
		pDC->SetTextColor(RGB(90, 92, 90));//�����ı���������ɫ

		pDC->SetBkMode(TRANSPARENT);
		CRect rc;
		pWnd->GetWindowRect(&rc);
		ScreenToClient(&rc);
		CDC* dc = GetDC();
		pDC->BitBlt(0, 0, rc.Width(), rc.Height(), dc, rc.left, rc.top, SRCCOPY);  //�Ѹ����ڱ���ͼƬ�Ȼ�����ť��
		ReleaseDC(dc);

		return (HBRUSH) ::GetStockObject(NULL_BRUSH);
	}

}
