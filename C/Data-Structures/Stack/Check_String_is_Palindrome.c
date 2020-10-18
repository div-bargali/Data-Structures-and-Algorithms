/*C Program to Identify whether the String is Palindrome or not using Stack
This program takes a string and checks whether the string is palindrome or not using stack*/

/*We will solve the problem using the following steps :
1. Take a string as input.
2. Store the string in the stack array.
3. Check whether the string is palindrome or not. 
4. If it is true, it will display "<given_string> is not a palindrome" else "<given_string> is not a palindrome"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
 
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
 
/*Main function to check for palindrome function*/
void main()
{
    int i, choice;
    /*Take a string as input and store it in the array s*/
    char s[MAX], b;
    while (1)
    {
        printf("1-enter string\n2-exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            scanf("%s", s);
/*Using for loop compare the top and last element of the array stack s[ ]. 
If they are equal, then delete the top element, increment the variable front by 1 and compare again.*/
            for (i = 0;s[i] != '\0';i++)
            {
                b = s[i];
                push(b);
            }
            for (i = 0;i < (strlen(s) / 2);i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break; 
                }
            }
            /*/If every characters of the array is equal, then the input string is a palindrome.*/
            if ((strlen(s) / 2)  =  =  front)
                printf("%s is palindrome\n",  s);
            front  =  0;
            top  =  -1;
            break;
        case 2:
            exit(0);
        default:
            printf("enter correct choice\n");
        }
    }
}
 
/* to push a character into stack */
void push(char a)
{
    top++;
    stack[top]  =  a;
}
 
/* to delete an element in stack */
void pop()
{
    top--;
}