//***************************************************
//Program Title: Project 5
//Project File: bstree.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 11/15/2021
//Program Description: source file for given bstree.h header file to perform operations on a binary tree
//***************************************************


#include <iostream>
#include <new>
#include "bstree.h"

template <typename SomeType>
void BSTree<SomeType>::Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item)
 {

    	if(item < treePtr->data)
    	{
    		Delete(treePtr->leftPtr, item);
		}
		else if(item > treePtr->data)
		{
			Delete(treePtr->rightPtr, item);
		}
		else if(this->IsEmpty())
		{
			throw NotFoundBSTree();
		}
		else
		{
			item = treePtr->data;
			DeleteNode(treePtr);
		}	

 } // Delete()
  // Recursive function that traverses the tree starting at treePtr to locate the data value to be removed
  // Once located, DeleteNode is invoked to remove the value from the tree
  // If tree is not empty and item is NOT present, throw NotFoundBSTree	

template <typename SomeType>
void BSTree<SomeType>::DeleteNode(BSTreeNode<SomeType>*& treePtr)
 {
    SomeType data1;
    BSTreeNode<SomeType>* tempPtr = treePtr;

    if (treePtr->leftPtr == NULL) 
    {
        treePtr = treePtr->rightPtr;
        delete tempPtr;
    }
    else if (treePtr->rightPtr == NULL) 
    {
        treePtr = treePtr->leftPtr;
        delete tempPtr;
    }
    else          
    {
    	GetPredecessor(treePtr->leftPtr, data1);
    	treePtr->data = data1;
    	Delete(treePtr->leftPtr, data1);
    }
 }
  // DeleteNode()
  // Removes the node pointed to by treePtr from the tree
  // Hint:  calls GetPredecessor and Delete
  
 template <typename SomeType>
 void BSTree<SomeType>::Insert(BSTreeNode<SomeType>*& ptr, SomeType item)
 {
    if(ptr == NULL)
    {
        ptr = new BSTreeNode<SomeType>;
        ptr->rightPtr = NULL;
        ptr->leftPtr = NULL;
        ptr->data = item;
    }
    else if(ptr->data == item)
    {
    	throw FoundInBSTree();
	}
    else if(item < ptr->data) 
	{
        Insert(ptr->leftPtr, item);    // Insert in left subtree.
    }
    else 
	{
        Insert(ptr->rightPtr, item);   // Insert in right subtree.
    }
    
 }
  // Insert()
  // Recursive function that finds the correct position of item and adds it to the tree
  // Throws FoundInBSTree if item is already in the tree

template <typename SomeType>
void BSTree<SomeType>::Destroy(BSTreeNode<SomeType>*& ptr)
{
     if(ptr != NULL)
     {
     	Destroy(ptr->leftPtr);
     	Destroy(ptr->rightPtr);
     	delete ptr;
	 }
}
  // Destroy()
  // Recursively deallocates every node in the tree pointed to by ptr
  
template <typename SomeType>
void BSTree<SomeType>::CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree)
 {
    if (originalTree == NULL) 
	{ 
        copy = NULL;
    }
    else
    {
        copy = new BSTreeNode<SomeType>;
        copy->data = originalTree->data;
        CopyTree(copy->leftPtr, originalTree->leftPtr);
        CopyTree(copy->rightPtr, originalTree->rightPtr);
    }
 }
 
template <typename SomeType>
SomeType BSTree<SomeType>::GetPredecessor(BSTreeNode<SomeType>* treePtr) const
 {
    while (treePtr->rightPtr != NULL) 
    { 
        treePtr = treePtr->rightPtr;
    }
    return treePtr->data;
 
 }
  // GetPredecessor()
  // Finds the largest data value in the tree pointed to by treePtr and returns that data value
  // as the functions return value
  // CopyTree()
  // Recursively copies all data from original tree into copy

template <typename SomeType>
int BSTree<SomeType>::CountNodes(BSTreeNode<SomeType>* treePtr) const 
{
    if(treePtr == NULL)
    {
        return 0;
    }
    else
	{
        return CountNodes(treePtr->leftPtr) + CountNodes(treePtr->rightPtr) + 1; 
    }
}

template <typename SomeType>
int BSTree<SomeType>::LevelCount(BSTreeNode<SomeType>* treePtr) const
{
    
}
  // LevelCount()
  // Recursive function that traverses the entire tree to determine the total number of levels in the tree

template <typename SomeType>
int BSTree<SomeType>::FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const
{
    
}
  // FindLevel()
  // Recursive function that traverses the tree looking for item and returns the level where
  // item was found
	
template <typename SomeType>	
BSTree<SomeType>::BSTree()
{
	rootPtr = NULL;
}								
  // BSTree()
  // Default constructor initializes root pointer to NULL

template <typename SomeType>	
BSTree<SomeType>::BSTree(const BSTree<SomeType>& someTree)
{
	CopyTree(rootPtr, someTree.rootPtr);
}
  // BSTree() 
  // Copy constructor for BSTree
  // Hint:  calls CopyTree
	
template <typename SomeType>
void BSTree<SomeType>::operator=(const BSTree<SomeType>& originalTree)
{
 	if(&originalTree == this)
 	{
 		return;
		Destroy(rootPtr);
		CopyTree(rootPtr, originalTree.rootPtr);
	}

}
  // operator=() 
  // Overloaded assignment operator for BSTree.
  // Hint:  calls CopyTree

template <typename SomeType>
BSTree<SomeType>::~BSTree()	
{
    Destroy(rootPtr);                
}						
  // ~BSTree()
  // Destructor deallocates all tree nodes
  // Hint:  calls the private helper function Destroy

template <typename SomeType>
void BSTree<SomeType>::InsertItem(SomeType item)
{
	if(this->IsFull())
	{
		throw FullBSTree();
	}
	else
	{
		Insert(this->rootPtr, item);
	}
} 		
  // InsertItem()
  // Inserts item into BSTree;  if tree already full, throws FullBSTree exception
  // If item is already in BSTree, throw FoundInBSTree exception
  // Hint:  calls the private helper function Insert

template <typename SomeType> 
SomeType BSTree<SomeType>::DeleteItem(SomeType item)
{
	if(IsEmpty())
	{
		throw EmptyBSTree();
	}
	else
	{
		Delete(rootPtr, item);
		return item;
	}
	
}		
  // DeleteItem()
  // Deletes item from BSTree if item is present AND returns object via function return value
  // If tree is empty, throw the EmptyBSTree exception
  // If tree is not empty and item is NOT present, throw NotFoundBSTree
  // Hint:  calls the private helper function Delete


template <typename SomeType> 
void BSTree<SomeType>::MakeEmpty()	
{
    if(!this->IsEmpty())
    {
    	Destroy(this->rootPtr);
	}
}					
  // MakeEmpty()
  // Deallocates all BSTree nodes and sets root pointer to NULL
  // Hint:  calls the private helper function Destroy
 
 
template <typename SomeType> 
int BSTree<SomeType>::Size() const
{
	return CountNodes(this->rootPtr);
}	
  // Size()
  // Returns total number of data values stored in tree


template <typename SomeType>  
bool BSTree<SomeType>::IsFull() const
{
   BSTreeNode<SomeType>* location;
    try 
    {
        location = new BSTreeNode<SomeType>;  // create a new node
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;  // threw an error when we created a node so it IsFull return true
    }
}					
  // IsFull()
  // Returns true if BSTree is full; returns false otherwise

template <typename SomeType> 
bool BSTree<SomeType>::IsEmpty() const
{
    return rootPtr == NULL;  
}					
  // IsEmpty()
  // Returns true if BSTree is empty; returns false otherwise

template <typename SomeType> 	
SomeType BSTree<SomeType>::Min() const
{

}                
  // Min()
  // Returns minimum value in tree; throws EmptyBSTree if tree is empty

template <typename SomeType>	
SomeType BSTree<SomeType>::Max() const    
{

}            
  // Max()
  // Returns maximum value in tree; throws EmptyBSTree if tree is empty

template <typename SomeType>	
int BSTree<SomeType>::TotalLevels() const
{
	
}
  // TotalLevels()
  // Returns the maximum level value for current tree contents
  // Levels are numbered 0, 1, ..., N-1.  This function returns N
  // Throws EmptyBSTree if empty
  // Hint:  calls the private helper function LevelCount
template <typename SomeType>
int BSTree<SomeType>::Level(SomeType item) const    
{
	
}
  // Level()
  // Returns the level within the BSTree at which the value item is found
  // If tree is empty, throws EmptyBSTree
  // If tree is not empty and item is not found, throws NotFoundBSTree
  // Hint:  calls the private helper funtion FindLevel
	
