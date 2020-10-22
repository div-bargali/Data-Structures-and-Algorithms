#include <bits/stdc++.h>
using namespace std;
#define sz(a)               int((a).size())
#define ll                  long long
#define pb                  push_back
#define ld                  long double
#define mp                  make_pair
#define vi                  vector<ll>
#define vii                  vector<pi>
#define endl                "\n"
#define ff                  first
#define ss                  second
#define all(c)              (c).begin(),(c).end()
#define allr(c)             (c).rbegin(),(c).rend()
#define rep(i,n)            for(ll i=0;i<n;i++)
#define cpresent(c,x)       (find(all(c),x) != (c).end())
#define input(a,n)          for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n)         for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define vl                  LLONG_MIN
#define vm                  LLONG_MAX
#define ep                  1e-10
#define seed                13331
#define pi                  pair<ll,ll>
#define inf                 10e9
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                  1000000009
#define pie                 3.1415926535897932384626433832795
#define eu                  2.718281828459045
#define                     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);    clock_t startTime=clock();
#define time     cout<<(double(clock()-startTime )/(double)CLOCKS_PER_SEC)*1000<<" ms"<<endl;
#define debug(k) cout<<"\t-> "<<#k<<" = "<<k<<endl;


bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b)
{
    return b?gcd(b, a % b):a;
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll n,m;
vi visited(N,0),dis(N,0);
vector<pair<ll,ll> > adj[N];        // value, node
ll arr[1000][1000];
void warshall()
{
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
}
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(mp(c,b));
        adj[b].pb(mp(c,a));
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
            arr[i][j]=INT_MAX;
    }
    for(ll i=1;i<=n;i++)
        arr[i][i]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<adj[i].size();j++)
        {
            arr[i][adj[i][j].ss]=adj[i][j].ff;
            arr[adj[i][j].ss][i]=adj[i][j].ff;
        }
    }
    warshall();
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
