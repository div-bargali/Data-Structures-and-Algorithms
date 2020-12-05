#include<bits/stdc++.h>
using namespace std;
template <typename T>

class QueueUsingArray {            //create class
   T* data;
   int firstIndex;
   int nextIndex;
   int size;
   int capacity;
public:
   QueueUsingArray() {
      data = new T[5];
      firstIndex = -1;
      nextIndex = 0;
      size = 0;
      capacity = 5;
   }
   int getsize() {                     //return size of aueue
      return size;
   }
   bool isEmpty() {                  //empty or not
      return size == 0;
   }
   void enqueue(T element) {            //insert data
      if (size == capacity)
      {
         int j = 0;
         T* newData = new T[capacity * 2];
         for (int i = firstIndex; i < capacity; i++) {
            newData[j] = data[i];
            j++;
         }
         for (int i = 0; i < firstIndex; i++) {
            newData[j] = data[i];
            j++;
         }
         delete [] data;
         data = newData;
         firstIndex = 0;
         nextIndex = capacity;
         capacity *= 2;
      }
      data[nextIndex] = element;
      nextIndex = (nextIndex + 1) % capacity;
      if (firstIndex == -1) {
         firstIndex = 0;
      }
      size++;
   }
   T front() {                        //print first data
      if (isEmpty()) {
         cout << "Queue is empty!" << endl;
         return 0;
      }
      return data[firstIndex];
   }

   T dequeue() {                     //delete data
      if (isEmpty()) {
         cout << "Queue is empty!" << endl;
         return 0;
      }
      T ans = data[firstIndex];
      firstIndex = (firstIndex + 1) % capacity;
      size--;
      if (size == 0) {
         firstIndex = -1;
         nextIndex = 0;
      }
      return ans;
   }

};



int main() {                        //driver
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   QueueUsingArray<int> q;
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
