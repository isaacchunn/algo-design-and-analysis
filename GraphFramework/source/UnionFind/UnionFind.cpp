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

void UnionFind::PrintID()
{
    for(int i = 0; i < (int)id.size(); i++)
    {
        std::cout << id[i] + 1 << " ";
    }
    std::cout << std::endl;
}
