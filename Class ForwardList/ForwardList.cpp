
#include <iostream>
#include "ForwardList.h"

void ForwardList::clear() // O(n)
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	head = nullptr;
	tail = nullptr;
}

ForwardList::ForwardList()
{
	head = tail = nullptr;
}

ForwardList::ForwardList(const ForwardList& other)
{
	std::cout << "copy\n";
}

void ForwardList::push_back(int value) // O(1)
{
	if (head && tail)
	{
		Node* new_node = new Node(value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
}

void ForwardList::pop_front() // O(1)
{
	if (head && tail)
	{
		Node* temp = head->next;
		delete head;
		if (!temp)
		{
			tail = temp;
		}
		head = temp;
	}
}

void ForwardList::pop_back()
{
	if (head && tail)
	{
		delete tail;
	}
}

const Node* ForwardList::find(int value)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == value) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void ForwardList::print() // O(n)
{
	if (head && tail)
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << ' ';
			current = current->next;
		}
		std::cout << std::endl;
	}
}

ForwardList::~ForwardList()
{
	clear();
}
