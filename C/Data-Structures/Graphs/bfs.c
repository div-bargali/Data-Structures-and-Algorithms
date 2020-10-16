// Implementation of Breadth First Search for Graph DS (adjacency list)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int dest;
	int weight;
	struct node* next;
}node; // a struture to denote vertices in a edgelist

typedef struct adjList{
	int startIndex;
	int visited;
	node* edgeList;
}adjList; // a structure representing the start vertex and all of its neighbours(edges)

typedef struct graph{
	int n;
	adjList** vertices;
}Graph; // a structure representing whole of the graph DS(adjacency list)

// Queue Implementation (Required for breadth first search)

typedef struct queue{
	adjList* list;
	struct queue* next;
}queue;


queue* front = NULL;

queue* rear = NULL;

queue* createQueueNode(adjList* list){
	queue* temp = (queue *) malloc(sizeof(queue));
	temp->list = list;
	temp->next = NULL;
	return temp;
}

void enque(adjList* list){
	if(list == NULL || list->visited == 1){
		return;
	}
	list->visited = 1;
	queue* temp = createQueueNode(list);
	if(front == NULL){
		front = temp;
		rear = temp;
	}else{
		rear->next = temp;
		rear = temp;
	}
}

queue* deque(){
	if(front == NULL){
		return NULL;
	}else if(front == rear){
		queue* temp = front;
		front = NULL;
		rear = NULL;
		return temp;
	}else{
		queue* temp = front;
		front  = front->next;
		temp->next = NULL;
		return temp;
	}
}

node* newNode(int destination, int weight){
	node* temp = (node *) malloc(sizeof(node));
	temp->dest = destination;
	temp->weight = weight;
	temp->next = NULL;
	return temp;
} // creates a new node 

void addEdge(adjList* list, int destination, int weight){
	node* temp = newNode(rand() % destination, weight);
	temp->next = list->edgeList;
	list->edgeList = temp;
}

// creates a random weighted graph(can be customised to make a graph with specific requirements)
//createGraph() takes in number of nodes as parameter and returns a randomly generated weighted graph

Graph* createGraph(int n){
	Graph* temp = (Graph *) malloc(sizeof(Graph));
	temp->n = n;
	temp->vertices = (adjList **) malloc(n*sizeof(adjList*));
	for(int i=0; i<n; i++){
		adjList* tempList = (adjList *) malloc(sizeof(adjList));
		tempList->startIndex = i;
		tempList->visited = 0;
		tempList->edgeList = NULL;
		int listSize = rand() % n + 1;
		for(int j=0; j<listSize; j++){
			addEdge(tempList, n, rand()%50 + 1);
		}
		temp->vertices[i] = tempList;
	}
	printf("Random Graph generated!!, ");
	return temp;
}

//prints the generated graph
void printGraph(Graph* graph){
	printf("Graph  : \nstart vertex : (destination , weight)\n");
	for(int i=0; i<graph->n; i++){
		adjList* temp = graph->vertices[i];
		printf("%d ->", temp->startIndex);
		node* tempList = temp->edgeList;
		while(tempList!=NULL){
			printf(" (%d, %d) ", tempList->dest, tempList->weight);
			tempList = tempList->next;
		}
		printf("\n");
	}
}

// Helper Function for BFS
void enqueChildren(node* list, Graph* graph){
	if(list == NULL){
		return;
	}else{
		while(list!=NULL){
			int vertex = list->dest;
			if(graph->vertices[vertex]->visited != 1){
				enque(graph->vertices[vertex]);
			}
			list = list->next;
		}
	}
}

//Helper Function for BFS
void removeVisitedFlag(Graph* graph){
	for(int i=0; i<graph->n; i++){
		graph->vertices[i]->visited = 0;
	}
}

// Implementation of breadth first search
// Works well for edges without different weights

void BreadthFirstSearch(Graph* graph, int startVetex){
	printf("\nBFS of graph(adjacency list) : ");
	adjList** vertices = graph->vertices;
	enque(vertices[startVetex]);
	while(front!=NULL){
		queue* temp = deque();
		printf(" %d ", temp->list->startIndex);
		enqueChildren(temp->list->edgeList, graph);
	}
	removeVisitedFlag(graph);
	printf("\n\n");
}

void main(){
	int n = 15; // Default value for number of nodes
	// printf("Enter the number of nodes for graph generation : ");
	// scanf("%d", &n);   (Optional)
	Graph* graph = createGraph(n);
	printGraph(graph);
	int startVertex = 0; // Default value for start Index (vertex where breadth first search starts)
	// printf("Enter the startVertex for BFS of generated graph : ");
	// scanf("%d", &startVertex);
	BreadthFirstSearch(graph, startVertex);
}




