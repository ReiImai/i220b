#include "matmul.h"

void
matrix_multiply(int n, double a[][n], double b[][n], double c[][n])
{
  double temp[n][n];
  int col = 0;
  int row = 0;
  for(int r = 0; r < n; r++){
 	for(int c = 0; c < n; c++){
		temp[r][c] = b[row][col];
		row++;
	}
	col++;
	row = 0;
  }


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
	c[i][j] += a[i][k]*temp[j][k];
      }
    }
  }
}

