#include <iostream>
using namespace std;
class Date
{
public:
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << this->_year << endl;
		cout << "month:" <<this->_month << endl;
		cout << "day:" << this->_day << endl << endl;
		/*this->_year = 2019;*/
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	const Date d1;
	d1.Display();
}
int main()
{
	Test();
	return 0;
}