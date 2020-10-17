// Implementation of Graph DS (adjacency list)

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
	printf("\nRandom Graph generated!!\n\n");
	return temp;
}

//prints the generated graph

void printGraph(Graph* graph){
	printf("Graph  : \nstart vertex : (destination , weight)\n\n");
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

void main(){
	int n = 15;  // Default value for number of nodes createGraph() takes in number of nodes as parameter
	// printf("\nEnter the number of nodes for graph generation : ");
	// scanf("%d", &n);      // (Optional)
	Graph* graph = createGraph(n);
	printGraph(graph);
}




