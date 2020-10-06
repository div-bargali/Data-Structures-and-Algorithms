#include <iostream> 
#include <stack> 
using namespace std;
int main() {
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	
         st.pop();
	st.pop();

	while (!st.empty()) {
		cout << ' ' << st.top();
		st.pop();
	}
}
