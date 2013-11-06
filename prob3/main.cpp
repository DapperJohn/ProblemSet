#include <iostream>
#include <string>
#include <fstream>
#include <queue>

#include <cstdio>
#include <cstdlib>

#include "AVLTree.h"
#include "timer.h"

using namespace std;

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

	printf("%d", test.rank(0));
	printf("%d", test.rank(9));
	printf("%d", test.rank(2));

    timer.stopTimer();

    cout << timer.getElapsedTime();
	// NOT WORKING..... printf("%d", rank(root, 2));
}
/*
    /bool found = false;
    struct node *root = NULL;
    string line;
    ifstream inputFile("AVLtree-input.txt");

    // Reading input file
    inputFile.open("AVLtree-input", ifstream::in);
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
            cout << line << endl;
        inputFile.close();
    }
    else cout << "Unable to open file" << endl;

    // Construct Tree
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Pre order traversal of AVL tree is \n");
    preOrderTraversal(root);
    printf("\nIn order traversal of AVL tree is \n");
    inOrderTraversal(root);

    print(root);

    /* AVL Tree after inserts

                  9
                 / \
                1   10
               / \    \
              0   5    11
             /   / \
            -1  2   6

    *//*

    root = erase(root, 10);
    printf("\nPre order traversal after deletion \n");
    preOrderTraversal(root);

    /* AVL Tree after deletion

                  1
                 / \
                0   9
               /   / \
             -1   5   11
                 / \
                2   6

    *//*

    printf("\n");
    found = search(root, 7);
    printf("Search for 7 = ");
    printf(found ? "Number found!" : "Number not found!");

    printf("\n");
    found = search(root, 11);
    printf("Search for 11 = ");
    printf(found ? "Number found!" : "Number not found!");

    printf("%d", rank(root, 0));
    printf("%d", rank(root, 1));
    // NOT WORKING..... printf("%d", rank(root, 2));


    printf("\n%d\n", select(root, 2));
    printf("\n%d\n", select(root, 3));





    return 0;
}*/