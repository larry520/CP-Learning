#include "pch.h"
#include "word_search.h"
#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map> 
#include<fstream>
#include <sstream>

using namespace std;

word_search::word_search()
{
	map<string, pair<int, map<size_t, string>>> word_map;
}


word_search::~word_search()
{
}


// 根据输入文件建立索引库
void word_search::read(ifstream &input)
{
	
	// 逐行读取
	size_t line = 1;
	string text;
	while (getline(input, text))
	{
		istringstream stream(text); // 输入输出控制类 将text绑定到 stream对象，以空格为分隔符分开
		string word;
		bool firstword = true;   // 流控制会将空格截取，输出时增加空格控制
		while (stream >> word)   // 通过循环将stream对象中的字符串 逐个输出到word 中
		{
			word_map[word].second.insert({ line,text }); // 将每行出现的word 存到word_map的键值中，第一次出现则新建一个
			word_map[word].first++;  // 计算每个单词出现次数
		}
		line++;
	}
}

void word_search::serch(string &word)
{
	auto iter = word_map.find(word);
	if (iter == word_map.end())
		cout << word << " is not in the file." << endl;
	else

		cout << "element '" << word << (iter->second.first > 1 ? "' occurs " : "occur ") << iter->second.first
		<< (iter->second.first > 1 ? " times in " : "time in ")
		<< iter->second.second.size() << (iter->second.second.size() > 1 ? " lines:" : " line:") << endl;

	for (auto val : iter->second.second)
		cout << "line[" << val.first << "]: " << val.second << endl;
}