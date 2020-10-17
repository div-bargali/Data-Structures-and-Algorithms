#include<stdlib.h>
#include<stdio.h>

int *input_array(int);

int recursive_linear_search(int, int*, int, int);

int main(int argc, char** argv){
    int size_array;
    scanf("%d", &size_array);

    int *array = input_array(size_array);

    int key;
    scanf("%d", &key);

    int found = 
    free(array);    //Making sure to free the memory allocated to the array
    return 0;
}

//Allocates and inputs values to an array of size_array values. Returns the array.
int *input_array(int size_array){
    int *array = (int*)malloc(size_array * sizeof(int));    //Creating an array in heap memory
    for(int i = 0; i < size_array; i++){
        scanf("%d", &array[i]);
    }
    return array;
}

//Looks for a key in the array of size_array items using linear search logic, it starts at the beggining of the array and goes all the way until it finds the key or reaches the end. 
//Returns the position of the item in the array if found.If not found returns -1.
int linear_search(int key, int *array, int size_array){
    int found = -1;
    for(int i = 0; i < size_array; i++)
        if(key == array[i])
            found = i;
    return found;
}