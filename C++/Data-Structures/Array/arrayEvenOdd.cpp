#include<iostream>
int main(){
    int arr[]={2,4,5,5,8,2,3,4,7}; //you can take array elements as a user input also.
    int i;
    int length= sizeof(arr)/sizeof(arr[0]); //sizeof gives the size of the array in bytes (integer is of 4 bytes) divided by size of single element of array
    std::cout<<"even index elements: ";
    for(i=0;i<length;i++){
        
        if (i%2==0){  //modulo(%) gives the remainder
            std::cout<<arr[i]<<" ";
        }
    }
    std::cout<<"\nodd index elements: ";
    for(i=0;i<length;i++){
        
        if(i%2!=0){
            std::cout<<arr[i]<<" ";
        }
    }
}
