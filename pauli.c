#include "pauli.h"
#include <stdio.h>

pauli_term* new_pauli_term(int index, complex coeff, pauli op) {
  pauli_term* t = (pauli_term*)malloc(sizeof(pauli_term));
  t->coeff = coeff;
  t->ops = (pauli*)malloc(n * sizeof(pauli));
  for (int i = 0; i < n; i ++) {
    if (i == index) {
      t->ops[i] = op;
    } else {
      t->ops[i] = sI;
    }
  }
  return t;
}

pauli_sum* new_pauli_sum() {
  pauli_sum* s = (pauli_sum*)malloc(sizeof(pauli_sum));
  s->len = 0;
  s->sum = (pauli_term**)malloc(10 * sizeof(pauli_term*));
  for (int i = 0; i < 10; i ++) {
    s->sum[i] = new_pauli_term(0, new_complex(1,0), sI);
  }
  return s;
}

pauli_term* pauli_term_prod(pauli_term* a, pauli_term* b) {
  complex coeff = mul(a->coeff, b->coeff);
  complex pos_i = new_complex(0,1);
  complex neg_i = new_complex(0,-1);

  pauli_term* p = new_pauli_term(0, new_complex(1,0), sI);
  for (int i = 0; i < n; i ++) {
    pauli A = a->ops[i];
    pauli B = b->ops[i];
    if (A == sI && B == sI) {
      continue;
    }
    //p->len ++;
    pauli prod;
    if (A == B) {
      prod = sI;
    } else if (A == sI || B == sI) {
      if (A == sI) {
        prod = B;
      } else {
        prod = A;
      }
    } else {
      if (A == sX && B == sY) {
        prod = sZ;
        coeff = mul(pos_i, coeff);
      } else if (A == sX && B == sZ) {
        prod = sY;
        coeff = mul(neg_i, coeff);
      } else if (A == sY && B == sX) {
        prod = sZ;
        coeff = mul(neg_i, coeff);
      } else if (A == sY && B == sZ) {
        prod = sX;
        coeff = mul(pos_i, coeff);
      } else { // (A == Z && B == X)
        prod = sY;
        coeff = mul(pos_i, coeff);
      }
    }
      p->ops[i] = prod;
  }
  p->coeff = coeff;
  return p;
}

int is_identity(pauli_term* p) {
    for (int i = 0; i < n; i ++) {
      if (p->ops[i] != sI) {
        return 0;
      }
    }
    return p->coeff.re != 0 || p->coeff.im != 0;
}

void pauli_term_prod_const(pauli_term** p_ref, double c) {
  pauli_term* p = *p_ref;
  p->coeff = mul(p->coeff, new_complex(c,0));
}

pauli_sum* pauli_term_add_to_sum(pauli_sum* s, pauli_term* t) {
  int len = s->len;
  int flag = 1;
  if (is_identity(t)) {
    for (int i = 0; i < len; i ++) {
      if (is_identity(s->sum[i])) {
        s->sum[i]->coeff = add(s->sum[i]->coeff, t->coeff);
        flag = 0;
        break;
      }
    }
  }
  if (flag) {
    s->sum[len] = t;
    s->len ++;
  }
  return s;
}

void pauli_sum_prod_const(pauli_sum** s_ref, double c) {
  pauli_sum* s = *s_ref;
  int len = s->len;
  for (int i = 0; i < len; i ++) {
    pauli_term_prod_const(&s->sum[i], c);
  }
}