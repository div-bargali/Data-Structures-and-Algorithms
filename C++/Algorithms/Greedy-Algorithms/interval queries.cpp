#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	// this program will give an intuition behind the solution for CP questions based on interval quries. Refer to the question 
	//http://codeforces.com/gym/294377/problem/E

	//this following two lines are used for fast input-output
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) //running the program for 't' test cases
    {
        int n;
        cin>>n; //number of students in th college

        //declare an array of max size (based on the input constraint) to indicate the timeline of all the students
        int N=2*100000;
        int a[N]={0};

        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            // while taking the entering and leaving time of each student, increase the (x-1)th index by one and decrease the (y-1)th index by 1.  
            a[x-1]+=1;
            a[y-1]-=1;// Here the student is outside the college during the yth sec, hence we subtract 1 from (y-1)th index. Else we would subtract the same from yth index  
        }
        for(int i=1;i<2*100000;i++)
        {
            // Summing the value in the current index by its previous index's value will give the total number of students at a perticular instance of time on the timeline a[N] 
            a[i]+=a[i-1];
        }
        int q;
        cin>>q;
        while(q--)// running a loop to ans all the queries
        {
            int pp;
            cin>>pp;// The required time to output number of students present at that particular instance 

            // We can find out the number of students present at that perticular time by accessing the value stored in the array 'a' at (pp-1) index
            cout<<a[pp-1]<<endl;   
        }
    }
	return 0;
}
