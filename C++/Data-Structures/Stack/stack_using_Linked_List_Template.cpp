#include<bits/stdc++.h>
using namespace std;

template<typename T>                  //create Node class
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
class StackUsingLL {                  //create Stack class
   Node<T>* head;
   int size;
public:
   StackUsingLL() {                  //initial setting
      head = NULL;
      size = 0;
   }

   int getsize() {                     //get stack size
      return size;
   }
   bool isEmpty() {                  //get stack is empty or not
      return size == 0;
   }
   void push(T n) {                  //insert data
      Node<T> *newNode = new Node<T>(n);
      newNode->next = head;
      head = newNode;
      size++;
   }
   T pop() {                        //delete data
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
   T top() {                        //get first data
      if (isEmpty()) {
         return 0;
      }
      return head->data;
   }


};

int main() {                        //driver
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
