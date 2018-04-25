#include <math.h>
#include "pauli_lib.h"
#include <stdio.h>
#define MAX_LEN 4
void exponentiate_general_case(pauli_term* p, double param) {
  pauli* ops = p->ops;
  // Change to Z basis
  for (int i = 0; i < MAX_LEN; i ++) {
    if (ops[i] == sX) {
      printf("H %d\n", i);
    } else if (ops[i] == sY) {
      Rz(q[i], pi/2.0);//Rx
    } else {
      continue;
    }
  }

  // CNOT sequnece
  int** arr = (int**)malloc(MAX_LEN * sizeof(int*));
  int prev_index = 0;
  int highest_index = 0;
  arr[0] = (int*)malloc(2 * sizeof(int));
  arr[0][0] = 0;
  arr[0][1] = 0;
  for (int i = 1; i < MAX_LEN; i ++) {
    arr[i] = (int*)malloc(2 * sizeof(int));
    if (ops[i] != sI) {
      CNOT(q[prev_index], q[i]);
      arr[i][0] = prev_index;
      arr[i][1] = i;
      highest_index = i;
    } else {
      arr[i][0] = 0;
      arr[i][1] = 0;
    }
    prev_index = i;
  }

  Rz(q[highest_index], 2.0 * p->coeff.re * param);
  
  // Reverse CNOT sequence, to do
  for (int i = MAX_LEN - 1; i >= 0; i --) {
    int prev_index = arr[i][0];
    int index = arr[i][1];
    if (prev_index != 0 || index != 0) {
      CNOT(q[prev_index], q[i]);
    }
  }

  // Change back to original basis
  for (int i = 0; i < MAX_LEN; i ++) {
    if (ops[i] == sX) {
      H(q[i]);
    } else if (ops[i] == sY) {
      Rz(q[i], -pi / 2.0);// Rx
    }
  }
}

void exponentiate(qbit q[n], pauli_term* p, double param) {
  if (is_identity(p)) {
    X(q[0]);
    Rz(q[0], -param * p->coeff.re*2.0);
    X(q[0]);
    Rz(q[0], -param * p->coeff.re*2.0);
  } else {
    exponentiate_general_case(q, p, param);
  }
}

void exponentiate_pauli_sum(qbit q[n], pauli_sum* p, double param) {
  int len = p->len;
  for (int i = 0; i < len; i ++) {
    exponentiate(q, p->sum[i], param);
  }
}