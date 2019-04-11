#pragma once
#ifndef Stock_H_
#define Stock_H_
#include<string>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void cal_tot() {
		total_val = shares * share_val;
	}

public:
	Stock();
	Stock
	~Stock();
	void buy(std::string &co, long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};

#endif // !Stock_H_