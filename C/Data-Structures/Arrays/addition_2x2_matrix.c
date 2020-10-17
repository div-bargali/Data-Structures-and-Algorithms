          //Title-Addition of 2x2 Matrix in C Language
//What it does-The program inputs the elements of two 2x2 matrix from the user. On the obtained matrices, the operation of matrix addition is performed. Finally the optput of it is displayed.
//Code:


#include <stdio.h>
int main() {
    int a[2][2], b[2][2], sum[2][2], i, j; //a[2][2] is 1st matrix,
	                                   //b[2][2] is 2nd matrix,
	                                   //sum[2][2] is the resultant 
    printf("\t\t\tADDITION OF 2x2 MATRIX USING POINTERS\n");
    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i <=1; ++i)              //input the elements of 1st matrix
        for (j = 0; j <=1; ++j) 
		{
            scanf("%d", &*(*(a+i)+j));   //value of a[i][j] element
        }

    printf("\nEnter elements of 2nd matrix:\n");
    for (i = 0; i <=1; ++i)             //input the elements of 2nd matrix
        for (j = 0; j <=1; ++j) 
		{
            scanf("%d", &*(*(b+i)+j));  //value of b[i][j] element
        }
    for (i = 0; i <=1; ++i)             //addition operation execution
        for (j = 0; j <=1; ++j) {
            *(*(sum+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);
        }
    printf("\nSum of two matrices: \n");
    for (i = 0; i <=1; ++i)             //display resultant matrix
        for (j = 0; j <=1; ++j) {
            printf("%d   ", *(*(sum+i)+j));
            if (j ==1) {
                printf("\n\n");
            }
        }

    return 0;
}
