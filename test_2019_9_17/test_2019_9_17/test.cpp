#include <iostream>
using namespace std;
#if 0
int** Get2Array(int M, int N)
{
	int** p = new int*[M];//先申请存放每一行首地址的空间M个，p表示这M个空间的首地址
	for (int i = 0; i < M; ++i)
	{
		p[i] = new int[N];//再申请每一行的元素N个
	}
	return p;
}
#endif
#if 0
//stack的模拟实现
#include <deque>
namespace bite
{
	template<class T, class Container = deque<T>>//指定容器是deque
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
//queue的模拟实现
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
//优先队列的使用
#include <queue>
#include <functional>
int main()
{
	priority_queue<int, vector<int>, greater<int>> q;//建小堆
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
//优先队列的模拟实现
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
				_AdjustDown(root);//向下调整
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
			swap(c.front(), c.back()); //将堆顶元素与最后一个元素交换
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
			size_t child = parent * 2 + 1;//这时是左孩子
			while (child < c.size())
			{
				//找两个孩子中较大的那个
				Compare com;
				if (child + 1 < c.size() && com(c[child], c[child + 1]))//右孩子存在并且比较左右孩子
				{
					child += 1;//右孩子比较大
				}
				//比较parent与child
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
//对于自定义类型，创建小堆，必须重载>
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
	priority_queue<Date> q;//默认是大堆
	q.push(d1);
	q.push(d2);
	q.push(d3);
	return 0;
}
#endif
#if 0
//但是如果按照地址比较，那么无法使用内容比较，得不到想要的结果
//例如：

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
	//不是按照年月日比较
	return 0;
}
#endif
#if 0
//可以使用函数指针来设定比较规则，但是这样比较麻烦
class Date
{
	friend bool Less(Date* pLeft, Date* pRight);//设置友元
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
	priority_queue<Date*,vector<Date*>,Compare> q(Less);//建大堆
	q.push(&d1);
	q.push(&d2);
	q.push(&d3);
	return 0;
}
#endif
#if 0
class Date
{
	friend class Less;//友元类
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
	bool operator()(Date* pLeft, Date* pRight)//按照less的规则
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
	Less min;//定义一个对象
	min(&d1, &d2);//仿函数||函数对象----像函数调用一样的对象
	//相当于min.operator()(&d1,&d2)
	priority_queue<Date*, vector<Date*>, Less> q;//建大堆
	q.push(&d1);
	q.push(&d2);
	q.push(&d3);
	return 0;
}
#endif


