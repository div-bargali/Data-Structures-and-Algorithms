#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>



struct Stack { 
    int top; 
    int capacity; 
    int* array; 
}; 
  
  
typedef struct Node {
    int data;
    struct Node* next;
}node;



struct Stack* initializingStack(int capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    
} 
  

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  

int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 


void insert(int v,int u,node* Graph[])
{
    node *p,*q;
    
	
	q=(node*)malloc(sizeof(node));
    q->data=u;
    q->next=NULL;
 
    
    if(Graph[v]==NULL)
        Graph[v]=q;
    else
    {
        
        p=Graph[v];
       
		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}


void addingEdge(node* arr[] , int v , int u){
    
    insert(v, u, arr);
    insert(u, v, arr);
}


void iterativeDFS(node* head[], int root , bool visited[] ){
    struct Stack* stack = initializingStack(100); 
  
    
    push(stack,root); 
  
    while (!isEmpty(stack)) 
    { 
        int s;
        s = peek(stack) ; 
        pop(stack); 
  
        
        if (!visited[s]) 
        { 
            printf("%d ",s) ;
            visited[s] = true; 
        } 
  
         
       node* temp = head[s];

       while (temp){
            if (!visited[temp->data]) 
                push(stack,temp->data);

            temp = temp ->next ;
       } 
    } 
} 


void recursiveDFS(node* arr[] , int key , bool visited[]){
    visited[key] = true;

    printf("%d ", key) ;

    node* temp = arr[key] ;

    while (temp){
        if (!visited[temp->data])
        recursiveDFS(arr, temp->data , visited);

        temp = temp ->next ;
    }
}



int main(){

    int n ;
    printf("Enter the number of nodes of the graph\n") ;
    scanf("%d", &n);

    node* head[n];
    bool visited[n];
    for (int i = 0 ; i<n ; i++){
    head[i] = NULL;
    visited[i] = false;
    }
    int numberOfEdges;

    printf("Enter the number of edges:\n");
    scanf("%d", &numberOfEdges);

    int u,v;

    printf("Enter the (v,u) pairs:\n");
    for (int i = 0 ;i<numberOfEdges;i++){
        scanf("%d%d",&v,&u);
        addingEdge(head,v,u);
    }

    int choice;

    printf("Enter your preference for DFS \n One for Recursive \n Any other number For Iterative\n");
    scanf("%d", &choice);

    if (choice == 1 ){
        int start ;
        printf("Enter the starting Root\n");
        scanf("%d",&start) ;
        recursiveDFS(head, start , visited);
    }

    else{
        int start ;
        printf("Enter the starting Root\n");
        scanf("%d",&start) ;
        iterativeDFS(head, start , visited);
    }

    return 0;
}
