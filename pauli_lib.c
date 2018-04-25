#include <math.h>
#include "pauli_lib.h"
#include <stdio.h>

void exponentiate_general_case(pauli_term* p, double param) {
  pauli* ops = p->ops;
  // Change to Z basis
  for (int i = 0; i < n; i ++) {
    if (ops[i] == sX) {
      printf("H q[%d]\n", i);
    } else if (ops[i] == sY) {
      printf("RX[%lf] q[%d]\n", pi/2.0, i);
    } else {
      continue;
    }
  }

  // CNOT sequnece
  int** arr = (int**)malloc(n * sizeof(int*));
  int prev_index = 0;
  int highest_index = 0;
  arr[0] = (int*)malloc(2 * sizeof(int));
  arr[0][0] = 0;
  arr[0][1] = 0;
  for (int i = 1; i < n; i ++) {
    arr[i] = (int*)malloc(2 * sizeof(int));
    if (ops[i] != sI) {
      printf("CNOT q[%d],q[%d]\n", prev_index, i);
      arr[i][0] = prev_index;
      arr[i][1] = i;
      highest_index = i;
    } else {
      arr[i][0] = 0;
      arr[i][1] = 0;
    }
    prev_index = i;
  }
  printf("PH[%lf] q[%d]\n", p->coeff.re * param, highest_index);
  
  // Reverse CNOT sequence, to do
  for (int i = n - 1; i >= 0; i --) {
    int prev_index = arr[i][0];
    int index = arr[i][1];
    if (prev_index != 0 || index != 0) {
      printf("CNOT q[%d], q[%d]\n", prev_index, i);
    }
  }

  // Change back to original basis
  for (int i = 0; i < n; i ++) {
    if (ops[i] == sX) {
      printf("H q[%d]\n", i);
    } else if (ops[i] == sY) {
      printf("RX[%lf] q[%d]\n", -pi/2.0, i);
    }
  }
}

void exponentiate(pauli_term* p, double param) {
  if (is_identity(p)) {
    printf("RX[%lf] q[0]\n", pi/2);
    printf("PH[%lf] q[0]\n", -param * p->coeff.re);
   printf("RX[%lf] q[0]\n", pi/2);
    printf("PH[%lf] q[0]\n", -param * p->coeff.re);
  } else {
    exponentiate_general_case(p, param);
  }
}

void exponentiate_pauli_sum(pauli_sum* p, double param) {
  int len = p->len;
  for (int i = 0; i < len; i ++) {
    exponentiate(p->sum[i], param);
  }
}