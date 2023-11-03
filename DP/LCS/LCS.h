#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

//#define DEBUG

/// <summary>
/// Class is just a rough sketch to visualize LCS, does not promote any programming paradigm
/// Meant to be something coded in ~20 mins
/// </summary>
class LCS
{
private:
	static string ConstructLCS(string a, string b, char** values);
	static void PrintArray(string a, string b, int** values);
	static void PrintArray(string a, string b, char** values);
public:
	static string CalculateLCS(string a, string b);
};
#endif

