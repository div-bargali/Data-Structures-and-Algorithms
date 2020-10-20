/*
    Code made by Pedro Perez
    GitHub: https://github.com/pedrousp

    This code works in the following steps:
    1. Reads an integer from stdin and stores it in size_array variable
    2. Allocates size_array * 4 bytes in heap memory for the array
    3. Reads size_array integers from stdin an stores it in each address of the array
    4. Calls mergesort_3way, which is a recursive function. It'll split the array in three pieces and order it
    5. Frees the memory allocated for the array

*/



#include<stdlib.h>
#include<stdio.h>

int input_integer();
int *create_array(int);
void mergesort_3way(int*, int, int);
void merge(int*, int, int, int, int);

int main(int argc, char **argv){
    int size_array = input_integer();
    int *array = create_array(size_array);
    mergesort_3way(array, 0, size_array-1);
    free(array);
    return 0;
}

int input_integer(){
    int integer;
    scanf("%d", &integer);
    return integer;
}

int *create_array(int size){
    int *array = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        array[i] = input_integer();
    }
    return array;
}

void mergesort_3way(int *array, int begin, int end){
    //Base -> returns if it cannot split in lowest pieces
    if(end <= begin)
        return;
    
    int difference = end - begin;

    //Defines the split range
    int split1 = begin + (difference / 3);
    int split2 = begin + (2 * (difference / 3)) + 1;

    //Calls a recursive function setting a new range to split the array
    mergesort_3way(array, begin, split1);
    mergesort_3way(array, split1+1, split2);
    mergesort_3way(array, split2+1, end);

    //After the recursive functions return, then it'll merge the values to order them
    merge(array, begin, split1, split2, end);
}

void merge(int *array, int begin, int split1, int split2, int end){
    //Creates an auxiliar array to help storing the values
    int *auxiliar_array = malloc((end - begin + 1) * sizeof(int));
    int i = begin, j = split1 + 1, k = split2 + 1, l = 0;

    //From the three pieces, stores the lowest numbers
    while(i <= split1 && j <= split2 && k <= end){
        if(array[i] <= array[j] && array[i] <= array[k])
            auxiliar_array[l++] = array[i++];
        else if(array[j] <= array[i] && array[j] <= array[k])
            auxiliar_array[l++] = array[j++];
        else
            auxiliar_array[l++] = array[k++];
    }

    //From the two remaining pieces, stores the lowest numbers
    while(i <= split1 && j <= split2){
        if(array[i] <= array[j])
            auxiliar_array[l++] = array[i++];
        else
            auxiliar_array[l++] = array[j++];
    }

    while(j <= split2 && k <= end){
        if(array[j] <= array[k])
            auxiliar_array[l++] = array[j++];
        else
            auxiliar_array[l++] = array[k++];
    }

    while(i <= split1 && k <= end){
        if(array[i] <= array[k])
            auxiliar_array[l++] = array[i++];
        else
            auxiliar_array[l++] = array[k++];
    }

    //Finish storing the remaining values
    while(i <= split1)
        auxiliar_array[l++] = array[i++];

    while(j <= split2)
        auxiliar_array[l++] = array[j++];

    while(k <= end)
        auxiliar_array[l++] = array[k++];

    //Copies the values back to the original array
    for(int i = begin, k = 0; i <= end; i++, k++)
        array[i] = auxiliar_array[k];

    //Frees the memory allocated to the auxiliar array
    free(auxiliar_array);
}
