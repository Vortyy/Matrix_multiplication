#ifndef MATRIX_H
#define MATRIX_H

#include<stdint.h>

#define MATRIX_PRINT_MEM 0x1

typedef struct _matrix{
  uint32_t row;
  uint32_t column;

  int *data;
} Matrix;

void print_matrix(Matrix *M, int flags);

void matrix_addition(Matrix *dest, Matrix A, Matrix B);
void matrix_substraction(Matrix *dest, Matrix A, Matrix B);
void matrix_multiplication(Matrix *dest, Matrix A, Matrix B);

#endif
