#include "pch.h"
// #include "Arry.h"
#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

int main()
{
	//vector<const char*> articles = { "c", "dn", "the" };
	//vector<string> words(articles.begin(), articles.end());
	//auto p = words.begin();
	//while (p != words.end())
	//{	
	//	cout<< *p << endl;
	//	++p;
	//}
/*
	list<const char*> pp = { articles.at(0),articles.at(1),articles.at(2) };
	auto p = pp.begin();
	int i = 0;
	while (i<3)
	{	
		
		cout <<"h: "<< *p << endl;
		++i;
		++p;
	}*/

	int qqt { 121};
	cout << qqt << endl;

}






// ÎÄ¼þ²Ù×÷
void file_option() 
{
	FILE * pFile;
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL)
	{
		fputs("fopen example", pFile);
		fclose(pFile);
	}
}