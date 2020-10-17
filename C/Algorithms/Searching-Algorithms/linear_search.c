/*Program made by Pedro Perez
  Github: https://github.com/pedrousp
  This program will read an integer from stdin and it'll be stored in size_array, which will be the size of the array
  Then it'll allocate size_array * 4 bytes in heap memory
  Next it'll read size_array integers from stdin
  Next it'll read an integer from stdin which will be looked for in the array
  Then it'll look for the key in the array, stating at the position 0 and going all the way to the end or until it finds the first occurence of key
  After that it'll free the memory allocated for the array and it'll return the found value
  The program will stop*/


#include<stdlib.h>
#include<stdio.h>

int *input_array(int);
int linear_search(int, int*, int);
int input_integer();

int main(int argc, char** argv){
    int size_array = input_integer();
    int *array = input_array(size_array);
    int key = input_integer();
    int found = linear_search(key, array, size_array);
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

//Looks for the key in the array of size elements. Returns the position of key in the array or -1 if key is not in the array
int linear_search(int key, int* array, int size){
    int found = -1;
    for(int i = 0; i < size && found == -1; i++){
        if(key == array[i]){
            found = i;
        }
    }
    free(array);    //Making sure to free the memory allocated to the array
    return found;
}
