#include "QuickFind.h"

QuickFind::QuickFind()
	: UnionFind()
{

}

QuickFind::QuickFind(int N)
	: UnionFind(N)
{
	//Initialize the array in increasing order O(n)
	for (int i = 0; i < size; i++)
	{
		id[i] = i;
	}
}

QuickFind::~QuickFind()
{
}

/// <summary>
/// Joins the two subsets of components from v1 and v2 O(N)
/// </summary>
/// <param name="v1">vertex 1</param>
/// <param name="v2">vertex 2</param>
void QuickFind::UnionV(int v1, int v2)
{
	int v1id = id[v1];
	int v2id = id[v2];
	//Loop through all vertices
	for (int i = 0; i < size; i++)
	{
		//If the element at this index shares the same predecessor as v1
		//Then update predecessor
		if (id[i] == v1id)
			id[i] = v2id;
	}
}

/// <summary>
/// Finds the "group leader" of a particular index O(1)
/// </summary>
/// <param name="v1">vertex number 0-indexed</param>
/// <returns>element at index v1 in the id array</returns>
int QuickFind::Find(int v1)
{
	return id[v1];
}

/// <summary>
/// Checks if two vertices are connected O(1)
/// </summary>
/// <param name="v1">vertex 1</param>
/// <param name="v2">vertex 2</param>
/// <returns>true if they are connected, false if not.</returns>
bool QuickFind::Connected(int v1, int v2)
{
	return Find(v1) == Find(v2);
}
