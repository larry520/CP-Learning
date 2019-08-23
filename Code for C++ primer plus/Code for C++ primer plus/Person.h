#pragma once
#include<string>
using namespace std;

class Person
{
public:
	Person();
	~Person();
	
protected:	
	void eat();

	string m_strName;
	int m_iAge;

};

