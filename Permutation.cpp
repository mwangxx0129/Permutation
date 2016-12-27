
// IMPLEMENTATION FILE 	 ( Permutation.cpp )
// Implements the Permutation member functions.  

#include "Permutation.h"  // includes specification of the class

//pre: "n" is a positive integer with 0 < n < 26 
//post: inits array "a" with {1,2,..,n}
void Permutation::Initialize(const int n)
{
	
	currentNum = n;

	for (int i = 0; i < currentNum; i++) {
		a[i] = i + 1;
		directions[i] = LEFT;
	}

	currentRow = 0;	 
}


// pre: the last permutation
// post: is an mobile element Existed, if found, return index, otherwise -1.
int Permutation::IsExistMobile()
{
	for (int i = 0; i < currentNum; i++) {

		// gets the index of adjacent element.
		// i works like base index, direction[i] is offset
		// if dir is LEFT, iAdj = index -1; if RIGHT, iAdj = index +1
		int iAdjacent = i + directions[i]; 

		if (iAdjacent < 0 || iAdjacent >= currentNum) { // out of array's range
			continue;
		}

		if (a[i] > a[iAdjacent]) {  
			// an element is mobile if its direction points to a smaller adjacent element
			return i;
		}

	}
	return -1;
}

// pre: the first mobile index
// post: find the index of largest mobile element
int Permutation::FindLargestMobile(const int firstMobileIndex)
{
	int maxIndex = firstMobileIndex;
	for (int i = firstMobileIndex + 1; i < currentNum; i++) {

		// gets the index of adjacent element.
		// i works like base index, direction[i] is offset
		// if dir is LEFT, iAdj = index -1; if RIGHT, iAdj = index +1
		int iAdjacent = i + directions[i]; 

		if (iAdjacent >= currentNum) { // out of array's range
			continue;
		}

		// an element is mobile if its direction points to a smaller adjacent element
		if (a[i] > a[iAdjacent]) {
			if (a[i] > a[maxIndex]) { // compare with current largest mobile
				maxIndex = i; // update largest mobile element
			}
		}

	}
	return maxIndex;

}

// pre: the index of mobile element
// post: swaps index's element and the element to which it is directed.
//	     the index of mobile will change.
int Permutation::SwapWithDirectedElement(const int iMobile)
{
	int iAdjacent = iMobile + directions[iMobile];

	// swap value of elements
	int tmpVal = a[iMobile];
	a[iMobile] = a[iAdjacent];
	a[iAdjacent] = tmpVal;

	// swap direction of elements
	int tmpDir = directions[iMobile];
	directions[iMobile] = directions[iAdjacent];
	directions[iAdjacent] = tmpDir;
	return iAdjacent;

}

// pre: the index of mobile element
// post: reverse the direction of all elements that are larger than a[i]
void Permutation::ReverseDirection(const int iMobile)
{
	for (int i = 0; i < currentNum; i++) {
		if (a[i] > a[iMobile]) {
			// reverse the direction
			if (directions[i] == LEFT) {
				directions[i] = RIGHT;
			}
			else {
				directions[i] = LEFT;
			}
		}
	}

}

// pre: List is not full
// post: Adds the new permutation to the listBuffer
void Permutation::AddToList()
{
	for (int i = 0; i < currentNum; i++) {
		listBuffer[currentRow][i] = a[i];
	}

	currentRow++; 
	
}

// pre: none
// post: return true, if buf is full, otherwise flase.
bool Permutation::IsListBufFull()
{
	if (currentRow == MAX_ROW) {
		return true;
	}
	return false;
}

//pre: none
//post : print to file
void Permutation::PrintList(ofstream &ofs)
{
	for(int i = 0; i< currentRow; i++){
		for (int j = 0; j < currentNum; j++) {
			ofs << listBuffer[i][j] << ' ';
		}
		ofs << '\n';
	}
	
}

// Pre:  ListBuffer is full.
// Post: Sets zero to currentRow. 
void Permutation::ResetList()
{
	currentRow = 0;
}


