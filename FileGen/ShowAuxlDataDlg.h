#pragma once
#include "afxcmn.h"

#include <vector>
using namespace std;
#include "CAST_SrcData.h"

// ShowAuxlDataDlg 对话框

class ShowAuxlDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowAuxlDataDlg)

public:
	ShowAuxlDataDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowAuxlDataDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_AUXLSHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ListCtrl;
	void ListInsert(HEAD_INFO& hdif, AUXIL_DATA& auxdt, bool b_parse = false);
	int LineCnt;
};
