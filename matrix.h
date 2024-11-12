#ifndef MATRIX_H
#define MATRIX_H

#define MATRIX_PRINT_MEM 0x1

typedef struct _matrix{
  unsigned int row;
  unsigned int column;

  int *data;
} Matrix;

void print_matrix(Matrix *M, int flags);

Matrix matrix_add(Matrix A, Matrix B);
Matrix matrix_sub(Matrix A, Matrix B);
Matrix matrix_mult(Matrix A, Matrix B);
#endif
