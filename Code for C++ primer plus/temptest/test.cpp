
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void fun(int &a, int &b);

int main()
{
	cout << "welcome to my world!" << endl;
	int x = 2;
	int y = 3; 
	fun(x, y);
	cout << x<<endl<< y;


	
}

void fun(int &a, int &b)
{
	a = 10;
	b = 20;
}

// ±éÀú
void loop()
{
	vector<int> vec_int(10, 6);
	for (auto key : vec_int)
	{
		cout << key << endl;
	}
}
// ¼Ì³Ð
