#if 0
#include <iostream>
using namespace std;
#include <list>
//list：链式结构（带头节点的双向循环链表）
template <class T>
void Print(const list<T>& l)
{
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	list<int> L1;
	list<int> L2(10, 5);
	Print(L2);
	cout << L2.size() << endl;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	list<int> L3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(L3);
	cout << L3.size() << endl;
	cout << L3.front() << endl;
	cout << L3.back() << endl;

	L3.resize(3);
	Print(L3);
	cout << L3.size() << endl;

	L3.resize(3, 6);
	Print(L3);
	cout << L3.size() << endl;

	L3.resize(20, 6);
	Print(L3);
	cout << L3.size() << endl;

	list<int> L4(L3);//拷贝构造
	Print(L4);
	L4.push_back(8);
	Print(L4);
	L4.push_front(0);
	Print(L4);
	L4.insert(L4.begin(), 9);
	Print(L4);
	L4.erase(L4.begin());
	Print(L4);
	L4.sort();
	Print(L4);
	L4.unique();//去除重复的元素
	Print(L4);
	auto it = L4.begin();
	while (it != L4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	auto rit = L4.rbegin();//反向迭代器进行反向打印
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif
