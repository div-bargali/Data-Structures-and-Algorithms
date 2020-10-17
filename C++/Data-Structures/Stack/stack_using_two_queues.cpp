// Implement Stack operations pop(),push() using two queues
#include <bits/stdc++.h>
using namespace std;
class Stack
{
	queue<int> q1, q2;

public:
	// push function to get element into stack
	void push(int x)
	{
		// Push item into q1
		q1.push(x);
	}

	// pop the top element from the stack and return it
	int pop()
	{
		// if q1 is empty
		if (q1.empty()) {
			cout << "Stack is empty";
			return 0;
		}

		// Move all elements except last from q1 to q2
		int f;
		while (!q1.empty())
		{
			if (q1.size() == 1)
				f= q1.front();
			else
				q2.push(q1.front());

			q1.pop();
		}

		//last element (i.e when  q1 size==1 )is the element that will be returned after moving all elements except last to q1
		// Below loop can be replaced with a call to swap(q1, q2)
		while (!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}

		return f;
	}
};

int main()
{
	int a[]= { 1, 2, 3, 4};
	int n=sizeof(a)/sizeof(a[0]);

	// insert above elements into the stack
	Stack s;
	for (int i=0;i<n;i++) {
		s.push(a[i]);
	}

	for (int i = 0; i <n; i++)
		cout << s.pop() <<endl;

	return 0;
}
