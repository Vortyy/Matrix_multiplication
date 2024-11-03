#include<stdlib.h>
#include<stdio.h>
#include"matrix.h"

void print_matrix(Matrix *M, int flags){
  for(uint32_t i = 0; i < M->row; i++){
    for(uint32_t j = 0; j < M->column; j++){
      //printf("%d ", M->data[i * M->row + j]);
      //printf("%d", (*(*M).data + i * M->row + j));
      //printf("%d ", i * M->column + j);
      printf("%d ", (*(M->data + i * M->column + j)));
      if((MATRIX_PRINT_MEM & flags) == MATRIX_PRINT_MEM){
        printf("- %p ", (M->data) + i * M->column + j);
      }
    }
    printf("\n");
  }
}
 
void matrix_addition(Matrix *dest, Matrix A, Matrix B){
  if(A.row == B.row && A.column == B.column){
    dest->row = A.row;
    dest->column = A.column;

    int* data = malloc(sizeof(int) * (dest->column * dest->row));

    for(int i = 0; i < dest->row; i++){
      for(int j = 0; j < dest->column; j++){
        *(data + i * dest->column + j) = *(A.data + i * A.column + j) + *(B.data + i * B.column + j);
      }
    }

    dest->data = data;
  } else {
    fprintf(stderr, "A(%d, %d) and B(%d, %d) don't have the same dimension\n", A.row, A.column, B.row, B.column);
  }
} 

int main(int argc, char **args){
  int flags = MATRIX_PRINT_MEM;

  int data[] = {0, 1, 0, 0};
  int dataM2[] = {0, 0, 2, 0, 0, 0};

  Matrix m = (Matrix){
    .row = 2,
    .column = 2,
    .data = data
  };

  Matrix m2 = (Matrix){
    .row = 3,
    .column = 2,
    .data = dataM2
  };

  printf("size of struct _matrix : %lu Bytes\n", sizeof(Matrix));

  print_matrix(&m, flags);
  print_matrix(&m2, flags);

  Matrix result;

  matrix_addition(&result, m, m2);

  printf("Testing github connection...");
}
