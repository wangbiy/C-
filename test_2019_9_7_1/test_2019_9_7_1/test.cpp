#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
namespace bite
{
	class string
	{
	public:
		string();
		string(const char* str = "")
		{
			/*
			if (nullptr == str)
			{
				_str = new char[1];
				*_str = '\0';	
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
			*/
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

	private:
		char* _str;//��̬�ռ�
	};
}
int main()
{
	bite::string s1("hello");
	bite::string s2(nullptr);
	//bite::string s3(s1);
	//�������캯��û����ʽ���壬�������Զ�����һ����
	//����s3��s1����һ��ռ䣬����ͷ�ʱ���ͷ�s3��
	//Ȼ��s1���ͷ���һ�Σ�һ��ռ䱻�ͷ������Σ������ǳ����
	//s2 = s1;//������������Ĭ�ϵĸ�ֵ��������أ�Ҳ�ᷢ��ǳ����
	return 0;
}
#endif
#if 0
#include <string.h>
//���---��ͳ��ʽ
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
		//���������ÿ�����������Դ
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				//delete[]_str;//��ԭ���Ŀռ��ͷ�
				//_str = new char[strlen(s._str) + 1];
				//strcpy(_str, s._str);
				char* ptr = new char[strlen(s._str) + 1];
				strcpy(ptr, s._str);
				delete[]_str;
				_str = ptr;//���ַ�ʽ�ȽϺã���Ϊ��һ�ַ���ʵ���ͷſռ䣬����������ռ䣬������һ��������ռ�ʧ�ܣ��ͻ����
			}
			return *this;
		}
	private:
		char* _str;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(nullptr);
	bit::string s3(s1);
	s3 = s1;
	return 0;
}
#endif
#if 0
//���---�ִ���ʽ
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
		//���������ÿ�����������Դ
		string(const string& s)//�������캯��
			: _str(nullptr)
			//���磺string s3(s1),��ΪpTemp������һ����s1��ͬ�Ŀռ䣬��ͬ������
			//pTemp��s3������s3ָ����pTempָ������ݣ���pTempָ���ԭ��s3ָ�������
			//Ҳ�������ֵ�����˸����������������������������pTemp��_str�����ͷţ�
		{	//��ʱ�Ƕ����ֵ�����ͷţ�Ҳ�����ͷ�Ұָ�룬�������������������s3��_str��ʼ��Ϊnullptr
			string pTemp(s._str);//����һ����ʱ����
			swap(_str, pTemp._str);
		}
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string pTemp(s);//��������
		//		swap(_str, pTemp._str);
		//	}
		//	return *this;
		//}
		string& operator=(const string& s)
		
		{
			string pTemp(s);//��������
			swap(_str, pTemp._str);
			return *this;
		}
		//string& operator=(string s)
		//{
		//	swap(_str, s._str);
		//	return *this;
		//}
	private:
		char* _str;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(nullptr);
	bit::string s3(s1);
	s2 = s1;
	return 0;
}
#endif
#if 0
//ʹ�ü����ķ�ʽ�����ǳ����,��������ʹ����ͨ�ĳ�Ա��������ÿ��������һ�ݼ����������ǹ��еģ�
//���������s2ʱ��s2�еļ���-1����s1�еļ�����û�иı�
namespace bit
{
	class string
	{
	public:
		string(const char* str="")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str)+1];
			strcpy(_str, str);
			_count = 1;
		}
		string(string& s)
			:_str(s._str)
			, _count(++s._count)
		{}
		~string()
		{
			if (0==--_count)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		int _count;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	return 0;
}
#endif
#if 0
//���ʹ��static���εĳ�Ա������Ϊ����������һ�����µ��ù��캯����_count�ֻᷢ������,ֱ�ӱ�Ϊ1,���ǹ��еģ�ʹ���������������Ϊ1���޷����
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_count = 1;
			}	
		}
		string(string& s)
			:_str(s._str)
		{
			++_count;
		}
		~string()
		{
			if (0 == --_count)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		static int _count;
	};
}
int bit::string::_count = 0;
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	bit::string s3("world");
	return 0;
}
#endif
#if 0
//����ʹ��ָ�������
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_pCount=new int(1);
			}
		}
		string(string& s)
			:_str(s._str)
			, _pCount(s._pCount)
		{
			++(*_pCount);
			
		}
		~string()
		{
			Release();
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				Release();
				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}
			return *this;
		}
		char& operator[](size_t index)
		{
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}
	private:
		void Release()
		{
			if (_str && 0 == --(*_pCount))
			{
				delete[]_str;
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	//����һ�ݿռ�
	bit::string s3("world");
	bit::string s4(s3);
	//����һ�ݿռ�
	s1 = s3;
	s2 = s4;
	s1[0] = 'w';//��Ҫ�ı�s1�е����ݣ����ǲ��ܸ�����3����������ݣ�����Ҫ����s1������,
	//���Ծ�����дʱ����
	return 0;
}
#endif
//дʱ����:ǳ����+���ü���+���޸Ķ���ʱ�������
#if 1
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_pCount = new int(1);
			}
		}
		string(string& s)
			:_str(s._str)
			, _pCount(s._pCount)
		{
			++(*_pCount);

		}
		~string()
		{
			Release();
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				Release();
				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}
			return *this;
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_pCount, s._pCount);
		}
		char& operator[](size_t index)
		{
			if (*_pCount > 1)//�ж�����һ���ռ�
			{
				//����
				string strTemp(_str);
				Swap(strTemp);
			}
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}
	private:
		void Release()
		{
			if (_str && 0 == --(*_pCount))
			{
				delete[]_str;
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	//����һ�ݿռ�
	bit::string s3("world");
	bit::string s4(s3);
	//����һ�ݿռ�
	/*s1 = s3;
	s2 = s4;*/
	s1[0] = 'w';
	return 0;
}
#endif

