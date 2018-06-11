#pragma once

#include <atlimage.h>

typedef union
{
	UINT8 m_AllData[19];
	struct
	{
		UINT8 m_HeadIdent[3];//�ļ�ͷ��ʶ,3Byte
		UINT8 m_HeadLen[2];//�ļ�ͷ����,2Byte
		UINT8 m_FileFmt[3];//�ļ���ʽ,3Byte
		UINT8 m_DataBitWidth[2];//����λ��,2Byte
		UINT8 m_HeadReserv[3];//�ļ�ͷԤ��,3Byte
		UINT8 m_ImgWidth[3];//ͼ����,3Byte
		UINT8 m_ImgHeight[3];//ͼ��߶�,3Byte
	}SubData;
}HEAD_INFO;

typedef union
{
	UINT8 m_AllData[158];
	struct
	{
		UINT8 m_PackHeadPos[2];//�������ݰ�ͷλ�ã�2bytes
		UINT8 m_DataWidth[2];//�������ݿ�ȣ�2bytes
		UINT8 m_DataLength[2];//�������ݳ��ȣ�2bytes
		UINT8 m_ProjIdent[8];//��Ŀ��ʶ��8bytes
		UINT8 m_FrameCnt[8];//֡������8bytes
		UINT8 m_LineCnt[8];//�м�����8bytes
		UINT8 m_BroadTime[8];//�㲥ʱ�䣬8bytes
		UINT8 m_PixStPos[2];//��Ч��Ԫ��ʼλ�ã�2bytes
		UINT8 m_PixEdPos[2];//��Ч��Ԫ��ֹλ�ã�2bytes
		UINT8 m_ProjName[8];//��Ŀ���ƣ�8bytes
		UINT8 m_SaveTime[6];//��ͼʱ�䣬6bytes
		UINT8 m_DevModel[8];//�����ͺţ�8bytes
		UINT8 m_DevQuant;//����������1byte
		UINT8 m_DevNum;//������ţ�1byte
		UINT8 m_SpecsecNum;//�׶α�ţ�1byte
		UINT8 m_DataOrder[4];//����˳��4bytes
		UINT8 m_SplicPixQuant[2];//ƴ������Ԫ����2bytes
		UINT8 m_LightRadLevel;//��Դ�����ȵȼ���1byte
		UINT8 m_DevLevel[11];//����������11bytes
		UINT8 m_IntgTime[5];//����ʱ�䣬5bytes
		UINT8 m_Gain[11];//���棬11bytes
		UINT8 m_Alg1Switch[4];//Algorithm1 Switch��4bytes
		UINT8 m_Alg2Switch[4];//Algorithm2 Switch��4bytes
		UINT8 m_Alg3Switch[4];//Algorithm3 Switch��4bytes
		UINT8 m_Alg4Switch[4];//Algorithm4 Switch��4bytes
		UINT8 m_Alg5Switch[4];//Algorithm5 Switch��4bytes
		UINT8 m_Alg6Switch[4];//Algorithm6 Switch��4bytes
		UINT8 m_Alg7Switch[4];//Algorithm7 Switch��4bytes
		UINT8 m_Alg8Switch[4];//Algorithm8 Switch��4bytes
		UINT8 m_Sp1SgTapPQ;//Spectrum 1 Single Tap Pixel Quantity��
		UINT8 m_Sp1Tap1PPos[2];//Spectrum 1 Tap1 Dark Pixel Start Position��
		UINT8 m_Sp1Tap2PPos[2];//Spectrum 1 Tap2 Dark Pixel Start Position��
		UINT8 m_Sp2SgTapPQ;//Spectrum 2 Single Tap Pixel Quantity��
		UINT8 m_Sp2Tap1PPos[2];//Spectrum 2 Tap1 Dark Pixel Start Position��
		UINT8 m_Sp2Tap2PPos[2];//Spectrum 2 Tap2 Dark Pixel Start Position��
		UINT8 m_Sp3SgTapPQ;//Spectrum 3 Single Tap Pixel Quantity��
		UINT8 m_Sp3Tap1PPos[2];//Spectrum 3 Tap1 Dark Pixel Start Position��
		UINT8 m_Sp3Tap2PPos[2];//Spectrum 3 Tap2 Dark Pixel Start Position
		UINT8 m_Sp4SgTapPQ;//Spectrum 4 Single Tap Pixel Quantity
		UINT8 m_Sp4Tap1PPos[2];//Spectrum 4 Tap1 Dark Pixel Start Position
		UINT8 m_Sp4Tap2PPos[2];//Spectrum 4 Tap2 Dark Pixel Start Position
		UINT8 m_Sp5SgTapPQ;//Spectrum 5 Single Tap Pixel Quantity
		UINT8 m_Sp5Tap1PPos[2];//Spectrum 5 Tap1 Dark Pixel Start Position
		UINT8 m_Sp5Tap2PPos[2];//Spectrum 5 Tap2 Dark Pixel Start Position
	}SubData;
}AUXIL_DATA;

const int HEAD_INFO_ITEM_NUMS = 51;
const int HEAD_INFO_BYTE_SIZE = 177;
typedef union
{
	UINT32 m_PixV;
	struct
	{
		UINT32 m_R : 8;
		UINT32 m_G : 8;
		UINT32 m_B : 8;
		UINT32 m_A : 8;
	}RGBA;
}PIXEL_PACK;

static inline int GetHeadInfoItemOff(int idx)
{
	switch (idx)
	{
	case 0:
		return 0;
	case 1:
		return 3;
	case 2:
		return 5;
	case 3:
		return 8;
	case 4:
		return 10;
	case 5:
		return 13;
	case 6:
		return 16;
	case 7:
		return 19;
	case 8:
		return 21;
	case 9:
		return 23;
	case 10:
		return 25;
	case 11:
		return 33;
	case 12:
		return 41;
	case 13:
		return 49;
	case 14:
		return 57;
	case 15:
		return 59;
	case 16:
		return 61;
	case 17:
		return 69;
	case 18:
		return 75;
	case 19:
		return 83;
	case 20:
		return 84;
	case 21:
		return 85;
	case 22:
		return 86;
	case 23:
		return 90;
	case 24:
		return 92;
	case 25:
		return 93;
	case 26:
		return 104;
	case 27:
		return 109;
	case 28:
		return 120;
	case 29:
		return 124;
	case 30:
		return 128;
	case 31:
		return 132;
	case 32:
		return 136;
	case 33:
		return 140;
	case 34:
		return 144;
	case 35:
		return 148;
	case 36:
		return 152;
	case 37:
		return 153;
	case 38:
		return 155;
	case 39:
		return 157;
	case 40:
		return 158;
	case 41:
		return 160;
	case 42:
		return 162;
	case 43:
		return 163;
	case 44:
		return 165;
	case 45:
		return 167;
	case 46:
		return 168;
	case 47:
		return 170;
	case 48:
		return 172;
	case 49:
		return 173;
	case 50:
		return 175;
	default:
		break;
	}
	return 0;
}

static inline int GetHeadInfoItemSize(int idx)
{
	switch (idx)
	{
	case 0:
		return 3;
	case 1:
		return 2;
	case 2:
		return 3;
	case 3:
		return 2;
	case 4:
		return 3;
	case 5:
		return 3;
	case 6:
		return 3;
	case 7:
		return 2;
	case 8:
		return 2;
	case 9:
		return 2;
	case 10:
		return 8;
	case 11:
		return 8;
	case 12:
		return 8;
	case 13:
		return 8;
	case 14:
		return 2;
	case 15:
		return 2;
	case 16:
		return 8;
	case 17:
		return 6;
	case 18:
		return 8;
	case 19:
		return 1;
	case 20:
		return 1;
	case 21:
		return 1;
	case 22:
		return 4;
	case 23:
		return 2;
	case 24:
		return 1;
	case 25:
		return 11;
	case 26:
		return 5;
	case 27:
		return 11;
	case 28:
		return 4;
	case 29:
		return 4;
	case 30:
		return 4;
	case 31:
		return 4;
	case 32:
		return 4;
	case 33:
		return 4;
	case 34:
		return 4;
	case 35:
		return 4;
	case 36:
		return 1;
	case 37:
		return 2;
	case 38:
		return 2;
	case 39:
		return 1;
	case 40:
		return 2;
	case 41:
		return 2;
	case 42:
		return 1;
	case 43:
		return 2;
	case 44:
		return 2;
	case 45:
		return 1;
	case 46:
		return 2;
	case 47:
		return 2;
	case 48:
		return 1;
	case 49:
		return 2;
	case 50:
		return 2;
	default:
		break;
	}
	return 0;
}

static inline const wchar_t* GetHeadInfoItemStr(int idx)
{
	switch (idx)
	{
	case 0:
		return _T("�ļ�ͷ��ʶ");
	case 1:
		return _T("�ļ�ͷ����");
	case 2:
		return _T("�ļ���ʽ");
	case 3:
		return _T("����λ��");
	case 4:
		return _T("�ļ�ͷԤ��");
	case 5:
		return _T("ͼ����");
	case 6:
		return _T("ͼ��߶�");
	case 7:
		return _T("�������ݰ�ͷλ��");
	case 8:
		return _T("�������ݿ��");
	case 9:
		return _T("�������ݳ���");
	case 10:
		return _T("��Ŀ��ʶ");
	case 11:
		return _T("֡����");
	case 12:
		return _T("�м���");
	case 13:
		return _T("�㲥ʱ��");
	case 14:
		return _T("��Ч��Ԫ��ʼλ��");
	case 15:
		return _T("��Ч��Ԫ��ֹλ��");
	case 16:
		return _T("��Ŀ����");
	case 17:
		return _T("��ͼʱ��");
	case 18:
		return _T("�����ͺ�");
	case 19:
		return _T("��������");
	case 20:
		return _T("�������");
	case 21:
		return _T("�׶α��");
	case 22:
		return _T("����˳��");
	case 23:
		return _T("ƴ������Ԫ��");
	case 24:
		return _T("��Դ�����ȵȼ�");
	case 25:
		return _T("��������");
	case 26:
		return _T("����ʱ��");
	case 27:
		return _T("����");
	case 28:
		return _T("�㷨1����");
	case 29:
		return _T("�㷨2����");
	case 30:
		return _T("�㷨3����");
	case 31:
		return _T("�㷨4����");
	case 32:
		return _T("�㷨5����");
	case 33:
		return _T("�㷨6����");
	case 34:
		return _T("�㷨7����");
	case 35:
		return _T("�㷨8����");
	case 36:
		return _T("�׶�1����ͷ����Ԫ����");
	case 37:
		return _T("�׶�1��ͷ1����Ԫ��ʼλ��");
	case 38:
		return _T("�׶�1��ͷ2����Ԫ��ʼλ��");
	case 39:
		return _T("�׶�2����ͷ����Ԫ����");
	case 40:
		return _T("�׶�2��ͷ1����Ԫ��ʼλ��");
	case 41:
		return _T("�׶�2��ͷ2����Ԫ��ʼλ��");
	case 42:
		return _T("�׶�3����ͷ����Ԫ����");
	case 43:
		return _T("�׶�3��ͷ1����Ԫ��ʼλ��");
	case 44:
		return _T("�׶�3��ͷ2����Ԫ��ʼλ��");
	case 45:
		return _T("�׶�4����ͷ����Ԫ����");
	case 46:
		return _T("�׶�4��ͷ1����Ԫ��ʼλ��");
	case 47:
		return _T("�׶�4��ͷ2����Ԫ��ʼλ��");
	case 48:
		return _T("�׶�5����ͷ����Ԫ����");
	case 49:
		return _T("�׶�5��ͷ1����Ԫ��ʼλ��");
	case 50:
		return _T("�׶�5��ͷ2����Ԫ��ʼλ��");
	default:
		break;
	}
	return _T("");
}

typedef enum
{
	from15to8,
	from14to7,
	from13to6,
	from12to5,
	from11to4,
	from10to3,
	from9to2,
	from8to1,
	from7to0
}BIT_RANGE;

class CAST_IMG
{
public:
	CAST_IMG();
	~CAST_IMG();
public:
	void* m_pData;//whole file data
	void* m_pImgData;//real image data
	int m_ImgW;
	int m_ImgH;
	int m_BPP;//Byte Per Pixel
	int m_LinePitch;//line pitch
	AUXIL_DATA m_AuxData;
	HEAD_INFO m_HeadData;
	CImage cimg;
	int m_CImgW;
	int m_CImgH;
	void LoadFile(const char* pFileName);
	void ReadFile(const char* pFileName, BYTE*& pData);
	void DataCfg();
	inline BYTE GetPixValue(int x, int y) const {
		return *((BYTE*)m_pImgData + y*m_LinePitch + x);
	};
	int CreateCImg(int& CImgW, int& CImgH);
	int CopyDataToCImg(void* pData, int& ImgW, int& ImgH, BIT_RANGE bitRange = from15to8);
};