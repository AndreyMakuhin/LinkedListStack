#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element(int val);
	public:		
		int value;
		Element* pNext;
		Element* pPrev;
	};

public:
	Stack() = default;
	~Stack();
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	Element* pBottom = nullptr;
	Element* pTop = nullptr;
	int size = 0;
};