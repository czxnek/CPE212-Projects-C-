//******************************************
//Program Title: Project 4
//Project File: list.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 11/01/2021
//Program Description: fill out .cpp file for given header file to perform actions on a linked list
//******************************************

#include <iostream>
#include <new>
#include "list.h"

List::List()
{
	num = 0;
	head = NULL;
}

List::~List()
{
	Node* TEMP = head;
	
	while(TEMP != NULL) 
	{
		TEMP = TEMP->next;
		delete TEMP;
	}
}

void List::Append(string newword) 
{
	try {
		Node* TEMP = head;
		Node* NODE = new Node;

		NODE->next = NULL;
		NODE->word = newword;

		if (head == NULL)
		{
			head = NODE;
			num++;
			return;
		}
		while (TEMP->next != NULL)
		{
			TEMP = TEMP->next;
		}
		TEMP->next = NODE;
		num++;
	}
	catch (ListFull())
	{
		throw ListFull();
	}

}

void List::InsertAt(int pos, string newword) 
{
	try {
		Node* TEMP1 = head;
		Node* TEMP2 = NULL;

		if (pos > num - 1)
		{
			throw ListBadPosition();
		}
		else
		{
			for (int i = 0; i < pos; i++)
			{
				TEMP2 = TEMP1;
				TEMP1 = TEMP1->next;
			}
		}
	}
	catch (ListFull())
	{
		throw ListFull();
	}
	catch (ListBadPosition())
	{
		throw ListBadPosition();
	}
	
}

void List::Delete(string someword)
{
	Node* TEMP1 = head;
	Node* TEMP2 = NULL;

	while (TEMP1 != NULL)
	{
		if (TEMP1->word == someword)
		{
			if (TEMP2 == NULL)
			{
				head = TEMP1->next;
			}
			else
			{
				TEMP2->next = TEMP1->next;
			}
			delete(TEMP1);
			num--;
			return;
		}
		
		TEMP2 = TEMP1;
		TEMP1 = TEMP1->next;

		if (TEMP1 == NULL)
		{
			throw ListNotFound();
		}
	}
	
}

void List::Replace(string oldword, string newword)
{
	try {
		Node* TEMP = head;

		while (TEMP != NULL)
		{
			if (TEMP->word == oldword)
			{
				TEMP->word == newword;
			}

			TEMP = TEMP->next;
		}
	}
	catch (ListNotFound())
	{
		throw ListNotFound();
	}
}

int List::Length() const
{
	return num;
}

bool List::Find(string someword) const
{
	Node* TEMP = head;

	while (TEMP != NULL)
	{
		if (TEMP->word == someword)
		{
			return true;
			TEMP = TEMP->next;
		}
		else
		{
			return false;
		}
	}
}


