#pragma once
#include <iostream>
class Struct_function
{
public:
		
	Struct_function();// :m_pi(3.14) 
	Struct_function(int q);
	
	Struct_function(int q, const double m);//:m_pi(m),a(q)
	
	//Struct_function(const double q) :m_pi(q) {}
	~Struct_function();
	double get_pi();
private:
	const double m_pi;
	int a = 0;
};

