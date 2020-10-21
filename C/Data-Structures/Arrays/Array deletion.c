#include <stdio.h>

void display(int arr[], int n)
{
    //traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int inddeletion(int arr[], int size, int index)
{
    //code of deletion
    printf("element of the array after deletion\n");
    for (int i = index; i <=size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, index = 3;
    printf("element of the array is:\n");
    display(arr, size);
    inddeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}
