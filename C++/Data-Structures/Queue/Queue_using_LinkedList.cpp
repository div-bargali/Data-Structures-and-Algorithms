#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node {                           //create class
public:
   T data;
   Node<T>* next;
   Node(T data) {
      this->data = data;
      next = NULL;
   }
};
template <typename T>
class QueueUsingLL {
   int size;
   Node<T> *head;
   Node<T> *tail;
public:
   QueueUsingLL() {
      size = 0;
      head = NULL;
      tail = NULL;
   }
   int getsize() {                        //get size of queue
      return size;
   }
   bool isEmpty() {                     //get empty or not of queue
      return size == 0;
   }
   void enqueue(T element) {               //insert data
      Node<T>* newNode = new Node<T>(element);
      if (head == NULL) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         tail = newNode;
      }
      size++;
   }
   T front() {                           //print first of queue
      if (head == NULL) {
         cout << "Queue is empty!";
      }
      return head->data;
   }

   T dequeue() {                        //delete of queue
      if (head == NULL) {
         cout << "Queue is empty!";
      }
      T ans = head->data;
      Node<T> * temp = head;
      head = head->next;
      delete temp;
      size--;
      return ans;
   }

};



int main() {                           //driver 
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   QueueUsingLL<int> q;
   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);
   q.enqueue(40);
   q.enqueue(50);
   q.enqueue(60);
   q.enqueue(70);
   q.enqueue(80);
   q.enqueue(90);
   cout << q.front() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.getsize() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.dequeue() << endl;
   cout << q.front() << endl;
   cout << q.isEmpty() << endl;

   return 0;
}
