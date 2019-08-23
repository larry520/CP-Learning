#include "pch.h"
// #include "Arry.h"
#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map> 
#include<fstream>
#include<sstream>
#include"word_search.h"
using namespace std;
//map<string, pair<int, map<size_t, string>>> read(ifstream &input);
//void serch_word(string &word, const  map<string, pair<int, map<size_t, string>>> & word_map);
void maint()
{
	ifstream input("E:\\cpp_data\\hello.txt");
	word_search wsearch;
	wsearch.read(input);
	while (true)
	{
		string word;
		if (!(cin >> word) || word == "q") break;	
		wsearch.serch(word);  // ��������ӡ���������
	}

}


// ���������ļ�����������
map<string, pair<int, map<size_t, string>>> read(ifstream &input)
{
	map<string,pair<int, map<size_t, string>>> word_map;
	string text;
	// ���ж�ȡ
	size_t line = 1;
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
	return word_map; 
}

void serch_word(string &word, const  map<string, pair<int, map<size_t, string>>> & word_map)
{
	auto iter = word_map.find(word);
	if (iter == word_map.end())
		cout << word << " is not in the file." << endl;
	else
		
		cout << "element '" << word << (iter->second.first > 1 ? "' occurs " : "occur ") << iter->second.first
		<< (iter->second.first > 1 ? " times in " : "time in ")
		<<iter->second.second.size()<< (iter->second.second.size() > 1 ? " lines:" : " line:") << endl;

	for (auto val : iter->second.second)
			cout << "line[" << val.first << "]: " << val.second << endl;
}







// �����뱾���뵽map����
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	 // getline ����ǰ������ȫȡ�����¸�ѭ���Զ�������һ�У���Ϊ��ǰ���Ѷ��꣩
	while (map_file >> key && getline(map_file, value))  
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1); // ����ǰ���ո񣬸����ļ���ʽ���壬�ı���key��valueͨ��1���ո�ֿ�
			// trans_map.insert({ key,value.substr(1) });
		else
			cout << "no rule for " + key;
			// throw runtime_error("no rule for " + key);

	}
	return trans_map;
}

//����ת��
const string& transform(const string&s, const map<string, string>&m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())       //m Ϊ��������м����룬���򷵻�ԭֵ
		return map_it->second;
	else
		return s;
}

// ��һ���ı����ݸ����ṩ�����뱾���з��벢���
void word_trandsform()
{
	fstream winput("E:\\cpp_data\\hello.txt", ios::out | ios::trunc);        //����ת���ı�������ļ��Ѵ��ڣ���ɾ���ļ�
	fstream wmap_file("E:\\cpp_data\\map_file.txt", ios::out | ios::trunc);  // �������뱾
	const char sinput[] = "w  u try l8r ?";   // ת���ı�����
	winput.write(sinput, strlen(sinput)); //
	const char smap_file[] = "w why\nu you\nl8r later"; // ���뱾����
	wmap_file.write(smap_file, strlen(smap_file));
	winput.close();
	wmap_file.close();

	ifstream input("E:\\cpp_data\\hello.txt");        //��ת���ı�
	ifstream map_file("E:\\cpp_data\\map_file.txt");  // �����뱾


	auto trans_map = buildMap(map_file);   // �����뱾ƥ�����ת����pair 
	string text;
	while (getline(input, text))   //����ת���ı�����text��
	{
		istringstream stream(text); // ������������� ��text�󶨵� stream�����Կո�Ϊ�ָ����ֿ�
		string word;
		bool firstword = true;   // �����ƻὫ�ո��ȡ�����ʱ���ӿո����
		while (stream >> word)   // ͨ��ѭ����stream�����е��ַ��� ��������word ��
		{
			if (firstword)       // �׸��ַ�ǰ������ո�
				firstword = false;
			else
				cout << " ";     // �����ַ�ǰ����ո�
			cout << transform(word, trans_map);  //ת���������������뱾�б�ִ��ת��
		}
		cout << endl;
	}
}

map<string, string> build_map(ifstream &m)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (m >> key && getline(m, value))
	{
		if (value.size() > 1)
			trans_map.insert({ key,value.substr(1) });
		else
			cout << "There is no rule for" + key;
	}

	return trans_map;
}

const string& trans_content(const string &word, const map<string, string> &tr)
{

	auto map_it = tr.find(word);
	if (map_it != tr.cend())
		return map_it->second;
	else
		return word;
}

// ��ȡ�����ļ����ݣ�������ת����map, �������ļ����з���
void file_convect(ifstream &input, ifstream &m)
{
	if (m.is_open()) {
		auto trans_map = build_map(m);
		if (input.is_open()) {
			string text;
			while (getline(input, text)) {
				istringstream stream(text);
				string word;
				bool firstword = true;
				while (stream >> word) {
					if (firstword)
						firstword = false;
					else {
						cout << " ";
					}
					cout << trans_content(word, trans_map);
				}
				cout << endl;
			}
		}
		else
			cout << "The input file isn't open!";
	}
	else
		cout << "The map file isn't open!";
}

// �ļ�����
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

// lambda ���ʽ
void  lambda_t()
{
	auto f = [](int a = 2, int b = 5) {return (a + b); };
	cout << f(3,6) << endl;
}

// map ��vector ����
void map_op()
{
	string sInput;
	//int iInput;
	//vector<pair<string,int>> vOutput;
	map<string, int>vOutput;
	cout << "Please input key,enter 'quit' for end: " << endl;
	int i = 0;
	while (cin >> sInput)
	{
		if (sInput == "quit")break;
		//vOutput.push_back(make_pair(sInput, 0));
		//vOutput.push_back(pair<string, int>{sInput, 0});
		//pair<string, int>p(sInput, 0); vOutput.push_back(p);
		vOutput.insert(make_pair(sInput, 0));
		i++;
	}
	cout << "Please input value,enter 'quit' for end:  " << endl;

	int j = 0;
	//while (cin >> iInput)
	//{
	//	if (j >( i - 1))
	//	{	
	//		cout << "Warning:the value numbers is bigger than key number!" << endl;
	//		cout << "You can't input value number more!" << endl;
	//		break;
	//	}
	//	vOutput[j].second = iInput;
	//	j++;
	//}
	for (auto key : vOutput)
	{
		cout << "key: " << key.first << " value: ";
		cin >> vOutput[key.first];
	}




	cout << "\nkey- value: \n" << endl;
	for (auto val : vOutput)
	{
		cout << "key: " << val.first << "  value:" << val.second << endl;
	}
}


