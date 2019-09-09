#include "String.h"
void Test1()
{
	String s1;
	String s2("hello");
	String s3(s2);
	s1 = s3;
	s1[0] = 'w';
	s1.swap(s2);
}
void Test2()
{
	String s1("helloworld");
	s1.Pushback('!');
	s1.Pushback('&');
	s1.append(1, 'i');
	s1 += 'u';
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	s1.Popback();
	s1.Pushfront('a');
	s1.Popfront();
	s1.Pushfront("you");
	s1.insert(3, ',');
	s1.insert(5, "hako");
	s1.erase(4, 5);
	cout << s1 << endl;
	size_t ret = s1.find('h');
	cout << ret << endl;
	ret = s1.find("haho");
	cout << ret << endl;
}
void Test3()
{
	String s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
void Test4()
{
	String s1("hello worl");
	String s2 = s1 + 'd';
	String s3 = s1 + "haha";
	s1 += 'd';
	s1 += "haha";
}
void Test5()
{
	String s1("hello");
	String s2("hello");
	if (s1 == s2)
		cout << "ПаµИ" << endl;
	s1 = "Hello";
	if (s2 > s1)
		cout << "s2>s1" << endl;
}
int main()
{
	//Test1();
	Test2();
	//Test3();
	//Test4();
	//Test5();
	return 0;
}