#include "UnionFind.h"

UnionFind::UnionFind()
	:size(0)
{
	
}

UnionFind::UnionFind(int N)
	:size(N)
{
	//Resize to n as the initialization is done in respective classes differently
	id.resize(N);
}

UnionFind::~UnionFind()
{
	id.clear();
}
