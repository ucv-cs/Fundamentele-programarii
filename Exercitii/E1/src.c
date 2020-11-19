/**
 * Citirea unei matrice cu do while dupa pozitie si afisarea unui
 * element de pe o pozitie data.
 **/

#pragma warning(disable: 4996 6031)
#include <stdio.h>
#define MAX 10

void main() {
	int matrix[MAX][MAX],
		matrix_rows = 0,
		matrix_columns = 0,
		i = 0, j = 0, size = 0;

	//obtine dimensiunile matricei de la utilizator
	printf("Scrieti dimensiunile matricei A (in forma: m n): ");
	scanf("%d %d", &matrix_rows, &matrix_columns);

	//completeaza elementele matricei
	size = matrix_rows * matrix_columns;
	int position = 0;
	printf("Scrieti elementele matricei:\n");
	do {
		i = position / matrix_columns;
		j = position % matrix_columns;
		printf("A[%d][%d] = ", i, j);
		scanf("%d", &matrix[i][j]);
		position++;
	} while (position < size);

	//afiseaza matricea pentru verificare
	printf("\nMatricea introdusa este: A =\n");
	for (i = 0; i < matrix_rows; i++) {
		for (j = 0; j < matrix_columns; j++) {
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}

	//afiseaza un element din matrice, cunoscandu-i pozitia
	while (1) {
		printf("Scrieti pozitia unui element din matrice: ");
		scanf("%d", &position);

		if (position < 1 || position > size) {
			printf("Pozitia %d nu exista in matricea A.\n", position);
		}
		else {
			--position; //numaratoarea incepe de la 1; v. si size
			break;
		}
	}

	i = position / matrix_columns;
	j = position % matrix_columns;
	printf("Al %d-lea element este A[%d][%d] = %d\n", position + 1, i, j, matrix[i][j]);

	_getch();
}
