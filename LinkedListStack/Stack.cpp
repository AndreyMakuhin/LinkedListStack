#include "Stack.h"

Stack::Stack()
{
	head = nullptr;
	tail = head;	
}

Stack::~Stack()
{
	if (size > 0)
	{
		Item* iter = head;
		Item* tmp = iter;
		while (iter->next)
		{
			iter = iter->next;
			delete tmp;
			tmp = iter;
		}

		delete iter;
	}	
}

void Stack::Push(int val)
{
	if (size > 0)
	{
		tail->next = new Item(val);
		tail = tail->next;
		tail->next = nullptr;
		size++;
	}
	else
	{
		head = new Item(val);
		tail = head;
		tail->next = nullptr;
		size++;
	}
	
}

int Stack::Pop()
{
	
	if (size > 0)
	{
		int val = tail->Value();
		Item* iter = head;
		if (size > 1)
		{
			for (int i = 1; i < size - 1; ++i)
			{
				iter = iter->next;
			}
		}

		if (size == 1)
		{
			delete tail;
			tail = head;
			tail->next = nullptr;
			size--;
			return val;
		}

		delete tail;
		tail = iter;
		tail->next = nullptr;

		size--;

		return val;
	}
	else
	{
		return -1;
	}	
}

int Stack::Size() const
{
	return size;
}

bool Stack::Empty() const
{
	return size == 0;
}

Stack::Item::Item(int value)
	:
	val(value)
{
}

int Stack::Item::Value() const
{
	return val;
}
