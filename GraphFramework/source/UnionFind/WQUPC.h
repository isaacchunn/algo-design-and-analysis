#ifndef WQUPC_H
#define WQUPC_H

#include "UnionFind.h"

class WQUPC : public UnionFind
{
	private:
		//We need an array of length n, lets just use vector for easy access
		std::vector<int> sz;
	public:
		WQUPC();
		WQUPC(int N);
		~WQUPC();

		//Implement the functions
		void UnionV(int v1, int v2);
		int Find(int v1);
		bool Connected(int v1, int v2);
    
        void PrintSize();
};
#endif
