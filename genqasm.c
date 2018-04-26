#include "pauli_lib.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "const.h"

int main(int argc, char * argv[]) {
  printf("BEGIN\n");
  printf("qubits %d\n", n);

  float theta[1];


    printf("float value : %4.5f\n", atof(argv[1])); 
        theta[0] = atof(argv[1]);
  pauli_sum* H_cost = new_pauli_sum();
  /*
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
        pauli_term* t_i = new_pauli_term(i, new_complex(-1,0), sZ);
        pauli_term* t_j = new_pauli_term(j, new_complex(-1,0), sZ);
//      pauli_term* I = new_pauli_term(0, new_complex(1,0), sI);
        pauli_term* t = pauli_term_prod(t_i, t_j);
//      H_cost = pauli_term_add_to_sum(H_cost, I);
        H_cost = pauli_term_add_to_sum(H_cost, t);
    }
  }*/
  pauli_term* t_i = new_pauli_term(0, new_complex(-1,0), sZ);
  pauli_term* t_j = new_pauli_term(1, new_complex(-1,0), sZ);
  pauli_term* t = pauli_term_prod(t_i, t_j);
  H_cost = pauli_term_add_to_sum(H_cost, t);
//  pauli_sum_prod_const(&H_cost, -0.5);
/*
  pauli_sum* H_ref = new_pauli_sum();
  for (int i = 0; i < n; i ++) {
    pauli_term* t = new_pauli_term(i, new_complex(1,0), sX);
    H_ref = pauli_term_add_to_sum(H_ref, t);
  }
  pauli_sum_prod_const(&H_ref, -1.0);
*/
    exponentiate_pauli_sum(H_cost, theta[0]);
//  exponentiate_pauli_sum(H_ref, betas[i]);
  printf("END\n");
  return 0;
}
