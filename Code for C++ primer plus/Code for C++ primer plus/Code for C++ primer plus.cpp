// use for c++ learning

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "SerialPort.h"

using namespace std;
void struct_use();
void pt_use();
void quote();
void string_test();
void vetcor_type();

int main()
{
    std::cout << "Hello World!\n"; 
	using namespace std;

	//pt_use();
	//struct_use();
	//string_test();
	//vetcor_type();
	
	return 0;
}

// 串口操作
int _tmain(int argc, _TCHAR* argv[])
{

	CSerialPort mySerialPort;

	if (!mySerialPort.InitPort(2))
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}

	if (!mySerialPort.OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}

	int temp;
	std::cin >> temp;

	return 0;
}

//vector 类型的使用
void vetcor_type()
{
	using std::vector;
	vector<int> ivec1{ 666 };						// 创建1个元素，初始值为666
	vector<int> ivec2(10, 1);						//创建10个元素，初始值为1
	cout << ivec2[3] << endl << ivec1[0] << endl;
	
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin>>grade)
	{
		if (grade <= 100) 
		{  
			// 统计各分数段的数量，并存在scores里面。
			++scores[grade / 10];
			cout << grade / 10 << endl;
		}	
	}
	// 输出各分数段的数量
	cout << "The scores destribution are:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout <<i*10<<" ~ "<<(i+1)*10<<": "<< scores[i] << endl;
	}
	cout << " 100 ： " << scores[10] << endl;
}

// String option   使用string需要#include<string> 头文件，以及 using std::string两行代码。
void string_test()
{
	
	using std::string;
	string s1= "hey ha! ";
	string s2 = "good";
	string s3("job!");
	string	&s4 = s1;
	string	s5(6, '6');
	cout << s4 << " " << s2 << " " << s3 <<endl<< s5 << endl;
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
	years s01, s02;
	s01.year = 1990;
	years *pa = &s02;
	pa->year = 1999;
	cout << "I Love C++, that's a prefect program language! \n";
}

//引用，即和引用变量指向同一地址。两个变量同时作用于该地址存储值
void quote()
{
	int j0 = 1;
	int i = j0;
	int &k = i;
	j0 = 2;
	std::cout << k << std::endl;
}












// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件