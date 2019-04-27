#include "pch.h"
#include "Sales_data.h"
#include <iostream>


Sales_data::Sales_data()
{	
	serialNo = "None";
	count = 0;
	price = 0.0;
}


Sales_data::~Sales_data()
{
	std::cout << "Bye bye " << serialNo << "\n"; 
}


Sales_data::Sales_data(const std::string & isb, int n , double p )
{
	std::cout << "Constructor using " << isb << " called\n";
	serialNo = isb;
	if (n < 0)
	{
		std::cout << "Book No. can't be negative! "
			<< "Transaction is aborted. \n";
	}
	else if( p<0)
	{
		std::cout << "Book No. can't be negative! "
			<< "Transaction is aborted. \n";
	}
	else
	{
		count = n;
		price = p;
	}
}

void Sales_data::isbn()
{
	std::cout << "ISBN: " << serialNo << "\n";
}

// add s1 to s2
void Sales_data::combine(Sales_data s1)  
{
	if (serialNo != s1.serialNo)
	{
		std::cout << "You can't combine two different books! \n Book1: "
			<< serialNo << "  Book2: " << s1.serialNo << "\n";
	}
	else
	{
		count += s1.count;
		std::cout << "Now " << serialNo << "Book No. is" << count << "\n";
	}
}

void Sales_data::read()
{
	std::cout << "Plsease input Book data: \n";
	std::cin >> serialNo>>count>>price;
}

void Sales_data::print()
{
	std::cout << "Book ISBN: " << serialNo << " Count: " << count
		<< " Price: " << price << "\n";
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}