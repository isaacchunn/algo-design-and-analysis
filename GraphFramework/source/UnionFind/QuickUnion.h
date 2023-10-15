#ifndef QUICKUNION_H
#define QUICKUNION_H

#include "UnionFind.h"

class QuickUnion : public UnionFind
{
public:
	QuickUnion();
	QuickUnion(int N);
	~QuickUnion();

	//Implement the functions
	void UnionV(int v1, int v2);
	int Find(int v1);
	bool Connected(int v1, int v2);
};

#endif