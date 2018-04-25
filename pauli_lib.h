#include "pauli.h"
#define n 4
#define pi 3.141592653589793238462643383279502884197

void exponentiate(qbit q[n], pauli_term* p, double param);
void exponentiate_pauli_sum(qbit q[n], pauli_sum* p, double param);
void exponentiate_general_case(qbit q[n], pauli_term* p, double param);