/*
The code is for range queries and range updates using segment tree with lazy propagation. All the queries take log(n) time.
*/

#include<bits/stdc++.h>
using namespace std;
#define sz(a)               ll((a).size())
#define ll                  long long
#define int                 ll
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
#define input(a,n)          for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n)         for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define inputt(a,n,m)       for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>a[i][j]
#define outputt(a,n,m)      for(ll i=0;i<n;i++){for(ll j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define pi                  pair<ll,ll>
#define inf                 LLONG_MAX
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                  1000000009
#define pie                 3.1415926535897932384626433832795

vi tree(4*N),lazy(4*N,0),v(N);                              //insert first data
void push(ll node) {
    tree[node*2] += lazy[node];
    lazy[node*2] += lazy[node];
    tree[node*2+1] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
}
void build(ll node, ll left, ll right){                     
    if(left == right){
        tree[node] = v[left];
    }
    else{
        ll mid = (left + right) / 2;
        build(2*node, left, mid);
        build(2*node+1, mid+1, right);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(ll node,ll left,ll right,ll l,ll r,ll add) {    //insert new data
    if(r < left || right < l){
        return;
    }
    push(node);
    if(l <= left && r >= right){
        tree[node]+=add;
        lazy[node]+=add;
    }
    else {
        ll mid = (left + right) / 2;
        update(2*node,left,mid,l,r,add);
        update(2*node+1,mid+1,right,l,r,add);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
}

ll query(ll node,ll left,ll right,ll l,ll r){   //get data
    if(l>r){
        return -inf;
    }
    push(node);
    if(l>right || r<left){
        return -inf;
    }
    if(left>=l && right<=r){
        return tree[node];
    }
    ll mid=(left+right)/2;
    return max(query(node*2,left,mid,l,r),query(node*2+1,mid+1,right,l,r));
}
int32_t main(){

    ll n;                   // length of array
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    build(1,0,n-1);         // building segment tree
    ll m;                   // number of queries
    cin>>m;
    for(ll i=0;i<m;i++){
        int q;
        cin>>q;
        if(q==1){   // update
            // left is the left index, right is the right index (0 based indexing) and add is the value to be added to the segment [left,right]
            ll left,right,add;      
            cin>>left>>right>>add;
            update(1,0,n-1,left,right,add);
        }
        else{        // query
            // left is the left index, right is the right index (0 based indexing) it will print the maximum value in the segment [left,right]
            ll left,right;
            cin>>left>>right;
            cout<<query(1,0,n-1,left,right)<<endl;
        }
    }
    return 0;
}
