
// FileGenDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CFileGenDlg 对话框



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


// CFileGenDlg 消息处理程序

BOOL CFileGenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

// 	CRect rect;
// 	// 获取编程语言列表视图控件的位置和大小   
// 	m_programLangList.GetClientRect(&rect);
// 	// 为列表视图控件添加全行选中和栅格风格   
// 	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
// 	// 为列表视图控件添加三列   
// 	m_programLangList.InsertColumn(0, _T("语言"), LVCFMT_CENTER, rect.Width() / 3, 0);
// 	m_programLangList.InsertColumn(1, _T("2012.02排名"), LVCFMT_CENTER, rect.Width() / 3, 1);
// 	m_programLangList.InsertColumn(2, _T("2011.02排名"), LVCFMT_CENTER, rect.Width() / 3, 2);
// 	// 在列表视图控件中插入列表项，并设置列表子项文本   
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFileGenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFileGenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileGenDlg::OnBnClickedButtonPath()
{
	// TODO: 在此添加控件通知处理程序代码
// 	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
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
	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
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
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData(TRUE);
	GenFiles(m_strPath, m_FileNum);
}
