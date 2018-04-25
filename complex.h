#include <stdlib.h>

typedef struct
{
  double re; // real part
  double im; // imaginary part
} complex;

complex new_complex(double re, double im);
complex add(complex a, complex b);
complex mul(complex a, complex b);
complex sub(complex a, complex b);
complex quo(complex a, complex b);
void disp_complex(complex a);

