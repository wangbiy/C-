#include "queue.h"
void Testfunc()
{
	Queue q;
	q.QueuePush(1);
	q.QueuePush(2);
	q.QueuePush(3);
	q.QueuePush(4);
	q.QueueShow();
	q.QueuePop();
	q.QueueShow();
	DataType data=q.QueueFront();
	cout << data << endl;
	data = q.QueueBack();
	cout << data << endl;
	q.Queuempty();
	int size = q.QueueSize();
	cout << size << endl;
}
int main()
{
	Testfunc();
	system("pause");
	return 0;
}