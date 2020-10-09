//Program to convert postfix to prefix conversion
//using stacks
//example
// Input
// AB+CD+*
//Output
// *+AB+CD

#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <ctype.h>

#include <string.h>

#define max 100

char st[max];

int top = -1;

void push(char st[],char c)

{

if(top==max - 1)

printf("overflow\n");

else

{

top++;

st[top] = c;

}

}

char pop(char st[])

{ 

char val;

if(top==-1)

printf(“already empty\n”);

else 

{

val = st[top];

top--;

}

return val;

}

void reverse(char input[],char output[])

{

int len = strlen(input);

int i=0,j=len-1;

while(j>=0)

{

if(input[j]==’(‘)

output[i] = ‘)’;

else if(input[j]==’)’)

output[i]= ‘(‘;

else

output[i]=input[j];

i++; j--;

}

output[i]=’\0’;

}

int priority(char op)

{

if(op== ‘/’ || op == ‘*’ || op == ‘%’)

return 1;

else 

return 0;

}

void postfix_to_prefix(char input[])

{

char out[100];

int n,i,j=0;

char a,b;

n = strlen(input);

for(i=0;i<max;i++)

st[i] = ‘\0’;

for(i=n- 1;i>=0;i--)

{

if(input[i]== ‘+’ || input[i]== ‘-‘ || input[i]== ‘*’ || input[i]== ‘/’ || input[i]== ‘%’)

push(st,input[i]);

else

{

out[j++] = input[i];

while(top != -1 && st[top]== ‘$’)

{

a = pop(st) ; out[j++] = pop(st);

}

push(st,’$’);

}

}

out[j] = ‘\0’;

char temp[max];

reverse(out,temp);

puts(temp);

}

int main()

{

char input[100];

printf(“enter input string:”);

gets(input);

postfix_to_prefix(input);

}

