#include <iostream>
#include <bits/stdc++.h> 
#include <climits>
#include <string.h>
#include <deque>

using namespace std;

int MergeSort(vector<int>& v, int l, int r);
int Merge(vector<int>& v, int l, int m, int r);
void PrintArray(const vector<int>& v);

/*
    LOGIC FOR FINDING THE NUMBER OF INVERSIONS:
    -   This can be found while merging two sorted subarrays l_arr and r_arr.	(Note that l_arr and r_arr are both sorted arrays)
    -   Let, i be the pointer iterating over l_arr and j be the pointer iterating over
        r_arr.
    PSEUDOCODE:
    int i=0; j=0;
    while(i<n1 && j<n2)
    {
        if(*i > *j)    //*i could defeat *j, means all values to the right of i can also defeat *j
        {
            inv_cnt = inv_cnt+(n1-i)    //now, this *j needn't be checked anymore.
            j++              		//since *i < *j, now, we need to check if it is greater than the next j element.. i.e., *(j+1)
        }        

        else        //*i < *j.. so, check with the next i value i.e., *(i+1)..
        {
            i++;
        }
    }
*/

int main()
{
    int n, inv_cnt;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n;i++)
        cin >> v[i];
    inv_cnt = MergeSort(v,0,v.size()-1);
    PrintArray(v);
    cout << "The inversion count is " << inv_cnt << endl;
    return 0;
}

int MergeSort(vector<int>& v, int l, int r)
{
    int inv_cnt=0; 
    if(l<r)
    {
        int m = l+((r-l)/2);
        /*
            Inversion count will be sum of inversions in left part,
            right part, and number of inversions in merging.
        */
        inv_cnt += MergeSort(v,l,m);
        inv_cnt += MergeSort(v,m+1,r);

        inv_cnt += Merge(v,l,m,r);
    }

    return inv_cnt;
}

int Merge(vector<int>& v, int l, int m, int r)
{
    int n1, n2, count=0;
    n1 = (m-l)+1;   n2 = r-m;

    vector<int> temp1;   //we can use a queue also, instead of deque
    vector<int> temp2;
    for(int i=l;i<l+n1;i++)
        temp1.push_back(v[i]);
    for(int i=m+1;i<m+1+n2;i++)
        temp2.push_back(v[i]);

    //merge step
    int temp, ind=l, i=0,j=0;
    while(i<n1 && j<n2)
    {
        v[ind] = min(temp1[i], temp2[j]);
        if(v[ind] == temp1[i])
            i++;
        else
            j++;
        ind++;
    }

    //if temp1 becomes empty
    while(j<n2)
    {
        v[ind] = temp2[j];
        j++;
        ind++;
    }

    //if temp2 becomes empty
    while(i<n1)
    {
        v[ind] = temp1[i];
        i++;
        ind++;
    }

    //finding the number of inversions now..
    i=0; j=0;
    while(i<n1 && j<n2)
    {
        if(temp1[i]>temp2[j])   //*i > *j, now it'll be ready to be compared with *(j+1)
        {
            count += (n1-i);
            j++;
        }

        else            // *i < *j. so, increment i pointer..
            i++;
    }

    return count;
}

void PrintArray(const vector<int>& v)
{
    for(auto num : v)
        cout << num << " ";
    cout << endl;
    return;
}


