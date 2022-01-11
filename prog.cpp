#include <iostream>

#include"Queue.h"

int main()
{
	//Stack<int> s;
	////while (true)
	////{
	////	s.push(1);
	////	s.pop();
	////}
	//for (size_t i = 0; i < 1000000; i++)
	//{
	//	s.push(10 + i);
	//}
	//system("pause");
	//s.clear();

	//while (!s.isEmpty())
	//{
	//	std::cout << s.pop() << "\n";
	//}
	//system("pause");

	Queue<int> q;
	//while (true)
	//{
	//	q.enqueue(1);
	//	q.dequeue();
	//}

	for (size_t i = 0; i < 10; i++)
	{
		q.enqueue(10 + i);
	}
	system("pause");
	//q.clear();

	while (!q.isEmpty())
	{
		std::cout << q.dequeue() << "\n";
	}
	system("pause");
}