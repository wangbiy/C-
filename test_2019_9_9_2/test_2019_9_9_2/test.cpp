#include <iostream>
using namespace std;
#include <vector>
#if 0
int main()
{
	std::vector<int> v1;
	vector<int> v2(10, 5);
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v3(arr, arr+sizeof(arr) / sizeof(arr[0]));//区间
	vector<int>v4(v3);
	v1 = v2;
	return 0;
}
#endif
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//C++11
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e;
	}
	cout << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	v.resize(20,9);//增加，剩下的以9填充
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(5);//缩小有效元素个数
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(10);//增加,剩下的由0填充
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(30);
	cout << v.size() << endl;
	cout << v.capacity() << endl;


	
	return 0;
}
#endif
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v[5] << endl;
	v.insert(v.begin(), 10);
	//cout << v[100] << endl;//断言
	//cout << v.at(100) << endl;//抛异常
	//at与operator[]的区别：当访问下标元素时，如果越界，at会抛异常，operator[]会断言
	v.assign(10, 5);//将v修改为10个为5的元素
	for (auto e : v)
	{
		cout << e;
	}
	cout << endl;
	string s("hello");
	vector<char> vv;
	vv.assign(s.begin(), s.end());//给一个范围
	
	return 0;
}
#endif
//迭代器：方便用户遍历容器,最主要是提供给算法来使用---好处：可以不用知道容器的底层数据结构
//string::iterator---char*
//vector<T>::iterator---T*
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v[5] << endl;
	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end())
	{
		cout << *it1;
		++it1;
	}
	cout << endl;
	vector<int>::reverse_iterator it2 = v.rbegin();//逆向打印,使用反向迭代器
	while (it2 != v.rend())
	{
		cout << *it2;
		++it2;
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	size_t sz;
	std::vector<int> v;
	v.reserve(100);//提前分配好空间
	sz = v.capacity();
	std::cout << "making v grow" << endl;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);//效率太低,可以提前就分配好空间
		if (sz != v.capacity())
		{
			sz = v.capacity();
			std::cout << "capacity changed" << sz << endl;
		}
	}
	return 0;
}
#endif
//vector迭代器失效问题
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	auto it = v.begin();
	v.push_back(1);//出现问题，迭代器失效,容量发生改变，扩容，it指向的空间没有变，失效
	//给it重新赋值
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	it = v.begin();
	while (it != v.end())
	{
		//v.erase(it);//出现问题,迭代器失效
		//++it;
		it = v.erase(it);//因为erase返回值是it的下一个位置,所以要将他赋给it
	}
	cout << endl;
	return 0;
}
#endif
#if 0
#include <string>
int main()
{
	//vector<int> v;
	//cout << v[0] << endl;运行的时候崩溃
	string str;
	cout << (int)str[0] << endl;//不会崩溃，输出0
	return 0;
}
#endif
#if 0
#include <algorithm>//算法头文件
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 16, 7, 10 };
	sort(v.begin(), v.end());//默认是升序
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif
#if 0
//只出现一次的数字
class S {
public:
	S(vector<int>& arr)
		:nums(arr)
	{}
	int singleNumber()
	{
		int ret = 0;
		for (size_t i = 0; i<nums.size(); ++i)
		{
			ret ^= nums[i];
		}
		return ret;
	}
private:
	vector<int>& nums;
};
int main()
{
	vector<int> arr{ 1, 2, 2, 4, 1, 5, 5 };
	S s(arr);
	int result = s.singleNumber();
	cout << result << endl;
	return 0;
}
#endif
#if 1
class S
{
public:
	S(int line)
		:numRows(line)
	{}
	vector<vector<int>> generate()
	{
		vector<vector<int>> vRet;//定义二维数组
		//开辟空间,先开辟每行，在内存中是每行存元素
		vRet.resize(numRows);
		for (size_t i = 0; i < numRows; ++i)
		{
			vRet[i].resize(i + 1);//例如第0行有1个元素。。。。
			vRet[i][0] = vRet[i][i] = 1;//每行的第0列和对角线都是1
		}
		for (size_t i = 2; i < numRows; ++i)
		{
			for (size_t j = 1; j < i; ++j)
			{
				vRet[i][j] = vRet[i - 1][j] + vRet[i - 1][j - 1];
			}
		}
		return vRet;
	}
private:
	int numRows;
};
int main()
{
	S s(10);
	vector<vector<int>> arr=s.generate();
	return 0;
}
#endif