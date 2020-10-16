//g++  7.4.0
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
bool v[100000]={false};
vector<int>g[100000];
int level[100000];
int cy=0;
void edge(int a,int b)
{
    g[a].pb(b);
    g[b].pb(a);

}
void  dfs(int n,int p)
{
    //cout<<n<<" "<<p<<"  main"<<endl;
      v[n]=true;
        for(int i=0;i<g[n].size();i++)
        {
            if(g[n][i]!=p)
            {
                if(v[g[n][i]]==true)
                {
                     cy=1;
                }
                 else
                {
                 dfs(g[n][i],n);
                }
            }

            }

}


int main()
{
    int n,e,a,b;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        edge(a,b);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==false)
        {
        dfs(i,-1);
        cout<<i<<endl;
        }
    }

   cout<<cy;
   if(cy==1)
   {
       
       cout<<"CYCLE DETECTED"
   }
   else
   {
       
       cout<<"NO CYCLE DETECTED"
   }
}
