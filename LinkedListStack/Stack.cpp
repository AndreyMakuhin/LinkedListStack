#include "Stack.h"

Stack::Stack()
{
	head = new Item();
	tail = head;
	tail->next = nullptr;
}

Stack::~Stack()
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

void Stack::Push(int val)
{
	tail->next = new Item(val);
	tail = tail->next;
	tail->next = nullptr;
	size++;
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
		}

		delete tail;
		tail = iter;

		return val;
	}
	else
	{
		return 0;
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
