#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T> *next;
	Node(T data) {
		this->data = data;
		next = NULL;

	}
};
template<typename T>
class StackUsingLL {
	Node<T>* head;
	int size;
public:
	StackUsingLL() {
		head = NULL;
		size = 0;
	}

	int getsize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void push(T n) {
		Node<T> *newNode = new Node<T>(n);
		newNode->next = head;
		head = newNode;
		size++;
	}
	T pop() {
		if (isEmpty()) {
			return 0;
		}
		T ans = head->data;
		Node<T> *temp = head;
		head = head->next;
		delete temp;
		size--;
		return ans;
	}
	T top() {
		if (isEmpty()) {
			return 0;
		}
		return head->data;
	}


};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	StackUsingLL<char> s;
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);


	cout << s.getsize() << endl;
	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}