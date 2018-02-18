#include <bits/stdc++.h>
using namespace std; 

class type1 {
	private:
		int stk[100010];
		int topval = 0;

	public:
		void push (int x) { 
			stk[topval++] = x;
		}

		void pop () {
			if (topval > 0) 
				topval = topval - 1;
		}

		int top () {
			return stk[topval-1];
		}
}; 

class type2 {
	private:
		int que[100010];
		int frontval = 0;
		int backval = 0; 

	public:
		void push (int x) {
			que[backval++] = x; 
		}

		void pop () {
			if (backval > 0) 
				frontval = frontval + 1;
		}

		int front () {
			return que[frontval];
		}
};

class type3 {
	private:
		int frontval = 0;
		int backval = 0;
		int pri[100010];

	public:
		void push (int x) {
			int i;
			for (i=backval-2; (i>=0 && pri[i] < x); i--) //Checking to see where value should be inserted
				pri[i+1] = pri[i]; //Shifting the values to the right
			pri[i+1] = x;
		}

		void pop () {
			if (backval > 0) 
				frontval = frontval + 1;
		}

		int top () {
			return pri[frontval];
		}
};

int main (void) {
	int N;
	cin >> N;

	int check1 = 1; //for stacks
	int check2 = 1; //for queues
	int check3 = 1; //for priority queue

	do {
		int command[2];
		type1 obj1;
		type2 obj2;
		type3 obj3;

		for (int i = 0; i < N; i++) {
			cin >> command[0] >> command[1];
			if (command[0] == 1) {
				obj1.push (command[1]);
				obj2.push (command[1]);
				obj3.push (command[1]);
			} else if (command[0] == 2) {
				if ((check1 != 0) && (obj1.top() == command[1])) 
					obj1.pop();
				else 
					check1 = 0;
				if ((check2 != 0) && (obj2.front() == command[1]))
					obj2.pop();
				else 
					check2 = 0;
				if ((check3 != 0) && (obj3.top() == command[1]))
					obj3.pop();
				else 
					check3 = 0; 
			}
		}

		if ((check1) && (!check2) && (!check3))
			cout << "stack" << endl;
		else if ((!check1) && (check2) && (!check3))
			cout << "queue" << endl; 
		else if ((!check1) && (!check2) && (check3))
			cout << "priority queue" << endl;
		else if ((check1 && check2) || (check1 && check3) || (check2 && check3) || (check1 && check2 && check3)) 
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









