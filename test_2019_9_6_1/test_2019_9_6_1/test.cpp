#include <iostream>
using namespace std;

#include <string>
#if 0
int main()
{
	string s1;
	string s2("hello");
	string s3(10, 'a'); 
	string s4(s2);//拷贝构造
	//string类支持C++标准的输入输出
	cin >> s1;
	cout << s1 << endl;

	for (auto e : s2)//遍历方式：范围for
		cout << e << " ";//e表示s2字符串中每个字符
	cout << endl;

	for (size_t i = 0; i < s3.size(); ++i)
		cout << s3[i];
	cout << endl;

	//迭代器的方式来遍历
	//迭代器当成是指针
	//string::iterator it = s4.begin();
	auto it = s4.begin();
	while (it != s4.end())//string:[begin,end)--->begin代表的是首字符的位置
		//end代表最后一个有效字符的下一个位置
	{
		cout << *it;
		++it;
	}
	cout << endl;

	return 0;
}
#endif
#if 0
//capacity相关
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.clear();//清空
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	if (s.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
	}
	
	return 0;
}
#endif
#if 0
//void resize(size_t n,char ch)将string类中有效字符改变到n个，多出的位置采用ch填充
//void resize(size_t n)将string类中有效字符改变到n个，多出的位置采用0填充
//resize:改变string中有效元素个数
//将有效字符个数增多到n个：多处的位置需要ch填充（可能需要扩容）
//讲有效字符个数减少到n个：只修改有效字符个数，不会缩小空间
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//扩增有效字符个数
	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '$');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//减少有效元素个数
	s.resize(18);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}
#endif
#if 0
//void reserve(size_t n):改变底层容量的大小，不会修改有效元素的个数
//扩大容量：n<=旧空间大小，不会改变容量；n>旧空间大小，扩容
//缩小容量：n>15,不会缩小，n<=15,缩小容量
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(80);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(60);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}
#endif
#if 0
int main()
{
	string s1;
	s1.resize(10,'$');
	s1[0] = '%';

	string s2;
	s2.reserve(10);
	s2[0] = '%';
	//reserve没有改变有效元素个数，这时只有0个字符，没法访问s2[0]
	return 0;
}
#endif
#if 0
//reverse逆转
int main()
{
	string s("hello");
	cout << s << endl;

	reverse(s.begin(),s.end());//给出范围
	cout << s << endl;
	return 0;
}
#endif
#if 0
//拼接
int main()
{
	string s1;
	s1 += 'I';

	string s2("love");
	s1 += s2;

	s1 += "China";
	cout << s1 << endl;
	string s3("too");
	s1.append(s3);//把s3拼接到s1
	s1.append("!!!!!!!!!");
	return 0;
}
#endif
#if 0
int main()
{
	string s;
	for (size_t i = 0; i < 100; ++i)
		s.push_back('$');//不断地扩容了，成本比较大
	return 0;
}
#endif
#if 0
void Test()
{
	string s;
	s.reserve(100);//直接将容量扩好，这样效率比较高
	size_t sz = s.capacity();
	cout << "s grow" << endl;
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('%');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed" << endl;
		}
	}
}
int main()
{
	Test();
	return 0;
}
#endif
#if 0
int main()
{
	string s("hello");
	s.insert(1, "aaa");//表示在第一个字符后加上aaa
	cout << s << endl;
	return 0;
}
#endif
#if 0
int main()
{
	string s("hello world");
	s.erase(s.begin() + s.find(' '), s.end());//将指定字符后面的删除
	return 0;
}
#endif
#if 0
int main()
{
	string s("111.txt");//怎么拿到文件的后缀
	string ret=s.substr(s.rfind('.'));//rfind实现的功能是从后往前找到'.'，截取'.'后面的内容
	//substr实现的功能是从某个位置开始截取
	cout << ret << endl;

	string strRet("https://www.baidu.com/s?wd=retriev");//要截取www.baidu.com
	size_t start=strRet.find("://");
	if (start != string::npos)
		cout << "is in" << endl;
	else
		cout << "is not in" << endl;
	start += 3;
	size_t finish = strRet.find('/', start);//从start开始找到'/'的位置，得到finish个字符
	ret = strRet.substr(start, finish - start);//从start开始截取finish-start个字符
	cout << ret << endl;
	return 0;
}
#endif
#if 0
//字符串里面最后一个单词的长度

int main()
{
	string s;
	getline(cin, s);//输入字符串，不能用cin,因为遇到空格就停止了
	cout<<s.substr(s.rfind(' ') + 1).size() << endl;
	return 0;
}
#endif
#if 0
int main()
{
	string s;
	while (getline(cin, s))//行的循环输入
	{
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
	return 0;
}
#endif
#if 0
int main()
{
	string s1("hello");
	string s2("Hello");//比较大小
	if (s1 > s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;
	return 0;
}
#endif
#if 1
//寻找字符串中第一个只出现一次的字符,返回下标
class S
{
public:
	S(const char* c)//构造函数
	:s (c)
	{}
	int FirstUniqChar()
	{
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			count[s[i]] += 1;
		}
		for (int i = 0; i < size; ++i)
		{
			if (1 == count[s[i]])
				return i;
		}
		return -1;
	}
private:
	string s;
};
int main()
{
	S s1("aaacvccbnnmj");
	int ret=s1.FirstUniqChar();
	cout << ret << endl;
	return 0;
}
#endif
