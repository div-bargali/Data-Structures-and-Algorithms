// fenwick tree code
// one application for finding the number of inversions in an array


// definition of inversion-----> 
// in an array if there is a pair of index i,j such that
// i < j and array[i] > array[j] is counted as one inversion

#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i)){
		bit[i] += x;
		cout<<"update "<<i<<endl;
		}
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i)){
		ans += bit[i];
	cout<<"sum bit "<<i<<endl;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	long long a[n+10];
	map<long long,int> mp;
	for(int i = 1;i <= n; ++i){
		cin >> a[i];
		mp[a[i]];
	}


	// compression of numbers for the case where a[i] > 10 ^ 6
	int ptr = 1;
	for(auto &pr : mp){
		pr.second = ptr++;
	}

	for(int i = 1; i <= n; ++i){
		a[i] = mp[a[i]];
	}

	// Finding Inversion count


	int inversion_ct = 0;
	for(int i = n; i>= 1; --i){
	//  cout<<"sum n "<<sum(N)<<endl;
	  //cout<<"sum ai "<<sum(a[i])<<endl;
		inversion_ct += sum(a[i]);
		cout<<"invv "<< inversion_ct << endl;
		//	cout 

		update(a[i], 1);
		cout<<"tree ";
		for(int i=1;i<=n;i++){
			cout<<bit[i]<<" ";
		}
		cout<<endl;
	}

	cout << inversion_ct << endl;


}
