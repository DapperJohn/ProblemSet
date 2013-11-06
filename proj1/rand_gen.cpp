#include <iostream>
#include <fstream>
#include <cstdlib>

//John Anny and Selby Kendrick
//CSC 3102 Sect 001
//November 5th, 2013
//Problem #1
//
//Description:
//Random Number Generator

using namespace std;

int main () {
  srand (time(NULL));
  ofstream myfile;
  myfile.open ("10exp8.txt");
  for(int i = 0 ; i < 100000000; ++i)
  	myfile << rand() % 65535 + 1 << endl;
  myfile.close();
  return 0;
}