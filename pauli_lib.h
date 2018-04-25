#include "pauli.h"
#define n 4
#define pi 3.141592653589793238462643383279502884197

void exponentiate(pauli_term* p, double param);
void exponentiate_pauli_sum(pauli_sum* p, double param);
void exponentiate_general_case(pauli_term* p, double param);