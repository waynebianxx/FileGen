
// FileGenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileGen.h"
#include "FileGenDlg.h"
#include "afxdialogex.h"

#include <random>
#include <stdio.h>
#include <string>
#include "CAST_SrcData.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileGenDlg �Ի���



CFileGenDlg::CFileGenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILEGEN_DIALOG, pParent)
	, m_FileNum(100)
	, m_strPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileGenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILENUM, m_FileNum);
	DDX_Text(pDX, IDC_EDIT_SAVEPATH, m_strPath);
}

BEGIN_MESSAGE_MAP(CFileGenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PATH, &CFileGenDlg::OnBnClickedButtonPath)
	ON_BN_CLICKED(IDOK, &CFileGenDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFileGenDlg ��Ϣ�������

BOOL CFileGenDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

// 	CRect rect;
// 	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
// 	m_programLangList.GetClientRect(&rect);
// 	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
// 	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
// 	// Ϊ�б���ͼ�ؼ��������   
// 	m_programLangList.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 0);
// 	m_programLangList.InsertColumn(1, _T("2012.02����"), LVCFMT_CENTER, rect.Width() / 3, 1);
// 	m_programLangList.InsertColumn(2, _T("2011.02����"), LVCFMT_CENTER, rect.Width() / 3, 2);
// 	// ���б���ͼ�ؼ��в����б���������б������ı�   
// 	m_programLangList.InsertItem(0, _T("Java"));
// 	m_programLangList.SetItemText(0, 1, _T("1"));
// 	m_programLangList.SetItemText(0, 2, _T("1"));
// 	m_programLangList.InsertItem(1, _T("C"));
// 	m_programLangList.SetItemText(1, 1, _T("2"));
// 	m_programLangList.SetItemText(1, 2, _T("2"));
// 	m_programLangList.InsertItem(2, _T("C#"));
// 	m_programLangList.SetItemText(2, 1, _T("3"));
// 	m_programLangList.SetItemText(2, 2, _T("6"));
// 	m_programLangList.InsertItem(3, _T("C++"));
// 	m_programLangList.SetItemText(3, 1, _T("4"));
// 	m_programLangList.SetItemText(3, 2, _T("3"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFileGenDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileGenDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFileGenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileGenDlg::OnBnClickedButtonPath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
// 	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
// 	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
// 	if (IDOK == fileDlg.DoModal())
// 		m_strPath = fileDlg.GetPathName();
	m_strPath = SelFilePath();
	UpdateData(FALSE);

}

CString CFileGenDlg::SelFilePath()
{
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT("");
	BROWSEINFO      sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("Select File Path");
	sInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	sInfo.lpfn = NULL;
	// ��ʾ�ļ���ѡ��Ի���  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// ȡ���ļ�����  
		if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree(lpidlBrowse);
	}
	return strFolderPath;
}

void CFileGenDlg::GenFiles(CString strPath, const int FNum)
{
	int len1 = 19, len2 = 158, len3 = 1920 * 1080;
	HEAD_INFO hdInf;
	AUXIL_DATA auxDt;
	BYTE* ImgData = new BYTE[len3];
	char fName[64] = { 0 };
	FILE* pF=nullptr;
	for (int i=0;i!=FNum;++i)
	{
		srand((unsigned)time(NULL));
		for (int l = 0; l != len1; ++l)
			hdInf.m_AllData[l] = rand() % 0x100;
		for (int l = 0; l != len2; ++l)
			auxDt.m_AllData[l] = rand() % 0x100;
		for (int l = 0; l != len3; ++l)
			ImgData[l] = rand() % 0x100;
		string strFPath = CT2A(strPath.GetBuffer(0));
		sprintf_s(fName, "%s\\%d", strFPath.c_str(), i);
		fopen_s(&pF, fName, "w+");
		fwrite(hdInf.m_AllData, 1, len1, pF);
		fwrite(auxDt.m_AllData, 1, len2, pF);
		fwrite(ImgData, 1, len3, pF);
		fclose(pF);
		pF = nullptr;
		memset(fName, 0, 64);
	}
	delete[]ImgData;
	return;
}

void CFileGenDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	UpdateData(TRUE);
	GenFiles(m_strPath, m_FileNum);
}
