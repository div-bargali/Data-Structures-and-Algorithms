#include<stdio.h>
#include<time.h>
#include<math.h>
double bubble(long int a[],long int d){
    long int n=d,temp;
    int flag=0;
    clock_t start,end;
    start=clock();

    for(long int i=0;i<d-1;i++){
        flag=0;
        for(long int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
        n--;
    }
    end=clock()-start;
    return((double)end/CLOCKS_PER_SEC);
}


double selection(long int a[],long int d){
    long int n=d,temp;
    clock_t start,end;
    start=clock();

    for(long int i=0;i<d-1;i++){
        for(long int j=i+1;j<d;j++){
            if(a[j]<a[i]){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }

    end=clock()-start;
    return((double)end/CLOCKS_PER_SEC);
}


double insertion(long int a[],long int d){
    long int i,key,j;
    clock_t start,end;
    start=clock();

    for(long i=1;i<d;i++) {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key) {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }

    end=clock()-start;
    return((double)end/CLOCKS_PER_SEC);
}

void merge(long int arr[],long int l,long int m,long int r){
    long int i,j,k;
    long int n1=m-l+1;
    long int n2=r-m;
    long int L[n1],R[n2];
    for (long i=0;i<n1;i++)
        L[i]=arr[l+i];
    for (long j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(long int a[],long int l,long int d){
    if (l<d){
        long int m=l+(d-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,d);
        merge(a,l,m,d);
    }
}

long int divide(long int a[],long int low,long int high){
    long int pivot=a[high];
    long int i=(low-1),t;

    for(long int j=low;j<=high-1;j++){
        if(a[j]<pivot){
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[high];
    a[high]=t;
    return (i + 1);
}

void quicksort(long int a[],long int low,long int high){
    if(low<high){
        long int p=divide(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

void heapify(long int a[],long int n,long int i)
{
    long int largest=i,t;
    long int l=2*i+1;
    long int r=2*i+2;
    if(l<n&&a[l]>a[largest])
        largest=l;
    if(r<n&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        heapify(a,n,largest);
    }
}

void heapsort(long int a[],long int n)
{
    long int t;
    for (long int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for (long int i=n-1;i>0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify(a,i,0);
    }
}
int main(){
    clock_t start,end;
    double ans[6][5];
    long int a[100000];
    for(long int i=0;i<100000;i++){
        a[i]=rand();
    }

    char algo[][10]={"Bubble","Selection","Insertion","Merge","Quick","Heap"};

    for(int i=0;i<5;i++){
        long int c[100000];
        for(long int i=0;i<100000;i++){
            c[i]=a[i];
        }
        ans[0][i]=bubble(c,pow(10,i+1));
        for(long int i=0;i<100000;i++){
            c[i]=a[i];
        }
        ans[1][i]=selection(c,pow(10,i+1));
        for(long int i=0;i<100000;i++){
            c[i]=a[i];
        }
        ans[2][i]=insertion(c,pow(10,i+1));
        for(long int i=0;i<100000;i++){
            c[i]=a[i];
        }
        start=clock();
        mergesort(c,0,pow(10,i+1));
        end=clock()-start;
        ans[3][i]=(double)end/CLOCKS_PER_SEC;
        for(long int i=0;i<100000;i++){
            c[i]=a[i];
        }
        start=clock();
        quicksort(c,0,pow(10,i+1)-1);
        end=clock()-start;
        ans[4][i]=(double)end/CLOCKS_PER_SEC;
        for(long int i=0;i<100000;i++){
            c[i]=a[i];
        }
        start=clock();
        heapsort(c,pow(10,i+1));
        end=clock()-start;
        ans[5][i]=(double)end/CLOCKS_PER_SEC;
    }
    printf("\t\t|\t     Time Complexity (seconds)       |\n________________|____________________________________________|\n");
    printf("Array Size(n)\t|   10   |   100  |  1000  |  10000 | 100000 |\n________________|________|________|________|________|________|\n");
    for(int i=0;i<6;i++){
        printf("%s Sort\t| ",algo[i]);
        for(int j=0;j<5;j++){
            printf("%6.3lf | ",ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
