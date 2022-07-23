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

int Management::GetCount()
{
	return Count;
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

	//------------------使用冒泡排序---------------------
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

	//------------------使用冒泡排序---------------------
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
	if (!IsSame(obj))							//对学号有效性判断
		return FALSE;
	if (obj.maths < 0 || obj.CPP < 0)//对成绩有效性判断
		return FALSE;
	else
		return TRUE;
}