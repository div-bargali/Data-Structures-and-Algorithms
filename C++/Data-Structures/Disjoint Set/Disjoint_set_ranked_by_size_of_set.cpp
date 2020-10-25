#include<iostream>

using namespace std;
/*
In a lot of cases,size of disjoint sets are also needed.
So instead of using a rank array we can use the sizes of
each set for union operation.
*/
class Disjoint_set
{
private:
    int *size,*par,n;    
public:
    Disjoint_set(int n){
        this->n=n;
        par=new int[n];
        size=new int[n];
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }

    int find(int x){
        /* returns the root of the set*/
        if(par[x]!=x)
            par[x]=find(par[x]);

        return par[x];
    }

    void unin(int x,int y){
        /*Union of two disjoint sets*/
        int px=find(x);
        int py=find(y);

        if(px!=py){
            if(size[px]<size[py])
             swap(px,py);

            par[py]=px;
            size[px]+=size[py];
        
        }

    }

    int size_of_set(int x){
        /*returns the size of the set*/
        int px=find(x);
        return size[px];
    }
    
};

int main(){
    Disjoint_set dsu(100);
    dsu.unin(1,2);
    dsu.unin(3,4);
    dsu.unin(1,4);
    dsu.unin(2,3);
    dsu.unin(7,1);
    dsu.unin(7,6);
    cout<<dsu.size_of_set(1)<<endl;
    cout<<dsu.size_of_set(7)<<endl;
    cout<<dsu.size_of_set(89)<<endl;
    if(dsu.find(1)==dsu.find(6))
        cout<<"belongs to the same set"<<endl;
    if(dsu.find(1)!=dsu.find(99))
        cout<<"belongs to different set"<<endl;

}
