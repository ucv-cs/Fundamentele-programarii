/**
 * Matrice triunghiulara superioara = elementele de sub diagonala sunt zero
 **/

#pragma warning(disable: 4996 6031)
#include <stdio.h>
#define MAX 10

void main() {
	int matrix[MAX][MAX],
		matrix_rows = 0,
		i = 0, j = 0;

	//obtine dimensiunea matricei patratice de la utilizator
	printf("Scrieti ordinul matricei patratice A: ");
	scanf_s("%d", &matrix_rows);

	//completeaza matricea cu zerouri
	for (i = 0; i < matrix_rows; i++) {
		for (j = 0; j < matrix_rows; j++)
			matrix[i][j] = 0;
	}
	printf("\n");

	//obtine de la utilizator numai elementele de deasupra diagonalei
	for (i = 0; i < matrix_rows; i++) {
		for (j = i; j < matrix_rows; j++) {
			printf("A[%d][%d] = ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}

	//afiseaza matricea rezultata
	printf("\nMatricea triunghiulara superioara este: \n");
	for (i = 0; i < matrix_rows; i++) {
		for (j = 0; j < matrix_rows; j++) {
			printf("%4d\t", matrix[i][j]);
		}
		printf("\n");
	}

	_getch();
}