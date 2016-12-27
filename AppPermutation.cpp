#include "AppPermutation.h"


//pre: num is a postive number
//post: generate all permutations, and output to file
void GenAllPermutations(Permutation& p,const int num, const char path[])
{
	ofstream ofs;
	long long totalCounter = 1; // count num of permutations; init 1, since original permutation is covered. 

	OpenOutFile(ofs, path);
	WriteProLog(ofs, num);

	p.Initialize(num); // initialize the first permutation as 1 2 бн num with directions pointing left
	p.AddToList(); // add the original permutation to List

	int firMob = -1;
	while ((firMob = p.IsExistMobile()) != -1) { // the last permutation has a mobile element 
		int k = p.FindLargestMobile(firMob); // find its largest mobile element k
		k = p.SwapWithDirectedElement(k); // swap k and the element to which k is directed
		p.ReverseDirection(k); // reverse the direction of all elements that are larger than k
		p.AddToList(); // add the new permutation to the list
		if (p.IsListBufFull()) { //check list buffer is full
			p.PrintList(ofs);
			p.ResetList(); // reset currentRow
		}
		firMob = -1;
		totalCounter++; // count 
	}

	p.PrintList(ofs);
	WritePostLog(ofs, totalCounter);
	CloseOutFile(ofs);
}

// Pre:  None.
// Post: Creat out file, if failure, throw exception on screen, and exit system.
void OpenOutFile(std::ofstream &ofs, const char path[])
{
	ofs.open(path, ofstream::out);

	if (!ofs) // failure of opening file
	{
		cout << "File opening failed" << endl;
		system("PAUSE");
		exit(1);
	}
}

// Pre:  ofs open
// Post: Close ofs.
void CloseOutFile(std::ofstream & ofs)
{
	ofs.close();
}


//pre: current Num is a postive integer
//post : write proLog at the beign of output
void WriteProLog(std::ofstream &ofs, int num)
{

	ofs << "There are ";
	ofs << GetFactorial(num);
	ofs << " permutations of the set {" << 1;
	for (int i = 1; i < num; i++) {
		ofs << "," << i + 1;
	}
	ofs << "}:" << endl;
}

void WritePostLog(std::ofstream &ofs ,const int num)
{
	ofs << "The number of permutations above is: " << num << endl;
}

//pre: num is a postive number
//post: return factorial of num
long long GetFactorial(const int num)
{
	long long ret = 1;
	for (int i = 1; i <= num; i++)
		ret *= i;
	return ret;
}

// pre: none
// post: test 1-10 all permutations, and output into local file "num_permutations.txt"
void TestAuto()
{
	Permutation pmt; // creat an instance of class Permutation
	for (int i = 1; i<6; i++) {

		// generate full path
		stringstream ss;
		ss << i << BASE_PATH;
		string fullPath = ss.str();

		GenAllPermutations(pmt, i, fullPath.c_str()); // call GenAllPermutations
		cout << "# Congraution ^_^ Relative path of generated permutation(s): " << fullPath << endl;
	}
}



// pre: none
// post: test all permutations of an input positive, and output into local file "num_permutations.txt"
void TestManual()
{

	Permutation pmt; // creat an instance of class Permutation
	int n; // get number from screen

	cout << "# Please input a positive num, more than or equal 1, less than or equal 25: " << endl;
	
	cin >> n;
	if (n<0 || n> MAX_NUM) { // illegal n
		cout << "Illegal number >_<" << endl;
		return;
	}
	cout << "# Thank your patience for our computation..." << endl;

	// generate full path
	stringstream ss;
	ss << n << BASE_PATH;
	string fullPath = ss.str();

	GenAllPermutations(pmt, n, fullPath.c_str());
	cout << "# Congraution ^_^ Relative path of generated permutation(s): " << fullPath << endl;
}
