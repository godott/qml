#include <stdio.h>
#include "graph.h"


Graph* new_graph(int num_of_vertices) {
  Graph* G = (Graph*)malloc(sizeof(Graph));
  G->num_of_vertices = num_of_vertices;
  G->num_of_edges = 0;
  int** M = (int**)malloc(num_of_vertices *  sizeof(int*));
  for (int i = 0; i < num_of_vertices; i ++) {
    M[i] = (int*)malloc(num_of_vertices * sizeof(int));
    for (int j = 0; j < num_of_vertices; j ++) {
      M[i][j] = 0;
    }
  }
  G->adjacency_matrix = M;
  return G;
}

void addEdge(Graph* G, int u, int v) {
  G->adjacency_matrix[u][v] = 1;
  //G->adjacency_matrix[v][u] = 1;
  G->num_of_edges ++;
}

void addEdges(Graph* G, int** edges, int len) {
  for (int i = 0; i < len; i ++) {
    int u = edges[i][0];
    int v = edges[i][1];
    addEdge(G, u, v);
  }
}

void disp_graph(Graph* G) {
  printf("There are %d vertices and %d edges\n", G->num_of_vertices, G->num_of_edges);
  printf("---------------------\n");
  printf("Adjacency Matrix: \n");
  for (int i = 0; i < G->num_of_vertices; i ++) {
    for (int j = 0; j < G->num_of_vertices; j ++) {
      printf("%d  ", G->adjacency_matrix[i][j]);
    } 
    printf("\n");
  }
}