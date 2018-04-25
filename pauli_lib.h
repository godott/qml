#include "pauli.h"
#include "const.h"

void exponentiate(pauli_term* p, double param);
void exponentiate_pauli_sum(pauli_sum* p, double param);
void exponentiate_general_case(pauli_term* p, double param);