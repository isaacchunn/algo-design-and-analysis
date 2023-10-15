#include "WQUPC.h"

WQUPC::WQUPC()
	: UnionFind()
{

}

WQUPC::WQUPC(int N)
	: UnionFind(N)
{
	sz.resize(N);
	//Initialize the array in increasing order O(n)
	for (int i = 0; i < size; i++)
	{
		id[i] = i;
		//The size of each tree is 1 at the start
		sz[i] = 1;
	}
}

WQUPC::~WQUPC()
{
}

/// <summary>
/// Joins the two subsets of components from v1 and v2 O(logn) as find has been shortened, and union v iterative balances the tree
/// </summary>
/// <param name="v1">vertex 1</param>
/// <param name="v2">vertex 2</param>
void WQUPC::UnionV(int v1, int v2)
{
	//Can skip the trivial case of union 2 of the same vertices.
	if (v1 == v2)
		return;
	
	//have to make the smaller tree lower than the bigger tree (so depth isnt increased)
	int v1Root = Find(v1);
	int v2Root = Find(v2);

	//if both roots are the same, then return
	if (v1Root == v2Root)
		return;
	
	//Else we check size of the sub trees. If the tree of v1 is smaller than v2, merge v1 into v2
	if (sz[v1Root] < sz[v2Root])
	{
		//If v1 root is smaller than v2 root
		//Update root id of v1 to be v2
		id[v1Root] = v2Root;
		//Increment size of the tree that was merged
		sz[v2Root] += sz[v1Root];
	}
	else // Else v1 is larger than v2, so merge v2 into v1
	{
		id[v2Root] = v1Root;
		//Increment size of the tree that was merged
		sz[v1Root] += sz[v2Root];
	}
}

/// <summary>
/// Finds the "group leader" of a particular index O(logn)
/// </summary>
/// <param name="v1">vertex number 0-indexed</param>
/// <returns>element at index v1 in the id array</returns>
int WQUPC::Find(int v1)
{
	//Have to while loop up to find the root of v1
	//The root of a node is itself, so we are just checking if parent and current vertex is same.
	int root = v1;
	
	while (root != id[root])
	{
		//One pass path compression
		//id[root] = id[id[root]];
		root = id[root];
	}
    /*
	////Two pass path compression
	while (v1 != id[v1])
	{
		//Save the parent to current parent
		int parent = id[v1];
		//Set the current parent of v1 straight to root
		id[v1] = root;
		//Then let v1 be parent
		v1 = parent;
	}
     */

	//itr is now the root
	return root;
}

/// <summary>
/// Checks if two vertices are connected O(logn)
/// </summary>
/// <param name="v1">vertex 1</param>
/// <param name="v2">vertex 2</param>
/// <returns>true if they are connected, false if not.</returns>
bool WQUPC::Connected(int v1, int v2)
{
	//Do v1 and v2 have the same root?
	return Find(v1) == Find(v2);
}

void WQUPC::PrintSize()
{
    for(int i = 0; i < (int)sz.size(); i++)
    {
        std::cout << sz[i] << " ";
    }
    std::cout << std::endl;
}
