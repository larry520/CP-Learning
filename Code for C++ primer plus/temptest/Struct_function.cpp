#include "pch.h"
#include "Struct_function.h"
#include <iostream>


Struct_function::Struct_function():m_pi(0)// 常量的初始化赋值只能通过初始化列表实现
{
	std::cout << "test 001" << std::endl;
}

Struct_function::Struct_function(int q,const double m ):m_pi(m),a(q)
{
	std::cout << "test 002" << std::endl;
}
Struct_function::Struct_function(int q):m_pi(1)
{
	a = q;
	std::cout << "test 003" << std::endl;
}


double Struct_function::get_pi()
{
	std::cout <<"Pi: "<< m_pi << "  a:" << a << "\n";
	return m_pi;
}

Struct_function::~Struct_function()
{
}
