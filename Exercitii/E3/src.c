/**
 * Matrice triunghiulara inferioara = elementele de deasupra diagonala sunt zero
 **/

#pragma warning(disable: 4996 6031)
#include <stdio.h>
#define MAX 10

void main() {
	int matrix[MAX][MAX],
		matrix_rows = 0,
		i = 0, j = 0;

	//obtine dimensiunea matricei de la utilizator
	printf("Scrieti ordinul matricei patratice A: ");
	scanf("%d", &matrix_rows);

	//completeaza matricea cu zerouri
	for (i = 0; i < matrix_rows; i++) {
		for (j = 0; j < matrix_rows; j++) {
			matrix[i][j] = 0;
		}
	}

	//obtine elementele de sub diagonala de la utilizator
	printf("Scrieti elementele matricei triunghiulare inferioare:\n");
	for (i = 0; i < matrix_rows; i++) {
		for (j = 0; j <= i; j++) {
			printf("A[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}

	//afiseaza rezultatul
	printf("\nMatricea triunghiulara inferioara este:\n");
	for (i = 0; i < matrix_rows; i++) {
		for (j = 0; j < matrix_rows; j++) {
			printf("%4d\t", matrix[i][j]);
		}
		printf("\n");
	}

	_getch();
}