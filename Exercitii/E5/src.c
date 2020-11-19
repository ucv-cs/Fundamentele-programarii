/**
 * Matrice tridimensionala / cub / matrici in sectiuni
 **/

#pragma warning(disable: 4996 6031)
#include <stdio.h>
#define MAX 10

void main() {
	int matrix[MAX][MAX][MAX];
	int x_matrix, y_matrix, z_matrix;
	int i = 0, j = 0, k = 0;

	//obtine dimensiunile matricei de la utilizator
	printf("Introduceti dimensiunile matricei A (x y z): ");
	scanf("%d %d %d", &x_matrix, &y_matrix, &z_matrix);

	//completeaza matricea cu elemente introduse de utilizator
	for (k = 0; k < z_matrix; k++) {
		for (i = 0; i < x_matrix; i++) {
			for (j = 0; j < y_matrix; j++) {
				printf("A[%d][%d][%d] = ", i, j, k);
				scanf("%d", &matrix[i][j][k]);
			}
		}
	}

	//afiseaza matricea
	printf("\nMatricea A este: \n\n");
	for (k = 0; k < z_matrix; k++) {
		for (i = 0; i < x_matrix; i++) {
			for (int padding = 0; padding < k; padding++) {
				printf("\t");
			}

			for (j = 0; j < y_matrix; j++) {
				printf("%4d ", matrix[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	_getch();
}