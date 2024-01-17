//*************************************
//Program Title: Project 3
//Project File: stack.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 10/18/2021
//Program Description: stack.cpp source file for function defintions to match prototypes given in stack.h
//*************************************

#include <iostream>
#include <new>
#include "stack.h"

using namespace std;

	void Stack::Resize(int n)
	{
		int* array2 = NULL; // creating new temporary array reference to use for assigning 
		
		try // exception handling
		{
			array2 = new int[2 * num];
		}
		catch (bad_alloc& bd) // using example from stak powerpoint
		{
			throw StackFull(); // if bad allocation happens throw a stack full error
		}
		
		for (int i = 0; i < num; i++) // getting array size to match it to temporary array
		{
			array2[i] = array[i]; 
		}
		
		array2[num] = n; 
		top = num; 
		num = 2 * num; // making size larger
		
		delete[] array; 
		array = array2; // resize complete, assigns array equal to modified temporary array2 
	
	}

    Stack::Stack(int n)      
	{
		num = n;
		array = new int[n]; // array reference created
		top = -1; // -1 means stack is set to empty
	}                        

    Stack::~Stack()
	{
		delete[] array; // delete array
	}          

    void Stack::Push(int n)
	{
		if(IsFull())
		{
			Resize(n); // if full, resize
		}
		else
		{
			top++;
			array[top] = n; // push
		}
	}
	
    void Stack::Pop()  
    {
    	if(IsEmpty())
    	{
    		throw StackEmpty(); // empty stack error
		}
		else
		{
			top --; // decrement
		}
	}

	bool Stack::IsEmpty() const
	{
		return (top == -1);
	}  // Returns true if stack is empty; false otherwise
	
    bool Stack::IsFull() const
	{
		return (top == (num - 1));
	}  // Returns true if stack is full; false otherwise
	
    void Stack::MakeEmpty()     
	{
		top = -1; // make stack empty
	}

	
    int Stack::Top() const  
    {
    	if (IsEmpty())
    	{
    		throw StackEmpty(); // throw stack is empty error
		}
		else
		{
			return array[top]; // return top int of array
		}
	}           

    int Stack::Size() const
    {
    	return (top + 1); // returns size of array
	}

    int Stack::Max() const
	{
		if (IsEmpty())
		{
			throw StackEmpty(); // throws stack empty error
		}
		else
		{
			int val = array[0]; // temp array = 0 
			
			for (int i = 1; i < top; i++) 
			{
				if(array[i] > val) 
				{
					val = array[i]; // making temp array = to array size
				}
			}
			return val; // return temp array
		}
	} 

    int Stack::Min() const 
	{
		if (IsEmpty())
		{
			throw StackEmpty();
		}
		else
		{
			int val = array[0];
			
			for (int i = 1; i < top; i++)
			{
				if(array[i] < val)
				{
					val = array[i];
				}
			}
			return val;
		}
	} 
	
	int Stack::Peek(unsigned int n) const
	{
		if(top + 1 <= n) 
		{
			throw StackInvalidPeek(); // throws peek error
		}
		else
		{
			return array[top - n]; // returns top - n position
		}
	} 
	
	int Stack::Capacity() const 
	{
		return num; // return total number of elements capable of being stored in the stack
	}
	
	// end of stack.cpp
