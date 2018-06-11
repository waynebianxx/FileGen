
// FileGenDlg.h : ͷ�ļ�
//

#pragma once

#include "ShowAuxlDataDlg.h"
#include "CAST_SrcData.h"
#include "afxcmn.h"

// CFileGenDlg �Ի���
class CFileGenDlg : public CDialogEx
{
// ����
public:
	CFileGenDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEGEN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
