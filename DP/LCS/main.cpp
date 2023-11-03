#include <iostream>
#include "LCS.h"

int main()
{
	string a = "ACTG";
	string b = "ACGGA";
	string lcs = LCS::CalculateLCS(a,b);
	cout << "The LCS of " << a << " and " << b << " is " << lcs << endl;
	return 0;
}