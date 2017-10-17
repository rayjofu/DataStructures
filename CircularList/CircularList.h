#include <iostream>

template <class T>
class CircularList
{
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
	};

	Node* head;

	public:
	CircularList();
	~CircularList();
	void Add(T data);
	bool Remove(T data);
	void Print();
	void PrintReverse();
	Node* Find(T data);
	bool HasData(T data);
};
