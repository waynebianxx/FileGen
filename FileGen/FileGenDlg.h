
// FileGenDlg.h : 头文件
//

#pragma once

#include "ShowAuxlDataDlg.h"
#include "CAST_SrcData.h"
#include "afxcmn.h"

// CFileGenDlg 对话框
class CFileGenDlg : public CDialogEx
{
// 构造
public:
	CFileGenDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEGEN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPath();
	int m_FileNum;
	CString m_strPath;
	CString SelFilePath();
	void GenFiles(CString strPath, const int FNum);
	afx_msg void OnBnClickedOk();
	void HEADCfg(HEAD_INFO& HdInfo, int& MemSize);
	void AUXLCfg(AUXIL_DATA& HdInfo, int& MemSize);
	void IMGDATACfg(void* pData, int& MemSize);
	CListCtrl m_AuxList;
	ShowAuxlDataDlg AuxDlg;
	afx_msg void OnBnClickedShowAux();
};
