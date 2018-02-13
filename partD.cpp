#include <bits/stdc++.h>
using namespace std;

void insertionSort(int [], int, int, int);

int main () {
	int arr1 [100010] = {0}; //for stack
	int arr2 [100010] = {0}; //for queue
	int arr3 [100010] = {0}; //for max priority queue

	int N;
	cin >> N;
	int i=0, j=0, k=0; //keep track of where to insert
	int queuefront=0, prifront=0; //keeps track of the front of the queue/ priority queue, so we dont have to actually pop the elements
	int check1 = 1, check2 = 1, check3 = 1; //check for each of the data structures
	int count=0; //counts how many times the first command is called and hence, is used to keep track of the number of elements in the priority queue

	do {
		int command[2];
		cin >> command[0] >> command[1];

		for(int a=0; a < N; a++) {
			if (command[0] == 1) {
				count++;
				arr1[i] = command[1];//inserting elements
				arr2[j] = command[1];
				arr3[k] = command[1];
				insertionSort(arr3, count, command[1], prifront); //sorting the elements in max priority queue in descending order
				i++;
				j++;
				k++;
			} else if (command[1] == 2) {
				if ((arr1[i-1] == command[1]) && (check1 != 0)) { //top of stack check
					i = i-1; //deleting element without actually deleting
				} else {
					check1 = 0;
				} if ((arr2[queuefront] == command[1]) && (check2 != 0)) { //for queues
					queuefront++;
				} else {
					check2 = 0;
				} if ((arr3[prifront] == command[1]) && (check3 != 0)) { //for priority queue
					prifront++;
					count = count - 1; //the size of the max priority queue reduces by 1
				} else {
					check3 = 0;
				}
			}
		} 

		if(check1 && (!check2) && (!check3)) 
			cout << "stack" << endl;
		else if(check2 && (!check1) && (!check3)) 
			cout << "queue" << endl;
		else if(check3 && (!check1) && (!check2))
			cout << "priority queue" << endl; 
		else if((check1 && check2) || (check1 && check3) || (check2 && check3) || (check1 && check2 && check3))
			cout << "not sure" << endl;
		else
			cout << "impossible" << endl;

		check1 = 1;
		check2 = 1;
		check3 = 1;
		cin >> N;
	} while (N != 0);

	return 0;
}

void insertionSort(int values[], int size, int num, int front) {
	int i;
	for (i = size-2+front; ((i>=front) && (values[i] < num)); i--) //Checking to see where value should be inserted
		values[i+1] = values[i]; //Shifting the values to the right

	values[i+1] = num;
}
