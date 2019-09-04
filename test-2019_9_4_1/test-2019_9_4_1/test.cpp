#include <iostream>
using namespace std;
#include <assert.h>
#if 0
template<class T>//函数模板
T Add(const T& left, const T& right)
{
	cout << typeid(right).name() << endl;
	return left + right;
}
int main()
{
	//隐式实例化
	cout << Add(1, 2) << endl;//在编译期间，必须推演实参的类型来确定模板参数列表中的T，根据确定的T的结果来生成代码
	cout << Add(12.3, 4.56) << endl;
	//cout << Add((double)1, 2.3) << endl;
	//或者
	cout << Add<double>(1, 2.3) << endl;//显式实例化,明确指定T的类型为double
	//尝试进行隐式类型转换
	//Add<double>("hello", 1.0);//错误，转换失败
	system("pause");
	return 0;
#endif
#if 0
template<class T>//函数模板
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
	//优化
	Complex operator+(const Complex& c)const
	{
		return Complex (_real + c._real, _image + c._image);//无名对象
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
	Add(c1, c2);//处理自定义类型时如果遇到此类问题，进行运算符重载
	return 0;
}
#endif
#if 0
int Add(int left, int right) 
{
	return left + right;
}
template<class T>//函数模板
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
	// 与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0); 
	// 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
	
	return 0;
}
#endif
//类模板
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)//构造函数
		:_array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}
	SeqList(size_t n, const T& data = T())//T()为构造函数
		:_array(new T[n])
		, _capacity(n)
		,_size(n)
	{
			for (size_t i = 0; i < _capacity; ++i)//不能用memset
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
	void PushBack(const T& data);//尾插
	void PopBack();//尾删
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
	T& operator[](size_t index)//下标运算符重载
	{
		assert(index < _size);
		return _array[index];
	}
	const T& operator[](size_t index)const//返回值类型加上const
	{
		assert(index < _size);
		return _array[index];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
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


	const SeqList<int> s3(10,5);//放10个值为5的元素
	//cout << s3[5] << endl;//不能得到,错误,因为const类型的对象不能调用普通的下标运算符重载
	//重新进行运算符重载
	//s3[5] = 10;//按理上const类型的对象不能修改，但是却可以修改
	//重新进行运算符重载,应该运算符重载的返回值结果不能被修改，返回值类型加上const
	system("pause");
	return 0;
}


