#include "pch.h"
#include "Arry.h"
#include<iostream>
using namespace std;

Arry::Arry(int m_ilen)
{
	m_iLen = m_ilen;
	cout << "Arry(int m_iLen)" << endl;
}


Arry::~Arry()
{
}

int Arry::get() const
{
	return m_iLen;
}
void Arry::setLen(int m_ilen)
{
	m_iLen = m_ilen;
}

void Arry::printInfo()
{
	cout <<"Len= "<< m_iLen << endl;
}