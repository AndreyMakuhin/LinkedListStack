#include "Stack.h"

void Stack::Push(int val)
{
	Element newElement(val);
}

int Stack::Size() const
{
	return size;
}

bool Stack::Empty() const
{
	return size == 0;
}

Stack::Element::Element(int val)
	:
	value(val)
{
}
