#include <iostream>
#include "CircularList.h"

using namespace std;

template <typename T>
CircularList<T>::CircularList()
{
	head = NULL;
}

template <typename T>
CircularList<T>::~CircularList()
{
	// empty list
	if (head == NULL)
	{
		return;
	}

	Node* ptr = head->next;
	while (ptr != head)
	{
		ptr = ptr->next;
		delete ptr->prev;
	}
	delete head;
}

template <typename T>
void CircularList<T>::Add(T data)
{
	// empty list
	if (head == NULL)
	{
		head = new Node;
		head->data = data;
		head->prev = head;
		head->next = head;	
		return;
	}

	Node* ptr = new Node;
	ptr->data = data;
	ptr->prev = head->prev;
	ptr->next = head;
	ptr->prev->next = ptr;
	head->prev = ptr;
}

template <typename T>
bool CircularList<T>::Remove(T data)
{
	// empty list
	if (head == NULL)
	{
		return false;
	}

	// if head contains target data
	Node* ptr = head->next;
	if (head->data == data)
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		delete head;
		
		// if resulting list is empty
		if (ptr == head)
		{
			head = NULL;
		}
		// else resulting list is non-empty
		else
		{
			head = ptr;
		}
		return true;
	}

	// search backwards
	ptr = head->prev;
	while (ptr != head)
	{
		// found data
		if (ptr->data == data)
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			delete ptr;
			return true;
		}

		ptr = ptr->prev;
	}

	// no matching data found
	return false;
}

template <typename T>
void CircularList<T>::Print()
{
	if (head == NULL)
	{
		return;
	}

	Node* ptr = head->next;
	cout << head->data << endl;
	while (ptr != head)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
}

template <typename T>
void CircularList<T>::PrintReverse()
{
	if (head == NULL)
	{
		return;
	}

	Node* ptr = head->prev;
	while (ptr != head)
	{
		cout << ptr->data << endl;
		ptr = ptr->prev;
	}
	cout << head->data << endl;
}

template <typename T>
typename CircularList<T>::Node* CircularList<T>::Find(T data)
{
	if (head == NULL)
	{
		return NULL;
	}

	if (head->data == data)
	{
		return head;
	}

	Node* ptr = head->prev;
	while (ptr != head)
	{
		if (ptr->data == data)
		{
			return ptr;
		}
		ptr = ptr->prev;
	}

	return NULL;
}

template <typename T>
bool CircularList<T>::HasData(T data)
{
	return Find(data) != NULL;
}

int main()
{
	CircularList<string> ll;
	ll.Add("a");
	ll.Add("b");
	ll.Add("c");
	ll.Add("d");
	ll.Add("e");
	ll.Print();
	cout << (ll.HasData("e")? "true" : "false") << endl;
	cout << ll.Remove("e") << endl;
	cout << (ll.HasData("e")? "true" : "false") << endl;
	ll.PrintReverse();
}
