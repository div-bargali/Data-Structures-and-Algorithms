#include <bits/stdc++.h>
using namespace std;
struct ne
{
    long long int z;
    long long int y;
};
bool compute(struct ne w,struct ne x)
{
    double r1=(double)w.z/w.y;
    double r2=(double)x.z/x.y;
    return r1>r2;
}
double knacpsack(long long int w,struct ne arr[],long long int n)
{
    sort(arr,arr+n,compute);
    long long int weight=0,i,x;
    double value=0.0;
    for(i=0;i<n;i++)
    {
        if(weight+arr[i].y<=w)
        {
            weight=weight+arr[i].y;
            value=value+arr[i].z;
        }
        else
        {
          x=w-weight;
          value=value+arr[i].z*((double)x/arr[i].y);
          break;
        }
    }
    printf("%.4lf",value);
}
int main()
{
   long long int n,w,i;
   cin>>n>>w;
  ne arr[n];
   for(i=0;i<n;i++)
    cin>>arr[i].z>>arr[i].y;

    knacpsack(w,arr,n);
}

