
// FileGenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileGen.h"
#include "FileGenDlg.h"
#include "afxdialogex.h"

#include <random>
#include <stdio.h>
#include <string>
using namespace std;

#include "ShowAuxlDataDlg.h"

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
	DDX_Control(pDX, IDC_LIST_AUXLDATA, m_AuxList);
}

BEGIN_MESSAGE_MAP(CFileGenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PATH, &CFileGenDlg::OnBnClickedButtonPath)
	ON_BN_CLICKED(IDOK, &CFileGenDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SHOW_AUX, &CFileGenDlg::OnBnClickedShowAux)
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
	GetDlgItem(IDC_SHOW_AUX)->ShowWindow(SW_HIDE);

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

void CFileGenDlg::HEADCfg(HEAD_INFO& HdInfo, int& MemSize)
{
	MemSize = sizeof(HdInfo.m_AllData);
	HdInfo.SubData.m_HeadIdent[0] = 'I';
	HdInfo.SubData.m_HeadIdent[1] = 'F';
	HdInfo.SubData.m_HeadIdent[2] = 'H';
	HdInfo.SubData.m_HeadLen[0] = 177 & 0xff;
	HdInfo.SubData.m_HeadLen[1] = 177 >> 8;
	HdInfo.SubData.m_FileFmt[0] = 'r';
	HdInfo.SubData.m_FileFmt[1] = 'a';
	HdInfo.SubData.m_FileFmt[2] = 'w';
	HdInfo.SubData.m_DataBitWidth[0] = 8;
	HdInfo.SubData.m_DataBitWidth[1] = 0;
	HdInfo.SubData.m_HeadReserv[0] = 0;
	HdInfo.SubData.m_HeadReserv[1] = 0;
	HdInfo.SubData.m_HeadReserv[2] = 0;
	int imgw = rand() % 1921;
	int imgh = rand() % 1081;
	memcpy(HdInfo.SubData.m_ImgWidth, &imgw, 3);
	memcpy(HdInfo.SubData.m_ImgHeight, &imgh, 3);
	return;
}
void CFileGenDlg::AUXLCfg(AUXIL_DATA& AuxData, int& MemSize)
{
	MemSize = sizeof(AuxData.m_AllData);
	for (int i = 0; i != MemSize; ++i)
		AuxData.m_AllData[i] = rand() % 0x100;
	return;
}
void CFileGenDlg::IMGDATACfg(void* pData, int& MemSize)
{
	srand((unsigned)time(NULL));
	BYTE* pDataTmp = (BYTE*)pData;
	for (int i = 0; i != MemSize; ++i)
		pDataTmp[i] = rand() % 0x100;
	return;
}

void CFileGenDlg::GenFiles(CString strPath, const int FNum)
{
	int len1 = 0, len2 = 0, len3 = 0;
	HEAD_INFO hdInf;
	AUXIL_DATA auxDt;
	char fName[64] = { 0 };
	FILE* pF=nullptr;
	srand((unsigned)time(NULL));
	for (int i=0;i!=FNum;++i)
	{
		HEADCfg(hdInf, len1);
		AUXLCfg(auxDt, len2);
		int imgw = 0, imgh = 0;
		memcpy(&imgw, hdInf.SubData.m_ImgWidth, 3);
		memcpy(&imgh, hdInf.SubData.m_ImgHeight, 3);
		len3 = imgw*imgh;
		BYTE* ImgData = new BYTE[len3];
		IMGDATACfg(ImgData, len3);
		string strFPath = CT2A(strPath.GetBuffer(0));
		sprintf_s(fName, "%s\\%d", strFPath.c_str(), i);
		fopen_s(&pF, fName, "w+");
		fwrite(hdInf.m_AllData, 1, len1, pF);
		fwrite(auxDt.m_AllData, 1, len2, pF);
		fwrite(ImgData, 1, len3, pF);
		delete[]ImgData;
		fclose(pF);
		pF = nullptr;
		memset(fName, 0, 64);
	}
	return;
}

void CFileGenDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	UpdateData(TRUE);
	GenFiles(m_strPath, m_FileNum);
}


void CFileGenDlg::OnBnClickedShowAux()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAST_IMG catimg;
	BYTE* pFData = NULL;
	HEAD_INFO tmphdif;
	AUXIL_DATA tmpauxdt;
	AuxDlg.Create(IDD_DIALOG_AUXLSHOW, NULL);
	char fname[64] = { 0 };
	for (int i=0;i!=100;++i)
	{
		sprintf_s(fname, "E:\\my_vs_project\\CAST\\src_data\\%d", i);
		catimg.ReadFile(fname, pFData);
		memcpy(tmphdif.m_AllData, pFData, sizeof(tmphdif.m_AllData));
		memcpy(tmpauxdt.m_AllData, pFData + sizeof(tmphdif.m_AllData), sizeof(tmpauxdt.m_AllData));
		delete[]pFData;
		pFData = NULL;
		memset(fname, 0, 64);
		AuxDlg.ListInsert(tmphdif, tmpauxdt);
	}
	AuxDlg.ShowWindow(SW_SHOW);
}
