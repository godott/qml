#include "pauli_lib.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "const.h"

int main() {
  printf("BEGIN\n");
  printf("qubits %d\n", n);
  Graph* G = new_graph(n);
  addEdge(G, 0, 1);
  addEdge(G, 1, 2);
  addEdge(G, 2, 3);

  for (int i = 0; i < n; i ++) {
    printf("H q[%d]\n", i);
  }
  
  pauli_sum* H_cost = new_pauli_sum();
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      if (G->adjacency_matrix[i][j]) { 
        pauli_term* t_i = new_pauli_term(i, new_complex(1,0), sZ);
        pauli_term* t_j = new_pauli_term(j, new_complex(1,0), sZ);
        pauli_term* t = pauli_term_prod(t_i, t_j);
        pauli_term_prod_const(&t, -1.0);
        pauli_term* I = new_pauli_term(0, new_complex(1,0), sI);
        H_cost = pauli_term_add_to_sum(H_cost, I);
        H_cost = pauli_term_add_to_sum(H_cost, t);
      }
    }
  }
  pauli_sum_prod_const(&H_cost, -0.5);

  pauli_sum* H_ref = new_pauli_sum();
  for (int i = 0; i < n; i ++) {
    pauli_term* t = new_pauli_term(i, new_complex(1,0), sX);
    H_ref = pauli_term_add_to_sum(H_ref, t);
  }
  pauli_sum_prod_const(&H_ref, -1.0);

  int num_param = 2;
  double gammas[] = {0.0, 0.5};
  double betas[] = {0.75, 1.0};
  for (int i = 0; i < num_param; i ++) {
    exponentiate_pauli_sum(H_cost, gammas[i]);
    exponentiate_pauli_sum(H_ref, betas[i]);
  }
  printf("END\n");
  return 0;
}