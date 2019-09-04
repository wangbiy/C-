#include <iostream>
using namespace std;
#include <assert.h>
#if 0
template<class T>//����ģ��
T Add(const T& left, const T& right)
{
	cout << typeid(right).name() << endl;
	return left + right;
}
int main()
{
	//��ʽʵ����
	cout << Add(1, 2) << endl;//�ڱ����ڼ䣬��������ʵ�ε�������ȷ��ģ������б��е�T������ȷ����T�Ľ�������ɴ���
	cout << Add(12.3, 4.56) << endl;
	//cout << Add((double)1, 2.3) << endl;
	//����
	cout << Add<double>(1, 2.3) << endl;//��ʽʵ����,��ȷָ��T������Ϊdouble
	//���Խ�����ʽ����ת��
	//Add<double>("hello", 1.0);//����ת��ʧ��
	system("pause");
	return 0;
#endif
#if 0
template<class T>//����ģ��
T Add(const T& left, const T& right)
{
	return left + right;
}
class Complex
{
public:
	Complex(double real, double image)
		:_real(real)
		, _image(image)
	{}
	/*Complex operator+(const Complex& c)const
	{
		Complex ret(_real + c._real, _image + c._image);
		return ret;
	}*/
	//�Ż�
	Complex operator+(const Complex& c)const
	{
		return Complex (_real + c._real, _image + c._image);//��������
	}
private:
	double _real;
	double _image;
};
int main()
{
	Add(1, 2);
	Add(2.3, 4.5);
	Add('1', '2');
	Add(1, (int)2.7);
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	Add(c1, c2);//�����Զ�������ʱ��������������⣬�������������
	return 0;
}
#endif
#if 0
int Add(int left, int right) 
{
	return left + right;
}
template<class T>//����ģ��
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	Add <int>(1, 2);
	return 0;
}
#endif
#if 0
int Add(int left, int right)
{
	return left + right;
}
template<class T1,class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	// ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 2.0); 
	// ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
	
	return 0;
}
#endif
//��ģ��
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)//���캯��
		:_array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}
	SeqList(size_t n, const T& data = T())//T()Ϊ���캯��
		:_array(new T[n])
		, _capacity(n)
		,_size(n)
	{
			for (size_t i = 0; i < _capacity; ++i)//������memset
			{
				_array[i] = data;
			}
	}
	~SeqList()
	{
		if (_array)
		{
			delete[]_array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	void PushBack(const T& data);//β��
	void PopBack();//βɾ
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	bool Empty()const
	{
		return 0 == _size;
	}
	T& operator[](size_t index)//�±����������
	{
		assert(index < _size);
		return _array[index];
	}
	const T& operator[](size_t index)const//����ֵ���ͼ���const
	{
		assert(index < _size);
		return _array[index];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template<class T>
void SeqList<T>::PushBack(const T&data)
{
	//_ChackCapacity()
	_array[_size++] = data;
}
template<class T>
void SeqList<T>::PopBack()
{
	if (0 == _size)
		return;
	_size--;
}
int main()
{
	SeqList<int>s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1[0] = 10;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1[3] << endl;
	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	s2.PushBack(4.0);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2[0] = 9.0;
	cout << s2[0] << endl;


	const SeqList<int> s3(10,5);//��10��ֵΪ5��Ԫ��
	//cout << s3[5] << endl;//���ܵõ�,����,��Ϊconst���͵Ķ����ܵ�����ͨ���±����������
	//���½������������
	//s3[5] = 10;//������const���͵Ķ������޸ģ�����ȴ�����޸�
	//���½������������,Ӧ����������صķ���ֵ������ܱ��޸ģ�����ֵ���ͼ���const
	system("pause");
	return 0;
}


