#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct node {
  int vertex;
  int valor;
  int somatorio;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

// Creating a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void adicionarAresta(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

int main()
{
    
    int vertices, arestas, i, src, dest, aux;
    aux = 0;
    scanf("%d %d", &vertices, &arestas);
    char cores[vertices + (vertices - 1)];
    struct Graph* graph = createGraph(vertices);

    for(i=0; i < arestas; i++){
      scanf("%d %d", &src, &dest);
      adicionarAresta(graph, src, dest);
    }

    scanf("%s", cores);

    for (i=0; i < vertices + (vertices-1); i++){
      if(i % 2 == 0){
        graph->adjLists[0]->valor = 943;
        aux = aux + 1;
      }
    }
    
    printf("%d", graph->adjLists[2]->vertex);
    return 0;
}