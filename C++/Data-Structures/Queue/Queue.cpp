// stl library for cp
#include <iostream> 
#include <queue> 
  
using namespace std; 

//function for queue
void showq(queue <int> gq) 
{ 
    queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 

//main  
int main() 
{ 
    queue <int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
  
    cout << "The queue q is : "; 
    showq(q); 
  
    cout << "\nq.size() : " << q.size(); 
    cout << "\nq.front() : " << q.front(); 
    cout << "\nq.back() : " << q.back(); 
  
    cout << "\nq.pop() : "; 
    q.pop(); 
    showq(q); 
  
    return 0; 
} 


/*
Output:

The queue q is :     10    20    30

q.size() : 3
q.front() : 10
q.back() : 30
q.pop() :     20    30
*/
