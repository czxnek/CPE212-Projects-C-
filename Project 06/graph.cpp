//********************************************
//Program Title: Project 6
//Project File: graph.cpp
//Name: Caleb Keller
//Course Section: CPE-212-01
//Due Date: 12/01/2021
//Program Description: function definitions for given header file "graph.h" to implement a Graph ADT Class 
//that uses an Adjacency List as the internal representation of the graph's vertices and edges
//********************************************

#include "graph.h"

Graph::Graph()
{
  	vertices = NULL;
}							
  // Graph()
  // Constructor initializes vertices linked list to empty
	
Graph::~Graph()
{
		vertices->edgePtr;
		
		while(vertices->edgePtr != NULL)
		{
			EdgeNode* TEMP = vertices->edgePtr;
			vertices->edgePtr = vertices->edgePtr->nextPtr;
			delete TEMP;
		}
		
		VertexNode* TEMP = vertices;
		vertices = vertices->nextVertex;
		delete TEMP;

}
  // ~Graph()
  // For each VertexNode in the vertices list, Destructor deallocates all EdgeNodes before
  // deallocating the VertexNode itself
	
void Graph::AddVertex(string v)
{
	if(vertices == NULL)
	{
		vertices = new VertexNode;
		vertices->vname = v;
		
		vertices->nextVertex = NULL;
		vertices->edgePtr = NULL;
		vertices->mark = false;
	}
	else
	{
		VertexNode* TEMP = new VertexNode;
		TEMP->nextVertex = vertices;
		vertices = TEMP;
		vertices->edgePtr = NULL;
		vertices->vname = v;
		vertices->mark = false;
	}
}		
  // AddVertex()
  // Adds vertex to graph assuming vertex not already present

void Graph::AddEdge(string s, string d, int w)
{
	try
	{
		EdgeNode* TEMP = new EdgeNode;
		delete TEMP;
	}
	catch(bad_alloc)
	{
		throw GraphFull();
	}
	if(WhereIs(s) == NULL || WhereIs(d) == NULL)
	{
		throw GraphVertexNotFound();
	}
	
	VertexNode* TEMP2 = WhereIs(s);
	
	if(TEMP2->edgePtr == NULL)
	{
		TEMP2->edgePtr = new EdgeNode;
		TEMP2->edgePtr->destination = WhereIs(d);
		TEMP2->edgePtr->weight = w;
		TEMP2->edgePtr->nextPtr = NULL;
	}
	else
	{
		EdgeNode* TEMP3 = new EdgeNode;
		TEMP3->destination = WhereIs(d);
		TEMP3->weight = w;
		TEMP3->nextPtr = TEMP2->edgePtr;
		
		TEMP2->edgePtr = TEMP3;
	}
}		
  // AddEdge()
  // Adds edge from source S  to destination D with specified weight W.
  // If there is not enough memory to add the edge, throw the GraphFull exception
	
bool Graph::IsPresent(string v)	
{
	if(WhereIs(v) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
  // IsPresent()
  // Returns true if vertex V in graph, false otherwise
	
VertexNode*  Graph::WhereIs(string v)		/* Note: This function replaces IndexIs */
{
  	VertexNode* TEMP = vertices;
  	
  	while(TEMP->vname != v)
  	{
  		if(TEMP->nextVertex != NULL)
  		{
  			TEMP = TEMP->nextVertex;
		}
		else
		{
			return NULL;
		}
	}
	return TEMP; 
}
  // WhereIs()
  // Returns pointer to the vertex node that stores vertex v in the vertices linked list; 
  // Throws GraphVertexNotFound if V is not present in the vertices list
	
int Graph::WeightIs(string s, string d)    
{
	if(WhereIs(s) != NULL && WhereIs(d) != NULL)
	{
		EdgeNode* TEMP = WhereIs(s)->edgePtr;
		
		while(TEMP != NULL)
		{
			if(TEMP->destination->vname == d)
			{
				return TEMP->weight; // returns weight
			}
			
			TEMP = TEMP->nextPtr;
		}
		
		throw GraphEdgeNotFound();
	}
	else
	{
		throw GraphVertexNotFound();
	}
}
  // WeightIs()
  // Returns weight of edge (s,d).  Throws GraphEdgeNotFound if edge not present.
	
void Graph::ClearMarks()	
{
  	VertexNode* TEMP = vertices;
  	
  	while(TEMP != NULL)
  	{
  		TEMP->mark = false;
  		TEMP = TEMP->nextVertex;
	}
}	
  // ClearMarks()
  // Clears all vertex marks
	
void Graph::MarkVertex(string v)	
{
	if(WhereIs(v) == NULL)
	{
		throw GraphVertexNotFound();
	}
	else
	{
		WhereIs(v)->mark = true;
	}
}
  // MarkVertex()
  // Marks vertex V as visited
	
bool Graph::IsMarked(string v)	
{
	if(WhereIs(v) == NULL)
	{
		throw GraphVertexNotFound();
	}
	else
	{
		return WhereIs(v)->mark; 
	}
}	
  // IsMarked()
  // Returns true if vertex V is marked, false otherwise

void Graph::GetToVertices(string V, queue<string>& q)	
{
	if(WhereIs(V) == NULL)
	{
		throw GraphVertexNotFound();
	}
	else
	{
		EdgeNode* TEMP = WhereIs(V)->edgePtr;
		
		while(TEMP != NULL)
		{
			if(TEMP->destination->mark == false)
			{
				q.push(TEMP->destination->vname);
			}
			
				TEMP = TEMP->nextPtr;
		}
	}
}
  // GetToVertices()
  // Returns queue Q of vertex names of those vertices adjacent to vertex V
  // The queue here is from the Standard Template Library
	
void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
{
	
	if(WhereIs(startVertex) == NULL || WhereIs(endVertex) == NULL)
	{
		throw GraphVertexNotFound();
	}
	
  	stack<string> stack;
  	queue<string> Q;

  	bool found = false; // initial set to false
  	string vertex;
  	string item;
  	
  	ClearMarks();
  	stack.push(startVertex);
  	
  	do
  	{
  		vertex = stack.top();
		stack.pop();
		
  		if(vertex == endVertex)
  		{ 
  			path.push(vertex);
  			found == true;	
		}
		else
		{
			if(!IsMarked(vertex))
			{
				MarkVertex(vertex);
				path.push(vertex);
				GetToVertices(vertex, Q);
			
			
				while(!Q.empty())
				{
					item = Q.front();
					Q.pop();
			
					if(!IsMarked(item))
					{
						stack.push(item);
					}
				}
			}
		}
	}while(!stack.empty() && !found);
	{
		if(!found) 
		{
			while(!path.empty())
			{
				path.pop();
			}
		}
	}

  	
} 
  	
   // DepthFirstSearch()
  // Uses the DFS algorithm from the CPE 212 textbook to determine a path from the
  // startVertex to the endVertex.  If a path is found, the path vertices should
  // be in the path queue.  If no path is found, the path queue should be emptied
  // as a signal to the client code that no path exists between the start and
  // end vertices.
  //
  // Notes:
  // (1) This algorithm is flawed in that as it searches for a path, it may
  // output some additional vertices that it visited but were not part
  // of the actual path.  Implement the algorithm just as it appears in the textbook.
  // 
  // (2) This algorithm requires use of the stack and queue containers from the
  // Standard Template Library.  The STL stack and queue interfaces may require
  // minor modifications to the DFS code from the textbook.
