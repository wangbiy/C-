#include <iostream>
using namespace std;
#if 0
int** Get2Array(int M, int N)
{
	int** p = new int*[M];//��������ÿһ���׵�ַ�Ŀռ�M����p��ʾ��M���ռ���׵�ַ
	for (int i = 0; i < M; ++i)
	{
		p[i] = new int[N];//������ÿһ�е�Ԫ��N��
	}
	return p;
}
#endif
#if 0
//stack��ģ��ʵ��
#include <deque>
namespace bite
{
	template<class T, class Container = deque<T>>//ָ��������deque
	class stack
	{
	public:
		stack()
			:_con()
		{}
		void push(const T& data)
		{
			_con.push_back(data);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		const T& top()const
		{
			return _con.back();
		}
		size_t size()const
		{
			return _con.size();
		}
		bool empty()const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}
#include <vector>
int main()
{
	bite::stack<int> s1;
	bite::stack<int, vector<int>> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	cout << s2.size() << endl;
	cout << s2.top() << endl;

	s2.pop();
	s2.pop();
	cout << s2.size() << endl;
	cout << s2.top() << endl;
	return 0;
}
#endif
#if 0
//queue��ģ��ʵ��
#include <deque>
namespace bite
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
			:c()
		{}
		void push(const T& data)
		{
			c.push_back(data);
		}
		void pop()
		{
			c.pop_front();
		}
		T& front()
		{
			return c.front();
		}
		const T& front()const
		{
			return c.front();
		}
		T& back()
		{
			return c.back();
		}
		const T& back()const
		{
			return c.back();
		}
		size_t size()const
		{
			return c.size();
		}
		bool empty()const
		{
			return c.empty();
		}
	private:
		Container c;
	};
}
#include <list>
int main()
{
	bite::queue<int> q1;
	bite::queue<int, list<int>> q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	q2.push(5);
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;

	q2.pop();
	q2.pop();
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;

	return 0;
}
#endif
#if 0
//���ȶ��е�ʹ��
#include <queue>
#include <functional>
int main()
{
	priority_queue<int, vector<int>, greater<int>> q;//��С��
	q.push(3);
	q.push(1);
	q.push(9);
	q.push(0);
	q.push(5);
	q.push(7);
	cout << q.top() << endl;
	return 0;
}
#endif
//���ȶ��е�ģ��ʵ��
#include <vector>
namespace bite
{
	template <class T, class Container = vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		priority_queue() 
			: c()
		{}
		template <class Iterator>
		priority_queue(Iterator first, Iterator last) 
			: c(first, last) 
		{ 
			int root = ((c.size() - 2) >> 1);
			for (; root >= 0; --root)
			{
				_AdjustDown(root);//���µ���
			}
		}
		void push(const T& x)
		{
			c.push_back(x);
			_AdjustUp(c.size()-1);
		}
		void pop()
		{
			if (empty())
				return;
			swap(c.front(), c.back()); //���Ѷ�Ԫ�������һ��Ԫ�ؽ���
			c.pop_back();
			_AdjustDown(0);
		}
		bool empty() const 
		{ 
			return c.empty();
		}
		size_t size() const 
		{ 
			return c.size(); 
		}
		T& top() const 
		{ 
			return c.front(); 
		}
	private:
		void _AdjustDown(int parent)
		{
			size_t child = parent * 2 + 1;//��ʱ������
			while (child < c.size())
			{
				//�����������нϴ���Ǹ�
				Compare com;
				if (child + 1 < c.size() && com(c[child], c[child + 1]))//�Һ��Ӵ��ڲ��ұȽ����Һ���
				{
					child += 1;//�Һ��ӱȽϴ�
				}
				//�Ƚ�parent��child
				if (com(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					return;
			}
		}
		void _AdjustUp(int child)
		{
			int parent = ((child - 1)) >> 1;
			while (child)
			{
				Compare com;
				if (com(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					child = parent;
					parent = ((child - 1)) >> 1;
				}
				else
					return;
			}
		}
	private:
		Container c;
	};
}
#include <functional>
int main()
{
	int arr[] = { 4, 2, 8, 9, 3, 7, 0, 6, 5, 1 };
	bite::priority_queue<int> q1;
	for(auto e:arr)
	{
		q1.push(e);
	}
	bite::priority_queue<int, vector<int>, greater<int>> q2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	return 0;
}
#if 0
//�����Զ������ͣ�����С�ѣ���������>
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		if (_year < d._year || _year == d._year&&_month < d._month || _year == d._year&&_month == d._month&&_day < d._day)
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
#include <queue>
int main()
{
	Date d1(2019, 9, 17);
	Date d2(2019, 9, 16);
	Date d3(2019, 9, 18);
	priority_queue<Date> q;//Ĭ���Ǵ��
	q.push(d1);
	q.push(d2);
	q.push(d3);
	return 0;
}
#endif
#if 0
//����������յ�ַ�Ƚϣ���ô�޷�ʹ�����ݱȽϣ��ò�����Ҫ�Ľ��
//���磺

class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		if (_year < d._year || _year == d._year&&_month < d._month || _year == d._year&&_month == d._month&&_day < d._day)
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
#include <queue>
int main()
{
	Date d1(2019, 9, 17);
	Date d2(2019, 9, 16);
	Date d3(2019, 9, 18);
	priority_queue<Date*> q;
	q.push(&d1);
	q.push(&d2);
	q.push(&d3);
	//���ǰ��������ձȽ�
	return 0;
}
#endif
#if 0
//����ʹ�ú���ָ�����趨�ȽϹ��򣬵��������Ƚ��鷳
class Date
{
	friend bool Less(Date* pLeft, Date* pRight);//������Ԫ
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	
private:
	int _year;
	int _month;
	int _day;
};
bool Less(Date* pLeft, Date* pRight)
{
	if (pLeft->_day < pRight->_day)
		return true;
	return false;
}
typedef bool(*Compare)(Date* pLeft, Date* pRight);
#include <queue>
int main()
{
	Date d1(2019, 9, 17);
	Date d2(2019, 9, 16);
	Date d3(2019, 9, 18);
	priority_queue<Date*,vector<Date*>,Compare> q(Less);//�����
	q.push(&d1);
	q.push(&d2);
	q.push(&d3);
	return 0;
}
#endif
#if 0
class Date
{
	friend class Less;//��Ԫ��
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
class Less
{
public:
	bool operator()(Date* pLeft, Date* pRight)//����less�Ĺ���
	{
		if (pLeft->_day < pRight->_day)
			return true;
		return false;
	}
};
#include <queue>
int main()
{
	Date d1(2019, 9, 17);
	Date d2(2019, 9, 16);
	Date d3(2019, 9, 18);
	Less min;//����һ������
	min(&d1, &d2);//�º���||��������----��������һ���Ķ���
	//�൱��min.operator()(&d1,&d2)
	priority_queue<Date*, vector<Date*>, Less> q;//�����
	q.push(&d1);
	q.push(&d2);
	q.push(&d3);
	return 0;
}
#endif


