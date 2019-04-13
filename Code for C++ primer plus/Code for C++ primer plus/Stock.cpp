#include "pch.h"
#include<iostream>
#include"Stock.h"


Stock::Stock() //delfault constructor
{
	std::cout << "Delfault constructor called \n";
	company = "no name"; 
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	company = co;

	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << "shares set to 0. \n";
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();	
}

// class destructor
Stock::~Stock() {   //verbose class destructor
	std::cout << "Bye, " << company << " !\n";
}

// other methods
void Stock::buy(long num, double price)
{
	if (num < 0) 
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted. \n";

	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
		std::cout << "Number of shares sold can't be negative. "
		<< "Transaction is aborted. \n";
	else if(num > shares)
	{
		std::cout << "You can't sell more than you have! "
			<< "Transaction is aborted. \n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}

}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::ios_base;
	//set format to #.###
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout << "Company: " << company << "Shares: " << shares << std::endl;
	cout << "Share Price : $" << share_val;
	// set fomat to #.##
	cout.precision(2);
	cout << "  Total Worth: $" << total_val << "\n";
	// restore original format
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

}