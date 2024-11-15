#pragma once

class List
{
	class Node {
	public:
		int value;
		Node* prev;
		Node* next;
		Node()
			:value(0), prev(nullptr), next(nullptr)
		{}
		Node(int value)
			:value(value), prev(nullptr), next(nullptr)
		{}
		Node(Node* prev, int value)
			:value(value), prev(prev), next(nullptr)
		{}
		Node(int value, Node* next)
			:value(value), prev(nullptr), next(next)
		{}
	};
private:
	Node* head;
	Node* tail;
	size_t size;
public:
	List();
	~List();
	List(const List& other);
	void push_back(int value);
	void push_front(int value);
	void clear();
	int insert(int index, int value);
	int back() const;
	int front() const;
	void show() const;
};