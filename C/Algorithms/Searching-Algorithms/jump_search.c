/*
    Code by Pedro Perez
    GitHub: https://github.com/pedrousp

    This code works in the following steps:
    1. Reads an integer from stdin and stores it in the size_array variable
    2. Allocates size_array * 4 bytes in heap memory for the array
    3. Reads size_array integers from stdin and stores it in each position of the array
    4. Reads an integer from stdin and stores it in the key array variable
    //You'll need to be sure the array is ordered to perform jump search
    5. Performs jump search, setting the range to look for the key
    6. Performs linear search in the specific range. The memory allocated for the array is freed after linear search is executed
    7. Returns found value, which can be either the position of key in the array or -1 if no found.
    
*/




#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int *input_array(int);
int linear_search(int, int*, int, int);
int jump_search(int, int*, int);
int input_integer();

int main(int argc, char** argv){
    int size_array = input_integer();
    int *array = input_array(size_array);
    int key = input_integer();
    int found = jump_search(key, array, size_array);
    return 0;
}

//Returns an integer from stdin
int input_integer(){
    int integer;
    scanf("%d", &integer);
    return integer;
}

//Creates an array of size elements in the heap memory. Return the pointer to the array
int *input_array(int size){
    int *array = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    return array;
}

//Looks for the key in the array of size elements starting at start_position. Returns the position of key in the array or -1 if key is not in the array
int linear_search(int key, int* array, int size, int start_position){
    int found = -1;
    for(int i = 0; i < size; i++){
        if(key == array[i])
            return i;
    }
    free(array);    //Making sure to free the memory allocated to the array
    return found;
}

//Looks for the key in a specific block in the array. If the key is in the block, the code performs a linear search in that block to find the key.
//The array MUST be ordered
int jump_search(int key, int* array, int size){
    int block = (int)sqrt(size);
    int start = 0;
    int end = block;
    while(end < size && array[end] <= key){
        start = end;
        end += block;
        if(end > size)
            end = size;
    }
    return linear_search(key, array, end, start);
}
