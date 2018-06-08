
// FileGenDlg.h : ͷ�ļ�
//

#pragma once


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
};
