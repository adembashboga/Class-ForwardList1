#include "List.h"
#include <iostream>

List::List()
	:head(nullptr), tail(nullptr), size(0)
{}

List::~List()
{
	clear();
}

List::List(const List& other)
	:head(nullptr), tail(nullptr), size(0)
{
	if (other.size == 0)
		return;

	Node* current = other.head;
	Node* prevNode = nullptr;
	Node* curNode = nullptr;
	while (current)
	{
		prevNode = curNode;
		curNode = new Node(prevNode, current->value);

		size == 0 ? head = curNode : prevNode->next = curNode;

		tail = curNode;
		current = current->next;
		size++;
	}
}

void List::push_back(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(tail, value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::push_front(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(value, head);
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		tail = new_node;
		head = new_node;
	}
	size++;
}

void List::clear()
{
	if (size = 0)
		return;

	Node* current = tail;
	Node* temp;
	while (current)
	{
		temp = current->prev;
		delete current;
		current = temp;
	}
	tail = nullptr;
	head = nullptr;
	size = 0;
}

int List::insert(int index, int value)
{

	if (index < 0 index > size)
	{
		return false;
	}
	Node* current = head;
	Node* new_node = new Node(value);

	if (index == size)
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
		return;
	}
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	if (current->prev)
	{
		current->prev->next = new_node;
		new_node->prev = current->prev;
	}
	else
	{
		head = new_node;
	}

	new_node->next = current;
	current->prev = new_node;

	size++;
}

int List::back() const
{
	if (tail)
	{
		return head->value;
	}
}

int List::front() const
{
	if (head)
	{
		return head->value;
	}
}

void List::show() const
{
	Node* current = head;
	while (current)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
	std::cout << std::endl;
}

List& List::operator=(const List& other)
{
	if (this == &other)
		return *this;

	if (other.size == 0)

	Node* current = other.head;
	Node* prevNode = nullptr;
	Node* curNode = nullptr;
	while (current)
	{
		prevNode = curNode;
		curNode = new Node(prevNode, current->value);

		if (size == 0)
			head = curNode;
		else
			prevNode->next = curNode;

		tail = curNode;
		current = current->next;
		size++;
	}
}

void List::reverse()
{
	Node* current = head;
	Node* temp = nullptr;

	while (current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev; 
	}

	temp = head;
	head = tail;
	tail = temp;
}

void List::pop_back()
{
	if (size == 0)
		return;

	if (tail)
	{
		Node* toDelete = tail;
		tail = tail->prev;

		if (tail)
			tail->next = nullptr;
		else
			head = nullptr;
	}
}

void List::pop_front()
{
	if (size == 0)
		return;

	if (head)
	{
		Node* toDelete = head;
		head = head->next;

		if (head)
			head->prev = nullptr;
		else
			tail = nullptr
	}
}
