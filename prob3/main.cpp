#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <queue>
#include <map>

#include <cstdio>
#include <cstdlib>
 
#include "AVLTree.h"
#include "timer.h"

using namespace std;

//class TestResult {public: bool success; int timeMs;};
//typedef struct TestResult { bool success = false; int timeMs = 0; } TestResult;
//struct;
//typedef AVLTree (*TestFunc)();
//typedef function<TestResult(AVLTree)> TestFunc();
//typedef function<TestResults(AVLTree&)> ();
//auto lambda = [](AVLTree x) { return x; };
//typedef	map<string, TestResult> TestMap;

int main()
{
	// Read in elements to sort.
	/*inputFile.open("10exp6.txt");
	while (!inputFile.eof()) { // Probably should read input from file each time, but whatevs
		int tmp = 0;
		inputFile >> tmp;
		if (tmp > 0) {
			radixTestList.push_back(tmp);
			qsortTestList.push_back(tmp);
		}
	}
	inputFile.close();*/
	//TestResult result;
	//map<string, TestResult> TestMaps;
	//TestMap tests;

	FILE *fptr = fopen("AVLTree-input.txt", "r");
	char* testSwitch; int input, numRead;

	while(!feof ( fptr ) && fscanf(fptr, "%s %d", testSwitch, &input))
	{
		printf("testSwitch: %s\ninput: %d\n\n", testSwitch, input);
	}
	

	fclose(fptr);

	CStopWatch timer;
	timer.startTimer();

	AVLTree test;
	test.insert(9);
	test.insert(5);
	test.insert(10);
	test.insert(0);
	test.insert(6);
	test.insert(11);
	test.insert(-1);
	test.insert(1);
	test.insert(2);

	printf("Pre order traversal of AVL tree is \n");
	test.preOrderTraversal();
	printf("\nIn order traversal of AVL tree is \n");
	test.inOrderTraversal();

	test.print();

	test.erase(10);
	printf("\nPre order traversal after deletion \n");
	test.preOrderTraversal();

	test.print();

	printf("\n");
	printf("Search for 7 = ");
	printf(test.search(7) ? "Number found!" : "Number not found!");

	printf("\n");
	printf("Search for 11 = ");
	printf(test.search(11) ? "Number found!" : "Number not found!");

	//printf("%d", test.rank(0));
	//printf("%d", test.rank(9));
	//printf("%d", test.rank(2));

    timer.stopTimer();

    cout << timer.getElapsedTime();
}