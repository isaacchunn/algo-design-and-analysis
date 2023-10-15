#ifndef UNIONFIND_H
#define UNION_FIND_H

#include <vector>

enum UNION_TYPE
{
	QUICKFIND,
	QUICKUNION,
	WQUPC,
	TOTAL_UNION_TYPE
};

/// <summary>
/// Abstract class to enclose the methods and some common variables of our three find algorithms
/// </summary>
class UnionFind
{
protected:
	int size;
	//We need an array of length n, lets just use vector for easy access
	std::vector<int> id;

public:
	UnionFind();
	UnionFind(int N);
	~UnionFind();

	virtual void UnionV(int v1, int v2) = 0; //called unionV as union is a keyword in C++ for variables that are stored in same memory space (think adj matrix or adj list)
	virtual int Find(int v1) = 0;
	virtual bool Connected(int v1, int v2) = 0;
};

#endif