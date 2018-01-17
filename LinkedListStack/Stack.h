#pragma once

class Stack
{
public:
	class Item
	{
	public:
		Item() = default;
		Item(int value);
		Item* next;
		int Value()const;
	private:
		int val;
	};
public:
	Stack();
	~Stack();
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	int size = 0;
	Item* head;
	Item* tail;
};