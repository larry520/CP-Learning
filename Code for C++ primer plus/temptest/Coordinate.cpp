#include "pch.h"
#include "Coordinate.h"
#include<iostream>
using namespace std;


Coordinate::Coordinate()
{
	cout << "Coordinate()" << endl;
}


Coordinate::~Coordinate()
{
	cout << "~Coordinate()" << endl;
}


//Coordinate p1[2];
//Coordinate *p2 = &p1[1];
//p1[0].m_iX = 10;
//p1[0].m_iY = 20;
//(*p2).m_iX = 11;
//(*p2).m_iY = 22;
//cout << p1[0].m_iX + (*p2).m_iX << endl;
//cout << p1[0].m_iX + p2->m_iY << endl;
//cout << p1[1].m_iX << endl;