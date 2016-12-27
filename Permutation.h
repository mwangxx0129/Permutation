//  SPECIFICATION FILE	( Permutation.h )
//  Specifies the data and function members.

#ifndef _PERMUTATION_H_ // avoid duplicate include
#define _PERMUTATION_H_
#include <iostream> // cout cin
#include <sstream>	// for stringstream
#include <fstream> // ofstream
using namespace std;

const  int MAX_ROW = 4096; // max row for list buffer
const  int MAX_NUM = 25; // max num for input number

typedef   int  PermutationLisType[MAX_ROW][MAX_NUM]; // typedef listBuffer

enum Direction // the pointing directions
{
	LEFT = -1,
	RIGHT = 1

};

class Permutation // declares Permutation
{
public:
	//  9 public member functions
	void Initialize(const int n);
	int IsExistMobile();
	int FindLargestMobile(const int firstMobileIndex);
	int SwapWithDirectedElement(const int iMobile);
	void ReverseDirection(const int iMobile);
	void AddToList();
	bool IsListBufFull(); 
	void PrintList(ofstream &ofs);
	void ResetList();

private:
	//  7 private data members
	int a[MAX_NUM];
	int directions[MAX_NUM];
	PermutationLisType listBuffer; // an 2-D array storing permutations
	int currentRow;
	int currentNum;

};

#endif
