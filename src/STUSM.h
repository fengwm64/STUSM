
// STUSM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSTUSMApp: 
// �йش����ʵ�֣������ STUSM.cpp
//

class CSTUSMApp : public CWinApp
{
public:
	CSTUSMApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSTUSMApp theApp;