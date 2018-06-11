// ShowAuxlDataDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileGen.h"
#include "ShowAuxlDataDlg.h"
#include "afxdialogex.h"

#include <string>
using namespace std;

// ShowAuxlDataDlg �Ի���

IMPLEMENT_DYNAMIC(ShowAuxlDataDlg, CDialogEx)

ShowAuxlDataDlg::ShowAuxlDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_AUXLSHOW, pParent)
{

}

ShowAuxlDataDlg::~ShowAuxlDataDlg()
{
}

void ShowAuxlDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(ShowAuxlDataDlg, CDialogEx)
END_MESSAGE_MAP()


// ShowAuxlDataDlg ��Ϣ�������


BOOL ShowAuxlDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ShowWindow(SW_SHOWMAXIMIZED);
 	LineCnt = 0;
 	CRect rect;
 	GetClientRect(&rect);
 	m_ListCtrl.MoveWindow(&rect);
 	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
 	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
 	// Ϊ�б���ͼ�ؼ��������
 	m_ListCtrl.InsertColumn(0, _T("���"), LVCFMT_CENTER, 50, 0);
 	for (int i = 1; i != HEAD_INFO_ITEM_NUMS + 1; ++i)
 		m_ListCtrl.InsertColumn(i, GetHeadInfoItemStr(i - 1), LVCFMT_CENTER, rect.Width() / 10, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void ShowAuxlDataDlg::ListInsert(HEAD_INFO& hdif, AUXIL_DATA& auxdt, bool b_parse)
{
	CString strNum;
	strNum.Format(_T("%d"), LineCnt);
	m_ListCtrl.InsertItem(LineCnt, strNum);
	if (b_parse)
	{
	}
	else
	{
		int len1 = sizeof(hdif.m_AllData);
		int len2 = sizeof(auxdt.m_AllData);
		BYTE* HeadByte=new BYTE[len1+len2];
		memcpy(HeadByte, hdif.m_AllData, len1);
		memcpy(HeadByte + len1, auxdt.m_AllData, len2);
		for (int i = 1; i != HEAD_INFO_ITEM_NUMS + 1; ++i)
		{
			int ByteSize = GetHeadInfoItemSize(i - 1);
			int ByteOff = GetHeadInfoItemOff(i - 1);
			CString strData;
			strData = "0x";
			for (int j = ByteOff + ByteSize - 1; j != ByteOff - 1; --j)
			{
				CString strTmp;
				strTmp.Format(_T("%x"), HeadByte[j]);
				strData += strTmp;
			}
			m_ListCtrl.SetItemText(LineCnt, i, strData);
		}
		delete[]HeadByte;
	}
	++LineCnt;
	return;
}