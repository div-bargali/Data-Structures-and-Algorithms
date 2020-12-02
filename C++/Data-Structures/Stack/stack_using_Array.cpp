#include<bits/stdc++.h>
using namespace std;

template<typename T>
class StackUsingArray {                        //create class
   T *data;
   int nextIndex;
   int capacity;
public:
   StackUsingArray() {
      data = new T[capacity];
      capacity = 4;
      nextIndex = 0;
   }
   int size() {                           //get size
      return nextIndex;
   }
   bool isEmpty() {                        //get empty or not of stack
      return nextIndex == 0;
   }
   void push(T n) {                        //insert data
      if (nextIndex == capacity) {
         T *newData = new T[2 * capacity];
         for (int i = 0; i < capacity; i++) {
            newData[i] = data[i];
         }
         capacity = capacity * 2;
         delete[] data;
         data = newData;

      }
      data[nextIndex] = n;
      nextIndex++;
   }
   T pop() {                              //delete data
      if (isEmpty() == true) {
         cout << "Stack is empty" << endl;
         return 0;
      }
      nextIndex--;
      return data[nextIndex];
   }
   T top() {                              //return    
      return data[nextIndex - 1];
   }

};
int main() {                              //driver
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   StackUsingArray<int> s;
   s.push(101);
   s.push(102);
   s.push(103);
   s.push(104);
   s.push(105);


   cout << s.size() << endl;
   cout << s.top() << endl;
   cout << s.pop() << endl;
   cout << s.pop() << endl;
   cout << s.pop() << endl;
   cout << s.pop() << endl;
   cout << s.pop() << endl;
   return 0;
}
