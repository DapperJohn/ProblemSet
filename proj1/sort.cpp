#include <iostream>
#include <fstream>
#include <list>
#include <ctime>

//John Anny and Selby Kendrick
//CSC 3102 Sect 001
//November 5th, 2013
//Problem #1
//
//Description:
//Quicksort and radix sort comparison main program

using namespace std;

const bool PRINT_LISTS = false; // Flag to print input and sorted lists
const bool PRINT_TRIALS = true; // Flag to each trial runtime
const unsigned short int NUM_TRIALS = 100; // Amt of trials to take average Note: 1000 trials gets 10^3 input elements within +- ~5 ms

void sort(list<int> &input); // Radix sort

int main()
{
	clock_t start, stop;
	float runtime, radixAvg = 0, qsortAvg = 0;

	ifstream inputFile;
	list<int> radixTestList; // Yeah, lists are slower that straight up array.  But they're hella more convenient 
	list<int> qsortTestList;
	
	for(int i = 0; i < NUM_TRIALS; ++i)
	{
		// Read in elements to sort.
		inputFile.open("10exp6.txt");
		while(!inputFile.eof()) // Probably should read input from file each time, but whatevs
		{
			int tmp = 0;
			inputFile >> tmp;
			if(tmp > 0)
			{
				radixTestList.push_back(tmp);
				qsortTestList.push_back(tmp);
			}
		}
		inputFile.close();

		cout << "# Input: " << radixTestList.size() << endl;
		
		// Measure runtime of radix sort
		start=clock(); // Start clock
		sort(radixTestList); // Radix (Bucket) Sort list
		stop=clock(); // Stop clock

		runtime = ((float)stop-(float)start); // Calc time in ms

		radixAvg = (radixAvg*i + runtime)/(i+1);

		if(PRINT_LISTS) // Print sorted array if desired
		{
			for (std::list<int>::iterator it=radixTestList.begin() ; it != radixTestList.end(); ++it)
			cout << ' ' << *it;
			cout << endl;
		}
		if(PRINT_TRIALS)
			cout<< runtime << " ms" << endl;

		// Measure runtime of qsort sort
		start=clock();
		qsortTestList.sort();
		stop=clock();

		runtime = ((float)stop-(float)start);

		qsortAvg = (qsortAvg*i + runtime)/(i+1);

		if(PRINT_LISTS) // Print sorted array if desired
		{
			for (std::list<int>::iterator it=qsortTestList.begin() ; it != qsortTestList.end(); ++it)
			std::cout << ' ' << *it;
			cout << endl;
		}
		if(PRINT_TRIALS)
			cout<< runtime << " ms" << endl;

		// Empty the lists so we can do it all over again
		radixTestList.clear();
		qsortTestList.clear();
	}

	// Finally.  What we've all been waiting for.
	cout << "Radix Avg: " << radixAvg << " ms" << endl;
	cout << "qsort Avg: " << qsortAvg << " ms" << endl;
}

/**
 * Radix sort using two rounds of 256 buckets (unsigned short ints only)
 * @param input list of unsigned short ints
 */
void sort(list<int> &input)
{
	list<int> bucketsOne[256];
	list<int> bucketsTwo[256];
	int bucketNum;

	while(!input.empty())
	{
		bucketNum = input.front()/256;
		bucketsOne[bucketNum].splice(
			bucketsOne[bucketNum].end(),
			input,
			input.begin()
		);
	}
	for(int i = 0; i<256; ++i)
	{
		while(!bucketsOne[i].empty())
		{
			bucketNum = bucketsOne[i].front()%256;
			bucketsTwo[bucketNum].splice(
				bucketsTwo[bucketNum].end(),
				bucketsOne[i],
				bucketsOne[i].begin()
			);
		}
		for(int j = 0; j<256; ++j)
		{
			if (!bucketsTwo[j].empty())
			{
				input.splice(
					input.end(),
					bucketsTwo[j]
				);
			}
		}
	}
}