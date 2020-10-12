#include<bits/stdc++.h>
using namespace std;
int n=1000;
vector<int> graph[1002];
int vis[n]={0};
void dfs(int root)// dfs using stack
{vis[root]=1;
stack st;
st.push(root);
while(!st.empty())
{ int k=st.top();
st.pop();
for(i=0;i<graph[k].size();i++)
{
if(vis[graph[k][i]==0)
{st.push(graph[k][i]);
vis[graph[k][i]=1;}
}
}
}

 

int main() {

int n;// no of vertex
int e;//no of edges
for(i=0;i<e;i++)
{int c,d;//which two have edges
cin>>c>>d;
graph[c].push_back(d);
graph[d].push_back(c);
}
dfs(1);
	return 0;
}
