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


// ���������ļ�����������
void word_search::read(ifstream &input)
{
	
	// ���ж�ȡ
	size_t line = 1;
	string text;
	while (getline(input, text))
	{
		istringstream stream(text); // ������������� ��text�󶨵� stream�����Կո�Ϊ�ָ����ֿ�
		string word;
		bool firstword = true;   // �����ƻὫ�ո��ȡ�����ʱ���ӿո����
		while (stream >> word)   // ͨ��ѭ����stream�����е��ַ��� ��������word ��
		{
			word_map[word].second.insert({ line,text }); // ��ÿ�г��ֵ�word �浽word_map�ļ�ֵ�У���һ�γ������½�һ��
			word_map[word].first++;  // ����ÿ�����ʳ��ִ���
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