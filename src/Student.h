#pragma once

#include "afxdialogex.h"

//--------Student������---------
class Student
{
public:
	Student();

	CString Num;//ѧ��
	CString Grade;
	CString Class;
	CString Name;
	CString Sex;

	double maths;//�ߵ���ѧ�ĳɼ�
	CString mathsD;
	CString mathsT;

	double CPP;//�������������
	CString CPPD;
	CString CPPT;
};