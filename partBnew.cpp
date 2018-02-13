#include <bits/stdc++.h>
using namespace std;

int main () {

	int N; //Precondition: N>= 1 && N <= 100000
	cin >> N;
	bool stackcheck = false; //Setting flags for the different possible data structures 
	bool queuecheck = false;
	
	do {
		int command[2]; 
		stack <int> store1; //Declaring a stack called store1
		queue <int> store2; //Declaring a queue called store2
		for (int i = 0; i < N; i++) {
			cin >> command[0] >> command[1];
			if (command[0] == 1) { //First operation
				store1.push(command[1]);
			store2.push(command[1]);
			} else {
				if((!store1.empty()) && (store1.top() == command[1])){
					store1.pop();
					stackcheck = true;
				} if ((!store1.empty()) && (store1.top() != command[1])) {
					stackcheck = false; //reset it, in-case it had been set to true in a previous iteration
				} if ((!store2.empty()) && (store2.front() == command[1])) {
					store2.pop();
					queuecheck = true;
				} if ((!store2.empty()) && (store2.front() != command[1])) {
					queuecheck = false; //reset, similar to stack
				} 
			}
		}					

		if (stackcheck && (!queuecheck)) 
			cout << "stack" << endl;
		else if ((!stackcheck) && queuecheck) 
			cout << "queue" << endl;
		else if (stackcheck && queuecheck)
			cout << "not sure" << endl;
		else
			cout << "impossible" << endl;

		stackcheck = false;
		queuecheck = false;
		cin >> N;

	} while (N != 0);

	return 0;
}


