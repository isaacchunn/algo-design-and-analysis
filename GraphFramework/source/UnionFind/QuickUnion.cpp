#include "QuickUnion.h"

QuickUnion::QuickUnion()
	:UnionFind()
{

}

QuickUnion::QuickUnion(int N)
	:UnionFind(N)
{
	//Initialize the array in increasing order O(n)
	for (int i = 0; i < size; i++)
	{
		id[i] = i;
	}
}

QuickUnion::~QuickUnion()
{
}

/// <summary>
/// Joins the two subsets of components from v1 and v2 by changing root of p to point to root q O(n)
/// </summary>
/// <param name="v1">vertex 1</param>
/// <param name="v2">vertex 2</param>
void QuickUnion::UnionV(int v1, int v2)
{
	//Sets the id of v1's root to the id of v2's root
	//Find both the parents
	int v1Root = Find(v1);
	int v2Root = Find(v2);
	//Set v1 root to be v2
	id[v1Root] = v2Root;
}

/// <summary>
/// Chase parent pointers until we reach the root O(n) worst case if its singly linked list
/// </summary>
/// <param name="v1">vertex number 0-indexed</param>
/// <returns>element at index v1 in the id array</returns>
int QuickUnion::Find(int v1)
{
	//Have to while loop up to find the root of v1
	//The root of a node is itself, so we are just checking if parent and current vertex is same.
	while (v1 != id[v1])
	{
		v1 = id[v1];
	}
	return v1;
}

/// <summary>
/// Checks if two vertices are connected O(n)
/// </summary>
/// <param name="v1">vertex 1</param>
/// <param name="v2">vertex 2</param>
/// <returns>true if they are connected, false if not.</returns>
bool QuickUnion::Connected(int v1, int v2)
{
	//Do v1 and v2 have the same root?
	return Find(v1) == Find(v2);
}
