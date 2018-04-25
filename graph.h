#include <stdlib.h>

typedef struct 
{
  int num_of_vertices;
  int num_of_edges;
  int** adjacency_matrix;
} Graph;

Graph* new_graph(int num_of_vertices);

void addEdge(Graph* G, int u, int v); //edge e = (u,v) is added 
void addEdges(Graph*, int** egdes, int len);
void disp_graph(Graph* G);

