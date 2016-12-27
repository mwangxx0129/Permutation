#ifndef _APPPERMUTATION_H_
#define _APPPERMUTATION_H_

#include "Permutation.h"

const char BASE_PATH[64] = "_permutations.txt"; // base address of outputfile

void GenAllPermutations(Permutation& p, const int num, const char path[]);
void OpenOutFile(std::ofstream &ofs, const char path[]);
void CloseOutFile(std::ofstream &ofs);
long long GetFactorial(const int num);

void WriteProLog(std::ofstream &ofs, int num);
void WritePostLog(std::ofstream &ofs, const int num);

void TestAuto();
void TestManual();

#endif // !_APPPERMUTATION_H_