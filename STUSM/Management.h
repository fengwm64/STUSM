#pragma once
#include "afxdialogex.h"
#include "Student.h"
#include <fstream>
#include <string>

using namespace std;	//	如果不使用标准命名空间 swap函数需要注明std::

//	----------------------------------------------------Management类声明---------------------------------------------------
class Management
{
public:
	Management();			//	构造
	~Management();		//	析构

	//-----------------------对容器的操作----------------------
	void AddData(Student);				//	学生成绩数据的增加
	void DeleteData(int n);					//	学生成绩数据的删除
	void EditData(Student obj, int n);	//	学生成绩数据的修改
	void SortDataM();							//	学生成绩数据的排序(按高数)
	void SortDataC();							//	学生成绩数据的排序(按面向对象)


	//--------------------对数据的有效性判断-------------------
	BOOL IsSame(Student obj);			//	判断容器内是否已经存在相同学号的人
	BOOL Iscorrect(Student obj);		//	判断输入数据的有效性


	//-------------------------统计数据------------------------
	int GetCount();						//	返回容器内人数
	double GetSum(int ID);			//	求和
	double GetAver(int ID);			//	求平均值
	double GetMedian(int ID);	//	求中位数
	double GetRange(int ID);		//	求极差
	double GetVariance(int ID);	//	求方差


	//-----------------------容器数据成员----------------------
public:
	Student* Pstu;						//	指向无序数据数组的指针
	Student* SortM;					//	指向按高数成绩排序后数组的指针
	Student* SortC;					//	指向按面向对象成绩排序后数组的指针

private:
	int Count;								//	用于统计容器内已经添加的人数
	int Size;								//	容器的总容量
};