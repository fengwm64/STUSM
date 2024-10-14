#include "stdafx.h"
#include "Management.h"

Management::Management()
{
	Size = 100;
	Pstu = new Student[Size];
	SortM = NULL;
	SortC = NULL;
	Count = 0;
}

Management::~Management()
{
	delete[]Pstu;
	delete[]SortC;
	delete[]SortM;
	Size = 0;
	Count = 0;
}


//-----------------------对容器的操作----------------------
void Management::AddData(Student obj)
{
	Count++;
	if (Count > Size)
	{
		Student* temp = new Student[Size + 50];
		for (int i = 0; i < Size; i++)
			temp[i] = Pstu[i];
		Size += 50;
		delete[]Pstu;
		Pstu = temp;
	}
	Pstu[Count - 1] = obj;
}

void Management::DeleteData(int n)
{
	for (int i = n; i < Count; i++)
		Pstu[i] = Pstu[i + 1];
	Count--;
}

void Management::EditData(Student obj, int n)
{
	Pstu[n] = obj;
}

void Management::SortDataM()
{
	//为按数学成绩排序的容器开辟空间，并复制原容器数据
	SortM = new Student[Count];
	for (int i = 0; i < Count; i++)
		SortM[i] = Pstu[i];

	//	使用冒泡排序
	for (int i = 0; i < Count - 1; i++)
	{
		int work = 1;	//监测点，若数据本已经有序直接结束程序
		for (int k = 0; k < Count - i - 1; k++)
		{
			if (SortM[k].maths < SortM[k + 1].maths)
			{
				swap(SortM[k], SortM[k + 1]);
				work = 0;
			}
		}
		if (work)
			break;
	}
}

void Management::SortDataC()
{
	//为按CPP成绩排序的容器开辟空间，并复制原容器数据
	SortC = new Student[Count];
	for (int i = 0; i < Count; i++)
		SortC[i] = Pstu[i];

	//	使用冒泡排序
	for (int i = 0; i < Count - 1; i++)
	{
		int work = 1;	//监测点，若数据本已经有序直接结束程序
		for (int k = 0; k < Count - i - 1; k++)
		{
			if (SortC[k].CPP < SortC[k + 1].CPP)
			{
				swap(SortC[k], SortC[k + 1]);
				work = 0;
			}
		}
		if (work)
			break;
	}
}


//--------------------对数据的有效性判断-------------------
BOOL Management::IsSame(Student obj)
{
	for (int i = 0; i < Count; i++)
	{
		if (obj.Num == Pstu[i].Num)
			return FALSE;
	}
	return TRUE;
}

BOOL Management::Iscorrect(Student obj)
{
	if (!IsSame(obj))							//	对学号有效性判断
		return FALSE;
	if (obj.maths < 0 || obj.CPP < 0)	//	对成绩有效性判断
		return FALSE;
	else
		return TRUE;
}


//-------------------------统计数据------------------------

//	返回容器内人数
int Management::GetCount()
{
	return Count;
}

//	求和
double Management::GetSum(int ID)
{
	//	根据ID选择计算高数还是CPP的成绩
	//	求和
	double sum = 0;

	switch (ID)
	{
	case 0:	//	高数
		for (int i = 0; i < Count; i++)
			sum += Pstu[i].maths;
		break;

	case 1:	//	CPP
		for (int i = 0; i < Count; i++)
			sum += Pstu[i].CPP;
		break;

	default:
		break;
	}
	return sum;
}

//	求平均值
double Management::GetAver(int ID)
{
	return GetSum(ID) / Count;
}

//	求中位数
double Management::GetMedian(int ID)
{
	double Aver = GetAver(ID);	//	平均数

	switch (ID)
	{
	case 0:
		if (Count % 2 == 0)
			return (SortM[Count / 2].maths + SortM[Count / 2].maths) / 2;
		else
			return SortM[Count / 2 + 1].maths;
		break;
		
	case 1:
		if (Count % 2 == 0)
			return (SortC[Count / 2].CPP + SortC[Count / 2].CPP) / 2;
		else
			return SortC[Count / 2 + 1].CPP;
		break;

	default:
		return -1;
		break;
	}
}

//	求极差
double Management::GetRange(int ID)
{
	double max;
	double min;

	switch (ID)
	{
	case 0:
		max = SortM[0].maths;
		min = SortM[Count - 1].maths;
		return max - min;
		break;

	case 1:
		max = SortC[0].CPP;
		min = SortC[Count - 1].CPP;
		return max - min;
		break;

	default:
		return -1;
		break;
	}
}

//	求方差
double Management::GetVariance(int ID)
{
	double aver = GetAver(ID);	//	平均数
	double sum = 0;					//	和

	switch (ID)
	{
	case 0:
		for (int i = 0; i < Count; i++)
			sum += Pstu[i].maths - aver;
		return sum / Count;

	case 1:
		for (int i = 0; i < Count; i++)
			sum += Pstu[i].CPP - aver;
		return sum / Count;
		
	default:
		return -1;
	}
}