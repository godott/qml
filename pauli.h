#include "complex.h"
#include "const.h"

typedef enum {sX, sY, sZ, sI} pauli;

typedef struct
{
  //int len;
  complex coeff;
  pauli* ops;
} pauli_term;


typedef struct
{
  int len;
  pauli_term** sum;
} pauli_sum;

pauli_term* new_pauli_term(int index, complex coeff, pauli op);
pauli_term* pauli_term_prod(pauli_term* a, pauli_term* b);
pauli_sum* new_pauli_sum();
int is_identity(pauli_term* p);
pauli_sum* pauli_term_add_to_sum(pauli_sum* s, pauli_term* t);
void pauli_term_prod_const(pauli_term** p_ref, double c);
void pauli_sum_prod_const(pauli_sum** s_ref, double c);
