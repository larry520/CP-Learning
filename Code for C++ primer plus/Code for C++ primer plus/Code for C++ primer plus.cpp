// Code for C++ primer plus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
void struct_use();
void pt_use();

int main()
{
    std::cout << "Hello World!\n"; 
	//pt_use();
	//struct_use();
	return 0;
}


// 指针的使用
void pt_use()
{
	using namespace std;
	int qq = 100;
	int *p = &qq;
	int *pp = new int;
	cout << pp << endl << *pp << endl << &pp << endl;
	*pp = *pp + qq;
	cout << pp << endl << *pp << endl << &pp;
}

// 结构体使用及结构体指针
void struct_use()
{
	struct fruit   // 结构体定义
	{
		int apple;
		int orange;
		int cherry;
	};

	fruit fruitNo = { 6,5,2 };
	fruit *pt = &fruitNo;
	using namespace std;
	cout << "fruitNo member: " << endl
		<< "apple: " << fruitNo.apple << endl
		<< "orange: " << pt->orange << endl
		<< "cherry: " << pt->cherry << endl;

	struct years
	{
		int year;
	};
	years s01, s02, s03;
	s01.year = 1990;
	years *pa = &s02;
	pa->year = 1999;
}

void 

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
