#pragma once
#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map> 
#include<fstream>
#include <sstream>

using namespace std;
class word_search
{
public:
	word_search();
	~word_search();
	void read(ifstream &input);
	void serch(string &word);
private:	
	map<string, pair<int, map<size_t, string>>> word_map;
};

