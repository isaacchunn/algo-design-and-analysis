#ifndef QUICKFIND_H
#define QUICKFIND_H

#include "UnionFind.h"

/// <summary>
/// Implementation of the quickfind algorithm that inherits from UnionFind~
/// </summary>
class QuickFind : public UnionFind
{
public:
	QuickFind();
	QuickFind(int N);
	~QuickFind();

	//Implement the functions
	void UnionV(int v1, int v2);
	int Find(int v1);
	bool Connected(int v1, int v2);

};
#endif