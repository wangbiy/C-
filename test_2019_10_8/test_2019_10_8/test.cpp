#include <iostream>
using namespace std;
#include <map>
#include <string>
#if 0
int main()
{
	map<string, string> m;
	//C++98
	m.insert(pair<string, string>("apple", "ƻ��"));
	m.insert(make_pair("orange", "����"));
	m.insert(make_pair("banana", "�㽶"));
	m.insert(make_pair("peach", "����"));
	m.insert(make_pair("apple","pingguo"));//��ͬkeyֵ���޷�����
	cout << m["peach"] << endl;
	cout << m["straberry"] << endl;//��ӡ���ǿյ��ַ���
	//��[]�е�key��map�в����ڵ�����£�
	//map��<key,Ĭ��value>����һ����ֵ�Բ��뵽map�У�����Ĭ��value
	cout << m.size() << endl;//5����ֵ��

	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	m.erase("peach");//ɾ�����������ǵ��������ͣ��൱��key

	if ((m.find("peach")) != m.end())//end������ҿ��ģ���ʾû��Ԫ��
	{
		cout << "����" << endl;
	}
	else
		cout << "������" << endl;

	map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	auto rit = m.rbegin();
	while (rit != m.rend())//���������
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
	m.insert(pair<string, string>("apple", "ƻ��"));
	m.insert(make_pair("orange", "����"));
	m.insert(make_pair("banana", "�㽶"));
	m.insert(make_pair("peach", "����"));
	m.insert(make_pair("apple", "pingguo"));
	//cout << m["peach"] << endl;//�޷�ʹ���±����������Ϊkeyֵ�����ظ����޷��������
	cout << m.size() << endl;
	cout << m.count("apple");//��ʱ����2����Ϊ������keyΪapple��

	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	m.erase("peach");//ɾ�����������ǵ��������ͣ��൱��key

	if ((m.find("peach")) != m.end())//end������ҿ��ģ���ʾû��Ԫ��
	{
		cout << "����" << endl;
	}
	else
		cout << "������" << endl;

	multimap<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	auto rit = m.rbegin();
	while (rit != m.rend())//���������
	{
		cout << rit->first << "--->" << rit->second << endl;
		++rit;
	}
	cout << endl;
	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	m.clear();//���
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
		s.insert(e);//0,1,2,3,4,5,6,7,8,9,����setҲ��ȥ���ظ�������
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
		s.insert(e);//0,1,2,3,4,5,6,7,8,9,����setҲ��ȥ���ظ�������
	cout << s.size() << endl;//multiset���Դ����ظ���Ԫ��
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
