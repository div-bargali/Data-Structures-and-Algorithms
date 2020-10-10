#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
int n;//number of vertices
int m;//number of edges
cin>>n>>m;
int i;
vector<int> v[n+1];
for(i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;//input the vertices which are connected
    v[x].push_back(y); //put the vertex y in the list of x
    v[y].push_back(x); // put the vertex x in the list of y
}
int q;
cin>>q;// queries to check whether a edge exist or not
while(q--)
{
    int x,y;
    cin>>x>>y;//check whether edge between x or y exist or not
  int flg=-1;
    for(i=0;i<v[x].size();i++)
    {if(v[x][i]==y)
    {
        flg=1;break;
    }
        
    }
    if(flg==1)
    cout<<"Edge exist\n";
    else
    cout<<"Edge does not exist\n";
}
	return 0;
}
