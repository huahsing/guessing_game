#include <bits/stdc++.h>
using namespace std;

int main () {

	int N; //Precondition: N>= 1 && N <= 100000
	cin >> N;
	bool stackcheck = false; //Setting flags for the different possible data structures 
	bool queuecheck = false;
	bool pricheck = false; 

	do {
		int command[2]; 
		stack <int> store1; //Declaring a stack called store1
		queue <int> store2; //Declaring a queue called store2
		priority_queue <int> store3; //Declaring a vector to represent a max priority queue called store3

		for (int i = 0; i < N; i++) {
			cin >> command[0] >> command[1];
			if (command[0] == 1) { //First operation - Pushing in elements into each of the different data structures
				store1.push(command[1]);
				store2.push(command[1]);
				store3.push(command[1]);
			} else {
				if((!store1.empty()) && (store1.top() == command[1])) {
					stackcheck = true;
					store1.pop();
				} else {
					stackcheck = false;
				} if ((!store2.empty()) && (store2.front() == command[1])) {
					store2.pop();
					queuecheck = true; 
				} else {
					queuecheck = false;
				} if((!store3.empty()) && (store3.top() == command[1])) { //check for priority queue
					store3.pop();
					pricheck = true;
				} else
					pricheck = false;
			}
		}					

		if (stackcheck && (!queuecheck) && (!pricheck)) 
			cout << "stack" << endl;
		else if ((!stackcheck) && queuecheck && (!pricheck)) 
			cout << "queue" << endl;
		else if ((!stackcheck) && (!queuecheck) && pricheck)
			cout << "priority queue" << endl;
		else if ((stackcheck && queuecheck) || (stackcheck && pricheck) || (queuecheck && pricheck) || (stackcheck && queuecheck && pricheck))
			cout << "not sure" << endl;
		else
			cout << "impossible" << endl;

		stackcheck = false;
		queuecheck = false;
		pricheck = false;
		cin >> N;

	} while (N != 0);

	return 0;
}


