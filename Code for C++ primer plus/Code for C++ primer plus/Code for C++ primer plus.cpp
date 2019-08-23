// use for c++ learning

#include "pch.h"
#include "LearnSkills.h"
#include <iostream>
#include <string>
#include <vector>
#include "SerialPort.h"
#include<windows.h>
#include"Stock.h"
#include"Sales_data.h" 
#include<algorithm>
#include<numeric>
#include"Worker.h"

using namespace std;



int main()
{
    std::cout << "Hello World!\n"; 
	using namespace std;
	
	Worker worker;
	worker.work();
	worker.m_iAge = 18;

	//generic_algorithm();
	//pt_use();
	//struct_use();
	//string_test();
	//vetcor_type();
	//serail_test(1);
	//exception_test();
	//fact();
	//class_t2();
	//sale_book();

	return 0;
}
//对象指针 
// Coordinate *p = new Coordinate();
// p->m_iX = 10; // (*p).m_iX = 10;    指针使用时采用（*p）为一个指针对象，可直接访问成员。
// p->m_iY = 20; // (*p).m_iY = 20;
// delete p;
// p = NULL;
// ------------this 指针------------------------
// this 指针为对本身对象的引用  指针与引用实质上都是指向地址





