#pragma once
#ifndef Sales_data_H_
#define Sales_data_H_

#include"pch.h"
#include<string>

class Sales_data
{
private:
	std::string serialNo;
	int count;
	double price;

public:
	Sales_data();
	virtual ~Sales_data();
	Sales_data(const std::string & isb, int n=0, double p=0.0);
	void isbn();
	void combine(Sales_data s1);
	void read();
	void print();
};

#endif
