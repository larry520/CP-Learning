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
		wsearch.serch(word);  // 搜索并打印搜索结果；
	}

}


// 根据输入文件建立索引库
map<string, pair<int, map<size_t, string>>> read(ifstream &input)
{
	map<string,pair<int, map<size_t, string>>> word_map;
	string text;
	// 逐行读取
	size_t line = 1;
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







// 将密码本输入到map容器
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	 // getline 将当前行数据全取出，下个循环自动调到下一行（因为当前行已读完）
	while (map_file >> key && getline(map_file, value))  
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1); // 跳过前导空格，根据文件格式定义，文本中key与value通过1个空格分开
			// trans_map.insert({ key,value.substr(1) });
		else
			cout << "no rule for " + key;
			// throw runtime_error("no rule for " + key);

	}
	return trans_map;
}

//内容转换
const string& transform(const string&s, const map<string, string>&m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())       //m 为翻译规则，有即翻译，无则返回原值
		return map_it->second;
	else
		return s;
}

// 将一个文本内容根据提供的密码本进行翻译并输出
void word_trandsform()
{
	fstream winput("E:\\cpp_data\\hello.txt", ios::out | ios::trunc);        //创建转换文本，如果文件已存在，先删除文件
	fstream wmap_file("E:\\cpp_data\\map_file.txt", ios::out | ios::trunc);  // 创建密码本
	const char sinput[] = "w  u try l8r ?";   // 转换文本内容
	winput.write(sinput, strlen(sinput)); //
	const char smap_file[] = "w why\nu you\nl8r later"; // 密码本内容
	wmap_file.write(smap_file, strlen(smap_file));
	winput.close();
	wmap_file.close();

	ifstream input("E:\\cpp_data\\hello.txt");        //打开转换文本
	ifstream map_file("E:\\cpp_data\\map_file.txt");  // 打开密码本


	auto trans_map = buildMap(map_file);   // 将密码本匹配规则转换成pair 
	string text;
	while (getline(input, text))   //将待转换文本存入text中
	{
		istringstream stream(text); // 输入输出控制类 将text绑定到 stream对象，以空格为分隔符分开
		string word;
		bool firstword = true;   // 流控制会将空格截取，输出时增加空格控制
		while (stream >> word)   // 通过循环将stream对象中的字符串 逐个输出到word 中
		{
			if (firstword)       // 首个字符前不插入空格
				firstword = false;
			else
				cout << " ";     // 后续字符前插入空格
			cout << transform(word, trans_map);  //转换输出，如果在密码本中便执行转换
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

// 获取两个文件内容，将内容转换成map, 对输入文件进行翻译
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

// 文件操作
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

// lambda 表达式
void  lambda_t()
{
	auto f = [](int a = 2, int b = 5) {return (a + b); };
	cout << f(3,6) << endl;
}

// map 与vector 操作
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


