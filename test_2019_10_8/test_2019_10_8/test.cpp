#include <iostream>
using namespace std;
#include <map>
#include <string>
#if 0
int main()
{
	map<string, string> m;
	//C++98
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(make_pair("orange", "橘子"));
	m.insert(make_pair("banana", "香蕉"));
	m.insert(make_pair("peach", "桃子"));
	m.insert(make_pair("apple","pingguo"));//相同key值的无法插入
	cout << m["peach"] << endl;
	cout << m["straberry"] << endl;//打印的是空的字符串
	//当[]中的key在map中不存在的情况下，
	//map将<key,默认value>构成一个键值对插入到map中，返回默认value
	cout << m.size() << endl;//5个键值对

	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	m.erase("peach");//删除，括号中是迭代器类型，相当于key

	if ((m.find("peach")) != m.end())//end是左闭右开的，表示没有元素
	{
		cout << "存在" << endl;
	}
	else
		cout << "不存在" << endl;

	map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	auto rit = m.rbegin();
	while (rit != m.rend())//反向迭代器
	{
		cout << rit->first << "--->" << rit->second << endl;
		++rit;
	}
	cout << endl;
	for (auto e : m)
		cout << e.first <<"---->"<< e.second << endl;
	return 0;
}
#endif
#if 0
int main()
{
	multimap<string, string> m;
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(make_pair("orange", "橘子"));
	m.insert(make_pair("banana", "香蕉"));
	m.insert(make_pair("peach", "桃子"));
	m.insert(make_pair("apple", "pingguo"));
	//cout << m["peach"] << endl;//无法使用下表运算符，因为key值可以重复，无法具体访问
	cout << m.size() << endl;
	cout << m.count("apple");//这时就是2，因为有两个key为apple的

	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	m.erase("peach");//删除，括号中是迭代器类型，相当于key

	if ((m.find("peach")) != m.end())//end是左闭右开的，表示没有元素
	{
		cout << "存在" << endl;
	}
	else
		cout << "不存在" << endl;

	multimap<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	auto rit = m.rbegin();
	while (rit != m.rend())//反向迭代器
	{
		cout << rit->first << "--->" << rit->second << endl;
		++rit;
	}
	cout << endl;
	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	m.clear();//清空
	return 0;
}
#endif
#include <set>
#if 0
int main()
{
	int array[] = { 4, 4, 3, 3, 0, 0, 9, 9, 1, 1, 3, 3, 2, 2, 5, 5, 8, 8, 6, 6, 7, 7 };
	set<int> s;
	for (auto e : array)
		s.insert(e);//0,1,2,3,4,5,6,7,8,9,所以set也有去除重复的作用
	cout << s.size() << endl;
	if (s.find(3) != s.end())
		cout << "3 is in set" << endl;
	else
		cout << "3 is not in set" << endl;
	s.erase(3);
	cout << s.count(3) << endl;
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}
#endif
#if 0
int main()
{
	int array[] = { 4, 4, 3, 3, 0, 0, 9, 9, 1, 1, 3, 3, 2, 2, 5, 5, 8, 8, 6, 6, 7, 7 };
	multiset<int> s;
	for (auto e : array)
		s.insert(e);//0,1,2,3,4,5,6,7,8,9,所以set也有去除重复的作用
	cout << s.size() << endl;//multiset可以存在重复的元素
	cout << s.count(3) << endl;
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}
#endif
