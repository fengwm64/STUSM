#pragma once

#include "afxdialogex.h"

//--------Student类声明---------
class Student
{
public:
	Student();

	CString Num;//学号
	CString Grade;
	CString Class;
	CString Name;
	CString Sex;

	double maths;//高等数学的成绩
	CString mathsD;
	CString mathsT;

	double CPP;//面向对象程序设计
	CString CPPD;
	CString CPPT;
};