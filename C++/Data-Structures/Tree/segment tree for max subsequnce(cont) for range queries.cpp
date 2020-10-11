#include <bits/stdc++.h>
using namespace std;

/*Structure that is used to
store value*/
struct node
{
    int sum,prefixsum;
    int suffixsum,maxsum;
};

node tree[4*50010];
int arr[50010];

/*This function is used to build the
segment tree*/
void build(int index,int start,int end)
{
    if(start == end)
    {
        tree[index].sum = arr[start];
        tree[index].prefixsum = arr[start];
        tree[index].suffixsum = arr[start];
        tree[index].maxsum = arr[start];
    }
    else
    {
        int mid = (start+end)/2;
        build(2*index+1,start,mid);
        build(2*index+2,mid+1,end);

        /*Note how we use the array to access the left
        and right subtree*/
        tree[index].sum =
            tree[2*index+1].sum + tree[2*index+2].sum;
        tree[index].prefixsum =
            max(tree[2*index+1].prefixsum,
                tree[2*index+1].sum + tree[2*index+2].prefixsum);
        tree[index].suffixsum =
            max(tree[2*index+2].suffixsum,
                tree[2*index+2].sum + tree[2*index+1].suffixsum);
        tree[index].maxsum =
            max(tree[index].prefixsum,
                max(tree[index].suffixsum,
                    max(tree[2*index+1].maxsum,
                        max(tree[2*index+2].maxsum,
                            tree[2*index+1].suffixsum
                            +tree[2*index+2].prefixsum
                           )
                       )
                   )
               );
    }
}

/*this function is used to return the result
for each query*/
node query(int index,int start,int end,int l,int r)
{
    node result;
    result.sum=result.prefixsum=INT_MIN;
    result.suffixsum=result.maxsum=INT_MIN;

    if(r<start || end<l)
        return result;
    if(l<=start && end<=r)
        return tree[index];

    int mid = (start+end)/2;
    if (l > mid)
        return query(2*index+2, mid+1, end, l, r);
    if (r <= mid)
        return query(2*index+1, start, mid, l, r);

    node left = query(2*index+1,start,mid,l,r);
    node right = query(2*index+2,mid+1,end,l,r);

    result.sum = left.sum + right.sum;
    result.prefixsum =
        max(left.prefixsum, left.sum + right.prefixsum);
    result.suffixsum =
        max(right.suffixsum, right.sum + left.suffixsum);
    result.maxsum =
        max(result.prefixsum,
            max(result.suffixsum,
                max(left.maxsum,
                    max(right.maxsum,
                        left.suffixsum + right.prefixsum))));
    return result;
}

int main()
{
    int n,m,a,b;
    scanf("%d",&n);

    for(int i=0; i<n; ++i)
        scanf("%d",&arr[i]);

    build(0,0,n-1);

    scanf("%d",&m);

    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",query(0,0,n-1,a-1,b-1).maxsum);
    }
    return 0;
}
