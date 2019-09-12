#include <iostream>
using namespace std;
#include <vector>
#if 0
int main()
{
	std::vector<int> v1;
	vector<int> v2(10, 5);
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v3(arr, arr+sizeof(arr) / sizeof(arr[0]));//����
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
	v.resize(20,9);//���ӣ�ʣ�µ���9���
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(5);//��С��ЧԪ�ظ���
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(10);//����,ʣ�µ���0���
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
	//cout << v[100] << endl;//����
	//cout << v.at(100) << endl;//���쳣
	//at��operator[]�����𣺵������±�Ԫ��ʱ�����Խ�磬at�����쳣��operator[]�����
	v.assign(10, 5);//��v�޸�Ϊ10��Ϊ5��Ԫ��
	for (auto e : v)
	{
		cout << e;
	}
	cout << endl;
	string s("hello");
	vector<char> vv;
	vv.assign(s.begin(), s.end());//��һ����Χ
	
	return 0;
}
#endif
//�������������û���������,����Ҫ���ṩ���㷨��ʹ��---�ô������Բ���֪�������ĵײ����ݽṹ
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
	vector<int>::reverse_iterator it2 = v.rbegin();//�����ӡ,ʹ�÷��������
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
	v.reserve(100);//��ǰ����ÿռ�
	sz = v.capacity();
	std::cout << "making v grow" << endl;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);//Ч��̫��,������ǰ�ͷ���ÿռ�
		if (sz != v.capacity())
		{
			sz = v.capacity();
			std::cout << "capacity changed" << sz << endl;
		}
	}
	return 0;
}
#endif
//vector������ʧЧ����
#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	auto it = v.begin();
	v.push_back(1);//�������⣬������ʧЧ,���������ı䣬���ݣ�itָ��Ŀռ�û�б䣬ʧЧ
	//��it���¸�ֵ
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
		//v.erase(it);//��������,������ʧЧ
		//++it;
		it = v.erase(it);//��Ϊerase����ֵ��it����һ��λ��,����Ҫ��������it
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
	//cout << v[0] << endl;���е�ʱ�����
	string str;
	cout << (int)str[0] << endl;//������������0
	return 0;
}
#endif
#if 0
#include <algorithm>//�㷨ͷ�ļ�
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 16, 7, 10 };
	sort(v.begin(), v.end());//Ĭ��������
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
//ֻ����һ�ε�����
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
		vector<vector<int>> vRet;//�����ά����
		//���ٿռ�,�ȿ���ÿ�У����ڴ�����ÿ�д�Ԫ��
		vRet.resize(numRows);
		for (size_t i = 0; i < numRows; ++i)
		{
			vRet[i].resize(i + 1);//�����0����1��Ԫ�ء�������
			vRet[i][0] = vRet[i][i] = 1;//ÿ�еĵ�0�кͶԽ��߶���1
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