#include <stdio.h>
#include "complex.h"

complex new_complex(double re, double im) {
  complex a;
  a.re = re;
  a.im = im;
  return a;
}

complex add(complex a, complex b) {
  complex c;
  c.re = a.re + b.re;
  c.im = a.im + b.im;
  return c;
}

complex sub(complex a, complex b) {
  complex c;
  c.re = a.re - b.re;
  c.im = a.im - b.im;
  return c;
}


complex mul(complex a, complex b) {
  complex c;
  c.re = a.re * b.re - a.im * b.im;
  c.im = a.re * b.im + a.im * b.re;
  return c;
}

complex quo(complex a, complex b) {
  complex c;
  c.re = (a.re * b.re + a.im * b.im) / (b.im * b.im + b.re * b.re); 
  c.im = (a.im * b.re - a.re * b.im) / (b.im * b.im + b.re * b.re);
  return c;
}

void disp_complex(complex a) {
  if (a.im >= 0) {
    printf("%.2f+%.2fi\n", a.re, a.im);
  } else {
    printf("%.2f-%.2fi\n", a.re, -a.im);
  }
}
