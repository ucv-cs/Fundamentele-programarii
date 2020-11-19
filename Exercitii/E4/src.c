/**
 * Inmultirea a doua matrice.
 **/

#pragma warning(disable: 4996 6031)
#include <stdio.h>
#define MAX 10

void main() {
	int a[MAX][MAX],
		b[MAX][MAX],
		product[MAX][MAX],
		a_rows, a_cols,
		b_rows, b_cols;

	//obtine de la utilizator dimensiunile matricelor si apoi elementele lor
	printf("Scrieti dimensiunile matricei A (m n): ");
	scanf("%d %d", &a_rows, &a_cols);
	printf("Scrieti elementele matricei A:\n");
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < a_cols; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	while (1) {
		printf("Scrieti dimensiunile matricei B (m n): ");
		scanf("%d %d", &b_rows, &b_cols);

		//verifica daca matricele sunt compatibile
		if (b_rows != a_cols) {
			printf("Matricele nu sunt compatibile. "
				"B trebuie sa aiba acelasi numar de "
				"linii cate coloane are A (%d).\n", a_cols);
		} else {
			break;
		}
	}

	printf("Scrieti elementele matricei B:\n");
	for (int i = 0; i < b_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	//afiseaza matricele pentru verificare
	printf("\nA =\n");
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < a_cols; j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\nB =\n");
	for (int i = 0; i < b_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			printf("%4d ", b[i][j]);
		}
		printf("\n");
	}
	
	//realizeaza produsul matricelor; product[a_rows][b_cols]
	int sum;
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			sum = 0;
			for (int k = 0; k < b_rows; k++) {
				sum += a[i][k] * b[k][j];
			}
			product[i][j] = sum;
		}
	}

	//afiseaza rezultatul
	printf("\nA x B =\n");
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			printf("%4d ", product[i][j]);
		}
		printf("\n");
	}

	_getch();
}