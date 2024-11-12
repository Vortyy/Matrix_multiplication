#include<stdlib.h>
#include<stdio.h>
#include"matrix.h"

void print_matrix(Matrix *M, int flags){
  printf("\n");
  for(int i = 0; i < M->row; i++){
    for(int j = 0; j < M->column; j++){
      //printf("%d", (*(*M).data + i * M->row + j));
      //printf("%d ", M->data[i * M->row + j]);
      //printf("%d ", i * M->column + j);
      printf("%4d ", (*(M->data + i * M->column + j)));
      if((MATRIX_PRINT_MEM & flags) == MATRIX_PRINT_MEM){
        printf("- %p ", (M->data) + i * M->column + j);
      }
    }
    printf("\n");
  }
}
 
Matrix matrix_add(Matrix A, Matrix B){
  if(A.row == B.row && A.column == B.column){
    Matrix res = (Matrix){.row = A.row, .column = A.column};
    int* data = malloc(sizeof(int) * (res.column * res.row));

    for(int i = 0; i < res.row; i++){
      for(int j = 0; j < res.column; j++){
        *(data + i * res.column + j) = *(A.data + i * A.column + j) + *(B.data + i * B.column + j);
      }
    }

    res.data = data;
    return res;
  } else {
    fprintf(stderr, "A(%d, %d) and B(%d, %d) don't have the same dimension\n", A.row, A.column, B.row, B.column);
    exit(EXIT_FAILURE);
  }
} 

Matrix matrix_sub(Matrix A, Matrix B){
  if(A.row == B.row && A.column == B.column){
    Matrix res = (Matrix){.row = A.row, .column = A.column};
    int* data = malloc(sizeof(int) * (res.column * res.row));

    for (int i = 0; i < res.row; i++) {
      for (int j = 0; j < res.column; j++) {
        *(data + i * res.column + j) = *(A.data + i * A.column + j) - *(B.data + i * B.column + j); 
      }
    }

    res.data = data;
    return res;
  } else{
    fprintf(stderr, "A(%d, %d) and B(%d, %d) don't have the same dimension\n", A.row, A.column, B.row, B.column);
    exit(EXIT_FAILURE);
  }
}

Matrix matrix_mult(Matrix A, Matrix B){
  Matrix res;

  return res;
}

int main(int argc, char **args){
  int flags = 0;// MATRIX_PRINT_MEM;

  int data[] = {1, 1, 0, 0};
  int dataM2[] = {2, 4, 2, 7};

  Matrix m = (Matrix){
    .row = 2,
    .column = 2,
    .data = data
  };

  Matrix m2 = (Matrix){
    .row = 2,
    .column = 2,
    .data = dataM2
  };

  printf("size of struct _matrix : %lu Bytes\n", sizeof(Matrix));

  print_matrix(&m, flags);
  print_matrix(&m2, flags);

  Matrix result = matrix_add(m, m2);

  print_matrix(&result, flags);

  result = matrix_sub(m, m2);
  
  print_matrix(&result, flags);
}
