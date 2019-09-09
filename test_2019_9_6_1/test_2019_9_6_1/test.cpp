#include <iostream>
using namespace std;

#include <string>
#if 0
int main()
{
	string s1;
	string s2("hello");
	string s3(10, 'a'); 
	string s4(s2);//��������
	//string��֧��C++��׼���������
	cin >> s1;
	cout << s1 << endl;

	for (auto e : s2)//������ʽ����Χfor
		cout << e << " ";//e��ʾs2�ַ�����ÿ���ַ�
	cout << endl;

	for (size_t i = 0; i < s3.size(); ++i)
		cout << s3[i];
	cout << endl;

	//�������ķ�ʽ������
	//������������ָ��
	//string::iterator it = s4.begin();
	auto it = s4.begin();
	while (it != s4.end())//string:[begin,end)--->begin�����������ַ���λ��
		//end�������һ����Ч�ַ�����һ��λ��
	{
		cout << *it;
		++it;
	}
	cout << endl;

	return 0;
}
#endif
#if 0
//capacity���
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.clear();//���
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
//void resize(size_t n,char ch)��string������Ч�ַ��ı䵽n���������λ�ò���ch���
//void resize(size_t n)��string������Ч�ַ��ı䵽n���������λ�ò���0���
//resize:�ı�string����ЧԪ�ظ���
//����Ч�ַ��������ൽn�����ദ��λ����Ҫch��䣨������Ҫ���ݣ�
//����Ч�ַ��������ٵ�n����ֻ�޸���Ч�ַ�������������С�ռ�
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//������Ч�ַ�����
	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '$');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//������ЧԪ�ظ���
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
//void reserve(size_t n):�ı�ײ������Ĵ�С�������޸���ЧԪ�صĸ���
//����������n<=�ɿռ��С������ı�������n>�ɿռ��С������
//��С������n>15,������С��n<=15,��С����
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
	//reserveû�иı���ЧԪ�ظ�������ʱֻ��0���ַ���û������s2[0]
	return 0;
}
#endif
#if 0
//reverse��ת
int main()
{
	string s("hello");
	cout << s << endl;

	reverse(s.begin(),s.end());//������Χ
	cout << s << endl;
	return 0;
}
#endif
#if 0
//ƴ��
int main()
{
	string s1;
	s1 += 'I';

	string s2("love");
	s1 += s2;

	s1 += "China";
	cout << s1 << endl;
	string s3("too");
	s1.append(s3);//��s3ƴ�ӵ�s1
	s1.append("!!!!!!!!!");
	return 0;
}
#endif
#if 0
int main()
{
	string s;
	for (size_t i = 0; i < 100; ++i)
		s.push_back('$');//���ϵ������ˣ��ɱ��Ƚϴ�
	return 0;
}
#endif
#if 0
void Test()
{
	string s;
	s.reserve(100);//ֱ�ӽ��������ã�����Ч�ʱȽϸ�
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
	s.insert(1, "aaa");//��ʾ�ڵ�һ���ַ������aaa
	cout << s << endl;
	return 0;
}
#endif
#if 0
int main()
{
	string s("hello world");
	s.erase(s.begin() + s.find(' '), s.end());//��ָ���ַ������ɾ��
	return 0;
}
#endif
#if 0
int main()
{
	string s("111.txt");//��ô�õ��ļ��ĺ�׺
	string ret=s.substr(s.rfind('.'));//rfindʵ�ֵĹ����ǴӺ���ǰ�ҵ�'.'����ȡ'.'���������
	//substrʵ�ֵĹ����Ǵ�ĳ��λ�ÿ�ʼ��ȡ
	cout << ret << endl;

	string strRet("https://www.baidu.com/s?wd=retriev");//Ҫ��ȡwww.baidu.com
	size_t start=strRet.find("://");
	if (start != string::npos)
		cout << "is in" << endl;
	else
		cout << "is not in" << endl;
	start += 3;
	size_t finish = strRet.find('/', start);//��start��ʼ�ҵ�'/'��λ�ã��õ�finish���ַ�
	ret = strRet.substr(start, finish - start);//��start��ʼ��ȡfinish-start���ַ�
	cout << ret << endl;
	return 0;
}
#endif
#if 0
//�ַ����������һ�����ʵĳ���

int main()
{
	string s;
	getline(cin, s);//�����ַ�����������cin,��Ϊ�����ո��ֹͣ��
	cout<<s.substr(s.rfind(' ') + 1).size() << endl;
	return 0;
}
#endif
#if 0
int main()
{
	string s;
	while (getline(cin, s))//�е�ѭ������
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
	string s2("Hello");//�Ƚϴ�С
	if (s1 > s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;
	return 0;
}
#endif
#if 0
//Ѱ���ַ����е�һ��ֻ����һ�ε��ַ�,�����±�
class S
{
public:
	S(const char* c)//���캯��
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
#if 0
//��ת�ַ���
class S
{
public:
	S(const char* c)
	:s(c)
	{}
	string reverseString()
	{
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
private:
	string s;
};
int main()
{
	S s1("hello");
	string s2=s1.reverseString();
	cout << s2;
	cout << endl;
	return 0;
}
#endif 
#if 0
//�ж�һ���ַ����Ƿ��ǻ��ģ�ֻҪ���ֻ�����ĸ�������ַ�����
class S
{
public:
	S(const char* c)
		:s(c)
	{}
	bool LetterOrNumber(char ch)
	{
		return (ch >= '0'&&ch <= '9')
			|| (ch >= 'a'&&ch <= 'z')
			|| (ch >= 'A'&&ch <= 'Z');
	}
	bool isPalindrome()
	{
		for (auto& ch : s)//��Сд��ĸת��Ϊ��д
		{
			if (ch >= 'a'&&ch <= 'z')
				ch -= 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end&&!LetterOrNumber(s[begin]))
			{
				++begin;
			}
			while (begin < end&&!LetterOrNumber(s[end]))
			{
				--end;
			}
			if (s[begin] != s[end])
				return false;
			else
			{
				++begin;
				--end;
			}
		}
		return true;
	}
private:
	string s;
};
int main()
{
	S s1("a bba cddc");
	if (s1.isPalindrome() == true)
		cout << "�ǻ���" << endl;
	else
		cout << "���ǻ���" << endl;
	system("pause");
	return 0;
}
#endif
//���������ַ�����ʽ�ķǸ����� num1 ��num2���������ǵĺ�
class Solution
{
public:
	Solution(const char* c1, const char* c2)
		: num1(c1)
		, num2(c2)
	{}
	string addStrings()
	{
		int Lsize = num1.size();
		int Rsize = num2.size();
		if (Lsize<Rsize)//��֤����������Ҳ�����λ����
		{
			num1.swap(num2);
			swap(Lsize, Rsize);
		}
		char step = 0;//��ʾ��λ
		string strRet(Lsize + 1, '0');//���Ӧ�ñȳ��������������һλ
		//��num1���ַ�������Ϊѭ������
		for (int idxL = Lsize - 1, idxR = Rsize - 1; idxL >= 0; --idxL, --idxR)
		{

			char cRet = num1[idxL] - '0' + step;
			//ÿһλ����ӣ��������ַ���ת��Ϊ���֣�������ܳ���10����Ҫ��λ
			if (idxR >= 0)
				cRet += num2[idxR] - '0';
			step = 0;//����һ�ν�λ��0
			if (cRet >= 10)
			{
				step = 1;
				cRet -= 10;
			}
			strRet[idxL + 1] += cRet;//���λ����cRet     
		}
		if (step == 1)//������һ��Ҫ��λ
			strRet[0] += 1;
		else//����ɾ�����������һλ
			strRet.erase(strRet.begin());
		return strRet;
	}
private:
	string num1;
	string num2;
};
int main()
{
	Solution s1("111", "33");
	string ret = s1.addStrings();
	for (size_t i = 0; i < ret.size(); ++i)
	{
		cout << ret[i];
	}
	cout << endl;
	system("pause");
	return 0;
}