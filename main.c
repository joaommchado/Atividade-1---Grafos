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

void printGraph(struct Graph* graph){
  int i, j;
  struct node* temp = graph->adjLists[0];

  for (i = 0; i < graph->numVertices; i++){
    if(graph->adjLists[i] == NULL){
      printf("[cabeça: %d] ->\n", i);
    }
    else {
      temp = graph->adjLists[i];
      printf("[cabeça: %d] ->", i);
      while(temp) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
      }
      printf("\n");
    }
  }
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

void Calcularsomatorio(struct Graph* graph, int *cores, int *somatorio){
  int i, j;
  struct node* temp = graph->adjLists[0];

  for (i = 0; i < graph->numVertices; i++){
    if(graph->adjLists[i] == NULL){
      somatorio[i] = cores[i];
    }

    else {
      temp = graph->adjLists[i];
      while(temp) {
        somatorio[i] += cores[temp->vertex];
        temp = temp->next;
      }
    }
  }
} 

//void calcularConflito()

// Driver program to test above functions
int main(){
    
    int vertices, arestas, i, src, dest, aux = 0, j = 0;
    scanf("%d %d", &vertices, &arestas);
    int cores[vertices], somatorio[vertices], 
    mapaArestas[2 * arestas];
    struct Graph* graph = createGraph(vertices);

    for(i=0; i < arestas; i++){
      scanf("%d %d", &src, &dest);
      adicionarAresta(graph, src, dest);
      mapaArestas[j] = src;
      j++;
      mapaArestas[j] = dest;
      j++;
    }
  
    for(i=0; i < vertices; i++)
      scanf("%d", &cores[i] );

  Calcularsomatorio(graph, cores, somatorio);
    return 0;
}